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
static unsigned long value = 0;
static unsigned int linear = 0;
module_param(value, ulong, 0);
module_param(addr, ulong, 0);
module_param(linear, int, 0);
uint64_t phys_addr;
uint64_t va;

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

static int __init arbitrary_access_init(void) {

    int rc = 0;
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
