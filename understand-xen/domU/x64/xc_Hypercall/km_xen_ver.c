/* Linux Kernel Includes */
#include <linux/module.h>
#include <linux/kernel.h>

/* Xen  Includes */
/* Xen header files */                                                                             
#include <asm/xen/hypercall.h>


static int __init hc_xen_ver_init(void) {

	unsigned long ret = 0;
    printk("Loading the hc_xen_ver : %s\n",__FUNCTION__);
    printk("Entering: %s\n",__FUNCTION__);
	ret = HYPERVISOR_xen_version(0, 0);
    printk("Xen version %ld.%ld\n", ret >> 16, ret & 0xffff);

    return 0;
}

static void __exit hc_xen_ver_exit(void) {

    printk(KERN_INFO "Exiting hc_xen_ver  module\n");

}

module_init(hc_xen_ver_init); 
module_exit(hc_xen_ver_exit);


MODULE_LICENSE("GPL");
MODULE_AUTHOR("Charles F.'. Goncalves");

