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
#include <getopt.h>
#include <ctype.h>

// The order of the followin includes is relevant
#define XC_WANT_COMPAT_MAP_FOREIGN_API

#include <xenctrl.h>
#include <xc_private.h>
#include <xc_core.h>

static int quiet = 0;
static int is_address = 0;

#define LOG(_m,_a...) \
    if (!quiet) \
        printf("%s:%s:%d- " _m "\n",__FILE__,__FUNCTION__,__LINE__, ## _a);

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

// ----------------
// Global Variables
// ----------------
static int domid = -1;
static int print_fmt = 0;
static unsigned long gpfn;
static unsigned long hex_action_value = -1;
char str_action[50];

int print_page(uint64_t *page)
{
    if (!print_fmt)
        return 0;

    LOG("Printing the Values of Page: %p", page);
    int i = 0;
    uint64_t *p = page;

    for(i=0; i < (PAGE_SIZE/sizeof(uint64_t)); i++)
    {
        if (print_fmt == 1)
            printf("%d: 0x%lx",i, *p++);
        else
            printf("%d: 0x%lu",i, *p++);

        printf(i%4==3? "\n":"\t");
    }

    return 0;
}
int write_ulong_value(uint64_t *page, uint64_t value)
{
    LOG("Write Value in Page:\n\tPage:  %p\n\tValue: 0x%lx", page, value);
    int i = 0;
    uint64_t *p = page;

    for(i=0; i < PAGE_SIZE / sizeof(uint64_t); i++)
    {
        *p++ = value;
    }

    return 0;
}


static void usage(void)
{
    printf("Usage: gpfn2mfn [options] gpfn\n");
    printf("  gpfn: guest page frame number represented as an hexadecimal\n\n");
    printf("Options:\n");
    printf("  -d, --domid [int]\n");
    printf("      The id of the target domain domain, page's owner.\n");
    printf("  -a, --address\n");
    printf("      Interpret gpfn as Guest Address not Frame Number\n");
    printf("  -q, --quiet\n");
    printf("      Quiesce normal informational output\n");
    printf("  -h, --help\n");
    printf("      Display this information\n");
}

void parse_args(int argc, char** argv)
{
    int ch;
    const static char sopts[] = "hqd:a";
    const static struct option lopts[] = {
        { "help",      no_argument,       NULL,  'h' },
        { "address",   no_argument,       NULL,  'a' },
        { "quiet",     no_argument,       NULL,  'q' },
        { "domid",     required_argument, NULL,  'd' },
        { 0, 0, 0, 0}
    };

    while ( (ch = getopt_long(argc, argv, sopts, lopts, NULL)) != -1 )
    {
        switch ( ch )
        {
        case 'd':
            domid = 0;
            if (strcmp("0",optarg)!=0)
            {
                domid = atoi(optarg);
                if (!domid)
                {
                    printf("Domain Id '%s' is not valid\n", optarg);
                    usage();
                    exit(EXIT_FAILURE);
                }
            }
            break;
        case '?':
            if (strchr(sopts, optopt) != NULL)
                printf("Option: -%c requires an argument\n",optopt);
            else if (isprint (optopt))
                fprintf (stderr, "Unknown option `-%c'.\n", optopt);
            else
                fprintf (stderr,
                        "Unknown option character `\\x%x'.\n",
                        optopt);
            usage();
            exit(EXIT_FAILURE); 
        case 'a':
            LOG("+ Setting the quiet flag\n");
            is_address = 1;
            break;
        case 'q':
            LOG("+ Setting the quiet flag\n");
            quiet = 1;
            break;
        case 'h':
            usage();
            exit(1);
        default:
            LOG("went to default\n");
            usage();
            exit(1);
        }
    }

    if (domid == -1)
    {
        fprintf(stderr,"Domain Id should be provided\n");
        usage();
        exit(EXIT_FAILURE); 
    }


    if (optind < argc)
    {
        gpfn = 0;
        char *gpfn_str = argv[optind++];
        if (strcmp("0",gpfn_str)!=0)
        {
            gpfn = strtoull(gpfn_str, NULL, 16);
            if (!gpfn)
            {
                printf("Guest Page Frame Number '%s' is not valid\n", gpfn_str);
                usage();
                exit(EXIT_FAILURE);
            }
            if (is_address)
            {
                printf("Using input as address : '%s'\n", gpfn_str);
                gpfn = gpfn >> PAGE_SHIFT;
                printf("Guest Page Frame Number is '%lx'\n", gpfn);

            }
        }
    }
    else
    {
        printf("page address must be supplied!\n");
        usage();
        exit(EXIT_FAILURE);
    }

    if (!quiet) 
    {
        LOG("Values passed:");
        LOG("  domid            = %d", domid);
        LOG("  quiet            = %d", quiet);
        LOG("  hex_action_value = %lx", hex_action_value);
        LOG("  action           = '%s'", str_action);
        LOG("  gpfn             = %lx", gpfn);
    }
}

int main(int argc, char **argv)
{
    uintptr_t mfn;
    
    parse_args(argc, argv);

    xc_interface *xch;
    xch = xc_interface_open(NULL, NULL, 0);

    struct xc_domain_meminfo minfo;
    xc_dominfo_t info;

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

    LOG(" --- P2M for domain %d ---", domid);
    LOG(" Guest Width: %u, PT Levels: %u P2M size: = %lu",
           minfo.guest_width, minfo.pt_levels, minfo.p2m_size);

    unsigned long pagetype = minfo.pfn_type[gpfn] & XEN_DOMCTL_PFINFO_LTAB_MASK;
    mfn = ((uint64_t*)minfo.p2m_table)[gpfn];

    LOG("gpfn=0x%lx ==> mfn=0x%lx (%s)", gpfn, mfn, get_pagetype_str(pagetype));

    // LOG("Trying to map pages from domU %d", domid);

    // uint64_t *map_page;
    // map_page = (uint64_t *) xc_map_foreign_range(xch, domid, PAGE_SIZE, 
    //         PROT_READ | PROT_WRITE , mfn);

    // if (!map_page) {
    //     printf("Could not map address:\n%s\n",xc_strerror(xch, errno));
    //     return EXIT_FAILURE;
    // }

    // LOG("Mapped address Returned %p", map_page);
    // LOG("Invoking action '%s' for page %p and  value 0x%lx!", 
    //         str_action, map_page, hex_action_value);
    // 
    // print_page(map_page);

    // if(action(map_page, hex_action_value))
    // {
    //     printf("Error in invoking the action!\n");
    //     exit(EXIT_FAILURE);
    // }

    // struct mmuext_op uops[] = {{.cmd =  MMUEXT_TLB_FLUSH_ALL}};

    // 
    // LOG("Flushing the TLB");

    // if( !xc_mmuext_op(xch, uops, 1, 0)){
    //     printf("Could not Flush the TLB\n%s\n",xc_strerror(xch, errno));
    //     return EXIT_FAILURE;
    // }

    // print_page(map_page);


    // munmap(map_page, PAGE_SIZE);
    xc_unmap_domain_meminfo(xch, &minfo);


    return EXIT_SUCCESS;
}
