//Based on from https://stackoverflow.com/questions/15215865/netlink-sockets-in-c-using-the-3-x-linux-kernel?lq=1
/**
 *    This LKM will set a variable and print it value to the kernel buffer
 * for a specified number of times;
 * 
 * 
 */


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
static int value = 0;
module_param(value, int, 0);
module_param(addr, ulong, 0);
uint64_t phys_addr;
uint64_t va;

#define LOG(_f, _a...) \
	printk("change_mem:%d - " _f "\n", __LINE__, ## _a);
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

static int __init change_mem_init_v2(void) {

    printk("Entering: %s\n",__FUNCTION__);

    if ( !addr ){
        printk("Address parameter is mandatory!\n");
        return -1;
    }

    if ( !value ) {
        printk("Attributing the value\n");
    }

    pte_t p;
    // We need to point the page to the address of the page with all flags
    p.pte = (uint64_t) value;
    printk("Calling faulty_update with addr %lx and value %lx\n", addr, p.pte);
    int rc = HYPERVISOR_faulty_update_va_mapping(addr, p, UVMF_TLB_FLUSH);

    if ( rc ) 
        printk("Error on updating va mapping: %d\n", rc);
    else
    {
        LOG("Value should have been written successfully!");
    }


    return 0;
}

static int __init change_mem_init(void) {

    printk("Entering: %s\n",__FUNCTION__);

    if ( !addr ){
        printk("Address parameter is mandatory!\n");
        return -1;
    }
    uint64_t gpfn = addr >> PAGE_SHIFT;
    int offset = addr & ~PAGE_MASK;
    printk("The INPUT address info:\n");
    logvar(addr,"%lx");
    printk("\taddres:\t%lx\n",addr);
    printk("\tGuest Page address (with flags):\t%llx\n", (gpfn << PAGE_SHIFT) | PTE_FLAG );
    printk("\tgpfn:\t%llx\n",gpfn);
    printk("\toffset:\t%x\n",offset);

    va = __get_free_pages(GFP_KERNEL, 0);
    LOG("va address before mapping");
    page_walk(va);
    printk("Value in the va+offset before mapping : %lx\n", \
            (unsigned long) *((unsigned long*) va + offset));
    


    phys_addr = virt_to_phys((void*) va);
    printk("The LOCAL address info:\n");
    printk("\tvirtual:\t%llx\n",va);
    printk("\tphysical:\t%llx\n",phys_addr);

    pte_t p;
    // We need to point the page to the address of the page with all flags
    p.pte = ((gpfn << PAGE_SHIFT) | PTE_FLAG);

    
    printk("Mapping the physical address\n");
    int rc = HYPERVISOR_faulty_update_va_mapping(va, p, UVMF_TLB_FLUSH);

    if ( rc ) 
        printk("Error on updating va mapping: %d\n", rc);
    else
    {
        LOG("va address after mapping");
        page_walk(va);
//        printk("Value in the address passed: %lx\n", \
                (unsigned long) *((unsigned long*) va + offset));
    }

    if ( value ) {
        printk("Attributing the value\n");
        *((unsigned long*) va + offset) = value;
        printk("New value  in the address passed: %lx\n", \
                (unsigned long) *((unsigned long*) va + offset));
    }

    return 0;
}

static void __exit change_mem_exit(void) {
    
    printk(KERN_INFO "Exiting change_mem module\n");

}

//module_init(change_mem_init); 
module_init(change_mem_init); 
module_exit(change_mem_exit);


MODULE_LICENSE("GPL");
MODULE_AUTHOR("Charles F.'. Goncalves");
