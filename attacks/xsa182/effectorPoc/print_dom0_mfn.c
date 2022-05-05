/* Linux Kernel Includes */
#include "linux/gfp.h"
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/delay.h>
#include <linux/slab.h>
#include <linux/sched.h>
#include <linux/gfp.h>
#include <linux/highmem.h>


/* Xen  Includes */
/* Xen header files */
#include <asm/xen/page.h>
#include <asm/xen/hypervisor.h>
#include <asm/xen/hypercall.h>
#include <xen/interface/event_channel.h>
#include <xen/xen.h>
#include <xen/interface/xen.h>
#include <xen/interface/memory.h>
#include <asm/xen/interface.h>

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

#define FIND_START_INFO_PAGE 1
#define FIND_VDSO_PAGE 2
#define DO_PAGE_READ 1
#define DO_PAGE_WRITE 2

#define DEBUG(_f, _a...) \
	printk("xen_test:%d - " _f "\n", __LINE__, ## _a);

#define __mfn(_v) ((unsigned long) (arbitrary_virt_to_machine(_v).maddr >> PAGE_SHIFT))
#define __machine_addr(_v) ((unsigned long) arbitrary_virt_to_machine(_v).maddr)

#define HYPERVISOR_tlb_flush_all() { \
	struct mmuext_op uops[] = {{.cmd =  MMUEXT_TLB_FLUSH_ALL}}; \
	HYPERVISOR_mmuext_op(uops, 1, NULL, DOMID_SELF); }

/*
 * Variables related to the attack
 */
#define SET_BYPASS_L2_UPDATE 1
#define UNSET_BYPASS_L2_UPDATE 2




void print_xen_start_info_content(void){
	struct start_info *x = xen_start_info;
printk("\n\n\
  char magic[32]='%s'\t/*'xen-<version>-<platform>'*/\n\
  unsigned long nr_pages=%ld\t/* Total pages allocated to this domain.  */\n\
  unsigned long shared_info=%p\t/* MACHINE address of shared info struct. */\n\
  uint32_t flags=%X\t/* SIF_xxx flags.*/\n\
  xen_pfn_t store_mfn=%ld\t/* MACHINE page number of shared page.*/\n\
  uint32_t store_evtchn=%d\t/* Event channel for store communication. */\n\
  union {\n\
    struct {\n\
            xen_pfn_t mfn=%ld\t/* MACHINE page number of console page.*/\n\
            uint32_t  evtchn=%d\t/* Event channel for console page.*/\n\
    } domU;\n", x->magic, x->nr_pages, (void *) x->shared_info, x->flags, x->store_mfn,
x->store_evtchn,x->console.domU.mfn, x->console.domU.evtchn);

printk("  } console;\n\
  /* THE FOLLOWING ARE ONLY FILLED IN ON INITIAL BOOT (NOT RESUME).*/\n\
  unsigned long pt_base=%p\t/* VIRTUAL address of page directory.*/\n\
  unsigned long nr_pt_frames=%ld\t/* Number of bootstrap p.t. frames.*/\n\
  unsigned long mfn_list=%p\t/* VIRTUAL address of page-frame list.  */\n\
  unsigned long mod_start=%p\t/* VIRTUAL address of pre-loaded module.*/\n\
  unsigned long mod_len=%ld\t/* Size (bytes) of pre-loaded module. */\n\
  int8_t cmd_line[MAX_GUEST_CMDLINE]%s\n\
",(void *) x->pt_base,x->nr_pt_frames,(void *) x->mfn_list,(void *) x->mod_start, 
x->mod_len, x->cmd_line
);
}

