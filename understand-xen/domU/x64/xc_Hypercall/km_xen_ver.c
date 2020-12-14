#include <linux/module.h>
#include <net/sock.h>
#include <linux/netlink.h>
#include <linux/skbuff.h>
#include <linux/kthread.h>
#include <linux/sched.h>  

static int __init hc_xen_ver_init(void) {

    printk("Loading the hc_xen_ver : %s\n",__FUNCTION__);
    printk("Entering: %s\n",__FUNCTION__);

     /* wait for message coming down from user-space */    

    return 0;
}

static void __exit hc_xen_ver_exit(void) {

    printk(KERN_INFO "Exiting hc_xen_ver  module\n");

}

module_init(hc_xen_ver_init); 
module_exit(hc_xen_ver_exit);


MODULE_LICENSE("GPL");
MODULE_AUTHOR("Charles F.'. Goncalves");

