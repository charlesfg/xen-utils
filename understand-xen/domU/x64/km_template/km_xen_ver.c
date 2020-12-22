/* Linux Kernel Includes */
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/delay.h>

/* Xen  Includes */
/* Xen header files */                                                                             
#include <linux/slab.h>
#include <asm/xen/page.h>
#include <asm/xen/hypervisor.h>
#include <asm/xen/hypercall.h>
#include <xen/interface/event_channel.h>
#include <xen/xen.h>
#include <xen/interface/xen.h>


static int __init hc_xen_ver_init(void) {

	unsigned long ret = 0;
    printk("Loading the hc_xen_ver : %s\n",__FUNCTION__);
    printk("Entering: %s\n",__FUNCTION__);
	ret = HYPERVISOR_xen_version(0, 0);
    printk("Xen version %ld.%ld\n", ret >> 16, ret & 0xffff);
    printk("Address of ret %p\n", &ret);
    printk("Address of __va(ret) %p\n", __va(&ret));
    printk("Address of virt_to_page(ret) %p\n", virt_to_page(&ret));
    printk("Address of virt_to_phys(ret) %p\n",(void*) virt_to_phys(&ret));
    printk("\n\n");
    printk("Xen Running on: xen_domain_type = %d\n", xen_domain_type);
    printk("Is a DomU = %d\n", xen_domain());
    printk("\n\n");
    //printk("Number of pages = %d\n", start_info.nr_page);
    
    /* Read the CR3 Register*/
    u64 cr3;
    asm volatile("mov %%cr3, %%rax\n"
            "mov %%rax, %0\n"
            :"=m"(cr3)
            ::"%rax"
            );
    printk("CR3 Register Address = %p\n", (void *)cr3);
    
    //xen_domctl_t domctl;
    //domctl.cmd = 5
    int i=0;
    for(i=0; i<20; ++i){
        printk("Xen version %ld.%ld\n", ret >> 16, ret & 0xffff);
        mdelay(1000);
    }
 
    return 0;
}

static void __exit hc_xen_ver_exit(void) {

    printk(KERN_INFO "Exiting hc_xen_ver  module\n");

}

module_init(hc_xen_ver_init); 
module_exit(hc_xen_ver_exit);


MODULE_LICENSE("GPL");
MODULE_AUTHOR("Charles F.'. Goncalves");