void page_walk(unsigned long va)
{
	pgd_t *pgd;
    p4d_t *p4d;
	pud_t *pud;
	pmd_t *pmd;
	pte_t *pte;
	struct mm_struct *mm = current->mm;

	pgd = pgd_offset(mm, va);
    p4d = p4d_offset(pgd, va);
	pud = pud_offset(p4d, va);
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

p4d_t *get_p4d(unsigned long va)
{
	return p4d_offset(get_pgd(va), va);
}

pud_t *get_pud(unsigned long va)
{
	return pud_offset(get_p4d(va), va);
}

pmd_t *get_pmd(unsigned long va)
{
	return pmd_offset(get_pud(va), va);
}

pte_t *get_pte(unsigned long va)
{
	return pte_offset_kernel(get_pmd(va), va);
}



struct shared_info dummy_shared_info;
struct shared_info *HYPERVISOR_shared_info = (void *)&dummy_shared_info;
static struct arch_shared_info *my_arch;

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


void print_my_arch_info(void)
{

    //printk("pm2_cr3\t%ld\n",my_arch->p2m_cr3);
    printk("max_pfn\t%ld\n",my_arch->max_pfn);
    xen_pfn_t fll =  my_arch->pfn_to_mfn_frame_list_list << PAGE_SHIFT;
    printk("fll\t%lx\n",fll);
    printk("__va(fll)\t%p\n",__va(fll));


}





void print_kmemory_info(void * ret){
    printk("Address of ret \t\t\t%p\n", &ret);
    /* 
     * __va is used only for converting virtuall memory on kernel 
     * every address is always virtual, we need to stablish the physicall address
     * __pa will get the physiscal address of this SO 
     * BUT, we are on a virtualized system
     */
    printk("Address of __pa(ret) \t\t%p\n",(void *) __pa(&ret));
    printk("Address of virt_to_phys(ret) \t\t%p\n",(void*) virt_to_phys(&ret));
    printk("PAGE_OFFSET \t%lX\n", PAGE_OFFSET);
    printk("virt_addr_valid(ret) \t%d\n", virt_addr_valid(&ret));
    printk("Address of virt_to_page(ret) \t%p\n", virt_to_page(&ret));
    printk("\n\n");
}


static int __init print_dom0_mfn_init(void) {

    unsigned long *p2m;
    map_shared_info();
    printk("Loading the print_dom0_mfn : %s\n",__FUNCTION__);
    print_xen_start_info_content();
    DEBUG("Page Walk of x->pt_base");
    page_walk(xen_start_info->pt_base);
    unsigned long *fl = (unsigned long *)xen_start_info->mfn_list;
    int i;
    DEBUG("Bootstrap p.t. frames");
    for(i=0; i< xen_start_info->nr_pt_frames; i++){
        DEBUG("fl[%d] = %lx",i,fl[i]);
    }
    DEBUG("mfn_list");
    DEBUG("fl[0] = %lx",fl[0]);
    for(i=0; i< 5; i++){
        DEBUG("fl[%d] = %lx",i,fl[i]);
    }
    int j = xen_start_info->nr_pages;
    for(i=j-5; i< j; i++){
        DEBUG("fl[%d] = %lx",i,fl[i]);
    }
    DEBUG("fl[%ld] = %lx",xen_start_info->nr_pages,fl[xen_start_info->nr_pages]);

    DEBUG("page walk of xen_start_info page %p : 0x%lx", xen_start_info, __machine_addr(xen_start_info));
    page_walk((unsigned long)xen_start_info);

    DEBUG("p2m_vaddr : %lx", my_arch->p2m_vaddr);
    
    p2m = (unsigned long *) my_arch->p2m_vaddr;
    for(i=0; i< 10; i++){
        DEBUG("p2m[%d] = %lx",i,p2m[i]);
    }
    



    return 0;

}


static void __exit print_dom0_mfn_exit(void) {
    printk(KERN_INFO "Exiting print_dom0_mfn  module\n");

}

module_init(print_dom0_mfn_init);
module_exit(print_dom0_mfn_exit);


MODULE_LICENSE("GPL");
MODULE_AUTHOR("Charles F.'. Goncalves");

