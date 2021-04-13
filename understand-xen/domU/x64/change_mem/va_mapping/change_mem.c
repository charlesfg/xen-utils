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


struct task_struct *task;

static  long addr = 0;
static int value = 0;
module_param(value, int, 0);
module_param(addr,  long, 0);
uint64_t phys_addr;
uint64_t va;


static int __init change_mem_init(void) {

    printk("Entering: %s\n",__FUNCTION__);

    if ( !addr ){
        printk("Address parameter is mandatory!\n");
        return -1;
    }
    uint64_t gpfn = addr >> PAGE_SHIFT;
    int offset = addr & ~PAGE_MASK;
    printk("The INPUT address info:\n");
    printk("\taddres:\t%lx\n",addr);
    printk("\tgpfn:\t%llx\n",gpfn);
    printk("\toffset:\t%x\n",offset);

    va = __get_free_pages(GFP_KERNEL, 0);
    


    phys_addr = virt_to_phys((void*) va);
    printk("The LOCAL address info:\n");
    printk("\tvirtual:\t%llx\n",va);
    printk("\tphysical:\t%llx\n",phys_addr);

    pte_t p;
    p.pte = gpfn;

    
    int rc = HYPERVISOR_update_va_mapping(va, p, UVMF_TLB_FLUSH);

    if ( rc ) 
    {
        printk("Eror on updating va mapping: %d\n", rc);
    }

    printk("Mapping the physical address\n");

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
