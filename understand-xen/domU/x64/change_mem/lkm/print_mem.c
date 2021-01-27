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

static int keepRunning = 1;
static unsigned long int ret = 0;

struct task_struct *task;

static int ms_sleep = 500;
module_param(ms_sleep, int, 0);


int thread_function(void *data)
{
    while(keepRunning)
    {
        printk("ret  %ld\n", ret);
        msleep(ms_sleep);           
    }

    printk(KERN_INFO "Leaving thread process!\n");

    return 0;    
}

static int __init print_mem_init(void) {

    printk("Entering: %s\n",__FUNCTION__);

    keepRunning = 1;
    task = kthread_run(&thread_function,(void *)NULL,"print_t");
    printk(KERN_INFO "Kernel Thread : %s\n",task->comm);    

    ret = HYPERVISOR_xen_version(0, 0);

    printk("ret  %ld\n", ret);
    printk("Xen version %ld.%ld\n", ret >> 16, ret & 0xffff);
    printk("Address of ret %p\n", &ret);
    printk("Address of __va(ret) %p\n", __va(&ret));
    printk("Address of virt_to_page(ret) %p\n", virt_to_page(&ret));
    printk("Address of virt_to_phys(ret) %p\n",(void*) virt_to_phys(&ret));
    printk("\n\n");
    

    return 0;
}

static void __exit print_mem_exit(void) {
    
    printk(KERN_INFO "Stoping the thread_function\n");
    keepRunning = 0;
    msleep(500);
    printk(KERN_INFO "Exiting print_mem module\n");

}

module_init(print_mem_init); 
module_exit(print_mem_exit);


MODULE_LICENSE("GPL");
MODULE_AUTHOR("Charles F.'. Goncalves");
