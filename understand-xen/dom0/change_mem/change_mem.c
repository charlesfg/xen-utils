#define _XOPEN_SOURCE 700
#include <fcntl.h> /* open */
#include <stdint.h> /* uint64_t  */
#include <stdio.h> /* printf */
#include <stdlib.h> /* size_t */
#include <unistd.h> /* pread, sysconf */
#include <sys/mman.h>
#include <inttypes.h>
#include <errno.h>
#include <string.h>

// The order of the followin includes is relevant
#define XC_WANT_COMPAT_MAP_FOREIGN_API

#include <xenctrl.h>
#include <xc_private.h>
#include <xc_core.h>


int dump_p2m(int domid, struct xc_domain_meminfo *minfo)
    
{
    unsigned long i;
    printf(" --- P2M for domain %d ---\n", domid);
    printf(" Guest Width: %u, PT Levels: %u P2M size: = %lu\n",
           minfo->guest_width, minfo->pt_levels, minfo->p2m_size);
    for ( i = 0; i < minfo->p2m_size; i++ )
    {
        unsigned long pagetype = minfo->pfn_type[i] &
                                     XEN_DOMCTL_PFINFO_LTAB_MASK;
        xen_pfn_t mfn;

        if ( minfo->guest_width == sizeof(uint64_t) )
            mfn = ((uint64_t*)minfo->p2m_table)[i];
        else
        {
            mfn = ((uint32_t*)minfo->p2m_table)[i];
#ifdef __x86_64__
            if ( mfn == ~0U ) /* Expand a 32bit guest's idea of INVALID_MFN */
                mfn = ~0UL;
#endif
        }

        printf("  pfn=0x%lx ==> mfn=0x%lx (type 0x%lx)", i, mfn,
               pagetype >> XEN_DOMCTL_PFINFO_LTAB_SHIFT);

        switch ( pagetype >> XEN_DOMCTL_PFINFO_LTAB_SHIFT )
        {
        case 0x0: /* NOTAB */
            printf("\n");
            break;
        case 0x1 ... 0x4: /* L1 -> L4 */
            printf(" L%lu\n", pagetype >> XEN_DOMCTL_PFINFO_LTAB_SHIFT);
            break;
        case 0x9 ... 0xc: /* Pinned L1 -> L4 */
            printf(" pinned L%lu\n",
                   (pagetype >> XEN_DOMCTL_PFINFO_LTAB_SHIFT) & 7);
            break;
        case 0xd: /* BROKEN */
            printf(" broken\n");
            break;
        case 0xe: /* XALLOC */
            printf(" xalloc\n");
            break;
        case 0xf: /* XTAB */
            printf(" invalid\n");
            break;
        default:
            printf(" <invalid type>\n");
            break;
        }
    }
    printf(" --- End of P2M for domain %d ---\n", domid);
    return 0;
}

char * get_pagetype_str(unsigned long pagetype)
{

    char *ret;
    ret = (char *) malloc(40*sizeof(char));
    unsigned long type_masked = pagetype >> XEN_DOMCTL_PFINFO_LTAB_SHIFT;
    switch ( type_masked )
    {
        case 0x0: /* NOTAB */
            sprintf(ret, "pagetype 0x%lu - NOTAB",type_masked );
            break;
        case 0x1 ... 0x4: /* L1 -> L4 */
            sprintf(ret, "pagetype 0x%lu - L%lu",type_masked, 
                    pagetype >> XEN_DOMCTL_PFINFO_LTAB_SHIFT);
            break;
        case 0x9 ... 0xc: /* Pinned L1 -> L4 */
            sprintf(ret, "pagetype 0x%lu - Pinned L%lu", type_masked ,
                    (pagetype >> XEN_DOMCTL_PFINFO_LTAB_SHIFT) & 7);
            break;
        case 0xd: /* BROKEN */
            sprintf(ret, "pagetype 0x%lu - Broken", type_masked);
            break;
        case 0xe: /* XALLOC */
            sprintf(ret, "pagetype 0x%lu - Xalloc", type_masked);
            break;
        case 0xf: /* XTAB */
            sprintf(ret, "pagetype 0x%lu - invalid XTAB", type_masked);
            break;
        default:
            sprintf(ret, " <?invalid type?> ");
            break;
    }
    return ret;
}

