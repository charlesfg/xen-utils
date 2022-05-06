/* https://github.com/cirosantilli/linux-kernel-module-cheat#kthread */
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

#define LOG(_f, _a...) \
	printk("kutils:%d - " _f "\n", __LINE__, ## _a);
#define logvar(_v,_f) \
    printk("\t" #_v ":\t" _f "\n",_v);

#define HYPERVISOR_tlb_flush_all() { \
	struct mmuext_op uops[] = {{.cmd =  MMUEXT_TLB_FLUSH_ALL}}; \
	HYPERVISOR_mmuext_op(uops, 1, NULL, DOMID_SELF); }

void page_walk(unsigned long va)
{
	pgd_t *pgd;
    p4d_t *p4d;
	pud_t *pud;
	pmd_t *pmd;
	pte_t *pte;
	struct mm_struct *mm = current->mm;

	pgd = pgd_offset(mm, va);
    p4d = p4d_offset(pgd, va);
	pud = pud_offset(p4d, va);
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

p4d_t *get_p4d(unsigned long va)
{
	return p4d_offset(get_pgd(va), va);
}

pud_t *get_pud(unsigned long va)
{
	return pud_offset(get_p4d(va), va);
}

pmd_t *get_pmd(unsigned long va)
{
	return pmd_offset(get_pud(va), va);
}

pte_t *get_pte(unsigned long va)
{
	return pte_offset_kernel(get_pmd(va), va);
}


static struct task_struct *kthread;

static int work_func(void *data)
{

    unsigned long* my_pg = (void *)__get_free_pages(GFP_KERNEL, 0);

	u32 i = 0;
    *my_pg = 18012016UL;
	while (!kthread_should_stop()) {
		LOG("%p\t%lu", (void*)my_pg, *my_pg);
		usleep_range(1000000, 3000001);
		i++;
		if (i % 10 == 1)
			page_walk((unsigned long)my_pg);
	}
	return 0;
}

static int myinit(void)
{
	kthread = kthread_create(work_func, NULL, "mykthread");
	wake_up_process(kthread);
	return 0;
}

static void myexit(void)
{
	/* Waits for thread to return. */
	kthread_stop(kthread);
    LOG("Existing print_ulong");
}

module_init(myinit)
module_exit(myexit)
MODULE_LICENSE("GPL");
