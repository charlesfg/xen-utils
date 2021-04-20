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
 
#include <linux/slab.h>
#include <asm/xen/page.h>
#include <asm/xen/hypervisor.h>
#include <asm/xen/hypercall.h>
#include <xen/interface/event_channel.h>
#include <xen/xen.h>
#include <xen/interface/xen.h>


struct task_struct *task;

static  long addr = 0;
static int value = 0;
module_param(value, int, 0);
module_param(addr,  long, 0);

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

static int __init change_mem_init(void) {

    printk("Entering: %s\n",__FUNCTION__);

    if ( !addr ){
        printk("Address parameter is mandatory!\n");
        return -1;
    }
    printk("The address passed is: %lx\n",addr);

    printk("Mapping the physical address\n");
    void __iomem *io = ioremap(addr, 4);
    if ( io == NULL) 
    {
        printk("Could not map the physical addres %p\n",(void*) addr);
        return -1;
    }

    printk("The address returned by the ioremap  %p\n",io);
    printk("Value in the addr %p -> %d", (void *) addr, readl(io));

    page_walk((unsigned long )io);


    if ( value ) {
        printk("Attributing the value\n");
        *((int *) addr) = value;
        printk("New value in the addr %p -> %d", (void *) addr, *((int *) addr));
    }

    return 0;
}

static void __exit change_mem_exit(void) {
    
    printk(KERN_INFO "Exiting change_mem module\n");

}

module_init(change_mem_init); 
module_exit(change_mem_exit);


MODULE_LICENSE("GPL");
MODULE_AUTHOR("Charles F.'. Goncalves");