int main(int argc, char **argv)
{
    int domid, value, offset;
    uintptr_t paddr = 0, mfn, pfn;

    if (argc < 3) {
        printf("Usage: %s paddr dom_id [value]\n", argv[0]);
        printf("\t'paddr' physical address\n");
        printf("\t'dom_id' id of the domain that maps the physical address\n");
        printf("\tif 'value' provided will overwrite its value on the dom_id\n");
        return EXIT_FAILURE;
    }

    xc_interface *xch;
    xch = xc_interface_open(NULL, NULL, 0);

    struct xc_domain_meminfo minfo;
    xc_dominfo_t info;

    domid = strtoull(argv[2], NULL, 0);
    paddr = strtoull(argv[1], NULL, 16);

    if ( xc_domain_getinfo(xch, domid, 1, &info) != 1 ||
         info.domid != domid )
    {
        ERROR("Failed to obtain info for domain %d\n", domid);
        return -1;
    }

    /* Retrieve all the info about the domain's memory */
    memset(&minfo, 0, sizeof(minfo));
    if ( xc_map_domain_meminfo(xch, domid, &minfo) )
    {
        ERROR("Could not map domain %d memory information\n", domid);
        return -1;
    }

    printf(" --- P2M for domain %d ---\n", domid);
    printf(" Guest Width: %u, PT Levels: %u P2M size: = %lu\n",
           minfo.guest_width, minfo.pt_levels, minfo.p2m_size);

    printf("Address passed 0x%lx\n", paddr);
    pfn = paddr >> PAGE_SHIFT;
    printf("pfn => 0x%lx\n", pfn);
    offset = paddr & ~PAGE_MASK;
    unsigned long pagetype = minfo.pfn_type[pfn] & XEN_DOMCTL_PFINFO_LTAB_MASK;
    mfn = ((uint64_t*)minfo.p2m_table)[pfn];
    printf("pfn=0x%lx ==> mfn=0x%lx (%s)", pfn, mfn, get_pagetype_str(pagetype));

    printf("Related Page Address 0x%lx\n", mfn);
    printf("Related Page offset 0x%x\n", offset);

    if (argc == 4){
        value = atoi(argv[3]);
    }

    printf("Trying to map pages from domU %d\n", domid);

    uint64_t *map_page;
    map_page = (uint64_t *) xc_map_foreign_range(xch, domid, PAGE_SIZE, 
            PROT_READ | PROT_WRITE , mfn);

    if (!map_page) {
        printf("Could not map address:\n%s\n",xc_strerror(xch, errno));
        return EXIT_FAILURE;
    }

    printf("Mapped address Returned %p\n", map_page);
    printf("Value in the addr 0x%lx on the VM: %ld\n", paddr, (uint64_t) map_page[offset]);
    
    int i; 
    for(i=0; i < 20; i++){
        printf("%ld",(uint64_t) map_page[i]);
        (i % 4 == 3) ? printf("\n"): printf("\t");
    }
    printf("\n");
    

    if (value) {
        printf("Will write the value %d in the foreign address\n", value);
        map_page[offset] = (uint64_t) value;
	    
    }
    struct mmuext_op uops[] = {{.cmd =  MMUEXT_TLB_FLUSH_ALL}};

    printf("Flushing the TLB\n");
    if( !xc_mmuext_op(xch, uops, 1, 0)){
        printf("Could not Flush the TLB\n%s\n",xc_strerror(xch, errno));
        return EXIT_FAILURE;
    }

    printf("Value in the addr 0x%lx on the VM: %ld\n", paddr, (uint64_t) map_page[offset]);

    munmap(map_page, PAGE_SIZE);
    xc_unmap_domain_meminfo(xch, &minfo);


    return EXIT_SUCCESS;
}
