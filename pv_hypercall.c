# 1 "hypercall.c"
# 1 "<built-in>"
# 1 "<command-line>"
# 31 "<command-line>"
# 1 "/usr/include/stdc-predef.h" 1 3 4
# 32 "<command-line>" 2
# 1 "hypercall.c"
# 22 "hypercall.c"
# 1 "/var/xen-dev/xen/xen/include/xen/compiler.h" 1
# 23 "hypercall.c" 2
# 1 "/var/xen-dev/xen/xen/include/xen/hypercall.h" 1







# 1 "/var/xen-dev/xen/xen/include/xen/types.h" 1



# 1 "/var/xen-dev/xen/xen/include/xen/stdbool.h" 1
# 5 "/var/xen-dev/xen/xen/include/xen/types.h" 2

# 1 "/var/xen-dev/xen/xen/include/asm/types.h" 1





typedef __signed__ char __s8;
typedef unsigned char __u8;

typedef __signed__ short __s16;
typedef unsigned short __u16;

typedef __signed__ int __s32;
typedef unsigned int __u32;


typedef __signed__ long __s64;
typedef unsigned long __u64;


typedef signed char s8;
typedef unsigned char u8;

typedef signed short s16;
typedef unsigned short u16;

typedef signed int s32;
typedef unsigned int u32;

typedef signed long s64;
typedef unsigned long u64;
typedef unsigned long paddr_t;




typedef long unsigned int size_t;



typedef signed long ssize_t;
# 7 "/var/xen-dev/xen/xen/include/xen/types.h" 2
# 36 "/var/xen-dev/xen/xen/include/xen/types.h"
typedef __u8 uint8_t;
typedef __s8 int8_t;

typedef __u16 uint16_t;
typedef __s16 int16_t;

typedef __u32 uint32_t;
typedef __s32 int32_t;

typedef __u64 uint64_t;
typedef __s64 int64_t;

typedef __u16 __le16;
typedef __u16 __be16;
typedef __u32 __le32;
typedef __u32 __be32;
typedef __u64 __le64;
typedef __u64 __be64;

typedef unsigned int __attribute__((__mode__(__pointer__))) uintptr_t;

typedef _Bool bool_t;
# 9 "/var/xen-dev/xen/xen/include/xen/hypercall.h" 2
# 1 "/var/xen-dev/xen/xen/include/xen/time.h" 1
# 12 "/var/xen-dev/xen/xen/include/xen/time.h"
# 1 "/var/xen-dev/xen/xen/include/public/xen.h" 1
# 30 "/var/xen-dev/xen/xen/include/public/xen.h"
# 1 "/var/xen-dev/xen/xen/include/public/xen-compat.h" 1
# 31 "/var/xen-dev/xen/xen/include/public/xen.h" 2


# 1 "/var/xen-dev/xen/xen/include/public/arch-x86/xen.h" 1
# 27 "/var/xen-dev/xen/xen/include/public/arch-x86/xen.h"
# 1 "/var/xen-dev/xen/xen/include/public/arch-x86/../xen.h" 1
# 28 "/var/xen-dev/xen/xen/include/public/arch-x86/xen.h" 2
# 72 "/var/xen-dev/xen/xen/include/public/arch-x86/xen.h"
# 1 "/var/xen-dev/xen/xen/include/public/arch-x86/xen-x86_64.h" 1
# 127 "/var/xen-dev/xen/xen/include/public/arch-x86/xen-x86_64.h"
struct iret_context {

    uint64_t rax, r11, rcx, flags, rip, cs, rflags, rsp, ss;

};
# 179 "/var/xen-dev/xen/xen/include/public/arch-x86/xen-x86_64.h"
struct cpu_user_regs {
    uint64_t r15;
    uint64_t r14;
    uint64_t r13;
    uint64_t r12;
    union { uint64_t rbp, ebp; uint32_t _ebp; };
    union { uint64_t rbx, ebx; uint32_t _ebx; };
    uint64_t r11;
    uint64_t r10;
    uint64_t r9;
    uint64_t r8;
    union { uint64_t rax, eax; uint32_t _eax; };
    union { uint64_t rcx, ecx; uint32_t _ecx; };
    union { uint64_t rdx, edx; uint32_t _edx; };
    union { uint64_t rsi, esi; uint32_t _esi; };
    union { uint64_t rdi, edi; uint32_t _edi; };
    uint32_t error_code;
    uint32_t entry_vector;
    union { uint64_t rip, eip; uint32_t _eip; };
    uint16_t cs, _pad0[1];
    uint8_t saved_upcall_mask;
    uint8_t _pad1[3];
    union { uint64_t rflags, eflags; uint32_t _eflags; };
    union { uint64_t rsp, esp; uint32_t _esp; };
    uint16_t ss, _pad2[3];
    uint16_t es, _pad3[3];
    uint16_t ds, _pad4[3];
    uint16_t fs, _pad5[3];
    uint16_t gs, _pad6[3];
};
typedef struct cpu_user_regs cpu_user_regs_t;
typedef cpu_user_regs_t * __guest_handle_cpu_user_regs_t; typedef const cpu_user_regs_t * __guest_handle_const_cpu_user_regs_t;
# 221 "/var/xen-dev/xen/xen/include/public/arch-x86/xen-x86_64.h"
struct arch_vcpu_info {
    unsigned long cr2;
    unsigned long pad;
};
typedef struct arch_vcpu_info arch_vcpu_info_t;

typedef unsigned long xen_callback_t;
# 73 "/var/xen-dev/xen/xen/include/public/arch-x86/xen.h" 2



typedef unsigned long xen_pfn_t;
# 121 "/var/xen-dev/xen/xen/include/public/arch-x86/xen.h"
typedef unsigned long xen_ulong_t;
# 151 "/var/xen-dev/xen/xen/include/public/arch-x86/xen.h"
struct trap_info {
    uint8_t vector;
    uint8_t flags;
    uint16_t cs;
    unsigned long address;
};
typedef struct trap_info trap_info_t;
typedef trap_info_t * __guest_handle_trap_info_t; typedef const trap_info_t * __guest_handle_const_trap_info_t;

typedef uint64_t tsc_timestamp_t;
# 173 "/var/xen-dev/xen/xen/include/public/arch-x86/xen.h"
struct vcpu_guest_context {

    struct { char x[512]; } fpu_ctxt;
# 188 "/var/xen-dev/xen/xen/include/public/arch-x86/xen.h"
    unsigned long flags;
    struct cpu_user_regs user_regs;
    struct trap_info trap_ctxt[256];
    unsigned long ldt_base, ldt_ents;
    unsigned long gdt_frames[16], gdt_ents;
    unsigned long kernel_ss, kernel_sp;

    unsigned long ctrlreg[8];
    unsigned long debugreg[8];






    unsigned long event_callback_eip;
    unsigned long failsafe_callback_eip;
# 214 "/var/xen-dev/xen/xen/include/public/arch-x86/xen.h"
    unsigned long syscall_callback_eip;


    unsigned long vm_assist;


    uint64_t fs_base;
    uint64_t gs_base_kernel;
    uint64_t gs_base_user;

};
typedef struct vcpu_guest_context vcpu_guest_context_t;
typedef vcpu_guest_context_t * __guest_handle_vcpu_guest_context_t; typedef const vcpu_guest_context_t * __guest_handle_const_vcpu_guest_context_t;

struct arch_shared_info {




    unsigned long max_pfn;







    xen_pfn_t pfn_to_mfn_frame_list_list;
    unsigned long nmi_reason;
# 261 "/var/xen-dev/xen/xen/include/public/arch-x86/xen.h"
    unsigned long p2m_cr3;
    unsigned long p2m_vaddr;
    unsigned long p2m_generation;




    uint32_t hypercall_number;
};
typedef struct arch_shared_info arch_shared_info_t;
# 322 "/var/xen-dev/xen/xen/include/public/arch-x86/xen.h"
typedef struct xen_cpuid_leaf {

    uint32_t leaf, subleaf;
    uint32_t a, b, c, d;
} xen_cpuid_leaf_t;
typedef xen_cpuid_leaf_t * __guest_handle_xen_cpuid_leaf_t; typedef const xen_cpuid_leaf_t * __guest_handle_const_xen_cpuid_leaf_t;

typedef struct xen_msr_entry {
    uint32_t idx;
    uint32_t flags;
    uint64_t val;
} xen_msr_entry_t;
typedef xen_msr_entry_t * __guest_handle_xen_msr_entry_t; typedef const xen_msr_entry_t * __guest_handle_const_xen_msr_entry_t;
# 34 "/var/xen-dev/xen/xen/include/public/xen.h" 2
# 42 "/var/xen-dev/xen/xen/include/public/xen.h"
typedef char * __guest_handle_char; typedef const char * __guest_handle_const_char;
typedef unsigned char * __guest_handle_uchar; typedef const unsigned char * __guest_handle_const_uchar;
typedef int * __guest_handle_int; typedef const int * __guest_handle_const_int;
typedef unsigned int * __guest_handle_uint; typedef const unsigned int * __guest_handle_const_uint;

typedef long * __guest_handle_long; typedef const long * __guest_handle_const_long;
typedef unsigned long * __guest_handle_ulong; typedef const unsigned long * __guest_handle_const_ulong;

typedef void * __guest_handle_void; typedef const void * __guest_handle_const_void;

typedef uint64_t * __guest_handle_uint64_t; typedef const uint64_t * __guest_handle_const_uint64_t;
typedef xen_pfn_t * __guest_handle_xen_pfn_t; typedef const xen_pfn_t * __guest_handle_const_xen_pfn_t;
typedef xen_ulong_t * __guest_handle_xen_ulong_t; typedef const xen_ulong_t * __guest_handle_const_xen_ulong_t;
# 444 "/var/xen-dev/xen/xen/include/public/xen.h"
struct mmuext_op {
    unsigned int cmd;
    union {


        xen_pfn_t mfn;

        unsigned long linear_addr;
    } arg1;
    union {

        unsigned int nr_ents;




        const void *vcpumask;


        xen_pfn_t src_mfn;
    } arg2;
};
typedef struct mmuext_op mmuext_op_t;
typedef mmuext_op_t * __guest_handle_mmuext_op_t; typedef const mmuext_op_t * __guest_handle_const_mmuext_op_t;
# 619 "/var/xen-dev/xen/xen/include/public/xen.h"
typedef uint16_t domid_t;





struct mmu_update {
    uint64_t ptr;
    uint64_t val;
};
typedef struct mmu_update mmu_update_t;
typedef mmu_update_t * __guest_handle_mmu_update_t; typedef const mmu_update_t * __guest_handle_const_mmu_update_t;
# 641 "/var/xen-dev/xen/xen/include/public/xen.h"
struct multicall_entry {
    xen_ulong_t op, result;
    xen_ulong_t args[6];
};
typedef struct multicall_entry multicall_entry_t;
typedef multicall_entry_t * __guest_handle_multicall_entry_t; typedef const multicall_entry_t * __guest_handle_const_multicall_entry_t;
# 656 "/var/xen-dev/xen/xen/include/public/xen.h"
struct vcpu_time_info {
# 666 "/var/xen-dev/xen/xen/include/public/xen.h"
    uint32_t version;
    uint32_t pad0;
    uint64_t tsc_timestamp;
    uint64_t system_time;







    uint32_t tsc_to_system_mul;
    int8_t tsc_shift;




    int8_t pad1[3];

};
typedef struct vcpu_time_info vcpu_time_info_t;




struct vcpu_info {
# 717 "/var/xen-dev/xen/xen/include/public/xen.h"
    uint8_t evtchn_upcall_pending;

    uint8_t evtchn_upcall_mask;



    xen_ulong_t evtchn_pending_sel;
    struct arch_vcpu_info arch;
    struct vcpu_time_info time;
};

typedef struct vcpu_info vcpu_info_t;
# 740 "/var/xen-dev/xen/xen/include/public/xen.h"
struct shared_info {
    struct vcpu_info vcpu_info[32];
# 774 "/var/xen-dev/xen/xen/include/public/xen.h"
    xen_ulong_t evtchn_pending[sizeof(xen_ulong_t) * 8];
    xen_ulong_t evtchn_mask[sizeof(xen_ulong_t) * 8];
# 786 "/var/xen-dev/xen/xen/include/public/xen.h"
    uint32_t wc_version;
    uint32_t wc_sec;
    uint32_t wc_nsec;

    uint32_t wc_sec_hi;





    struct arch_shared_info arch;

};

typedef struct shared_info shared_info_t;
# 841 "/var/xen-dev/xen/xen/include/public/xen.h"
struct start_info {

    char magic[32];
    unsigned long nr_pages;
    unsigned long shared_info;
    uint32_t flags;
    xen_pfn_t store_mfn;
    uint32_t store_evtchn;
    union {
        struct {
            xen_pfn_t mfn;
            uint32_t evtchn;
        } domU;
        struct {
            uint32_t info_off;
            uint32_t info_size;
        } dom0;
    } console;

    unsigned long pt_base;
    unsigned long nr_pt_frames;
    unsigned long mfn_list;
    unsigned long mod_start;


    unsigned long mod_len;

    int8_t cmd_line[1024];

    unsigned long first_p2m_pfn;
    unsigned long nr_p2m_frames;
};
typedef struct start_info start_info_t;
# 905 "/var/xen-dev/xen/xen/include/public/xen.h"
struct xen_multiboot_mod_list
{

    uint32_t mod_start;

    uint32_t mod_end;

    uint32_t cmdline;

    uint32_t pad;
};
# 924 "/var/xen-dev/xen/xen/include/public/xen.h"
typedef struct dom0_vga_console_info {
    uint8_t video_type;




    union {
        struct {

            uint16_t font_height;

            uint16_t cursor_x, cursor_y;

            uint16_t rows, columns;
        } text_mode_3;

        struct {

            uint16_t width, height;

            uint16_t bytes_per_line;

            uint16_t bits_per_pixel;

            uint32_t lfb_base;
            uint32_t lfb_size;

            uint8_t red_pos, red_size;
            uint8_t green_pos, green_size;
            uint8_t blue_pos, blue_size;
            uint8_t rsvd_pos, rsvd_size;
# 966 "/var/xen-dev/xen/xen/include/public/xen.h"
        } vesa_lfb;
    } u;
} dom0_vga_console_info_t;



typedef uint8_t xen_domain_handle_t[16];

typedef uint8_t * __guest_handle_uint8; typedef const uint8_t * __guest_handle_const_uint8;
typedef uint16_t * __guest_handle_uint16; typedef const uint16_t * __guest_handle_const_uint16;
typedef uint32_t * __guest_handle_uint32; typedef const uint32_t * __guest_handle_const_uint32;
typedef uint64_t * __guest_handle_uint64; typedef const uint64_t * __guest_handle_const_uint64;

typedef struct {
    uint8_t a[16];
} xen_uuid_t;
# 13 "/var/xen-dev/xen/xen/include/xen/time.h" 2

extern int init_xen_time(void);
extern void cstate_restore_tsc(void);

extern unsigned long cpu_khz;
extern unsigned long pit0_ticks;

struct domain;
struct vcpu;
# 32 "/var/xen-dev/xen/xen/include/xen/time.h"
typedef s64 s_time_t;


s_time_t get_s_time_fixed(u64 at_tick);
s_time_t get_s_time(void);
unsigned long get_localtime(struct domain *d);
uint64_t get_localtime_us(struct domain *d);

struct tm {
    int tm_sec;
    int tm_min;
    int tm_hour;
    int tm_mday;
    int tm_mon;
    int tm_year;
    int tm_wday;
    int tm_yday;
    int tm_isdst;
};
struct tm gmtime(unsigned long t);
struct tm wallclock_time(uint64_t *ns);
# 66 "/var/xen-dev/xen/xen/include/xen/time.h"
extern void update_vcpu_system_time(struct vcpu *v);
extern void update_domain_wallclock_time(struct domain *d);

extern void do_settime(
    u64 secs, unsigned int nsecs, u64 system_time_base);

extern void send_timer_event(struct vcpu *v);

void domain_set_time_offset(struct domain *d, int64_t time_offset_seconds);

# 1 "/var/xen-dev/xen/xen/include/asm/time.h" 1




# 1 "/var/xen-dev/xen/xen/include/asm/msr.h" 1



# 1 "/var/xen-dev/xen/xen/include/asm/msr-index.h" 1
# 5 "/var/xen-dev/xen/xen/include/asm/msr.h" 2


# 1 "/var/xen-dev/xen/xen/include/xen/percpu.h" 1



# 1 "/var/xen-dev/xen/xen/include/asm/percpu.h" 1




extern char __per_cpu_start[], __per_cpu_data_end[];
extern unsigned long __per_cpu_offset[NR_CPUS];
void percpu_init_areas(void);
# 5 "/var/xen-dev/xen/xen/include/xen/percpu.h" 2
# 8 "/var/xen-dev/xen/xen/include/asm/msr.h" 2
# 1 "/var/xen-dev/xen/xen/include/xen/errno.h" 1






enum {
# 1 "/var/xen-dev/xen/xen/include/public/errno.h" 1
# 60 "/var/xen-dev/xen/xen/include/public/errno.h"
EPERM = 1,
ENOENT = 2,
ESRCH = 3,



EIO = 5,
ENXIO = 6,
E2BIG = 7,
ENOEXEC = 8,
EBADF = 9,
ECHILD = 10,
EAGAIN = 11,
EWOULDBLOCK = 11,
ENOMEM = 12,
EACCES = 13,
EFAULT = 14,
EBUSY = 16,
EEXIST = 17,
EXDEV = 18,
ENODEV = 19,
EISDIR = 21,
EINVAL = 22,
ENFILE = 23,
EMFILE = 24,
ENOSPC = 28,
EROFS = 30,
EMLINK = 31,
EDOM = 33,
ERANGE = 34,
EDEADLK = 35,
EDEADLOCK = 35,
ENAMETOOLONG = 36,
ENOLCK = 37,
ENOSYS = 38,
ENOTEMPTY = 39,
ENODATA = 61,
ETIME = 62,
EBADMSG = 74,
EOVERFLOW = 75,
EILSEQ = 84,



ENOTSOCK = 88,
EMSGSIZE = 90,
EOPNOTSUPP = 95,
EADDRINUSE = 98,
EADDRNOTAVAIL = 99,
ENOBUFS = 105,
EISCONN = 106,
ENOTCONN = 107,
ETIMEDOUT = 110,
ECONNREFUSED = 111,
# 9 "/var/xen-dev/xen/xen/include/xen/errno.h" 2
};
# 9 "/var/xen-dev/xen/xen/include/asm/msr.h" 2

# 1 "/var/xen-dev/xen/xen/include/xen/lib/x86/msr.h" 1
# 9 "/var/xen-dev/xen/xen/include/xen/lib/x86/msr.h"
struct msr_policy
{
# 19 "/var/xen-dev/xen/xen/include/xen/lib/x86/msr.h"
    union {
        uint32_t raw;
        struct {
            uint32_t :31;
            _Bool cpuid_faulting:1;
        };
    } platform_info;
};





# 1 "/usr/local/include/xen/arch-x86/xen.h" 1 3
# 27 "/usr/local/include/xen/arch-x86/xen.h" 3
# 1 "/usr/local/include/xen/xen.h" 1 3
# 28 "/usr/local/include/xen/arch-x86/xen.h" 2 3
# 33 "/var/xen-dev/xen/xen/include/xen/lib/x86/msr.h" 2
typedef xen_msr_entry_t msr_entry_buffer_t[];
# 48 "/var/xen-dev/xen/xen/include/xen/lib/x86/msr.h"
int x86_msr_copy_to_buffer(const struct msr_policy *policy,
                           msr_entry_buffer_t msrs, uint32_t *nr_entries);
# 68 "/var/xen-dev/xen/xen/include/xen/lib/x86/msr.h"
int x86_msr_copy_from_buffer(struct msr_policy *policy,
                             const msr_entry_buffer_t msrs, uint32_t nr_entries,
                             uint32_t *err_msr);
# 11 "/var/xen-dev/xen/xen/include/asm/msr.h" 2

# 1 "/var/xen-dev/xen/xen/include/asm/asm_defns.h" 1






# 1 "/var/xen-dev/xen/xen/include/asm/asm-offsets.h" 1
# 8 "/var/xen-dev/xen/xen/include/asm/asm_defns.h" 2

# 1 "/var/xen-dev/xen/xen/include/asm/bug.h" 1
# 17 "/var/xen-dev/xen/xen/include/asm/bug.h"
struct bug_frame {
    signed int loc_disp:24;
    unsigned int line_hi:(31 - 24);
    signed int ptr_disp:24;
    unsigned int line_lo:(31 - 24);
    signed int msg_disp[];
};
# 75 "/var/xen-dev/xen/xen/include/asm/bug.h"
extern const struct bug_frame __start_bug_frames[],
                              __stop_bug_frames_0[],
                              __stop_bug_frames_1[],
                              __stop_bug_frames_2[],
                              __stop_bug_frames_3[];
# 10 "/var/xen-dev/xen/xen/include/asm/asm_defns.h" 2
# 1 "/var/xen-dev/xen/xen/include/asm/x86-defns.h" 1
# 11 "/var/xen-dev/xen/xen/include/asm/asm_defns.h" 2
# 1 "/var/xen-dev/xen/xen/include/xen/stringify.h" 1
# 12 "/var/xen-dev/xen/xen/include/asm/asm_defns.h" 2
# 1 "/var/xen-dev/xen/xen/include/asm/cpufeature.h" 1
# 9 "/var/xen-dev/xen/xen/include/asm/cpufeature.h"
# 1 "/var/xen-dev/xen/xen/include/xen/const.h" 1
# 10 "/var/xen-dev/xen/xen/include/asm/cpufeature.h" 2
# 1 "/var/xen-dev/xen/xen/include/asm/cpuid.h" 1



# 1 "/var/xen-dev/xen/xen/include/asm/cpufeatureset.h" 1
# 9 "/var/xen-dev/xen/xen/include/asm/cpufeatureset.h"
enum {
# 1 "/var/xen-dev/xen/xen/include/public/arch-x86/cpufeatureset.h" 1
# 93 "/var/xen-dev/xen/xen/include/public/arch-x86/cpufeatureset.h"
X86_FEATURE_FPU = 0*32+ 0,
X86_FEATURE_VME = 0*32+ 1,
X86_FEATURE_DE = 0*32+ 2,
X86_FEATURE_PSE = 0*32+ 3,
X86_FEATURE_TSC = 0*32+ 4,
X86_FEATURE_MSR = 0*32+ 5,
X86_FEATURE_PAE = 0*32+ 6,
X86_FEATURE_MCE = 0*32+ 7,
X86_FEATURE_CX8 = 0*32+ 8,
X86_FEATURE_APIC = 0*32+ 9,
X86_FEATURE_SEP = 0*32+11,
X86_FEATURE_MTRR = 0*32+12,
X86_FEATURE_PGE = 0*32+13,
X86_FEATURE_MCA = 0*32+14,
X86_FEATURE_CMOV = 0*32+15,
X86_FEATURE_PAT = 0*32+16,
X86_FEATURE_PSE36 = 0*32+17,
X86_FEATURE_CLFLUSH = 0*32+19,
X86_FEATURE_DS = 0*32+21,
X86_FEATURE_ACPI = 0*32+22,
X86_FEATURE_MMX = 0*32+23,
X86_FEATURE_FXSR = 0*32+24,
X86_FEATURE_SSE = 0*32+25,
X86_FEATURE_SSE2 = 0*32+26,
X86_FEATURE_SS = 0*32+27,
X86_FEATURE_HTT = 0*32+28,
X86_FEATURE_TM1 = 0*32+29,
X86_FEATURE_PBE = 0*32+31,


X86_FEATURE_SSE3 = 1*32+ 0,
X86_FEATURE_PCLMULQDQ = 1*32+ 1,
X86_FEATURE_DTES64 = 1*32+ 2,
X86_FEATURE_MONITOR = 1*32+ 3,
X86_FEATURE_DSCPL = 1*32+ 4,
X86_FEATURE_VMX = 1*32+ 5,
X86_FEATURE_SMX = 1*32+ 6,
X86_FEATURE_EIST = 1*32+ 7,
X86_FEATURE_TM2 = 1*32+ 8,
X86_FEATURE_SSSE3 = 1*32+ 9,
X86_FEATURE_FMA = 1*32+12,
X86_FEATURE_CX16 = 1*32+13,
X86_FEATURE_XTPR = 1*32+14,
X86_FEATURE_PDCM = 1*32+15,
X86_FEATURE_PCID = 1*32+17,
X86_FEATURE_DCA = 1*32+18,
X86_FEATURE_SSE4_1 = 1*32+19,
X86_FEATURE_SSE4_2 = 1*32+20,
X86_FEATURE_X2APIC = 1*32+21,
X86_FEATURE_MOVBE = 1*32+22,
X86_FEATURE_POPCNT = 1*32+23,
X86_FEATURE_TSC_DEADLINE = 1*32+24,
X86_FEATURE_AESNI = 1*32+25,
X86_FEATURE_XSAVE = 1*32+26,
X86_FEATURE_OSXSAVE = 1*32+27,
X86_FEATURE_AVX = 1*32+28,
X86_FEATURE_F16C = 1*32+29,
X86_FEATURE_RDRAND = 1*32+30,
X86_FEATURE_HYPERVISOR = 1*32+31,


X86_FEATURE_SYSCALL = 2*32+11,
X86_FEATURE_NX = 2*32+20,
X86_FEATURE_MMXEXT = 2*32+22,
X86_FEATURE_FFXSR = 2*32+25,
X86_FEATURE_PAGE1GB = 2*32+26,
X86_FEATURE_RDTSCP = 2*32+27,
X86_FEATURE_LM = 2*32+29,
X86_FEATURE_3DNOWEXT = 2*32+30,
X86_FEATURE_3DNOW = 2*32+31,


X86_FEATURE_LAHF_LM = 3*32+ 0,
X86_FEATURE_CMP_LEGACY = 3*32+ 1,
X86_FEATURE_SVM = 3*32+ 2,
X86_FEATURE_EXTAPIC = 3*32+ 3,
X86_FEATURE_CR8_LEGACY = 3*32+ 4,
X86_FEATURE_ABM = 3*32+ 5,
X86_FEATURE_SSE4A = 3*32+ 6,
X86_FEATURE_MISALIGNSSE = 3*32+ 7,
X86_FEATURE_3DNOWPREFETCH = 3*32+ 8,
X86_FEATURE_OSVW = 3*32+ 9,
X86_FEATURE_IBS = 3*32+10,
X86_FEATURE_XOP = 3*32+11,
X86_FEATURE_SKINIT = 3*32+12,
X86_FEATURE_WDT = 3*32+13,
X86_FEATURE_LWP = 3*32+15,
X86_FEATURE_FMA4 = 3*32+16,
X86_FEATURE_NODEID_MSR = 3*32+19,
X86_FEATURE_TBM = 3*32+21,
X86_FEATURE_TOPOEXT = 3*32+22,
X86_FEATURE_DBEXT = 3*32+26,
X86_FEATURE_MONITORX = 3*32+29,


X86_FEATURE_XSAVEOPT = 4*32+ 0,
X86_FEATURE_XSAVEC = 4*32+ 1,
X86_FEATURE_XGETBV1 = 4*32+ 2,
X86_FEATURE_XSAVES = 4*32+ 3,


X86_FEATURE_FSGSBASE = 5*32+ 0,
X86_FEATURE_TSC_ADJUST = 5*32+ 1,
X86_FEATURE_SGX = 5*32+ 2,
X86_FEATURE_BMI1 = 5*32+ 3,
X86_FEATURE_HLE = 5*32+ 4,
X86_FEATURE_AVX2 = 5*32+ 5,
X86_FEATURE_FDP_EXCP_ONLY = 5*32+ 6,
X86_FEATURE_SMEP = 5*32+ 7,
X86_FEATURE_BMI2 = 5*32+ 8,
X86_FEATURE_ERMS = 5*32+ 9,
X86_FEATURE_INVPCID = 5*32+10,
X86_FEATURE_RTM = 5*32+11,
X86_FEATURE_PQM = 5*32+12,
X86_FEATURE_NO_FPU_SEL = 5*32+13,
X86_FEATURE_MPX = 5*32+14,
X86_FEATURE_PQE = 5*32+15,
X86_FEATURE_AVX512F = 5*32+16,
X86_FEATURE_AVX512DQ = 5*32+17,
X86_FEATURE_RDSEED = 5*32+18,
X86_FEATURE_ADX = 5*32+19,
X86_FEATURE_SMAP = 5*32+20,
X86_FEATURE_AVX512_IFMA = 5*32+21,
X86_FEATURE_CLFLUSHOPT = 5*32+23,
X86_FEATURE_CLWB = 5*32+24,
X86_FEATURE_AVX512PF = 5*32+26,
X86_FEATURE_AVX512ER = 5*32+27,
X86_FEATURE_AVX512CD = 5*32+28,
X86_FEATURE_SHA = 5*32+29,
X86_FEATURE_AVX512BW = 5*32+30,
X86_FEATURE_AVX512VL = 5*32+31,


X86_FEATURE_PREFETCHWT1 = 6*32+ 0,
X86_FEATURE_AVX512_VBMI = 6*32+ 1,
X86_FEATURE_UMIP = 6*32+ 2,
X86_FEATURE_PKU = 6*32+ 3,
X86_FEATURE_OSPKE = 6*32+ 4,
X86_FEATURE_AVX512_VBMI2 = 6*32+ 6,
X86_FEATURE_GFNI = 6*32+ 8,
X86_FEATURE_VAES = 6*32+ 9,
X86_FEATURE_VPCLMULQDQ = 6*32+10,
X86_FEATURE_AVX512_VNNI = 6*32+11,
X86_FEATURE_AVX512_BITALG = 6*32+12,
X86_FEATURE_AVX512_VPOPCNTDQ = 6*32+14,
X86_FEATURE_RDPID = 6*32+22,
X86_FEATURE_CLDEMOTE = 6*32+25,


X86_FEATURE_ITSC = 7*32+ 8,
X86_FEATURE_EFRO = 7*32+10,


X86_FEATURE_CLZERO = 8*32+ 0,
X86_FEATURE_RSTR_FP_ERR_PTRS = 8*32+ 2,
X86_FEATURE_WBNOINVD = 8*32+ 9,
X86_FEATURE_IBPB = 8*32+12,


X86_FEATURE_AVX512_4VNNIW = 9*32+ 2,
X86_FEATURE_AVX512_4FMAPS = 9*32+ 3,
X86_FEATURE_MD_CLEAR = 9*32+10,
X86_FEATURE_TSX_FORCE_ABORT = 9*32+13,
X86_FEATURE_IBRSB = 9*32+26,
X86_FEATURE_STIBP = 9*32+27,
X86_FEATURE_L1D_FLUSH = 9*32+28,
X86_FEATURE_ARCH_CAPS = 9*32+29,
X86_FEATURE_SSBD = 9*32+31,


X86_FEATURE_AVX512_BF16 = 10*32+ 5,
# 11 "/var/xen-dev/xen/xen/include/asm/cpufeatureset.h" 2
# 1 "/var/xen-dev/xen/xen/include/asm/cpufeatures.h" 1




# 1 "/var/xen-dev/xen/xen/include/xen/lib/x86/cpuid-autogen.h" 1
# 6 "/var/xen-dev/xen/xen/include/asm/cpufeatures.h" 2
# 15 "/var/xen-dev/xen/xen/include/asm/cpufeatures.h"
X86_FEATURE_CONSTANT_TSC = (11 * 32 + (0)),
X86_FEATURE_NONSTOP_TSC = (11 * 32 + (1)),
X86_FEATURE_ARAT = (11 * 32 + (2)),
X86_FEATURE_ARCH_PERFMON = (11 * 32 + (3)),
X86_FEATURE_TSC_RELIABLE = (11 * 32 + (4)),
X86_FEATURE_XTOPOLOGY = (11 * 32 + (5)),
X86_FEATURE_CPUID_FAULTING = (11 * 32 + (6)),
X86_FEATURE_CLFLUSH_MONITOR = (11 * 32 + (7)),
X86_FEATURE_APERFMPERF = (11 * 32 + (8)),
X86_FEATURE_MFENCE_RDTSC = (11 * 32 + (9)),
X86_FEATURE_XEN_SMEP = (11 * 32 + (10)),
X86_FEATURE_XEN_SMAP = (11 * 32 + (11)),
X86_FEATURE_LFENCE_DISPATCH = (11 * 32 + (12)),
X86_FEATURE_IND_THUNK_LFENCE = (11 * 32 + (13)),
X86_FEATURE_IND_THUNK_JMP = (11 * 32 + (14)),
X86_FEATURE_SC_BRANCH_HARDEN = (11 * 32 + (15)),
X86_FEATURE_SC_MSR_PV = (11 * 32 + (16)),
X86_FEATURE_SC_MSR_HVM = (11 * 32 + (17)),
X86_FEATURE_SC_RSB_PV = (11 * 32 + (18)),
X86_FEATURE_SC_RSB_HVM = (11 * 32 + (19)),
X86_FEATURE_XEN_SELFSNOOP = (11 * 32 + (20)),
X86_FEATURE_SC_MSR_IDLE = (11 * 32 + (21)),
X86_FEATURE_XEN_LBR = (11 * 32 + (22)),
X86_FEATURE_SC_VERW_PV = (11 * 32 + (23)),
X86_FEATURE_SC_VERW_HVM = (11 * 32 + (24)),
X86_FEATURE_SC_VERW_IDLE = (11 * 32 + (25)),
# 12 "/var/xen-dev/xen/xen/include/asm/cpufeatureset.h" 2
};




# 1 "/var/xen-dev/xen/xen/include/public/arch-x86/cpufeatureset.h" 1
# 93 "/var/xen-dev/xen/xen/include/public/arch-x86/cpufeatureset.h"
asm (".equ X86_FEATURE_" "FPU" ", " "0*32+ 0");
asm (".equ X86_FEATURE_" "VME" ", " "0*32+ 1");
asm (".equ X86_FEATURE_" "DE" ", " "0*32+ 2");
asm (".equ X86_FEATURE_" "PSE" ", " "0*32+ 3");
asm (".equ X86_FEATURE_" "TSC" ", " "0*32+ 4");
asm (".equ X86_FEATURE_" "MSR" ", " "0*32+ 5");
asm (".equ X86_FEATURE_" "PAE" ", " "0*32+ 6");
asm (".equ X86_FEATURE_" "MCE" ", " "0*32+ 7");
asm (".equ X86_FEATURE_" "CX8" ", " "0*32+ 8");
asm (".equ X86_FEATURE_" "APIC" ", " "0*32+ 9");
asm (".equ X86_FEATURE_" "SEP" ", " "0*32+11");
asm (".equ X86_FEATURE_" "MTRR" ", " "0*32+12");
asm (".equ X86_FEATURE_" "PGE" ", " "0*32+13");
asm (".equ X86_FEATURE_" "MCA" ", " "0*32+14");
asm (".equ X86_FEATURE_" "CMOV" ", " "0*32+15");
asm (".equ X86_FEATURE_" "PAT" ", " "0*32+16");
asm (".equ X86_FEATURE_" "PSE36" ", " "0*32+17");
asm (".equ X86_FEATURE_" "CLFLUSH" ", " "0*32+19");
asm (".equ X86_FEATURE_" "DS" ", " "0*32+21");
asm (".equ X86_FEATURE_" "ACPI" ", " "0*32+22");
asm (".equ X86_FEATURE_" "MMX" ", " "0*32+23");
asm (".equ X86_FEATURE_" "FXSR" ", " "0*32+24");
asm (".equ X86_FEATURE_" "SSE" ", " "0*32+25");
asm (".equ X86_FEATURE_" "SSE2" ", " "0*32+26");
asm (".equ X86_FEATURE_" "SS" ", " "0*32+27");
asm (".equ X86_FEATURE_" "HTT" ", " "0*32+28");
asm (".equ X86_FEATURE_" "TM1" ", " "0*32+29");
asm (".equ X86_FEATURE_" "PBE" ", " "0*32+31");


asm (".equ X86_FEATURE_" "SSE3" ", " "1*32+ 0");
asm (".equ X86_FEATURE_" "PCLMULQDQ" ", " "1*32+ 1");
asm (".equ X86_FEATURE_" "DTES64" ", " "1*32+ 2");
asm (".equ X86_FEATURE_" "MONITOR" ", " "1*32+ 3");
asm (".equ X86_FEATURE_" "DSCPL" ", " "1*32+ 4");
asm (".equ X86_FEATURE_" "VMX" ", " "1*32+ 5");
asm (".equ X86_FEATURE_" "SMX" ", " "1*32+ 6");
asm (".equ X86_FEATURE_" "EIST" ", " "1*32+ 7");
asm (".equ X86_FEATURE_" "TM2" ", " "1*32+ 8");
asm (".equ X86_FEATURE_" "SSSE3" ", " "1*32+ 9");
asm (".equ X86_FEATURE_" "FMA" ", " "1*32+12");
asm (".equ X86_FEATURE_" "CX16" ", " "1*32+13");
asm (".equ X86_FEATURE_" "XTPR" ", " "1*32+14");
asm (".equ X86_FEATURE_" "PDCM" ", " "1*32+15");
asm (".equ X86_FEATURE_" "PCID" ", " "1*32+17");
asm (".equ X86_FEATURE_" "DCA" ", " "1*32+18");
asm (".equ X86_FEATURE_" "SSE4_1" ", " "1*32+19");
asm (".equ X86_FEATURE_" "SSE4_2" ", " "1*32+20");
asm (".equ X86_FEATURE_" "X2APIC" ", " "1*32+21");
asm (".equ X86_FEATURE_" "MOVBE" ", " "1*32+22");
asm (".equ X86_FEATURE_" "POPCNT" ", " "1*32+23");
asm (".equ X86_FEATURE_" "TSC_DEADLINE" ", " "1*32+24");
asm (".equ X86_FEATURE_" "AESNI" ", " "1*32+25");
asm (".equ X86_FEATURE_" "XSAVE" ", " "1*32+26");
asm (".equ X86_FEATURE_" "OSXSAVE" ", " "1*32+27");
asm (".equ X86_FEATURE_" "AVX" ", " "1*32+28");
asm (".equ X86_FEATURE_" "F16C" ", " "1*32+29");
asm (".equ X86_FEATURE_" "RDRAND" ", " "1*32+30");
asm (".equ X86_FEATURE_" "HYPERVISOR" ", " "1*32+31");


asm (".equ X86_FEATURE_" "SYSCALL" ", " "2*32+11");
asm (".equ X86_FEATURE_" "NX" ", " "2*32+20");
asm (".equ X86_FEATURE_" "MMXEXT" ", " "2*32+22");
asm (".equ X86_FEATURE_" "FFXSR" ", " "2*32+25");
asm (".equ X86_FEATURE_" "PAGE1GB" ", " "2*32+26");
asm (".equ X86_FEATURE_" "RDTSCP" ", " "2*32+27");
asm (".equ X86_FEATURE_" "LM" ", " "2*32+29");
asm (".equ X86_FEATURE_" "3DNOWEXT" ", " "2*32+30");
asm (".equ X86_FEATURE_" "3DNOW" ", " "2*32+31");


asm (".equ X86_FEATURE_" "LAHF_LM" ", " "3*32+ 0");
asm (".equ X86_FEATURE_" "CMP_LEGACY" ", " "3*32+ 1");
asm (".equ X86_FEATURE_" "SVM" ", " "3*32+ 2");
asm (".equ X86_FEATURE_" "EXTAPIC" ", " "3*32+ 3");
asm (".equ X86_FEATURE_" "CR8_LEGACY" ", " "3*32+ 4");
asm (".equ X86_FEATURE_" "ABM" ", " "3*32+ 5");
asm (".equ X86_FEATURE_" "SSE4A" ", " "3*32+ 6");
asm (".equ X86_FEATURE_" "MISALIGNSSE" ", " "3*32+ 7");
asm (".equ X86_FEATURE_" "3DNOWPREFETCH" ", " "3*32+ 8");
asm (".equ X86_FEATURE_" "OSVW" ", " "3*32+ 9");
asm (".equ X86_FEATURE_" "IBS" ", " "3*32+10");
asm (".equ X86_FEATURE_" "XOP" ", " "3*32+11");
asm (".equ X86_FEATURE_" "SKINIT" ", " "3*32+12");
asm (".equ X86_FEATURE_" "WDT" ", " "3*32+13");
asm (".equ X86_FEATURE_" "LWP" ", " "3*32+15");
asm (".equ X86_FEATURE_" "FMA4" ", " "3*32+16");
asm (".equ X86_FEATURE_" "NODEID_MSR" ", " "3*32+19");
asm (".equ X86_FEATURE_" "TBM" ", " "3*32+21");
asm (".equ X86_FEATURE_" "TOPOEXT" ", " "3*32+22");
asm (".equ X86_FEATURE_" "DBEXT" ", " "3*32+26");
asm (".equ X86_FEATURE_" "MONITORX" ", " "3*32+29");


asm (".equ X86_FEATURE_" "XSAVEOPT" ", " "4*32+ 0");
asm (".equ X86_FEATURE_" "XSAVEC" ", " "4*32+ 1");
asm (".equ X86_FEATURE_" "XGETBV1" ", " "4*32+ 2");
asm (".equ X86_FEATURE_" "XSAVES" ", " "4*32+ 3");


asm (".equ X86_FEATURE_" "FSGSBASE" ", " "5*32+ 0");
asm (".equ X86_FEATURE_" "TSC_ADJUST" ", " "5*32+ 1");
asm (".equ X86_FEATURE_" "SGX" ", " "5*32+ 2");
asm (".equ X86_FEATURE_" "BMI1" ", " "5*32+ 3");
asm (".equ X86_FEATURE_" "HLE" ", " "5*32+ 4");
asm (".equ X86_FEATURE_" "AVX2" ", " "5*32+ 5");
asm (".equ X86_FEATURE_" "FDP_EXCP_ONLY" ", " "5*32+ 6");
asm (".equ X86_FEATURE_" "SMEP" ", " "5*32+ 7");
asm (".equ X86_FEATURE_" "BMI2" ", " "5*32+ 8");
asm (".equ X86_FEATURE_" "ERMS" ", " "5*32+ 9");
asm (".equ X86_FEATURE_" "INVPCID" ", " "5*32+10");
asm (".equ X86_FEATURE_" "RTM" ", " "5*32+11");
asm (".equ X86_FEATURE_" "PQM" ", " "5*32+12");
asm (".equ X86_FEATURE_" "NO_FPU_SEL" ", " "5*32+13");
asm (".equ X86_FEATURE_" "MPX" ", " "5*32+14");
asm (".equ X86_FEATURE_" "PQE" ", " "5*32+15");
asm (".equ X86_FEATURE_" "AVX512F" ", " "5*32+16");
asm (".equ X86_FEATURE_" "AVX512DQ" ", " "5*32+17");
asm (".equ X86_FEATURE_" "RDSEED" ", " "5*32+18");
asm (".equ X86_FEATURE_" "ADX" ", " "5*32+19");
asm (".equ X86_FEATURE_" "SMAP" ", " "5*32+20");
asm (".equ X86_FEATURE_" "AVX512_IFMA" ", " "5*32+21");
asm (".equ X86_FEATURE_" "CLFLUSHOPT" ", " "5*32+23");
asm (".equ X86_FEATURE_" "CLWB" ", " "5*32+24");
asm (".equ X86_FEATURE_" "AVX512PF" ", " "5*32+26");
asm (".equ X86_FEATURE_" "AVX512ER" ", " "5*32+27");
asm (".equ X86_FEATURE_" "AVX512CD" ", " "5*32+28");
asm (".equ X86_FEATURE_" "SHA" ", " "5*32+29");
asm (".equ X86_FEATURE_" "AVX512BW" ", " "5*32+30");
asm (".equ X86_FEATURE_" "AVX512VL" ", " "5*32+31");


asm (".equ X86_FEATURE_" "PREFETCHWT1" ", " "6*32+ 0");
asm (".equ X86_FEATURE_" "AVX512_VBMI" ", " "6*32+ 1");
asm (".equ X86_FEATURE_" "UMIP" ", " "6*32+ 2");
asm (".equ X86_FEATURE_" "PKU" ", " "6*32+ 3");
asm (".equ X86_FEATURE_" "OSPKE" ", " "6*32+ 4");
asm (".equ X86_FEATURE_" "AVX512_VBMI2" ", " "6*32+ 6");
asm (".equ X86_FEATURE_" "GFNI" ", " "6*32+ 8");
asm (".equ X86_FEATURE_" "VAES" ", " "6*32+ 9");
asm (".equ X86_FEATURE_" "VPCLMULQDQ" ", " "6*32+10");
asm (".equ X86_FEATURE_" "AVX512_VNNI" ", " "6*32+11");
asm (".equ X86_FEATURE_" "AVX512_BITALG" ", " "6*32+12");
asm (".equ X86_FEATURE_" "AVX512_VPOPCNTDQ" ", " "6*32+14");
asm (".equ X86_FEATURE_" "RDPID" ", " "6*32+22");
asm (".equ X86_FEATURE_" "CLDEMOTE" ", " "6*32+25");


asm (".equ X86_FEATURE_" "ITSC" ", " "7*32+ 8");
asm (".equ X86_FEATURE_" "EFRO" ", " "7*32+10");


asm (".equ X86_FEATURE_" "CLZERO" ", " "8*32+ 0");
asm (".equ X86_FEATURE_" "RSTR_FP_ERR_PTRS" ", " "8*32+ 2");
asm (".equ X86_FEATURE_" "WBNOINVD" ", " "8*32+ 9");
asm (".equ X86_FEATURE_" "IBPB" ", " "8*32+12");


asm (".equ X86_FEATURE_" "AVX512_4VNNIW" ", " "9*32+ 2");
asm (".equ X86_FEATURE_" "AVX512_4FMAPS" ", " "9*32+ 3");
asm (".equ X86_FEATURE_" "MD_CLEAR" ", " "9*32+10");
asm (".equ X86_FEATURE_" "TSX_FORCE_ABORT" ", " "9*32+13");
asm (".equ X86_FEATURE_" "IBRSB" ", " "9*32+26");
asm (".equ X86_FEATURE_" "STIBP" ", " "9*32+27");
asm (".equ X86_FEATURE_" "L1D_FLUSH" ", " "9*32+28");
asm (".equ X86_FEATURE_" "ARCH_CAPS" ", " "9*32+29");
asm (".equ X86_FEATURE_" "SSBD" ", " "9*32+31");


asm (".equ X86_FEATURE_" "AVX512_BF16" ", " "10*32+ 5");
# 18 "/var/xen-dev/xen/xen/include/asm/cpufeatureset.h" 2
# 1 "/var/xen-dev/xen/xen/include/asm/cpufeatures.h" 1
# 15 "/var/xen-dev/xen/xen/include/asm/cpufeatures.h"
asm (".equ X86_FEATURE_" "CONSTANT_TSC" ", " "(11 * 32 + (0))");
asm (".equ X86_FEATURE_" "NONSTOP_TSC" ", " "(11 * 32 + (1))");
asm (".equ X86_FEATURE_" "ARAT" ", " "(11 * 32 + (2))");
asm (".equ X86_FEATURE_" "ARCH_PERFMON" ", " "(11 * 32 + (3))");
asm (".equ X86_FEATURE_" "TSC_RELIABLE" ", " "(11 * 32 + (4))");
asm (".equ X86_FEATURE_" "XTOPOLOGY" ", " "(11 * 32 + (5))");
asm (".equ X86_FEATURE_" "CPUID_FAULTING" ", " "(11 * 32 + (6))");
asm (".equ X86_FEATURE_" "CLFLUSH_MONITOR" ", " "(11 * 32 + (7))");
asm (".equ X86_FEATURE_" "APERFMPERF" ", " "(11 * 32 + (8))");
asm (".equ X86_FEATURE_" "MFENCE_RDTSC" ", " "(11 * 32 + (9))");
asm (".equ X86_FEATURE_" "XEN_SMEP" ", " "(11 * 32 + (10))");
asm (".equ X86_FEATURE_" "XEN_SMAP" ", " "(11 * 32 + (11))");
asm (".equ X86_FEATURE_" "LFENCE_DISPATCH" ", " "(11 * 32 + (12))");
asm (".equ X86_FEATURE_" "IND_THUNK_LFENCE" ", " "(11 * 32 + (13))");
asm (".equ X86_FEATURE_" "IND_THUNK_JMP" ", " "(11 * 32 + (14))");
asm (".equ X86_FEATURE_" "SC_BRANCH_HARDEN" ", " "(11 * 32 + (15))");
asm (".equ X86_FEATURE_" "SC_MSR_PV" ", " "(11 * 32 + (16))");
asm (".equ X86_FEATURE_" "SC_MSR_HVM" ", " "(11 * 32 + (17))");
asm (".equ X86_FEATURE_" "SC_RSB_PV" ", " "(11 * 32 + (18))");
asm (".equ X86_FEATURE_" "SC_RSB_HVM" ", " "(11 * 32 + (19))");
asm (".equ X86_FEATURE_" "XEN_SELFSNOOP" ", " "(11 * 32 + (20))");
asm (".equ X86_FEATURE_" "SC_MSR_IDLE" ", " "(11 * 32 + (21))");
asm (".equ X86_FEATURE_" "XEN_LBR" ", " "(11 * 32 + (22))");
asm (".equ X86_FEATURE_" "SC_VERW_PV" ", " "(11 * 32 + (23))");
asm (".equ X86_FEATURE_" "SC_VERW_HVM" ", " "(11 * 32 + (24))");
asm (".equ X86_FEATURE_" "SC_VERW_IDLE" ", " "(11 * 32 + (25))");
# 19 "/var/xen-dev/xen/xen/include/asm/cpufeatureset.h" 2
# 5 "/var/xen-dev/xen/xen/include/asm/cpuid.h" 2



# 1 "/var/xen-dev/xen/xen/include/xen/kernel.h" 1
# 68 "/var/xen-dev/xen/xen/include/xen/kernel.h"
extern char _start[], _end[], start[];





extern char _stext[], _etext[];





extern const char _srodata[], _erodata[];





extern char _sinittext[], _einittext[];





extern enum system_state {
    SYS_STATE_early_boot,
    SYS_STATE_boot,
    SYS_STATE_smp_boot,
    SYS_STATE_active,
    SYS_STATE_suspend,
    SYS_STATE_resume
} system_state;

bool_t is_active_kernel_text(unsigned long addr);
# 9 "/var/xen-dev/xen/xen/include/asm/cpuid.h" 2


# 1 "/var/xen-dev/xen/xen/include/xen/lib/x86/cpu-policy.h" 1




# 1 "/var/xen-dev/xen/xen/include/xen/lib/x86/cpuid.h" 1
# 19 "/var/xen-dev/xen/xen/include/xen/lib/x86/cpuid.h"
struct cpuid_leaf
{
    uint32_t a, b, c, d;
};
# 47 "/var/xen-dev/xen/xen/include/xen/lib/x86/cpuid.h"
static __inline__ void cpuid_leaf(uint32_t leaf, struct cpuid_leaf *l)
{
    asm ( ""
          "cpuid;"
          ""
          : "=a" (l->a), "=&b" (l->b), "=&c" (l->c), "=&d" (l->d)
          : "a" (leaf) );
}

static __inline__ void cpuid_count_leaf(
    uint32_t leaf, uint32_t subleaf, struct cpuid_leaf *l)
{
    asm ( ""
          "cpuid;"
          ""
          : "=a" (l->a), "=&b" (l->b), "=c" (l->c), "=&d" (l->d)
          : "a" (leaf), "c" (subleaf) );
}
# 73 "/var/xen-dev/xen/xen/include/xen/lib/x86/cpuid.h"
unsigned int x86_cpuid_lookup_vendor(uint32_t ebx, uint32_t ecx, uint32_t edx);





const char *x86_cpuid_vendor_to_str(unsigned int vendor);
# 104 "/var/xen-dev/xen/xen/include/xen/lib/x86/cpuid.h"
struct cpuid_policy
{





    union {
        struct cpuid_leaf raw[(0xdu + 1)];
        struct {

            uint32_t max_leaf, vendor_ebx, vendor_ecx, vendor_edx;


            uint32_t raw_fms;
            uint8_t :8,
                clflush_size,
                lppp,
                apic_id;
            union {
                uint32_t _1c;
                struct { _Bool sse3:1, pclmulqdq:1, dtes64:1, monitor:1, dscpl:1, vmx:1, smx:1, eist:1, tm2:1, ssse3:1, :1, :1, fma:1, cx16:1, xtpr:1, pdcm:1, :1, pcid:1, dca:1, sse4_1:1, sse4_2:1, x2apic:1, movbe:1, popcnt:1, tsc_deadline:1, aesni:1, xsave:1, :1, avx:1, f16c:1, rdrand:1, hypervisor:1; };
            };
            union {
                uint32_t _1d;
                struct { _Bool fpu:1, vme:1, de:1, pse:1, tsc:1, msr:1, pae:1, mce:1, cx8:1, :1, :1, sep:1, mtrr:1, pge:1, mca:1, cmov:1, pat:1, pse36:1, :1, clflush:1, :1, ds:1, acpi:1, mmx:1, fxsr:1, sse:1, sse2:1, ss:1, htt:1, tm1:1, :1, pbe:1; };
            };


            uint8_t l2_nr_queries;
            uint8_t l2_desc[15];

            uint64_t :64, :64;
            uint64_t :64, :64;
            uint64_t :64, :64;
            uint64_t :64, :64;
            uint64_t :64, :64;
            uint64_t :64, :64;
            uint64_t :64, :64;


            uint8_t pmu_version, _pmu[15];

            uint64_t :64, :64;
            uint64_t :64, :64;
            uint64_t :64, :64;
        };
    } basic;


    union {
        struct cpuid_leaf raw[(5u + 1)];
        struct cpuid_cache_leaf {
            uint32_t type:5, level:3;
            _Bool self_init:1, fully_assoc:1;
            uint32_t :4, threads_per_cache:12, cores_per_package:6;
            uint32_t line_size:12, partitions:10, ways:10;
            uint32_t sets;
            _Bool wbinvd:1, inclusive:1, complex:1;
        } subleaf[(5u + 1)];
    } cache;


    union {
        struct cpuid_leaf raw[(1u + 1)];
        struct {

            uint32_t max_subleaf;
            union {
                uint32_t _7b0;
                struct { _Bool fsgsbase:1, tsc_adjust:1, sgx:1, bmi1:1, hle:1, avx2:1, fdp_excp_only:1, smep:1, bmi2:1, erms:1, invpcid:1, rtm:1, pqm:1, no_fpu_sel:1, mpx:1, pqe:1, avx512f:1, avx512dq:1, rdseed:1, adx:1, smap:1, avx512_ifma:1, :1, clflushopt:1, clwb:1, :1, avx512pf:1, avx512er:1, avx512cd:1, sha:1, avx512bw:1, avx512vl:1; };
            };
            union {
                uint32_t _7c0;
                struct { _Bool prefetchwt1:1, avx512_vbmi:1, umip:1, pku:1, :1, :1, avx512_vbmi2:1, :1, gfni:1, vaes:1, vpclmulqdq:1, avx512_vnni:1, avx512_bitalg:1, :1, avx512_vpopcntdq:1, :1, :1, :1, :1, :1, :1, :1, rdpid:1, :1, :1, cldemote:1, :1, :1, :1, :1, :1, :1; };
            };
            union {
                uint32_t _7d0;
                struct { _Bool :1, :1, avx512_4vnniw:1, avx512_4fmaps:1, :1, :1, :1, :1, :1, :1, md_clear:1, :1, :1, tsx_force_abort:1, :1, :1, :1, :1, :1, :1, :1, :1, :1, :1, :1, :1, ibrsb:1, stibp:1, l1d_flush:1, arch_caps:1, :1, ssbd:1; };
            };
        };
        struct {

            union {
                uint32_t _7a1;
                struct { _Bool :1, :1, :1, :1, :1, avx512_bf16:1, :1, :1, :1, :1, :1, :1, :1, :1, :1, :1, :1, :1, :1, :1, :1, :1, :1, :1, :1, :1, :1, :1, :1, :1, :1, :1; };
            };
        };
    } feat;


    union {
        struct cpuid_leaf raw[(1u + 1)];
        struct cpuid_topo_leaf {
            uint32_t id_shift:5, :27;
            uint16_t nr_logical, :16;
            uint8_t level, type, :8, :8;
            uint32_t x2apic_id;
        } subleaf[(1u + 1)];
    } topo;


    union {
        struct cpuid_leaf raw[(62u + 1)];

        struct {

            uint32_t xcr0_low, :32, max_size, xcr0_high;


            union {
                uint32_t Da1;
                struct { _Bool xsaveopt:1, xsavec:1, xgetbv1:1, xsaves:1, :1, :1, :1, :1, :1, :1, :1, :1, :1, :1, :1, :1, :1, :1, :1, :1, :1, :1, :1, :1, :1, :1, :1, :1, :1, :1, :1, :1; };
            };
            uint32_t :32, xss_low, xss_high;
        };


        struct {
            uint32_t size, offset;
            _Bool xss:1, align:1;
            uint32_t _res_d;
        } comp[(62u + 1)];
    } xstate;


    union {
        struct cpuid_leaf raw[(((0x8u + 1)) > ((0x1cu + 1)) ? ((0x8u + 1)) : ((0x1cu + 1)))];
        struct {

            uint32_t max_leaf, vendor_ebx, vendor_ecx, vendor_edx;


            uint32_t raw_fms, :32;
            union {
                uint32_t e1c;
                struct { _Bool lahf_lm:1, cmp_legacy:1, svm:1, extapic:1, cr8_legacy:1, abm:1, sse4a:1, misalignsse:1, _3dnowprefetch:1, osvw:1, ibs:1, xop:1, skinit:1, wdt:1, :1, lwp:1, fma4:1, :1, :1, nodeid_msr:1, :1, tbm:1, topoext:1, :1, :1, :1, dbext:1, :1, :1, monitorx:1, :1, :1; };
            };
            union {
                uint32_t e1d;
                struct { _Bool :1, :1, :1, :1, :1, :1, :1, :1, :1, :1, :1, syscall:1, :1, :1, :1, :1, :1, :1, :1, :1, nx:1, :1, mmxext:1, :1, :1, ffxsr:1, page1gb:1, rdtscp:1, :1, lm:1, _3dnowext:1, _3dnow:1; };
            };

            uint64_t :64, :64;
            uint64_t :64, :64;
            uint64_t :64, :64;
            uint64_t :64, :64;
            uint64_t :64, :64;


            uint32_t :32, :32, :32;
            union {
                uint32_t e7d;
                struct { _Bool :1, :1, :1, :1, :1, :1, :1, :1, itsc:1, :1, efro:1, :1, :1, :1, :1, :1, :1, :1, :1, :1, :1, :1, :1, :1, :1, :1, :1, :1, :1, :1, :1, :1; };
            };


            uint8_t maxphysaddr, maxlinaddr, :8, :8;
            union {
                uint32_t e8b;
                struct { _Bool clzero:1, :1, rstr_fp_err_ptrs:1, :1, :1, :1, :1, :1, :1, wbnoinvd:1, :1, :1, ibpb:1, :1, :1, :1, :1, :1, :1, :1, :1, :1, :1, :1, :1, :1, :1, :1, :1, :1, :1, :1; };
            };
            uint32_t nc:8, :4, apic_id_size:4, :16;
            uint32_t :32;
        };
    } extd;






    uint8_t hv_limit, hv2_limit;


    uint8_t x86_vendor;
};


static __inline__ void cpuid_policy_to_featureset(
    const struct cpuid_policy *p, uint32_t fs[11])
{
    fs[0] = p->basic._1d;
    fs[1] = p->basic._1c;
    fs[2] = p->extd.e1d;
    fs[3] = p->extd.e1c;
    fs[4] = p->xstate.Da1;
    fs[5] = p->feat._7b0;
    fs[6] = p->feat._7c0;
    fs[7] = p->extd.e7d;
    fs[8] = p->extd.e8b;
    fs[9] = p->feat._7d0;
    fs[10] = p->feat._7a1;
}


static __inline__ void cpuid_featureset_to_policy(
    const uint32_t fs[11], struct cpuid_policy *p)
{
    p->basic._1d = fs[0];
    p->basic._1c = fs[1];
    p->extd.e1d = fs[2];
    p->extd.e1c = fs[3];
    p->xstate.Da1 = fs[4];
    p->feat._7b0 = fs[5];
    p->feat._7c0 = fs[6];
    p->extd.e7d = fs[7];
    p->extd.e8b = fs[8];
    p->feat._7d0 = fs[9];
    p->feat._7a1 = fs[10];
}

static __inline__ uint64_t cpuid_policy_xcr0_max(const struct cpuid_policy *p)
{
    return ((uint64_t)p->xstate.xcr0_high << 32) | p->xstate.xcr0_low;
}

static __inline__ uint64_t cpuid_policy_xstates(const struct cpuid_policy *p)
{
    uint64_t val = p->xstate.xcr0_high | p->xstate.xss_high;

    return (val << 32) | p->xstate.xcr0_low | p->xstate.xss_low;
}

const uint32_t *x86_cpuid_lookup_deep_deps(uint32_t feature);




void x86_cpuid_policy_recalc_synth(struct cpuid_policy *p);
# 342 "/var/xen-dev/xen/xen/include/xen/lib/x86/cpuid.h"
void x86_cpuid_policy_fill_native(struct cpuid_policy *p);
# 353 "/var/xen-dev/xen/xen/include/xen/lib/x86/cpuid.h"
void x86_cpuid_policy_clear_out_of_range_leaves(struct cpuid_policy *p);





# 1 "/usr/local/include/xen/arch-x86/xen.h" 1 3
# 360 "/var/xen-dev/xen/xen/include/xen/lib/x86/cpuid.h" 2
typedef xen_cpuid_leaf_t cpuid_leaf_buffer_t[];
# 375 "/var/xen-dev/xen/xen/include/xen/lib/x86/cpuid.h"
int x86_cpuid_copy_to_buffer(const struct cpuid_policy *policy,
                             cpuid_leaf_buffer_t leaves, uint32_t *nr_entries);
# 395 "/var/xen-dev/xen/xen/include/xen/lib/x86/cpuid.h"
int x86_cpuid_copy_from_buffer(struct cpuid_policy *policy,
                               const cpuid_leaf_buffer_t leaves,
                               uint32_t nr_entries, uint32_t *err_leaf,
                               uint32_t *err_subleaf);
# 6 "/var/xen-dev/xen/xen/include/xen/lib/x86/cpu-policy.h" 2


struct cpu_policy
{
    struct cpuid_policy *cpuid;
    struct msr_policy *msr;
};

struct cpu_policy_errors
{
    uint32_t leaf, subleaf;
    uint32_t msr;
};
# 36 "/var/xen-dev/xen/xen/include/xen/lib/x86/cpu-policy.h"
int x86_cpu_policies_are_compatible(const struct cpu_policy *host,
                                    const struct cpu_policy *guest,
                                    struct cpu_policy_errors *err);
# 12 "/var/xen-dev/xen/xen/include/asm/cpuid.h" 2


# 1 "/var/xen-dev/xen/xen/include/public/sysctl.h" 1
# 34 "/var/xen-dev/xen/xen/include/public/sysctl.h"
# 1 "/var/xen-dev/xen/xen/include/public/xen.h" 1
# 35 "/var/xen-dev/xen/xen/include/public/sysctl.h" 2
# 1 "/var/xen-dev/xen/xen/include/public/domctl.h" 1
# 36 "/var/xen-dev/xen/xen/include/public/domctl.h"
# 1 "/var/xen-dev/xen/xen/include/public/event_channel.h" 1
# 79 "/var/xen-dev/xen/xen/include/public/event_channel.h"
typedef uint32_t evtchn_port_t;
typedef evtchn_port_t * __guest_handle_evtchn_port_t; typedef const evtchn_port_t * __guest_handle_const_evtchn_port_t;
# 90 "/var/xen-dev/xen/xen/include/public/event_channel.h"
struct evtchn_alloc_unbound {

    domid_t dom, remote_dom;

    evtchn_port_t port;
};
typedef struct evtchn_alloc_unbound evtchn_alloc_unbound_t;
# 118 "/var/xen-dev/xen/xen/include/public/event_channel.h"
struct evtchn_bind_interdomain {

    domid_t remote_dom;
    evtchn_port_t remote_port;

    evtchn_port_t local_port;
};
typedef struct evtchn_bind_interdomain evtchn_bind_interdomain_t;
# 139 "/var/xen-dev/xen/xen/include/public/event_channel.h"
struct evtchn_bind_virq {

    uint32_t virq;
    uint32_t vcpu;

    evtchn_port_t port;
};
typedef struct evtchn_bind_virq evtchn_bind_virq_t;







struct evtchn_bind_pirq {

    uint32_t pirq;

    uint32_t flags;

    evtchn_port_t port;
};
typedef struct evtchn_bind_pirq evtchn_bind_pirq_t;







struct evtchn_bind_ipi {
    uint32_t vcpu;

    evtchn_port_t port;
};
typedef struct evtchn_bind_ipi evtchn_bind_ipi_t;






struct evtchn_close {

    evtchn_port_t port;
};
typedef struct evtchn_close evtchn_close_t;





struct evtchn_send {

    evtchn_port_t port;
};
typedef struct evtchn_send evtchn_send_t;
# 206 "/var/xen-dev/xen/xen/include/public/event_channel.h"
struct evtchn_status {

    domid_t dom;
    evtchn_port_t port;







    uint32_t status;
    uint32_t vcpu;
    union {
        struct {
            domid_t dom;
        } unbound;
        struct {
            domid_t dom;
            evtchn_port_t port;
        } interdomain;
        uint32_t pirq;
        uint32_t virq;
    } u;
};
typedef struct evtchn_status evtchn_status_t;
# 245 "/var/xen-dev/xen/xen/include/public/event_channel.h"
struct evtchn_bind_vcpu {

    evtchn_port_t port;
    uint32_t vcpu;
};
typedef struct evtchn_bind_vcpu evtchn_bind_vcpu_t;





struct evtchn_unmask {

    evtchn_port_t port;
};
typedef struct evtchn_unmask evtchn_unmask_t;
# 272 "/var/xen-dev/xen/xen/include/public/event_channel.h"
struct evtchn_reset {

    domid_t dom;
};
typedef struct evtchn_reset evtchn_reset_t;
# 285 "/var/xen-dev/xen/xen/include/public/event_channel.h"
struct evtchn_init_control {

    uint64_t control_gfn;
    uint32_t offset;
    uint32_t vcpu;

    uint8_t link_bits;
    uint8_t _pad[7];
};
typedef struct evtchn_init_control evtchn_init_control_t;




struct evtchn_expand_array {

    uint64_t array_gfn;
};
typedef struct evtchn_expand_array evtchn_expand_array_t;




struct evtchn_set_priority {

    uint32_t port;
    uint32_t priority;
};
typedef struct evtchn_set_priority evtchn_set_priority_t;







struct evtchn_op {
    uint32_t cmd;
    union {
        struct evtchn_alloc_unbound alloc_unbound;
        struct evtchn_bind_interdomain bind_interdomain;
        struct evtchn_bind_virq bind_virq;
        struct evtchn_bind_pirq bind_pirq;
        struct evtchn_bind_ipi bind_ipi;
        struct evtchn_close close;
        struct evtchn_send send;
        struct evtchn_status status;
        struct evtchn_bind_vcpu bind_vcpu;
        struct evtchn_unmask unmask;
    } u;
};
typedef struct evtchn_op evtchn_op_t;
typedef evtchn_op_t * __guest_handle_evtchn_op_t; typedef const evtchn_op_t * __guest_handle_const_evtchn_op_t;
# 356 "/var/xen-dev/xen/xen/include/public/event_channel.h"
typedef uint32_t event_word_t;
# 368 "/var/xen-dev/xen/xen/include/public/event_channel.h"
struct evtchn_fifo_control_block {
    uint32_t ready;
    uint32_t _rsvd;
    uint32_t head[(15 + 1)];
};
typedef struct evtchn_fifo_control_block evtchn_fifo_control_block_t;
# 37 "/var/xen-dev/xen/xen/include/public/domctl.h" 2
# 1 "/var/xen-dev/xen/xen/include/public/grant_table.h" 1
# 114 "/var/xen-dev/xen/xen/include/public/grant_table.h"
typedef uint32_t grant_ref_t;
# 131 "/var/xen-dev/xen/xen/include/public/grant_table.h"
struct grant_entry {

    uint16_t flags;

    domid_t domid;






    uint32_t frame;
};
typedef struct grant_entry grant_entry_t;
# 321 "/var/xen-dev/xen/xen/include/public/grant_table.h"
typedef uint32_t grant_handle_t;
# 340 "/var/xen-dev/xen/xen/include/public/grant_table.h"
struct gnttab_map_grant_ref {

    uint64_t host_addr;
    uint32_t flags;
    grant_ref_t ref;
    domid_t dom;

    int16_t status;
    grant_handle_t handle;
    uint64_t dev_bus_addr;
};
typedef struct gnttab_map_grant_ref gnttab_map_grant_ref_t;
typedef gnttab_map_grant_ref_t * __guest_handle_gnttab_map_grant_ref_t; typedef const gnttab_map_grant_ref_t * __guest_handle_const_gnttab_map_grant_ref_t;
# 365 "/var/xen-dev/xen/xen/include/public/grant_table.h"
struct gnttab_unmap_grant_ref {

    uint64_t host_addr;
    uint64_t dev_bus_addr;
    grant_handle_t handle;

    int16_t status;
};
typedef struct gnttab_unmap_grant_ref gnttab_unmap_grant_ref_t;
typedef gnttab_unmap_grant_ref_t * __guest_handle_gnttab_unmap_grant_ref_t; typedef const gnttab_unmap_grant_ref_t * __guest_handle_const_gnttab_unmap_grant_ref_t;
# 385 "/var/xen-dev/xen/xen/include/public/grant_table.h"
struct gnttab_setup_table {

    domid_t dom;
    uint32_t nr_frames;

    int16_t status;

    __guest_handle_ulong frame_list;



};
typedef struct gnttab_setup_table gnttab_setup_table_t;
typedef gnttab_setup_table_t * __guest_handle_gnttab_setup_table_t; typedef const gnttab_setup_table_t * __guest_handle_const_gnttab_setup_table_t;





struct gnttab_dump_table {

    domid_t dom;

    int16_t status;
};
typedef struct gnttab_dump_table gnttab_dump_table_t;
typedef gnttab_dump_table_t * __guest_handle_gnttab_dump_table_t; typedef const gnttab_dump_table_t * __guest_handle_const_gnttab_dump_table_t;
# 422 "/var/xen-dev/xen/xen/include/public/grant_table.h"
struct gnttab_transfer {

    xen_pfn_t mfn;
    domid_t domid;
    grant_ref_t ref;

    int16_t status;
};
typedef struct gnttab_transfer gnttab_transfer_t;
typedef gnttab_transfer_t * __guest_handle_gnttab_transfer_t; typedef const gnttab_transfer_t * __guest_handle_const_gnttab_transfer_t;
# 457 "/var/xen-dev/xen/xen/include/public/grant_table.h"
struct gnttab_copy {

    struct gnttab_copy_ptr {
        union {
            grant_ref_t ref;
            xen_pfn_t gmfn;
        } u;
        domid_t domid;
        uint16_t offset;
    } source, dest;
    uint16_t len;
    uint16_t flags;

    int16_t status;
};
typedef struct gnttab_copy gnttab_copy_t;
typedef gnttab_copy_t * __guest_handle_gnttab_copy_t; typedef const gnttab_copy_t * __guest_handle_const_gnttab_copy_t;
# 482 "/var/xen-dev/xen/xen/include/public/grant_table.h"
struct gnttab_query_size {

    domid_t dom;

    uint32_t nr_frames;
    uint32_t max_nr_frames;
    int16_t status;
};
typedef struct gnttab_query_size gnttab_query_size_t;
typedef gnttab_query_size_t * __guest_handle_gnttab_query_size_t; typedef const gnttab_query_size_t * __guest_handle_const_gnttab_query_size_t;
# 504 "/var/xen-dev/xen/xen/include/public/grant_table.h"
struct gnttab_unmap_and_replace {

    uint64_t host_addr;
    uint64_t new_addr;
    grant_handle_t handle;

    int16_t status;
};
typedef struct gnttab_unmap_and_replace gnttab_unmap_and_replace_t;
typedef gnttab_unmap_and_replace_t * __guest_handle_gnttab_unmap_and_replace_t; typedef const gnttab_unmap_and_replace_t * __guest_handle_const_gnttab_unmap_and_replace_t;
# 38 "/var/xen-dev/xen/xen/include/public/domctl.h" 2
# 1 "/var/xen-dev/xen/xen/include/public/hvm/save.h" 1
# 49 "/var/xen-dev/xen/xen/include/public/hvm/save.h"
struct hvm_save_descriptor {
    uint16_t typecode;
    uint16_t instance;
    uint32_t length;
};
# 102 "/var/xen-dev/xen/xen/include/public/hvm/save.h"
struct hvm_save_end {};
struct __HVM_SAVE_TYPE_END { struct hvm_save_end t; char c[0]; char cpt[1];};


# 1 "/var/xen-dev/xen/xen/include/public/hvm/../arch-x86/hvm/save.h" 1
# 36 "/var/xen-dev/xen/xen/include/public/hvm/../arch-x86/hvm/save.h"
struct hvm_save_header {
    uint32_t magic;
    uint32_t version;
    uint64_t changeset;
    uint32_t cpuid;
    uint32_t gtsc_khz;
};

struct __HVM_SAVE_TYPE_HEADER { struct hvm_save_header t; char c[1]; char cpt[1];};
# 55 "/var/xen-dev/xen/xen/include/public/hvm/../arch-x86/hvm/save.h"
struct hvm_hw_cpu {
    uint8_t fpu_regs[512];

    uint64_t rax;
    uint64_t rbx;
    uint64_t rcx;
    uint64_t rdx;
    uint64_t rbp;
    uint64_t rsi;
    uint64_t rdi;
    uint64_t rsp;
    uint64_t r8;
    uint64_t r9;
    uint64_t r10;
    uint64_t r11;
    uint64_t r12;
    uint64_t r13;
    uint64_t r14;
    uint64_t r15;

    uint64_t rip;
    uint64_t rflags;

    uint64_t cr0;
    uint64_t cr2;
    uint64_t cr3;
    uint64_t cr4;

    uint64_t dr0;
    uint64_t dr1;
    uint64_t dr2;
    uint64_t dr3;
    uint64_t dr6;
    uint64_t dr7;

    uint32_t cs_sel;
    uint32_t ds_sel;
    uint32_t es_sel;
    uint32_t fs_sel;
    uint32_t gs_sel;
    uint32_t ss_sel;
    uint32_t tr_sel;
    uint32_t ldtr_sel;

    uint32_t cs_limit;
    uint32_t ds_limit;
    uint32_t es_limit;
    uint32_t fs_limit;
    uint32_t gs_limit;
    uint32_t ss_limit;
    uint32_t tr_limit;
    uint32_t ldtr_limit;
    uint32_t idtr_limit;
    uint32_t gdtr_limit;

    uint64_t cs_base;
    uint64_t ds_base;
    uint64_t es_base;
    uint64_t fs_base;
    uint64_t gs_base;
    uint64_t ss_base;
    uint64_t tr_base;
    uint64_t ldtr_base;
    uint64_t idtr_base;
    uint64_t gdtr_base;

    uint32_t cs_arbytes;
    uint32_t ds_arbytes;
    uint32_t es_arbytes;
    uint32_t fs_arbytes;
    uint32_t gs_arbytes;
    uint32_t ss_arbytes;
    uint32_t tr_arbytes;
    uint32_t ldtr_arbytes;

    uint64_t sysenter_cs;
    uint64_t sysenter_esp;
    uint64_t sysenter_eip;


    uint64_t shadow_gs;


    uint64_t msr_flags;
    uint64_t msr_lstar;
    uint64_t msr_star;
    uint64_t msr_cstar;
    uint64_t msr_syscall_mask;
    uint64_t msr_efer;
    uint64_t msr_tsc_aux;


    uint64_t tsc;


    union {
        uint32_t pending_event;
        struct {
            uint8_t pending_vector:8;
            uint8_t pending_type:3;
            uint8_t pending_error_valid:1;
            uint32_t pending_reserved:19;
            uint8_t pending_valid:1;
        };
    };

    uint32_t error_code;



    uint32_t flags;
    uint32_t pad0;
};

struct hvm_hw_cpu_compat {
    uint8_t fpu_regs[512];

    uint64_t rax;
    uint64_t rbx;
    uint64_t rcx;
    uint64_t rdx;
    uint64_t rbp;
    uint64_t rsi;
    uint64_t rdi;
    uint64_t rsp;
    uint64_t r8;
    uint64_t r9;
    uint64_t r10;
    uint64_t r11;
    uint64_t r12;
    uint64_t r13;
    uint64_t r14;
    uint64_t r15;

    uint64_t rip;
    uint64_t rflags;

    uint64_t cr0;
    uint64_t cr2;
    uint64_t cr3;
    uint64_t cr4;

    uint64_t dr0;
    uint64_t dr1;
    uint64_t dr2;
    uint64_t dr3;
    uint64_t dr6;
    uint64_t dr7;

    uint32_t cs_sel;
    uint32_t ds_sel;
    uint32_t es_sel;
    uint32_t fs_sel;
    uint32_t gs_sel;
    uint32_t ss_sel;
    uint32_t tr_sel;
    uint32_t ldtr_sel;

    uint32_t cs_limit;
    uint32_t ds_limit;
    uint32_t es_limit;
    uint32_t fs_limit;
    uint32_t gs_limit;
    uint32_t ss_limit;
    uint32_t tr_limit;
    uint32_t ldtr_limit;
    uint32_t idtr_limit;
    uint32_t gdtr_limit;

    uint64_t cs_base;
    uint64_t ds_base;
    uint64_t es_base;
    uint64_t fs_base;
    uint64_t gs_base;
    uint64_t ss_base;
    uint64_t tr_base;
    uint64_t ldtr_base;
    uint64_t idtr_base;
    uint64_t gdtr_base;

    uint32_t cs_arbytes;
    uint32_t ds_arbytes;
    uint32_t es_arbytes;
    uint32_t fs_arbytes;
    uint32_t gs_arbytes;
    uint32_t ss_arbytes;
    uint32_t tr_arbytes;
    uint32_t ldtr_arbytes;

    uint64_t sysenter_cs;
    uint64_t sysenter_esp;
    uint64_t sysenter_eip;


    uint64_t shadow_gs;


    uint64_t msr_flags;
    uint64_t msr_lstar;
    uint64_t msr_star;
    uint64_t msr_cstar;
    uint64_t msr_syscall_mask;
    uint64_t msr_efer;



    uint64_t tsc;


    union {
        uint32_t pending_event;
        struct {
            uint8_t pending_vector:8;
            uint8_t pending_type:3;
            uint8_t pending_error_valid:1;
            uint32_t pending_reserved:19;
            uint8_t pending_valid:1;
        };
    };

    uint32_t error_code;
};

static __inline__ int _hvm_hw_fix_cpu(void *h, uint32_t size) {

    union hvm_hw_cpu_union {
        struct hvm_hw_cpu nat;
        struct hvm_hw_cpu_compat cmp;
    } *ucpu = (union hvm_hw_cpu_union *)h;

    if ( size == sizeof(struct hvm_hw_cpu_compat) )
    {




        ucpu->nat.error_code = ucpu->cmp.error_code;
        ucpu->nat.pending_event = ucpu->cmp.pending_event;
        ucpu->nat.tsc = ucpu->cmp.tsc;
        ucpu->nat.msr_tsc_aux = 0;
    }

    ucpu->nat.flags = (1U<<0);

    return 0;
}

struct __HVM_SAVE_TYPE_CPU { struct hvm_hw_cpu t; char c[2]; char cpt[2];}
                                                                       ;





struct hvm_hw_vpic {

    uint8_t irr;
    uint8_t imr;
    uint8_t isr;


    uint8_t irq_base;







    uint8_t init_state:4;


    uint8_t priority_add:4;


    uint8_t readsel_isr:1;


    uint8_t poll:1;


    uint8_t auto_eoi:1;


    uint8_t rotate_on_auto_eoi:1;


    uint8_t special_fully_nested_mode:1;


    uint8_t special_mask_mode:1;


    uint8_t is_master:1;


    uint8_t elcr;


    uint8_t int_output;
};

struct __HVM_SAVE_TYPE_PIC { struct hvm_hw_vpic t; char c[3]; char cpt[1];};






union vioapic_redir_entry
{
    uint64_t bits;
    struct {
        uint8_t vector;
        uint8_t delivery_mode:3;
        uint8_t dest_mode:1;
        uint8_t delivery_status:1;
        uint8_t polarity:1;
        uint8_t remote_irr:1;
        uint8_t trig_mode:1;
        uint8_t mask:1;
        uint8_t reserve:7;
        uint8_t reserved[4];
        uint8_t dest_id;
    } fields;
};
# 392 "/var/xen-dev/xen/xen/include/public/hvm/../arch-x86/hvm/save.h"
struct hvm_hw_vioapic { uint64_t base_address; uint32_t ioregsel; uint32_t id; union vioapic_redir_entry redirtbl[48]; };







struct __HVM_SAVE_TYPE_IOAPIC { struct hvm_hw_vioapic t; char c[4]; char cpt[1];};






struct hvm_hw_lapic {
    uint64_t apic_base_msr;
    uint32_t disabled;
    uint32_t timer_divisor;
    uint64_t tdt_msr;
};

struct __HVM_SAVE_TYPE_LAPIC { struct hvm_hw_lapic t; char c[5]; char cpt[1];};

struct hvm_hw_lapic_regs {
    uint8_t data[1024];
};

struct __HVM_SAVE_TYPE_LAPIC_REGS { struct hvm_hw_lapic_regs t; char c[6]; char cpt[1];};






struct hvm_hw_pci_irqs {




    union {
        unsigned long i[16 / sizeof (unsigned long)];
        uint64_t pad[2];
    };
};

struct __HVM_SAVE_TYPE_PCI_IRQ { struct hvm_hw_pci_irqs t; char c[7]; char cpt[1];};

struct hvm_hw_isa_irqs {




    union {
        unsigned long i[1];
        uint64_t pad[1];
    };
};

struct __HVM_SAVE_TYPE_ISA_IRQ { struct hvm_hw_isa_irqs t; char c[8]; char cpt[1];};

struct hvm_hw_pci_link {






    uint8_t route[4];
    uint8_t pad0[4];
};

struct __HVM_SAVE_TYPE_PCI_LINK { struct hvm_hw_pci_link t; char c[9]; char cpt[1];};





struct hvm_hw_pit {
    struct hvm_hw_pit_channel {
        uint32_t count;
        uint16_t latched_count;
        uint8_t count_latched;
        uint8_t status_latched;
        uint8_t status;
        uint8_t read_state;
        uint8_t write_state;
        uint8_t write_latch;
        uint8_t rw_mode;
        uint8_t mode;
        uint8_t bcd;
        uint8_t gate;
    } channels[3];
    uint32_t speaker_data_on;
    uint32_t pad0;
};

struct __HVM_SAVE_TYPE_PIT { struct hvm_hw_pit t; char c[10]; char cpt[1];};







struct hvm_hw_rtc {

    uint8_t cmos_data[14];

    uint8_t cmos_index;
    uint8_t pad0;
};

struct __HVM_SAVE_TYPE_RTC { struct hvm_hw_rtc t; char c[11]; char cpt[1];};







struct hvm_hw_hpet {

    uint64_t capability;
    uint64_t res0;
    uint64_t config;
    uint64_t res1;
    uint64_t isr;
    uint64_t res2[25];
    uint64_t mc64;
    uint64_t res3;
    struct {
        uint64_t config;
        uint64_t cmp;
        uint64_t fsb;
        uint64_t res4;
    } timers[3];
    uint64_t res5[4*(24-3)];


    uint64_t period[3];
};

struct __HVM_SAVE_TYPE_HPET { struct hvm_hw_hpet t; char c[12]; char cpt[1];};






struct hvm_hw_pmtimer {
    uint32_t tmr_val;
    uint16_t pm1a_sts;
    uint16_t pm1a_en;
};

struct __HVM_SAVE_TYPE_PMTIMER { struct hvm_hw_pmtimer t; char c[13]; char cpt[1];};





struct hvm_hw_mtrr {


    uint64_t msr_pat_cr;

    uint64_t msr_mtrr_var[8*2];
    uint64_t msr_mtrr_fixed[11];
    uint64_t msr_mtrr_cap;
    uint64_t msr_mtrr_def_type;
};

struct __HVM_SAVE_TYPE_MTRR { struct hvm_hw_mtrr t; char c[14]; char cpt[1];};





struct hvm_hw_cpu_xsave {
    uint64_t xfeature_mask;
    uint64_t xcr0;
    uint64_t xcr0_accum;
    struct {
        struct { char x[512]; } fpu_sse;

        struct hvm_hw_cpu_xsave_hdr {
            uint64_t xstate_bv;
            uint64_t xcomp_bv;
            uint64_t reserved[6];
        } xsave_hdr;
    } save_area;
};







struct hvm_viridian_domain_context {
    uint64_t hypercall_gpa;
    uint64_t guest_os_id;
    uint64_t time_ref_count;
    uint64_t reference_tsc;
};

struct __HVM_SAVE_TYPE_VIRIDIAN_DOMAIN { struct hvm_viridian_domain_context t; char c[15]; char cpt[1];};

struct hvm_viridian_vcpu_context {
    uint64_t vp_assist_msr;
    uint8_t apic_assist_pending;
    uint8_t _pad[7];
    uint64_t simp_msr;
    uint64_t sint_msr[16];
    uint64_t stimer_config_msr[4];
    uint64_t stimer_count_msr[4];
};

struct __HVM_SAVE_TYPE_VIRIDIAN_VCPU { struct hvm_viridian_vcpu_context t; char c[17]; char cpt[1];};

struct hvm_vmce_vcpu {
    uint64_t caps;
    uint64_t mci_ctl2_bank0;
    uint64_t mci_ctl2_bank1;
    uint64_t mcg_ext_ctl;
};

struct __HVM_SAVE_TYPE_VMCE_VCPU { struct hvm_vmce_vcpu t; char c[18]; char cpt[1];};

struct hvm_tsc_adjust {
    uint64_t tsc_adjust;
};

struct __HVM_SAVE_TYPE_TSC_ADJUST { struct hvm_tsc_adjust t; char c[19]; char cpt[1];};


struct hvm_msr {
    uint32_t count;
    struct hvm_one_msr {
        uint32_t index;
        uint32_t _rsvd;
        uint64_t val;
    } msr[];
};
# 107 "/var/xen-dev/xen/xen/include/public/hvm/save.h" 2
# 39 "/var/xen-dev/xen/xen/include/public/domctl.h" 2
# 1 "/var/xen-dev/xen/xen/include/public/memory.h" 1
# 31 "/var/xen-dev/xen/xen/include/public/memory.h"
# 1 "/var/xen-dev/xen/xen/include/public/physdev.h" 1
# 40 "/var/xen-dev/xen/xen/include/public/physdev.h"
struct physdev_eoi {

    uint32_t irq;
};
typedef struct physdev_eoi physdev_eoi_t;
typedef physdev_eoi_t * __guest_handle_physdev_eoi_t; typedef const physdev_eoi_t * __guest_handle_const_physdev_eoi_t;
# 63 "/var/xen-dev/xen/xen/include/public/physdev.h"
struct physdev_pirq_eoi_gmfn {

    xen_pfn_t gmfn;
};
typedef struct physdev_pirq_eoi_gmfn physdev_pirq_eoi_gmfn_t;
typedef physdev_pirq_eoi_gmfn_t * __guest_handle_physdev_pirq_eoi_gmfn_t; typedef const physdev_pirq_eoi_gmfn_t * __guest_handle_const_physdev_pirq_eoi_gmfn_t;






struct physdev_irq_status_query {

    uint32_t irq;

    uint32_t flags;
};
typedef struct physdev_irq_status_query physdev_irq_status_query_t;
typedef physdev_irq_status_query_t * __guest_handle_physdev_irq_status_query_t; typedef const physdev_irq_status_query_t * __guest_handle_const_physdev_irq_status_query_t;
# 97 "/var/xen-dev/xen/xen/include/public/physdev.h"
struct physdev_set_iopl {

    uint32_t iopl;
};
typedef struct physdev_set_iopl physdev_set_iopl_t;
typedef physdev_set_iopl_t * __guest_handle_physdev_set_iopl_t; typedef const physdev_set_iopl_t * __guest_handle_const_physdev_set_iopl_t;






struct physdev_set_iobitmap {




    uint8_t *bitmap;

    uint32_t nr_ports;
};
typedef struct physdev_set_iobitmap physdev_set_iobitmap_t;
typedef physdev_set_iobitmap_t * __guest_handle_physdev_set_iobitmap_t; typedef const physdev_set_iobitmap_t * __guest_handle_const_physdev_set_iobitmap_t;







struct physdev_apic {

    unsigned long apic_physbase;
    uint32_t reg;

    uint32_t value;
};
typedef struct physdev_apic physdev_apic_t;
typedef physdev_apic_t * __guest_handle_physdev_apic_t; typedef const physdev_apic_t * __guest_handle_const_physdev_apic_t;







struct physdev_irq {

    uint32_t irq;

    uint32_t vector;
};
typedef struct physdev_irq physdev_irq_t;
typedef physdev_irq_t * __guest_handle_physdev_irq_t; typedef const physdev_irq_t * __guest_handle_const_physdev_irq_t;
# 159 "/var/xen-dev/xen/xen/include/public/physdev.h"
struct physdev_map_pirq {
    domid_t domid;

    int type;

    int index;

    int pirq;

    int bus;

    int devfn;

    int entry_nr;

    uint64_t table_base;
};
typedef struct physdev_map_pirq physdev_map_pirq_t;
typedef physdev_map_pirq_t * __guest_handle_physdev_map_pirq_t; typedef const physdev_map_pirq_t * __guest_handle_const_physdev_map_pirq_t;


struct physdev_unmap_pirq {
    domid_t domid;

    int pirq;
};

typedef struct physdev_unmap_pirq physdev_unmap_pirq_t;
typedef physdev_unmap_pirq_t * __guest_handle_physdev_unmap_pirq_t; typedef const physdev_unmap_pirq_t * __guest_handle_const_physdev_unmap_pirq_t;



struct physdev_manage_pci {

    uint8_t bus;
    uint8_t devfn;
};

typedef struct physdev_manage_pci physdev_manage_pci_t;
typedef physdev_manage_pci_t * __guest_handle_physdev_manage_pci_t; typedef const physdev_manage_pci_t * __guest_handle_const_physdev_manage_pci_t;


struct physdev_restore_msi {

    uint8_t bus;
    uint8_t devfn;
};
typedef struct physdev_restore_msi physdev_restore_msi_t;
typedef physdev_restore_msi_t * __guest_handle_physdev_restore_msi_t; typedef const physdev_restore_msi_t * __guest_handle_const_physdev_restore_msi_t;


struct physdev_manage_pci_ext {

    uint8_t bus;
    uint8_t devfn;
    unsigned is_extfn;
    unsigned is_virtfn;
    struct {
        uint8_t bus;
        uint8_t devfn;
    } physfn;
};

typedef struct physdev_manage_pci_ext physdev_manage_pci_ext_t;
typedef physdev_manage_pci_ext_t * __guest_handle_physdev_manage_pci_ext_t; typedef const physdev_manage_pci_ext_t * __guest_handle_const_physdev_manage_pci_ext_t;





struct physdev_op {
    uint32_t cmd;
    union {
        struct physdev_irq_status_query irq_status_query;
        struct physdev_set_iopl set_iopl;
        struct physdev_set_iobitmap set_iobitmap;
        struct physdev_apic apic_op;
        struct physdev_irq irq_op;
    } u;
};
typedef struct physdev_op physdev_op_t;
typedef physdev_op_t * __guest_handle_physdev_op_t; typedef const physdev_op_t * __guest_handle_const_physdev_op_t;


struct physdev_setup_gsi {
    int gsi;

    uint8_t triggering;

    uint8_t polarity;

};

typedef struct physdev_setup_gsi physdev_setup_gsi_t;
typedef physdev_setup_gsi_t * __guest_handle_physdev_setup_gsi_t; typedef const physdev_setup_gsi_t * __guest_handle_const_physdev_setup_gsi_t;






struct physdev_get_free_pirq {

    int type;

    uint32_t pirq;
};

typedef struct physdev_get_free_pirq physdev_get_free_pirq_t;
typedef physdev_get_free_pirq_t * __guest_handle_physdev_get_free_pirq_t; typedef const physdev_get_free_pirq_t * __guest_handle_const_physdev_get_free_pirq_t;




struct physdev_pci_mmcfg_reserved {
    uint64_t address;
    uint16_t segment;
    uint8_t start_bus;
    uint8_t end_bus;
    uint32_t flags;
};
typedef struct physdev_pci_mmcfg_reserved physdev_pci_mmcfg_reserved_t;
typedef physdev_pci_mmcfg_reserved_t * __guest_handle_physdev_pci_mmcfg_reserved_t; typedef const physdev_pci_mmcfg_reserved_t * __guest_handle_const_physdev_pci_mmcfg_reserved_t;






struct physdev_pci_device_add {

    uint16_t seg;
    uint8_t bus;
    uint8_t devfn;
    uint32_t flags;
    struct {
        uint8_t bus;
        uint8_t devfn;
    } physfn;





    uint32_t optarr[];
};
typedef struct physdev_pci_device_add physdev_pci_device_add_t;
typedef physdev_pci_device_add_t * __guest_handle_physdev_pci_device_add_t; typedef const physdev_pci_device_add_t * __guest_handle_const_physdev_pci_device_add_t;
# 316 "/var/xen-dev/xen/xen/include/public/physdev.h"
struct physdev_pci_device {

    uint16_t seg;
    uint8_t bus;
    uint8_t devfn;
};
typedef struct physdev_pci_device physdev_pci_device_t;
typedef physdev_pci_device_t * __guest_handle_physdev_pci_device_t; typedef const physdev_pci_device_t * __guest_handle_const_physdev_pci_device_t;
# 332 "/var/xen-dev/xen/xen/include/public/physdev.h"
struct physdev_dbgp_op {

    uint8_t op;
    uint8_t bus;
    union {
        struct physdev_pci_device pci;
    } u;
};
typedef struct physdev_dbgp_op physdev_dbgp_op_t;
typedef physdev_dbgp_op_t * __guest_handle_physdev_dbgp_op_t; typedef const physdev_dbgp_op_t * __guest_handle_const_physdev_dbgp_op_t;
# 32 "/var/xen-dev/xen/xen/include/public/memory.h" 2
# 63 "/var/xen-dev/xen/xen/include/public/memory.h"
struct xen_memory_reservation {
# 77 "/var/xen-dev/xen/xen/include/public/memory.h"
    __guest_handle_xen_pfn_t extent_start;


    xen_ulong_t nr_extents;
    unsigned int extent_order;





    unsigned int address_bits;






    domid_t domid;
};
typedef struct xen_memory_reservation xen_memory_reservation_t;
typedef xen_memory_reservation_t * __guest_handle_xen_memory_reservation_t; typedef const xen_memory_reservation_t * __guest_handle_const_xen_memory_reservation_t;
# 109 "/var/xen-dev/xen/xen/include/public/memory.h"
struct xen_memory_exchange {




    struct xen_memory_reservation in;
# 126 "/var/xen-dev/xen/xen/include/public/memory.h"
    struct xen_memory_reservation out;
# 139 "/var/xen-dev/xen/xen/include/public/memory.h"
    xen_ulong_t nr_exchanged;
};
typedef struct xen_memory_exchange xen_memory_exchange_t;
typedef xen_memory_exchange_t * __guest_handle_xen_memory_exchange_t; typedef const xen_memory_exchange_t * __guest_handle_const_xen_memory_exchange_t;
# 171 "/var/xen-dev/xen/xen/include/public/memory.h"
struct xen_machphys_mfn_list {




    unsigned int max_extents;






    __guest_handle_xen_pfn_t extent_start;





    unsigned int nr_extents;
};
typedef struct xen_machphys_mfn_list xen_machphys_mfn_list_t;
typedef xen_machphys_mfn_list_t * __guest_handle_xen_machphys_mfn_list_t; typedef const xen_machphys_mfn_list_t * __guest_handle_const_xen_machphys_mfn_list_t;
# 210 "/var/xen-dev/xen/xen/include/public/memory.h"
struct xen_machphys_mapping {
    xen_ulong_t v_start, v_end;
    xen_ulong_t max_mfn;
};
typedef struct xen_machphys_mapping xen_machphys_mapping_t;
typedef xen_machphys_mapping_t * __guest_handle_xen_machphys_mapping_t; typedef const xen_machphys_mapping_t * __guest_handle_const_xen_machphys_mapping_t;
# 238 "/var/xen-dev/xen/xen/include/public/memory.h"
struct xen_add_to_physmap {

    domid_t domid;


    uint16_t size;

    unsigned int space;




    xen_ulong_t idx;


    xen_pfn_t gpfn;
};
typedef struct xen_add_to_physmap xen_add_to_physmap_t;
typedef xen_add_to_physmap_t * __guest_handle_xen_add_to_physmap_t; typedef const xen_add_to_physmap_t * __guest_handle_const_xen_add_to_physmap_t;



struct xen_add_to_physmap_batch {


    domid_t domid;
    uint16_t space;


    uint16_t size;


    domid_t foreign_domid;
# 279 "/var/xen-dev/xen/xen/include/public/memory.h"
    __guest_handle_xen_ulong_t idxs;


    __guest_handle_xen_pfn_t gpfns;




    __guest_handle_int errs;
};
typedef struct xen_add_to_physmap_batch xen_add_to_physmap_batch_t;
typedef xen_add_to_physmap_batch_t * __guest_handle_xen_add_to_physmap_batch_t; typedef const xen_add_to_physmap_batch_t * __guest_handle_const_xen_add_to_physmap_batch_t;




typedef struct xen_add_to_physmap_batch xen_add_to_physmap_range_t;
typedef xen_add_to_physmap_range_t * __guest_handle_xen_add_to_physmap_range_t; typedef const xen_add_to_physmap_range_t * __guest_handle_const_xen_add_to_physmap_range_t;
# 305 "/var/xen-dev/xen/xen/include/public/memory.h"
struct xen_remove_from_physmap {

    domid_t domid;


    xen_pfn_t gpfn;
};
typedef struct xen_remove_from_physmap xen_remove_from_physmap_t;
typedef xen_remove_from_physmap_t * __guest_handle_xen_remove_from_physmap_t; typedef const xen_remove_from_physmap_t * __guest_handle_const_xen_remove_from_physmap_t;
# 324 "/var/xen-dev/xen/xen/include/public/memory.h"
struct xen_memory_map {





    unsigned int nr_entries;





    __guest_handle_void buffer;
};
typedef struct xen_memory_map xen_memory_map_t;
typedef xen_memory_map_t * __guest_handle_xen_memory_map_t; typedef const xen_memory_map_t * __guest_handle_const_xen_memory_map_t;
# 356 "/var/xen-dev/xen/xen/include/public/memory.h"
struct xen_foreign_memory_map {
    domid_t domid;
    struct xen_memory_map map;
};
typedef struct xen_foreign_memory_map xen_foreign_memory_map_t;
typedef xen_foreign_memory_map_t * __guest_handle_xen_foreign_memory_map_t; typedef const xen_foreign_memory_map_t * __guest_handle_const_xen_foreign_memory_map_t;



struct xen_pod_target {

    uint64_t target_pages;

    uint64_t tot_pages;
    uint64_t pod_cache_pages;
    uint64_t pod_entries;

    domid_t domid;
};
typedef struct xen_pod_target xen_pod_target_t;
# 670 "/var/xen-dev/xen/xen/include/public/memory.h"
struct xen_vmemrange {
    uint64_t start, end;
    unsigned int flags;
    unsigned int nid;
};
typedef struct xen_vmemrange xen_vmemrange_t;
typedef xen_vmemrange_t * __guest_handle_xen_vmemrange_t; typedef const xen_vmemrange_t * __guest_handle_const_xen_vmemrange_t;
# 687 "/var/xen-dev/xen/xen/include/public/memory.h"
struct xen_vnuma_topology_info {

    domid_t domid;
    uint16_t pad;

    unsigned int nr_vnodes;
    unsigned int nr_vcpus;
    unsigned int nr_vmemranges;

    union {
        __guest_handle_uint h;
        uint64_t pad;
    } vdistance;
    union {
        __guest_handle_uint h;
        uint64_t pad;
    } vcpu_to_vnode;
    union {
        __guest_handle_xen_vmemrange_t h;
        uint64_t pad;
    } vmemrange;
};
typedef struct xen_vnuma_topology_info xen_vnuma_topology_info_t;
typedef xen_vnuma_topology_info_t * __guest_handle_xen_vnuma_topology_info_t; typedef const xen_vnuma_topology_info_t * __guest_handle_const_xen_vnuma_topology_info_t;
# 40 "/var/xen-dev/xen/xen/include/public/domctl.h" 2
# 48 "/var/xen-dev/xen/xen/include/public/domctl.h"
struct xen_domctl_createdomain {

    uint32_t ssidref;
    xen_domain_handle_t handle;
# 74 "/var/xen-dev/xen/xen/include/public/domctl.h"
    uint32_t flags;







    uint32_t iommu_opts;







    uint32_t max_vcpus;
    uint32_t max_evtchn_port;
    int32_t max_grant_frames;
    int32_t max_maptrack_frames;

    struct xen_arch_domainconfig arch;
};


struct xen_domctl_getdomaininfo {

    domid_t domain;
# 132 "/var/xen-dev/xen/xen/include/public/domctl.h"
    uint32_t flags;
    uint64_aligned_t tot_pages;
    uint64_aligned_t max_pages;
    uint64_aligned_t outstanding_pages;
    uint64_aligned_t shr_pages;
    uint64_aligned_t paged_pages;
    uint64_aligned_t shared_info_frame;
    uint64_aligned_t cpu_time;
    uint32_t nr_online_vcpus;

    uint32_t max_vcpu_id;
    uint32_t ssidref;
    xen_domain_handle_t handle;
    uint32_t cpupool;
    struct xen_arch_domainconfig arch_config;
};
typedef struct xen_domctl_getdomaininfo xen_domctl_getdomaininfo_t;
typedef xen_domctl_getdomaininfo_t * __guest_handle_xen_domctl_getdomaininfo_t; typedef const xen_domctl_getdomaininfo_t * __guest_handle_const_xen_domctl_getdomaininfo_t;
# 172 "/var/xen-dev/xen/xen/include/public/domctl.h"
struct xen_domctl_getpageframeinfo3 {

    uint64_aligned_t num;

    XEN_GUEST_HANDLE_64(xen_pfn_t) array;
};
# 240 "/var/xen-dev/xen/xen/include/public/domctl.h"
struct xen_domctl_shadow_op_stats {
    uint32_t fault_count;
    uint32_t dirty_count;
};

struct xen_domctl_shadow_op {

    uint32_t op;



    uint32_t mode;


    uint32_t mb;


    XEN_GUEST_HANDLE_64(uint8) dirty_bitmap;
    uint64_aligned_t pages;
    struct xen_domctl_shadow_op_stats stats;
};



struct xen_domctl_max_mem {

    uint64_aligned_t max_memkb;
};




struct xen_domctl_vcpucontext {
    uint32_t vcpu;
    XEN_GUEST_HANDLE_64(vcpu_guest_context_t) ctxt;
};



struct xen_domctl_getvcpuinfo {

    uint32_t vcpu;

    uint8_t online;
    uint8_t blocked;
    uint8_t running;
    uint64_aligned_t cpu_time;
    uint32_t cpu;
};





struct xen_domctl_nodeaffinity {
    struct xenctl_bitmap nodemap;
};





struct xen_domctl_vcpuaffinity {

    uint32_t vcpu;
# 314 "/var/xen-dev/xen/xen/include/public/domctl.h"
    uint32_t flags;
# 331 "/var/xen-dev/xen/xen/include/public/domctl.h"
    struct xenctl_bitmap cpumap_hard;
    struct xenctl_bitmap cpumap_soft;
};
# 344 "/var/xen-dev/xen/xen/include/public/domctl.h"
struct xen_domctl_max_vcpus {
    uint32_t max;
};
# 358 "/var/xen-dev/xen/xen/include/public/domctl.h"
struct xen_domctl_sched_credit {
    uint16_t weight;
    uint16_t cap;
};

struct xen_domctl_sched_credit2 {
    uint16_t weight;
    uint16_t cap;
};

struct xen_domctl_sched_rtds {
    uint32_t period;
    uint32_t budget;



    uint32_t flags;
};

typedef struct xen_domctl_schedparam_vcpu {
    union {
        struct xen_domctl_sched_credit credit;
        struct xen_domctl_sched_credit2 credit2;
        struct xen_domctl_sched_rtds rtds;
    } u;
    uint32_t vcpuid;
} xen_domctl_schedparam_vcpu_t;
typedef xen_domctl_schedparam_vcpu_t * __guest_handle_xen_domctl_schedparam_vcpu_t; typedef const xen_domctl_schedparam_vcpu_t * __guest_handle_const_xen_domctl_schedparam_vcpu_t;
# 403 "/var/xen-dev/xen/xen/include/public/domctl.h"
struct xen_domctl_scheduler_op {
    uint32_t sched_id;
    uint32_t cmd;

    union {
        struct xen_domctl_sched_credit credit;
        struct xen_domctl_sched_credit2 credit2;
        struct xen_domctl_sched_rtds rtds;
        struct {
            XEN_GUEST_HANDLE_64(xen_domctl_schedparam_vcpu_t) vcpus;




            uint32_t nr_vcpus;
            uint32_t padding;
        } v;
    } u;
};



struct xen_domctl_setdomainhandle {
    xen_domain_handle_t handle;
};



struct xen_domctl_setdebugging {
    uint8_t enable;
};



struct xen_domctl_irq_permission {
    uint8_t pirq;
    uint8_t allow_access;
};



struct xen_domctl_iomem_permission {
    uint64_aligned_t first_mfn;
    uint64_aligned_t nr_mfns;
    uint8_t allow_access;
};



struct xen_domctl_ioport_permission {
    uint32_t first_port;
    uint32_t nr_ports;
    uint8_t allow_access;
};



struct xen_domctl_hypercall_init {
    uint64_aligned_t gmfn;
};



struct xen_domctl_settimeoffset {
    int64_aligned_t time_offset_seconds;
};



struct xen_domctl_hvmcontext {
    uint32_t size;
    XEN_GUEST_HANDLE_64(uint8) buffer;


};




struct xen_domctl_address_size {
    uint32_t size;
};
# 493 "/var/xen-dev/xen/xen/include/public/domctl.h"
struct xen_domctl_sendtrigger {
    uint32_t trigger;
    uint32_t vcpu;
};
# 516 "/var/xen-dev/xen/xen/include/public/domctl.h"
struct xen_domctl_assign_device {

    uint32_t dev;
    uint32_t flags;

    union {
        struct {
            uint32_t machine_sbdf;
        } pci;
        struct {
            uint32_t size;
            XEN_GUEST_HANDLE_64(char) path;
        } dt;
    } u;
};



struct xen_domctl_get_device_group {
    uint32_t machine_sbdf;
    uint32_t max_sdevs;
    uint32_t num_sdevs;
    XEN_GUEST_HANDLE_64(uint32) sdev_array;
};




enum pt_irq_type {
    PT_IRQ_TYPE_PCI,
    PT_IRQ_TYPE_ISA,
    PT_IRQ_TYPE_MSI,
    PT_IRQ_TYPE_MSI_TRANSLATE,
    PT_IRQ_TYPE_SPI,
};
struct xen_domctl_bind_pt_irq {
    uint32_t machine_irq;
    uint32_t irq_type;

    union {
        struct {
            uint8_t isa_irq;
        } isa;
        struct {
            uint8_t bus;
            uint8_t device;
            uint8_t intx;
        } pci;
        struct {
            uint8_t gvec;
            uint32_t gflags;







            uint64_aligned_t gtable;
        } msi;
        struct {
            uint16_t spi;
        } spi;
    } u;
};
# 595 "/var/xen-dev/xen/xen/include/public/domctl.h"
struct xen_domctl_memory_mapping {
    uint64_aligned_t first_gfn;
    uint64_aligned_t first_mfn;
    uint64_aligned_t nr_mfns;
    uint32_t add_mapping;
    uint32_t padding;
};




struct xen_domctl_ioport_mapping {
    uint32_t first_gport;
    uint32_t first_mport;
    uint32_t nr_ports;
    uint32_t add_mapping;
};
# 630 "/var/xen-dev/xen/xen/include/public/domctl.h"
struct xen_domctl_ext_vcpucontext {

    uint32_t vcpu;




    uint32_t size;



    uint64_aligned_t syscall32_callback_eip;
    uint64_aligned_t sysenter_callback_eip;
    uint16_t syscall32_callback_cs;
    uint16_t sysenter_callback_cs;
    uint8_t syscall32_disables_events;
    uint8_t sysenter_disables_events;

    union {
        uint64_aligned_t mcg_cap;
        struct hvm_vmce_vcpu vmce;
    };




};





struct xen_domctl_set_target {
    domid_t target;
};
# 674 "/var/xen-dev/xen/xen/include/public/domctl.h"
struct xen_domctl_cpu_policy {
    uint32_t nr_leaves;

    uint32_t nr_msrs;

    XEN_GUEST_HANDLE_64(xen_cpuid_leaf_t) cpuid_policy;
    XEN_GUEST_HANDLE_64(xen_msr_entry_t) msr_policy;





    uint32_t err_leaf, err_subleaf, err_msr;
};
typedef struct xen_domctl_cpu_policy xen_domctl_cpu_policy_t;
typedef xen_domctl_cpu_policy_t * __guest_handle_xen_domctl_cpu_policy_t; typedef const xen_domctl_cpu_policy_t * __guest_handle_const_xen_domctl_cpu_policy_t;
# 709 "/var/xen-dev/xen/xen/include/public/domctl.h"
struct xen_domctl_subscribe {
    uint32_t port;
};




struct xen_domctl_debug_op {
    uint32_t op;
    uint32_t vcpu;
};





struct xen_domctl_hvmcontext_partial {
    uint32_t type;
    uint32_t instance;
    uint64_aligned_t bufsz;
    XEN_GUEST_HANDLE_64(uint8) buffer;
};


struct xen_domctl_disable_migrate {
    uint32_t disable;
};




struct xen_domctl_tsc_info {

    uint32_t tsc_mode;
    uint32_t gtsc_khz;
    uint32_t incarnation;
    uint32_t pad;
    uint64_aligned_t elapsed_nsec;
};


struct xen_domctl_gdbsx_memio {

    uint64_aligned_t pgd3val;
    uint64_aligned_t gva;
    uint64_aligned_t uva;
    uint32_t len;
    uint8_t gwr;

    uint32_t remain;
};



struct xen_domctl_gdbsx_pauseunp_vcpu {
    uint32_t vcpu;
};


struct xen_domctl_gdbsx_domstatus {

    uint8_t paused;
    uint32_t vcpu_id;
    uint32_t vcpu_ev;
};
# 850 "/var/xen-dev/xen/xen/include/public/domctl.h"
struct xen_domctl_vm_event_op {
    uint32_t op;
    uint32_t mode;

    union {
        struct {
            uint32_t port;
        } enable;

        uint32_t version;
    } u;
};
# 870 "/var/xen-dev/xen/xen/include/public/domctl.h"
struct xen_domctl_mem_sharing_op {
    uint8_t op;

    union {
        uint8_t enable;
    } u;
};

struct xen_domctl_audit_p2m {

    uint64_t orphans;
    uint64_t m2p_bad;
    uint64_t p2m_bad;
};

struct xen_domctl_set_virq_handler {
    uint32_t virq;
};




struct xen_domctl_vcpuextstate {

    uint32_t vcpu;







    uint64_aligned_t xfeature_mask;




    uint64_aligned_t size;
    XEN_GUEST_HANDLE_64(uint64) buffer;
};






struct xen_domctl_set_access_required {
    uint8_t access_required;
};

struct xen_domctl_set_broken_page_p2m {
    uint64_aligned_t pfn;
};





struct xen_domctl_cacheflush {

    xen_pfn_t start_pfn, nr_pfns;
};


struct xen_domctl_vcpu_msr {
    uint32_t index;
    uint32_t reserved;
    uint64_aligned_t value;
};
typedef struct xen_domctl_vcpu_msr xen_domctl_vcpu_msr_t;
typedef xen_domctl_vcpu_msr_t * __guest_handle_xen_domctl_vcpu_msr_t; typedef const xen_domctl_vcpu_msr_t * __guest_handle_const_xen_domctl_vcpu_msr_t;
# 959 "/var/xen-dev/xen/xen/include/public/domctl.h"
struct xen_domctl_vcpu_msrs {
    uint32_t vcpu;
    uint32_t msr_count;
    XEN_GUEST_HANDLE_64(xen_domctl_vcpu_msr_t) msrs;
};



struct xen_domctl_vnuma {

    uint32_t nr_vnodes;

    uint32_t nr_vmemranges;




    uint32_t nr_vcpus;
    uint32_t pad;





    XEN_GUEST_HANDLE_64(uint) vdistance;




    XEN_GUEST_HANDLE_64(uint) vcpu_to_vnode;




    XEN_GUEST_HANDLE_64(uint) vnode_to_pnode;




    XEN_GUEST_HANDLE_64(xen_vmemrange_t) vmemrange;
};

struct xen_domctl_psr_cmt_op {



    uint32_t cmd;
    uint32_t data;
};
# 1042 "/var/xen-dev/xen/xen/include/public/domctl.h"
struct xen_domctl_monitor_op {
    uint32_t op;
# 1052 "/var/xen-dev/xen/xen/include/public/domctl.h"
    uint32_t event;




    union {
        struct {

            uint8_t index;

            uint8_t sync;

            uint8_t onchangeonly;

            uint8_t pad1;
            uint32_t pad2;




            uint64_aligned_t bitmask;
        } mov_to_cr;

        struct {
            uint32_t msr;

            uint8_t onchangeonly;
        } mov_to_msr;

        struct {

            uint8_t sync;
            uint8_t allow_userspace;
        } guest_request;

        struct {

            uint8_t sync;
        } debug_exception;
    } u;
};

struct xen_domctl_psr_alloc {
# 1105 "/var/xen-dev/xen/xen/include/public/domctl.h"
    uint32_t cmd;
    uint32_t target;
    uint64_t data;
};


struct xen_domctl_vuart_op {

        uint32_t cmd;

        uint32_t type;


        uint64_aligned_t gfn;


        domid_t console_domid;


        uint8_t pad[2];
        evtchn_port_t evtchn;



};

struct xen_domctl {
    uint32_t cmd;
# 1216 "/var/xen-dev/xen/xen/include/public/domctl.h"
    uint32_t interface_version;
    domid_t domain;
    union {
        struct xen_domctl_createdomain createdomain;
        struct xen_domctl_getdomaininfo getdomaininfo;
        struct xen_domctl_getpageframeinfo3 getpageframeinfo3;
        struct xen_domctl_nodeaffinity nodeaffinity;
        struct xen_domctl_vcpuaffinity vcpuaffinity;
        struct xen_domctl_shadow_op shadow_op;
        struct xen_domctl_max_mem max_mem;
        struct xen_domctl_vcpucontext vcpucontext;
        struct xen_domctl_getvcpuinfo getvcpuinfo;
        struct xen_domctl_max_vcpus max_vcpus;
        struct xen_domctl_scheduler_op scheduler_op;
        struct xen_domctl_setdomainhandle setdomainhandle;
        struct xen_domctl_setdebugging setdebugging;
        struct xen_domctl_irq_permission irq_permission;
        struct xen_domctl_iomem_permission iomem_permission;
        struct xen_domctl_ioport_permission ioport_permission;
        struct xen_domctl_hypercall_init hypercall_init;
        struct xen_domctl_settimeoffset settimeoffset;
        struct xen_domctl_disable_migrate disable_migrate;
        struct xen_domctl_tsc_info tsc_info;
        struct xen_domctl_hvmcontext hvmcontext;
        struct xen_domctl_hvmcontext_partial hvmcontext_partial;
        struct xen_domctl_address_size address_size;
        struct xen_domctl_sendtrigger sendtrigger;
        struct xen_domctl_get_device_group get_device_group;
        struct xen_domctl_assign_device assign_device;
        struct xen_domctl_bind_pt_irq bind_pt_irq;
        struct xen_domctl_memory_mapping memory_mapping;
        struct xen_domctl_ioport_mapping ioport_mapping;
        struct xen_domctl_ext_vcpucontext ext_vcpucontext;
        struct xen_domctl_set_target set_target;
        struct xen_domctl_subscribe subscribe;
        struct xen_domctl_debug_op debug_op;
        struct xen_domctl_vm_event_op vm_event_op;
        struct xen_domctl_mem_sharing_op mem_sharing_op;

        struct xen_domctl_cpu_policy cpu_policy;
        struct xen_domctl_vcpuextstate vcpuextstate;
        struct xen_domctl_vcpu_msrs vcpu_msrs;

        struct xen_domctl_set_access_required access_required;
        struct xen_domctl_audit_p2m audit_p2m;
        struct xen_domctl_set_virq_handler set_virq_handler;
        struct xen_domctl_gdbsx_memio gdbsx_guest_memio;
        struct xen_domctl_set_broken_page_p2m set_broken_page_p2m;
        struct xen_domctl_cacheflush cacheflush;
        struct xen_domctl_gdbsx_pauseunp_vcpu gdbsx_pauseunp_vcpu;
        struct xen_domctl_gdbsx_domstatus gdbsx_domstatus;
        struct xen_domctl_vnuma vnuma;
        struct xen_domctl_psr_cmt_op psr_cmt_op;
        struct xen_domctl_monitor_op monitor_op;
        struct xen_domctl_psr_alloc psr_alloc;
        struct xen_domctl_vuart_op vuart_op;
        uint8_t pad[128];
    } u;
};
typedef struct xen_domctl xen_domctl_t;
typedef xen_domctl_t * __guest_handle_xen_domctl_t; typedef const xen_domctl_t * __guest_handle_const_xen_domctl_t;
# 36 "/var/xen-dev/xen/xen/include/public/sysctl.h" 2
# 44 "/var/xen-dev/xen/xen/include/public/sysctl.h"
struct xen_sysctl_readconsole {

    uint8_t clear;

    uint8_t incremental;
    uint8_t pad0, pad1;




    uint32_t index;

    XEN_GUEST_HANDLE_64(char) buffer;

    uint32_t count;
};



struct xen_sysctl_tbuf_op {







    uint32_t cmd;

    struct xenctl_bitmap cpu_mask;
    uint32_t evt_mask;

    uint64_aligned_t buffer_mfn;
    uint32_t size;
};
# 107 "/var/xen-dev/xen/xen/include/public/sysctl.h"
struct xen_sysctl_physinfo {
    uint32_t threads_per_core;
    uint32_t cores_per_socket;
    uint32_t nr_cpus;
    uint32_t max_cpu_id;
    uint32_t nr_nodes;
    uint32_t max_node_id;
    uint32_t cpu_khz;
    uint32_t capabilities;
    uint64_aligned_t total_pages;
    uint64_aligned_t free_pages;
    uint64_aligned_t scrub_pages;
    uint64_aligned_t outstanding_pages;
    uint64_aligned_t max_mfn;
    uint32_t hw_cap[8];
};





struct xen_sysctl_sched_id {

    uint32_t sched_id;
};






struct xen_sysctl_perfc_desc {
    char name[80];
    uint32_t nr_vals;
};
typedef struct xen_sysctl_perfc_desc xen_sysctl_perfc_desc_t;
typedef xen_sysctl_perfc_desc_t * __guest_handle_xen_sysctl_perfc_desc_t; typedef const xen_sysctl_perfc_desc_t * __guest_handle_const_xen_sysctl_perfc_desc_t;
typedef uint32_t xen_sysctl_perfc_val_t;
typedef xen_sysctl_perfc_val_t * __guest_handle_xen_sysctl_perfc_val_t; typedef const xen_sysctl_perfc_val_t * __guest_handle_const_xen_sysctl_perfc_val_t;

struct xen_sysctl_perfc_op {

    uint32_t cmd;

    uint32_t nr_counters;
    uint32_t nr_vals;

    XEN_GUEST_HANDLE_64(xen_sysctl_perfc_desc_t) desc;

    XEN_GUEST_HANDLE_64(xen_sysctl_perfc_val_t) val;
};


struct xen_sysctl_getdomaininfolist {

    domid_t first_domain;
    uint32_t max_domains;
    XEN_GUEST_HANDLE_64(xen_domctl_getdomaininfo_t) buffer;

    uint32_t num_domains;
};



struct xen_sysctl_debug_keys {

    XEN_GUEST_HANDLE_64(char) keys;
    uint32_t nr_keys;
};



struct xen_sysctl_cpuinfo {
    uint64_aligned_t idletime;
};
typedef struct xen_sysctl_cpuinfo xen_sysctl_cpuinfo_t;
typedef xen_sysctl_cpuinfo_t * __guest_handle_xen_sysctl_cpuinfo_t; typedef const xen_sysctl_cpuinfo_t * __guest_handle_const_xen_sysctl_cpuinfo_t;
struct xen_sysctl_getcpuinfo {

    uint32_t max_cpus;
    XEN_GUEST_HANDLE_64(xen_sysctl_cpuinfo_t) info;

    uint32_t nr_cpus;
};


struct xen_sysctl_availheap {

    uint32_t min_bitwidth;
    uint32_t max_bitwidth;
    int32_t node;

    uint64_aligned_t avail_bytes;
};


struct pm_px_val {
    uint64_aligned_t freq;
    uint64_aligned_t residency;
    uint64_aligned_t count;
};
typedef struct pm_px_val pm_px_val_t;
typedef pm_px_val_t * __guest_handle_pm_px_val_t; typedef const pm_px_val_t * __guest_handle_const_pm_px_val_t;

struct pm_px_stat {
    uint8_t total;
    uint8_t usable;
    uint8_t last;
    uint8_t cur;
    XEN_GUEST_HANDLE_64(uint64) trans_pt;
    XEN_GUEST_HANDLE_64(pm_px_val_t) pt;
};

struct pm_cx_stat {
    uint32_t nr;
    uint32_t last;
    uint64_aligned_t idle_time;
    XEN_GUEST_HANDLE_64(uint64) triggers;
    XEN_GUEST_HANDLE_64(uint64) residencies;
    uint32_t nr_pc;
    uint32_t nr_cc;







    XEN_GUEST_HANDLE_64(uint64) pc;
    XEN_GUEST_HANDLE_64(uint64) cc;
};

struct xen_sysctl_get_pmstat {
# 249 "/var/xen-dev/xen/xen/include/public/sysctl.h"
    uint32_t type;
    uint32_t cpuid;
    union {
        struct pm_px_stat getpx;
        struct pm_cx_stat getcx;

    } u;
};


struct xen_sysctl_cpu_hotplug {

    uint32_t cpu;
# 283 "/var/xen-dev/xen/xen/include/public/sysctl.h"
    uint32_t op;
};






struct xen_userspace {
    uint32_t scaling_setspeed;
};

struct xen_ondemand {
    uint32_t sampling_rate_max;
    uint32_t sampling_rate_min;

    uint32_t sampling_rate;
    uint32_t up_threshold;
};






struct xen_get_cpufreq_para {

    uint32_t cpu_num;
    uint32_t freq_num;
    uint32_t gov_num;



    XEN_GUEST_HANDLE_64(uint32) affected_cpus;
    XEN_GUEST_HANDLE_64(uint32) scaling_available_frequencies;
    XEN_GUEST_HANDLE_64(char) scaling_available_governors;
    char scaling_driver[16];

    uint32_t cpuinfo_cur_freq;
    uint32_t cpuinfo_max_freq;
    uint32_t cpuinfo_min_freq;
    uint32_t scaling_cur_freq;

    char scaling_governor[16];
    uint32_t scaling_max_freq;
    uint32_t scaling_min_freq;


    union {
        struct xen_userspace userspace;
        struct xen_ondemand ondemand;
    } u;

    int32_t turbo_enabled;
};

struct xen_set_cpufreq_gov {
    char scaling_governor[16];
};

struct xen_set_cpufreq_para {






    uint32_t ctrl_type;
    uint32_t ctrl_value;
};

struct xen_sysctl_pm_op {
# 383 "/var/xen-dev/xen/xen/include/public/sysctl.h"
    uint32_t cmd;
    uint32_t cpuid;
    union {
        struct xen_get_cpufreq_para get_para;
        struct xen_set_cpufreq_gov set_gov;
        struct xen_set_cpufreq_para set_para;
        uint64_aligned_t get_avgfreq;
        uint32_t set_sched_opt_smt;

        uint32_t get_max_cstate;
        uint32_t set_max_cstate;
    } u;
};


struct xen_sysctl_page_offline_op {




    uint32_t cmd;
    uint32_t start;
    uint32_t end;





    __guest_handle_uint32 status;
};
# 454 "/var/xen-dev/xen/xen/include/public/sysctl.h"
struct xen_sysctl_lockprof_data {
    char name[40];
    int32_t type;
    int32_t idx;
    uint64_aligned_t lock_cnt;
    uint64_aligned_t block_cnt;
    uint64_aligned_t lock_time;
    uint64_aligned_t block_time;
};
typedef struct xen_sysctl_lockprof_data xen_sysctl_lockprof_data_t;
typedef xen_sysctl_lockprof_data_t * __guest_handle_xen_sysctl_lockprof_data_t; typedef const xen_sysctl_lockprof_data_t * __guest_handle_const_xen_sysctl_lockprof_data_t;
struct xen_sysctl_lockprof_op {

    uint32_t cmd;
    uint32_t max_elem;

    uint32_t nr_elem;
    uint64_aligned_t time;

    XEN_GUEST_HANDLE_64(xen_sysctl_lockprof_data_t) data;
};






struct xen_sysctl_cputopo {
    uint32_t core;
    uint32_t socket;
    uint32_t node;
};
typedef struct xen_sysctl_cputopo xen_sysctl_cputopo_t;
typedef xen_sysctl_cputopo_t * __guest_handle_xen_sysctl_cputopo_t; typedef const xen_sysctl_cputopo_t * __guest_handle_const_xen_sysctl_cputopo_t;
# 501 "/var/xen-dev/xen/xen/include/public/sysctl.h"
struct xen_sysctl_cputopoinfo {
    uint32_t num_cpus;
    XEN_GUEST_HANDLE_64(xen_sysctl_cputopo_t) cputopo;
};





struct xen_sysctl_meminfo {
    uint64_t memsize;
    uint64_t memfree;
};
typedef struct xen_sysctl_meminfo xen_sysctl_meminfo_t;
typedef xen_sysctl_meminfo_t * __guest_handle_xen_sysctl_meminfo_t; typedef const xen_sysctl_meminfo_t * __guest_handle_const_xen_sysctl_meminfo_t;
# 533 "/var/xen-dev/xen/xen/include/public/sysctl.h"
struct xen_sysctl_numainfo {
    uint32_t num_nodes;

    XEN_GUEST_HANDLE_64(xen_sysctl_meminfo_t) meminfo;






    XEN_GUEST_HANDLE_64(uint32) distance;
};
# 555 "/var/xen-dev/xen/xen/include/public/sysctl.h"
struct xen_sysctl_cpupool_op {
    uint32_t op;
    uint32_t cpupool_id;
    uint32_t sched_id;
    uint32_t domid;
    uint32_t cpu;
    uint32_t n_dom;
    struct xenctl_bitmap cpumap;
};
# 606 "/var/xen-dev/xen/xen/include/public/sysctl.h"
struct xen_sysctl_arinc653_schedule {


    uint64_aligned_t major_frame;


    uint8_t num_sched_entries;

    struct {

        xen_domain_handle_t dom_handle;



        unsigned int vcpu_id;


        uint64_aligned_t runtime;
    } sched_entries[64];
};
typedef struct xen_sysctl_arinc653_schedule xen_sysctl_arinc653_schedule_t;
typedef xen_sysctl_arinc653_schedule_t * __guest_handle_xen_sysctl_arinc653_schedule_t; typedef const xen_sysctl_arinc653_schedule_t * __guest_handle_const_xen_sysctl_arinc653_schedule_t;
# 636 "/var/xen-dev/xen/xen/include/public/sysctl.h"
struct xen_sysctl_credit_schedule {



    unsigned tslice_ms;
    unsigned ratelimit_us;





    unsigned vcpu_migr_delay_us;
};

struct xen_sysctl_credit2_schedule {
    unsigned ratelimit_us;
};





struct xen_sysctl_scheduler_op {
    uint32_t cpupool_id;
    uint32_t sched_id;
    uint32_t cmd;
    union {
        struct xen_sysctl_sched_arinc653 {
            XEN_GUEST_HANDLE_64(xen_sysctl_arinc653_schedule_t) schedule;
        } sched_arinc653;
        struct xen_sysctl_credit_schedule sched_credit;
        struct xen_sysctl_credit2_schedule sched_credit2;
    } u;
};
# 703 "/var/xen-dev/xen/xen/include/public/sysctl.h"
struct xen_sysctl_coverage_op {
    uint32_t cmd;
    uint32_t size;
    XEN_GUEST_HANDLE_64(char) buffer;
};







struct xen_sysctl_psr_cmt_op {
    uint32_t cmd;
    uint32_t flags;
    union {
        uint64_t data;
        struct {
            uint32_t cpu;
            uint32_t rsvd;
        } l3_cache;
    } u;
};



struct xen_sysctl_pcitopoinfo {




    uint32_t num_devs;


    XEN_GUEST_HANDLE_64(physdev_pci_device_t) devs;
# 746 "/var/xen-dev/xen/xen/include/public/sysctl.h"
    XEN_GUEST_HANDLE_64(uint32) nodes;
};




struct xen_sysctl_psr_alloc {
    uint32_t cmd;
    uint32_t target;
    union {
        struct {
            uint32_t cbm_len;
            uint32_t cos_max;

            uint32_t flags;
        } cat_info;

        struct {
            uint32_t thrtl_max;
            uint32_t cos_max;

            uint32_t flags;
        } mba_info;
    } u;
};







struct xen_sysctl_cpu_levelling_caps {
# 788 "/var/xen-dev/xen/xen/include/public/sysctl.h"
    uint32_t caps;
};
# 800 "/var/xen-dev/xen/xen/include/public/sysctl.h"
struct xen_sysctl_cpu_featureset {




    uint32_t index;
    uint32_t nr_features;




    XEN_GUEST_HANDLE_64(uint32) features;
};
# 862 "/var/xen-dev/xen/xen/include/public/sysctl.h"
struct xen_livepatch_name {
    XEN_GUEST_HANDLE_64(char) name;
    uint16_t size;

    uint16_t pad[3];
};
# 885 "/var/xen-dev/xen/xen/include/public/sysctl.h"
struct xen_sysctl_livepatch_upload {
    struct xen_livepatch_name name;
    uint64_t size;
    XEN_GUEST_HANDLE_64(uint8) payload;
};
# 901 "/var/xen-dev/xen/xen/include/public/sysctl.h"
struct xen_livepatch_status {


    uint32_t state;
    int32_t rc;
};
typedef struct xen_livepatch_status xen_livepatch_status_t;
typedef xen_livepatch_status_t * __guest_handle_xen_livepatch_status_t; typedef const xen_livepatch_status_t * __guest_handle_const_xen_livepatch_status_t;

struct xen_sysctl_livepatch_get {
    struct xen_livepatch_name name;
    struct xen_livepatch_status status;
};
# 937 "/var/xen-dev/xen/xen/include/public/sysctl.h"
struct xen_sysctl_livepatch_list {
    uint32_t version;


    uint32_t idx;
    uint32_t nr;



    uint32_t pad;
    XEN_GUEST_HANDLE_64(xen_livepatch_status_t) status;

    XEN_GUEST_HANDLE_64(char) name;


    XEN_GUEST_HANDLE_64(uint32) len;

};







struct xen_sysctl_livepatch_action {
    struct xen_livepatch_name name;




    uint32_t cmd;
    uint32_t timeout;



};

struct xen_sysctl_livepatch_op {
    uint32_t cmd;
    uint32_t pad;
    union {
        struct xen_sysctl_livepatch_upload upload;
        struct xen_sysctl_livepatch_list list;
        struct xen_sysctl_livepatch_get get;
        struct xen_sysctl_livepatch_action action;
    } u;
};
# 996 "/var/xen-dev/xen/xen/include/public/sysctl.h"
struct xen_sysctl_set_parameter {
    XEN_GUEST_HANDLE_64(char) params;
    uint16_t size;
    uint16_t pad[3];
};
# 1014 "/var/xen-dev/xen/xen/include/public/sysctl.h"
struct xen_sysctl_cpu_policy {






    uint32_t index;
    uint32_t nr_leaves;


    uint32_t nr_msrs;


    uint32_t _rsvd;
    XEN_GUEST_HANDLE_64(xen_cpuid_leaf_t) cpuid_policy;
    XEN_GUEST_HANDLE_64(xen_msr_entry_t) msr_policy;
};
typedef struct xen_sysctl_cpu_policy xen_sysctl_cpu_policy_t;
typedef xen_sysctl_cpu_policy_t * __guest_handle_xen_sysctl_cpu_policy_t; typedef const xen_sysctl_cpu_policy_t * __guest_handle_const_xen_sysctl_cpu_policy_t;


struct xen_sysctl {
    uint32_t cmd;
# 1066 "/var/xen-dev/xen/xen/include/public/sysctl.h"
    uint32_t interface_version;
    union {
        struct xen_sysctl_readconsole readconsole;
        struct xen_sysctl_tbuf_op tbuf_op;
        struct xen_sysctl_physinfo physinfo;
        struct xen_sysctl_cputopoinfo cputopoinfo;
        struct xen_sysctl_pcitopoinfo pcitopoinfo;
        struct xen_sysctl_numainfo numainfo;
        struct xen_sysctl_sched_id sched_id;
        struct xen_sysctl_perfc_op perfc_op;
        struct xen_sysctl_getdomaininfolist getdomaininfolist;
        struct xen_sysctl_debug_keys debug_keys;
        struct xen_sysctl_getcpuinfo getcpuinfo;
        struct xen_sysctl_availheap availheap;
        struct xen_sysctl_get_pmstat get_pmstat;
        struct xen_sysctl_cpu_hotplug cpu_hotplug;
        struct xen_sysctl_pm_op pm_op;
        struct xen_sysctl_page_offline_op page_offline;
        struct xen_sysctl_lockprof_op lockprof_op;
        struct xen_sysctl_cpupool_op cpupool_op;
        struct xen_sysctl_scheduler_op scheduler_op;
        struct xen_sysctl_coverage_op coverage_op;
        struct xen_sysctl_psr_cmt_op psr_cmt_op;
        struct xen_sysctl_psr_alloc psr_alloc;
        struct xen_sysctl_cpu_levelling_caps cpu_levelling_caps;
        struct xen_sysctl_cpu_featureset cpu_featureset;
        struct xen_sysctl_livepatch_op livepatch;
        struct xen_sysctl_set_parameter set_parameter;

        struct xen_sysctl_cpu_policy cpu_policy;

        uint8_t pad[128];
    } u;
};
typedef struct xen_sysctl xen_sysctl_t;
typedef xen_sysctl_t * __guest_handle_xen_sysctl_t; typedef const xen_sysctl_t * __guest_handle_const_xen_sysctl_t;
# 15 "/var/xen-dev/xen/xen/include/asm/cpuid.h" 2

extern const uint32_t known_features[11];
extern const uint32_t special_features[11];

void init_guest_cpuid(void);
# 34 "/var/xen-dev/xen/xen/include/asm/cpuid.h"
extern unsigned int expected_levelling_cap, levelling_caps;

struct cpuidmasks
{
    uint64_t _1cd;
    uint64_t e1cd;
    uint64_t Da1;
    uint64_t _6c;
    uint64_t _7ab0;
};


extern __typeof__(struct cpuidmasks) per_cpu__cpuidmasks;


extern struct cpuidmasks cpuidmask_defaults;

extern struct cpuid_policy raw_cpuid_policy, host_cpuid_policy,
    pv_max_cpuid_policy, hvm_max_cpuid_policy;

extern const struct cpu_policy system_policies[];


_Bool recheck_cpu_features(unsigned int cpu);


int init_domain_cpuid_policy(struct domain *d);


void recalculate_cpuid_policy(struct domain *d);

struct vcpu;
void guest_cpuid(const struct vcpu *v, uint32_t leaf,
                 uint32_t subleaf, struct cpuid_leaf *res);
# 11 "/var/xen-dev/xen/xen/include/asm/cpufeature.h" 2
# 20 "/var/xen-dev/xen/xen/include/asm/cpufeature.h"
# 1 "/var/xen-dev/xen/xen/include/xen/bitops.h" 1
# 22 "/var/xen-dev/xen/xen/include/xen/bitops.h"
static __inline__ int generic_ffs(int x)
{
    int r = 1;

    if (!x)
        return 0;
    if (!(x & 0xffff)) {
        x >>= 16;
        r += 16;
    }
    if (!(x & 0xff)) {
        x >>= 8;
        r += 8;
    }
    if (!(x & 0xf)) {
        x >>= 4;
        r += 4;
    }
    if (!(x & 3)) {
        x >>= 2;
        r += 2;
    }
    if (!(x & 1)) {
        x >>= 1;
        r += 1;
    }
    return r;
}





static __inline__ int generic_fls(int x)
{
    int r = 32;

    if (!x)
        return 0;
    if (!(x & 0xffff0000u)) {
        x <<= 16;
        r -= 16;
    }
    if (!(x & 0xff000000u)) {
        x <<= 8;
        r -= 8;
    }
    if (!(x & 0xf0000000u)) {
        x <<= 4;
        r -= 4;
    }
    if (!(x & 0xc0000000u)) {
        x <<= 2;
        r -= 2;
    }
    if (!(x & 0x80000000u)) {
        x <<= 1;
        r -= 1;
    }
    return r;
}
# 107 "/var/xen-dev/xen/xen/include/xen/bitops.h"
# 1 "/var/xen-dev/xen/xen/include/asm/bitops.h" 1







# 1 "/var/xen-dev/xen/xen/include/asm/alternative.h" 1






# 1 "/var/xen-dev/xen/xen/include/xen/lib.h" 1



# 1 "/var/xen-dev/xen/xen/include/xen/inttypes.h" 1
# 5 "/var/xen-dev/xen/xen/include/xen/lib.h" 2
# 1 "/var/xen-dev/xen/xen/include/xen/stdarg.h" 1



typedef __builtin_va_list va_list;
# 6 "/var/xen-dev/xen/xen/include/xen/lib.h" 2

# 1 "/var/xen-dev/xen/xen/include/xen/xmalloc.h" 1





# 1 "/var/xen-dev/xen/xen/include/xen/cache.h" 1



# 1 "/var/xen-dev/xen/xen/include/asm/cache.h" 1
# 5 "/var/xen-dev/xen/xen/include/xen/cache.h" 2
# 7 "/var/xen-dev/xen/xen/include/xen/xmalloc.h" 2
# 55 "/var/xen-dev/xen/xen/include/xen/xmalloc.h"
extern void xfree(void *);
# 64 "/var/xen-dev/xen/xen/include/xen/xmalloc.h"
extern void *_xmalloc(unsigned long size, unsigned long align);
extern void *_xzalloc(unsigned long size, unsigned long align);
extern void *_xrealloc(void *ptr, unsigned long size, unsigned long align);

static __inline__ void *_xmalloc_array(
    unsigned long size, unsigned long align, unsigned long num)
{

    if ( size && num > (~0U) / size )
        return ((void*)0);
    return _xmalloc(size * num, align);
}

static __inline__ void *_xzalloc_array(
    unsigned long size, unsigned long align, unsigned long num)
{

    if ( size && num > (~0U) / size )
        return ((void*)0);
    return _xzalloc(size * num, align);
}





struct xmem_pool;

typedef void *(xmem_pool_get_memory)(unsigned long bytes);
typedef void (xmem_pool_put_memory)(void *ptr);
# 105 "/var/xen-dev/xen/xen/include/xen/xmalloc.h"
struct xmem_pool *xmem_pool_create(
    const char *name,
    xmem_pool_get_memory get_mem,
    xmem_pool_put_memory put_mem,
    unsigned long max_size,
    unsigned long grow_size);
# 120 "/var/xen-dev/xen/xen/include/xen/xmalloc.h"
void xmem_pool_destroy(struct xmem_pool *pool);






void *xmem_pool_alloc(unsigned long size, struct xmem_pool *pool);





int xmem_pool_maxalloc(struct xmem_pool *pool);






void xmem_pool_free(void *ptr, struct xmem_pool *pool);






unsigned long xmem_pool_get_used_size(struct xmem_pool *pool);
# 157 "/var/xen-dev/xen/xen/include/xen/xmalloc.h"
unsigned long xmem_pool_get_total_size(struct xmem_pool *pool);
# 8 "/var/xen-dev/xen/xen/include/xen/lib.h" 2
# 1 "/var/xen-dev/xen/xen/include/xen/string.h" 1
# 9 "/var/xen-dev/xen/xen/include/xen/string.h"
# 1 "/var/xen-dev/xen/xen/include/asm/string.h" 1




void *memcpy(void *dest, const void *src, size_t n);



void *memmove(void *dest, const void *src, size_t n);



void *memset(void *dest, int c, size_t n);
# 10 "/var/xen-dev/xen/xen/include/xen/string.h" 2
# 21 "/var/xen-dev/xen/xen/include/xen/string.h"
size_t strlcpy(char *, const char *, size_t);



size_t strlcat(char *, const char *, size_t);



int strcmp(const char *, const char *);




int strncmp(const char *, const char *, size_t);




int strnicmp(const char *, const char *, size_t);



int strcasecmp(const char *, const char *);




char *strchr(const char *, int);




char *strrchr(const char *, int);




char *strstr(const char *, const char *);




size_t strlen(const char *);




size_t strnlen(const char *, size_t);



char *strpbrk(const char *, const char *);



char *strsep(char **, const char *);



size_t strspn(const char *, const char *);
# 100 "/var/xen-dev/xen/xen/include/xen/string.h"
int memcmp(const void *, const void *, size_t);




void *memchr(const void *, int, size_t);



void *memchr_inv(const void *, int, size_t);
# 9 "/var/xen-dev/xen/xen/include/xen/lib.h" 2
# 73 "/var/xen-dev/xen/xen/include/xen/lib.h"
struct domain;

void cmdline_parse(const char *cmdline);
int runtime_parse(const char *line);
int parse_bool(const char *s, const char *e);






int parse_boolean(const char *name, const char *s, const char *e);






int cmdline_strcmp(const char *frag, const char *name);






static __inline__ void debugtrace_dump(void) {}
static __inline__ void
 __attribute__ ((format (printf, 1, 2)))
debugtrace_printk(const char *fmt, ...) {}




extern void printk(const char *format, ...)
    __attribute__ ((format (printf, 1, 2)));
# 119 "/var/xen-dev/xen/xen/include/xen/lib.h"
extern void guest_printk(const struct domain *d, const char *format, ...)
    __attribute__ ((format (printf, 2, 3)));
extern void __attribute__((__noreturn__)) panic(const char *format, ...)
    __attribute__ ((format (printf, 1, 2)));
extern long vm_assist(struct domain *, unsigned int cmd, unsigned int type,
                      unsigned long valid);
extern int __printk_ratelimit(int ratelimit_ms, int ratelimit_burst);
extern int printk_ratelimit(void);
# 154 "/var/xen-dev/xen/xen/include/xen/lib.h"
extern int snprintf(char * buf, size_t size, const char * fmt, ...)
    __attribute__ ((format (printf, 3, 4)));
extern int vsnprintf(char *buf, size_t size, const char *fmt, va_list args)
    __attribute__ ((format (printf, 3, 0)));
extern int scnprintf(char * buf, size_t size, const char * fmt, ...)
    __attribute__ ((format (printf, 3, 4)));
extern int vscnprintf(char *buf, size_t size, const char *fmt, va_list args)
    __attribute__ ((format (printf, 3, 0)));
extern int asprintf(char ** bufp, const char * fmt, ...)
    __attribute__ ((format (printf, 2, 3)));
extern int vasprintf(char ** bufp, const char * fmt, va_list args)
    __attribute__ ((format (printf, 2, 0)));

long simple_strtol(
    const char *cp,const char **endp, unsigned int base);
unsigned long simple_strtoul(
    const char *cp,const char **endp, unsigned int base);
long long simple_strtoll(
    const char *cp,const char **endp, unsigned int base);
unsigned long long simple_strtoull(
    const char *cp,const char **endp, unsigned int base);

unsigned long long parse_size_and_unit(const char *s, const char **ps);

uint64_t muldiv64(uint64_t a, uint32_t b, uint32_t c);





extern unsigned int tainted;

extern char *print_tainted(char *str);
extern void add_taint(unsigned int taint);

struct cpu_user_regs;
void dump_execstate(struct cpu_user_regs *);

void init_constructors(void);

void *bsearch(const void *key, const void *base, size_t num, size_t size,
              int (*cmp)(const void *key, const void *elt));
# 8 "/var/xen-dev/xen/xen/include/asm/alternative.h" 2

# 1 "/var/xen-dev/xen/xen/include/asm/asm-macros.h" 1



asm ( ".include \"/var/xen-dev/xen/xen/include/asm-x86/asm-macros.h\"" );
# 10 "/var/xen-dev/xen/xen/include/asm/alternative.h" 2

struct __attribute__((__packed__)) alt_instr {
    int32_t orig_offset;
    int32_t repl_offset;
    uint16_t cpuid;
    uint8_t orig_len;
    uint8_t repl_len;
    uint8_t pad_len;
    uint8_t priv;
};





extern void add_nops(void *insns, unsigned int len);

extern void apply_alternatives(struct alt_instr *start, struct alt_instr *end);
extern void alternative_instructions(void);
extern void alternative_branches(void);
# 9 "/var/xen-dev/xen/xen/include/asm/bitops.h" 2
# 22 "/var/xen-dev/xen/xen/include/asm/bitops.h"
extern void __bitop_bad_size(void);
# 35 "/var/xen-dev/xen/xen/include/asm/bitops.h"
static __inline__ void set_bit(int nr, volatile void *addr)
{
    asm volatile ( "lock; btsl %1,%0"
                   : "+m" ((*(volatile int *) addr)) : "Ir" (nr) : "memory");
}
# 54 "/var/xen-dev/xen/xen/include/asm/bitops.h"
static __inline__ void variable_set_bit(int nr, void *addr)
{
    asm volatile ( "btsl %1,%0" : "+m" (*(int *)addr) : "Ir" (nr) : "memory" );
}
static __inline__ void constant_set_bit(int nr, void *addr)
{
    ((unsigned int *)addr)[nr >> 5] |= (1u << (nr & 31));
}
# 76 "/var/xen-dev/xen/xen/include/asm/bitops.h"
static __inline__ void clear_bit(int nr, volatile void *addr)
{
    asm volatile ( "lock; btrl %1,%0"
                   : "+m" ((*(volatile int *) addr)) : "Ir" (nr) : "memory");
}
# 95 "/var/xen-dev/xen/xen/include/asm/bitops.h"
static __inline__ void variable_clear_bit(int nr, void *addr)
{
    asm volatile ( "btrl %1,%0" : "+m" (*(int *)addr) : "Ir" (nr) : "memory" );
}
static __inline__ void constant_clear_bit(int nr, void *addr)
{
    ((unsigned int *)addr)[nr >> 5] &= ~(1u << (nr & 31));
}
# 119 "/var/xen-dev/xen/xen/include/asm/bitops.h"
static __inline__ void variable_change_bit(int nr, void *addr)
{
    asm volatile ( "btcl %1,%0" : "+m" (*(int *)addr) : "Ir" (nr) : "memory" );
}
static __inline__ void constant_change_bit(int nr, void *addr)
{
    ((unsigned int *)addr)[nr >> 5] ^= (1u << (nr & 31));
}
# 143 "/var/xen-dev/xen/xen/include/asm/bitops.h"
static __inline__ void change_bit(int nr, volatile void *addr)
{
    asm volatile ( "lock; btcl %1,%0"
                    : "+m" ((*(volatile int *) addr)) : "Ir" (nr) : "memory");
}
# 161 "/var/xen-dev/xen/xen/include/asm/bitops.h"
static __inline__ int test_and_set_bit(int nr, volatile void *addr)
{
    int oldbit;

    asm volatile ( "lock; btsl %[nr], %[addr]\n\t"
                  
                   : [old] "=@ccc" (oldbit),
                     [addr] "+m" ((*(volatile int *) addr)) : [nr] "Ir" (nr) : "memory" );

    return oldbit;
}
# 186 "/var/xen-dev/xen/xen/include/asm/bitops.h"
static __inline__ int __test_and_set_bit(int nr, void *addr)
{
    int oldbit;

    asm volatile ( "btsl %[nr], %[addr]\n\t"
                  
                   : [old] "=@ccc" (oldbit),
                     [addr] "+m" (*(int *)addr) : [nr] "Ir" (nr) : "memory" );

    return oldbit;
}
# 210 "/var/xen-dev/xen/xen/include/asm/bitops.h"
static __inline__ int test_and_clear_bit(int nr, volatile void *addr)
{
    int oldbit;

    asm volatile ( "lock; btrl %[nr], %[addr]\n\t"
                  
                   : [old] "=@ccc" (oldbit),
                     [addr] "+m" ((*(volatile int *) addr)) : [nr] "Ir" (nr) : "memory" );

    return oldbit;
}
# 235 "/var/xen-dev/xen/xen/include/asm/bitops.h"
static __inline__ int __test_and_clear_bit(int nr, void *addr)
{
    int oldbit;

    asm volatile ( "btrl %[nr], %[addr]\n\t"
                  
                   : [old] "=@ccc" (oldbit),
                     [addr] "+m" (*(int *)addr) : [nr] "Ir" (nr) : "memory" );

    return oldbit;
}






static __inline__ int __test_and_change_bit(int nr, void *addr)
{
    int oldbit;

    asm volatile ( "btcl %[nr], %[addr]\n\t"
                  
                   : [old] "=@ccc" (oldbit),
                     [addr] "+m" (*(int *)addr) : [nr] "Ir" (nr) : "memory" );

    return oldbit;
}
# 276 "/var/xen-dev/xen/xen/include/asm/bitops.h"
static __inline__ int test_and_change_bit(int nr, volatile void *addr)
{
    int oldbit;

    asm volatile ( "lock; btcl %[nr], %[addr]\n\t"
                  
                   : [old] "=@ccc" (oldbit),
                     [addr] "+m" ((*(volatile int *) addr)) : [nr] "Ir" (nr) : "memory" );

    return oldbit;
}





static __inline__ int constant_test_bit(int nr, const volatile void *addr)
{
    return ((1U << (nr & 31)) &
            (((const volatile unsigned int *)addr)[nr >> 5])) != 0;
}

static __inline__ int variable_test_bit(int nr, const volatile void *addr)
{
    int oldbit;

    asm volatile ( "btl %[nr], %[addr]\n\t"
                  
                   : [old] "=@ccc" (oldbit)
                   : [addr] "m" ((*(const volatile int *) addr)), [nr] "Ir" (nr) : "memory" );

    return oldbit;
}
# 317 "/var/xen-dev/xen/xen/include/asm/bitops.h"
extern unsigned int __find_first_bit(
    const unsigned long *addr, unsigned int size);
extern unsigned int __find_next_bit(
    const unsigned long *addr, unsigned int size, unsigned int offset);
extern unsigned int __find_first_zero_bit(
    const unsigned long *addr, unsigned int size);
extern unsigned int __find_next_zero_bit(
    const unsigned long *addr, unsigned int size, unsigned int offset);

static __inline__ __attribute__ ((__always_inline__)) unsigned int __scanbit(unsigned long val, unsigned int max)
{
    if ( __builtin_constant_p(max) && max == BITS_PER_LONG )
        asm volatile (".LXEN%=_orig_s:\n\t" "bsf %[in],%[out]; cmovz %[max],%k[out]" "\n .LXEN%=_orig_e:\n\t" ".LXEN%=_diff = " "(" ".LXEN%=_repl_e""1" " - " ".LXEN%=_repl_s""1" ")" "-" "(.LXEN%=_orig_e - .LXEN%=_orig_s)" "\n\t" "mknops (""""(.LXEN%=_diff > 0) * .LXEN%=_diff)\n\t" ".LXEN%=_orig_p:\n\t" ".pushsection .altinstructions, \"a\", @progbits\n" " .long .LXEN%=_orig_s - .\n" " .long " ".LXEN%=_repl_s""1"" - .\n" " .word " "X86_FEATURE_BMI1" "\n" " .byte " "(.LXEN%=_orig_e - .LXEN%=_orig_s)" "\n" " .byte " "(" ".LXEN%=_repl_e""1" " - " ".LXEN%=_repl_s""1" ")" "\n" " .byte " "(.LXEN%=_orig_p - .LXEN%=_orig_e)" "\n" " .byte 0\n" ".section .discard, \"a\", @progbits\n" ".byte " "(.LXEN%=_orig_p - .LXEN%=_orig_s)" "\n" " .byte 0xff + (" "(" ".LXEN%=_repl_e""1" " - " ".LXEN%=_repl_s""1" ")" ") - (" "(.LXEN%=_orig_p - .LXEN%=_orig_s)" ")\n" ".section .altinstr_replacement, \"ax\", @progbits\n" ".LXEN%=_repl_s""1"":\n\t" "rep; bsf %[in],%[out]" "\n" ".LXEN%=_repl_e""1" ":\n\t" ".popsection\n" : [out] "=&r" (val) : [in] "r" (val), [max] "r" (max))



                                                       ;
    else
        asm ( "bsf %1,%0 ; cmovz %2,%k0"
              : "=&r" (val) : "r" (val), "r" (max) );
    return (unsigned int)val;
}
# 410 "/var/xen-dev/xen/xen/include/asm/bitops.h"
static __inline__ unsigned int find_first_set_bit(unsigned long word)
{
    asm ( "rep; bsf %1,%0" : "=r" (word) : "rm" (word) );
    return (unsigned int)word;
}







static __inline__ int ffsl(unsigned long x)
{
    long r;

    asm ( "bsf %1,%0\n\t"
          "jnz 1f\n\t"
          "mov $-1,%0\n"
          "1:" : "=r" (r) : "rm" (x));
    return (int)r+1;
}

static __inline__ int ffs(unsigned int x)
{
    int r;

    asm ( "bsf %1,%0\n\t"
          "jnz 1f\n\t"
          "mov $-1,%0\n"
          "1:" : "=r" (r) : "rm" (x));
    return r + 1;
}







static __inline__ int flsl(unsigned long x)
{
    long r;

    asm ( "bsr %1,%0\n\t"
          "jnz 1f\n\t"
          "mov $-1,%0\n"
          "1:" : "=r" (r) : "rm" (x));
    return (int)r+1;
}

static __inline__ int fls(unsigned int x)
{
    int r;

    asm ( "bsr %1,%0\n\t"
          "jnz 1f\n\t"
          "mov $-1,%0\n"
          "1:" : "=r" (r) : "rm" (x));
    return r + 1;
}
# 108 "/var/xen-dev/xen/xen/include/xen/bitops.h" 2






static __inline__ int generic_ffs64(__u64 x)
{
    return !x || (__u32)x ? ffs(x) : ffs(x >> 32) + 32;
}



static __inline__ int generic_fls64(__u64 x)
{
    __u32 h = x >> 32;

    return h ? fls(h) + 32 : fls(x);
}




static __inline__ int get_bitmask_order(unsigned int count)
{
    int order;

    order = fls(count);
    return order;
}

static __inline__ int get_count_order(unsigned int count)
{
    int order;

    order = fls(count) - 1;
    if (count & (count - 1))
        order++;
    return order;
}






static __inline__ unsigned int generic_hweight32(unsigned int w)
{
    w -= (w >> 1) & 0x55555555;
    w = (w & 0x33333333) + ((w >> 2) & 0x33333333);
    w = (w + (w >> 4)) & 0x0f0f0f0f;

    if ( IS_ENABLED(CONFIG_HAS_FAST_MULTIPLY) )
        return (w * 0x01010101) >> 24;

    w += w >> 8;

    return (w + (w >> 16)) & 0xff;
}

static __inline__ unsigned int generic_hweight16(unsigned int w)
{
    w -= ((w >> 1) & 0x5555);
    w = (w & 0x3333) + ((w >> 2) & 0x3333);
    w = (w + (w >> 4)) & 0x0f0f;

    return (w + (w >> 8)) & 0xff;
}

static __inline__ unsigned int generic_hweight8(unsigned int w)
{
    w -= ((w >> 1) & 0x55);
    w = (w & 0x33) + ((w >> 2) & 0x33);

    return (w + (w >> 4)) & 0x0f;
}

static __inline__ unsigned int generic_hweight64(uint64_t w)
{
    if ( BITS_PER_LONG < 64 )
        return generic_hweight32(w >> 32) + generic_hweight32(w);

    w -= (w >> 1) & 0x5555555555555555ul;
    w = (w & 0x3333333333333333ul) + ((w >> 2) & 0x3333333333333333ul);
    w = (w + (w >> 4)) & 0x0f0f0f0f0f0f0f0ful;

    if ( IS_ENABLED(CONFIG_HAS_FAST_MULTIPLY) )
        return (w * 0x0101010101010101ul) >> 56;

    w += w >> 8;
    w += w >> 16;

    return (w + (w >> 32)) & 0xFF;
}

static __inline__ unsigned long hweight_long(unsigned long w)
{
    return sizeof(w) == 4 ? generic_hweight32(w) : generic_hweight64(w);
}







static __inline__ __u32 rol32(__u32 word, unsigned int shift)
{
    return (word << shift) | (word >> (32 - shift));
}







static __inline__ __u32 ror32(__u32 word, unsigned int shift)
{
    return (word >> shift) | (word << (32 - shift));
}
# 21 "/var/xen-dev/xen/xen/include/asm/cpufeature.h" 2
# 144 "/var/xen-dev/xen/xen/include/asm/cpufeature.h"
enum _cache_type {
    CACHE_TYPE_NULL = 0,
    CACHE_TYPE_DATA = 1,
    CACHE_TYPE_INST = 2,
    CACHE_TYPE_UNIFIED = 3
};

union _cpuid4_leaf_eax {
    struct {
        enum _cache_type type:5;
        unsigned int level:3;
        unsigned int is_self_initializing:1;
        unsigned int is_fully_associative:1;
        unsigned int reserved:4;
        unsigned int num_threads_sharing:12;
        unsigned int num_cores_on_die:6;
    } split;
    u32 full;
};

union _cpuid4_leaf_ebx {
    struct {
        unsigned int coherency_line_size:12;
        unsigned int physical_line_partition:10;
        unsigned int ways_of_associativity:10;
    } split;
    u32 full;
};

union _cpuid4_leaf_ecx {
    struct {
        unsigned int number_of_sets:32;
    } split;
    u32 full;
};

struct cpuid4_info {
    union _cpuid4_leaf_eax eax;
    union _cpuid4_leaf_ebx ebx;
    union _cpuid4_leaf_ecx ecx;
    unsigned long size;
};

int cpuid4_cache_lookup(int index, struct cpuid4_info *this_leaf);
# 13 "/var/xen-dev/xen/xen/include/asm/asm_defns.h" 2







asm ( "\t.equ CONFIG_INDIRECT_THUNK, "
      "IS_ENABLED(CONFIG_INDIRECT_THUNK)" );

# 1 "/var/xen-dev/xen/xen/include/asm/indirect_thunk_asm.h" 1
# 10 "/var/xen-dev/xen/xen/include/asm/indirect_thunk_asm.h"
asm ( "\t.include \"asm/indirect_thunk_asm.h\"" );
# 24 "/var/xen-dev/xen/xen/include/asm/asm_defns.h" 2


void ret_from_intr(void);
# 215 "/var/xen-dev/xen/xen/include/asm/asm_defns.h"
static __inline__ __attribute__ ((__always_inline__)) void clac(void)
{

    asm volatile (".LXEN%=_orig_s:\n\t" "" "\n .LXEN%=_orig_e:\n\t" ".LXEN%=_diff = " "(" ".LXEN%=_repl_e""1" " - " ".LXEN%=_repl_s""1" ")" "-" "(.LXEN%=_orig_e - .LXEN%=_orig_s)" "\n\t" "mknops (""""(.LXEN%=_diff > 0) * .LXEN%=_diff)\n\t" ".LXEN%=_orig_p:\n\t" ".pushsection .altinstructions, \"a\", @progbits\n" " .long .LXEN%=_orig_s - .\n" " .long " ".LXEN%=_repl_s""1"" - .\n" " .word " "X86_FEATURE_XEN_SMAP" "\n" " .byte " "(.LXEN%=_orig_e - .LXEN%=_orig_s)" "\n" " .byte " "(" ".LXEN%=_repl_e""1" " - " ".LXEN%=_repl_s""1" ")" "\n" " .byte " "(.LXEN%=_orig_p - .LXEN%=_orig_e)" "\n" " .byte 0\n" ".section .discard, \"a\", @progbits\n" ".byte " "(.LXEN%=_orig_p - .LXEN%=_orig_s)" "\n" " .byte 0xff + (" "(" ".LXEN%=_repl_e""1" " - " ".LXEN%=_repl_s""1" ")" ") - (" "(.LXEN%=_orig_p - .LXEN%=_orig_s)" ")\n" ".section .altinstr_replacement, \"ax\", @progbits\n" ".LXEN%=_repl_s""1"":\n\t" ".byte 0x0f,0x01,0xca" "\n" ".LXEN%=_repl_e""1" ":\n\t" ".popsection\n" : : : "memory");
}

static __inline__ __attribute__ ((__always_inline__)) void stac(void)
{

    asm volatile (".LXEN%=_orig_s:\n\t" "" "\n .LXEN%=_orig_e:\n\t" ".LXEN%=_diff = " "(" ".LXEN%=_repl_e""1" " - " ".LXEN%=_repl_s""1" ")" "-" "(.LXEN%=_orig_e - .LXEN%=_orig_s)" "\n\t" "mknops (""""(.LXEN%=_diff > 0) * .LXEN%=_diff)\n\t" ".LXEN%=_orig_p:\n\t" ".pushsection .altinstructions, \"a\", @progbits\n" " .long .LXEN%=_orig_s - .\n" " .long " ".LXEN%=_repl_s""1"" - .\n" " .word " "X86_FEATURE_XEN_SMAP" "\n" " .byte " "(.LXEN%=_orig_e - .LXEN%=_orig_s)" "\n" " .byte " "(" ".LXEN%=_repl_e""1" " - " ".LXEN%=_repl_s""1" ")" "\n" " .byte " "(.LXEN%=_orig_p - .LXEN%=_orig_e)" "\n" " .byte 0\n" ".section .discard, \"a\", @progbits\n" ".byte " "(.LXEN%=_orig_p - .LXEN%=_orig_s)" "\n" " .byte 0xff + (" "(" ".LXEN%=_repl_e""1" " - " ".LXEN%=_repl_s""1" ")" ") - (" "(.LXEN%=_orig_p - .LXEN%=_orig_s)" ")\n" ".section .altinstr_replacement, \"ax\", @progbits\n" ".LXEN%=_repl_s""1"":\n\t" ".byte 0x0f,0x01,0xcb" "\n" ".LXEN%=_repl_e""1" ":\n\t" ".popsection\n" : : : "memory");
}
# 13 "/var/xen-dev/xen/xen/include/asm/msr.h" 2

# 1 "/var/xen-dev/xen/xen/include/asm/processor.h" 1
# 10 "/var/xen-dev/xen/xen/include/asm/processor.h"
# 1 "/var/xen-dev/xen/xen/include/xen/smp.h" 1



# 1 "/var/xen-dev/xen/xen/include/asm/smp.h" 1
# 9 "/var/xen-dev/xen/xen/include/asm/smp.h"
# 1 "/var/xen-dev/xen/xen/include/xen/cpumask.h" 1
# 58 "/var/xen-dev/xen/xen/include/xen/cpumask.h"
# 1 "/var/xen-dev/xen/xen/include/xen/bitmap.h" 1
# 69 "/var/xen-dev/xen/xen/include/xen/bitmap.h"
extern int __bitmap_empty(const unsigned long *bitmap, int bits);
extern int __bitmap_full(const unsigned long *bitmap, int bits);
extern int __bitmap_equal(const unsigned long *bitmap1,
                 const unsigned long *bitmap2, int bits);
extern void __bitmap_complement(unsigned long *dst, const unsigned long *src,
   int bits);
extern void __bitmap_and(unsigned long *dst, const unsigned long *bitmap1,
   const unsigned long *bitmap2, int bits);
extern void __bitmap_or(unsigned long *dst, const unsigned long *bitmap1,
   const unsigned long *bitmap2, int bits);
extern void __bitmap_xor(unsigned long *dst, const unsigned long *bitmap1,
   const unsigned long *bitmap2, int bits);
extern void __bitmap_andnot(unsigned long *dst, const unsigned long *bitmap1,
   const unsigned long *bitmap2, int bits);
extern int __bitmap_intersects(const unsigned long *bitmap1,
   const unsigned long *bitmap2, int bits);
extern int __bitmap_subset(const unsigned long *bitmap1,
   const unsigned long *bitmap2, int bits);
extern int __bitmap_weight(const unsigned long *bitmap, int bits);

extern int bitmap_find_free_region(unsigned long *bitmap, int bits, int order);
extern void bitmap_release_region(unsigned long *bitmap, int pos, int order);
extern int bitmap_allocate_region(unsigned long *bitmap, int pos, int order);
# 111 "/var/xen-dev/xen/xen/include/xen/bitmap.h"
static __inline__ void bitmap_zero(unsigned long *dst, int nbits)
{
 unsigned int n__ = (nbits); if (__builtin_constant_p(nbits) && !n__) { ; } else if (__builtin_constant_p(nbits) && n__ <= BITS_PER_LONG) { *dst = 0UL; } else { __builtin_memset(dst, 0, ((((nbits)+BITS_PER_LONG-1)/BITS_PER_LONG) * sizeof(unsigned long))); }

                                      ;
}

static __inline__ void bitmap_fill(unsigned long *dst, int nbits)
{
 size_t nlongs = (((nbits)+BITS_PER_LONG-1)/BITS_PER_LONG);

 switch (nlongs) {
 case 0:
  break;
 default:
  __builtin_memset(dst, -1, (nlongs - 1) * sizeof(unsigned long));

 case 1:
  dst[nlongs - 1] = ( ((nbits) % BITS_PER_LONG) ? (1UL<<((nbits) % BITS_PER_LONG))-1 : ~0UL );
  break;
 }
}

static __inline__ void bitmap_copy(unsigned long *dst, const unsigned long *src,
   int nbits)
{
 unsigned int n__ = (nbits); if (__builtin_constant_p(nbits) && !n__) { ; } else if (__builtin_constant_p(nbits) && n__ <= BITS_PER_LONG) { *dst = *src; } else { __builtin_memcpy(dst, src, ((((nbits)+BITS_PER_LONG-1)/BITS_PER_LONG) * sizeof(unsigned long))); }

                                        ;
}

static __inline__ void bitmap_and(unsigned long *dst, const unsigned long *src1,
   const unsigned long *src2, int nbits)
{
 unsigned int n__ = (nbits); if (__builtin_constant_p(nbits) && !n__) { ; } else if (__builtin_constant_p(nbits) && n__ <= BITS_PER_LONG) { *dst = *src1 & *src2; } else { __bitmap_and(dst, src1, src2, nbits); }

                                       ;
}

static __inline__ void bitmap_or(unsigned long *dst, const unsigned long *src1,
   const unsigned long *src2, int nbits)
{
 unsigned int n__ = (nbits); if (__builtin_constant_p(nbits) && !n__) { ; } else if (__builtin_constant_p(nbits) && n__ <= BITS_PER_LONG) { *dst = *src1 | *src2; } else { __bitmap_or(dst, src1, src2, nbits); }

                                      ;
}

static __inline__ void bitmap_xor(unsigned long *dst, const unsigned long *src1,
   const unsigned long *src2, int nbits)
{
 unsigned int n__ = (nbits); if (__builtin_constant_p(nbits) && !n__) { ; } else if (__builtin_constant_p(nbits) && n__ <= BITS_PER_LONG) { *dst = *src1 ^ *src2; } else { __bitmap_xor(dst, src1, src2, nbits); }

                                       ;
}

static __inline__ void bitmap_andnot(unsigned long *dst, const unsigned long *src1,
   const unsigned long *src2, int nbits)
{
 unsigned int n__ = (nbits); if (__builtin_constant_p(nbits) && !n__) { ; } else if (__builtin_constant_p(nbits) && n__ <= BITS_PER_LONG) { *dst = *src1 & ~*src2; } else { __bitmap_andnot(dst, src1, src2, nbits); }

                                          ;
}

static __inline__ void bitmap_complement(unsigned long *dst, const unsigned long *src,
   int nbits)
{
 unsigned int n__ = (nbits); if (__builtin_constant_p(nbits) && !n__) { ; } else if (__builtin_constant_p(nbits) && n__ <= BITS_PER_LONG) { *dst = ~*src & ( ((nbits) % BITS_PER_LONG) ? (1UL<<((nbits) % BITS_PER_LONG))-1 : ~0UL ); } else { __bitmap_complement(dst, src, nbits); }

                                       ;
}

static __inline__ int bitmap_equal(const unsigned long *src1,
   const unsigned long *src2, int nbits)
{
 unsigned int n__ = (nbits); if (__builtin_constant_p(nbits) && !n__) { return -1; } else if (__builtin_constant_p(nbits) && n__ <= BITS_PER_LONG) { return !((*src1 ^ *src2) & ( ((nbits) % BITS_PER_LONG) ? (1UL<<((nbits) % BITS_PER_LONG))-1 : ~0UL )); } else { return __bitmap_equal(src1, src2, nbits); }


                                           ;
}

static __inline__ int bitmap_intersects(const unsigned long *src1,
   const unsigned long *src2, int nbits)
{
 unsigned int n__ = (nbits); if (__builtin_constant_p(nbits) && !n__) { return -1; } else if (__builtin_constant_p(nbits) && n__ <= BITS_PER_LONG) { return ((*src1 & *src2) & ( ((nbits) % BITS_PER_LONG) ? (1UL<<((nbits) % BITS_PER_LONG))-1 : ~0UL )) != 0; } else { return __bitmap_intersects(src1, src2, nbits); }


                                                ;
}

static __inline__ int bitmap_subset(const unsigned long *src1,
   const unsigned long *src2, int nbits)
{
 unsigned int n__ = (nbits); if (__builtin_constant_p(nbits) && !n__) { return -1; } else if (__builtin_constant_p(nbits) && n__ <= BITS_PER_LONG) { return !((*src1 & ~*src2) & ( ((nbits) % BITS_PER_LONG) ? (1UL<<((nbits) % BITS_PER_LONG))-1 : ~0UL )); } else { return __bitmap_subset(src1, src2, nbits); }


                                            ;
}

static __inline__ int bitmap_empty(const unsigned long *src, int nbits)
{
 unsigned int n__ = (nbits); if (__builtin_constant_p(nbits) && !n__) { return -1; } else if (__builtin_constant_p(nbits) && n__ <= BITS_PER_LONG) { return !(*src & ( ((nbits) % BITS_PER_LONG) ? (1UL<<((nbits) % BITS_PER_LONG))-1 : ~0UL )); } else { return __bitmap_empty(src, nbits); }


                                    ;
}

static __inline__ int bitmap_full(const unsigned long *src, int nbits)
{
 unsigned int n__ = (nbits); if (__builtin_constant_p(nbits) && !n__) { return -1; } else if (__builtin_constant_p(nbits) && n__ <= BITS_PER_LONG) { return !(~*src & ( ((nbits) % BITS_PER_LONG) ? (1UL<<((nbits) % BITS_PER_LONG))-1 : ~0UL )); } else { return __bitmap_full(src, nbits); }


                                   ;
}

static __inline__ int bitmap_weight(const unsigned long *src, int nbits)
{
 return __bitmap_weight(src, nbits);
}




void bitmap_long_to_byte(uint8_t *bp, const unsigned long *lp, int nbits);
void bitmap_byte_to_long(unsigned long *lp, const uint8_t *bp, int nbits);
# 59 "/var/xen-dev/xen/xen/include/xen/cpumask.h" 2

# 1 "/var/xen-dev/xen/xen/include/xen/random.h" 1



unsigned int get_random(void);


extern unsigned int boot_random;
# 61 "/var/xen-dev/xen/xen/include/xen/cpumask.h" 2

typedef struct cpumask{ unsigned long bits[(((NR_CPUS)+BITS_PER_LONG-1)/BITS_PER_LONG)]; } cpumask_t;







extern unsigned int nr_cpu_ids;
# 81 "/var/xen-dev/xen/xen/include/xen/cpumask.h"
static __inline__ unsigned int cpumask_check(unsigned int cpu)
{
 do { if ( __builtin_expect(!!(!(cpu < nr_cpu_ids)),0) ) do { do { ({ _Static_assert(!((83) >> ((31 - 24) + (31 - 24))), "!(" "(83) >> (BUG_LINE_LO_WIDTH + BUG_LINE_HI_WIDTH)" ")"); }); ({ _Static_assert(!((3) >= 4), "!(" "(3) >= BUGFRAME_NR" ")"); }); asm volatile ( ".Lbug%=: ud2\n" ".pushsection .bug_frames.%c[bf_type], \"a\", @progbits\n" ".p2align 2\n" ".Lfrm%=:\n" ".long (.Lbug%= - .Lfrm%=) + %c[bf_line_hi]\n" ".long (%c[bf_ptr] - .Lfrm%=) + %c[bf_line_lo]\n" ".if " "1" "\n" ".long 0, %c[bf_msg] - .Lfrm%=\n" ".endif\n" ".popsection\n" :: [bf_type] "i" (3), [bf_ptr] "i" ("/var/xen-dev/xen/xen/include/xen/cpumask.h"), [bf_msg] "i" ("cpu < nr_cpu_ids"), [bf_line_lo] "i" ((83 & ((1 << (31 - 24)) - 1)) << 24), [bf_line_hi] "i" (((83) >> (31 - 24)) << 24) ); } while (0); __builtin_unreachable(); } while (0); } while (0);
 return cpu;
}

static __inline__ void cpumask_set_cpu(int cpu, volatile cpumask_t *dstp)
{
 ({ if ( (sizeof(*(dstp->bits)) < 4) ) __bitop_bad_size(); set_bit(cpumask_check(cpu), dstp->bits); });
}

static __inline__ void __cpumask_set_cpu(int cpu, cpumask_t *dstp)
{
 ({ if ( (sizeof(*(dstp->bits)) < 4) ) __bitop_bad_size(); __builtin_constant_p(cpumask_check(cpu)) ? constant_set_bit(cpumask_check(cpu), dstp->bits) : variable_set_bit(cpumask_check(cpu), dstp->bits); });
}

static __inline__ void cpumask_clear_cpu(int cpu, volatile cpumask_t *dstp)
{
 ({ if ( (sizeof(*(dstp->bits)) < 4) ) __bitop_bad_size(); clear_bit(cpumask_check(cpu), dstp->bits); });
}

static __inline__ void __cpumask_clear_cpu(int cpu, cpumask_t *dstp)
{
 ({ if ( (sizeof(*(dstp->bits)) < 4) ) __bitop_bad_size(); __builtin_constant_p(cpumask_check(cpu)) ? constant_clear_bit(cpumask_check(cpu), dstp->bits) : variable_clear_bit(cpumask_check(cpu), dstp->bits); });
}

static __inline__ void cpumask_setall(cpumask_t *dstp)
{
 bitmap_fill(dstp->bits, ((((NR_CPUS)+BITS_PER_LONG-1)/BITS_PER_LONG) * BITS_PER_LONG));
}

static __inline__ void cpumask_clear(cpumask_t *dstp)
{
 bitmap_zero(dstp->bits, ((((NR_CPUS)+BITS_PER_LONG-1)/BITS_PER_LONG) * BITS_PER_LONG));
}

static __inline__ _Bool cpumask_test_cpu(unsigned int cpu, const cpumask_t *src)
{
    return ({ if ( (sizeof(*(src->bits)) < 4) ) __bitop_bad_size(); __builtin_constant_p(cpumask_check(cpu)) ? constant_test_bit(cpumask_check(cpu), src->bits) : variable_test_bit(cpumask_check(cpu), src->bits); });
}

static __inline__ int cpumask_test_and_set_cpu(int cpu, volatile cpumask_t *addr)
{
 return ({ if ( (sizeof(*(addr->bits)) < 4) ) __bitop_bad_size(); test_and_set_bit(cpumask_check(cpu), addr->bits); });
}

static __inline__ int __cpumask_test_and_set_cpu(int cpu, cpumask_t *addr)
{
 return ({ if ( (sizeof(*(addr->bits)) < 4) ) __bitop_bad_size(); __test_and_set_bit(cpumask_check(cpu), addr->bits); });
}

static __inline__ int cpumask_test_and_clear_cpu(int cpu, volatile cpumask_t *addr)
{
 return ({ if ( (sizeof(*(addr->bits)) < 4) ) __bitop_bad_size(); test_and_clear_bit(cpumask_check(cpu), addr->bits); });
}

static __inline__ int __cpumask_test_and_clear_cpu(int cpu, cpumask_t *addr)
{
 return ({ if ( (sizeof(*(addr->bits)) < 4) ) __bitop_bad_size(); __test_and_clear_bit(cpumask_check(cpu), addr->bits); });
}

static __inline__ void cpumask_and(cpumask_t *dstp, const cpumask_t *src1p,
          const cpumask_t *src2p)
{
 bitmap_and(dstp->bits, src1p->bits, src2p->bits, ((((NR_CPUS)+BITS_PER_LONG-1)/BITS_PER_LONG) * BITS_PER_LONG));
}

static __inline__ void cpumask_or(cpumask_t *dstp, const cpumask_t *src1p,
         const cpumask_t *src2p)
{
 bitmap_or(dstp->bits, src1p->bits, src2p->bits, ((((NR_CPUS)+BITS_PER_LONG-1)/BITS_PER_LONG) * BITS_PER_LONG));
}

static __inline__ void cpumask_xor(cpumask_t *dstp, const cpumask_t *src1p,
          const cpumask_t *src2p)
{
 bitmap_xor(dstp->bits, src1p->bits, src2p->bits, ((((NR_CPUS)+BITS_PER_LONG-1)/BITS_PER_LONG) * BITS_PER_LONG));
}

static __inline__ void cpumask_andnot(cpumask_t *dstp, const cpumask_t *src1p,
      const cpumask_t *src2p)
{
 bitmap_andnot(dstp->bits, src1p->bits, src2p->bits, ((((NR_CPUS)+BITS_PER_LONG-1)/BITS_PER_LONG) * BITS_PER_LONG));
}

static __inline__ void cpumask_complement(cpumask_t *dstp, const cpumask_t *srcp)
{
 bitmap_complement(dstp->bits, srcp->bits, ((((NR_CPUS)+BITS_PER_LONG-1)/BITS_PER_LONG) * BITS_PER_LONG));
}

static __inline__ int cpumask_equal(const cpumask_t *src1p,
    const cpumask_t *src2p)
{
 return bitmap_equal(src1p->bits, src2p->bits, nr_cpu_ids);
}

static __inline__ int cpumask_intersects(const cpumask_t *src1p,
         const cpumask_t *src2p)
{
 return bitmap_intersects(src1p->bits, src2p->bits, nr_cpu_ids);
}

static __inline__ int cpumask_subset(const cpumask_t *src1p,
     const cpumask_t *src2p)
{
 return bitmap_subset(src1p->bits, src2p->bits, nr_cpu_ids);
}

static __inline__ int cpumask_empty(const cpumask_t *srcp)
{
 return bitmap_empty(srcp->bits, nr_cpu_ids);
}

static __inline__ int cpumask_full(const cpumask_t *srcp)
{
 return bitmap_full(srcp->bits, nr_cpu_ids);
}

static __inline__ int cpumask_weight(const cpumask_t *srcp)
{
 return bitmap_weight(srcp->bits, nr_cpu_ids);
}

static __inline__ void cpumask_copy(cpumask_t *dstp, const cpumask_t *srcp)
{
 bitmap_copy(dstp->bits, srcp->bits, ((((NR_CPUS)+BITS_PER_LONG-1)/BITS_PER_LONG) * BITS_PER_LONG));
}

static __inline__ int cpumask_first(const cpumask_t *srcp)
{
 return ({ int __x = (nr_cpu_ids); int __y = (({ unsigned int r__; const unsigned long *a__ = (srcp->bits); unsigned int s__ = (nr_cpu_ids); unsigned int o__ = (0); if ( o__ >= s__ ) r__ = s__; else if ( __builtin_constant_p(nr_cpu_ids) && s__ <= BITS_PER_LONG ) r__ = o__ + __scanbit(*(const unsigned long *)(a__) >> o__, s__); else if ( __builtin_constant_p(0) && !o__ ) r__ = __find_first_bit(a__, s__); else r__ = __find_next_bit(a__, s__, o__); r__; })); __x < __y ? __x: __y; });
}

static __inline__ int cpumask_next(int n, const cpumask_t *srcp)
{

 if (n != -1)
  cpumask_check(n);

 return ({ int __x = (nr_cpu_ids); int __y = (({ unsigned int r__; const unsigned long *a__ = (srcp->bits); unsigned int s__ = (nr_cpu_ids); unsigned int o__ = (n + 1); if ( o__ >= s__ ) r__ = s__; else if ( __builtin_constant_p(nr_cpu_ids) && s__ <= BITS_PER_LONG ) r__ = o__ + __scanbit(*(const unsigned long *)(a__) >> o__, s__); else if ( __builtin_constant_p(n + 1) && !o__ ) r__ = __find_first_bit(a__, s__); else r__ = __find_next_bit(a__, s__, o__); r__; })); __x < __y ? __x: __y; })
                                                                  ;
}

static __inline__ int cpumask_last(const cpumask_t *srcp)
{
 int cpu, pcpu = nr_cpu_ids;

 for (cpu = cpumask_first(srcp);
      cpu < nr_cpu_ids;
      cpu = cpumask_next(cpu, srcp))
  pcpu = cpu;
 return pcpu;
}

static __inline__ int cpumask_cycle(int n, const cpumask_t *srcp)
{
    int nxt = cpumask_next(n, srcp);

    if (nxt == nr_cpu_ids)
        nxt = cpumask_first(srcp);
    return nxt;
}

static __inline__ int cpumask_test_or_cycle(int n, const cpumask_t *srcp)
{
    if ( cpumask_test_cpu(n, srcp) )
        return n;

    return cpumask_cycle(n, srcp);
}

static __inline__ unsigned int cpumask_any(const cpumask_t *srcp)
{
    unsigned int cpu = cpumask_first(srcp);
    unsigned int w = cpumask_weight(srcp);

    if ( w > 1 && cpu < nr_cpu_ids )
        for ( w = get_random() % w; w--; )
        {
            unsigned int next = cpumask_next(cpu, srcp);

            if ( next >= nr_cpu_ids )
                break;
            cpu = next;
        }

    return cpu;
}
# 277 "/var/xen-dev/xen/xen/include/xen/cpumask.h"
extern const unsigned long
 cpu_bit_bitmap[BITS_PER_LONG+1][(((NR_CPUS)+BITS_PER_LONG-1)/BITS_PER_LONG)];

static __inline__ const cpumask_t *cpumask_of(unsigned int cpu)
{
 const unsigned long *p = cpu_bit_bitmap[1 + cpumask_check(cpu) %
                                                   BITS_PER_LONG];

 return (const cpumask_t *)(p - cpu / BITS_PER_LONG);
}



extern const cpumask_t cpumask_all;
# 349 "/var/xen-dev/xen/xen/include/xen/cpumask.h"
typedef cpumask_t cpumask_var_t[1];

static __inline__ _Bool alloc_cpumask_var(cpumask_var_t *mask)
{
 return 1;
}


static __inline__ _Bool zalloc_cpumask_var(cpumask_var_t *mask)
{
 cpumask_clear(*mask);
 return 1;
}


static __inline__ void free_cpumask_var(cpumask_var_t mask)
{
}
# 437 "/var/xen-dev/xen/xen/include/xen/cpumask.h"
extern cpumask_t cpu_possible_map;
extern cpumask_t cpu_online_map;
extern cpumask_t cpu_present_map;
# 462 "/var/xen-dev/xen/xen/include/xen/cpumask.h"
struct xenctl_bitmap;
int cpumask_to_xenctl_bitmap(struct xenctl_bitmap *, const cpumask_t *);
int xenctl_bitmap_to_cpumask(cpumask_var_t *, const struct xenctl_bitmap *);
# 10 "/var/xen-dev/xen/xen/include/asm/smp.h" 2
# 1 "/var/xen-dev/xen/xen/include/asm/current.h" 1
# 12 "/var/xen-dev/xen/xen/include/asm/current.h"
# 1 "/var/xen-dev/xen/xen/include/asm/page.h" 1
# 23 "/var/xen-dev/xen/xen/include/asm/page.h"
# 1 "/var/xen-dev/xen/xen/include/asm/x86_64/page.h" 1
# 37 "/var/xen-dev/xen/xen/include/asm/x86_64/page.h"
static __inline__ unsigned long canonicalise_addr(unsigned long addr)
{
    if ( addr & (1UL << (48 - 1)) )
        return addr | (~0UL & ~(((1UL) << 48) - 1));
    else
        return addr & ~(~0UL & ~(((1UL) << 48) - 1));
}



# 1 "/var/xen-dev/xen/xen/include/xen/pdx.h" 1
# 48 "/var/xen-dev/xen/xen/include/asm/x86_64/page.h" 2

extern unsigned long xen_virt_end;
# 60 "/var/xen-dev/xen/xen/include/asm/x86_64/page.h"
static __inline__ unsigned long __virt_to_maddr(unsigned long va)
{
    do { if ( __builtin_expect(!!(!(va < DIRECTMAP_VIRT_END)),0) ) do { do { ({ _Static_assert(!((62) >> ((31 - 24) + (31 - 24))), "!(" "(62) >> (BUG_LINE_LO_WIDTH + BUG_LINE_HI_WIDTH)" ")"); }); ({ _Static_assert(!((3) >= 4), "!(" "(3) >= BUGFRAME_NR" ")"); }); asm volatile ( ".Lbug%=: ud2\n" ".pushsection .bug_frames.%c[bf_type], \"a\", @progbits\n" ".p2align 2\n" ".Lfrm%=:\n" ".long (.Lbug%= - .Lfrm%=) + %c[bf_line_hi]\n" ".long (%c[bf_ptr] - .Lfrm%=) + %c[bf_line_lo]\n" ".if " "1" "\n" ".long 0, %c[bf_msg] - .Lfrm%=\n" ".endif\n" ".popsection\n" :: [bf_type] "i" (3), [bf_ptr] "i" ("/var/xen-dev/xen/xen/include/asm/x86_64/page.h"), [bf_msg] "i" ("va < DIRECTMAP_VIRT_END"), [bf_line_lo] "i" ((62 & ((1 << (31 - 24)) - 1)) << 24), [bf_line_hi] "i" (((62) >> (31 - 24)) << 24) ); } while (0); __builtin_unreachable(); } while (0); } while (0);
    if ( va >= DIRECTMAP_VIRT_START )
        va -= DIRECTMAP_VIRT_START;
    else
    {
        ({ _Static_assert(!(XEN_VIRT_END - XEN_VIRT_START != GB(1)), "!(" "XEN_VIRT_END - XEN_VIRT_START != GB(1)" ")"); });

        do { if ( __builtin_expect(!!(!(((long)va >> (18 + 12)) == ((long)XEN_VIRT_START >> (18 + 12)))),0) ) do { do { ({ _Static_assert(!((70) >> ((31 - 24) + (31 - 24))), "!(" "(70) >> (BUG_LINE_LO_WIDTH + BUG_LINE_HI_WIDTH)" ")"); }); ({ _Static_assert(!((3) >= 4), "!(" "(3) >= BUGFRAME_NR" ")"); }); asm volatile ( ".Lbug%=: ud2\n" ".pushsection .bug_frames.%c[bf_type], \"a\", @progbits\n" ".p2align 2\n" ".Lfrm%=:\n" ".long (.Lbug%= - .Lfrm%=) + %c[bf_line_hi]\n" ".long (%c[bf_ptr] - .Lfrm%=) + %c[bf_line_lo]\n" ".if " "1" "\n" ".long 0, %c[bf_msg] - .Lfrm%=\n" ".endif\n" ".popsection\n" :: [bf_type] "i" (3), [bf_ptr] "i" ("/var/xen-dev/xen/xen/include/asm/x86_64/page.h"), [bf_msg] "i" ("((long)va >> (PAGE_ORDER_1G + PAGE_SHIFT)) == ((long)XEN_VIRT_START >> (PAGE_ORDER_1G + PAGE_SHIFT))"), [bf_line_lo] "i" ((70 & ((1 << (31 - 24)) - 1)) << 24), [bf_line_hi] "i" (((70) >> (31 - 24)) << 24) ); } while (0); __builtin_unreachable(); } while (0); } while (0)
                                                                      ;

        va += xen_phys_start - XEN_VIRT_START;
    }
    return (va & ma_va_bottom_mask) |
           ((va << pfn_pdx_hole_shift) & ma_top_mask);
}

static __inline__ void *__maddr_to_virt(unsigned long ma)
{
    do { if ( __builtin_expect(!!(!(pfn_to_pdx(ma >> 12) < (DIRECTMAP_SIZE >> 12))),0) ) do { do { ({ _Static_assert(!((80) >> ((31 - 24) + (31 - 24))), "!(" "(80) >> (BUG_LINE_LO_WIDTH + BUG_LINE_HI_WIDTH)" ")"); }); ({ _Static_assert(!((3) >= 4), "!(" "(3) >= BUGFRAME_NR" ")"); }); asm volatile ( ".Lbug%=: ud2\n" ".pushsection .bug_frames.%c[bf_type], \"a\", @progbits\n" ".p2align 2\n" ".Lfrm%=:\n" ".long (.Lbug%= - .Lfrm%=) + %c[bf_line_hi]\n" ".long (%c[bf_ptr] - .Lfrm%=) + %c[bf_line_lo]\n" ".if " "1" "\n" ".long 0, %c[bf_msg] - .Lfrm%=\n" ".endif\n" ".popsection\n" :: [bf_type] "i" (3), [bf_ptr] "i" ("/var/xen-dev/xen/xen/include/asm/x86_64/page.h"), [bf_msg] "i" ("pfn_to_pdx(ma >> PAGE_SHIFT) < (DIRECTMAP_SIZE >> PAGE_SHIFT)"), [bf_line_lo] "i" ((80 & ((1 << (31 - 24)) - 1)) << 24), [bf_line_hi] "i" (((80) >> (31 - 24)) << 24) ); } while (0); __builtin_unreachable(); } while (0); } while (0);
    return (void *)(DIRECTMAP_VIRT_START +
                    ((ma & ma_va_bottom_mask) |
                     ((ma & ma_top_mask) >> pfn_pdx_hole_shift)));
}


typedef u64 intpte_t;


typedef struct { intpte_t l1; } l1_pgentry_t;
typedef struct { intpte_t l2; } l2_pgentry_t;
typedef struct { intpte_t l3; } l3_pgentry_t;
typedef struct { intpte_t l4; } l4_pgentry_t;
typedef l4_pgentry_t root_pgentry_t;
# 134 "/var/xen-dev/xen/xen/include/asm/x86_64/page.h"
static __inline__ unsigned int get_pte_flags(intpte_t x)
{
    return ((x >> 40) & ~0xfff) | (x & 0xfff);
}

static __inline__ intpte_t put_pte_flags(unsigned int x)
{
    return (((intpte_t)x & ~0xfff) << 40) | (x & 0xfff);
}
# 24 "/var/xen-dev/xen/xen/include/asm/page.h" 2
# 131 "/var/xen-dev/xen/xen/include/asm/page.h"
static __inline__ l1_pgentry_t l1e_from_paddr(paddr_t pa, unsigned int flags)
{
    do { if ( __builtin_expect(!!(!((pa & ~((((1UL) << 52) - 1) & (~(((1L) << 12)-1)))) == 0)),0) ) do { do { ({ _Static_assert(!((133) >> ((31 - 24) + (31 - 24))), "!(" "(133) >> (BUG_LINE_LO_WIDTH + BUG_LINE_HI_WIDTH)" ")"); }); ({ _Static_assert(!((3) >= 4), "!(" "(3) >= BUGFRAME_NR" ")"); }); asm volatile ( ".Lbug%=: ud2\n" ".pushsection .bug_frames.%c[bf_type], \"a\", @progbits\n" ".p2align 2\n" ".Lfrm%=:\n" ".long (.Lbug%= - .Lfrm%=) + %c[bf_line_hi]\n" ".long (%c[bf_ptr] - .Lfrm%=) + %c[bf_line_lo]\n" ".if " "1" "\n" ".long 0, %c[bf_msg] - .Lfrm%=\n" ".endif\n" ".popsection\n" :: [bf_type] "i" (3), [bf_ptr] "i" ("/var/xen-dev/xen/xen/include/asm/page.h"), [bf_msg] "i" ("(pa & ~(PADDR_MASK & PAGE_MASK)) == 0"), [bf_line_lo] "i" ((133 & ((1 << (31 - 24)) - 1)) << 24), [bf_line_hi] "i" (((133) >> (31 - 24)) << 24) ); } while (0); __builtin_unreachable(); } while (0); } while (0);
    return (l1_pgentry_t) { pa | put_pte_flags(flags) };
}
static __inline__ l2_pgentry_t l2e_from_paddr(paddr_t pa, unsigned int flags)
{
    do { if ( __builtin_expect(!!(!((pa & ~((((1UL) << 52) - 1) & (~(((1L) << 12)-1)))) == 0)),0) ) do { do { ({ _Static_assert(!((138) >> ((31 - 24) + (31 - 24))), "!(" "(138) >> (BUG_LINE_LO_WIDTH + BUG_LINE_HI_WIDTH)" ")"); }); ({ _Static_assert(!((3) >= 4), "!(" "(3) >= BUGFRAME_NR" ")"); }); asm volatile ( ".Lbug%=: ud2\n" ".pushsection .bug_frames.%c[bf_type], \"a\", @progbits\n" ".p2align 2\n" ".Lfrm%=:\n" ".long (.Lbug%= - .Lfrm%=) + %c[bf_line_hi]\n" ".long (%c[bf_ptr] - .Lfrm%=) + %c[bf_line_lo]\n" ".if " "1" "\n" ".long 0, %c[bf_msg] - .Lfrm%=\n" ".endif\n" ".popsection\n" :: [bf_type] "i" (3), [bf_ptr] "i" ("/var/xen-dev/xen/xen/include/asm/page.h"), [bf_msg] "i" ("(pa & ~(PADDR_MASK & PAGE_MASK)) == 0"), [bf_line_lo] "i" ((138 & ((1 << (31 - 24)) - 1)) << 24), [bf_line_hi] "i" (((138) >> (31 - 24)) << 24) ); } while (0); __builtin_unreachable(); } while (0); } while (0);
    return (l2_pgentry_t) { pa | put_pte_flags(flags) };
}
static __inline__ l3_pgentry_t l3e_from_paddr(paddr_t pa, unsigned int flags)
{
    do { if ( __builtin_expect(!!(!((pa & ~((((1UL) << 52) - 1) & (~(((1L) << 12)-1)))) == 0)),0) ) do { do { ({ _Static_assert(!((143) >> ((31 - 24) + (31 - 24))), "!(" "(143) >> (BUG_LINE_LO_WIDTH + BUG_LINE_HI_WIDTH)" ")"); }); ({ _Static_assert(!((3) >= 4), "!(" "(3) >= BUGFRAME_NR" ")"); }); asm volatile ( ".Lbug%=: ud2\n" ".pushsection .bug_frames.%c[bf_type], \"a\", @progbits\n" ".p2align 2\n" ".Lfrm%=:\n" ".long (.Lbug%= - .Lfrm%=) + %c[bf_line_hi]\n" ".long (%c[bf_ptr] - .Lfrm%=) + %c[bf_line_lo]\n" ".if " "1" "\n" ".long 0, %c[bf_msg] - .Lfrm%=\n" ".endif\n" ".popsection\n" :: [bf_type] "i" (3), [bf_ptr] "i" ("/var/xen-dev/xen/xen/include/asm/page.h"), [bf_msg] "i" ("(pa & ~(PADDR_MASK & PAGE_MASK)) == 0"), [bf_line_lo] "i" ((143 & ((1 << (31 - 24)) - 1)) << 24), [bf_line_hi] "i" (((143) >> (31 - 24)) << 24) ); } while (0); __builtin_unreachable(); } while (0); } while (0);
    return (l3_pgentry_t) { pa | put_pte_flags(flags) };
}
static __inline__ l4_pgentry_t l4e_from_paddr(paddr_t pa, unsigned int flags)
{
    do { if ( __builtin_expect(!!(!((pa & ~((((1UL) << 52) - 1) & (~(((1L) << 12)-1)))) == 0)),0) ) do { do { ({ _Static_assert(!((148) >> ((31 - 24) + (31 - 24))), "!(" "(148) >> (BUG_LINE_LO_WIDTH + BUG_LINE_HI_WIDTH)" ")"); }); ({ _Static_assert(!((3) >= 4), "!(" "(3) >= BUGFRAME_NR" ")"); }); asm volatile ( ".Lbug%=: ud2\n" ".pushsection .bug_frames.%c[bf_type], \"a\", @progbits\n" ".p2align 2\n" ".Lfrm%=:\n" ".long (.Lbug%= - .Lfrm%=) + %c[bf_line_hi]\n" ".long (%c[bf_ptr] - .Lfrm%=) + %c[bf_line_lo]\n" ".if " "1" "\n" ".long 0, %c[bf_msg] - .Lfrm%=\n" ".endif\n" ".popsection\n" :: [bf_type] "i" (3), [bf_ptr] "i" ("/var/xen-dev/xen/xen/include/asm/page.h"), [bf_msg] "i" ("(pa & ~(PADDR_MASK & PAGE_MASK)) == 0"), [bf_line_lo] "i" ((148 & ((1 << (31 - 24)) - 1)) << 24), [bf_line_hi] "i" (((148) >> (31 - 24)) << 24) ); } while (0); __builtin_unreachable(); } while (0); } while (0);
    return (l4_pgentry_t) { pa | put_pte_flags(flags) };
}
# 216 "/var/xen-dev/xen/xen/include/asm/page.h"
typedef struct { u64 pfn; } pagetable_t;
# 228 "/var/xen-dev/xen/xen/include/asm/page.h"
void clear_page_sse2(void *);
void copy_page_sse2(void *, const void *);
# 290 "/var/xen-dev/xen/xen/include/asm/page.h"
extern root_pgentry_t idle_pg_table[(1<<9)];
extern l2_pgentry_t *compat_idle_pg_table_l2;
extern unsigned int m2p_compat_vstart;
extern l2_pgentry_t l2_xenmap[(1<<9)],
    l2_bootmap[4*(1<<9)];
extern l3_pgentry_t l3_bootmap[(1<<9)];
extern l2_pgentry_t l2_identmap[4*(1<<9)];
extern l1_pgentry_t l1_fixmap[(1<<9)];
void paging_init(void);
void efi_update_l4_pgtable(unsigned int l4idx, l4_pgentry_t);
# 349 "/var/xen-dev/xen/xen/include/asm/page.h"
void *alloc_xen_pagetable(void);
void free_xen_pagetable(void *v);
l1_pgentry_t *virt_to_xen_l1e(unsigned long v);


static __inline__ unsigned int pte_flags_to_cacheattr(unsigned int flags)
{
    return ((flags >> 5) & 4) | ((flags >> 3) & 3);
}
static __inline__ unsigned int cacheattr_to_pte_flags(unsigned int cacheattr)
{
    return ((cacheattr & 4) << 5) | ((cacheattr & 3) << 3);
}


static __inline__ bool_t
perms_strictly_increased(uint32_t old_flags, uint32_t new_flags)


{
    uint32_t of = old_flags & ((0x001U)|(0x002U)|(0x004U)|(1U<<23));
    uint32_t nf = new_flags & ((0x001U)|(0x002U)|(0x004U)|(1U<<23));


    of ^= (1U<<23);
    nf ^= (1U<<23);


    return ((of | (of ^ nf)) == nf);
}

static __inline__ void invalidate_icache(void)
{




}
# 13 "/var/xen-dev/xen/xen/include/asm/current.h" 2
# 31 "/var/xen-dev/xen/xen/include/asm/current.h"
static __inline__ unsigned int get_stack_page(unsigned long sp)
{
    return (sp & (STACK_SIZE-1)) >> 12;
}

struct vcpu;

struct cpu_info {
    struct cpu_user_regs guest_cpu_user_regs;
    unsigned int processor_id;
    unsigned int verw_sel;
    struct vcpu *current_vcpu;
    unsigned long per_cpu_offset;
    unsigned long cr4;
# 53 "/var/xen-dev/xen/xen/include/asm/current.h"
    unsigned long xen_cr3;
    unsigned long pv_cr3;


    unsigned int shadow_spec_ctrl;
    uint8_t xen_spec_ctrl;
    uint8_t spec_ctrl_flags;







    _Bool root_pgt_changed;






    _Bool use_pv_cr3;

    unsigned long __pad;

};

static __inline__ struct cpu_info *get_cpu_info_from_stack(unsigned long sp)
{
    return (struct cpu_info *)((sp | (STACK_SIZE - 1)) + 1) - 1;
}

static __inline__ struct cpu_info *get_cpu_info(void)
{





    register unsigned long sp asm("rsp");


    return get_cpu_info_from_stack(sp);
}
# 123 "/var/xen-dev/xen/xen/include/asm/current.h"
unsigned long get_stack_trace_bottom(unsigned long sp);
unsigned long get_stack_dump_bottom (unsigned long sp);
# 153 "/var/xen-dev/xen/xen/include/asm/current.h"
extern __typeof__(struct vcpu *) per_cpu__curr_vcpu;
# 11 "/var/xen-dev/xen/xen/include/asm/smp.h" 2




# 1 "/var/xen-dev/xen/xen/include/asm/mpspec.h" 1




# 1 "/var/xen-dev/xen/xen/include/asm/mpspec_def.h" 1
# 19 "/var/xen-dev/xen/xen/include/asm/mpspec_def.h"
struct intel_mp_floating
{
 char mpf_signature[4];
 unsigned int mpf_physptr;
 unsigned char mpf_length;
 unsigned char mpf_specification;
 unsigned char mpf_checksum;
 unsigned char mpf_feature1;
 unsigned char mpf_feature2;
 unsigned char mpf_feature3;
 unsigned char mpf_feature4;
 unsigned char mpf_feature5;
};

struct mp_config_table
{
 char mpc_signature[4];

 unsigned short mpc_length;
 char mpc_spec;
 char mpc_checksum;
 char mpc_oem[8];
 char mpc_productid[12];
 unsigned int mpc_oemptr;
 unsigned short mpc_oemsize;
 unsigned short mpc_oemcount;
 unsigned int mpc_lapic;
 unsigned int reserved;
};
# 58 "/var/xen-dev/xen/xen/include/asm/mpspec_def.h"
struct mpc_config_processor
{
 unsigned char mpc_type;
 unsigned char mpc_apicid;
 unsigned char mpc_apicver;
 unsigned char mpc_cpuflag;


 unsigned int mpc_cpufeature;



 unsigned int mpc_featureflag;
 unsigned int mpc_reserved[2];
};

struct mpc_config_bus
{
 unsigned char mpc_type;
 unsigned char mpc_busid;
 unsigned char mpc_bustype[6];
};
# 102 "/var/xen-dev/xen/xen/include/asm/mpspec_def.h"
struct mpc_config_ioapic
{
 unsigned char mpc_type;
 unsigned char mpc_apicid;
 unsigned char mpc_apicver;
 unsigned char mpc_flags;

 unsigned int mpc_apicaddr;
};

struct mpc_config_intsrc
{
 unsigned char mpc_type;
 unsigned char mpc_irqtype;
 unsigned short mpc_irqflag;
 unsigned char mpc_srcbus;
 unsigned char mpc_srcbusirq;
 unsigned char mpc_dstapic;
 unsigned char mpc_dstirq;
};

enum mp_irq_source_types {
 mp_INT = 0,
 mp_NMI = 1,
 mp_SMI = 2,
 mp_ExtINT = 3
};






struct mpc_config_lintsrc
{
 unsigned char mpc_type;
 unsigned char mpc_irqtype;
 unsigned short mpc_irqflag;
 unsigned char mpc_srcbusid;
 unsigned char mpc_srcbusirq;
 unsigned char mpc_destapic;

 unsigned char mpc_destapiclint;
};

struct mp_config_oemtable
{
 char oem_signature[4];

 unsigned short oem_length;
 char oem_rev;
 char oem_checksum;
 char mpc_oem[8];
};

struct mpc_config_translation
{
        unsigned char mpc_type;
        unsigned char trans_len;
        unsigned char trans_type;
        unsigned char trans_quad;
        unsigned char trans_global;
        unsigned char trans_local;
        unsigned short trans_reserved;
};
# 180 "/var/xen-dev/xen/xen/include/asm/mpspec_def.h"
enum mp_bustype {
 MP_BUS_ISA = 1,
 MP_BUS_EISA,
 MP_BUS_PCI,
 MP_BUS_MCA,
 MP_BUS_NEC98
};
# 6 "/var/xen-dev/xen/xen/include/asm/mpspec.h" 2
# 1 "/var/xen-dev/xen/xen/include/asm-x86/mach-default/mach_mpspec.h" 1
# 7 "/var/xen-dev/xen/xen/include/asm/mpspec.h" 2

extern unsigned char mp_bus_id_to_type[260];

extern _Bool def_to_bigsmp;
extern unsigned int boot_cpu_physical_apicid;
extern _Bool smp_found_config;
extern void find_smp_config (void);
extern void get_smp_config (void);
extern unsigned char apic_version [((256) > (4 * NR_CPUS) ? (256) : (4 * NR_CPUS))];
extern int mp_irq_entries;
extern struct mpc_config_intsrc mp_irqs [256];
extern int mpc_default_type;
extern unsigned long mp_lapic_addr;
extern _Bool pic_mode;
# 34 "/var/xen-dev/xen/xen/include/asm/mpspec.h"
struct physid_mask
{
 unsigned long mask[(((((256) > (4 * NR_CPUS) ? (256) : (4 * NR_CPUS)))+BITS_PER_LONG-1)/BITS_PER_LONG)];
};

typedef struct physid_mask physid_mask_t;
# 70 "/var/xen-dev/xen/xen/include/asm/mpspec.h"
extern physid_mask_t phys_cpu_present_map;
# 16 "/var/xen-dev/xen/xen/include/asm/smp.h" 2
# 25 "/var/xen-dev/xen/xen/include/asm/smp.h"
extern __typeof__(cpumask_var_t) per_cpu__cpu_sibling_mask;
extern __typeof__(cpumask_var_t) per_cpu__cpu_core_mask;
extern __typeof__(cpumask_var_t) per_cpu__scratch_cpumask;





extern _Bool park_offline_cpus;

void smp_send_nmi_allbutself(void);

void send_IPI_mask(const cpumask_t *, int vector);
void send_IPI_self(int vector);

extern void (*mtrr_hook) (void);

extern void zap_low_mappings(void);

extern u32 x86_cpu_to_apicid[];




extern void cpu_exit_clear(unsigned int cpu);
extern void cpu_uninit(unsigned int cpu);
int cpu_add(uint32_t apic_id, uint32_t acpi_id, uint32_t pxm);
# 60 "/var/xen-dev/xen/xen/include/asm/smp.h"
void __stop_this_cpu(void);

long cpu_up_helper(void *data);
long cpu_down_helper(void *data);

long core_parking_helper(void *data);
_Bool core_parking_remove(unsigned int cpu);
uint32_t get_cur_idle_nums(void);





extern unsigned int nr_sockets;

void set_nr_sockets(void);


extern cpumask_t **socket_cpumask;
# 5 "/var/xen-dev/xen/xen/include/xen/smp.h" 2




extern void smp_send_stop(void);

extern void smp_send_event_check_mask(const cpumask_t *mask);



extern void smp_send_state_dump(unsigned int cpu);




extern void smp_prepare_cpus(void);




extern void smp_cpus_done(void);




extern void smp_call_function(
    void (*func) (void *info),
    void *info,
    int wait);




extern void on_selected_cpus(
    const cpumask_t *selected,
    void (*func) (void *info),
    void *info,
    int wait);





void smp_prepare_boot_cpu(void);




static __inline__ void on_each_cpu(
    void (*func) (void *info),
    void *info,
    int wait)
{
    on_selected_cpus(&cpu_online_map, func, info, wait);
}




void smp_call_function_interrupt(void);

void smp_send_call_function_mask(const cpumask_t *mask);



int alloc_cpu_id(void);

extern void *stack_base[NR_CPUS];

void initialize_cpu_data(unsigned int cpu);
# 11 "/var/xen-dev/xen/xen/include/asm/processor.h" 2




# 1 "/var/xen-dev/xen/xen/include/asm/desc.h" 1
# 109 "/var/xen-dev/xen/xen/include/asm/desc.h"
typedef union {
    uint64_t raw;
    struct {
        uint32_t a, b;
    };
} seg_desc_t;

typedef union {
    struct {
        uint64_t a, b;
    };
    struct {
        uint16_t addr0;
        uint16_t cs;
        uint8_t ist;
        uint8_t type:4, s:1, dpl:2, p:1;
        uint16_t addr1;
        uint32_t addr2;

    };
} idt_entry_t;
# 139 "/var/xen-dev/xen/xen/include/asm/desc.h"
static __inline__ void _write_gate_lower(volatile idt_entry_t *gate,
                                     const idt_entry_t *new)
{
    do { if ( __builtin_expect(!!(!(gate->b == new->b)),0) ) do { do { ({ _Static_assert(!((142) >> ((31 - 24) + (31 - 24))), "!(" "(142) >> (BUG_LINE_LO_WIDTH + BUG_LINE_HI_WIDTH)" ")"); }); ({ _Static_assert(!((3) >= 4), "!(" "(3) >= BUGFRAME_NR" ")"); }); asm volatile ( ".Lbug%=: ud2\n" ".pushsection .bug_frames.%c[bf_type], \"a\", @progbits\n" ".p2align 2\n" ".Lfrm%=:\n" ".long (.Lbug%= - .Lfrm%=) + %c[bf_line_hi]\n" ".long (%c[bf_ptr] - .Lfrm%=) + %c[bf_line_lo]\n" ".if " "1" "\n" ".long 0, %c[bf_msg] - .Lfrm%=\n" ".endif\n" ".popsection\n" :: [bf_type] "i" (3), [bf_ptr] "i" ("/var/xen-dev/xen/xen/include/asm/desc.h"), [bf_msg] "i" ("gate->b == new->b"), [bf_line_lo] "i" ((142 & ((1 << (31 - 24)) - 1)) << 24), [bf_line_hi] "i" (((142) >> (31 - 24)) << 24) ); } while (0); __builtin_unreachable(); } while (0); } while (0);
    gate->a = new->a;
}
# 162 "/var/xen-dev/xen/xen/include/asm/desc.h"
static __inline__ void _set_gate_lower(idt_entry_t *gate, unsigned long type,
                                   unsigned long dpl, void *addr)
{
    idt_entry_t idte;
    idte.b = gate->b;
    idte.a =
        (((unsigned long)(addr) & 0xFFFF0000UL) << 32) |
        ((unsigned long)(dpl) << 45) |
        ((unsigned long)(type) << 40) |
        ((unsigned long)(addr) & 0xFFFFUL) |
        ((unsigned long)__HYPERVISOR_CS << 16) |
        (1UL << 47);
    _write_gate_lower(gate, &idte);
}



static __inline__ void _update_gate_addr_lower(idt_entry_t *gate, void *addr)
{
    idt_entry_t idte;
    idte.a = gate->a;

    idte.b = ((unsigned long)(addr) >> 32);
    idte.a &= 0x0000FFFFFFFF0000ULL;
    idte.a |= (((unsigned long)(addr) & 0xFFFF0000UL) << 32) |
        ((unsigned long)(addr) & 0xFFFFUL);

    _write_gate_lower(gate, &idte);
}
# 206 "/var/xen-dev/xen/xen/include/asm/desc.h"
struct __attribute__((__packed__)) desc_ptr {
 unsigned short limit;
 unsigned long base;
};

extern seg_desc_t boot_gdt[];
extern __typeof__(seg_desc_t *) per_cpu__gdt;
extern __typeof__(l1_pgentry_t) per_cpu__gdt_l1e;
extern seg_desc_t boot_compat_gdt[];
extern __typeof__(seg_desc_t *) per_cpu__compat_gdt;
extern __typeof__(l1_pgentry_t) per_cpu__compat_gdt_l1e;
extern __typeof__(_Bool) per_cpu__full_gdt_loaded;

static __inline__ void lgdt(const struct desc_ptr *gdtr)
{
    __asm__ __volatile__ ( "lgdt %0" :: "m" (*gdtr) : "memory" );
}

static __inline__ void lidt(const struct desc_ptr *idtr)
{
    __asm__ __volatile__ ( "lidt %0" :: "m" (*idtr) : "memory" );
}

static __inline__ void lldt(unsigned int sel)
{
    __asm__ __volatile__ ( "lldt %w0" :: "rm" (sel) : "memory" );
}

static __inline__ void ltr(unsigned int sel)
{
    __asm__ __volatile__ ( "ltr %w0" :: "rm" (sel) : "memory" );
}
# 16 "/var/xen-dev/xen/xen/include/asm/processor.h" 2



# 1 "/var/xen-dev/xen/xen/include/asm/x86-vendors.h" 1
# 20 "/var/xen-dev/xen/xen/include/asm/processor.h" 2
# 107 "/var/xen-dev/xen/xen/include/asm/processor.h"
struct domain;
struct vcpu;

struct x86_cpu_id {
    uint16_t vendor;
    uint16_t family;
    uint16_t model;
    uint16_t feature;
    const void *driver_data;
};

struct cpuinfo_x86 {
    __u8 x86;
    __u8 x86_vendor;
    __u8 x86_model;
    __u8 x86_mask;
    int cpuid_level;
    __u32 extended_cpuid_level;
    unsigned int x86_capability[(11 + 1 + 1)];
    char x86_vendor_id[16];
    char x86_model_id[64];
    int x86_cache_size;
    int x86_cache_alignment;
    __u32 x86_max_cores;
    __u32 booted_cores;
    __u32 x86_num_siblings;
    __u32 apicid;
    __u32 phys_proc_id;
    __u32 cpu_core_id;
    __u32 compute_unit_id;
    unsigned short x86_clflush_size;
} __attribute__((__aligned__((1 << (CONFIG_X86_L1_CACHE_SHIFT)))));





extern struct cpuinfo_x86 boot_cpu_data;

extern struct cpuinfo_x86 cpu_data[];


extern _Bool probe_cpuid_faulting(void);
extern void ctxt_switch_levelling(const struct vcpu *next);
extern void (*ctxt_switch_masking)(const struct vcpu *next);

extern bool_t opt_cpu_info;
extern u32 trampoline_efer;
extern u64 trampoline_misc_enable_off;


extern unsigned int paddr_bits;

extern unsigned int hap_paddr_bits;

extern unsigned int vaddr_bits;

extern const struct x86_cpu_id *x86_match_cpu(const struct x86_cpu_id table[]);

extern void identify_cpu(struct cpuinfo_x86 *);
extern void setup_clear_cpu_cap(unsigned int);
extern void setup_force_cpu_cap(unsigned int);
extern void print_cpu_info(unsigned int cpu);
extern unsigned int init_intel_cacheinfo(struct cpuinfo_x86 *c);




unsigned int apicid_to_socket(unsigned int);
# 191 "/var/xen-dev/xen/xen/include/asm/processor.h"
static __inline__ void cpuid_count(
    unsigned int op,
    unsigned int count,
    unsigned int *eax,
    unsigned int *ebx,
    unsigned int *ecx,
    unsigned int *edx)
{
    asm volatile ( "cpuid"
          : "=a" (*eax), "=b" (*ebx), "=c" (*ecx), "=d" (*edx)
          : "0" (op), "c" (count) );
}




static __inline__ __attribute__ ((__always_inline__)) unsigned int cpuid_eax(unsigned int op)
{
    unsigned int eax;

    asm volatile ( "cpuid"
          : "=a" (eax)
          : "0" (op)
          : "bx", "cx", "dx" );
    return eax;
}

static __inline__ __attribute__ ((__always_inline__)) unsigned int cpuid_ebx(unsigned int op)
{
    unsigned int eax, ebx;

    asm volatile ( "cpuid"
          : "=a" (eax), "=b" (ebx)
          : "0" (op)
          : "cx", "dx" );
    return ebx;
}

static __inline__ __attribute__ ((__always_inline__)) unsigned int cpuid_ecx(unsigned int op)
{
    unsigned int eax, ecx;

    asm volatile ( "cpuid"
          : "=a" (eax), "=c" (ecx)
          : "0" (op)
          : "bx", "dx" );
    return ecx;
}

static __inline__ __attribute__ ((__always_inline__)) unsigned int cpuid_edx(unsigned int op)
{
    unsigned int eax, edx;

    asm volatile ( "cpuid"
          : "=a" (eax), "=d" (edx)
          : "0" (op)
          : "bx", "cx" );
    return edx;
}

static __inline__ __attribute__ ((__always_inline__)) unsigned int cpuid_count_ebx(
    unsigned int leaf, unsigned int subleaf)
{
    unsigned int ebx, tmp;

    cpuid_count(leaf, subleaf, &tmp, &ebx, &tmp, &tmp);

    return ebx;
}

static __inline__ __attribute__ ((__always_inline__)) unsigned int cpuid_count_edx(
    unsigned int leaf, unsigned int subleaf)
{
    unsigned int edx, tmp;

    cpuid_count(leaf, subleaf, &tmp, &tmp, &tmp, &edx);

    return edx;
}

static __inline__ unsigned long read_cr0(void)
{
    unsigned long cr0;
    asm volatile ( "mov %%cr0,%0\n\t" : "=r" (cr0) );
    return cr0;
}

static __inline__ void write_cr0(unsigned long val)
{
    asm volatile ( "mov %0,%%cr0" : : "r" ((unsigned long)val) );
}

static __inline__ unsigned long read_cr2(void)
{
    unsigned long cr2;
    asm volatile ( "mov %%cr2,%0\n\t" : "=r" (cr2) );
    return cr2;
}

static __inline__ void write_cr3(unsigned long val)
{
    asm volatile ( "mov %0, %%cr3" : : "r" (val) : "memory" );
}

static __inline__ unsigned long cr3_pa(unsigned long cr3)
{
    return cr3 & ((~(((1L) << 12)-1)) & (((1UL) << 52) - 1));
}

static __inline__ unsigned int cr3_pcid(unsigned long cr3)
{
    return IS_ENABLED(CONFIG_PV) ? cr3 & (0x0fffULL) : 0;
}

static __inline__ unsigned long read_cr4(void)
{
    return get_cpu_info()->cr4;
}

static __inline__ void write_cr4(unsigned long val)
{
    struct cpu_info *info = get_cpu_info();





    do { if ( __builtin_expect(!!(!(!(val & 0x00020000))),0) ) do { do { ({ _Static_assert(!((318) >> ((31 - 24) + (31 - 24))), "!(" "(318) >> (BUG_LINE_LO_WIDTH + BUG_LINE_HI_WIDTH)" ")"); }); ({ _Static_assert(!((3) >= 4), "!(" "(3) >= BUGFRAME_NR" ")"); }); asm volatile ( ".Lbug%=: ud2\n" ".pushsection .bug_frames.%c[bf_type], \"a\", @progbits\n" ".p2align 2\n" ".Lfrm%=:\n" ".long (.Lbug%= - .Lfrm%=) + %c[bf_line_hi]\n" ".long (%c[bf_ptr] - .Lfrm%=) + %c[bf_line_lo]\n" ".if " "1" "\n" ".long 0, %c[bf_msg] - .Lfrm%=\n" ".endif\n" ".popsection\n" :: [bf_type] "i" (3), [bf_ptr] "i" ("/var/xen-dev/xen/xen/include/asm/processor.h"), [bf_msg] "i" ("!(val & X86_CR4_PCIDE)"), [bf_line_lo] "i" ((318 & ((1 << (31 - 24)) - 1)) << 24), [bf_line_hi] "i" (((318) >> (31 - 24)) << 24) ); } while (0); __builtin_unreachable(); } while (0); } while (0);
# 334 "/var/xen-dev/xen/xen/include/asm/processor.h"
    info->cr4 = val & (info->cr4 | ~0x00010000);

    asm volatile ( "mov %[val], %%cr4"
                   : "+m" (info->cr4)
                   : [val] "r" (val) );

    info->cr4 = val;
}


static __inline__ void clts(void)
{
    asm volatile ( "clts" );
}

static __inline__ void stts(void)
{
    write_cr0(0x00000008|read_cr0());
}







extern unsigned long mmu_cr4_features;

static __inline__ __attribute__ ((__always_inline__)) void set_in_cr4 (unsigned long mask)
{
    mmu_cr4_features |= mask;
    write_cr4(read_cr4() | mask);
}

static __inline__ unsigned int read_pkru(void)
{
    unsigned int pkru;
    unsigned long cr4 = read_cr4();






    write_cr4(cr4 | 0x00400000);
    asm volatile (".byte 0x0f,0x01,0xee"
        : "=a" (pkru) : "c" (0) : "dx");
    write_cr4(cr4);

    return pkru;
}
# 396 "/var/xen-dev/xen/xen/include/asm/processor.h"
static __inline__ bool_t read_pkru_ad(uint32_t pkru, unsigned int pkey)
{
    do { if ( __builtin_expect(!!(!(pkey < 16)),0) ) do { do { ({ _Static_assert(!((398) >> ((31 - 24) + (31 - 24))), "!(" "(398) >> (BUG_LINE_LO_WIDTH + BUG_LINE_HI_WIDTH)" ")"); }); ({ _Static_assert(!((3) >= 4), "!(" "(3) >= BUGFRAME_NR" ")"); }); asm volatile ( ".Lbug%=: ud2\n" ".pushsection .bug_frames.%c[bf_type], \"a\", @progbits\n" ".p2align 2\n" ".Lfrm%=:\n" ".long (.Lbug%= - .Lfrm%=) + %c[bf_line_hi]\n" ".long (%c[bf_ptr] - .Lfrm%=) + %c[bf_line_lo]\n" ".if " "1" "\n" ".long 0, %c[bf_msg] - .Lfrm%=\n" ".endif\n" ".popsection\n" :: [bf_type] "i" (3), [bf_ptr] "i" ("/var/xen-dev/xen/xen/include/asm/processor.h"), [bf_msg] "i" ("pkey < 16"), [bf_line_lo] "i" ((398 & ((1 << (31 - 24)) - 1)) << 24), [bf_line_hi] "i" (((398) >> (31 - 24)) << 24) ); } while (0); __builtin_unreachable(); } while (0); } while (0);
    return (pkru >> (pkey * (2) + (0))) & 1;
}

static __inline__ bool_t read_pkru_wd(uint32_t pkru, unsigned int pkey)
{
    do { if ( __builtin_expect(!!(!(pkey < 16)),0) ) do { do { ({ _Static_assert(!((404) >> ((31 - 24) + (31 - 24))), "!(" "(404) >> (BUG_LINE_LO_WIDTH + BUG_LINE_HI_WIDTH)" ")"); }); ({ _Static_assert(!((3) >= 4), "!(" "(3) >= BUGFRAME_NR" ")"); }); asm volatile ( ".Lbug%=: ud2\n" ".pushsection .bug_frames.%c[bf_type], \"a\", @progbits\n" ".p2align 2\n" ".Lfrm%=:\n" ".long (.Lbug%= - .Lfrm%=) + %c[bf_line_hi]\n" ".long (%c[bf_ptr] - .Lfrm%=) + %c[bf_line_lo]\n" ".if " "1" "\n" ".long 0, %c[bf_msg] - .Lfrm%=\n" ".endif\n" ".popsection\n" :: [bf_type] "i" (3), [bf_ptr] "i" ("/var/xen-dev/xen/xen/include/asm/processor.h"), [bf_msg] "i" ("pkey < 16"), [bf_line_lo] "i" ((404 & ((1 << (31 - 24)) - 1)) << 24), [bf_line_hi] "i" (((404) >> (31 - 24)) << 24) ); } while (0); __builtin_unreachable(); } while (0); } while (0);
    return (pkru >> (pkey * (2) + (1))) & 1;
}

static __inline__ __attribute__ ((__always_inline__)) void __monitor(const void *eax, unsigned long ecx,
                                    unsigned long edx)
{

    asm volatile (
        ".byte 0x0f,0x01,0xc8;"
        : : "a" (eax), "c" (ecx), "d"(edx) );
}

static __inline__ __attribute__ ((__always_inline__)) void __mwait(unsigned long eax, unsigned long ecx)
{

    asm volatile (
        ".byte 0x0f,0x01,0xc9;"
        : : "a" (eax), "c" (ecx) );
}




struct __attribute__((__packed__)) tss64 {
    uint32_t :32;
    uint64_t rsp0, rsp1, rsp2;
    uint64_t :64;




    uint64_t ist[7];
    uint64_t :64;
    uint16_t :16, bitmap;
};
struct tss_page {
    struct tss64 __attribute__((__aligned__(((1L) << 12)))) tss;
};
extern __typeof__(struct tss_page) per_cpu__tss_page;
# 453 "/var/xen-dev/xen/xen/include/asm/processor.h"
static __inline__ void set_ist(idt_entry_t *idt, unsigned int ist)
{

    do { if ( __builtin_expect(!!(!(ist <= 4UL)),0) ) do { do { ({ _Static_assert(!((456) >> ((31 - 24) + (31 - 24))), "!(" "(456) >> (BUG_LINE_LO_WIDTH + BUG_LINE_HI_WIDTH)" ")"); }); ({ _Static_assert(!((3) >= 4), "!(" "(3) >= BUGFRAME_NR" ")"); }); asm volatile ( ".Lbug%=: ud2\n" ".pushsection .bug_frames.%c[bf_type], \"a\", @progbits\n" ".p2align 2\n" ".Lfrm%=:\n" ".long (.Lbug%= - .Lfrm%=) + %c[bf_line_hi]\n" ".long (%c[bf_ptr] - .Lfrm%=) + %c[bf_line_lo]\n" ".if " "1" "\n" ".long 0, %c[bf_msg] - .Lfrm%=\n" ".endif\n" ".popsection\n" :: [bf_type] "i" (3), [bf_ptr] "i" ("/var/xen-dev/xen/xen/include/asm/processor.h"), [bf_msg] "i" ("ist <= IST_MAX"), [bf_line_lo] "i" ((456 & ((1 << (31 - 24)) - 1)) << 24), [bf_line_hi] "i" (((456) >> (31 - 24)) << 24) ); } while (0); __builtin_unreachable(); } while (0); } while (0);


    (*({ (void)(typeof(idt->ist))0; (volatile typeof(idt->ist) *)&(idt->ist); })) = ist;
}

static __inline__ void enable_each_ist(idt_entry_t *idt)
{
    set_ist(&idt[8], 1UL);
    set_ist(&idt[2], 2UL);
    set_ist(&idt[18], 3UL);
    set_ist(&idt[1], 4UL);
}

static __inline__ void disable_each_ist(idt_entry_t *idt)
{
    set_ist(&idt[8], 0UL);
    set_ist(&idt[2], 0UL);
    set_ist(&idt[18], 0UL);
    set_ist(&idt[1], 0UL);
}


extern idt_entry_t idt_table[];
extern idt_entry_t *idt_tables[];

extern __typeof__(root_pgentry_t *) per_cpu__root_pgt;

extern void write_ptbase(struct vcpu *v);


static __inline__ __attribute__ ((__always_inline__)) void rep_nop(void)
{
    asm volatile ( "rep;nop" : : : "memory" );
}



void show_code(const struct cpu_user_regs *regs);
void show_stack(const struct cpu_user_regs *regs);
void show_stack_overflow(unsigned int cpu, const struct cpu_user_regs *regs);
void show_registers(const struct cpu_user_regs *regs);
void show_execution_state(const struct cpu_user_regs *regs);

void show_page_walk(unsigned long addr);
void __attribute__((__noreturn__)) fatal_trap(const struct cpu_user_regs *regs, bool_t show_remote);

extern void mtrr_ap_init(void);
extern void mtrr_bp_init(void);

void mcheck_init(struct cpuinfo_x86 *c, bool_t bsp);


extern void (* const exception_table[32])(struct cpu_user_regs *regs);
# 518 "/var/xen-dev/xen/xen/include/asm/processor.h"
void divide_error(void); void do_divide_error(struct cpu_user_regs *regs);
void debug(void); void do_debug(struct cpu_user_regs *regs);
void nmi(void); void do_nmi(const struct cpu_user_regs *regs);
void int3(void); void do_int3(struct cpu_user_regs *regs);
void overflow(void); void do_overflow(struct cpu_user_regs *regs);
void bounds(void); void do_bounds(struct cpu_user_regs *regs);
void invalid_op(void); void do_invalid_op(struct cpu_user_regs *regs);
void device_not_available(void); void do_device_not_available(struct cpu_user_regs *regs);
void double_fault(void); void do_double_fault(struct cpu_user_regs *regs);
void invalid_TSS(void); void do_invalid_TSS(struct cpu_user_regs *regs);
void segment_not_present(void); void do_segment_not_present(struct cpu_user_regs *regs);
void stack_segment(void); void do_stack_segment(struct cpu_user_regs *regs);
void general_protection(void); void do_general_protection(struct cpu_user_regs *regs);
void page_fault(void); void do_page_fault(struct cpu_user_regs *regs);
void early_page_fault(void); void do_early_page_fault(struct cpu_user_regs *regs);
void coprocessor_error(void); void do_coprocessor_error(struct cpu_user_regs *regs);
void simd_coprocessor_error(void); void do_simd_coprocessor_error(struct cpu_user_regs *regs);
void machine_check(void); void do_machine_check(const struct cpu_user_regs *regs);
void alignment_check(void); void do_alignment_check(struct cpu_user_regs *regs);

void entry_int82(void); void do_entry_int82(struct cpu_user_regs *regs);




void trap_nop(void);

static __inline__ void enable_nmis(void)
{
    unsigned long tmp;

    asm volatile ( "mov %%rsp, %[tmp]     \n\t"
                   "push %[ss]            \n\t"
                   "push %[tmp]           \n\t"
                   "pushf                 \n\t"
                   "push %[cs]            \n\t"
                   "lea 1f(%%rip), %[tmp] \n\t"
                   "push %[tmp]           \n\t"
                   "iretq; 1:             \n\t"
                   : [tmp] "=&r" (tmp)
                   : [ss] "i" (__HYPERVISOR_DS),
                     [cs] "i" (__HYPERVISOR_CS) );
}

void sysenter_entry(void);
void sysenter_eflags_saved(void);
void int80_direct_trap(void);



struct stubs {
    union {
        void(*func)(void);
        unsigned long addr;
    };
    unsigned long mfn;
};

extern __typeof__(struct stubs) per_cpu__stubs;
unsigned long alloc_stub_page(unsigned int cpu, unsigned long *mfn);

void cpuid_hypervisor_leaves(const struct vcpu *v, uint32_t leaf,
                             uint32_t subleaf, struct cpuid_leaf *res);
int guest_rdmsr_xen(const struct vcpu *v, uint32_t idx, uint64_t *val);
int guest_wrmsr_xen(struct vcpu *v, uint32_t idx, uint64_t val);

void microcode_set_module(unsigned int);
int microcode_update(__guest_handle_const_void, unsigned long len);
int early_microcode_update_cpu(void);
int early_microcode_init(void);
int microcode_update_one(_Bool start_update);
int microcode_init_intel(void);
int microcode_init_amd(void);

static __inline__ uint8_t get_cpu_family(uint32_t raw, uint8_t *model,
                                     uint8_t *stepping)
{
    uint8_t fam = (raw >> 8) & 0xf;

    if ( fam == 0xf )
        fam += (raw >> 20) & 0xff;

    if ( model )
    {
        uint8_t mod = (raw >> 4) & 0xf;

        if ( fam >= 0x6 )
            mod |= (raw >> 12) & 0xf0;

        *model = mod;
    }
    if ( stepping )
        *stepping = raw & 0xf;
    return fam;
}

extern int8_t opt_tsx, cpu_has_tsx_ctrl;
void tsx_init(void);
# 15 "/var/xen-dev/xen/xen/include/asm/msr.h" 2
# 33 "/var/xen-dev/xen/xen/include/asm/msr.h"
static __inline__ void wrmsrl(unsigned int msr, __u64 val)
{
        __u32 lo, hi;
        lo = (__u32)val;
        hi = (__u32)(val >> 32);
        __asm__ __volatile__("wrmsr" : : "c" (msr), "a" (lo), "d" (hi));
}
# 58 "/var/xen-dev/xen/xen/include/asm/msr.h"
static __inline__ int wrmsr_safe(unsigned int msr, uint64_t val)
{
    int _rc;
    uint32_t lo, hi;
    lo = (uint32_t)val;
    hi = (uint32_t)(val >> 32);

    __asm__ __volatile__(
        "1: wrmsr\n2:\n"
        ".section .fixup,\"ax\"\n"
        "3: movl %5,%0\n; jmp 2b\n"
        ".previous\n"
        " .section .ex_table" "" ",\"a\"\n" " .balign 4\n" " .long " "1b" "-." ", " "3b" "-." "\n" " .previous\n"
        : "=&r" (_rc)
        : "c" (msr), "a" (lo), "d" (hi), "0" (0), "i" (-EFAULT));
    return _rc;
}

static __inline__ uint64_t msr_fold(const struct cpu_user_regs *regs)
{
    return (regs->rdx << 32) | regs->eax;
}

static __inline__ void msr_split(struct cpu_user_regs *regs, uint64_t val)
{
    regs->rdx = val >> 32;
    regs->rax = (uint32_t)val;
}

static __inline__ uint64_t rdtsc(void)
{
    uint32_t low, high;

    __asm__ __volatile__("rdtsc" : "=a" (low), "=d" (high));

    return ((uint64_t)high << 32) | low;
}

static __inline__ uint64_t rdtsc_ordered(void)
{
# 108 "/var/xen-dev/xen/xen/include/asm/msr.h"
 asm volatile (".LXEN%=_orig_s:\n\t" "lfence" "\n .LXEN%=_orig_e:\n\t" ".LXEN%=_diff = " "(" ".LXEN%=_repl_e""1" " - " ".LXEN%=_repl_s""1" ")" "-" "(.LXEN%=_orig_e - .LXEN%=_orig_s)" "\n\t" "mknops (""""(.LXEN%=_diff > 0) * .LXEN%=_diff)\n\t" ".LXEN%=_orig_p:\n\t" ".pushsection .altinstructions, \"a\", @progbits\n" " .long .LXEN%=_orig_s - .\n" " .long " ".LXEN%=_repl_s""1"" - .\n" " .word " "X86_FEATURE_MFENCE_RDTSC" "\n" " .byte " "(.LXEN%=_orig_e - .LXEN%=_orig_s)" "\n" " .byte " "(" ".LXEN%=_repl_e""1" " - " ".LXEN%=_repl_s""1" ")" "\n" " .byte " "(.LXEN%=_orig_p - .LXEN%=_orig_e)" "\n" " .byte 0\n" ".section .discard, \"a\", @progbits\n" ".byte " "(.LXEN%=_orig_p - .LXEN%=_orig_s)" "\n" " .byte 0xff + (" "(" ".LXEN%=_repl_e""1" " - " ".LXEN%=_repl_s""1" ")" ") - (" "(.LXEN%=_orig_p - .LXEN%=_orig_s)" ")\n" ".section .altinstr_replacement, \"ax\", @progbits\n" ".LXEN%=_repl_s""1"":\n\t" "mfence" "\n" ".LXEN%=_repl_e""1" ":\n\t" ".popsection\n" : : : "memory");
 return rdtsc();
}
# 133 "/var/xen-dev/xen/xen/include/asm/msr.h"
static __inline__ unsigned long __rdfsbase(void)
{
    unsigned long base;




    asm volatile ( ".byte 0xf3, 0x48, 0x0f, 0xae, 0xc0" : "=a" (base) );


    return base;
}

static __inline__ unsigned long __rdgsbase(void)
{
    unsigned long base;




    asm volatile ( ".byte 0xf3, 0x48, 0x0f, 0xae, 0xc8" : "=a" (base) );


    return base;
}

static __inline__ unsigned long rdfsbase(void)
{
    unsigned long base;

    if ( read_cr4() & 0x00010000 )
        return __rdfsbase();

    do { unsigned long a__,b__; __asm__ __volatile__("rdmsr" : "=a" (a__), "=d" (b__) : "c" (0xc0000100)); base = a__ | ((u64)b__<<32); } while(0);

    return base;
}

static __inline__ unsigned long rdgsbase(void)
{
    unsigned long base;

    if ( read_cr4() & 0x00010000 )
        return __rdgsbase();

    do { unsigned long a__,b__; __asm__ __volatile__("rdmsr" : "=a" (a__), "=d" (b__) : "c" (0xc0000101)); base = a__ | ((u64)b__<<32); } while(0);

    return base;
}

static __inline__ unsigned long rdgsshadow(void)
{
    unsigned long base;

    if ( read_cr4() & 0x00010000 )
    {
        asm volatile ( "swapgs" );
        base = __rdgsbase();
        asm volatile ( "swapgs" );
    }
    else
        do { unsigned long a__,b__; __asm__ __volatile__("rdmsr" : "=a" (a__), "=d" (b__) : "c" (0xc0000102)); base = a__ | ((u64)b__<<32); } while(0);

    return base;
}

static __inline__ void wrfsbase(unsigned long base)
{
    if ( read_cr4() & 0x00010000 )



        asm volatile ( ".byte 0xf3, 0x48, 0x0f, 0xae, 0xd0" :: "a" (base) );

    else
        wrmsrl(0xc0000100, base);
}

static __inline__ void wrgsbase(unsigned long base)
{
    if ( read_cr4() & 0x00010000 )



        asm volatile ( ".byte 0xf3, 0x48, 0x0f, 0xae, 0xd8" :: "a" (base) );

    else
        wrmsrl(0xc0000101, base);
}

static __inline__ void wrgsshadow(unsigned long base)
{
    if ( read_cr4() & 0x00010000 )
    {
        asm volatile ( "swapgs\n\t"





                       ".byte 0xf3, 0x48, 0x0f, 0xae, 0xd8\n\t"
                       "swapgs"
                       :: "a" (base) );

    }
    else
        wrmsrl(0xc0000102, base);
}

extern __typeof__(uint64_t) per_cpu__efer;
static __inline__ uint64_t read_efer(void)
{
    return (*({ unsigned long __ptr; __asm__ ("" : "=r"(__ptr) : "0"(&per_cpu__efer)); (typeof(&per_cpu__efer)) (__ptr + (get_cpu_info()->per_cpu_offset)); }));
}

static __inline__ void write_efer(uint64_t val)
{
    (*({ unsigned long __ptr; __asm__ ("" : "=r"(__ptr) : "0"(&per_cpu__efer)); (typeof(&per_cpu__efer)) (__ptr + (get_cpu_info()->per_cpu_offset)); })) = val;
    wrmsrl(0xc0000080, val);
}

extern unsigned int ler_msr;

extern __typeof__(uint32_t) per_cpu__tsc_aux;


static __inline__ void wrmsr_tsc_aux(uint32_t val)
{
    uint32_t *this_tsc_aux = &(*({ unsigned long __ptr; __asm__ ("" : "=r"(__ptr) : "0"(&per_cpu__tsc_aux)); (typeof(&per_cpu__tsc_aux)) (__ptr + (get_cpu_info()->per_cpu_offset)); }));

    if ( *this_tsc_aux != val )
    {
        __asm__ __volatile__("wrmsr" : : "c" (0xc0000103), "a" (val), "d" (0));
        *this_tsc_aux = val;
    }
}

extern struct msr_policy raw_msr_policy,
                            host_msr_policy,
                         hvm_max_msr_policy,
                          pv_max_msr_policy;


struct vcpu_msrs
{

    struct {
        uint32_t raw;
    } spec_ctrl;
# 290 "/var/xen-dev/xen/xen/include/asm/msr.h"
    union {
        uint32_t raw;
        struct {
            _Bool cpuid_faulting:1;
        };
    } misc_features_enables;


    struct {
        uint64_t raw;
    } xss;
# 309 "/var/xen-dev/xen/xen/include/asm/msr.h"
    uint32_t tsc_aux;
# 318 "/var/xen-dev/xen/xen/include/asm/msr.h"
    uint32_t dr_mask[4];
};

void init_guest_msr_policy(void);
int init_domain_msr_policy(struct domain *d);
int init_vcpu_msr_policy(struct vcpu *v);
# 334 "/var/xen-dev/xen/xen/include/asm/msr.h"
int guest_rdmsr(struct vcpu *v, uint32_t msr, uint64_t *val);
int guest_wrmsr(struct vcpu *v, uint32_t msr, uint64_t val);
# 6 "/var/xen-dev/xen/xen/include/asm/time.h" 2
# 21 "/var/xen-dev/xen/xen/include/asm/time.h"
typedef u64 cycles_t;

extern _Bool disable_tsc_sync;

static __inline__ cycles_t get_cycles(void)
{
    return rdtsc_ordered();
}

unsigned long
mktime (unsigned int year, unsigned int mon,
        unsigned int day, unsigned int hour,
        unsigned int min, unsigned int sec);

int time_suspend(void);
int time_resume(void);

void init_percpu_time(void);
void time_latch_stamps(void);

struct ioreq;
int hwdom_pit_access(struct ioreq *ioreq);

int cpu_frequency_change(u64 freq);

void pit_broadcast_enter(void);
void pit_broadcast_exit(void);
int pit_broadcast_is_available(void);

uint64_t acpi_pm_tick_to_ns(uint64_t ticks);
uint64_t ns_to_acpi_pm_tick(uint64_t ns);

uint64_t tsc_ticks2ns(uint64_t ticks);

uint64_t pv_soft_rdtsc(const struct vcpu *v, const struct cpu_user_regs *regs);
u64 gtime_to_gtsc(struct domain *d, u64 time);
u64 gtsc_to_gtime(struct domain *d, u64 tsc);

int tsc_set_info(struct domain *d, uint32_t tsc_mode, uint64_t elapsed_nsec,
                 uint32_t gtsc_khz, uint32_t incarnation);

void tsc_get_info(struct domain *d, uint32_t *tsc_mode, uint64_t *elapsed_nsec,
                  uint32_t *gtsc_khz, uint32_t *incarnation);


void force_update_vcpu_system_time(struct vcpu *v);

_Bool clocksource_is_tsc(void);
int host_tsc_is_safe(void);
u64 stime2tsc(s_time_t stime);

struct time_scale;
void set_time_scale(struct time_scale *ts, u64 ticks_per_sec);
u64 scale_delta(u64 delta, const struct time_scale *scale);
# 77 "/var/xen-dev/xen/xen/include/xen/time.h" 2
# 10 "/var/xen-dev/xen/xen/include/xen/hypercall.h" 2

# 1 "/var/xen-dev/xen/xen/include/public/domctl.h" 1
# 12 "/var/xen-dev/xen/xen/include/xen/hypercall.h" 2

# 1 "/var/xen-dev/xen/xen/include/public/platform.h" 1
# 39 "/var/xen-dev/xen/xen/include/public/platform.h"
struct xenpf_settime32 {

    uint32_t secs;
    uint32_t nsecs;
    uint64_t system_time;
};

struct xenpf_settime64 {

    uint64_t secs;
    uint32_t nsecs;
    uint32_t mbz;
    uint64_t system_time;
};







typedef struct xenpf_settime32 xenpf_settime_t;
typedef xenpf_settime_t * __guest_handle_xenpf_settime_t; typedef const xenpf_settime_t * __guest_handle_const_xenpf_settime_t;
# 71 "/var/xen-dev/xen/xen/include/public/platform.h"
struct xenpf_add_memtype {

    xen_pfn_t mfn;
    uint64_t nr_mfns;
    uint32_t type;

    uint32_t handle;
    uint32_t reg;
};
typedef struct xenpf_add_memtype xenpf_add_memtype_t;
typedef xenpf_add_memtype_t * __guest_handle_xenpf_add_memtype_t; typedef const xenpf_add_memtype_t * __guest_handle_const_xenpf_add_memtype_t;
# 91 "/var/xen-dev/xen/xen/include/public/platform.h"
struct xenpf_del_memtype {

    uint32_t handle;
    uint32_t reg;
};
typedef struct xenpf_del_memtype xenpf_del_memtype_t;
typedef xenpf_del_memtype_t * __guest_handle_xenpf_del_memtype_t; typedef const xenpf_del_memtype_t * __guest_handle_const_xenpf_del_memtype_t;



struct xenpf_read_memtype {

    uint32_t reg;

    xen_pfn_t mfn;
    uint64_t nr_mfns;
    uint32_t type;
};
typedef struct xenpf_read_memtype xenpf_read_memtype_t;
typedef xenpf_read_memtype_t * __guest_handle_xenpf_read_memtype_t; typedef const xenpf_read_memtype_t * __guest_handle_const_xenpf_read_memtype_t;


struct xenpf_microcode_update {

    __guest_handle_const_void data;
    uint32_t length;
};
typedef struct xenpf_microcode_update xenpf_microcode_update_t;
typedef xenpf_microcode_update_t * __guest_handle_xenpf_microcode_update_t; typedef const xenpf_microcode_update_t * __guest_handle_const_xenpf_microcode_update_t;





struct xenpf_platform_quirk {

    uint32_t quirk_id;
};
typedef struct xenpf_platform_quirk xenpf_platform_quirk_t;
typedef xenpf_platform_quirk_t * __guest_handle_xenpf_platform_quirk_t; typedef const xenpf_platform_quirk_t * __guest_handle_const_xenpf_platform_quirk_t;
# 145 "/var/xen-dev/xen/xen/include/public/platform.h"
struct xenpf_efi_time {
    uint16_t year;
    uint8_t month;
    uint8_t day;
    uint8_t hour;
    uint8_t min;
    uint8_t sec;
    uint32_t ns;
    int16_t tz;
    uint8_t daylight;
};

struct xenpf_efi_guid {
    uint32_t data1;
    uint16_t data2;
    uint16_t data3;
    uint8_t data4[8];
};

struct xenpf_efi_runtime_call {
    uint32_t function;





    uint32_t misc;
    xen_ulong_t status;
    union {

        struct {
            struct xenpf_efi_time time;
            uint32_t resolution;
            uint32_t accuracy;
        } get_time;

        struct xenpf_efi_time set_time;



        struct xenpf_efi_time get_wakeup_time;



        struct xenpf_efi_time set_wakeup_time;




        struct {
            __guest_handle_void name;
            xen_ulong_t size;
            __guest_handle_void data;
            struct xenpf_efi_guid vendor_guid;
        } get_variable, set_variable;

        struct {
            xen_ulong_t size;
            __guest_handle_void name;
            struct xenpf_efi_guid vendor_guid;
        } get_next_variable_name;


        struct {
            uint32_t attr;
            uint64_t max_store_size;
            uint64_t remain_store_size;
            uint64_t max_size;
        } query_variable_info;

        struct {
            __guest_handle_void capsule_header_array;
            xen_ulong_t capsule_count;
            uint64_t max_capsule_size;
            uint32_t reset_type;
        } query_capsule_capabilities;

        struct {
            __guest_handle_void capsule_header_array;
            xen_ulong_t capsule_count;
            uint64_t sg_list;
        } update_capsule;
    } u;
};
typedef struct xenpf_efi_runtime_call xenpf_efi_runtime_call_t;
typedef xenpf_efi_runtime_call_t * __guest_handle_xenpf_efi_runtime_call_t; typedef const xenpf_efi_runtime_call_t * __guest_handle_const_xenpf_efi_runtime_call_t;
# 245 "/var/xen-dev/xen/xen/include/public/platform.h"
struct xenpf_firmware_info {

    uint32_t type;
    uint32_t index;

    union {
        struct {

            uint8_t device;
            uint8_t version;
            uint16_t interface_support;

            uint16_t legacy_max_cylinder;
            uint8_t legacy_max_head;
            uint8_t legacy_sectors_per_track;


            __guest_handle_void edd_params;
        } disk_info;
        struct {
            uint8_t device;
            uint32_t mbr_signature;
        } disk_mbr_signature;
        struct {

            uint8_t capabilities;
            uint8_t edid_transfer_time;

            __guest_handle_uint8 edid;
        } vbeddc_info;
        union xenpf_efi_info {
            uint32_t version;
            struct {
                uint64_t addr;
                uint32_t nent;
            } cfg;
            struct {
                uint32_t revision;
                uint32_t bufsz;
                __guest_handle_void name;
            } vendor;
            struct {
                uint64_t addr;
                uint64_t size;
                uint64_t attr;
                uint32_t type;
            } mem;
            struct {

                uint16_t segment;
                uint8_t bus;
                uint8_t devfn;
                uint16_t vendor;
                uint16_t devid;

                uint64_t address;
                xen_ulong_t size;
            } pci_rom;
            struct {

                uint64_t address;
                xen_ulong_t size;
            } apple_properties;
        } efi_info;


        uint8_t kbd_shift_flags;
    } u;
};
typedef struct xenpf_firmware_info xenpf_firmware_info_t;
typedef xenpf_firmware_info_t * __guest_handle_xenpf_firmware_info_t; typedef const xenpf_firmware_info_t * __guest_handle_const_xenpf_firmware_info_t;


struct xenpf_enter_acpi_sleep {


    uint16_t pm1a_cnt_val;
    uint16_t pm1b_cnt_val;




    uint32_t sleep_state;

    uint32_t flags;
};
typedef struct xenpf_enter_acpi_sleep xenpf_enter_acpi_sleep_t;
typedef xenpf_enter_acpi_sleep_t * __guest_handle_xenpf_enter_acpi_sleep_t; typedef const xenpf_enter_acpi_sleep_t * __guest_handle_const_xenpf_enter_acpi_sleep_t;


struct xenpf_change_freq {

    uint32_t flags;
    uint32_t cpu;
    uint64_t freq;
};
typedef struct xenpf_change_freq xenpf_change_freq_t;
typedef xenpf_change_freq_t * __guest_handle_xenpf_change_freq_t; typedef const xenpf_change_freq_t * __guest_handle_const_xenpf_change_freq_t;
# 353 "/var/xen-dev/xen/xen/include/public/platform.h"
struct xenpf_getidletime {


    __guest_handle_uint8 cpumap_bitmap;


    uint32_t cpumap_nr_cpus;

    __guest_handle_uint64 idletime;


    uint64_t now;
};
typedef struct xenpf_getidletime xenpf_getidletime_t;
typedef xenpf_getidletime_t * __guest_handle_xenpf_getidletime_t; typedef const xenpf_getidletime_t * __guest_handle_const_xenpf_getidletime_t;
# 388 "/var/xen-dev/xen/xen/include/public/platform.h"
struct xen_power_register {
    uint32_t space_id;
    uint32_t bit_width;
    uint32_t bit_offset;
    uint32_t access_size;
    uint64_t address;
};

struct xen_processor_csd {
    uint32_t domain;
    uint32_t coord_type;
    uint32_t num;
};
typedef struct xen_processor_csd xen_processor_csd_t;
typedef xen_processor_csd_t * __guest_handle_xen_processor_csd_t; typedef const xen_processor_csd_t * __guest_handle_const_xen_processor_csd_t;

struct xen_processor_cx {
    struct xen_power_register reg;
    uint8_t type;
    uint32_t latency;
    uint32_t power;
    uint32_t dpcnt;
    __guest_handle_xen_processor_csd_t dp;
};
typedef struct xen_processor_cx xen_processor_cx_t;
typedef xen_processor_cx_t * __guest_handle_xen_processor_cx_t; typedef const xen_processor_cx_t * __guest_handle_const_xen_processor_cx_t;

struct xen_processor_flags {
    uint32_t bm_control:1;
    uint32_t bm_check:1;
    uint32_t has_cst:1;
    uint32_t power_setup_done:1;
    uint32_t bm_rld_set:1;
};

struct xen_processor_power {
    uint32_t count;
    struct xen_processor_flags flags;
    __guest_handle_xen_processor_cx_t states;
};

struct xen_pct_register {
    uint8_t descriptor;
    uint16_t length;
    uint8_t space_id;
    uint8_t bit_width;
    uint8_t bit_offset;
    uint8_t reserved;
    uint64_t address;
};

struct xen_processor_px {
    uint64_t core_frequency;
    uint64_t power;
    uint64_t transition_latency;
    uint64_t bus_master_latency;
    uint64_t control;
    uint64_t status;
};
typedef struct xen_processor_px xen_processor_px_t;
typedef xen_processor_px_t * __guest_handle_xen_processor_px_t; typedef const xen_processor_px_t * __guest_handle_const_xen_processor_px_t;

struct xen_psd_package {
    uint64_t num_entries;
    uint64_t revision;
    uint64_t domain;
    uint64_t coord_type;
    uint64_t num_processors;
};

struct xen_processor_performance {
    uint32_t flags;
    uint32_t platform_limit;
    struct xen_pct_register control_register;
    struct xen_pct_register status_register;
    uint32_t state_count;
    __guest_handle_xen_processor_px_t states;
    struct xen_psd_package domain_info;
    uint32_t shared_type;
};
typedef struct xen_processor_performance xen_processor_performance_t;
typedef xen_processor_performance_t * __guest_handle_xen_processor_performance_t; typedef const xen_processor_performance_t * __guest_handle_const_xen_processor_performance_t;

struct xenpf_set_processor_pminfo {

    uint32_t id;
    uint32_t type;
    union {
        struct xen_processor_power power;
        struct xen_processor_performance perf;
        __guest_handle_uint32 pdc;
    } u;
};
typedef struct xenpf_set_processor_pminfo xenpf_set_processor_pminfo_t;
typedef xenpf_set_processor_pminfo_t * __guest_handle_xenpf_set_processor_pminfo_t; typedef const xenpf_set_processor_pminfo_t * __guest_handle_const_xenpf_set_processor_pminfo_t;


struct xenpf_pcpuinfo {

    uint32_t xen_cpuid;


    uint32_t max_present;



    uint32_t flags;
    uint32_t apic_id;
    uint32_t acpi_id;
};
typedef struct xenpf_pcpuinfo xenpf_pcpuinfo_t;
typedef xenpf_pcpuinfo_t * __guest_handle_xenpf_pcpuinfo_t; typedef const xenpf_pcpuinfo_t * __guest_handle_const_xenpf_pcpuinfo_t;


struct xenpf_pcpu_version {

    uint32_t xen_cpuid;


    uint32_t max_present;
    char vendor_id[12];
    uint32_t family;
    uint32_t model;
    uint32_t stepping;
};
typedef struct xenpf_pcpu_version xenpf_pcpu_version_t;
typedef xenpf_pcpu_version_t * __guest_handle_xenpf_pcpu_version_t; typedef const xenpf_pcpu_version_t * __guest_handle_const_xenpf_pcpu_version_t;



struct xenpf_cpu_ol
{
    uint32_t cpuid;
};
typedef struct xenpf_cpu_ol xenpf_cpu_ol_t;
typedef xenpf_cpu_ol_t * __guest_handle_xenpf_cpu_ol_t; typedef const xenpf_cpu_ol_t * __guest_handle_const_xenpf_cpu_ol_t;


struct xenpf_cpu_hotadd
{
 uint32_t apic_id;
 uint32_t acpi_id;
 uint32_t pxm;
};


struct xenpf_mem_hotadd
{
    uint64_t spfn;
    uint64_t epfn;
    uint32_t pxm;
    uint32_t flags;
};





struct xenpf_core_parking {

    uint32_t type;


    uint32_t idle_nums;
};
typedef struct xenpf_core_parking xenpf_core_parking_t;
typedef xenpf_core_parking_t * __guest_handle_xenpf_core_parking_t; typedef const xenpf_core_parking_t * __guest_handle_const_xenpf_core_parking_t;
# 579 "/var/xen-dev/xen/xen/include/public/platform.h"
struct xenpf_resource_entry {
    union {
        uint32_t cmd;
        int32_t ret;
    } u;
    uint32_t rsvd;
    uint64_t idx;
    uint64_t val;
};
typedef struct xenpf_resource_entry xenpf_resource_entry_t;
typedef xenpf_resource_entry_t * __guest_handle_xenpf_resource_entry_t; typedef const xenpf_resource_entry_t * __guest_handle_const_xenpf_resource_entry_t;

struct xenpf_resource_op {
    uint32_t nr_entries;
    uint32_t cpu;
    __guest_handle_xenpf_resource_entry_t entries;
};
typedef struct xenpf_resource_op xenpf_resource_op_t;
typedef xenpf_resource_op_t * __guest_handle_xenpf_resource_op_t; typedef const xenpf_resource_op_t * __guest_handle_const_xenpf_resource_op_t;


struct xenpf_symdata {

    uint32_t namelen;


    uint32_t symnum;




    __guest_handle_char name;
    uint64_t address;
    char type;
};
typedef struct xenpf_symdata xenpf_symdata_t;
typedef xenpf_symdata_t * __guest_handle_xenpf_symdata_t; typedef const xenpf_symdata_t * __guest_handle_const_xenpf_symdata_t;





struct xen_platform_op {
    uint32_t cmd;
    uint32_t interface_version;
    union {
        struct xenpf_settime32 settime;
        struct xenpf_settime32 settime32;
        struct xenpf_settime64 settime64;
        struct xenpf_add_memtype add_memtype;
        struct xenpf_del_memtype del_memtype;
        struct xenpf_read_memtype read_memtype;
        struct xenpf_microcode_update microcode;
        struct xenpf_platform_quirk platform_quirk;
        struct xenpf_efi_runtime_call efi_runtime_call;
        struct xenpf_firmware_info firmware_info;
        struct xenpf_enter_acpi_sleep enter_acpi_sleep;
        struct xenpf_change_freq change_freq;
        struct xenpf_getidletime getidletime;
        struct xenpf_set_processor_pminfo set_pminfo;
        struct xenpf_pcpuinfo pcpu_info;
        struct xenpf_pcpu_version pcpu_version;
        struct xenpf_cpu_ol cpu_ol;
        struct xenpf_cpu_hotadd cpu_add;
        struct xenpf_mem_hotadd mem_add;
        struct xenpf_core_parking core_parking;
        struct xenpf_resource_op resource_op;
        struct xenpf_symdata symdata;
        uint8_t pad[128];
    } u;
};
typedef struct xen_platform_op xen_platform_op_t;
typedef xen_platform_op_t * __guest_handle_xen_platform_op_t; typedef const xen_platform_op_t * __guest_handle_const_xen_platform_op_t;
# 14 "/var/xen-dev/xen/xen/include/xen/hypercall.h" 2
# 1 "/var/xen-dev/xen/xen/include/public/event_channel.h" 1
# 15 "/var/xen-dev/xen/xen/include/xen/hypercall.h" 2
# 1 "/var/xen-dev/xen/xen/include/public/version.h" 1
# 41 "/var/xen-dev/xen/xen/include/public/version.h"
typedef char xen_extraversion_t[16];




struct xen_compile_info {
    char compiler[64];
    char compile_by[16];
    char compile_domain[32];
    char compile_date[32];
};
typedef struct xen_compile_info xen_compile_info_t;


typedef char xen_capabilities_info_t[1024];



typedef char xen_changeset_info_t[64];



struct xen_platform_parameters {
    xen_ulong_t virt_start;
};
typedef struct xen_platform_parameters xen_platform_parameters_t;


struct xen_feature_info {
    unsigned int submap_idx;
    uint32_t submap;
};
typedef struct xen_feature_info xen_feature_info_t;


# 1 "/var/xen-dev/xen/xen/include/public/features.h" 1
# 77 "/var/xen-dev/xen/xen/include/public/version.h" 2
# 89 "/var/xen-dev/xen/xen/include/public/version.h"
typedef char xen_commandline_t[1024];






struct xen_build_id {
        uint32_t len;
        unsigned char buf[];

};
typedef struct xen_build_id xen_build_id_t;
# 16 "/var/xen-dev/xen/xen/include/xen/hypercall.h" 2
# 1 "/var/xen-dev/xen/xen/include/public/pmu.h" 1
# 28 "/var/xen-dev/xen/xen/include/public/pmu.h"
# 1 "/var/xen-dev/xen/xen/include/public/arch-x86/pmu.h" 1
# 29 "/var/xen-dev/xen/xen/include/public/arch-x86/pmu.h"
struct xen_pmu_amd_ctxt {




    uint32_t counters;
    uint32_t ctrls;


    uint64_t regs[];
};
typedef struct xen_pmu_amd_ctxt xen_pmu_amd_ctxt_t;
typedef xen_pmu_amd_ctxt_t * __guest_handle_xen_pmu_amd_ctxt_t; typedef const xen_pmu_amd_ctxt_t * __guest_handle_const_xen_pmu_amd_ctxt_t;


struct xen_pmu_cntr_pair {
    uint64_t counter;
    uint64_t control;
};
typedef struct xen_pmu_cntr_pair xen_pmu_cntr_pair_t;
typedef xen_pmu_cntr_pair_t * __guest_handle_xen_pmu_cntr_pair_t; typedef const xen_pmu_cntr_pair_t * __guest_handle_const_xen_pmu_cntr_pair_t;

struct xen_pmu_intel_ctxt {





    uint32_t fixed_counters;
    uint32_t arch_counters;


    uint64_t global_ctrl;
    uint64_t global_ovf_ctrl;
    uint64_t global_status;
    uint64_t fixed_ctrl;
    uint64_t ds_area;
    uint64_t pebs_enable;
    uint64_t debugctl;


    uint64_t regs[];
};
typedef struct xen_pmu_intel_ctxt xen_pmu_intel_ctxt_t;
typedef xen_pmu_intel_ctxt_t * __guest_handle_xen_pmu_intel_ctxt_t; typedef const xen_pmu_intel_ctxt_t * __guest_handle_const_xen_pmu_intel_ctxt_t;


struct xen_pmu_regs {
    uint64_t ip;
    uint64_t sp;
    uint64_t flags;
    uint16_t cs;
    uint16_t ss;
    uint8_t cpl;
    uint8_t pad[3];
};
typedef struct xen_pmu_regs xen_pmu_regs_t;
typedef xen_pmu_regs_t * __guest_handle_xen_pmu_regs_t; typedef const xen_pmu_regs_t * __guest_handle_const_xen_pmu_regs_t;
# 102 "/var/xen-dev/xen/xen/include/public/arch-x86/pmu.h"
struct xen_pmu_arch {
    union {




        struct xen_pmu_regs regs;


        uint8_t pad[64];
    } r;


    uint64_t pmu_flags;







    union {
        uint32_t lapic_lvtpc;
        uint64_t pad;
    } l;







    union {
        struct xen_pmu_amd_ctxt amd;
        struct xen_pmu_intel_ctxt intel;






        uint8_t pad[128];
    } c;
};
typedef struct xen_pmu_arch xen_pmu_arch_t;
typedef xen_pmu_arch_t * __guest_handle_xen_pmu_arch_t; typedef const xen_pmu_arch_t * __guest_handle_const_xen_pmu_arch_t;
# 29 "/var/xen-dev/xen/xen/include/public/pmu.h" 2
# 57 "/var/xen-dev/xen/xen/include/public/pmu.h"
struct xen_pmu_params {

    struct {
        uint32_t maj;
        uint32_t min;
    } version;
    uint64_t val;


    uint32_t vcpu;
    uint32_t pad;
};
typedef struct xen_pmu_params xen_pmu_params_t;
typedef xen_pmu_params_t * __guest_handle_xen_pmu_params_t; typedef const xen_pmu_params_t * __guest_handle_const_xen_pmu_params_t;
# 110 "/var/xen-dev/xen/xen/include/public/pmu.h"
struct xen_pmu_data {

    uint32_t vcpu_id;





    uint32_t pcpu_id;






    domid_t domain_id;

    uint8_t pad[6];


    struct xen_pmu_arch pmu;
};
# 17 "/var/xen-dev/xen/xen/include/xen/hypercall.h" 2
# 1 "/var/xen-dev/xen/xen/include/public/hvm/dm_op.h" 1
# 27 "/var/xen-dev/xen/xen/include/public/hvm/dm_op.h"
# 1 "/var/xen-dev/xen/xen/include/public/hvm/../xen.h" 1
# 28 "/var/xen-dev/xen/xen/include/public/hvm/dm_op.h" 2
# 448 "/var/xen-dev/xen/xen/include/public/hvm/dm_op.h"
struct xen_dm_op_buf {
    __guest_handle_void h;
    xen_ulong_t size;
};
typedef struct xen_dm_op_buf xen_dm_op_buf_t;
typedef xen_dm_op_buf_t * __guest_handle_xen_dm_op_buf_t; typedef const xen_dm_op_buf_t * __guest_handle_const_xen_dm_op_buf_t;
# 18 "/var/xen-dev/xen/xen/include/xen/hypercall.h" 2
# 1 "/var/xen-dev/xen/xen/include/asm/hypercall.h" 1
# 9 "/var/xen-dev/xen/xen/include/asm/hypercall.h"
# 1 "/var/xen-dev/xen/xen/include/public/physdev.h" 1
# 10 "/var/xen-dev/xen/xen/include/asm/hypercall.h" 2

# 1 "/var/xen-dev/xen/xen/include/public/arch-x86/xen-mca.h" 1
# 111 "/var/xen-dev/xen/xen/include/public/arch-x86/xen-mca.h"
struct mcinfo_common {
    uint16_t type;
    uint16_t size;
};
# 125 "/var/xen-dev/xen/xen/include/public/arch-x86/xen-mca.h"
struct mcinfo_global {
    struct mcinfo_common common;


    uint16_t mc_domid;
    uint16_t mc_vcpuid;
    uint32_t mc_socketid;
    uint16_t mc_coreid;
    uint16_t mc_core_threadid;
    uint32_t mc_apicid;
    uint32_t mc_flags;
    uint64_t mc_gstatus;
};


struct mcinfo_bank {
    struct mcinfo_common common;

    uint16_t mc_bank;
    uint16_t mc_domid;

    uint64_t mc_status;
    uint64_t mc_addr;

    uint64_t mc_misc;
    uint64_t mc_ctrl2;
    uint64_t mc_tsc;
};


struct mcinfo_msr {
    uint64_t reg;
    uint64_t value;
};



struct mcinfo_extended {
    struct mcinfo_common common;





    uint32_t mc_msrs;





    struct mcinfo_msr mc_msr[sizeof(void *) * 4];
};
# 205 "/var/xen-dev/xen/xen/include/public/arch-x86/xen-mca.h"
struct page_offline_action
{

    uint64_t mfn;
    uint64_t status;
};

struct cpu_offline_action
{

    uint32_t mc_socketid;
    uint16_t mc_coreid;
    uint16_t mc_core_threadid;
};


struct mcinfo_recovery
{
    struct mcinfo_common common;
    uint16_t mc_bank;
    uint8_t action_flags;
    uint8_t action_types;
    union {
        struct page_offline_action page_retire;
        struct cpu_offline_action cpu_offline;
        uint8_t pad[16];
    } action_info;
};






struct mc_info {

    uint32_t mi_nentries;
    uint32_t flags;
    uint64_t mi_data[(768 - 1) / 8];
};
typedef struct mc_info mc_info_t;
typedef mc_info_t * __guest_handle_mc_info_t; typedef const mc_info_t * __guest_handle_const_mc_info_t;
# 259 "/var/xen-dev/xen/xen/include/public/arch-x86/xen-mca.h"
struct mcinfo_logical_cpu {
    uint32_t mc_cpunr;
    uint32_t mc_chipid;
    uint16_t mc_coreid;
    uint16_t mc_threadid;
    uint32_t mc_apicid;
    uint32_t mc_clusterid;
    uint32_t mc_ncores;
    uint32_t mc_ncores_active;
    uint32_t mc_nthreads;
    int32_t mc_cpuid_level;
    uint32_t mc_family;
    uint32_t mc_vendor;
    uint32_t mc_model;
    uint32_t mc_step;
    char mc_vendorid[16];
    char mc_brandid[64];
    uint32_t mc_cpu_caps[7];
    uint32_t mc_cache_size;
    uint32_t mc_cache_alignment;
    int32_t mc_nmsrvals;
    struct mcinfo_msr mc_msrvalues[8];
};
typedef struct mcinfo_logical_cpu xen_mc_logical_cpu_t;
typedef xen_mc_logical_cpu_t * __guest_handle_xen_mc_logical_cpu_t; typedef const xen_mc_logical_cpu_t * __guest_handle_const_xen_mc_logical_cpu_t;
# 346 "/var/xen-dev/xen/xen/include/public/arch-x86/xen-mca.h"
struct xen_mc_fetch {

    uint32_t flags;



    uint32_t _pad0;
    uint64_t fetch_id;


    __guest_handle_mc_info_t data;
};
typedef struct xen_mc_fetch xen_mc_fetch_t;
typedef xen_mc_fetch_t * __guest_handle_xen_mc_fetch_t; typedef const xen_mc_fetch_t * __guest_handle_const_xen_mc_fetch_t;






struct xen_mc_notifydomain {

    uint16_t mc_domid;
    uint16_t mc_vcpuid;



    uint32_t flags;



};
typedef struct xen_mc_notifydomain xen_mc_notifydomain_t;
typedef xen_mc_notifydomain_t * __guest_handle_xen_mc_notifydomain_t; typedef const xen_mc_notifydomain_t * __guest_handle_const_xen_mc_notifydomain_t;


struct xen_mc_physcpuinfo {

    uint32_t ncpus;
    uint32_t _pad0;

    __guest_handle_xen_mc_logical_cpu_t info;
};



struct xen_mc_msrinject {

    uint32_t mcinj_cpunr;
    uint32_t mcinj_flags;
    uint32_t mcinj_count;
    domid_t mcinj_domid;

    uint16_t _pad0;
    struct mcinfo_msr mcinj_msr[8];
};






struct xen_mc_mceinject {
    unsigned int mceinj_cpunr;
};
# 427 "/var/xen-dev/xen/xen/include/public/arch-x86/xen-mca.h"
struct xen_mc {
    uint32_t cmd;
    uint32_t interface_version;
    union {
        struct xen_mc_fetch mc_fetch;
        struct xen_mc_notifydomain mc_notifydomain;
        struct xen_mc_physcpuinfo mc_physcpuinfo;
        struct xen_mc_msrinject mc_msrinject;
        struct xen_mc_mceinject mc_mceinject;



    } u;
};
typedef struct xen_mc xen_mc_t;
typedef xen_mc_t * __guest_handle_xen_mc_t; typedef const xen_mc_t * __guest_handle_const_xen_mc_t;
# 12 "/var/xen-dev/xen/xen/include/asm/hypercall.h" 2
# 1 "/var/xen-dev/xen/xen/include/asm/paging.h" 1
# 27 "/var/xen-dev/xen/xen/include/asm/paging.h"
# 1 "/var/xen-dev/xen/xen/include/xen/mm.h" 1
# 55 "/var/xen-dev/xen/xen/include/xen/mm.h"
# 1 "/var/xen-dev/xen/xen/include/xen/list.h" 1
# 11 "/var/xen-dev/xen/xen/include/xen/list.h"
# 1 "/var/xen-dev/xen/xen/include/asm/system.h" 1
# 14 "/var/xen-dev/xen/xen/include/asm/system.h"
static __inline__ void wbinvd(void)
{
    asm volatile ( "wbinvd" ::: "memory" );
}

static __inline__ void wbnoinvd(void)
{
    asm volatile ( "repe; wbinvd" : : : "memory" );
}

static __inline__ void clflush(const void *p)
{
    asm volatile ( "clflush %0" :: "m" (*(const char *)p) );
}

static __inline__ void clflushopt(const void *p)
{
    asm volatile ( "data16 clflush %0" :: "m" (*(const char *)p) );
}

static __inline__ void clwb(const void *p)
{





    asm volatile ( ".byte 0x66, 0x0f, 0xae, 0x32"
                   :: "d" (p), "m" (*(const char *)p) );

}




# 1 "/var/xen-dev/xen/xen/include/asm/x86_64/system.h" 1
# 16 "/var/xen-dev/xen/xen/include/asm/x86_64/system.h"
static __inline__ __attribute__ ((__always_inline__)) __uint128_t __cmpxchg16b(
    volatile void *ptr, const __uint128_t *oldp, const __uint128_t *newp)
{
    union {
        struct { uint64_t lo, hi; };
        __uint128_t raw;
    } new = { .raw = *newp }, old = { .raw = *oldp }, prev;

    do { if ( __builtin_expect(!!(!(({ if ( (sizeof(*(boot_cpu_data.x86_capability)) < 4) ) __bitop_bad_size(); __builtin_constant_p(X86_FEATURE_CX16) ? constant_test_bit(X86_FEATURE_CX16, boot_cpu_data.x86_capability) : variable_test_bit(X86_FEATURE_CX16, boot_cpu_data.x86_capability); }))),0) ) do { do { ({ _Static_assert(!((24) >> ((31 - 24) + (31 - 24))), "!(" "(24) >> (BUG_LINE_LO_WIDTH + BUG_LINE_HI_WIDTH)" ")"); }); ({ _Static_assert(!((3) >= 4), "!(" "(3) >= BUGFRAME_NR" ")"); }); asm volatile ( ".Lbug%=: ud2\n" ".pushsection .bug_frames.%c[bf_type], \"a\", @progbits\n" ".p2align 2\n" ".Lfrm%=:\n" ".long (.Lbug%= - .Lfrm%=) + %c[bf_line_hi]\n" ".long (%c[bf_ptr] - .Lfrm%=) + %c[bf_line_lo]\n" ".if " "1" "\n" ".long 0, %c[bf_msg] - .Lfrm%=\n" ".endif\n" ".popsection\n" :: [bf_type] "i" (3), [bf_ptr] "i" ("/var/xen-dev/xen/xen/include/asm/x86_64/system.h"), [bf_msg] "i" ("cpu_has_cx16"), [bf_line_lo] "i" ((24 & ((1 << (31 - 24)) - 1)) << 24), [bf_line_hi] "i" (((24) >> (31 - 24)) << 24) ); } while (0); __builtin_unreachable(); } while (0); } while (0);


    asm volatile ( "lock cmpxchg16b %[ptr]"
                   : "=d" (prev.hi), "=a" (prev.lo),
                     [ptr] "+m" (*(volatile __uint128_t *)ptr)
                   : "c" (new.hi), "b" (new.lo), "d" (old.hi), "a" (old.lo) );

    return prev.raw;
}

static __inline__ __attribute__ ((__always_inline__)) __uint128_t cmpxchg16b_local_(
    void *ptr, const __uint128_t *oldp, const __uint128_t *newp)
{
    union {
        struct { uint64_t lo, hi; };
        __uint128_t raw;
    } new = { .raw = *newp }, old = { .raw = *oldp }, prev;

    do { if ( __builtin_expect(!!(!(({ if ( (sizeof(*(boot_cpu_data.x86_capability)) < 4) ) __bitop_bad_size(); __builtin_constant_p(X86_FEATURE_CX16) ? constant_test_bit(X86_FEATURE_CX16, boot_cpu_data.x86_capability) : variable_test_bit(X86_FEATURE_CX16, boot_cpu_data.x86_capability); }))),0) ) do { do { ({ _Static_assert(!((43) >> ((31 - 24) + (31 - 24))), "!(" "(43) >> (BUG_LINE_LO_WIDTH + BUG_LINE_HI_WIDTH)" ")"); }); ({ _Static_assert(!((3) >= 4), "!(" "(3) >= BUGFRAME_NR" ")"); }); asm volatile ( ".Lbug%=: ud2\n" ".pushsection .bug_frames.%c[bf_type], \"a\", @progbits\n" ".p2align 2\n" ".Lfrm%=:\n" ".long (.Lbug%= - .Lfrm%=) + %c[bf_line_hi]\n" ".long (%c[bf_ptr] - .Lfrm%=) + %c[bf_line_lo]\n" ".if " "1" "\n" ".long 0, %c[bf_msg] - .Lfrm%=\n" ".endif\n" ".popsection\n" :: [bf_type] "i" (3), [bf_ptr] "i" ("/var/xen-dev/xen/xen/include/asm/x86_64/system.h"), [bf_msg] "i" ("cpu_has_cx16"), [bf_line_lo] "i" ((43 & ((1 << (31 - 24)) - 1)) << 24), [bf_line_hi] "i" (((43) >> (31 - 24)) << 24) ); } while (0); __builtin_unreachable(); } while (0); } while (0);


    asm volatile ( "cmpxchg16b %[ptr]"
                   : "=d" (prev.hi), "=a" (prev.lo),
                     [ptr] "+m" (*(__uint128_t *)ptr)
                   : "c" (new.hi), "b" (new.lo), "d" (old.hi), "a" (old.lo) );

    return prev.raw;
}
# 50 "/var/xen-dev/xen/xen/include/asm/system.h" 2






static __inline__ __attribute__ ((__always_inline__)) unsigned long __xchg(
    unsigned long x, volatile void *ptr, int size)
{
    switch ( size )
    {
    case 1:
        asm volatile ( "xchg %b[x], %[ptr]"
                       : [x] "+q" (x), [ptr] "+m" (*(volatile uint8_t *)ptr)
                       :: "memory" );
        break;
    case 2:
        asm volatile ( "xchg %w[x], %[ptr]"
                       : [x] "+r" (x), [ptr] "+m" (*(volatile uint16_t *)ptr)
                       :: "memory" );
        break;
    case 4:
        asm volatile ( "xchg %k[x], %[ptr]"
                       : [x] "+r" (x), [ptr] "+m" (*(volatile uint32_t *)ptr)
                       :: "memory" );
        break;
    case 8:
        asm volatile ( "xchg %q[x], %[ptr]"
                       : [x] "+r" (x), [ptr] "+m" (*(volatile uint64_t *)ptr)
                       :: "memory" );
        break;
    }
    return x;
}







static __inline__ __attribute__ ((__always_inline__)) unsigned long __cmpxchg(
    volatile void *ptr, unsigned long old, unsigned long new, int size)
{
    unsigned long prev;
    switch ( size )
    {
    case 1:
        asm volatile ( "lock cmpxchg %b[new], %[ptr]"
                       : "=a" (prev), [ptr] "+m" (*(volatile uint8_t *)ptr)
                       : [new] "q" (new), "a" (old)
                       : "memory" );
        return prev;
    case 2:
        asm volatile ( "lock cmpxchg %w[new], %[ptr]"
                       : "=a" (prev), [ptr] "+m" (*(volatile uint16_t *)ptr)
                       : [new] "r" (new), "a" (old)
                       : "memory" );
        return prev;
    case 4:
        asm volatile ( "lock cmpxchg %k[new], %[ptr]"
                       : "=a" (prev), [ptr] "+m" (*(volatile uint32_t *)ptr)
                       : [new] "r" (new), "a" (old)
                       : "memory" );
        return prev;
    case 8:
        asm volatile ( "lock cmpxchg %q[new], %[ptr]"
                       : "=a" (prev), [ptr] "+m" (*(volatile uint64_t *)ptr)
                       : [new] "r" (new), "a" (old)
                       : "memory" );
        return prev;
    }
    return old;
}

static __inline__ __attribute__ ((__always_inline__)) unsigned long cmpxchg_local_(
    void *ptr, unsigned long old, unsigned long new, unsigned int size)
{
    unsigned long prev = ~old;

    switch ( size )
    {
    case 1:
        asm volatile ( "cmpxchg %b[new], %[ptr]"
                       : "=a" (prev), [ptr] "+m" (*(uint8_t *)ptr)
                       : [new] "q" (new), "a" (old) );
        break;
    case 2:
        asm volatile ( "cmpxchg %w[new], %[ptr]"
                       : "=a" (prev), [ptr] "+m" (*(uint16_t *)ptr)
                       : [new] "r" (new), "a" (old) );
        break;
    case 4:
        asm volatile ( "cmpxchg %k[new], %[ptr]"
                       : "=a" (prev), [ptr] "+m" (*(uint32_t *)ptr)
                       : [new] "r" (new), "a" (old) );
        break;
    case 8:
        asm volatile ( "cmpxchg %q[new], %[ptr]"
                       : "=a" (prev), [ptr] "+m" (*(uint64_t *)ptr)
                       : [new] "r" (new), "a" (old) );
        break;
    }

    return prev;
}
# 168 "/var/xen-dev/xen/xen/include/asm/system.h"
extern unsigned long __bad_fetch_and_add_size(void);

static __inline__ __attribute__ ((__always_inline__)) unsigned long __xadd(
    volatile void *ptr, unsigned long v, int size)
{
    switch ( size )
    {
    case 1:
        asm volatile ( "lock xadd %b[v], %[ptr]"
                       : [v] "+q" (v), [ptr] "+m" (*(volatile uint8_t *)ptr)
                       :: "memory");
        return v;
    case 2:
        asm volatile ( "lock xadd %w[v], %[ptr]"
                       : [v] "+r" (v), [ptr] "+m" (*(volatile uint16_t *)ptr)
                       :: "memory");
        return v;
    case 4:
        asm volatile ( "lock xadd %k[v], %[ptr]"
                       : [v] "+r" (v), [ptr] "+m" (*(volatile uint32_t *)ptr)
                       :: "memory");
        return v;
    case 8:
        asm volatile ( "lock xadd %q[v], %[ptr]"
                       : [v] "+r" (v), [ptr] "+m" (*(volatile uint64_t *)ptr)
                       :: "memory");

        return v;
    default:
        return __bad_fetch_and_add_size();
    }
}
# 245 "/var/xen-dev/xen/xen/include/asm/system.h"
static __inline__ unsigned long array_index_mask_nospec(unsigned long index,
                                                    unsigned long size)
{
    unsigned long mask;

    asm volatile ( "cmp %[size], %[index]; sbb %[mask], %[mask];"
                   : [mask] "=r" (mask)
                   : [size] "g" (size), [index] "r" (index) );

    return mask;
}
# 289 "/var/xen-dev/xen/xen/include/asm/system.h"
static __inline__ int local_irq_is_enabled(void)
{
    unsigned long flags;
    ({ ({ _Static_assert(!(sizeof(flags) != sizeof(long)), "!(" "sizeof(flags) != sizeof(long)" ")"); }); asm volatile ( "pushf" __OS " ; pop" __OS " %0" : "=g" (flags)); });
    return !!(flags & 0x00000200);
}




void trap_init(void);
void init_idt_traps(void);
void load_system_tables(void);
void percpu_traps_init(void);
void subarch_percpu_traps_init(void);
# 12 "/var/xen-dev/xen/xen/include/xen/list.h" 2
# 33 "/var/xen-dev/xen/xen/include/xen/list.h"
struct list_head {
    struct list_head *next, *prev;
};
# 46 "/var/xen-dev/xen/xen/include/xen/list.h"
# 1 "/var/xen-dev/xen/xen/include/xen/prefetch.h" 1
# 47 "/var/xen-dev/xen/xen/include/xen/list.h" 2

static __inline__ void INIT_LIST_HEAD(struct list_head *list)
{
    list->next = list;
    list->prev = list;
}

static __inline__ _Bool list_head_is_null(const struct list_head *list)
{
    return !list->next && !list->prev;
}







static __inline__ void __list_add(struct list_head *new,
                              struct list_head *prev,
                              struct list_head *next)
{
    next->prev = new;
    new->next = next;
    new->prev = prev;
    prev->next = new;
}
# 83 "/var/xen-dev/xen/xen/include/xen/list.h"
static __inline__ void list_add(struct list_head *new, struct list_head *head)
{
    __list_add(new, head, head->next);
}
# 96 "/var/xen-dev/xen/xen/include/xen/list.h"
static __inline__ void list_add_tail(struct list_head *new, struct list_head *head)
{
    __list_add(new, head->prev, head);
}







static __inline__ void __list_add_rcu(struct list_head *new,
                                  struct list_head *prev,
                                  struct list_head *next)
{
    new->next = next;
    new->prev = prev;
    __asm__ __volatile__("": : :"memory");
    next->prev = new;
    prev->next = new;
}
# 134 "/var/xen-dev/xen/xen/include/xen/list.h"
static __inline__ void list_add_rcu(struct list_head *new, struct list_head *head)
{
    __list_add_rcu(new, head, head->next);
}
# 155 "/var/xen-dev/xen/xen/include/xen/list.h"
static __inline__ void list_add_tail_rcu(struct list_head *new,
                                     struct list_head *head)
{
    __list_add_rcu(new, head->prev, head);
}
# 168 "/var/xen-dev/xen/xen/include/xen/list.h"
static __inline__ void __list_del(struct list_head *prev,
                              struct list_head *next)
{
    next->prev = prev;
    prev->next = next;
}







static __inline__ void list_del(struct list_head *entry)
{
    do { if ( __builtin_expect(!!(!(entry->next->prev == entry)),0) ) do { do { ({ _Static_assert(!((183) >> ((31 - 24) + (31 - 24))), "!(" "(183) >> (BUG_LINE_LO_WIDTH + BUG_LINE_HI_WIDTH)" ")"); }); ({ _Static_assert(!((3) >= 4), "!(" "(3) >= BUGFRAME_NR" ")"); }); asm volatile ( ".Lbug%=: ud2\n" ".pushsection .bug_frames.%c[bf_type], \"a\", @progbits\n" ".p2align 2\n" ".Lfrm%=:\n" ".long (.Lbug%= - .Lfrm%=) + %c[bf_line_hi]\n" ".long (%c[bf_ptr] - .Lfrm%=) + %c[bf_line_lo]\n" ".if " "1" "\n" ".long 0, %c[bf_msg] - .Lfrm%=\n" ".endif\n" ".popsection\n" :: [bf_type] "i" (3), [bf_ptr] "i" ("/var/xen-dev/xen/xen/include/xen/list.h"), [bf_msg] "i" ("entry->next->prev == entry"), [bf_line_lo] "i" ((183 & ((1 << (31 - 24)) - 1)) << 24), [bf_line_hi] "i" (((183) >> (31 - 24)) << 24) ); } while (0); __builtin_unreachable(); } while (0); } while (0);
    do { if ( __builtin_expect(!!(!(entry->prev->next == entry)),0) ) do { do { ({ _Static_assert(!((184) >> ((31 - 24) + (31 - 24))), "!(" "(184) >> (BUG_LINE_LO_WIDTH + BUG_LINE_HI_WIDTH)" ")"); }); ({ _Static_assert(!((3) >= 4), "!(" "(3) >= BUGFRAME_NR" ")"); }); asm volatile ( ".Lbug%=: ud2\n" ".pushsection .bug_frames.%c[bf_type], \"a\", @progbits\n" ".p2align 2\n" ".Lfrm%=:\n" ".long (.Lbug%= - .Lfrm%=) + %c[bf_line_hi]\n" ".long (%c[bf_ptr] - .Lfrm%=) + %c[bf_line_lo]\n" ".if " "1" "\n" ".long 0, %c[bf_msg] - .Lfrm%=\n" ".endif\n" ".popsection\n" :: [bf_type] "i" (3), [bf_ptr] "i" ("/var/xen-dev/xen/xen/include/xen/list.h"), [bf_msg] "i" ("entry->prev->next == entry"), [bf_line_lo] "i" ((184 & ((1 << (31 - 24)) - 1)) << 24), [bf_line_hi] "i" (((184) >> (31 - 24)) << 24) ); } while (0); __builtin_unreachable(); } while (0); } while (0);
    __list_del(entry->prev, entry->next);
    entry->next = ((void *) 0x00100100);
    entry->prev = ((void *) 0x00200200);
}
# 214 "/var/xen-dev/xen/xen/include/xen/list.h"
static __inline__ void list_del_rcu(struct list_head *entry)
{
    __list_del(entry->prev, entry->next);
    entry->prev = ((void *) 0x00200200);
}







static __inline__ void list_replace(struct list_head *old,
                                struct list_head *new)
{
    new->next = old->next;
    new->next->prev = new;
    new->prev = old->prev;
    new->prev->next = new;
}

static __inline__ void list_replace_init(struct list_head *old,
                                     struct list_head *new)
{
    list_replace(old, new);
    INIT_LIST_HEAD(old);
}
# 250 "/var/xen-dev/xen/xen/include/xen/list.h"
static __inline__ void list_replace_rcu(struct list_head *old,
                                    struct list_head *new)
{
    new->next = old->next;
    new->prev = old->prev;
    __asm__ __volatile__("": : :"memory");
    new->next->prev = new;
    new->prev->next = new;
    old->prev = ((void *) 0x00200200);
}





static __inline__ void list_del_init(struct list_head *entry)
{
    __list_del(entry->prev, entry->next);
    INIT_LIST_HEAD(entry);
}






static __inline__ void list_move(struct list_head *list, struct list_head *head)
{
    __list_del(list->prev, list->next);
    list_add(list, head);
}






static __inline__ void list_move_tail(struct list_head *list,
                                  struct list_head *head)
{
    __list_del(list->prev, list->next);
    list_add_tail(list, head);
}






static __inline__ int list_is_last(const struct list_head *list,
                               const struct list_head *head)
{
    return list->next == head;
}





static __inline__ int list_empty(const struct list_head *head)
{
    return head->next == head;
}





static __inline__ int list_is_singular(const struct list_head *head)
{
    return !list_empty(head) && (head->next == head->prev);
}
# 336 "/var/xen-dev/xen/xen/include/xen/list.h"
static __inline__ int list_empty_careful(const struct list_head *head)
{
    struct list_head *next = head->next;
    return (next == head) && (next == head->prev);
}

static __inline__ void __list_splice(struct list_head *list,
                                 struct list_head *head)
{
    struct list_head *first = list->next;
    struct list_head *last = list->prev;
    struct list_head *at = head->next;

    first->prev = head;
    head->next = first;

    last->next = at;
    at->prev = last;
}






static __inline__ void list_splice(struct list_head *list, struct list_head *head)
{
    if (!list_empty(list))
        __list_splice(list, head);
}
# 374 "/var/xen-dev/xen/xen/include/xen/list.h"
static __inline__ void list_splice_init(struct list_head *list,
                                    struct list_head *head)
{
    if (!list_empty(list)) {
        __list_splice(list, head);
        INIT_LIST_HEAD(list);
    }
}
# 702 "/var/xen-dev/xen/xen/include/xen/list.h"
struct hlist_head {
    struct hlist_node *first;
};

struct hlist_node {
    struct hlist_node *next, **pprev;
};




static __inline__ void INIT_HLIST_NODE(struct hlist_node *h)
{
    h->next = ((void*)0);
    h->pprev = ((void*)0);
}

static __inline__ int hlist_unhashed(const struct hlist_node *h)
{
    return !h->pprev;
}

static __inline__ int hlist_empty(const struct hlist_head *h)
{
    return !h->first;
}

static __inline__ void __hlist_del(struct hlist_node *n)
{
    struct hlist_node *next = n->next;
    struct hlist_node **pprev = n->pprev;
    *pprev = next;
    if (next)
        next->pprev = pprev;
}

static __inline__ void hlist_del(struct hlist_node *n)
{
    __hlist_del(n);
    n->next = ((void *) 0x00100100);
    n->pprev = ((void *) 0x00200200);
}
# 764 "/var/xen-dev/xen/xen/include/xen/list.h"
static __inline__ void hlist_del_rcu(struct hlist_node *n)
{
    __hlist_del(n);
    n->pprev = ((void *) 0x00200200);
}

static __inline__ void hlist_del_init(struct hlist_node *n)
{
    if (!hlist_unhashed(n)) {
        __hlist_del(n);
        INIT_HLIST_NODE(n);
    }
}
# 785 "/var/xen-dev/xen/xen/include/xen/list.h"
static __inline__ void hlist_replace_rcu(struct hlist_node *old,
                                     struct hlist_node *new)
{
    struct hlist_node *next = old->next;

    new->next = next;
    new->pprev = old->pprev;
    __asm__ __volatile__("": : :"memory");
    if (next)
        new->next->pprev = &new->next;
    *new->pprev = new;
    old->pprev = ((void *) 0x00200200);
}

static __inline__ void hlist_add_head(struct hlist_node *n, struct hlist_head *h)
{
    struct hlist_node *first = h->first;
    n->next = first;
    if (first)
        first->pprev = &n->next;
    h->first = n;
    n->pprev = &h->first;
}
# 828 "/var/xen-dev/xen/xen/include/xen/list.h"
static __inline__ void hlist_add_head_rcu(struct hlist_node *n,
                                      struct hlist_head *h)
{
    struct hlist_node *first = h->first;
    n->next = first;
    n->pprev = &h->first;
    __asm__ __volatile__("": : :"memory");
    if (first)
        first->pprev = &n->next;
    h->first = n;
}


static __inline__ void hlist_add_before(struct hlist_node *n,
                    struct hlist_node *next)
{
    n->pprev = next->pprev;
    n->next = next;
    next->pprev = &n->next;
    *(n->pprev) = n;
}

static __inline__ void hlist_add_after(struct hlist_node *n,
                    struct hlist_node *next)
{
    next->next = n->next;
    n->next = next;
    next->pprev = &n->next;

    if(next->next)
        next->next->pprev = &next->next;
}
# 879 "/var/xen-dev/xen/xen/include/xen/list.h"
static __inline__ void hlist_add_before_rcu(struct hlist_node *n,
                                        struct hlist_node *next)
{
    n->pprev = next->pprev;
    n->next = next;
    __asm__ __volatile__("": : :"memory");
    next->pprev = &n->next;
    *(n->pprev) = n;
}
# 907 "/var/xen-dev/xen/xen/include/xen/list.h"
static __inline__ void hlist_add_after_rcu(struct hlist_node *prev,
                                       struct hlist_node *n)
{
    n->next = prev->next;
    n->pprev = &prev->next;
    __asm__ __volatile__("": : :"memory");
    prev->next = n;
    if (n->next)
        n->next->pprev = &n->next;
}
# 56 "/var/xen-dev/xen/xen/include/xen/mm.h" 2
# 1 "/var/xen-dev/xen/xen/include/xen/spinlock.h" 1





# 1 "/var/xen-dev/xen/xen/include/asm/spinlock.h" 1
# 7 "/var/xen-dev/xen/xen/include/xen/spinlock.h" 2
# 27 "/var/xen-dev/xen/xen/include/xen/spinlock.h"
union lock_debug { };
# 129 "/var/xen-dev/xen/xen/include/xen/spinlock.h"
struct lock_profile_qhead { };
# 141 "/var/xen-dev/xen/xen/include/xen/spinlock.h"
typedef union {
    u32 head_tail;
    struct {
        u16 head;
        u16 tail;
    };
} spinlock_tickets_t;



typedef struct spinlock {
    spinlock_tickets_t tickets;
    u16 recurse_cpu:12;


    u16 recurse_cnt:(16 - 12);

    union lock_debug debug;



} spinlock_t;




void _spin_lock(spinlock_t *lock);
void _spin_lock_cb(spinlock_t *lock, void (*cond)(void *), void *data);
void _spin_lock_irq(spinlock_t *lock);
unsigned long _spin_lock_irqsave(spinlock_t *lock);

void _spin_unlock(spinlock_t *lock);
void _spin_unlock_irq(spinlock_t *lock);
void _spin_unlock_irqrestore(spinlock_t *lock, unsigned long flags);

int _spin_is_locked(spinlock_t *lock);
int _spin_trylock(spinlock_t *lock);
void _spin_barrier(spinlock_t *lock);

int _spin_trylock_recursive(spinlock_t *lock);
void _spin_lock_recursive(spinlock_t *lock);
void _spin_unlock_recursive(spinlock_t *lock);
# 57 "/var/xen-dev/xen/xen/include/xen/mm.h" 2
# 1 "/var/xen-dev/xen/xen/include/xen/typesafe.h" 1
# 58 "/var/xen-dev/xen/xen/include/xen/mm.h" 2

# 1 "/var/xen-dev/xen/xen/include/xen/perfc.h" 1
# 60 "/var/xen-dev/xen/xen/include/xen/mm.h" 2
# 1 "/var/xen-dev/xen/xen/include/public/memory.h" 1
# 61 "/var/xen-dev/xen/xen/include/xen/mm.h" 2

typedef struct { unsigned long mfn; } mfn_t; static __inline__ mfn_t _mfn(unsigned long n) { return (mfn_t) { n }; } static __inline__ unsigned long mfn_x(mfn_t n) { return n.mfn; };
# 80 "/var/xen-dev/xen/xen/include/xen/mm.h"
static __inline__ mfn_t mfn_add(mfn_t mfn, unsigned long i)
{
    return _mfn(mfn_x(mfn) + i);
}

static __inline__ mfn_t mfn_max(mfn_t x, mfn_t y)
{
    return _mfn(({ const typeof(mfn_x(x)) _x = (mfn_x(x)); const typeof(mfn_x(y)) _y = (mfn_x(y)); (void) (&_x == &_y); _x > _y ? _x : _y; }));
}

static __inline__ mfn_t mfn_min(mfn_t x, mfn_t y)
{
    return _mfn(({ const typeof(mfn_x(x)) _x = (mfn_x(x)); const typeof(mfn_x(y)) _y = (mfn_x(y)); (void) (&_x == &_y); _x < _y ? _x : _y; }));
}

static __inline__ bool_t mfn_eq(mfn_t x, mfn_t y)
{
    return mfn_x(x) == mfn_x(y);
}

typedef struct { unsigned long gfn; } gfn_t; static __inline__ gfn_t _gfn(unsigned long n) { return (gfn_t) { n }; } static __inline__ unsigned long gfn_x(gfn_t n) { return n.gfn; };
# 118 "/var/xen-dev/xen/xen/include/xen/mm.h"
static __inline__ gfn_t gfn_add(gfn_t gfn, unsigned long i)
{
    return _gfn(gfn_x(gfn) + i);
}

static __inline__ gfn_t gfn_max(gfn_t x, gfn_t y)
{
    return _gfn(({ const typeof(gfn_x(x)) _x = (gfn_x(x)); const typeof(gfn_x(y)) _y = (gfn_x(y)); (void) (&_x == &_y); _x > _y ? _x : _y; }));
}

static __inline__ gfn_t gfn_min(gfn_t x, gfn_t y)
{
    return _gfn(({ const typeof(gfn_x(x)) _x = (gfn_x(x)); const typeof(gfn_x(y)) _y = (gfn_x(y)); (void) (&_x == &_y); _x < _y ? _x : _y; }));
}

static __inline__ bool_t gfn_eq(gfn_t x, gfn_t y)
{
    return gfn_x(x) == gfn_x(y);
}

typedef struct { unsigned long pfn; } pfn_t; static __inline__ pfn_t _pfn(unsigned long n) { return (pfn_t) { n }; } static __inline__ unsigned long pfn_x(pfn_t n) { return n.pfn; };
# 151 "/var/xen-dev/xen/xen/include/xen/mm.h"
struct page_info;

void put_page(struct page_info *);
int get_page(struct page_info *, struct domain *);
struct domain *__attribute__((__warn_unused_result__)) page_get_owner_and_reference(struct page_info *);


void init_boot_pages(paddr_t ps, paddr_t pe);
mfn_t alloc_boot_pages(unsigned long nr_pfns, unsigned long pfn_align);
void end_boot_allocator(void);


void init_xenheap_pages(paddr_t ps, paddr_t pe);
void xenheap_max_mfn(unsigned long mfn);
void *alloc_xenheap_pages(unsigned int order, unsigned int memflags);
void free_xenheap_pages(void *v, unsigned int order);
_Bool scrub_free_pages(void);
# 179 "/var/xen-dev/xen/xen/include/xen/mm.h"
int map_pages_to_xen(
    unsigned long virt,
    mfn_t mfn,
    unsigned long nr_mfns,
    unsigned int flags);

int modify_xen_mappings(unsigned long s, unsigned long e, unsigned int flags);
int destroy_xen_mappings(unsigned long v, unsigned long e);




int populate_pt_range(unsigned long virt, unsigned long nr_mfns);

unsigned long __attribute__((__warn_unused_result__)) domain_adjust_tot_pages(struct domain *d,
    long pages);
int domain_set_outstanding_pages(struct domain *d, unsigned long pages);
void get_outstanding_claims(uint64_t *free_pages, uint64_t *outstanding_pages);


void init_domheap_pages(paddr_t ps, paddr_t pe);
struct page_info *alloc_domheap_pages(
    struct domain *d, unsigned int order, unsigned int memflags);
void free_domheap_pages(struct page_info *pg, unsigned int order);
unsigned long avail_domheap_pages_region(
    unsigned int node, unsigned int min_width, unsigned int max_width);
unsigned long avail_domheap_pages(void);
unsigned long avail_node_heap_pages(unsigned int);


unsigned int online_page(mfn_t mfn, uint32_t *status);
int offline_page(mfn_t mfn, int broken, uint32_t *status);
int query_page_offline(mfn_t mfn, uint32_t *status);

void heap_init_late(void);

int assign_pages(
    struct domain *d,
    struct page_info *pg,
    unsigned int order,
    unsigned int memflags);


void arch_dump_shared_mem_info(void);





typedef enum {
    npfec_kind_unknown,
    npfec_kind_in_gpt,
    npfec_kind_with_gla
} npfec_kind_t;




struct npfec {
    unsigned int read_access:1;
    unsigned int write_access:1;
    unsigned int insn_fetch:1;
    unsigned int present:1;
    unsigned int gla_valid:1;
    unsigned int kind:2;
};
# 277 "/var/xen-dev/xen/xen/include/xen/mm.h"
extern struct domain *dom_xen, *dom_io;
# 286 "/var/xen-dev/xen/xen/include/xen/mm.h"
# 1 "/var/xen-dev/xen/xen/include/asm/mm.h" 1






# 1 "/var/xen-dev/xen/xen/include/xen/rwlock.h" 1






# 1 "/var/xen-dev/xen/xen/include/asm/atomic.h" 1



# 1 "/var/xen-dev/xen/xen/include/xen/atomic.h" 1
# 25 "/var/xen-dev/xen/xen/include/xen/atomic.h"
typedef struct { int counter; } atomic_t;
# 35 "/var/xen-dev/xen/xen/include/xen/atomic.h"
static __inline__ int atomic_read(const atomic_t *v);







static __inline__ int _atomic_read(atomic_t v);
# 52 "/var/xen-dev/xen/xen/include/xen/atomic.h"
static __inline__ void atomic_set(atomic_t *v, int i);
# 61 "/var/xen-dev/xen/xen/include/xen/atomic.h"
static __inline__ void _atomic_set(atomic_t *v, int i);
# 84 "/var/xen-dev/xen/xen/include/xen/atomic.h"
static __inline__ int atomic_cmpxchg(atomic_t *v, int old, int new);
# 93 "/var/xen-dev/xen/xen/include/xen/atomic.h"
static __inline__ void atomic_add(int i, atomic_t *v);
# 102 "/var/xen-dev/xen/xen/include/xen/atomic.h"
static __inline__ int atomic_add_return(int i, atomic_t *v);
# 111 "/var/xen-dev/xen/xen/include/xen/atomic.h"
static __inline__ void atomic_sub(int i, atomic_t *v);
# 120 "/var/xen-dev/xen/xen/include/xen/atomic.h"
static __inline__ int atomic_sub_return(int i, atomic_t *v);
# 131 "/var/xen-dev/xen/xen/include/xen/atomic.h"
static __inline__ int atomic_sub_and_test(int i, atomic_t *v);







static __inline__ void atomic_inc(atomic_t *v);







static __inline__ int atomic_inc_return(atomic_t *v);
# 157 "/var/xen-dev/xen/xen/include/xen/atomic.h"
static __inline__ int atomic_inc_and_test(atomic_t *v);







static __inline__ void atomic_dec(atomic_t *v);







static __inline__ int atomic_dec_return(atomic_t *v);
# 183 "/var/xen-dev/xen/xen/include/xen/atomic.h"
static __inline__ int atomic_dec_and_test(atomic_t *v);
# 194 "/var/xen-dev/xen/xen/include/xen/atomic.h"
static __inline__ int atomic_add_negative(int i, atomic_t *v);
# 205 "/var/xen-dev/xen/xen/include/xen/atomic.h"
static __inline__ int atomic_add_unless(atomic_t *v, int a, int u);
# 5 "/var/xen-dev/xen/xen/include/asm/atomic.h" 2
# 29 "/var/xen-dev/xen/xen/include/asm/atomic.h"
static __inline__ uint8_t read_u8_atomic(const volatile uint8_t *addr) { uint8_t ret; asm volatile ( "mov" "b" " %1,%0" : "=q" (ret) : "m" (*addr) ); return ret; }
static __inline__ uint16_t read_u16_atomic(const volatile uint16_t *addr) { uint16_t ret; asm volatile ( "mov" "w" " %1,%0" : "=r" (ret) : "m" (*addr) ); return ret; }
static __inline__ uint32_t read_u32_atomic(const volatile uint32_t *addr) { uint32_t ret; asm volatile ( "mov" "l" " %1,%0" : "=r" (ret) : "m" (*addr) ); return ret; }
static __inline__ uint64_t read_u64_atomic(const volatile uint64_t *addr) { uint64_t ret; asm volatile ( "mov" "q" " %1,%0" : "=r" (ret) : "m" (*addr) ); return ret; }

static __inline__ void write_u8_atomic(volatile uint8_t *addr, uint8_t val) { asm volatile ( "mov" "b" " %1,%0" : "=m" (*addr) : "q" (val) ); }
static __inline__ void write_u16_atomic(volatile uint16_t *addr, uint16_t val) { asm volatile ( "mov" "w" " %1,%0" : "=m" (*addr) : "r" (val) ); }
static __inline__ void write_u32_atomic(volatile uint32_t *addr, uint32_t val) { asm volatile ( "mov" "l" " %1,%0" : "=m" (*addr) : "r" (val) ); }
static __inline__ void write_u64_atomic(volatile uint64_t *addr, uint64_t val) { asm volatile ( "mov" "q" " %1,%0" : "=m" (*addr) : "r" (val) ); }

static __inline__ void add_u8_sized(volatile uint8_t *addr, uint8_t val) { asm volatile("add" "b" " %1,%0" : "=m" (*addr) : "qi" (val)); }
static __inline__ void add_u16_sized(volatile uint16_t *addr, uint16_t val) { asm volatile("add" "w" " %1,%0" : "=m" (*addr) : "ri" (val)); }
static __inline__ void add_u32_sized(volatile uint32_t *addr, uint32_t val) { asm volatile("add" "l" " %1,%0" : "=m" (*addr) : "ri" (val)); }
static __inline__ void add_u64_sized(volatile uint64_t *addr, uint64_t val) { asm volatile("add" "q" " %1,%0" : "=m" (*addr) : "ri" (val)); }





void __bad_atomic_size(void);
# 88 "/var/xen-dev/xen/xen/include/asm/atomic.h"
static __inline__ int atomic_read(const atomic_t *v)
{
    return ({ unsigned long x_; switch ( sizeof(*(&v->counter)) ) { case 1: x_ = read_u8_atomic((uint8_t *)(&v->counter)); break; case 2: x_ = read_u16_atomic((uint16_t *)(&v->counter)); break; case 4: x_ = read_u32_atomic((uint32_t *)(&v->counter)); break; case 8: x_ = read_u64_atomic((uint64_t *)(&v->counter)); break; default: x_ = 0; __bad_atomic_size(); break; } (typeof(*(&v->counter)))x_; });
}

static __inline__ int _atomic_read(atomic_t v)
{
    return v.counter;
}

static __inline__ void atomic_set(atomic_t *v, int i)
{
    ({ typeof(*(&v->counter)) __x = (i); unsigned long x_ = (unsigned long)__x; switch ( sizeof(*(&v->counter)) ) { case 1: write_u8_atomic((uint8_t *)(&v->counter), x_); break; case 2: write_u16_atomic((uint16_t *)(&v->counter), x_); break; case 4: write_u32_atomic((uint32_t *)(&v->counter), x_); break; case 8: write_u64_atomic((uint64_t *)(&v->counter), x_); break; default: __bad_atomic_size(); break; } });
}

static __inline__ void _atomic_set(atomic_t *v, int i)
{
    v->counter = i;
}

static __inline__ int atomic_cmpxchg(atomic_t *v, int old, int new)
{
    return ((__typeof__(*(&v->counter)))__cmpxchg((&v->counter),(unsigned long)(old), (unsigned long)(new),sizeof(*(&v->counter))));
}

static __inline__ void atomic_add(int i, atomic_t *v)
{
    asm volatile (
        "lock; addl %1,%0"
        : "=m" (*(volatile int *)&v->counter)
        : "ir" (i), "m" (*(volatile int *)&v->counter) );
}

static __inline__ int atomic_add_return(int i, atomic_t *v)
{
    return i + ((typeof(*(&v->counter)))__xadd(&v->counter, (typeof(*(&v->counter)))(i), sizeof(*(&v->counter))));
}

static __inline__ void atomic_sub(int i, atomic_t *v)
{
    asm volatile (
        "lock; subl %1,%0"
        : "=m" (*(volatile int *)&v->counter)
        : "ir" (i), "m" (*(volatile int *)&v->counter) );
}

static __inline__ int atomic_sub_return(int i, atomic_t *v)
{
    return ((typeof(*(&v->counter)))__xadd(&v->counter, (typeof(*(&v->counter)))(-i), sizeof(*(&v->counter)))) - i;
}

static __inline__ int atomic_sub_and_test(int i, atomic_t *v)
{
    _Bool c;

    asm volatile ( "lock; subl %[i], %[counter]\n\t"
                  
                   : [counter] "+m" (*(volatile int *)&v->counter),
                     [zf] "=@ccz" (c)
                   : [i] "ir" (i) : "memory" );

    return c;
}

static __inline__ void atomic_inc(atomic_t *v)
{
    asm volatile (
        "lock; incl %0"
        : "=m" (*(volatile int *)&v->counter)
        : "m" (*(volatile int *)&v->counter) );
}

static __inline__ int atomic_inc_return(atomic_t *v)
{
    return atomic_add_return(1, v);
}

static __inline__ int atomic_inc_and_test(atomic_t *v)
{
    _Bool c;

    asm volatile ( "lock; incl %[counter]\n\t"
                  
                   : [counter] "+m" (*(volatile int *)&v->counter),
                     [zf] "=@ccz" (c)
                   :: "memory" );

    return c;
}

static __inline__ void atomic_dec(atomic_t *v)
{
    asm volatile (
        "lock; decl %0"
        : "=m" (*(volatile int *)&v->counter)
        : "m" (*(volatile int *)&v->counter) );
}

static __inline__ int atomic_dec_return(atomic_t *v)
{
    return atomic_sub_return(1, v);
}

static __inline__ int atomic_dec_and_test(atomic_t *v)
{
    _Bool c;

    asm volatile ( "lock; decl %[counter]\n\t"
                  
                   : [counter] "+m" (*(volatile int *)&v->counter),
                     [zf] "=@ccz" (c)
                   :: "memory" );

    return c;
}

static __inline__ int atomic_add_negative(int i, atomic_t *v)
{
    _Bool c;

    asm volatile ( "lock; addl %[i], %[counter]\n\t"
                  
                   : [counter] "+m" (*(volatile int *)&v->counter),
                     [sf] "=@ccs" (c)
                   : [i] "ir" (i) : "memory" );

    return c;
}

static __inline__ int atomic_add_unless(atomic_t *v, int a, int u)
{
    int c, old;

    c = atomic_read(v);
    while (c != u && (old = atomic_cmpxchg(v, c, c + a)) != c)
        c = old;
    return c;
}
# 8 "/var/xen-dev/xen/xen/include/xen/rwlock.h" 2


typedef struct {
    atomic_t cnts;
    spinlock_t lock;
} rwlock_t;
# 35 "/var/xen-dev/xen/xen/include/xen/rwlock.h"
void queue_read_lock_slowpath(rwlock_t *lock);
void queue_write_lock_slowpath(rwlock_t *lock);






static __inline__ int _read_trylock(rwlock_t *lock)
{
    u32 cnts;

    cnts = atomic_read(&lock->cnts);
    if ( __builtin_expect(!!(!(cnts & 0xff)),1) )
    {
        cnts = (u32)atomic_add_return((1U << 8), &lock->cnts);
        if ( __builtin_expect(!!(!(cnts & 0xff)),1) )
            return 1;
        atomic_sub((1U << 8), &lock->cnts);
    }
    return 0;
}





static __inline__ void _read_lock(rwlock_t *lock)
{
    u32 cnts;

    cnts = atomic_add_return((1U << 8), &lock->cnts);
    if ( __builtin_expect(!!(!(cnts & 0xff)),1) )
        return;


    queue_read_lock_slowpath(lock);
}

static __inline__ void _read_lock_irq(rwlock_t *lock)
{
    do { if ( __builtin_expect(!!(!(local_irq_is_enabled())),0) ) do { do { ({ _Static_assert(!((76) >> ((31 - 24) + (31 - 24))), "!(" "(76) >> (BUG_LINE_LO_WIDTH + BUG_LINE_HI_WIDTH)" ")"); }); ({ _Static_assert(!((3) >= 4), "!(" "(3) >= BUGFRAME_NR" ")"); }); asm volatile ( ".Lbug%=: ud2\n" ".pushsection .bug_frames.%c[bf_type], \"a\", @progbits\n" ".p2align 2\n" ".Lfrm%=:\n" ".long (.Lbug%= - .Lfrm%=) + %c[bf_line_hi]\n" ".long (%c[bf_ptr] - .Lfrm%=) + %c[bf_line_lo]\n" ".if " "1" "\n" ".long 0, %c[bf_msg] - .Lfrm%=\n" ".endif\n" ".popsection\n" :: [bf_type] "i" (3), [bf_ptr] "i" ("/var/xen-dev/xen/xen/include/xen/rwlock.h"), [bf_msg] "i" ("local_irq_is_enabled()"), [bf_line_lo] "i" ((76 & ((1 << (31 - 24)) - 1)) << 24), [bf_line_hi] "i" (((76) >> (31 - 24)) << 24) ); } while (0); __builtin_unreachable(); } while (0); } while (0);
    asm volatile ( "cli" : : : "memory" );
    _read_lock(lock);
}

static __inline__ unsigned long _read_lock_irqsave(rwlock_t *lock)
{
    unsigned long flags;
    ({ ({ ({ _Static_assert(!(sizeof(flags) != sizeof(long)), "!(" "sizeof(flags) != sizeof(long)" ")"); }); asm volatile ( "pushf" __OS " ; pop" __OS " %0" : "=g" (flags)); }); asm volatile ( "cli" : : : "memory" ); });
    _read_lock(lock);
    return flags;
}





static __inline__ void _read_unlock(rwlock_t *lock)
{



    atomic_sub((1U << 8), &lock->cnts);
}

static __inline__ void _read_unlock_irq(rwlock_t *lock)
{
    _read_unlock(lock);
    asm volatile ( "sti" : : : "memory" );
}

static __inline__ void _read_unlock_irqrestore(rwlock_t *lock, unsigned long flags)
{
    _read_unlock(lock);
    ({ ({ _Static_assert(!(sizeof(flags) != sizeof(long)), "!(" "sizeof(flags) != sizeof(long)" ")"); }); asm volatile ( "pushfq\n\t" "andq %0, (%%rsp)\n\t" "orq  %1, (%%rsp)\n\t" "popfq" : : "i?r" ( ~0x00000200 ), "ri" ( (flags) & 0x00000200 ) ); });
}

static __inline__ int _rw_is_locked(rwlock_t *lock)
{
    return atomic_read(&lock->cnts);
}





static __inline__ void _write_lock(rwlock_t *lock)
{

    if ( atomic_cmpxchg(&lock->cnts, 0, 0xff) == 0 )
        return;

    queue_write_lock_slowpath(lock);
}

static __inline__ void _write_lock_irq(rwlock_t *lock)
{
    do { if ( __builtin_expect(!!(!(local_irq_is_enabled())),0) ) do { do { ({ _Static_assert(!((133) >> ((31 - 24) + (31 - 24))), "!(" "(133) >> (BUG_LINE_LO_WIDTH + BUG_LINE_HI_WIDTH)" ")"); }); ({ _Static_assert(!((3) >= 4), "!(" "(3) >= BUGFRAME_NR" ")"); }); asm volatile ( ".Lbug%=: ud2\n" ".pushsection .bug_frames.%c[bf_type], \"a\", @progbits\n" ".p2align 2\n" ".Lfrm%=:\n" ".long (.Lbug%= - .Lfrm%=) + %c[bf_line_hi]\n" ".long (%c[bf_ptr] - .Lfrm%=) + %c[bf_line_lo]\n" ".if " "1" "\n" ".long 0, %c[bf_msg] - .Lfrm%=\n" ".endif\n" ".popsection\n" :: [bf_type] "i" (3), [bf_ptr] "i" ("/var/xen-dev/xen/xen/include/xen/rwlock.h"), [bf_msg] "i" ("local_irq_is_enabled()"), [bf_line_lo] "i" ((133 & ((1 << (31 - 24)) - 1)) << 24), [bf_line_hi] "i" (((133) >> (31 - 24)) << 24) ); } while (0); __builtin_unreachable(); } while (0); } while (0);
    asm volatile ( "cli" : : : "memory" );
    _write_lock(lock);
}

static __inline__ unsigned long _write_lock_irqsave(rwlock_t *lock)
{
    unsigned long flags;

    ({ ({ ({ _Static_assert(!(sizeof(flags) != sizeof(long)), "!(" "sizeof(flags) != sizeof(long)" ")"); }); asm volatile ( "pushf" __OS " ; pop" __OS " %0" : "=g" (flags)); }); asm volatile ( "cli" : : : "memory" ); });
    _write_lock(lock);
    return flags;
}






static __inline__ int _write_trylock(rwlock_t *lock)
{
    u32 cnts;

    cnts = atomic_read(&lock->cnts);
    if ( __builtin_expect(!!(cnts),0) )
        return 0;

    return __builtin_expect(!!(atomic_cmpxchg(&lock->cnts, 0, 0xff) == 0),1);
}

static __inline__ void _write_unlock(rwlock_t *lock)
{




    atomic_sub(0xff, &lock->cnts);
}

static __inline__ void _write_unlock_irq(rwlock_t *lock)
{
    _write_unlock(lock);
    asm volatile ( "sti" : : : "memory" );
}

static __inline__ void _write_unlock_irqrestore(rwlock_t *lock, unsigned long flags)
{
    _write_unlock(lock);
    ({ ({ _Static_assert(!(sizeof(flags) != sizeof(long)), "!(" "sizeof(flags) != sizeof(long)" ")"); }); asm volatile ( "pushfq\n\t" "andq %0, (%%rsp)\n\t" "orq  %1, (%%rsp)\n\t" "popfq" : : "i?r" ( ~0x00000200 ), "ri" ( (flags) & 0x00000200 ) ); });
}

static __inline__ int _rw_is_write_locked(rwlock_t *lock)
{
    return (atomic_read(&lock->cnts) & 0xff) == 0xff;
}
# 219 "/var/xen-dev/xen/xen/include/xen/rwlock.h"
typedef struct percpu_rwlock percpu_rwlock_t;

struct percpu_rwlock {
    rwlock_t rwlock;
    bool_t writer_activating;

    percpu_rwlock_t **percpu_owner;

};



static __inline__ void _percpu_rwlock_owner_check(percpu_rwlock_t **per_cpudata,
                                         percpu_rwlock_t *percpu_rwlock)
{
    do { if ( __builtin_expect(!!(!(per_cpudata == percpu_rwlock->percpu_owner)),0) ) do { do { ({ _Static_assert(!((234) >> ((31 - 24) + (31 - 24))), "!(" "(234) >> (BUG_LINE_LO_WIDTH + BUG_LINE_HI_WIDTH)" ")"); }); ({ _Static_assert(!((3) >= 4), "!(" "(3) >= BUGFRAME_NR" ")"); }); asm volatile ( ".Lbug%=: ud2\n" ".pushsection .bug_frames.%c[bf_type], \"a\", @progbits\n" ".p2align 2\n" ".Lfrm%=:\n" ".long (.Lbug%= - .Lfrm%=) + %c[bf_line_hi]\n" ".long (%c[bf_ptr] - .Lfrm%=) + %c[bf_line_lo]\n" ".if " "1" "\n" ".long 0, %c[bf_msg] - .Lfrm%=\n" ".endif\n" ".popsection\n" :: [bf_type] "i" (3), [bf_ptr] "i" ("/var/xen-dev/xen/xen/include/xen/rwlock.h"), [bf_msg] "i" ("per_cpudata == percpu_rwlock->percpu_owner"), [bf_line_lo] "i" ((234 & ((1 << (31 - 24)) - 1)) << 24), [bf_line_hi] "i" (((234) >> (31 - 24)) << 24) ); } while (0); __builtin_unreachable(); } while (0); } while (0);
}
# 246 "/var/xen-dev/xen/xen/include/xen/rwlock.h"
static __inline__ void _percpu_read_lock(percpu_rwlock_t **per_cpudata,
                                         percpu_rwlock_t *percpu_rwlock)
{

    _percpu_rwlock_owner_check(per_cpudata, percpu_rwlock);


    do { if ( __builtin_expect(!!(!((*({ unsigned long __ptr; __asm__ ("" : "=r"(__ptr) : "0"(per_cpudata)); (typeof(per_cpudata)) (__ptr + (get_cpu_info()->per_cpu_offset)); })) != percpu_rwlock)),0) ) do { do { ({ _Static_assert(!((253) >> ((31 - 24) + (31 - 24))), "!(" "(253) >> (BUG_LINE_LO_WIDTH + BUG_LINE_HI_WIDTH)" ")"); }); ({ _Static_assert(!((3) >= 4), "!(" "(3) >= BUGFRAME_NR" ")"); }); asm volatile ( ".Lbug%=: ud2\n" ".pushsection .bug_frames.%c[bf_type], \"a\", @progbits\n" ".p2align 2\n" ".Lfrm%=:\n" ".long (.Lbug%= - .Lfrm%=) + %c[bf_line_hi]\n" ".long (%c[bf_ptr] - .Lfrm%=) + %c[bf_line_lo]\n" ".if " "1" "\n" ".long 0, %c[bf_msg] - .Lfrm%=\n" ".endif\n" ".popsection\n" :: [bf_type] "i" (3), [bf_ptr] "i" ("/var/xen-dev/xen/xen/include/xen/rwlock.h"), [bf_msg] "i" ("this_cpu_ptr(per_cpudata) != percpu_rwlock"), [bf_line_lo] "i" ((253 & ((1 << (31 - 24)) - 1)) << 24), [bf_line_hi] "i" (((253) >> (31 - 24)) << 24) ); } while (0); __builtin_unreachable(); } while (0); } while (0);




    if ( __builtin_expect(!!((*({ unsigned long __ptr; __asm__ ("" : "=r"(__ptr) : "0"(per_cpudata)); (typeof(per_cpudata)) (__ptr + (get_cpu_info()->per_cpu_offset)); })) != ((void*)0)),0) )
    {
        _read_lock(&percpu_rwlock->rwlock);
        return;
    }


    (*({ unsigned long __ptr; __asm__ ("" : "=r"(__ptr) : "0"(per_cpudata)); (typeof(per_cpudata)) (__ptr + (get_cpu_info()->per_cpu_offset)); })) = percpu_rwlock;
    asm volatile ( "mfence" ::: "memory" );

    if ( __builtin_expect(!!(percpu_rwlock->writer_activating),0) )
    {

        (*({ unsigned long __ptr; __asm__ ("" : "=r"(__ptr) : "0"(per_cpudata)); (typeof(per_cpudata)) (__ptr + (get_cpu_info()->per_cpu_offset)); })) = ((void*)0);

        _read_lock(&percpu_rwlock->rwlock);

        (*({ unsigned long __ptr; __asm__ ("" : "=r"(__ptr) : "0"(per_cpudata)); (typeof(per_cpudata)) (__ptr + (get_cpu_info()->per_cpu_offset)); })) = percpu_rwlock;

        _read_unlock(&percpu_rwlock->rwlock);
    }
}

static __inline__ void _percpu_read_unlock(percpu_rwlock_t **per_cpudata,
                percpu_rwlock_t *percpu_rwlock)
{

    _percpu_rwlock_owner_check(per_cpudata, percpu_rwlock);


    do { if ( __builtin_expect(!!(!((*({ unsigned long __ptr; __asm__ ("" : "=r"(__ptr) : "0"(per_cpudata)); (typeof(per_cpudata)) (__ptr + (get_cpu_info()->per_cpu_offset)); })) != ((void*)0))),0) ) do { do { ({ _Static_assert(!((288) >> ((31 - 24) + (31 - 24))), "!(" "(288) >> (BUG_LINE_LO_WIDTH + BUG_LINE_HI_WIDTH)" ")"); }); ({ _Static_assert(!((3) >= 4), "!(" "(3) >= BUGFRAME_NR" ")"); }); asm volatile ( ".Lbug%=: ud2\n" ".pushsection .bug_frames.%c[bf_type], \"a\", @progbits\n" ".p2align 2\n" ".Lfrm%=:\n" ".long (.Lbug%= - .Lfrm%=) + %c[bf_line_hi]\n" ".long (%c[bf_ptr] - .Lfrm%=) + %c[bf_line_lo]\n" ".if " "1" "\n" ".long 0, %c[bf_msg] - .Lfrm%=\n" ".endif\n" ".popsection\n" :: [bf_type] "i" (3), [bf_ptr] "i" ("/var/xen-dev/xen/xen/include/xen/rwlock.h"), [bf_msg] "i" ("this_cpu_ptr(per_cpudata) != NULL"), [bf_line_lo] "i" ((288 & ((1 << (31 - 24)) - 1)) << 24), [bf_line_hi] "i" (((288) >> (31 - 24)) << 24) ); } while (0); __builtin_unreachable(); } while (0); } while (0);




    if ( __builtin_expect(!!((*({ unsigned long __ptr; __asm__ ("" : "=r"(__ptr) : "0"(per_cpudata)); (typeof(per_cpudata)) (__ptr + (get_cpu_info()->per_cpu_offset)); })) != percpu_rwlock),0) )
    {
        _read_unlock(&percpu_rwlock->rwlock);
        return;
    }
    (*({ unsigned long __ptr; __asm__ ("" : "=r"(__ptr) : "0"(per_cpudata)); (typeof(per_cpudata)) (__ptr + (get_cpu_info()->per_cpu_offset)); })) = ((void*)0);
    __asm__ __volatile__("": : :"memory");
}


void _percpu_write_lock(percpu_rwlock_t **per_cpudata,
                        percpu_rwlock_t *percpu_rwlock);

static __inline__ void _percpu_write_unlock(percpu_rwlock_t **per_cpudata,
                percpu_rwlock_t *percpu_rwlock)
{

    _percpu_rwlock_owner_check(per_cpudata, percpu_rwlock);

    do { if ( __builtin_expect(!!(!(percpu_rwlock->writer_activating)),0) ) do { do { ({ _Static_assert(!((312) >> ((31 - 24) + (31 - 24))), "!(" "(312) >> (BUG_LINE_LO_WIDTH + BUG_LINE_HI_WIDTH)" ")"); }); ({ _Static_assert(!((3) >= 4), "!(" "(3) >= BUGFRAME_NR" ")"); }); asm volatile ( ".Lbug%=: ud2\n" ".pushsection .bug_frames.%c[bf_type], \"a\", @progbits\n" ".p2align 2\n" ".Lfrm%=:\n" ".long (.Lbug%= - .Lfrm%=) + %c[bf_line_hi]\n" ".long (%c[bf_ptr] - .Lfrm%=) + %c[bf_line_lo]\n" ".if " "1" "\n" ".long 0, %c[bf_msg] - .Lfrm%=\n" ".endif\n" ".popsection\n" :: [bf_type] "i" (3), [bf_ptr] "i" ("/var/xen-dev/xen/xen/include/xen/rwlock.h"), [bf_msg] "i" ("percpu_rwlock->writer_activating"), [bf_line_lo] "i" ((312 & ((1 << (31 - 24)) - 1)) << 24), [bf_line_hi] "i" (((312) >> (31 - 24)) << 24) ); } while (0); __builtin_unreachable(); } while (0); } while (0);
    percpu_rwlock->writer_activating = 0;
    _write_unlock(&percpu_rwlock->rwlock);
}
# 8 "/var/xen-dev/xen/xen/include/asm/mm.h" 2
# 1 "/var/xen-dev/xen/xen/include/asm/io.h" 1



# 1 "/var/xen-dev/xen/xen/include/xen/vmap.h" 1
# 5 "/var/xen-dev/xen/xen/include/asm/io.h" 2
# 38 "/var/xen-dev/xen/xen/include/asm/io.h"
static __inline__ unsigned char inb(unsigned short port) { unsigned char _v; __asm__ __volatile__ ("in" "b" " %" "w" "1,%" "" "0" : "=a" (_v) : "Nd" (port) ); return _v; } static __inline__ unsigned char inb_p(unsigned short port) { unsigned char _v; __asm__ __volatile__ ("in" "b" " %" "w" "1,%" "" "0" : "=a" (_v) : "Nd" (port) ); return _v; }


static __inline__ unsigned short inw(unsigned short port) { unsigned short _v; __asm__ __volatile__ ("in" "w" " %" "w" "1,%" "" "0" : "=a" (_v) : "Nd" (port) ); return _v; } static __inline__ unsigned short inw_p(unsigned short port) { unsigned short _v; __asm__ __volatile__ ("in" "w" " %" "w" "1,%" "" "0" : "=a" (_v) : "Nd" (port) ); return _v; }


static __inline__ unsigned int inl(unsigned short port) { unsigned int _v; __asm__ __volatile__ ("in" "l" " %" "w" "1,%" "" "0" : "=a" (_v) : "Nd" (port) ); return _v; } static __inline__ unsigned int inl_p(unsigned short port) { unsigned int _v; __asm__ __volatile__ ("in" "l" " %" "w" "1,%" "" "0" : "=a" (_v) : "Nd" (port) ); return _v; }


static __inline__ void outb(unsigned char value, unsigned short port) { __asm__ __volatile__ ("out" "b" " %" "b" "0,%" "w" "1" : : "a" (value), "Nd" (port)); } static __inline__ void outb_p(unsigned char value, unsigned short port) { __asm__ __volatile__ ("out" "b" " %" "b" "0,%" "w" "1" : : "a" (value), "Nd" (port));}
static __inline__ void outw(unsigned short value, unsigned short port) { __asm__ __volatile__ ("out" "w" " %" "w" "0,%" "w" "1" : : "a" (value), "Nd" (port)); } static __inline__ void outw_p(unsigned short value, unsigned short port) { __asm__ __volatile__ ("out" "w" " %" "w" "0,%" "w" "1" : : "a" (value), "Nd" (port));}
static __inline__ void outl(unsigned int value, unsigned short port) { __asm__ __volatile__ ("out" "l" " %" "0,%" "w" "1" : : "a" (value), "Nd" (port)); } static __inline__ void outl_p(unsigned int value, unsigned short port) { __asm__ __volatile__ ("out" "l" " %" "0,%" "w" "1" : : "a" (value), "Nd" (port));}



extern _Bool (*ioemul_handle_quirk)(
    u8 opcode, char *io_emul_stub, struct cpu_user_regs *regs);
# 9 "/var/xen-dev/xen/xen/include/asm/mm.h" 2
# 1 "/var/xen-dev/xen/xen/include/asm/uaccess.h" 1
# 11 "/var/xen-dev/xen/xen/include/asm/uaccess.h"
# 1 "/var/xen-dev/xen/xen/include/asm/x86_64/uaccess.h" 1





struct vcpu;
int setup_compat_arg_xlat(struct vcpu *v);
void free_compat_arg_xlat(struct vcpu *v);
# 25 "/var/xen-dev/xen/xen/include/asm/x86_64/uaccess.h"
extern void *xlat_malloc(unsigned long *xlat_page_current, size_t size);
# 12 "/var/xen-dev/xen/xen/include/asm/uaccess.h" 2

unsigned copy_to_user(void *to, const void *from, unsigned len);
unsigned clear_user(void *to, unsigned len);
unsigned copy_from_user(void *to, const void *from, unsigned len);

unsigned __copy_to_user_ll(void __user*to, const void *from, unsigned n);
unsigned __copy_from_user_ll(void *to, const void __user *from, unsigned n);

extern long __get_user_bad(void);
extern void __put_user_bad(void);
# 137 "/var/xen-dev/xen/xen/include/asm/uaccess.h"
struct __large_struct { unsigned long buf[100]; };
# 188 "/var/xen-dev/xen/xen/include/asm/uaccess.h"
static __inline__ __attribute__ ((__always_inline__)) unsigned long
__copy_to_user(void __user *to, const void *from, unsigned long n)
{
    if (__builtin_constant_p(n)) {
        unsigned long ret;

        switch (n) {
        case 1:
            do { ret = 0; switch (1) { case 1: stac(); __asm__ __volatile__( "1:	mov""b"" %""b""1,%2\n" "2:\n" ".section .fixup,\"ax\"\n" "3:	mov %3,%0\n" "	jmp 2b\n" ".previous\n" " .section .ex_table" "" ",\"a\"\n" " .balign 4\n" " .long " "1b" "-." ", " "3b" "-." "\n" " .previous\n" : "=r"(ret) : "iq" (*(const u8 *)from), "m"((*(const struct __large_struct *)((u8 __user *)to))), "i"(1), "0"(ret)); clac();break; case 2: stac(); __asm__ __volatile__( "1:	mov""w"" %""w""1,%2\n" "2:\n" ".section .fixup,\"ax\"\n" "3:	mov %3,%0\n" "	jmp 2b\n" ".previous\n" " .section .ex_table" "" ",\"a\"\n" " .balign 4\n" " .long " "1b" "-." ", " "3b" "-." "\n" " .previous\n" : "=r"(ret) : "ir" (*(const u8 *)from), "m"((*(const struct __large_struct *)((u8 __user *)to))), "i"(1), "0"(ret)); clac();break; case 4: stac(); __asm__ __volatile__( "1:	mov""l"" %""k""1,%2\n" "2:\n" ".section .fixup,\"ax\"\n" "3:	mov %3,%0\n" "	jmp 2b\n" ".previous\n" " .section .ex_table" "" ",\"a\"\n" " .balign 4\n" " .long " "1b" "-." ", " "3b" "-." "\n" " .previous\n" : "=r"(ret) : "ir" (*(const u8 *)from), "m"((*(const struct __large_struct *)((u8 __user *)to))), "i"(1), "0"(ret)); clac();break; case 8: stac(); __asm__ __volatile__( "1:	mov""q"" %""""1,%2\n" "2:\n" ".section .fixup,\"ax\"\n" "3:	mov %3,%0\n" "	jmp 2b\n" ".previous\n" " .section .ex_table" "" ",\"a\"\n" " .balign 4\n" " .long " "1b" "-." ", " "3b" "-." "\n" " .previous\n" : "=r"(ret) : "ir" (*(const u8 *)from), "m"((*(const struct __large_struct *)((u8 __user *)to))), "i"(1), "0"(ret)); clac();break; default: __put_user_bad(); } } while (0);
            return ret;
        case 2:
            do { ret = 0; switch (2) { case 1: stac(); __asm__ __volatile__( "1:	mov""b"" %""b""1,%2\n" "2:\n" ".section .fixup,\"ax\"\n" "3:	mov %3,%0\n" "	jmp 2b\n" ".previous\n" " .section .ex_table" "" ",\"a\"\n" " .balign 4\n" " .long " "1b" "-." ", " "3b" "-." "\n" " .previous\n" : "=r"(ret) : "iq" (*(const u16 *)from), "m"((*(const struct __large_struct *)((u16 __user *)to))), "i"(2), "0"(ret)); clac();break; case 2: stac(); __asm__ __volatile__( "1:	mov""w"" %""w""1,%2\n" "2:\n" ".section .fixup,\"ax\"\n" "3:	mov %3,%0\n" "	jmp 2b\n" ".previous\n" " .section .ex_table" "" ",\"a\"\n" " .balign 4\n" " .long " "1b" "-." ", " "3b" "-." "\n" " .previous\n" : "=r"(ret) : "ir" (*(const u16 *)from), "m"((*(const struct __large_struct *)((u16 __user *)to))), "i"(2), "0"(ret)); clac();break; case 4: stac(); __asm__ __volatile__( "1:	mov""l"" %""k""1,%2\n" "2:\n" ".section .fixup,\"ax\"\n" "3:	mov %3,%0\n" "	jmp 2b\n" ".previous\n" " .section .ex_table" "" ",\"a\"\n" " .balign 4\n" " .long " "1b" "-." ", " "3b" "-." "\n" " .previous\n" : "=r"(ret) : "ir" (*(const u16 *)from), "m"((*(const struct __large_struct *)((u16 __user *)to))), "i"(2), "0"(ret)); clac();break; case 8: stac(); __asm__ __volatile__( "1:	mov""q"" %""""1,%2\n" "2:\n" ".section .fixup,\"ax\"\n" "3:	mov %3,%0\n" "	jmp 2b\n" ".previous\n" " .section .ex_table" "" ",\"a\"\n" " .balign 4\n" " .long " "1b" "-." ", " "3b" "-." "\n" " .previous\n" : "=r"(ret) : "ir" (*(const u16 *)from), "m"((*(const struct __large_struct *)((u16 __user *)to))), "i"(2), "0"(ret)); clac();break; default: __put_user_bad(); } } while (0);
            return ret;
        case 4:
            do { ret = 0; switch (4) { case 1: stac(); __asm__ __volatile__( "1:	mov""b"" %""b""1,%2\n" "2:\n" ".section .fixup,\"ax\"\n" "3:	mov %3,%0\n" "	jmp 2b\n" ".previous\n" " .section .ex_table" "" ",\"a\"\n" " .balign 4\n" " .long " "1b" "-." ", " "3b" "-." "\n" " .previous\n" : "=r"(ret) : "iq" (*(const u32 *)from), "m"((*(const struct __large_struct *)((u32 __user *)to))), "i"(4), "0"(ret)); clac();break; case 2: stac(); __asm__ __volatile__( "1:	mov""w"" %""w""1,%2\n" "2:\n" ".section .fixup,\"ax\"\n" "3:	mov %3,%0\n" "	jmp 2b\n" ".previous\n" " .section .ex_table" "" ",\"a\"\n" " .balign 4\n" " .long " "1b" "-." ", " "3b" "-." "\n" " .previous\n" : "=r"(ret) : "ir" (*(const u32 *)from), "m"((*(const struct __large_struct *)((u32 __user *)to))), "i"(4), "0"(ret)); clac();break; case 4: stac(); __asm__ __volatile__( "1:	mov""l"" %""k""1,%2\n" "2:\n" ".section .fixup,\"ax\"\n" "3:	mov %3,%0\n" "	jmp 2b\n" ".previous\n" " .section .ex_table" "" ",\"a\"\n" " .balign 4\n" " .long " "1b" "-." ", " "3b" "-." "\n" " .previous\n" : "=r"(ret) : "ir" (*(const u32 *)from), "m"((*(const struct __large_struct *)((u32 __user *)to))), "i"(4), "0"(ret)); clac();break; case 8: stac(); __asm__ __volatile__( "1:	mov""q"" %""""1,%2\n" "2:\n" ".section .fixup,\"ax\"\n" "3:	mov %3,%0\n" "	jmp 2b\n" ".previous\n" " .section .ex_table" "" ",\"a\"\n" " .balign 4\n" " .long " "1b" "-." ", " "3b" "-." "\n" " .previous\n" : "=r"(ret) : "ir" (*(const u32 *)from), "m"((*(const struct __large_struct *)((u32 __user *)to))), "i"(4), "0"(ret)); clac();break; default: __put_user_bad(); } } while (0);
            return ret;
        case 8:
            do { ret = 0; switch (8) { case 1: stac(); __asm__ __volatile__( "1:	mov""b"" %""b""1,%2\n" "2:\n" ".section .fixup,\"ax\"\n" "3:	mov %3,%0\n" "	jmp 2b\n" ".previous\n" " .section .ex_table" "" ",\"a\"\n" " .balign 4\n" " .long " "1b" "-." ", " "3b" "-." "\n" " .previous\n" : "=r"(ret) : "iq" (*(const u64 *)from), "m"((*(const struct __large_struct *)((u64 __user *)to))), "i"(8), "0"(ret)); clac();break; case 2: stac(); __asm__ __volatile__( "1:	mov""w"" %""w""1,%2\n" "2:\n" ".section .fixup,\"ax\"\n" "3:	mov %3,%0\n" "	jmp 2b\n" ".previous\n" " .section .ex_table" "" ",\"a\"\n" " .balign 4\n" " .long " "1b" "-." ", " "3b" "-." "\n" " .previous\n" : "=r"(ret) : "ir" (*(const u64 *)from), "m"((*(const struct __large_struct *)((u64 __user *)to))), "i"(8), "0"(ret)); clac();break; case 4: stac(); __asm__ __volatile__( "1:	mov""l"" %""k""1,%2\n" "2:\n" ".section .fixup,\"ax\"\n" "3:	mov %3,%0\n" "	jmp 2b\n" ".previous\n" " .section .ex_table" "" ",\"a\"\n" " .balign 4\n" " .long " "1b" "-." ", " "3b" "-." "\n" " .previous\n" : "=r"(ret) : "ir" (*(const u64 *)from), "m"((*(const struct __large_struct *)((u64 __user *)to))), "i"(8), "0"(ret)); clac();break; case 8: stac(); __asm__ __volatile__( "1:	mov""q"" %""""1,%2\n" "2:\n" ".section .fixup,\"ax\"\n" "3:	mov %3,%0\n" "	jmp 2b\n" ".previous\n" " .section .ex_table" "" ",\"a\"\n" " .balign 4\n" " .long " "1b" "-." ", " "3b" "-." "\n" " .previous\n" : "=r"(ret) : "ir" (*(const u64 *)from), "m"((*(const struct __large_struct *)((u64 __user *)to))), "i"(8), "0"(ret)); clac();break; default: __put_user_bad(); } } while (0);
            return ret;
        }
    }
    return __copy_to_user_ll(to, from, n);
}
# 229 "/var/xen-dev/xen/xen/include/asm/uaccess.h"
static __inline__ __attribute__ ((__always_inline__)) unsigned long
__copy_from_user(void *to, const void __user *from, unsigned long n)
{
    if (__builtin_constant_p(n)) {
        unsigned long ret;

        switch (n) {
        case 1:
            do { ret = 0; switch (1) { case 1: stac(); __asm__ __volatile__( "1:	mov""b"" %2,%""b""1\n" "2:\n" ".section .fixup,\"ax\"\n" "3:	mov %3,%0\n" "	xor""b"" %""b""1,%""b""1\n" "	jmp 2b\n" ".previous\n" " .section .ex_table" "" ",\"a\"\n" " .balign 4\n" " .long " "1b" "-." ", " "3b" "-." "\n" " .previous\n" : "=r"(ret), "=q" (*(u8 *)to) : "m"((*(const struct __large_struct *)(from))), "i"(1), "0"(ret)); clac();break; case 2: stac(); __asm__ __volatile__( "1:	mov""w"" %2,%""w""1\n" "2:\n" ".section .fixup,\"ax\"\n" "3:	mov %3,%0\n" "	xor""w"" %""w""1,%""w""1\n" "	jmp 2b\n" ".previous\n" " .section .ex_table" "" ",\"a\"\n" " .balign 4\n" " .long " "1b" "-." ", " "3b" "-." "\n" " .previous\n" : "=r"(ret), "=r" (*(u8 *)to) : "m"((*(const struct __large_struct *)(from))), "i"(1), "0"(ret)); clac();break; case 4: stac(); __asm__ __volatile__( "1:	mov""l"" %2,%""k""1\n" "2:\n" ".section .fixup,\"ax\"\n" "3:	mov %3,%0\n" "	xor""l"" %""k""1,%""k""1\n" "	jmp 2b\n" ".previous\n" " .section .ex_table" "" ",\"a\"\n" " .balign 4\n" " .long " "1b" "-." ", " "3b" "-." "\n" " .previous\n" : "=r"(ret), "=r" (*(u8 *)to) : "m"((*(const struct __large_struct *)(from))), "i"(1), "0"(ret)); clac();break; case 8: stac(); __asm__ __volatile__( "1:	mov""q"" %2,%""""1\n" "2:\n" ".section .fixup,\"ax\"\n" "3:	mov %3,%0\n" "	xor""q"" %""""1,%""""1\n" "	jmp 2b\n" ".previous\n" " .section .ex_table" "" ",\"a\"\n" " .balign 4\n" " .long " "1b" "-." ", " "3b" "-." "\n" " .previous\n" : "=r"(ret), "=r" (*(u8 *)to) : "m"((*(const struct __large_struct *)(from))), "i"(1), "0"(ret)); clac(); break; default: __get_user_bad(); } } while (0);
            return ret;
        case 2:
            do { ret = 0; switch (2) { case 1: stac(); __asm__ __volatile__( "1:	mov""b"" %2,%""b""1\n" "2:\n" ".section .fixup,\"ax\"\n" "3:	mov %3,%0\n" "	xor""b"" %""b""1,%""b""1\n" "	jmp 2b\n" ".previous\n" " .section .ex_table" "" ",\"a\"\n" " .balign 4\n" " .long " "1b" "-." ", " "3b" "-." "\n" " .previous\n" : "=r"(ret), "=q" (*(u16 *)to) : "m"((*(const struct __large_struct *)(from))), "i"(2), "0"(ret)); clac();break; case 2: stac(); __asm__ __volatile__( "1:	mov""w"" %2,%""w""1\n" "2:\n" ".section .fixup,\"ax\"\n" "3:	mov %3,%0\n" "	xor""w"" %""w""1,%""w""1\n" "	jmp 2b\n" ".previous\n" " .section .ex_table" "" ",\"a\"\n" " .balign 4\n" " .long " "1b" "-." ", " "3b" "-." "\n" " .previous\n" : "=r"(ret), "=r" (*(u16 *)to) : "m"((*(const struct __large_struct *)(from))), "i"(2), "0"(ret)); clac();break; case 4: stac(); __asm__ __volatile__( "1:	mov""l"" %2,%""k""1\n" "2:\n" ".section .fixup,\"ax\"\n" "3:	mov %3,%0\n" "	xor""l"" %""k""1,%""k""1\n" "	jmp 2b\n" ".previous\n" " .section .ex_table" "" ",\"a\"\n" " .balign 4\n" " .long " "1b" "-." ", " "3b" "-." "\n" " .previous\n" : "=r"(ret), "=r" (*(u16 *)to) : "m"((*(const struct __large_struct *)(from))), "i"(2), "0"(ret)); clac();break; case 8: stac(); __asm__ __volatile__( "1:	mov""q"" %2,%""""1\n" "2:\n" ".section .fixup,\"ax\"\n" "3:	mov %3,%0\n" "	xor""q"" %""""1,%""""1\n" "	jmp 2b\n" ".previous\n" " .section .ex_table" "" ",\"a\"\n" " .balign 4\n" " .long " "1b" "-." ", " "3b" "-." "\n" " .previous\n" : "=r"(ret), "=r" (*(u16 *)to) : "m"((*(const struct __large_struct *)(from))), "i"(2), "0"(ret)); clac(); break; default: __get_user_bad(); } } while (0);
            return ret;
        case 4:
            do { ret = 0; switch (4) { case 1: stac(); __asm__ __volatile__( "1:	mov""b"" %2,%""b""1\n" "2:\n" ".section .fixup,\"ax\"\n" "3:	mov %3,%0\n" "	xor""b"" %""b""1,%""b""1\n" "	jmp 2b\n" ".previous\n" " .section .ex_table" "" ",\"a\"\n" " .balign 4\n" " .long " "1b" "-." ", " "3b" "-." "\n" " .previous\n" : "=r"(ret), "=q" (*(u32 *)to) : "m"((*(const struct __large_struct *)(from))), "i"(4), "0"(ret)); clac();break; case 2: stac(); __asm__ __volatile__( "1:	mov""w"" %2,%""w""1\n" "2:\n" ".section .fixup,\"ax\"\n" "3:	mov %3,%0\n" "	xor""w"" %""w""1,%""w""1\n" "	jmp 2b\n" ".previous\n" " .section .ex_table" "" ",\"a\"\n" " .balign 4\n" " .long " "1b" "-." ", " "3b" "-." "\n" " .previous\n" : "=r"(ret), "=r" (*(u32 *)to) : "m"((*(const struct __large_struct *)(from))), "i"(4), "0"(ret)); clac();break; case 4: stac(); __asm__ __volatile__( "1:	mov""l"" %2,%""k""1\n" "2:\n" ".section .fixup,\"ax\"\n" "3:	mov %3,%0\n" "	xor""l"" %""k""1,%""k""1\n" "	jmp 2b\n" ".previous\n" " .section .ex_table" "" ",\"a\"\n" " .balign 4\n" " .long " "1b" "-." ", " "3b" "-." "\n" " .previous\n" : "=r"(ret), "=r" (*(u32 *)to) : "m"((*(const struct __large_struct *)(from))), "i"(4), "0"(ret)); clac();break; case 8: stac(); __asm__ __volatile__( "1:	mov""q"" %2,%""""1\n" "2:\n" ".section .fixup,\"ax\"\n" "3:	mov %3,%0\n" "	xor""q"" %""""1,%""""1\n" "	jmp 2b\n" ".previous\n" " .section .ex_table" "" ",\"a\"\n" " .balign 4\n" " .long " "1b" "-." ", " "3b" "-." "\n" " .previous\n" : "=r"(ret), "=r" (*(u32 *)to) : "m"((*(const struct __large_struct *)(from))), "i"(4), "0"(ret)); clac(); break; default: __get_user_bad(); } } while (0);
            return ret;
        case 8:
            do { ret = 0; switch (8) { case 1: stac(); __asm__ __volatile__( "1:	mov""b"" %2,%""b""1\n" "2:\n" ".section .fixup,\"ax\"\n" "3:	mov %3,%0\n" "	xor""b"" %""b""1,%""b""1\n" "	jmp 2b\n" ".previous\n" " .section .ex_table" "" ",\"a\"\n" " .balign 4\n" " .long " "1b" "-." ", " "3b" "-." "\n" " .previous\n" : "=r"(ret), "=q" (*(u64*)to) : "m"((*(const struct __large_struct *)(from))), "i"(8), "0"(ret)); clac();break; case 2: stac(); __asm__ __volatile__( "1:	mov""w"" %2,%""w""1\n" "2:\n" ".section .fixup,\"ax\"\n" "3:	mov %3,%0\n" "	xor""w"" %""w""1,%""w""1\n" "	jmp 2b\n" ".previous\n" " .section .ex_table" "" ",\"a\"\n" " .balign 4\n" " .long " "1b" "-." ", " "3b" "-." "\n" " .previous\n" : "=r"(ret), "=r" (*(u64*)to) : "m"((*(const struct __large_struct *)(from))), "i"(8), "0"(ret)); clac();break; case 4: stac(); __asm__ __volatile__( "1:	mov""l"" %2,%""k""1\n" "2:\n" ".section .fixup,\"ax\"\n" "3:	mov %3,%0\n" "	xor""l"" %""k""1,%""k""1\n" "	jmp 2b\n" ".previous\n" " .section .ex_table" "" ",\"a\"\n" " .balign 4\n" " .long " "1b" "-." ", " "3b" "-." "\n" " .previous\n" : "=r"(ret), "=r" (*(u64*)to) : "m"((*(const struct __large_struct *)(from))), "i"(8), "0"(ret)); clac();break; case 8: stac(); __asm__ __volatile__( "1:	mov""q"" %2,%""""1\n" "2:\n" ".section .fixup,\"ax\"\n" "3:	mov %3,%0\n" "	xor""q"" %""""1,%""""1\n" "	jmp 2b\n" ".previous\n" " .section .ex_table" "" ",\"a\"\n" " .balign 4\n" " .long " "1b" "-." ", " "3b" "-." "\n" " .previous\n" : "=r"(ret), "=r" (*(u64*)to) : "m"((*(const struct __large_struct *)(from))), "i"(8), "0"(ret)); clac(); break; default: __get_user_bad(); } } while (0);
            return ret;
        }
    }
    return __copy_from_user_ll(to, from, n);
}
# 266 "/var/xen-dev/xen/xen/include/asm/uaccess.h"
struct exception_table_entry
{
 s32 addr, cont;
};
extern struct exception_table_entry __start___ex_table[];
extern struct exception_table_entry __stop___ex_table[];
extern struct exception_table_entry __start___pre_ex_table[];
extern struct exception_table_entry __stop___pre_ex_table[];

union stub_exception_token {
    struct {
        uint16_t ec;
        uint8_t trapnr;
    } fields;
    unsigned long raw;
};

extern unsigned long search_exception_table(const struct cpu_user_regs *regs);
extern void sort_exception_tables(void);
extern void sort_exception_table(struct exception_table_entry *start,
                                 const struct exception_table_entry *stop);
# 10 "/var/xen-dev/xen/xen/include/asm/mm.h" 2
# 1 "/var/xen-dev/xen/xen/include/asm/x86_emulate.h" 1
# 17 "/var/xen-dev/xen/xen/include/asm/x86_emulate.h"
# 1 "/var/xen-dev/xen/xen/include/asm/regs.h" 1




# 1 "/var/xen-dev/xen/xen/include/asm/x86_64/regs.h" 1
# 6 "/var/xen-dev/xen/xen/include/asm/regs.h" 2
# 18 "/var/xen-dev/xen/xen/include/asm/x86_emulate.h" 2

# 1 "/var/xen-dev/xen/xen/include/asm/../../arch/x86/x86_emulate/x86_emulate.h" 1
# 38 "/var/xen-dev/xen/xen/include/asm/../../arch/x86/x86_emulate/x86_emulate.h"
struct x86_emulate_ctxt;






enum x86_segment {

    x86_seg_es,
    x86_seg_cs,
    x86_seg_ss,
    x86_seg_ds,
    x86_seg_fs,
    x86_seg_gs,

    x86_seg_tr,
    x86_seg_ldtr,
    x86_seg_gdtr,
    x86_seg_idtr,

    x86_seg_none
};

static __inline__ _Bool is_x86_user_segment(enum x86_segment seg)
{
    unsigned int idx = seg;

    return idx <= x86_seg_gs;
}
static __inline__ _Bool is_x86_system_segment(enum x86_segment seg)
{
    return seg >= x86_seg_tr && seg < x86_seg_none;
}






enum x86_event_type {
    X86_EVENTTYPE_EXT_INTR,
    X86_EVENTTYPE_NMI = 2,
    X86_EVENTTYPE_HW_EXCEPTION,
    X86_EVENTTYPE_SW_INTERRUPT,
    X86_EVENTTYPE_PRI_SW_EXCEPTION,
    X86_EVENTTYPE_SW_EXCEPTION,
};


struct x86_event {
    int16_t vector;
    uint8_t type;
    uint8_t insn_len;
    int32_t error_code;
    unsigned long cr2;
};





struct segment_register {
    uint16_t sel;
    union {
        uint16_t attr;
        struct {
            uint16_t type:4;
            uint16_t s: 1;
            uint16_t dpl: 2;
            uint16_t p: 1;
            uint16_t avl: 1;
            uint16_t l: 1;
            uint16_t db: 1;
            uint16_t g: 1;
            uint16_t pad: 4;
        };
    };
    uint32_t limit;
    uint64_t base;
};

struct x86_emul_fpu_aux {
    unsigned long ip, dp;
    uint16_t cs, ds;
    unsigned int op:11;
    unsigned int dval:1;
};
# 167 "/var/xen-dev/xen/xen/include/asm/../../arch/x86/x86_emulate/x86_emulate.h"
enum x86_emulate_fpu_type {
    X86EMUL_FPU_fpu,
    X86EMUL_FPU_wait,
    X86EMUL_FPU_mmx,
    X86EMUL_FPU_xmm,
    X86EMUL_FPU_ymm,
    X86EMUL_FPU_opmask,
    X86EMUL_FPU_zmm,

    X86EMUL_FPU_none
};

enum x86emul_cache_op {
    x86emul_clflush,
    x86emul_clflushopt,
    x86emul_clwb,
    x86emul_invd,
    x86emul_wbinvd,
    x86emul_wbnoinvd,
};

enum x86emul_tlb_op {
    x86emul_invlpg,
    x86emul_invlpga,
    x86emul_invpcid,
};

static __inline__ unsigned int x86emul_invpcid_aux(unsigned int pcid,
                                            unsigned int type)
{
    do { if ( __builtin_expect(!!(!(!(pcid & ~0xfff))),0) ) do { do { ({ _Static_assert(!((197) >> ((31 - 24) + (31 - 24))), "!(" "(197) >> (BUG_LINE_LO_WIDTH + BUG_LINE_HI_WIDTH)" ")"); }); ({ _Static_assert(!((3) >= 4), "!(" "(3) >= BUGFRAME_NR" ")"); }); asm volatile ( ".Lbug%=: ud2\n" ".pushsection .bug_frames.%c[bf_type], \"a\", @progbits\n" ".p2align 2\n" ".Lfrm%=:\n" ".long (.Lbug%= - .Lfrm%=) + %c[bf_line_hi]\n" ".long (%c[bf_ptr] - .Lfrm%=) + %c[bf_line_lo]\n" ".if " "1" "\n" ".long 0, %c[bf_msg] - .Lfrm%=\n" ".endif\n" ".popsection\n" :: [bf_type] "i" (3), [bf_ptr] "i" ("/var/xen-dev/xen/xen/include/asm/../../arch/x86/x86_emulate/x86_emulate.h"), [bf_msg] "i" ("!(pcid & ~0xfff)"), [bf_line_lo] "i" ((197 & ((1 << (31 - 24)) - 1)) << 24), [bf_line_hi] "i" (((197) >> (31 - 24)) << 24) ); } while (0); __builtin_unreachable(); } while (0); } while (0);
    return (type << 12) | pcid;
}

static __inline__ unsigned int x86emul_invpcid_pcid(unsigned int aux)
{
    return aux & 0xfff;
}

static __inline__ unsigned int x86emul_invpcid_type(unsigned int aux)
{
    return aux >> 12;
}

struct x86_emulate_state;
# 225 "/var/xen-dev/xen/xen/include/asm/../../arch/x86/x86_emulate/x86_emulate.h"
struct x86_emulate_ops
{
# 248 "/var/xen-dev/xen/xen/include/asm/../../arch/x86/x86_emulate/x86_emulate.h"
    int (*read)(
        enum x86_segment seg,
        unsigned long offset,
        void *p_data,
        unsigned int bytes,
        struct x86_emulate_ctxt *ctxt);
# 262 "/var/xen-dev/xen/xen/include/asm/../../arch/x86/x86_emulate/x86_emulate.h"
    int (*insn_fetch)(
        enum x86_segment seg,
        unsigned long offset,
        void *p_data,
        unsigned int bytes,
        struct x86_emulate_ctxt *ctxt);





    int (*write)(
        enum x86_segment seg,
        unsigned long offset,
        void *p_data,
        unsigned int bytes,
        struct x86_emulate_ctxt *ctxt);







    int (*rmw)(
        enum x86_segment seg,
        unsigned long offset,
        unsigned int bytes,
        uint32_t *eflags,
        struct x86_emulate_state *state,
        struct x86_emulate_ctxt *ctxt);
# 303 "/var/xen-dev/xen/xen/include/asm/../../arch/x86/x86_emulate/x86_emulate.h"
    int (*cmpxchg)(
        enum x86_segment seg,
        unsigned long offset,
        void *p_old,
        void *p_new,
        unsigned int bytes,
        _Bool lock,
        struct x86_emulate_ctxt *ctxt);





    int (*validate)(
        const struct x86_emulate_state *state,
        struct x86_emulate_ctxt *ctxt);







    int (*rep_ins)(
        uint16_t src_port,
        enum x86_segment dst_seg,
        unsigned long dst_offset,
        unsigned int bytes_per_rep,
        unsigned long *reps,
        struct x86_emulate_ctxt *ctxt);







    int (*rep_outs)(
        enum x86_segment src_seg,
        unsigned long src_offset,
        uint16_t dst_port,
        unsigned int bytes_per_rep,
        unsigned long *reps,
        struct x86_emulate_ctxt *ctxt);







    int (*rep_movs)(
        enum x86_segment src_seg,
        unsigned long src_offset,
        enum x86_segment dst_seg,
        unsigned long dst_offset,
        unsigned int bytes_per_rep,
        unsigned long *reps,
        struct x86_emulate_ctxt *ctxt);







    int (*rep_stos)(
        void *p_data,
        enum x86_segment seg,
        unsigned long offset,
        unsigned int bytes_per_rep,
        unsigned long *reps,
        struct x86_emulate_ctxt *ctxt);





    int (*read_segment)(
        enum x86_segment seg,
        struct segment_register *reg,
        struct x86_emulate_ctxt *ctxt);





    int (*write_segment)(
        enum x86_segment seg,
        const struct segment_register *reg,
        struct x86_emulate_ctxt *ctxt);





    int (*read_io)(
        unsigned int port,
        unsigned int bytes,
        unsigned long *val,
        struct x86_emulate_ctxt *ctxt);





    int (*write_io)(
        unsigned int port,
        unsigned int bytes,
        unsigned long val,
        struct x86_emulate_ctxt *ctxt);





    int (*read_cr)(
        unsigned int reg,
        unsigned long *val,
        struct x86_emulate_ctxt *ctxt);





    int (*write_cr)(
        unsigned int reg,
        unsigned long val,
        struct x86_emulate_ctxt *ctxt);





    int (*read_dr)(
        unsigned int reg,
        unsigned long *val,
        struct x86_emulate_ctxt *ctxt);





    int (*write_dr)(
        unsigned int reg,
        unsigned long val,
        struct x86_emulate_ctxt *ctxt);





    int (*read_xcr)(
        unsigned int reg,
        uint64_t *val,
        struct x86_emulate_ctxt *ctxt);





    int (*write_xcr)(
        unsigned int reg,
        uint64_t val,
        struct x86_emulate_ctxt *ctxt);





    int (*read_msr)(
        unsigned int reg,
        uint64_t *val,
        struct x86_emulate_ctxt *ctxt);





    int (*write_msr)(
        unsigned int reg,
        uint64_t val,
        struct x86_emulate_ctxt *ctxt);






    int (*cache_op)(
        enum x86emul_cache_op op,
        enum x86_segment seg,
        unsigned long offset,
        struct x86_emulate_ctxt *ctxt);
# 507 "/var/xen-dev/xen/xen/include/asm/../../arch/x86/x86_emulate/x86_emulate.h"
    int (*tlb_op)(
        enum x86emul_tlb_op op,
        unsigned long addr,
        unsigned long aux,
        struct x86_emulate_ctxt *ctxt);


    int (*cpuid)(
        uint32_t leaf,
        uint32_t subleaf,
        struct cpuid_leaf *res,
        struct x86_emulate_ctxt *ctxt);




    int (*get_fpu)(
        enum x86_emulate_fpu_type type,
        struct x86_emulate_ctxt *ctxt);
# 535 "/var/xen-dev/xen/xen/include/asm/../../arch/x86/x86_emulate/x86_emulate.h"
    void (*put_fpu)(
        struct x86_emulate_ctxt *ctxt,
        enum x86_emulate_fpu_type backout,
        const struct x86_emul_fpu_aux *aux);


    int (*vmfunc)(
        struct x86_emulate_ctxt *ctxt);
};

struct cpu_user_regs;

struct x86_emulate_ctxt
{





    const struct cpuid_policy *cpuid;


    _Bool force_writeback;


    void *data;






    struct cpu_user_regs *regs;


    unsigned int addr_size;


    unsigned int sp_size;


    _Bool lma;






    unsigned int opcode;


    union {
        uint8_t raw;
        struct {
            _Bool hlt:1;
            _Bool mov_ss:1;
            _Bool sti:1;
            _Bool unblock_nmi:1;
            _Bool singlestep:1;
        };
    } retire;

    _Bool event_pending;
    struct x86_event event;
};
# 660 "/var/xen-dev/xen/xen/include/asm/../../arch/x86/x86_emulate/x86_emulate.h"
struct x86_emulate_stub {
    union {
        void (*func)(void);
        uintptr_t addr;
    };




    uint8_t buf[15 + 1];

};





int
x86_emulate(
    struct x86_emulate_ctxt *ctxt,
    const struct x86_emulate_ops *ops);






int x86_emulate_wrapper(
    struct x86_emulate_ctxt *ctxt,
    const struct x86_emulate_ops *ops);
# 700 "/var/xen-dev/xen/xen/include/asm/../../arch/x86/x86_emulate/x86_emulate.h"
extern const uint8_t cpu_user_regs_gpr_offsets[16];





static __inline__ unsigned long *decode_gpr(struct cpu_user_regs *regs,
                                        unsigned int modrm)
{

    ({ _Static_assert(!((sizeof(cpu_user_regs_gpr_offsets) / sizeof((cpu_user_regs_gpr_offsets)[0]) + sizeof(struct { _Static_assert(!(__builtin_types_compatible_p(typeof(cpu_user_regs_gpr_offsets), typeof(&cpu_user_regs_gpr_offsets[0]))), "!(" "__builtin_types_compatible_p(typeof(cpu_user_regs_gpr_offsets), typeof(&cpu_user_regs_gpr_offsets[0]))" ")"); })) & ((sizeof(cpu_user_regs_gpr_offsets) / sizeof((cpu_user_regs_gpr_offsets)[0]) + sizeof(struct { _Static_assert(!(__builtin_types_compatible_p(typeof(cpu_user_regs_gpr_offsets), typeof(&cpu_user_regs_gpr_offsets[0]))), "!(" "__builtin_types_compatible_p(typeof(cpu_user_regs_gpr_offsets), typeof(&cpu_user_regs_gpr_offsets[0]))" ")"); })) - 1)), "!(" "ARRAY_SIZE(cpu_user_regs_gpr_offsets) & (ARRAY_SIZE(cpu_user_regs_gpr_offsets) - 1)" ")"); })
                                                             ;







    modrm &= (sizeof(cpu_user_regs_gpr_offsets) / sizeof((cpu_user_regs_gpr_offsets)[0]) + sizeof(struct { _Static_assert(!(__builtin_types_compatible_p(typeof(cpu_user_regs_gpr_offsets), typeof(&cpu_user_regs_gpr_offsets[0]))), "!(" "__builtin_types_compatible_p(typeof(cpu_user_regs_gpr_offsets), typeof(&cpu_user_regs_gpr_offsets[0]))" ")"); })) - 1;

    return (void *)regs + cpu_user_regs_gpr_offsets[modrm];
}


int
x86emul_unhandleable_rw(
    enum x86_segment seg,
    unsigned long offset,
    void *p_data,
    unsigned int bytes,
    struct x86_emulate_ctxt *ctxt);
# 790 "/var/xen-dev/xen/xen/include/asm/../../arch/x86/x86_emulate/x86_emulate.h"
int
x86_emul_rmw(
    void *ptr,
    unsigned int bytes,
    uint32_t *eflags,
    struct x86_emulate_state *state,
    struct x86_emulate_ctxt *ctxt);

static __inline__ void x86_emul_hw_exception(
    unsigned int vector, int error_code, struct x86_emulate_ctxt *ctxt)
{
    do { if ( __builtin_expect(!!(!(!ctxt->event_pending)),0) ) do { do { ({ _Static_assert(!((801) >> ((31 - 24) + (31 - 24))), "!(" "(801) >> (BUG_LINE_LO_WIDTH + BUG_LINE_HI_WIDTH)" ")"); }); ({ _Static_assert(!((3) >= 4), "!(" "(3) >= BUGFRAME_NR" ")"); }); asm volatile ( ".Lbug%=: ud2\n" ".pushsection .bug_frames.%c[bf_type], \"a\", @progbits\n" ".p2align 2\n" ".Lfrm%=:\n" ".long (.Lbug%= - .Lfrm%=) + %c[bf_line_hi]\n" ".long (%c[bf_ptr] - .Lfrm%=) + %c[bf_line_lo]\n" ".if " "1" "\n" ".long 0, %c[bf_msg] - .Lfrm%=\n" ".endif\n" ".popsection\n" :: [bf_type] "i" (3), [bf_ptr] "i" ("/var/xen-dev/xen/xen/include/asm/../../arch/x86/x86_emulate/x86_emulate.h"), [bf_msg] "i" ("!ctxt->event_pending"), [bf_line_lo] "i" ((801 & ((1 << (31 - 24)) - 1)) << 24), [bf_line_hi] "i" (((801) >> (31 - 24)) << 24) ); } while (0); __builtin_unreachable(); } while (0); } while (0);

    ctxt->event.vector = vector;
    ctxt->event.type = X86_EVENTTYPE_HW_EXCEPTION;
    ctxt->event.error_code = error_code;

    ctxt->event_pending = 1;
}

static __inline__ void x86_emul_pagefault(
    int error_code, unsigned long cr2, struct x86_emulate_ctxt *ctxt)
{
    do { if ( __builtin_expect(!!(!(!ctxt->event_pending)),0) ) do { do { ({ _Static_assert(!((813) >> ((31 - 24) + (31 - 24))), "!(" "(813) >> (BUG_LINE_LO_WIDTH + BUG_LINE_HI_WIDTH)" ")"); }); ({ _Static_assert(!((3) >= 4), "!(" "(3) >= BUGFRAME_NR" ")"); }); asm volatile ( ".Lbug%=: ud2\n" ".pushsection .bug_frames.%c[bf_type], \"a\", @progbits\n" ".p2align 2\n" ".Lfrm%=:\n" ".long (.Lbug%= - .Lfrm%=) + %c[bf_line_hi]\n" ".long (%c[bf_ptr] - .Lfrm%=) + %c[bf_line_lo]\n" ".if " "1" "\n" ".long 0, %c[bf_msg] - .Lfrm%=\n" ".endif\n" ".popsection\n" :: [bf_type] "i" (3), [bf_ptr] "i" ("/var/xen-dev/xen/xen/include/asm/../../arch/x86/x86_emulate/x86_emulate.h"), [bf_msg] "i" ("!ctxt->event_pending"), [bf_line_lo] "i" ((813 & ((1 << (31 - 24)) - 1)) << 24), [bf_line_hi] "i" (((813) >> (31 - 24)) << 24) ); } while (0); __builtin_unreachable(); } while (0); } while (0);

    ctxt->event.vector = 14;
    ctxt->event.type = X86_EVENTTYPE_HW_EXCEPTION;
    ctxt->event.error_code = error_code;
    ctxt->event.cr2 = cr2;

    ctxt->event_pending = 1;
}

static __inline__ void x86_emul_reset_event(struct x86_emulate_ctxt *ctxt)
{
    ctxt->event_pending = 0;
    ctxt->event = (struct x86_event){};
}
# 20 "/var/xen-dev/xen/xen/include/asm/x86_emulate.h" 2
# 11 "/var/xen-dev/xen/xen/include/asm/mm.h" 2
# 102 "/var/xen-dev/xen/xen/include/asm/mm.h"
struct page_list_entry
{
    unsigned int next, prev;
};




struct page_sharing_info;

struct page_info
{
    union {
# 126 "/var/xen-dev/xen/xen/include/asm/mm.h"
        struct page_list_entry list;


        paddr_t up;
# 140 "/var/xen-dev/xen/xen/include/asm/mm.h"
    };


    unsigned long count_info;


    union {


        struct {

            unsigned long type_info;
        } inuse;


        struct {
            unsigned long type:5;
            unsigned long pinned:1;
            unsigned long head:1;

            unsigned long count:((BITS_PER_LONG - (8)) - 7);
        } sh;


        union {
            struct {






                unsigned int first_dirty;


                _Bool need_tlbflush;




                uint8_t scrub_state;
            };

            unsigned long val;
        } free;

    } u;

    union {


        struct {

            unsigned int _domain;
        } inuse;


        struct {

            unsigned int back;
        } sh;


        struct {

            unsigned int order;
        } free;

    } v;

    union {





        u32 tlbflush_timestamp;
# 269 "/var/xen-dev/xen/xen/include/asm/mm.h"
        struct {
            u16 nr_validated_ptes:9 + 1;
            u16 :16 - 9 - 1 - 1;
            u16 partial_flags:1;
            s16 linear_pt_count;
        };
# 285 "/var/xen-dev/xen/xen/include/asm/mm.h"
        struct {
            uint16_t shadow_flags;
            _Bool pagetable_dying;
        };


        unsigned int next_shadow;
    };
};
# 320 "/var/xen-dev/xen/xen/include/asm/mm.h"
extern void free_shared_domheap_page(struct page_info *page);


extern unsigned long max_page;
extern unsigned long total_pages;
void init_frametable(void);




static __inline__ struct page_info *__virt_to_page(const void *v)
{
    unsigned long va = (unsigned long)v;

    do { if ( __builtin_expect(!!(!(va >= XEN_VIRT_START)),0) ) do { do { ({ _Static_assert(!((334) >> ((31 - 24) + (31 - 24))), "!(" "(334) >> (BUG_LINE_LO_WIDTH + BUG_LINE_HI_WIDTH)" ")"); }); ({ _Static_assert(!((3) >= 4), "!(" "(3) >= BUGFRAME_NR" ")"); }); asm volatile ( ".Lbug%=: ud2\n" ".pushsection .bug_frames.%c[bf_type], \"a\", @progbits\n" ".p2align 2\n" ".Lfrm%=:\n" ".long (.Lbug%= - .Lfrm%=) + %c[bf_line_hi]\n" ".long (%c[bf_ptr] - .Lfrm%=) + %c[bf_line_lo]\n" ".if " "1" "\n" ".long 0, %c[bf_msg] - .Lfrm%=\n" ".endif\n" ".popsection\n" :: [bf_type] "i" (3), [bf_ptr] "i" ("/var/xen-dev/xen/xen/include/asm/mm.h"), [bf_msg] "i" ("va >= XEN_VIRT_START"), [bf_line_lo] "i" ((334 & ((1 << (31 - 24)) - 1)) << 24), [bf_line_hi] "i" (((334) >> (31 - 24)) << 24) ); } while (0); __builtin_unreachable(); } while (0); } while (0);
    do { if ( __builtin_expect(!!(!(va < DIRECTMAP_VIRT_END)),0) ) do { do { ({ _Static_assert(!((335) >> ((31 - 24) + (31 - 24))), "!(" "(335) >> (BUG_LINE_LO_WIDTH + BUG_LINE_HI_WIDTH)" ")"); }); ({ _Static_assert(!((3) >= 4), "!(" "(3) >= BUGFRAME_NR" ")"); }); asm volatile ( ".Lbug%=: ud2\n" ".pushsection .bug_frames.%c[bf_type], \"a\", @progbits\n" ".p2align 2\n" ".Lfrm%=:\n" ".long (.Lbug%= - .Lfrm%=) + %c[bf_line_hi]\n" ".long (%c[bf_ptr] - .Lfrm%=) + %c[bf_line_lo]\n" ".if " "1" "\n" ".long 0, %c[bf_msg] - .Lfrm%=\n" ".endif\n" ".popsection\n" :: [bf_type] "i" (3), [bf_ptr] "i" ("/var/xen-dev/xen/xen/include/asm/mm.h"), [bf_msg] "i" ("va < DIRECTMAP_VIRT_END"), [bf_line_lo] "i" ((335 & ((1 << (31 - 24)) - 1)) << 24), [bf_line_hi] "i" (((335) >> (31 - 24)) << 24) ); } while (0); __builtin_unreachable(); } while (0); } while (0);
    if ( va < XEN_VIRT_END )
        va += DIRECTMAP_VIRT_START - XEN_VIRT_START + xen_phys_start;
    else
        do { if ( __builtin_expect(!!(!(va >= DIRECTMAP_VIRT_START)),0) ) do { do { ({ _Static_assert(!((339) >> ((31 - 24) + (31 - 24))), "!(" "(339) >> (BUG_LINE_LO_WIDTH + BUG_LINE_HI_WIDTH)" ")"); }); ({ _Static_assert(!((3) >= 4), "!(" "(3) >= BUGFRAME_NR" ")"); }); asm volatile ( ".Lbug%=: ud2\n" ".pushsection .bug_frames.%c[bf_type], \"a\", @progbits\n" ".p2align 2\n" ".Lfrm%=:\n" ".long (.Lbug%= - .Lfrm%=) + %c[bf_line_hi]\n" ".long (%c[bf_ptr] - .Lfrm%=) + %c[bf_line_lo]\n" ".if " "1" "\n" ".long 0, %c[bf_msg] - .Lfrm%=\n" ".endif\n" ".popsection\n" :: [bf_type] "i" (3), [bf_ptr] "i" ("/var/xen-dev/xen/xen/include/asm/mm.h"), [bf_msg] "i" ("va >= DIRECTMAP_VIRT_START"), [bf_line_lo] "i" ((339 & ((1 << (31 - 24)) - 1)) << 24), [bf_line_hi] "i" (((339) >> (31 - 24)) << 24) ); } while (0); __builtin_unreachable(); } while (0); } while (0);
    return ((struct page_info *)FRAMETABLE_VIRT_START) + ((va - DIRECTMAP_VIRT_START) >> 12);
}

static __inline__ void *__page_to_virt(const struct page_info *pg)
{
    do { if ( __builtin_expect(!!(!((unsigned long)pg - FRAMETABLE_VIRT_START < FRAMETABLE_SIZE)),0) ) do { do { ({ _Static_assert(!((345) >> ((31 - 24) + (31 - 24))), "!(" "(345) >> (BUG_LINE_LO_WIDTH + BUG_LINE_HI_WIDTH)" ")"); }); ({ _Static_assert(!((3) >= 4), "!(" "(3) >= BUGFRAME_NR" ")"); }); asm volatile ( ".Lbug%=: ud2\n" ".pushsection .bug_frames.%c[bf_type], \"a\", @progbits\n" ".p2align 2\n" ".Lfrm%=:\n" ".long (.Lbug%= - .Lfrm%=) + %c[bf_line_hi]\n" ".long (%c[bf_ptr] - .Lfrm%=) + %c[bf_line_lo]\n" ".if " "1" "\n" ".long 0, %c[bf_msg] - .Lfrm%=\n" ".endif\n" ".popsection\n" :: [bf_type] "i" (3), [bf_ptr] "i" ("/var/xen-dev/xen/xen/include/asm/mm.h"), [bf_msg] "i" ("(unsigned long)pg - FRAMETABLE_VIRT_START < FRAMETABLE_SIZE"), [bf_line_lo] "i" ((345 & ((1 << (31 - 24)) - 1)) << 24), [bf_line_hi] "i" (((345) >> (31 - 24)) << 24) ); } while (0); __builtin_unreachable(); } while (0); } while (0);






    return (void *)(DIRECTMAP_VIRT_START +
                    ((unsigned long)pg - FRAMETABLE_VIRT_START) /
                    (sizeof(*pg) / (sizeof(*pg) & -sizeof(*pg))) *
                    (((1L) << 12) / (sizeof(*pg) & -sizeof(*pg))));
}

int free_page_type(struct page_info *page, unsigned long type,
                   int preemptible);

void init_xen_pae_l2_slots(l2_pgentry_t *l2t, const struct domain *d);
void init_xen_l4_slots(l4_pgentry_t *l4t, mfn_t l4mfn,
                       const struct domain *d, mfn_t sl4mfn, _Bool ro_mpt);
_Bool fill_ro_mpt(mfn_t mfn);
void zap_ro_mpt(mfn_t mfn);

_Bool is_iomem_page(mfn_t mfn);

struct platform_bad_page {
    unsigned long mfn;
    unsigned int order;
};

const struct platform_bad_page *get_platform_badpages(unsigned int *array_size);
# 387 "/var/xen-dev/xen/xen/include/asm/mm.h"
int page_lock(struct page_info *page);
void page_unlock(struct page_info *page);

void put_page_type(struct page_info *page);
int get_page_type(struct page_info *page, unsigned long type);
int put_page_type_preemptible(struct page_info *page);
int get_page_type_preemptible(struct page_info *page, unsigned long type);
int put_old_guest_table(struct vcpu *);
int get_page_from_l1e(
    l1_pgentry_t l1e, struct domain *l1e_owner, struct domain *pg_owner);
void put_page_from_l1e(l1_pgentry_t l1e, struct domain *l1e_owner);

static __inline__ struct page_info *get_page_from_mfn(mfn_t mfn, struct domain *d)
{
    struct page_info *page = (((struct page_info *)FRAMETABLE_VIRT_START) + mfn_to_pdx(mfn));

    if ( __builtin_expect(!!(!__mfn_valid(mfn_x(mfn))),0) || __builtin_expect(!!(!get_page(page, d)),0) )
    {
        printk(XENLOG_GUEST XENLOG_WARNING "%s:%d:%pv " "Could not get page ref for mfn %""05lx""\n",
                                                                          "/var/xen-dev/xen/xen/include/asm/mm.h"
# 405 "/var/xen-dev/xen/xen/include/asm/mm.h"
        ,
                                                                          406
# 405 "/var/xen-dev/xen/xen/include/asm/mm.h"
        , ((get_cpu_info()->current_vcpu)), mfn_x(mfn))
                                                                           ;
        return ((void*)0);
    }

    return page;
}

static __inline__ void put_page_and_type(struct page_info *page)
{
    put_page_type(page);
    put_page(page);
}

static __inline__ int put_page_and_type_preemptible(struct page_info *page)
{
    int rc = put_page_type_preemptible(page);

    if ( __builtin_expect(!!(rc == 0),1) )
        put_page(page);
    return rc;
}

static __inline__ int get_page_and_type(struct page_info *page,
                                    struct domain *domain,
                                    unsigned long type)
{
    int rc = get_page(page, domain);

    if ( __builtin_expect(!!(rc),1) && __builtin_expect(!!(!get_page_type(page, type)),0) )
    {
        put_page(page);
        rc = 0;
    }

    return rc;
}
# 450 "/var/xen-dev/xen/xen/include/asm/mm.h"
int check_descriptor(const struct domain *d, seg_desc_t *desc);

extern paddr_t mem_hotplug;
# 508 "/var/xen-dev/xen/xen/include/asm/mm.h"
extern _Bool machine_to_phys_mapping_valid;





extern struct rangeset *mmio_ro_ranges;
# 534 "/var/xen-dev/xen/xen/include/asm/mm.h"
void memguard_guard_stack(void *p);
void memguard_unguard_stack(void *p);
_Bool __attribute__((__const__)) memguard_is_stack_guard_page(unsigned long addr);

struct mmio_ro_emulate_ctxt {
        unsigned long cr2;
        unsigned int seg, bdf;
};

extern int mmio_ro_emulated_write(enum x86_segment seg,
                                  unsigned long offset,
                                  void *p_data,
                                  unsigned int bytes,
                                  struct x86_emulate_ctxt *ctxt);
extern int mmcfg_intercept_write(enum x86_segment seg,
                                 unsigned long offset,
                                 void *p_data,
                                 unsigned int bytes,
                                 struct x86_emulate_ctxt *ctxt);

int audit_adjust_pgtables(struct domain *d, int dir, int noisy);

extern int pagefault_by_memadd(unsigned long addr, struct cpu_user_regs *regs);
extern int handle_memadd_fault(unsigned long addr, struct cpu_user_regs *regs);







void _audit_domain(struct domain *d, int flags);

void audit_domains(void);
# 577 "/var/xen-dev/xen/xen/include/asm/mm.h"
void make_cr3(struct vcpu *v, mfn_t mfn);
void update_cr3(struct vcpu *v);
int vcpu_destroy_pagetables(struct vcpu *);
void *do_page_walk(struct vcpu *v, unsigned long addr);

int __sync_local_execstate(void);


long arch_memory_op(unsigned long cmd, __guest_handle_void arg);
long subarch_memory_op(unsigned long cmd, __guest_handle_void arg);
int compat_arch_memory_op(unsigned long cmd, __guest_handle_void);
int compat_subarch_memory_op(int op, __guest_handle_void);




int create_perdomain_mapping(struct domain *, unsigned long va,
                             unsigned int nr, l1_pgentry_t **,
                             struct page_info **);
void destroy_perdomain_mapping(struct domain *, unsigned long va,
                               unsigned int nr);
void free_perdomain_mappings(struct domain *);

extern int memory_add(unsigned long spfn, unsigned long epfn, unsigned int pxm);

void domain_set_alloc_bitsize(struct domain *d);
unsigned int domain_clamp_alloc_bitsize(struct domain *d, unsigned int bits);

unsigned long domain_get_maximum_gpfn(struct domain *d);


typedef struct mm_lock {
    spinlock_t lock;
    int unlock_level;
    int locker;
    const char *locker_function;
} mm_lock_t;

typedef struct mm_rwlock {
    percpu_rwlock_t lock;
    int unlock_level;
    int recurse_count;
    int locker;
    const char *locker_function;
} mm_rwlock_t;






extern const char zero_page[];


void write_32bit_pse_identmap(uint32_t *l2);





static __inline__ _Bool arch_mfn_in_directmap(unsigned long mfn)
{
    unsigned long eva = ({ const typeof(DIRECTMAP_VIRT_END) _x = (DIRECTMAP_VIRT_END); const typeof(0xFFFF880000000000UL) _y = (0xFFFF880000000000UL); (void) (&_x == &_y); _x < _y ? _x : _y; });

    return mfn <= ((__virt_to_maddr((unsigned long)(eva - 1)) >> 12) + 1);
}

int arch_acquire_resource(struct domain *d, unsigned int type,
                          unsigned int id, unsigned long frame,
                          unsigned int nr_frames, xen_pfn_t mfn_list[]);
# 287 "/var/xen-dev/xen/xen/include/xen/mm.h" 2


struct page_list_head
{
    struct page_info *next, *tail;
};
# 309 "/var/xen-dev/xen/xen/include/xen/mm.h"
static __inline__ bool_t
page_list_empty(const struct page_list_head *head)
{
    return !head->next;
}
static __inline__ struct page_info *
page_list_first(const struct page_list_head *head)
{
    return head->next;
}
static __inline__ struct page_info *
page_list_last(const struct page_list_head *head)
{
    return head->tail;
}
static __inline__ struct page_info *
page_list_next(const struct page_info *page,
               const struct page_list_head *head)
{
    return page != head->tail ? (((struct page_info *)FRAMETABLE_VIRT_START) + mfn_to_pdx(page->list.next)) : ((void*)0);
}
static __inline__ struct page_info *
page_list_prev(const struct page_info *page,
               const struct page_list_head *head)
{
    return page != head->next ? (((struct page_info *)FRAMETABLE_VIRT_START) + mfn_to_pdx(page->list.prev)) : ((void*)0);
}
static __inline__ void
page_list_add(struct page_info *page, struct page_list_head *head)
{
    if ( head->next )
    {
        page->list.next = pdx_to_mfn((unsigned long)((head->next) - ((struct page_info *)FRAMETABLE_VIRT_START)));
        head->next->list.prev = pdx_to_mfn((unsigned long)((page) - ((struct page_info *)FRAMETABLE_VIRT_START)));
    }
    else
    {
        head->tail = page;
        page->list.next = ((typeof(((struct page_info){}).list.next))~0);
    }
    page->list.prev = ((typeof(((struct page_info){}).list.next))~0);
    head->next = page;
}
static __inline__ void
page_list_add_tail(struct page_info *page, struct page_list_head *head)
{
    page->list.next = ((typeof(((struct page_info){}).list.next))~0);
    if ( head->next )
    {
        page->list.prev = pdx_to_mfn((unsigned long)((head->tail) - ((struct page_info *)FRAMETABLE_VIRT_START)));
        head->tail->list.next = pdx_to_mfn((unsigned long)((page) - ((struct page_info *)FRAMETABLE_VIRT_START)));
    }
    else
    {
        page->list.prev = ((typeof(((struct page_info){}).list.next))~0);
        head->next = page;
    }
    head->tail = page;
}
static __inline__ bool_t
__page_list_del_head(struct page_info *page, struct page_list_head *head,
                     struct page_info *next, struct page_info *prev)
{
    if ( head->next == page )
    {
        if ( head->tail != page )
        {
            next->list.prev = ((typeof(((struct page_info){}).list.next))~0);
            head->next = next;
        }
        else
            head->tail = head->next = ((void*)0);
        return 1;
    }

    if ( head->tail == page )
    {
        prev->list.next = ((typeof(((struct page_info){}).list.next))~0);
        head->tail = prev;
        return 1;
    }

    return 0;
}
static __inline__ void
page_list_del(struct page_info *page, struct page_list_head *head)
{
    struct page_info *next = (((struct page_info *)FRAMETABLE_VIRT_START) + mfn_to_pdx(page->list.next));
    struct page_info *prev = (((struct page_info *)FRAMETABLE_VIRT_START) + mfn_to_pdx(page->list.prev));

    if ( !__page_list_del_head(page, head, next, prev) )
    {
        next->list.prev = page->list.prev;
        prev->list.next = page->list.next;
    }
}
static __inline__ void
page_list_del2(struct page_info *page, struct page_list_head *head1,
               struct page_list_head *head2)
{
    struct page_info *next = (((struct page_info *)FRAMETABLE_VIRT_START) + mfn_to_pdx(page->list.next));
    struct page_info *prev = (((struct page_info *)FRAMETABLE_VIRT_START) + mfn_to_pdx(page->list.prev));

    if ( !__page_list_del_head(page, head1, next, prev) &&
         !__page_list_del_head(page, head2, next, prev) )
    {
        next->list.prev = page->list.prev;
        prev->list.next = page->list.next;
    }
}
static __inline__ struct page_info *
page_list_remove_head(struct page_list_head *head)
{
    struct page_info *page = head->next;

    if ( page )
        page_list_del(page, head);

    return page;
}
static __inline__ void
page_list_move(struct page_list_head *dst, struct page_list_head *src)
{
    if ( !page_list_empty(src) )
    {
        *dst = *src;
        ((src)->tail = (src)->next = ((void*)0));
    }
}
static __inline__ void
page_list_splice(struct page_list_head *list, struct page_list_head *head)
{
    struct page_info *first, *last, *at;

    if ( page_list_empty(list) )
        return;

    if ( page_list_empty(head) )
    {
        head->next = list->next;
        head->tail = list->tail;
        return;
    }

    first = list->next;
    last = list->tail;
    at = head->next;

    do { if ( __builtin_expect(!!(!(first->list.prev == ((typeof(((struct page_info){}).list.next))~0))),0) ) do { do { ({ _Static_assert(!((457) >> ((31 - 24) + (31 - 24))), "!(" "(457) >> (BUG_LINE_LO_WIDTH + BUG_LINE_HI_WIDTH)" ")"); }); ({ _Static_assert(!((3) >= 4), "!(" "(3) >= BUGFRAME_NR" ")"); }); asm volatile ( ".Lbug%=: ud2\n" ".pushsection .bug_frames.%c[bf_type], \"a\", @progbits\n" ".p2align 2\n" ".Lfrm%=:\n" ".long (.Lbug%= - .Lfrm%=) + %c[bf_line_hi]\n" ".long (%c[bf_ptr] - .Lfrm%=) + %c[bf_line_lo]\n" ".if " "1" "\n" ".long 0, %c[bf_msg] - .Lfrm%=\n" ".endif\n" ".popsection\n" :: [bf_type] "i" (3), [bf_ptr] "i" ("/var/xen-dev/xen/xen/include/xen/mm.h"), [bf_msg] "i" ("first->list.prev == PAGE_LIST_NULL"), [bf_line_lo] "i" ((457 & ((1 << (31 - 24)) - 1)) << 24), [bf_line_hi] "i" (((457) >> (31 - 24)) << 24) ); } while (0); __builtin_unreachable(); } while (0); } while (0);
    do { if ( __builtin_expect(!!(!(first->list.prev == at->list.prev)),0) ) do { do { ({ _Static_assert(!((458) >> ((31 - 24) + (31 - 24))), "!(" "(458) >> (BUG_LINE_LO_WIDTH + BUG_LINE_HI_WIDTH)" ")"); }); ({ _Static_assert(!((3) >= 4), "!(" "(3) >= BUGFRAME_NR" ")"); }); asm volatile ( ".Lbug%=: ud2\n" ".pushsection .bug_frames.%c[bf_type], \"a\", @progbits\n" ".p2align 2\n" ".Lfrm%=:\n" ".long (.Lbug%= - .Lfrm%=) + %c[bf_line_hi]\n" ".long (%c[bf_ptr] - .Lfrm%=) + %c[bf_line_lo]\n" ".if " "1" "\n" ".long 0, %c[bf_msg] - .Lfrm%=\n" ".endif\n" ".popsection\n" :: [bf_type] "i" (3), [bf_ptr] "i" ("/var/xen-dev/xen/xen/include/xen/mm.h"), [bf_msg] "i" ("first->list.prev == at->list.prev"), [bf_line_lo] "i" ((458 & ((1 << (31 - 24)) - 1)) << 24), [bf_line_hi] "i" (((458) >> (31 - 24)) << 24) ); } while (0); __builtin_unreachable(); } while (0); } while (0);
    head->next = first;

    last->list.next = pdx_to_mfn((unsigned long)((at) - ((struct page_info *)FRAMETABLE_VIRT_START)));
    at->list.prev = pdx_to_mfn((unsigned long)((last) - ((struct page_info *)FRAMETABLE_VIRT_START)));
}
# 561 "/var/xen-dev/xen/xen/include/xen/mm.h"
static __inline__ unsigned int get_order_from_bytes(paddr_t size)
{
    unsigned int order;

    size = (size - 1) >> 12;
    for ( order = 0; size; order++ )
        size >>= 1;

    return order;
}

static __inline__ unsigned int get_order_from_pages(unsigned long nr_pages)
{
    unsigned int order;

    nr_pages--;
    for ( order = 0; nr_pages; order++ )
        nr_pages >>= 1;

    return order;
}

void scrub_one_page(struct page_info *);







int xenmem_add_to_physmap_one(struct domain *d, unsigned int space,
                              union xen_add_to_physmap_batch_extra extra,
                              unsigned long idx, gfn_t gfn);

int xenmem_add_to_physmap(struct domain *d, struct xen_add_to_physmap *xatp,
                          unsigned int start);


int __attribute__((__warn_unused_result__)) guest_remove_page(struct domain *d, unsigned long gmfn);
int __attribute__((__warn_unused_result__)) steal_page(struct domain *d, struct page_info *page,
                            unsigned int memflags);
int __attribute__((__warn_unused_result__)) donate_page(struct domain *d, struct page_info *page,
                             unsigned int memflags);







int page_is_ram_type(unsigned long mfn, unsigned long mem_type);

unsigned int page_get_ram_type(mfn_t mfn);



int prepare_ring_for_helper(struct domain *d, unsigned long gmfn,
                            struct page_info **_page, void **_va);
void destroy_ring_for_helper(void **_va, struct page_info *page);


unsigned long get_upper_mfn_bound(void);

# 1 "/var/xen-dev/xen/xen/include/asm/flushtlb.h" 1
# 13 "/var/xen-dev/xen/xen/include/asm/flushtlb.h"
# 1 "/var/xen-dev/xen/xen/include/xen/mm.h" 1
# 14 "/var/xen-dev/xen/xen/include/asm/flushtlb.h" 2





extern u32 tlbflush_clock;


extern __typeof__(u32) per_cpu__tlbflush_time;



static __inline__ void page_set_tlbflush_timestamp(struct page_info *page)
{






    do { if ( __builtin_expect(!!(!(local_irq_is_enabled())),0) ) do { do { ({ _Static_assert(!((34) >> ((31 - 24) + (31 - 24))), "!(" "(34) >> (BUG_LINE_LO_WIDTH + BUG_LINE_HI_WIDTH)" ")"); }); ({ _Static_assert(!((3) >= 4), "!(" "(3) >= BUGFRAME_NR" ")"); }); asm volatile ( ".Lbug%=: ud2\n" ".pushsection .bug_frames.%c[bf_type], \"a\", @progbits\n" ".p2align 2\n" ".Lfrm%=:\n" ".long (.Lbug%= - .Lfrm%=) + %c[bf_line_hi]\n" ".long (%c[bf_ptr] - .Lfrm%=) + %c[bf_line_lo]\n" ".if " "1" "\n" ".long 0, %c[bf_msg] - .Lfrm%=\n" ".endif\n" ".popsection\n" :: [bf_type] "i" (3), [bf_ptr] "i" ("/var/xen-dev/xen/xen/include/asm/flushtlb.h"), [bf_msg] "i" ("local_irq_is_enabled()"), [bf_line_lo] "i" ((34 & ((1 << (31 - 24)) - 1)) << 24), [bf_line_hi] "i" (((34) >> (31 - 24)) << 24) ); } while (0); __builtin_unreachable(); } while (0); } while (0);
    asm volatile ( "cli" : : : "memory" );
    page->tlbflush_timestamp = tlbflush_clock;
    asm volatile ( "sti" : : : "memory" );
}






static __inline__ int NEED_FLUSH(u32 cpu_stamp, u32 lastuse_stamp)
{
    u32 curr_time = tlbflush_clock;
# 57 "/var/xen-dev/xen/xen/include/asm/flushtlb.h"
    return ((curr_time == 0) ||
            ((cpu_stamp <= lastuse_stamp) &&
             (lastuse_stamp <= curr_time)));
}





static __inline__ void tlbflush_filter(cpumask_t *mask, uint32_t page_timestamp)
{
    unsigned int cpu;

    for ((cpu) = 0; (cpu) < 1; (cpu)++, (void)(mask))
        if ( !NEED_FLUSH((*({ unsigned long __ptr; __asm__ ("" : "=r"(__ptr) : "0"(&per_cpu__tlbflush_time)); (typeof(&per_cpu__tlbflush_time)) (__ptr + (__per_cpu_offset[cpu])); })), page_timestamp) )
            __cpumask_clear_cpu(cpu, mask);
}

void new_tlbflush_clock_period(void);


static __inline__ unsigned long read_cr3(void)
{
    unsigned long cr3;
    __asm__ __volatile__ (
        "mov %%cr3, %0" : "=r" (cr3) : );
    return cr3;
}


void switch_cr3_cr4(unsigned long cr3, unsigned long cr4);
# 110 "/var/xen-dev/xen/xen/include/asm/flushtlb.h"
unsigned int flush_area_local(const void *va, unsigned int flags);



void flush_area_mask(const cpumask_t *, const void *va, unsigned int flags);
# 145 "/var/xen-dev/xen/xen/include/asm/flushtlb.h"
static __inline__ void flush_page_to_ram(unsigned long mfn, _Bool sync_icache) {}
static __inline__ int invalidate_dcache_va_range(const void *p,
                                             unsigned long size)
{ return -EOPNOTSUPP; }
static __inline__ int clean_and_invalidate_dcache_va_range(const void *p,
                                                       unsigned long size)
{
    unsigned int order = get_order_from_bytes(size);

    flush_area_local(p, 0x400|((order)+1));
    return 0;
}
static __inline__ int clean_dcache_va_range(const void *p, unsigned long size)
{
    return clean_and_invalidate_dcache_va_range(p, size);
}
# 625 "/var/xen-dev/xen/xen/include/xen/mm.h" 2

static __inline__ void accumulate_tlbflush(_Bool *need_tlbflush,
                                       const struct page_info *page,
                                       uint32_t *tlbflush_timestamp)
{
    if ( page->u.free.need_tlbflush &&
         page->tlbflush_timestamp <= tlbflush_clock &&
         (!*need_tlbflush ||
          page->tlbflush_timestamp > *tlbflush_timestamp) )
    {
        *need_tlbflush = 1;
        *tlbflush_timestamp = page->tlbflush_timestamp;
    }
}

static __inline__ void filtered_flush_tlb_mask(uint32_t tlbflush_timestamp)
{
    cpumask_t mask;

    cpumask_copy(&mask, &cpu_online_map);
    tlbflush_filter(&mask, tlbflush_timestamp);
    if ( !cpumask_empty(&mask) )
    {
        ((void)0);
        flush_area_mask(&mask, ((void*)0), 0x100);
    }
}

enum XENSHARE_flags {
    SHARE_rw,
    SHARE_ro,
};
void share_xen_page_with_guest(struct page_info *page, struct domain *d,
                               enum XENSHARE_flags flags);

static __inline__ void share_xen_page_with_privileged_guests(
    struct page_info *page, enum XENSHARE_flags flags)
{
    share_xen_page_with_guest(page, dom_xen, flags);
}

static __inline__ void put_page_alloc_ref(struct page_info *page)
{
# 679 "/var/xen-dev/xen/xen/include/xen/mm.h"
    if ( ({ if ( (sizeof(*(&page->count_info)) < 4) ) __bitop_bad_size(); test_and_clear_bit((BITS_PER_LONG - (1)), &page->count_info); }) )
    {
        do { if (__builtin_expect(!!((page->count_info & ((1UL << (BITS_PER_LONG - (2))) | ((1UL<<(BITS_PER_LONG - (9)))-1))) <= 1),0)) do { do { ({ _Static_assert(!((681) >> ((31 - 24) + (31 - 24))), "!(" "(681) >> (BUG_LINE_LO_WIDTH + BUG_LINE_HI_WIDTH)" ")"); }); ({ _Static_assert(!((2) >= 4), "!(" "(2) >= BUGFRAME_NR" ")"); }); asm volatile ( ".Lbug%=: ud2\n" ".pushsection .bug_frames.%c[bf_type], \"a\", @progbits\n" ".p2align 2\n" ".Lfrm%=:\n" ".long (.Lbug%= - .Lfrm%=) + %c[bf_line_hi]\n" ".long (%c[bf_ptr] - .Lfrm%=) + %c[bf_line_lo]\n" ".if " "0" "\n" ".long 0, %c[bf_msg] - .Lfrm%=\n" ".endif\n" ".popsection\n" :: [bf_type] "i" (2), [bf_ptr] "i" ("/var/xen-dev/xen/xen/include/xen/mm.h"), [bf_msg] "i" (((void*)0)), [bf_line_lo] "i" ((681 & ((1 << (31 - 24)) - 1)) << 24), [bf_line_hi] "i" (((681) >> (31 - 24)) << 24) ); } while (0); __builtin_unreachable(); } while (0); } while (0);
        put_page(page);
    }
}
# 28 "/var/xen-dev/xen/xen/include/asm/paging.h" 2

# 1 "/var/xen-dev/xen/xen/include/xen/sched.h" 1







# 1 "/var/xen-dev/xen/xen/include/xen/shared.h" 1
# 36 "/var/xen-dev/xen/xen/include/xen/shared.h"
typedef struct shared_info shared_info_t;


typedef struct vcpu_info vcpu_info_t;




extern vcpu_info_t dummy_vcpu_info;
# 9 "/var/xen-dev/xen/xen/include/xen/sched.h" 2
# 1 "/var/xen-dev/xen/xen/include/xen/timer.h" 1
# 17 "/var/xen-dev/xen/xen/include/xen/timer.h"
struct timer {

    s_time_t expires;


    union {

        unsigned int heap_offset;

        struct timer *list_next;

        struct list_head inactive;
    };


    void (*function)(void *);
    void *data;



    uint16_t cpu;







    uint8_t status;
};
# 58 "/var/xen-dev/xen/xen/include/xen/timer.h"
void init_timer(
    struct timer *timer,
    void (*function)(void *),
    void *data,
    unsigned int cpu);


void set_timer(struct timer *timer, s_time_t expires);





void stop_timer(struct timer *timer);


_Bool timer_expires_before(struct timer *timer, s_time_t t);
# 85 "/var/xen-dev/xen/xen/include/xen/timer.h"
static __inline__ _Bool timer_is_active(const struct timer *timer)
{
    do { if ( __builtin_expect(!!(!(timer->status <= 4)),0) ) do { do { ({ _Static_assert(!((87) >> ((31 - 24) + (31 - 24))), "!(" "(87) >> (BUG_LINE_LO_WIDTH + BUG_LINE_HI_WIDTH)" ")"); }); ({ _Static_assert(!((3) >= 4), "!(" "(3) >= BUGFRAME_NR" ")"); }); asm volatile ( ".Lbug%=: ud2\n" ".pushsection .bug_frames.%c[bf_type], \"a\", @progbits\n" ".p2align 2\n" ".Lfrm%=:\n" ".long (.Lbug%= - .Lfrm%=) + %c[bf_line_hi]\n" ".long (%c[bf_ptr] - .Lfrm%=) + %c[bf_line_lo]\n" ".if " "1" "\n" ".long 0, %c[bf_msg] - .Lfrm%=\n" ".endif\n" ".popsection\n" :: [bf_type] "i" (3), [bf_ptr] "i" ("/var/xen-dev/xen/xen/include/xen/timer.h"), [bf_msg] "i" ("timer->status <= TIMER_STATUS_in_list"), [bf_line_lo] "i" ((87 & ((1 << (31 - 24)) - 1)) << 24), [bf_line_hi] "i" (((87) >> (31 - 24)) << 24) ); } while (0); __builtin_unreachable(); } while (0); } while (0);
    return timer->status >= 3;
}


void migrate_timer(struct timer *timer, unsigned int new_cpu);






void kill_timer(struct timer *timer);


void timer_init(void);


extern __typeof__(s_time_t) per_cpu__timer_deadline;


int reprogram_timer(s_time_t timeout);


s_time_t align_timer(s_time_t firsttick, uint64_t period);
# 10 "/var/xen-dev/xen/xen/include/xen/sched.h" 2
# 1 "/var/xen-dev/xen/xen/include/xen/rangeset.h" 1
# 15 "/var/xen-dev/xen/xen/include/xen/rangeset.h"
struct domain;
struct rangeset;
# 25 "/var/xen-dev/xen/xen/include/xen/rangeset.h"
void rangeset_domain_initialise(
    struct domain *d);
void rangeset_domain_destroy(
    struct domain *d);
# 38 "/var/xen-dev/xen/xen/include/xen/rangeset.h"
struct rangeset *rangeset_new(
    struct domain *d, char *name, unsigned int flags);
void rangeset_destroy(
    struct rangeset *r);





void rangeset_limit(
    struct rangeset *r, unsigned int limit);






bool_t __attribute__((__warn_unused_result__)) rangeset_is_empty(
    const struct rangeset *r);


int __attribute__((__warn_unused_result__)) rangeset_add_range(
    struct rangeset *r, unsigned long s, unsigned long e);
int __attribute__((__warn_unused_result__)) rangeset_claim_range(struct rangeset *r, unsigned long size,
                                      unsigned long *s);
int __attribute__((__warn_unused_result__)) rangeset_remove_range(
    struct rangeset *r, unsigned long s, unsigned long e);
bool_t __attribute__((__warn_unused_result__)) rangeset_contains_range(
    struct rangeset *r, unsigned long s, unsigned long e);
bool_t __attribute__((__warn_unused_result__)) rangeset_overlaps_range(
    struct rangeset *r, unsigned long s, unsigned long e);
int rangeset_report_ranges(
    struct rangeset *r, unsigned long s, unsigned long e,
    int (*cb)(unsigned long s, unsigned long e, void *), void *ctxt);






int rangeset_consume_ranges(struct rangeset *r,
                            int (*cb)(unsigned long s, unsigned long e,
                                      void *, unsigned long *c),
                            void *ctxt);


int __attribute__((__warn_unused_result__)) rangeset_merge(struct rangeset *r1, struct rangeset *r2);


int __attribute__((__warn_unused_result__)) rangeset_add_singleton(
    struct rangeset *r, unsigned long s);
int __attribute__((__warn_unused_result__)) rangeset_remove_singleton(
    struct rangeset *r, unsigned long s);
bool_t __attribute__((__warn_unused_result__)) rangeset_contains_singleton(
    struct rangeset *r, unsigned long s);


void rangeset_swap(struct rangeset *a, struct rangeset *b);


void rangeset_printk(
    struct rangeset *r);
void rangeset_domain_printk(
    struct domain *d);
# 11 "/var/xen-dev/xen/xen/include/xen/sched.h" 2
# 1 "/var/xen-dev/xen/xen/include/xen/domain.h" 1







# 1 "/var/xen-dev/xen/xen/include/asm/domain.h" 1




# 1 "/var/xen-dev/xen/xen/include/xen/radix-tree.h" 1
# 24 "/var/xen-dev/xen/xen/include/xen/radix-tree.h"
# 1 "/var/xen-dev/xen/xen/include/xen/rcupdate.h" 1
# 37 "/var/xen-dev/xen/xen/include/xen/rcupdate.h"
# 1 "/var/xen-dev/xen/xen/include/xen/preempt.h" 1
# 15 "/var/xen-dev/xen/xen/include/xen/preempt.h"
extern __typeof__(unsigned int) per_cpu____preempt_count;
# 29 "/var/xen-dev/xen/xen/include/xen/preempt.h"
bool_t in_atomic(void);


void ASSERT_NOT_IN_ATOMIC(void);
# 38 "/var/xen-dev/xen/xen/include/xen/rcupdate.h" 2
# 46 "/var/xen-dev/xen/xen/include/xen/rcupdate.h"
struct rcu_head {
    struct rcu_head *next;
    void (*func)(struct rcu_head *head);
};
# 58 "/var/xen-dev/xen/xen/include/xen/rcupdate.h"
int rcu_pending(int cpu);
int rcu_needs_cpu(int cpu);





struct _rcu_read_lock {};
typedef struct _rcu_read_lock rcu_read_lock_t;
# 139 "/var/xen-dev/xen/xen/include/xen/rcupdate.h"
void rcu_init(void);
void rcu_check_callbacks(int cpu);


void call_rcu(struct rcu_head *head,
              void (*func)(struct rcu_head *head));

int rcu_barrier(void);

void rcu_idle_enter(unsigned int cpu);
void rcu_idle_exit(unsigned int cpu);

void rcu_idle_timer_start(void);
void rcu_idle_timer_stop(void);
# 25 "/var/xen-dev/xen/xen/include/xen/radix-tree.h" 2
# 42 "/var/xen-dev/xen/xen/include/xen/radix-tree.h"
static __inline__ int radix_tree_is_indirect_ptr(void *ptr)
{
 return (int)((unsigned long)ptr & 1);
}
# 57 "/var/xen-dev/xen/xen/include/xen/radix-tree.h"
struct radix_tree_node {
 unsigned int height;
 unsigned int count;
 void *slots[(1UL << 6)];
};

typedef struct radix_tree_node *radix_tree_alloc_fn_t(void *);
typedef void radix_tree_free_fn_t(struct radix_tree_node *, void *);

struct radix_tree_root {
 unsigned int height;
 struct radix_tree_node *rnode;


 radix_tree_alloc_fn_t *node_alloc;
 radix_tree_free_fn_t *node_free;
 void *node_alloc_free_arg;
};





void radix_tree_init(struct radix_tree_root *root);
void radix_tree_set_alloc_callbacks(
 struct radix_tree_root *root,
 radix_tree_alloc_fn_t *node_alloc,
 radix_tree_free_fn_t *node_free,
 void *node_alloc_free_arg);

void radix_tree_destroy(
 struct radix_tree_root *root,
 void (*slot_free)(void *));
# 140 "/var/xen-dev/xen/xen/include/xen/radix-tree.h"
static __inline__ void *radix_tree_deref_slot(void **pslot)
{
 return (*pslot);
}
# 152 "/var/xen-dev/xen/xen/include/xen/radix-tree.h"
static __inline__ int radix_tree_deref_retry(void *arg)
{
 return __builtin_expect(!!((unsigned long)arg & 1),0);
}
# 165 "/var/xen-dev/xen/xen/include/xen/radix-tree.h"
static __inline__ void radix_tree_replace_slot(void **pslot, void *item)
{
 do { if (__builtin_expect(!!(radix_tree_is_indirect_ptr(item)),0)) do { do { ({ _Static_assert(!((167) >> ((31 - 24) + (31 - 24))), "!(" "(167) >> (BUG_LINE_LO_WIDTH + BUG_LINE_HI_WIDTH)" ")"); }); ({ _Static_assert(!((2) >= 4), "!(" "(2) >= BUGFRAME_NR" ")"); }); asm volatile ( ".Lbug%=: ud2\n" ".pushsection .bug_frames.%c[bf_type], \"a\", @progbits\n" ".p2align 2\n" ".Lfrm%=:\n" ".long (.Lbug%= - .Lfrm%=) + %c[bf_line_hi]\n" ".long (%c[bf_ptr] - .Lfrm%=) + %c[bf_line_lo]\n" ".if " "0" "\n" ".long 0, %c[bf_msg] - .Lfrm%=\n" ".endif\n" ".popsection\n" :: [bf_type] "i" (2), [bf_ptr] "i" ("/var/xen-dev/xen/xen/include/xen/radix-tree.h"), [bf_msg] "i" (((void*)0)), [bf_line_lo] "i" ((167 & ((1 << (31 - 24)) - 1)) << 24), [bf_line_hi] "i" (((167) >> (31 - 24)) << 24) ); } while (0); __builtin_unreachable(); } while (0); } while (0);
 ({ __asm__ __volatile__("": : :"memory"); (*pslot) = (item); });
}
# 180 "/var/xen-dev/xen/xen/include/xen/radix-tree.h"
static __inline__ void *radix_tree_int_to_ptr(int val)
{
    long _ptr = ((long)val << 2) | 0x2l;
    do { if ( __builtin_expect(!!(!((_ptr >> 2) == val)),0) ) do { do { ({ _Static_assert(!((183) >> ((31 - 24) + (31 - 24))), "!(" "(183) >> (BUG_LINE_LO_WIDTH + BUG_LINE_HI_WIDTH)" ")"); }); ({ _Static_assert(!((3) >= 4), "!(" "(3) >= BUGFRAME_NR" ")"); }); asm volatile ( ".Lbug%=: ud2\n" ".pushsection .bug_frames.%c[bf_type], \"a\", @progbits\n" ".p2align 2\n" ".Lfrm%=:\n" ".long (.Lbug%= - .Lfrm%=) + %c[bf_line_hi]\n" ".long (%c[bf_ptr] - .Lfrm%=) + %c[bf_line_lo]\n" ".if " "1" "\n" ".long 0, %c[bf_msg] - .Lfrm%=\n" ".endif\n" ".popsection\n" :: [bf_type] "i" (3), [bf_ptr] "i" ("/var/xen-dev/xen/xen/include/xen/radix-tree.h"), [bf_msg] "i" ("(_ptr >> 2) == val"), [bf_line_lo] "i" ((183 & ((1 << (31 - 24)) - 1)) << 24), [bf_line_hi] "i" (((183) >> (31 - 24)) << 24) ); } while (0); __builtin_unreachable(); } while (0); } while (0);
    return (void *)_ptr;
}

static __inline__ int radix_tree_ptr_to_int(void *ptr)
{
    do { if ( __builtin_expect(!!(!(((long)ptr & 0x3) == 0x2)),0) ) do { do { ({ _Static_assert(!((189) >> ((31 - 24) + (31 - 24))), "!(" "(189) >> (BUG_LINE_LO_WIDTH + BUG_LINE_HI_WIDTH)" ")"); }); ({ _Static_assert(!((3) >= 4), "!(" "(3) >= BUGFRAME_NR" ")"); }); asm volatile ( ".Lbug%=: ud2\n" ".pushsection .bug_frames.%c[bf_type], \"a\", @progbits\n" ".p2align 2\n" ".Lfrm%=:\n" ".long (.Lbug%= - .Lfrm%=) + %c[bf_line_hi]\n" ".long (%c[bf_ptr] - .Lfrm%=) + %c[bf_line_lo]\n" ".if " "1" "\n" ".long 0, %c[bf_msg] - .Lfrm%=\n" ".endif\n" ".popsection\n" :: [bf_type] "i" (3), [bf_ptr] "i" ("/var/xen-dev/xen/xen/include/xen/radix-tree.h"), [bf_msg] "i" ("((long)ptr & 0x3) == 0x2"), [bf_line_lo] "i" ((189 & ((1 << (31 - 24)) - 1)) << 24), [bf_line_hi] "i" (((189) >> (31 - 24)) << 24) ); } while (0); __builtin_unreachable(); } while (0); } while (0);
    return (int)((long)ptr >> 2);
}

int radix_tree_insert(struct radix_tree_root *, unsigned long, void *);
void *radix_tree_lookup(struct radix_tree_root *, unsigned long);
void **radix_tree_lookup_slot(struct radix_tree_root *, unsigned long);
void *radix_tree_delete(struct radix_tree_root *, unsigned long);
unsigned int
radix_tree_gang_lookup(struct radix_tree_root *root, void **results,
   unsigned long first_index, unsigned int max_items);
unsigned int
radix_tree_gang_lookup_slot(struct radix_tree_root *root, void ***results,
   unsigned long first_index, unsigned int max_items);
unsigned long radix_tree_next_hole(struct radix_tree_root *root,
    unsigned long index, unsigned long max_scan);
unsigned long radix_tree_prev_hole(struct radix_tree_root *root,
    unsigned long index, unsigned long max_scan);
# 6 "/var/xen-dev/xen/xen/include/asm/domain.h" 2
# 1 "/var/xen-dev/xen/xen/include/asm/hvm/vcpu.h" 1
# 22 "/var/xen-dev/xen/xen/include/asm/hvm/vcpu.h"
# 1 "/var/xen-dev/xen/xen/include/xen/tasklet.h" 1
# 17 "/var/xen-dev/xen/xen/include/xen/tasklet.h"
struct tasklet
{
    struct list_head list;
    int scheduled_on;
    bool_t is_softirq;
    bool_t is_running;
    bool_t is_dead;
    void (*func)(unsigned long);
    unsigned long data;
};
# 37 "/var/xen-dev/xen/xen/include/xen/tasklet.h"
extern __typeof__(unsigned long) per_cpu__tasklet_work_to_do;





static __inline__ _Bool tasklet_work_to_do(unsigned int cpu)
{




    return (*({ unsigned long __ptr; __asm__ ("" : "=r"(__ptr) : "0"(&per_cpu__tasklet_work_to_do)); (typeof(&per_cpu__tasklet_work_to_do)) (__ptr + (__per_cpu_offset[cpu])); })) == ((1ul << 0)|
                                                (1ul << 1));
}

static __inline__ _Bool tasklet_is_scheduled(const struct tasklet *t)
{
    return t->scheduled_on != -1;
}

void tasklet_schedule_on_cpu(struct tasklet *t, unsigned int cpu);
void tasklet_schedule(struct tasklet *t);
void do_tasklet(void);
void tasklet_kill(struct tasklet *t);
void tasklet_init(
    struct tasklet *t, void (*func)(unsigned long), unsigned long data);
void softirq_tasklet_init(
    struct tasklet *t, void (*func)(unsigned long), unsigned long data);
void tasklet_subsys_init(void);
# 23 "/var/xen-dev/xen/xen/include/asm/hvm/vcpu.h" 2
# 1 "/var/xen-dev/xen/xen/include/asm/hvm/io.h" 1
# 23 "/var/xen-dev/xen/xen/include/asm/hvm/io.h"
# 1 "/var/xen-dev/xen/xen/include/xen/pci.h" 1
# 13 "/var/xen-dev/xen/xen/include/xen/pci.h"
# 1 "/var/xen-dev/xen/xen/include/xen/irq.h" 1
# 10 "/var/xen-dev/xen/xen/include/xen/irq.h"
# 1 "/var/xen-dev/xen/xen/include/asm/hardirq.h" 1






typedef struct {
 unsigned int __softirq_pending;
 unsigned int __local_irq_count;
 unsigned int __nmi_count;
 bool_t __mwait_wakeup;
} __attribute__((__aligned__((1 << (CONFIG_X86_L1_CACHE_SHIFT))))) irq_cpustat_t;

# 1 "/var/xen-dev/xen/xen/include/xen/irq_cpustat.h" 1
# 12 "/var/xen-dev/xen/xen/include/xen/irq_cpustat.h"
# 1 "/var/xen-dev/xen/xen/include/asm/hardirq.h" 1
# 13 "/var/xen-dev/xen/xen/include/xen/irq_cpustat.h" 2







extern irq_cpustat_t irq_stat[];
# 15 "/var/xen-dev/xen/xen/include/asm/hardirq.h" 2






void ack_bad_irq(unsigned int irq);

extern void apic_intr_init(void);
extern void smp_intr_init(void);
# 11 "/var/xen-dev/xen/xen/include/xen/irq.h" 2

struct irqaction {
    void (*handler)(int, void *, struct cpu_user_regs *);
    const char *name;
    void *dev_id;
    bool_t free_on_release;



};
# 49 "/var/xen-dev/xen/xen/include/xen/irq.h"
struct irq_desc;





struct hw_interrupt_type {
    const char *typename;
    unsigned int (*startup)(struct irq_desc *);
    void (*shutdown)(struct irq_desc *);
    void (*enable)(struct irq_desc *);
    void (*disable)(struct irq_desc *);
    void (*ack)(struct irq_desc *);



    void (*end)(struct irq_desc *);

    void (*set_affinity)(struct irq_desc *, const cpumask_t *);
};

typedef const struct hw_interrupt_type hw_irq_controller;

# 1 "/var/xen-dev/xen/xen/include/asm/irq.h" 1






# 1 "/var/xen-dev/xen/xen/include/asm/numa.h" 1







typedef u8 nodeid_t;

extern int srat_rev;

extern nodeid_t cpu_to_node[NR_CPUS];
extern cpumask_t node_to_cpumask[];






struct node {
 u64 start,end;
};

extern int compute_hash_shift(struct node *nodes, int numnodes,
         nodeid_t *nodeids);
extern nodeid_t pxm_to_node(unsigned int pxm);




extern void numa_add_cpu(int cpu);
extern void numa_init_array(void);
extern _Bool numa_off;


extern int srat_disabled(void);
extern void numa_set_node(int cpu, nodeid_t node);
extern nodeid_t setup_node(unsigned int pxm);
extern void srat_detect_node(int cpu);

extern void setup_node_bootmem(nodeid_t nodeid, u64 start, u64 end);
extern nodeid_t apicid_to_node[];
extern void init_cpu_to_node(void);

static __inline__ void clear_node_cpumask(int cpu)
{
 cpumask_clear_cpu(cpu, &node_to_cpumask[(cpu_to_node[cpu])]);
}


extern int memnode_shift;
extern unsigned long memnodemapsize;
extern u8 *memnodemap;

struct node_data {
    unsigned long node_start_pfn;
    unsigned long node_spanned_pages;
};

extern struct node_data node_data[];

static __inline__ __attribute__((pure)) nodeid_t phys_to_nid(paddr_t addr)
{
 nodeid_t nid;
 ;
 nid = memnodemap[pfn_to_pdx(((unsigned long)((addr) >> 12))) >> memnode_shift];
 ;
 return nid;
}
# 78 "/var/xen-dev/xen/xen/include/asm/numa.h"
extern int valid_numa_range(u64 start, u64 end, nodeid_t node);

void srat_parse_regions(u64 addr);
extern u8 __node_distance(nodeid_t a, nodeid_t b);
unsigned int arch_get_dma_bitsize(void);
# 8 "/var/xen-dev/xen/xen/include/asm/irq.h" 2



# 1 "/var/xen-dev/xen/xen/include/asm/hvm/irq.h" 1
# 26 "/var/xen-dev/xen/xen/include/asm/hvm/irq.h"
# 1 "/var/xen-dev/xen/xen/include/asm/hvm/hvm.h" 1
# 25 "/var/xen-dev/xen/xen/include/asm/hvm/hvm.h"
# 1 "/var/xen-dev/xen/xen/include/asm/hvm/asid.h" 1
# 23 "/var/xen-dev/xen/xen/include/asm/hvm/asid.h"
struct vcpu;
struct hvm_vcpu_asid;


void hvm_asid_init(int nasids);


void hvm_asid_flush_vcpu_asid(struct hvm_vcpu_asid *asid);


void hvm_asid_flush_vcpu(struct vcpu *v);


void hvm_asid_flush_core(void);



bool_t hvm_asid_handle_vmenter(struct hvm_vcpu_asid *asid);
# 26 "/var/xen-dev/xen/xen/include/asm/hvm/hvm.h" 2

# 1 "/var/xen-dev/xen/xen/include/public/hvm/save.h" 1
# 28 "/var/xen-dev/xen/xen/include/asm/hvm/hvm.h" 2
# 38 "/var/xen-dev/xen/xen/include/asm/hvm/hvm.h"
enum hvm_intsrc {
    hvm_intsrc_none,
    hvm_intsrc_pic,
    hvm_intsrc_lapic,
    hvm_intsrc_nmi,
    hvm_intsrc_mce,
    hvm_intsrc_vector
};
struct hvm_intack {
    uint8_t source;
    uint8_t vector;
};







enum hvm_intblk {
    hvm_intblk_none,
    hvm_intblk_shadow,
    hvm_intblk_rflags_ie,
    hvm_intblk_tpr,
    hvm_intblk_nmi_iret,
    hvm_intblk_arch,
};
# 91 "/var/xen-dev/xen/xen/include/asm/hvm/hvm.h"
struct hvm_function_table {
    char *name;


    bool_t hap_supported;


    _Bool altp2m_supported;


    _Bool virtual_intr_delivery_enabled;


    unsigned int hap_capabilities;




    int (*domain_initialise)(struct domain *d);
    void (*domain_destroy)(struct domain *d);
    int (*vcpu_initialise)(struct vcpu *v);
    void (*vcpu_destroy)(struct vcpu *v);


    void (*save_cpu_ctxt)(struct vcpu *v, struct hvm_hw_cpu *ctxt);
    int (*load_cpu_ctxt)(struct vcpu *v, struct hvm_hw_cpu *ctxt);


    unsigned int (*get_interrupt_shadow)(struct vcpu *v);
    void (*set_interrupt_shadow)(struct vcpu *v, unsigned int intr_shadow);
    int (*guest_x86_mode)(struct vcpu *v);
    unsigned int (*get_cpl)(struct vcpu *v);
    void (*get_segment_register)(struct vcpu *v, enum x86_segment seg,
                                 struct segment_register *reg);
    void (*set_segment_register)(struct vcpu *v, enum x86_segment seg,
                                 struct segment_register *reg);
    unsigned long (*get_shadow_gs_base)(struct vcpu *v);




    void (*update_host_cr3)(struct vcpu *v);




    void (*update_guest_cr)(struct vcpu *v, unsigned int cr,
                            unsigned int flags);
    void (*update_guest_efer)(struct vcpu *v);

    void (*cpuid_policy_changed)(struct vcpu *v);

    void (*fpu_leave)(struct vcpu *v);

    int (*get_guest_pat)(struct vcpu *v, u64 *);
    int (*set_guest_pat)(struct vcpu *v, u64);

    _Bool (*get_guest_bndcfgs)(struct vcpu *v, u64 *);
    _Bool (*set_guest_bndcfgs)(struct vcpu *v, u64);

    void (*set_tsc_offset)(struct vcpu *v, u64 offset, u64 at_tsc);

    void (*inject_event)(const struct x86_event *event);

    void (*init_hypercall_page)(void *ptr);

    _Bool (*event_pending)(const struct vcpu *v);
    _Bool (*get_pending_event)(struct vcpu *v, struct x86_event *info);
    void (*invlpg)(struct vcpu *v, unsigned long linear);

    int (*cpu_up_prepare)(unsigned int cpu);
    void (*cpu_dead)(unsigned int cpu);

    int (*cpu_up)(void);
    void (*cpu_down)(void);


    unsigned int (*get_insn_bytes)(struct vcpu *v, uint8_t *buf);


    void (*wbinvd_intercept)(void);
    void (*fpu_dirty_intercept)(void);
    int (*msr_read_intercept)(unsigned int msr, uint64_t *msr_content);
    int (*msr_write_intercept)(unsigned int msr, uint64_t msr_content);
    void (*handle_cd)(struct vcpu *v, unsigned long value);
    void (*set_info_guest)(struct vcpu *v);
    void (*set_rdtsc_exiting)(struct vcpu *v, bool_t);
    void (*set_descriptor_access_exiting)(struct vcpu *v, _Bool);


    int (*nhvm_vcpu_initialise)(struct vcpu *v);
    void (*nhvm_vcpu_destroy)(struct vcpu *v);
    int (*nhvm_vcpu_reset)(struct vcpu *v);
    int (*nhvm_vcpu_vmexit_event)(struct vcpu *v, const struct x86_event *event);
    uint64_t (*nhvm_vcpu_p2m_base)(struct vcpu *v);
    bool_t (*nhvm_vmcx_guest_intercepts_event)(
        struct vcpu *v, unsigned int vector, int errcode);

    bool_t (*nhvm_vmcx_hap_enabled)(struct vcpu *v);

    enum hvm_intblk (*nhvm_intr_blocked)(struct vcpu *v);
    void (*nhvm_domain_relinquish_resources)(struct domain *d);


    void (*update_eoi_exit_bitmap)(struct vcpu *v, u8 vector, u8 trig);
    void (*process_isr)(int isr, struct vcpu *v);
    void (*deliver_posted_intr)(struct vcpu *v, u8 vector);
    void (*sync_pir_to_irr)(struct vcpu *v);
    _Bool (*test_pir)(const struct vcpu *v, uint8_t vector);
    void (*handle_eoi)(uint8_t vector, int isr);


    int (*nhvm_hap_walk_L1_p2m)(struct vcpu *v, paddr_t L2_gpa,
                                paddr_t *L1_gpa, unsigned int *page_order,
                                uint8_t *p2m_acc, bool_t access_r,
                                bool_t access_w, bool_t access_x);

    void (*enable_msr_interception)(struct domain *d, uint32_t msr);
    bool_t (*is_singlestep_supported)(void);


    void (*altp2m_vcpu_update_p2m)(struct vcpu *v);
    void (*altp2m_vcpu_update_vmfunc_ve)(struct vcpu *v);
    bool_t (*altp2m_vcpu_emulate_ve)(struct vcpu *v);
    int (*altp2m_vcpu_emulate_vmfunc)(const struct cpu_user_regs *regs);





    struct {

        uint8_t ratio_frac_bits;

        uint64_t max_ratio;


        void (*setup)(struct vcpu *v);
    } tsc_scaling;
};

extern struct hvm_function_table hvm_funcs;
extern bool_t hvm_enabled;
extern s8 hvm_port80_allowed;

extern const struct hvm_function_table *start_svm(void);
extern const struct hvm_function_table *start_vmx(void);

int hvm_domain_initialise(struct domain *d);
void hvm_domain_relinquish_resources(struct domain *d);
void hvm_domain_destroy(struct domain *d);

int hvm_vcpu_initialise(struct vcpu *v);
void hvm_vcpu_destroy(struct vcpu *v);
void hvm_vcpu_down(struct vcpu *v);
int hvm_vcpu_cacheattr_init(struct vcpu *v);
void hvm_vcpu_cacheattr_destroy(struct vcpu *v);
void hvm_vcpu_reset_state(struct vcpu *v, uint16_t cs, uint16_t ip);

void hvm_get_guest_pat(struct vcpu *v, u64 *guest_pat);
int hvm_set_guest_pat(struct vcpu *v, u64 guest_pat);

u64 hvm_get_guest_tsc_fixed(struct vcpu *v, u64 at_tsc);

u64 hvm_scale_tsc(const struct domain *d, u64 tsc);
u64 hvm_get_tsc_scaling_ratio(u32 gtsc_khz);

void hvm_init_guest_time(struct domain *d);
void hvm_set_guest_time(struct vcpu *v, u64 guest_time);
uint64_t hvm_get_guest_time_fixed(const struct vcpu *v, uint64_t at_tsc);

int vmsi_deliver(
    struct domain *d, int vector,
    uint8_t dest, uint8_t dest_mode,
    uint8_t delivery_mode, uint8_t trig_mode);
struct hvm_pirq_dpci;
void vmsi_deliver_pirq(struct domain *d, const struct hvm_pirq_dpci *);
int hvm_girq_dest_2_vcpu_id(struct domain *d, uint8_t dest, uint8_t dest_mode);

enum hvm_intblk
hvm_interrupt_blocked(struct vcpu *v, struct hvm_intack intack);

void hvm_init_hypercall_page(struct domain *d, void *ptr);

void hvm_get_segment_register(struct vcpu *v, enum x86_segment seg,
                              struct segment_register *reg);
void hvm_set_segment_register(struct vcpu *v, enum x86_segment seg,
                              struct segment_register *reg);

_Bool hvm_set_guest_bndcfgs(struct vcpu *v, u64 val);

int hvm_vmexit_cpuid(struct cpu_user_regs *regs, unsigned int inst_len);
void hvm_migrate_timers(struct vcpu *v);
void hvm_do_resume(struct vcpu *v);
void hvm_migrate_pirq(struct hvm_pirq_dpci *pirq_dpci, const struct vcpu *v);
void hvm_migrate_pirqs(struct vcpu *v);

void hvm_inject_event(const struct x86_event *event);

int hvm_event_needs_reinjection(uint8_t type, uint8_t vector);

uint8_t hvm_combine_hw_exceptions(uint8_t vec1, uint8_t vec2);

void hvm_set_rdtsc_exiting(struct domain *d, bool_t enable);

enum hvm_task_switch_reason { TSW_jmp, TSW_iret, TSW_call_or_int };
void hvm_task_switch(
    uint16_t tss_sel, enum hvm_task_switch_reason taskswitch_reason,
    int32_t errcode, unsigned int insn_len, unsigned int extra_eflags);

enum hvm_access_type {
    hvm_access_insn_fetch,
    hvm_access_none,
    hvm_access_read,
    hvm_access_write
};
bool_t hvm_virtual_to_linear_addr(
    enum x86_segment seg,
    const struct segment_register *reg,
    unsigned long offset,
    unsigned int bytes,
    enum hvm_access_type access_type,
    const struct segment_register *active_cs,
    unsigned long *linear_addr);

void *hvm_map_guest_frame_rw(unsigned long gfn, bool_t permanent,
                             bool_t *writable);
void *hvm_map_guest_frame_ro(unsigned long gfn, bool_t permanent);
void hvm_unmap_guest_frame(void *p, bool_t permanent);
void hvm_mapped_guest_frames_mark_dirty(struct domain *);

int hvm_debug_op(struct vcpu *v, int32_t op);


void hvm_toggle_singlestep(struct vcpu *v);

int hvm_hap_nested_page_fault(paddr_t gpa, unsigned long gla,
                              struct npfec npfec);


const char *hvm_efer_valid(const struct vcpu *v, uint64_t value,
                           signed int cr0_pg);
unsigned long hvm_cr4_guest_valid_bits(const struct domain *d, _Bool restore);

_Bool hvm_flush_vcpu_tlb(_Bool (*flush_vcpu)(void *ctxt, struct vcpu *v),
                        void *ctxt);
# 679 "/var/xen-dev/xen/xen/include/asm/hvm/hvm.h"
int hvm_guest_x86_mode(struct vcpu *v);
unsigned long hvm_get_shadow_gs_base(struct vcpu *v);
void hvm_set_info_guest(struct vcpu *v);
void hvm_cpuid_policy_changed(struct vcpu *v);
void hvm_set_tsc_offset(struct vcpu *v, uint64_t offset, uint64_t at_tsc);
_Bool hvm_get_guest_bndcfgs(struct vcpu *v, uint64_t *val);




static __inline__ _Bool hvm_is_singlestep_supported(void)
{
    return 0;
}

static __inline__ _Bool hvm_hap_supported(void)
{
    return 0;
}

static __inline__ _Bool nhvm_vmcx_hap_enabled(const struct vcpu *v)
{
    do { do { ({ _Static_assert(!((701) >> ((31 - 24) + (31 - 24))), "!(" "(701) >> (BUG_LINE_LO_WIDTH + BUG_LINE_HI_WIDTH)" ")"); }); ({ _Static_assert(!((3) >= 4), "!(" "(3) >= BUGFRAME_NR" ")"); }); asm volatile ( ".Lbug%=: ud2\n" ".pushsection .bug_frames.%c[bf_type], \"a\", @progbits\n" ".p2align 2\n" ".Lfrm%=:\n" ".long (.Lbug%= - .Lfrm%=) + %c[bf_line_hi]\n" ".long (%c[bf_ptr] - .Lfrm%=) + %c[bf_line_lo]\n" ".if " "1" "\n" ".long 0, %c[bf_msg] - .Lfrm%=\n" ".endif\n" ".popsection\n" :: [bf_type] "i" (3), [bf_ptr] "i" ("/var/xen-dev/xen/xen/include/asm/hvm/hvm.h"), [bf_msg] "i" ("unreachable"), [bf_line_lo] "i" ((701 & ((1 << (31 - 24)) - 1)) << 24), [bf_line_hi] "i" (((701) >> (31 - 24)) << 24) ); } while (0); __builtin_unreachable(); } while (0);
    return 0;
}



static __inline__ int hvm_cpu_up(void)
{
    return 0;
}

static __inline__ void hvm_cpu_down(void) {}

static __inline__ void hvm_flush_guest_tlbs(void) {}

static __inline__ void hvm_invlpg(const struct vcpu *v, unsigned long linear)
{
    do { do { ({ _Static_assert(!((718) >> ((31 - 24) + (31 - 24))), "!(" "(718) >> (BUG_LINE_LO_WIDTH + BUG_LINE_HI_WIDTH)" ")"); }); ({ _Static_assert(!((3) >= 4), "!(" "(3) >= BUGFRAME_NR" ")"); }); asm volatile ( ".Lbug%=: ud2\n" ".pushsection .bug_frames.%c[bf_type], \"a\", @progbits\n" ".p2align 2\n" ".Lfrm%=:\n" ".long (.Lbug%= - .Lfrm%=) + %c[bf_line_hi]\n" ".long (%c[bf_ptr] - .Lfrm%=) + %c[bf_line_lo]\n" ".if " "1" "\n" ".long 0, %c[bf_msg] - .Lfrm%=\n" ".endif\n" ".popsection\n" :: [bf_type] "i" (3), [bf_ptr] "i" ("/var/xen-dev/xen/xen/include/asm/hvm/hvm.h"), [bf_msg] "i" ("unreachable"), [bf_line_lo] "i" ((718 & ((1 << (31 - 24)) - 1)) << 24), [bf_line_hi] "i" (((718) >> (31 - 24)) << 24) ); } while (0); __builtin_unreachable(); } while (0);
}





static __inline__ void hvm_update_host_cr3(const struct vcpu *v)
{
    do { do { ({ _Static_assert(!((727) >> ((31 - 24) + (31 - 24))), "!(" "(727) >> (BUG_LINE_LO_WIDTH + BUG_LINE_HI_WIDTH)" ")"); }); ({ _Static_assert(!((3) >= 4), "!(" "(3) >= BUGFRAME_NR" ")"); }); asm volatile ( ".Lbug%=: ud2\n" ".pushsection .bug_frames.%c[bf_type], \"a\", @progbits\n" ".p2align 2\n" ".Lfrm%=:\n" ".long (.Lbug%= - .Lfrm%=) + %c[bf_line_hi]\n" ".long (%c[bf_ptr] - .Lfrm%=) + %c[bf_line_lo]\n" ".if " "1" "\n" ".long 0, %c[bf_msg] - .Lfrm%=\n" ".endif\n" ".popsection\n" :: [bf_type] "i" (3), [bf_ptr] "i" ("/var/xen-dev/xen/xen/include/asm/hvm/hvm.h"), [bf_msg] "i" ("unreachable"), [bf_line_lo] "i" ((727 & ((1 << (31 - 24)) - 1)) << 24), [bf_line_hi] "i" (((727) >> (31 - 24)) << 24) ); } while (0); __builtin_unreachable(); } while (0);
}

static __inline__ void hvm_update_guest_cr3(const struct vcpu *v, _Bool noflush)
{
    do { do { ({ _Static_assert(!((732) >> ((31 - 24) + (31 - 24))), "!(" "(732) >> (BUG_LINE_LO_WIDTH + BUG_LINE_HI_WIDTH)" ")"); }); ({ _Static_assert(!((3) >= 4), "!(" "(3) >= BUGFRAME_NR" ")"); }); asm volatile ( ".Lbug%=: ud2\n" ".pushsection .bug_frames.%c[bf_type], \"a\", @progbits\n" ".p2align 2\n" ".Lfrm%=:\n" ".long (.Lbug%= - .Lfrm%=) + %c[bf_line_hi]\n" ".long (%c[bf_ptr] - .Lfrm%=) + %c[bf_line_lo]\n" ".if " "1" "\n" ".long 0, %c[bf_msg] - .Lfrm%=\n" ".endif\n" ".popsection\n" :: [bf_type] "i" (3), [bf_ptr] "i" ("/var/xen-dev/xen/xen/include/asm/hvm/hvm.h"), [bf_msg] "i" ("unreachable"), [bf_line_lo] "i" ((732 & ((1 << (31 - 24)) - 1)) << 24), [bf_line_hi] "i" (((732) >> (31 - 24)) << 24) ); } while (0); __builtin_unreachable(); } while (0);
}

static __inline__ unsigned int hvm_get_cpl(const struct vcpu *v)
{
    do { do { ({ _Static_assert(!((737) >> ((31 - 24) + (31 - 24))), "!(" "(737) >> (BUG_LINE_LO_WIDTH + BUG_LINE_HI_WIDTH)" ")"); }); ({ _Static_assert(!((3) >= 4), "!(" "(3) >= BUGFRAME_NR" ")"); }); asm volatile ( ".Lbug%=: ud2\n" ".pushsection .bug_frames.%c[bf_type], \"a\", @progbits\n" ".p2align 2\n" ".Lfrm%=:\n" ".long (.Lbug%= - .Lfrm%=) + %c[bf_line_hi]\n" ".long (%c[bf_ptr] - .Lfrm%=) + %c[bf_line_lo]\n" ".if " "1" "\n" ".long 0, %c[bf_msg] - .Lfrm%=\n" ".endif\n" ".popsection\n" :: [bf_type] "i" (3), [bf_ptr] "i" ("/var/xen-dev/xen/xen/include/asm/hvm/hvm.h"), [bf_msg] "i" ("unreachable"), [bf_line_lo] "i" ((737 & ((1 << (31 - 24)) - 1)) << 24), [bf_line_hi] "i" (((737) >> (31 - 24)) << 24) ); } while (0); __builtin_unreachable(); } while (0);
    return -1;
}

static __inline__ _Bool hvm_event_pending(const struct vcpu *v)
{
    return 0;
}

static __inline__ void hvm_inject_hw_exception(unsigned int vector, int errcode)
{
    do { do { ({ _Static_assert(!((748) >> ((31 - 24) + (31 - 24))), "!(" "(748) >> (BUG_LINE_LO_WIDTH + BUG_LINE_HI_WIDTH)" ")"); }); ({ _Static_assert(!((3) >= 4), "!(" "(3) >= BUGFRAME_NR" ")"); }); asm volatile ( ".Lbug%=: ud2\n" ".pushsection .bug_frames.%c[bf_type], \"a\", @progbits\n" ".p2align 2\n" ".Lfrm%=:\n" ".long (.Lbug%= - .Lfrm%=) + %c[bf_line_hi]\n" ".long (%c[bf_ptr] - .Lfrm%=) + %c[bf_line_lo]\n" ".if " "1" "\n" ".long 0, %c[bf_msg] - .Lfrm%=\n" ".endif\n" ".popsection\n" :: [bf_type] "i" (3), [bf_ptr] "i" ("/var/xen-dev/xen/xen/include/asm/hvm/hvm.h"), [bf_msg] "i" ("unreachable"), [bf_line_lo] "i" ((748 & ((1 << (31 - 24)) - 1)) << 24), [bf_line_hi] "i" (((748) >> (31 - 24)) << 24) ); } while (0); __builtin_unreachable(); } while (0);
}

static __inline__ _Bool hvm_has_set_descriptor_access_exiting(void)
{
    return 0;
}
# 27 "/var/xen-dev/xen/xen/include/asm/hvm/irq.h" 2
# 1 "/var/xen-dev/xen/xen/include/asm/hvm/vpic.h" 1
# 32 "/var/xen-dev/xen/xen/include/asm/hvm/vpic.h"
void vpic_irq_positive_edge(struct domain *d, int irq);
void vpic_irq_negative_edge(struct domain *d, int irq);
void vpic_init(struct domain *d);
void vpic_reset(struct domain *d);
int vpic_ack_pending_irq(struct vcpu *v);
int is_periodic_irq(struct vcpu *v, int irq, int type);
# 28 "/var/xen-dev/xen/xen/include/asm/hvm/irq.h" 2
# 1 "/var/xen-dev/xen/xen/include/asm/hvm/vioapic.h" 1
# 50 "/var/xen-dev/xen/xen/include/asm/hvm/vioapic.h"
struct hvm_vioapic {
    struct domain *domain;
    uint32_t nr_pins;
    unsigned int base_gsi;
    union {
        XEN_HVM_VIOAPIC(,);
        struct hvm_hw_vioapic domU;
    };
};





int vioapic_init(struct domain *d);
void vioapic_deinit(struct domain *d);
void vioapic_reset(struct domain *d);
void vioapic_irq_positive_edge(struct domain *d, unsigned int irq);
void vioapic_update_EOI(struct domain *d, u8 vector);

int vioapic_get_mask(const struct domain *d, unsigned int gsi);
int vioapic_get_vector(const struct domain *d, unsigned int gsi);
int vioapic_get_trigger_mode(const struct domain *d, unsigned int gsi);
# 29 "/var/xen-dev/xen/xen/include/asm/hvm/irq.h" 2

struct hvm_irq {




    struct hvm_hw_pci_irqs pci_intx;





    struct hvm_hw_isa_irqs isa_irq;







    struct hvm_hw_pci_link pci_link;


    uint32_t callback_via_asserted;
    union {
        enum {
            HVMIRQ_callback_none,
            HVMIRQ_callback_gsi,
            HVMIRQ_callback_pci_intx,
            HVMIRQ_callback_vector
        } callback_via_type;
    };
    union {
        uint32_t gsi;
        struct { uint8_t dev, intx; } pci;
        uint32_t vector;
    } callback_via;


    u8 pci_link_assert_count[4];
# 78 "/var/xen-dev/xen/xen/include/asm/hvm/irq.h"
    u8 round_robin_prev_vcpu;

    struct hvm_irq_dpci *dpci;
# 92 "/var/xen-dev/xen/xen/include/asm/hvm/irq.h"
    unsigned int nr_gsis;
    u8 gsi_assert_count[];
};
# 106 "/var/xen-dev/xen/xen/include/asm/hvm/irq.h"
struct hvm_intack hvm_vcpu_has_pending_irq(struct vcpu *v);
struct hvm_intack hvm_vcpu_ack_pending_irq(struct vcpu *v,
                                           struct hvm_intack intack);

struct dev_intx_gsi_link {
    struct list_head list;
    uint8_t bus;
    uint8_t device;
    uint8_t intx;
};
# 134 "/var/xen-dev/xen/xen/include/asm/hvm/irq.h"
struct hvm_gmsi_info {
    uint32_t gvec;
    uint32_t gflags;
    int dest_vcpu_id;
    _Bool posted;
};

struct hvm_girq_dpci_mapping {
    struct list_head list;
    uint8_t bus;
    uint8_t device;
    uint8_t intx;
    uint8_t machine_gsi;
};






struct hvm_irq_dpci {

    struct list_head girq[(sizeof(((struct hvm_hw_vioapic *)0)->redirtbl) / sizeof((((struct hvm_hw_vioapic *)0)->redirtbl)[0]) + sizeof(struct { _Static_assert(!(__builtin_types_compatible_p(typeof(((struct hvm_hw_vioapic *)0)->redirtbl), typeof(&((struct hvm_hw_vioapic *)0)->redirtbl[0]))), "!(" "__builtin_types_compatible_p(typeof(((struct hvm_hw_vioapic *)0)->redirtbl), typeof(&((struct hvm_hw_vioapic *)0)->redirtbl[0]))" ")"); }))];

    unsigned long isairq_map[(((16)+BITS_PER_LONG-1)/BITS_PER_LONG)];

    uint8_t link_cnt[4];
};


struct hvm_pirq_dpci {
    uint32_t flags;
    unsigned int state;
    _Bool masked;
    uint16_t pending;
    struct list_head digl_list;
    struct domain *dom;
    struct hvm_gmsi_info gmsi;
    struct timer timer;
    struct list_head softirq_list;
};

void pt_pirq_init(struct domain *, struct hvm_pirq_dpci *);
_Bool pt_pirq_cleanup_check(struct hvm_pirq_dpci *);
int pt_pirq_iterate(struct domain *d,
                    int (*cb)(struct domain *,
                              struct hvm_pirq_dpci *, void *arg),
                    void *arg);




static __inline__ _Bool pt_pirq_softirq_active(struct hvm_pirq_dpci *dpci)
{
    return 0;
}



void hvm_pci_intx_assert(struct domain *d, unsigned int device,
                         unsigned int intx);
void hvm_pci_intx_deassert(struct domain *d, unsigned int device,
                           unsigned int intx);
# 205 "/var/xen-dev/xen/xen/include/asm/hvm/irq.h"
int hvm_isa_irq_assert(struct domain *d, unsigned int isa_irq,
                       int (*get_vector)(const struct domain *d,
                                         unsigned int gsi));
void hvm_isa_irq_deassert(struct domain *d, unsigned int isa_irq);


void hvm_gsi_assert(struct domain *d, unsigned int gsi);
void hvm_gsi_deassert(struct domain *d, unsigned int gsi);

int hvm_set_pci_link_route(struct domain *d, u8 link, u8 isa_irq);

int hvm_inject_msi(struct domain *d, uint64_t addr, uint32_t data);


int hvm_ioapic_assert(struct domain *d, unsigned int gsi, _Bool level);
void hvm_ioapic_deassert(struct domain *d, unsigned int gsi);

void hvm_maybe_deassert_evtchn_irq(void);
void hvm_assert_evtchn_irq(struct vcpu *v);
void hvm_set_callback_via(struct domain *d, uint64_t via);

struct pirq;
_Bool hvm_domain_use_pirq(const struct domain *, const struct pirq *);
# 12 "/var/xen-dev/xen/xen/include/asm/irq.h" 2
# 1 "/var/xen-dev/xen/xen/include/asm-x86/mach-default/irq_vectors.h" 1
# 13 "/var/xen-dev/xen/xen/include/asm/irq.h" 2

extern unsigned int nr_irqs_gsi;
extern unsigned int nr_irqs;
# 26 "/var/xen-dev/xen/xen/include/asm/irq.h"
typedef struct {
    unsigned long _bits[(((256)+BITS_PER_LONG-1)/BITS_PER_LONG)];
} vmask_t;

struct irq_desc;

struct arch_irq_desc {
        s16 vector;
        s16 old_vector;






        cpumask_var_t cpu_mask;
        cpumask_var_t old_cpu_mask;
        cpumask_var_t pending_mask;
        vmask_t *used_vectors;
        unsigned move_cleanup_count;
        u8 move_in_progress : 1;
        s8 used;




        domid_t creator_domid;
};
# 62 "/var/xen-dev/xen/xen/include/asm/irq.h"
typedef int vector_irq_t[256];
extern __typeof__(vector_irq_t) per_cpu__vector_irq;

extern _Bool opt_noirqbalance;






extern int opt_irq_vector_map;





extern __typeof__(struct cpu_user_regs *) per_cpu____irq_regs;

static __inline__ struct cpu_user_regs *get_irq_regs(void)
{
 return (*({ unsigned long __ptr; __asm__ ("" : "=r"(__ptr) : "0"(&per_cpu____irq_regs)); (typeof(&per_cpu____irq_regs)) (__ptr + (get_cpu_info()->per_cpu_offset)); }));
}

static __inline__ struct cpu_user_regs *set_irq_regs(struct cpu_user_regs *new_regs)
{
 struct cpu_user_regs *old_regs, **pp_regs = &(*({ unsigned long __ptr; __asm__ ("" : "=r"(__ptr) : "0"(&per_cpu____irq_regs)); (typeof(&per_cpu____irq_regs)) (__ptr + (get_cpu_info()->per_cpu_offset)); }));

 old_regs = *pp_regs;
 *pp_regs = new_regs;
 return old_regs;
}




void event_check_interrupt(struct cpu_user_regs *regs);
void invalidate_interrupt(struct cpu_user_regs *regs);
void call_function_interrupt(struct cpu_user_regs *regs);
void apic_timer_interrupt(struct cpu_user_regs *regs);
void error_interrupt(struct cpu_user_regs *regs);
void pmu_apic_interrupt(struct cpu_user_regs *regs);
void spurious_interrupt(struct cpu_user_regs *regs);
void irq_move_cleanup_interrupt(struct cpu_user_regs *regs);

uint8_t alloc_hipriority_vector(void);

void set_direct_apic_vector(
    uint8_t vector, void (*handler)(struct cpu_user_regs *));
void alloc_direct_apic_vector(
    uint8_t *vector, void (*handler)(struct cpu_user_regs *));

void do_IRQ(struct cpu_user_regs *regs);

void disable_8259A_irq(struct irq_desc *);
void enable_8259A_irq(struct irq_desc *);
int i8259A_irq_pending(unsigned int irq);
void mask_8259A(void);
void unmask_8259A(void);
void init_8259A(int aeoi);
void make_8259A_irq(unsigned int irq);
_Bool bogus_8259A_irq(unsigned int irq);
int i8259A_suspend(void);
int i8259A_resume(void);

void setup_IO_APIC(void);
void disable_IO_APIC(void);
void setup_ioapic_dest(void);
vmask_t *io_apic_get_used_vector_map(unsigned int irq);

extern unsigned int io_apic_irqs;

extern __typeof__(unsigned int) per_cpu__irq_count;

struct pirq;
struct arch_pirq {
    int irq;
    union {
        struct hvm_pirq {
            int emuirq;
            struct hvm_pirq_dpci dpci;
        } hvm;
    };
};




int pirq_shared(struct domain *d , int irq);

int map_domain_pirq(struct domain *d, int pirq, int irq, int type,
                           void *data);
int unmap_domain_pirq(struct domain *d, int pirq);
int get_free_pirq(struct domain *d, int type);
int get_free_pirqs(struct domain *, unsigned int nr);
void free_domain_pirqs(struct domain *d);
int map_domain_emuirq_pirq(struct domain *d, int pirq, int irq);
int unmap_domain_pirq_emuirq(struct domain *d, int pirq);


void fixup_irqs(const cpumask_t *mask, _Bool verbose);
void fixup_eoi(void);

int init_irq_data(void);

void clear_irq_vector(int irq);

int irq_to_vector(int irq);




int create_irq(nodeid_t node, _Bool grant_access);
void destroy_irq(unsigned int irq);
int assign_irq_vector(int irq, const cpumask_t *);

extern void irq_complete_move(struct irq_desc *);

extern struct irq_desc *irq_desc;

void lock_vector_lock(void);
void unlock_vector_lock(void);

void setup_vector_irq(unsigned int cpu);

void move_native_irq(struct irq_desc *);
void move_masked_irq(struct irq_desc *);

int bind_irq_vector(int irq, int vector, const cpumask_t *);

void end_nonmaskable_irq(struct irq_desc *, uint8_t vector);
void irq_set_affinity(struct irq_desc *, const cpumask_t *mask);

int init_domain_irq_mapping(struct domain *);
void cleanup_domain_irq_mapping(struct domain *);
# 213 "/var/xen-dev/xen/xen/include/asm/irq.h"
_Bool cpu_has_pending_apic_eoi(void);

static __inline__ void arch_move_irqs(struct vcpu *v) { }

struct msi_info;
int allocate_and_map_gsi_pirq(struct domain *d, int index, int *pirq_p);
int allocate_and_map_msi_pirq(struct domain *d, int index, int *pirq_p,
                              int type, struct msi_info *msi);
# 73 "/var/xen-dev/xen/xen/include/xen/irq.h" 2

struct msi_desc;
# 85 "/var/xen-dev/xen/xen/include/xen/irq.h"
typedef struct irq_desc {
    unsigned int status;
    hw_irq_controller *handler;
    struct msi_desc *msi_desc;
    struct irqaction *action;
    int irq;
    spinlock_t lock;
    struct arch_irq_desc arch;
    cpumask_var_t affinity;


    s_time_t rl_quantum_start;
    unsigned int rl_cnt;
    struct list_head rl_link;
} __attribute__((__aligned__((1 << (CONFIG_X86_L1_CACHE_SHIFT))))) irq_desc_t;





int init_one_irq_desc(struct irq_desc *);
int arch_init_one_irq_desc(struct irq_desc *);



extern int setup_irq(unsigned int irq, unsigned int irqflags,
                     struct irqaction *);
extern void release_irq(unsigned int irq, const void *dev_id);
extern int request_irq(unsigned int irq, unsigned int irqflags,
               void (*handler)(int, void *, struct cpu_user_regs *),
               const char * devname, void *dev_id);

extern hw_irq_controller no_irq_type;
extern void no_action(int cpl, void *dev_id, struct cpu_user_regs *regs);
extern unsigned int irq_startup_none(struct irq_desc *);
extern void irq_actor_none(struct irq_desc *);




struct domain;
struct vcpu;

struct pirq {
    int pirq;
    u16 evtchn;
    bool_t masked;
    struct rcu_head rcu_head;
    struct arch_pirq arch;
};





extern struct pirq *pirq_get_info(struct domain *, int pirq);
# 149 "/var/xen-dev/xen/xen/include/xen/irq.h"
void pirq_cleanup_check(struct pirq *, struct domain *);




extern void pirq_guest_eoi(struct pirq *);
extern void desc_guest_eoi(struct irq_desc *, struct pirq *);
extern int pirq_guest_unmask(struct domain *d);
extern int pirq_guest_bind(struct vcpu *, struct pirq *, int will_share);
extern void pirq_guest_unbind(struct domain *d, struct pirq *);
extern void pirq_set_affinity(struct domain *d, int irq, const cpumask_t *);
extern irq_desc_t *domain_spin_lock_irq_desc(
    struct domain *d, int irq, unsigned long *pflags);
extern irq_desc_t *pirq_spin_lock_irq_desc(
    const struct pirq *, unsigned long *pflags);

unsigned int set_desc_affinity(struct irq_desc *, const cpumask_t *);


unsigned int arch_hwdom_irqs(domid_t);



void arch_evtchn_bind_pirq(struct domain *, int pirq);
# 14 "/var/xen-dev/xen/xen/include/xen/pci.h" 2
# 1 "/var/xen-dev/xen/xen/include/xen/pci_regs.h" 1
# 15 "/var/xen-dev/xen/xen/include/xen/pci.h" 2
# 1 "/var/xen-dev/xen/xen/include/xen/pfn.h" 1
# 16 "/var/xen-dev/xen/xen/include/xen/pci.h" 2
# 1 "/var/xen-dev/xen/xen/include/asm/device.h" 1



# 1 "/var/xen-dev/xen/xen/include/xen/pci.h" 1
# 5 "/var/xen-dev/xen/xen/include/asm/device.h" 2






typedef struct pci_dev device_t;
# 17 "/var/xen-dev/xen/xen/include/xen/pci.h" 2

# 1 "/var/xen-dev/xen/xen/include/asm/pci.h" 1
# 16 "/var/xen-dev/xen/xen/include/asm/pci.h"
struct arch_pci_dev {
    vmask_t used_vectors;
};

int pci_conf_write_intercept(unsigned int seg, unsigned int bdf,
                             unsigned int reg, unsigned int size,
                             uint32_t *data);
int pci_msi_conf_write_intercept(struct pci_dev *, unsigned int reg,
                                 unsigned int size, uint32_t *data);
bool_t pci_mmcfg_decode(unsigned long mfn, unsigned int *seg,
                        unsigned int *bdf);

bool_t pci_ro_mmcfg_decode(unsigned long mfn, unsigned int *seg,
                           unsigned int *bdf);


extern int pci_mmcfg_config_num;
extern struct acpi_mcfg_allocation *pci_mmcfg_config;
# 19 "/var/xen-dev/xen/xen/include/xen/pci.h" 2
# 44 "/var/xen-dev/xen/xen/include/xen/pci.h"
typedef union {
    uint32_t sbdf;
    struct {
        union {
            uint16_t bdf;
            struct {
                union {
                    struct {
                        uint8_t fn : 3,
                                dev : 5;
                    };
                    uint8_t devfn,
                                extfunc;
                };
                uint8_t bus;
            };
        };
        uint16_t seg;
    };
} pci_sbdf_t;

struct pci_dev_info {




    bool_t is_extfn;
    bool_t is_virtfn;
    struct {
        u8 bus;
        u8 devfn;
    } physfn;
};

struct pci_dev {
    struct list_head alldevs_list;
    struct list_head domain_list;

    struct list_head msi_list;

    struct arch_msix *msix;

    struct domain *domain;

    const union {
        struct {
            uint8_t devfn;
            uint8_t bus;
            uint16_t seg;
        };
        pci_sbdf_t sbdf;
    };

    uint8_t msi_maxvec;
    uint8_t phantom_stride;

    nodeid_t node;


    _Bool quarantine;


    _Bool ignore_bars;

    enum pdev_type {
        DEV_TYPE_PCI_UNKNOWN,
        DEV_TYPE_PCIe_ENDPOINT,
        DEV_TYPE_PCIe_BRIDGE,
        DEV_TYPE_PCIe2PCI_BRIDGE,
        DEV_TYPE_PCI2PCIe_BRIDGE,
        DEV_TYPE_LEGACY_PCI_BRIDGE,
        DEV_TYPE_PCI_HOST_BRIDGE,
        DEV_TYPE_PCI,
    } type;

    struct pci_dev_info info;
    struct arch_pci_dev arch;
    struct {
        struct list_head list;
        unsigned int cap_pos;
        unsigned int queue_depth;
    } ats;
    struct {
        s_time_t time;
        unsigned int count;

    } fault;
    u64 vf_rlen[6];


    struct vpci *vpci;
};
# 148 "/var/xen-dev/xen/xen/include/xen/pci.h"
void pcidevs_lock(void);
void pcidevs_unlock(void);
bool_t __attribute__((__warn_unused_result__)) pcidevs_locked(void);
bool_t __attribute__((__warn_unused_result__)) pcidevs_trylock(void);

bool_t pci_known_segment(u16 seg);
bool_t pci_device_detect(u16 seg, u8 bus, u8 dev, u8 func);
int scan_pci_devices(void);
enum pdev_type pdev_type(u16 seg, u8 bus, u8 devfn);
int find_upstream_bridge(u16 seg, u8 *bus, u8 *devfn, u8 *secbus);
struct pci_dev *pci_lock_pdev(int seg, int bus, int devfn);
struct pci_dev *pci_lock_domain_pdev(
    struct domain *, int seg, int bus, int devfn);

void setup_hwdom_pci_devices(struct domain *,
                            int (*)(u8 devfn, struct pci_dev *));
int pci_release_devices(struct domain *d);
void pci_segments_init(void);
int pci_add_segment(u16 seg);
const unsigned long *pci_get_ro_map(u16 seg);
int pci_add_device(u16 seg, u8 bus, u8 devfn,
                   const struct pci_dev_info *, nodeid_t node);
int pci_remove_device(u16 seg, u8 bus, u8 devfn);
int pci_ro_device(int seg, int bus, int devfn);
int pci_hide_device(unsigned int seg, unsigned int bus, unsigned int devfn);
struct pci_dev *pci_get_pdev(int seg, int bus, int devfn);
struct pci_dev *pci_get_real_pdev(int seg, int bus, int devfn);
struct pci_dev *pci_get_pdev_by_domain(const struct domain *, int seg,
                                       int bus, int devfn);
void pci_check_disable_device(u16 seg, u8 bus, u8 devfn);

uint8_t pci_conf_read8(pci_sbdf_t sbdf, unsigned int reg);
uint16_t pci_conf_read16(pci_sbdf_t sbdf, unsigned int reg);
uint32_t pci_conf_read32(pci_sbdf_t sbdf, unsigned int reg);
void pci_conf_write8(pci_sbdf_t sbdf, unsigned int reg, uint8_t data);
void pci_conf_write16(pci_sbdf_t sbdf, unsigned int reg, uint16_t data);
void pci_conf_write32(pci_sbdf_t sbdf, unsigned int reg, uint32_t data);
uint32_t pci_conf_read(uint32_t cf8, uint8_t offset, uint8_t bytes);
void pci_conf_write(uint32_t cf8, uint8_t offset, uint8_t bytes, uint32_t data);
int pci_mmcfg_read(unsigned int seg, unsigned int bus,
                   unsigned int devfn, int reg, int len, u32 *value);
int pci_mmcfg_write(unsigned int seg, unsigned int bus,
                    unsigned int devfn, int reg, int len, u32 value);
int pci_find_cap_offset(u16 seg, u8 bus, u8 dev, u8 func, u8 cap);
int pci_find_next_cap(u16 seg, u8 bus, unsigned int devfn, u8 pos, int cap);
int pci_find_ext_capability(int seg, int bus, int devfn, int cap);
int pci_find_next_ext_capability(int seg, int bus, int devfn, int pos, int cap);
const char *parse_pci(const char *, unsigned int *seg, unsigned int *bus,
                      unsigned int *dev, unsigned int *func);
const char *parse_pci_seg(const char *, unsigned int *seg, unsigned int *bus,
                          unsigned int *dev, unsigned int *func, _Bool *def_seg);




unsigned int pci_size_mem_bar(pci_sbdf_t sbdf, unsigned int pos,
                              uint64_t *paddr, uint64_t *psize,
                              unsigned int flags);

void pci_intx(const struct pci_dev *, _Bool enable);
bool_t pcie_aer_get_firmware_first(const struct pci_dev *);

struct pirq;
int msixtbl_pt_register(struct domain *, struct pirq *, uint64_t gtable);
void msixtbl_pt_unregister(struct domain *, struct pirq *);
void msixtbl_pt_cleanup(struct domain *d);
# 24 "/var/xen-dev/xen/xen/include/asm/hvm/io.h" 2


# 1 "/var/xen-dev/xen/xen/include/public/hvm/ioreq.h" 1
# 52 "/var/xen-dev/xen/xen/include/public/hvm/ioreq.h"
struct ioreq {
    uint64_t addr;
    uint64_t data;
    uint32_t count;
    uint32_t size;
    uint32_t vp_eport;
    uint16_t _pad0;
    uint8_t state:4;
    uint8_t data_is_ptr:1;

    uint8_t dir:1;
    uint8_t df:1;
    uint8_t _pad1:1;
    uint8_t type;
};
typedef struct ioreq ioreq_t;

struct shared_iopage {
    struct ioreq vcpu_ioreq[1];
};
typedef struct shared_iopage shared_iopage_t;

struct buf_ioreq {
    uint8_t type;
    uint8_t pad:1;
    uint8_t dir:1;
    uint8_t size:2;
    uint32_t addr:20;
    uint32_t data;
};
typedef struct buf_ioreq buf_ioreq_t;


struct buffered_iopage {




            uint32_t read_pointer;
            uint32_t write_pointer;





    buf_ioreq_t buf_ioreq[511];
};
typedef struct buffered_iopage buffered_iopage_t;
# 27 "/var/xen-dev/xen/xen/include/asm/hvm/io.h" 2




typedef int (*hvm_mmio_read_t)(struct vcpu *v,
                               unsigned long addr,
                               unsigned int length,
                               unsigned long *val);
typedef int (*hvm_mmio_write_t)(struct vcpu *v,
                                unsigned long addr,
                                unsigned int length,
                                unsigned long val);
typedef int (*hvm_mmio_check_t)(struct vcpu *v, unsigned long addr);

struct hvm_mmio_ops {
    hvm_mmio_check_t check;
    hvm_mmio_read_t read;
    hvm_mmio_write_t write;
};

static __inline__ paddr_t hvm_mmio_first_byte(const ioreq_t *p)
{
    return __builtin_expect(!!(p->df),0) ?
           p->addr - (p->count - 1ul) * p->size :
           p->addr;
}

static __inline__ paddr_t hvm_mmio_last_byte(const ioreq_t *p)
{
    unsigned long size = p->size;

    return __builtin_expect(!!(p->df),0) ?
           p->addr + size - 1:
           p->addr + (p->count * size) - 1;
}

typedef int (*portio_action_t)(
    int dir, unsigned int port, unsigned int bytes, uint32_t *val);

struct hvm_io_handler {
    union {
        struct {
            const struct hvm_mmio_ops *ops;
        } mmio;
        struct {
            unsigned int port, size;
            portio_action_t action;
        } portio;
    };
    const struct hvm_io_ops *ops;
    uint8_t type;
};

typedef int (*hvm_io_read_t)(const struct hvm_io_handler *,
                             uint64_t addr,
                             uint32_t size,
                             uint64_t *data);
typedef int (*hvm_io_write_t)(const struct hvm_io_handler *,
                              uint64_t addr,
                              uint32_t size,
                              uint64_t data);
typedef bool_t (*hvm_io_accept_t)(const struct hvm_io_handler *,
                                  const ioreq_t *p);
typedef void (*hvm_io_complete_t)(const struct hvm_io_handler *);

struct hvm_io_ops {
    hvm_io_accept_t accept;
    hvm_io_read_t read;
    hvm_io_write_t write;
    hvm_io_complete_t complete;
};

int hvm_process_io_intercept(const struct hvm_io_handler *handler,
                             ioreq_t *p);

int hvm_io_intercept(ioreq_t *p);

struct hvm_io_handler *hvm_next_io_handler(struct domain *d);

bool_t hvm_mmio_internal(paddr_t gpa);

void register_mmio_handler(struct domain *d,
                           const struct hvm_mmio_ops *ops);

void register_portio_handler(
    struct domain *d, unsigned int port, unsigned int size,
    portio_action_t action);

void relocate_portio_handler(
    struct domain *d, unsigned int old_port, unsigned int new_port,
    unsigned int size);

void send_timeoffset_req(unsigned long timeoff);
void send_invalidate_req(void);
_Bool handle_mmio_with_translation(unsigned long gla, unsigned long gpfn,
                                  struct npfec);
_Bool handle_pio(uint16_t port, unsigned int size, int dir);
void hvm_interrupt_post(struct vcpu *v, int vector, int type);
void hvm_dpci_eoi(struct domain *d, unsigned int guest_irq,
                  const union vioapic_redir_entry *ent);
void msix_write_completion(struct vcpu *);




static __inline__ void msixtbl_init(struct domain *d) {}



struct vpci_arch_msi {
    int pirq;
};


struct vpci_arch_msix_entry {
    int pirq;
};

enum stdvga_cache_state {
    STDVGA_CACHE_UNINITIALIZED,
    STDVGA_CACHE_ENABLED,
    STDVGA_CACHE_DISABLED
};

struct hvm_hw_stdvga {
    uint8_t sr_index;
    uint8_t sr[8];
    uint8_t gr_index;
    uint8_t gr[9];
    bool_t stdvga;
    enum stdvga_cache_state cache;
    uint32_t latch;
    struct page_info *vram_page[64];
    spinlock_t lock;
};

void stdvga_init(struct domain *d);
void stdvga_deinit(struct domain *d);

extern void hvm_dpci_msi_eoi(struct domain *d, int vector);


unsigned int hvm_pci_decode_addr(unsigned int cf8, unsigned int addr,
                                 pci_sbdf_t *sbdf);





void register_g2m_portio_handler(struct domain *d);


void register_vpci_portio_handler(struct domain *d);


int register_vpci_mmcfg_handler(struct domain *d, paddr_t addr,
                                unsigned int start_bus, unsigned int end_bus,
                                unsigned int seg);

void destroy_vpci_mmcfg(struct domain *d);


_Bool vpci_is_mmcfg_address(const struct domain *d, paddr_t addr);
# 24 "/var/xen-dev/xen/xen/include/asm/hvm/vcpu.h" 2
# 1 "/var/xen-dev/xen/xen/include/asm/hvm/vlapic.h" 1
# 26 "/var/xen-dev/xen/xen/include/asm/hvm/vlapic.h"
# 1 "/var/xen-dev/xen/xen/include/asm/hvm/vpt.h" 1
# 22 "/var/xen-dev/xen/xen/include/asm/hvm/vpt.h"
# 1 "/var/xen-dev/xen/xen/include/xen/init.h" 1



# 1 "/var/xen-dev/xen/xen/include/asm/init.h" 1
# 5 "/var/xen-dev/xen/xen/include/xen/init.h" 2
# 61 "/var/xen-dev/xen/xen/include/xen/init.h"
typedef int (*initcall_t)(void);
typedef void (*exitcall_t)(void);
# 71 "/var/xen-dev/xen/xen/include/xen/init.h"
void do_presmp_initcalls(void);
void do_initcalls(void);




struct kernel_param {
    const char *name;
    enum {
        OPT_STR,
        OPT_UINT,
        OPT_BOOL,
        OPT_SIZE,
        OPT_CUSTOM,
        OPT_IGNORE,
    } type;
    unsigned int len;
    union {
        void *var;
        int (*func)(const char *);
    } par;
};

extern const struct kernel_param __setup_start[], __setup_end[];
extern const struct kernel_param __param_start[], __param_end[];
# 23 "/var/xen-dev/xen/xen/include/asm/hvm/vpt.h" 2
# 36 "/var/xen-dev/xen/xen/include/asm/hvm/vpt.h"
typedef void time_cb(struct vcpu *v, void *opaque);

struct periodic_time {
    struct list_head list;
    _Bool on_list;
    _Bool one_shot;
    _Bool do_not_freeze;
    _Bool irq_issued;
    _Bool warned_timeout_too_short;
    _Bool level;



    u8 source;
    u8 irq;
    struct vcpu *vcpu;
    u32 pending_intr_nr;
    u64 period;
    s_time_t scheduled;
    u64 last_plt_gtime;
    struct timer timer;
    time_cb *cb;
    void *priv;
};





typedef struct PITState {

    struct hvm_hw_pit hw;

    int64_t count_load_time[3];

    struct periodic_time pt0;
    spinlock_t lock;
} PITState;

struct hpet_registers {

    uint64_t capability;
    uint64_t config;
    uint64_t isr;
    uint64_t mc64;
    struct {
        uint64_t config;
        uint64_t cmp;
        uint64_t fsb;
    } timers[3];


    uint64_t period[3];
    uint64_t comparator64[3];
};

typedef struct HPETState {
    struct hpet_registers hpet;
    uint64_t stime_freq;
    uint64_t hpet_to_ns_scale;
    uint64_t hpet_to_ns_limit;
    uint64_t mc_offset;
    struct periodic_time pt[3];
    rwlock_t lock;
} HPETState;

typedef struct RTCState {

    struct hvm_hw_rtc hw;

    struct tm current_tm;

    struct timer update_timer;
    struct timer update_timer2;
    uint64_t next_update_time;

    struct timer alarm_timer;

    struct periodic_time pt;
    s_time_t start_time;
    s_time_t check_ticks_since;
    int period;
    uint8_t pt_dead_ticks;
    uint32_t use_timer;
    spinlock_t lock;
} RTCState;


typedef struct PMTState {
    struct vcpu *vcpu;
    uint64_t last_gtime;
    uint32_t not_accounted;
    uint64_t scale;
    struct timer timer;
    spinlock_t lock;
} PMTState;

struct pl_time {
    struct RTCState vrtc;
    struct HPETState vhpet;
    struct PMTState vpmt;

    int64_t stime_offset;

    uint64_t last_guest_time;
    spinlock_t pl_time_lock;
    struct domain *domain;
};

void pt_save_timer(struct vcpu *v);
void pt_restore_timer(struct vcpu *v);
int pt_update_irq(struct vcpu *v);
void pt_intr_post(struct vcpu *v, struct hvm_intack intack);
void pt_migrate(struct vcpu *v);

void pt_adjust_global_vcpu_target(struct vcpu *v);





void pt_may_unmask_irq(struct domain *d, struct periodic_time *vlapic_pt);
# 171 "/var/xen-dev/xen/xen/include/asm/hvm/vpt.h"
void create_periodic_time(
    struct vcpu *v, struct periodic_time *pt, uint64_t delta,
    uint64_t period, uint8_t irq, time_cb *cb, void *data, _Bool level);
void destroy_periodic_time(struct periodic_time *pt);

int pv_pit_handler(int port, int data, int write);
void pit_reset(struct domain *d);

void pit_init(struct domain *d, unsigned long cpu_khz);
void pit_stop_channel0_irq(PITState * pit);
void pit_deinit(struct domain *d);
void rtc_init(struct domain *d);
void rtc_migrate_timers(struct vcpu *v);
void rtc_deinit(struct domain *d);
void rtc_reset(struct domain *d);
void rtc_update_clock(struct domain *d);

void pmtimer_init(struct vcpu *v);
void pmtimer_deinit(struct domain *d);
void pmtimer_reset(struct domain *d);
int pmtimer_change_ioport(struct domain *d, unsigned int version);

void hpet_init(struct domain *d);
void hpet_deinit(struct domain *d);
void hpet_reset(struct domain *d);
# 27 "/var/xen-dev/xen/xen/include/asm/hvm/vlapic.h" 2
# 78 "/var/xen-dev/xen/xen/include/asm/hvm/vlapic.h"
struct vlapic {
    struct hvm_hw_lapic hw;
    struct hvm_hw_lapic_regs *regs;
    struct {
        bool_t hw, regs;
        uint32_t id, ldr;
    } loaded;
    spinlock_t esr_lock;
    struct periodic_time pt;
    s_time_t timer_last_update;
    struct page_info *regs_page;

    struct {
        uint32_t icr, dest;
        struct tasklet tasklet;
    } init_sipi;
};




static __inline__ uint32_t vlapic_get_reg(const struct vlapic *vlapic,
                                      uint32_t reg)
{
    return *((uint32_t *)(&vlapic->regs->data[reg]));
}

static __inline__ void vlapic_set_reg(
    struct vlapic *vlapic, uint32_t reg, uint32_t val)
{
    *((uint32_t *)(&vlapic->regs->data[reg])) = val;
}

void vlapic_reg_write(struct vcpu *v, unsigned int reg, uint32_t val);

bool_t is_vlapic_lvtpc_enabled(struct vlapic *vlapic);

_Bool vlapic_test_irq(const struct vlapic *vlapic, uint8_t vec);
void vlapic_set_irq(struct vlapic *vlapic, uint8_t vec, uint8_t trig);

int vlapic_has_pending_irq(struct vcpu *v);
int vlapic_ack_pending_irq(struct vcpu *v, int vector, bool_t force_ack);

int vlapic_init(struct vcpu *v);
void vlapic_destroy(struct vcpu *v);

void vlapic_reset(struct vlapic *vlapic);

int guest_wrmsr_apic_base(struct vcpu *v, uint64_t val);
int guest_rdmsr_x2apic(const struct vcpu *v, uint32_t msr, uint64_t *val);
int guest_wrmsr_x2apic(struct vcpu *v, uint32_t msr, uint64_t val);

void vlapic_tdt_msr_set(struct vlapic *vlapic, uint64_t value);
uint64_t vlapic_tdt_msr_get(struct vlapic *vlapic);

int vlapic_accept_pic_intr(struct vcpu *v);
uint32_t vlapic_set_ppr(struct vlapic *vlapic);

void vlapic_adjust_i8259_target(struct domain *d);

void vlapic_EOI_set(struct vlapic *vlapic);
void vlapic_handle_EOI(struct vlapic *vlapic, u8 vector);

void vlapic_ipi(struct vlapic *vlapic, uint32_t icr_low, uint32_t icr_high);

int vlapic_apicv_write(struct vcpu *v, unsigned int offset);

struct vlapic *vlapic_lowest_prio(
    struct domain *d, const struct vlapic *source,
    int short_hand, uint32_t dest, bool_t dest_mode);

bool_t vlapic_match_dest(
    const struct vlapic *target, const struct vlapic *source,
    int short_hand, uint32_t dest, bool_t dest_mode);

static __inline__ void vlapic_sync_pir_to_irr(struct vcpu *v)
{
    if ( hvm_funcs.sync_pir_to_irr )
        ({ register typeof((v) ? (v) : 0) a1_ asm ( "rdi" ) = (v); register unsigned long a2_ asm ( "rsi" ); register unsigned long a3_ asm ( "rdx" ); register unsigned long a4_ asm ( "rcx" ); register unsigned long a5_ asm ( "r8" ); register unsigned long a6_ asm ( "r9" ); (void)sizeof(hvm_funcs.sync_pir_to_irr(v)); (void)({ int ret_; register unsigned long r10_ asm("r10"); register unsigned long r11_ asm("r11"); asm volatile (".LXEN%=_orig_s:\n\t" "call *%c[addr](%%rip)" "\n .LXEN%=_orig_e:\n\t" ".LXEN%=_diff = " "(" ".LXEN%=_repl_e""1" " - " ".LXEN%=_repl_s""1" ")" "-" "(.LXEN%=_orig_e - .LXEN%=_orig_s)" "\n\t" "mknops (""""(.LXEN%=_diff > 0) * .LXEN%=_diff)\n\t" ".LXEN%=_orig_p:\n\t" ".pushsection .altinstructions, \"a\", @progbits\n" " .long .LXEN%=_orig_s - .\n" " .long " ".LXEN%=_repl_s""1"" - .\n" " .word " "X86_FEATURE_LM" "\n" " .byte " "(.LXEN%=_orig_e - .LXEN%=_orig_s)" "\n" " .byte " "(" ".LXEN%=_repl_e""1" " - " ".LXEN%=_repl_s""1" ")" "\n" " .byte " "(.LXEN%=_orig_p - .LXEN%=_orig_e)" "\n" " .byte 0\n" ".section .discard, \"a\", @progbits\n" ".byte " "(.LXEN%=_orig_p - .LXEN%=_orig_s)" "\n" " .byte 0xff + (" "(" ".LXEN%=_repl_e""1" " - " ".LXEN%=_repl_s""1" ")" ") - (" "(.LXEN%=_orig_p - .LXEN%=_orig_s)" ")\n" ".section .altinstr_replacement, \"ax\", @progbits\n" ".LXEN%=_repl_s""1"":\n\t" "call ." "\n" ".LXEN%=_repl_e""1" ":\n\t" ".popsection\n" : "+r" (a1_), "=r" (a2_), "=r" (a3_), "=r" (a4_), "=r" (a5_), "=r" (a6_), "=a" (ret_), "=r" (r10_), "=r" (r11_) : [addr] "i" (&(hvm_funcs.sync_pir_to_irr)), "g" (hvm_funcs.sync_pir_to_irr) : "memory" ); ret_; }); });
}
# 25 "/var/xen-dev/xen/xen/include/asm/hvm/vcpu.h" 2
# 1 "/var/xen-dev/xen/xen/include/asm/hvm/viridian.h" 1
# 12 "/var/xen-dev/xen/xen/include/asm/hvm/viridian.h"
union viridian_page_msr
{
    uint64_t raw;
    struct
    {
        uint64_t enabled:1;
        uint64_t reserved_preserved:11;
        uint64_t pfn:48;
    };
};

struct viridian_page
{
    union viridian_page_msr msr;
    void *ptr;
};

union viridian_sint_msr
{
    uint64_t raw;
    struct
    {
        uint64_t vector:8;
        uint64_t reserved_preserved1:8;
        uint64_t mask:1;
        uint64_t auto_eoi:1;
        uint64_t polling:1;
        uint64_t reserved_preserved2:45;
    };
};

union viridian_stimer_config_msr
{
    uint64_t raw;
    struct
    {
        uint64_t enabled:1;
        uint64_t periodic:1;
        uint64_t lazy:1;
        uint64_t auto_enable:1;
        uint64_t vector:8;
        uint64_t direct_mode:1;
        uint64_t reserved_zero1:3;
        uint64_t sintx:4;
        uint64_t reserved_zero2:44;
    };
};

struct viridian_stimer {
    struct vcpu *v;
    struct timer timer;
    union viridian_stimer_config_msr config;
    uint64_t count;
    uint64_t expiration;
    _Bool started;
};

struct viridian_vcpu
{
    struct viridian_page vp_assist;
    _Bool apic_assist_pending;
    _Bool polled;
    unsigned int msg_pending;
    uint64_t scontrol;
    uint64_t siefp;
    struct viridian_page simp;
    union viridian_sint_msr sint[16];
    uint8_t vector_to_sintx[256];
    struct viridian_stimer stimer[4];
    unsigned int stimer_enabled;
    unsigned int stimer_pending;
    uint64_t crash_param[5];
};

union viridian_guest_os_id_msr
{
    uint64_t raw;
    struct
    {
        uint64_t build_number:16;
        uint64_t service_pack:8;
        uint64_t minor:8;
        uint64_t major:8;
        uint64_t os:8;
        uint64_t vendor:16;
    };
};

struct viridian_time_ref_count
{
    unsigned long flags;






    uint64_t val;
    int64_t off;
};

struct viridian_domain
{
    union viridian_guest_os_id_msr guest_os_id;
    union viridian_page_msr hypercall_gpa;
    struct viridian_time_ref_count time_ref_count;
    struct viridian_page reference_tsc;
};

void cpuid_viridian_leaves(const struct vcpu *v, uint32_t leaf,
                           uint32_t subleaf, struct cpuid_leaf *res);

int guest_wrmsr_viridian(struct vcpu *v, uint32_t idx, uint64_t val);
int guest_rdmsr_viridian(const struct vcpu *v, uint32_t idx, uint64_t *val);

int
viridian_hypercall(struct cpu_user_regs *regs);

void viridian_time_domain_freeze(const struct domain *d);
void viridian_time_domain_thaw(const struct domain *d);

int viridian_vcpu_init(struct vcpu *v);
int viridian_domain_init(struct domain *d);

void viridian_vcpu_deinit(struct vcpu *v);
void viridian_domain_deinit(struct domain *d);

void viridian_apic_assist_set(const struct vcpu *v);
_Bool viridian_apic_assist_completed(const struct vcpu *v);
void viridian_apic_assist_clear(const struct vcpu *v);

void viridian_synic_poll(struct vcpu *v);
_Bool viridian_synic_is_auto_eoi_sint(const struct vcpu *v,
                                     unsigned int vector);
void viridian_synic_ack_sint(const struct vcpu *v, unsigned int vector);
# 26 "/var/xen-dev/xen/xen/include/asm/hvm/vcpu.h" 2
# 1 "/var/xen-dev/xen/xen/include/asm/hvm/vmx/vmcs.h" 1
# 24 "/var/xen-dev/xen/xen/include/asm/hvm/vmx/vmcs.h"
extern void vmcs_dump_vcpu(struct vcpu *v);
extern void setup_vmcs_dump(void);
extern int vmx_cpu_up_prepare(unsigned int cpu);
extern void vmx_cpu_dead(unsigned int cpu);
extern int vmx_cpu_up(void);
extern int _vmx_cpu_up(_Bool bsp);
extern void vmx_cpu_down(void);

struct vmcs_struct {
    u32 vmcs_revision_id;
    unsigned char data [0];
};

struct vmx_msr_entry {
    u32 index;
    u32 mbz;
    u64 data;
};



struct ept_data {
    union {
        struct {
            uint64_t mt:3,
                     wl:3,
                     ad:1,
                     :5,
                     mfn:52;
        };
        u64 eptp;
    };

    cpumask_var_t invalidate;
};



struct vmx_domain {
    unsigned long apic_access_mfn;

    unsigned int status;





    _Bool exec_sp;
};






struct vmx_msr_bitmap {
    unsigned long read_low [0x2000 / BITS_PER_LONG];
    unsigned long read_high [0x2000 / BITS_PER_LONG];
    unsigned long write_low [0x2000 / BITS_PER_LONG];
    unsigned long write_high[0x2000 / BITS_PER_LONG];
};

struct pi_desc {
    unsigned long pir[(((256)+BITS_PER_LONG-1)/BITS_PER_LONG)];
    union {
        struct {
            u16 on : 1,
                    sn : 1,
                    rsvd_1 : 14;
            u8 nv;
            u8 rsvd_2;
            u32 ndst;
        };
        u64 control;
    };
    u32 rsvd[6];
} __attribute__ ((aligned (64)));



struct pi_blocking_vcpu {
    struct list_head list;
    spinlock_t *lock;
};

struct vmx_vcpu {

    paddr_t vmcs_pa;

    paddr_t vmcs_shadow_maddr;


    spinlock_t vmcs_lock;






    struct list_head active_list;
    int active_cpu;
    int launched;


    u32 exec_control;
    u32 secondary_exec_control;
    u32 exception_bitmap;

    uint64_t shadow_gs;
    uint64_t star;
    uint64_t lstar;
    uint64_t cstar;
    uint64_t sfmask;

    struct vmx_msr_bitmap *msr_bitmap;







    struct vmx_msr_entry *msr_area;
    struct vmx_msr_entry *host_msr_area;
    unsigned int msr_load_count;
    unsigned int msr_save_count;
    unsigned int host_msr_count;

    unsigned long eoi_exitmap_changed;
    unsigned long eoi_exit_bitmap[(((256)+BITS_PER_LONG-1)/BITS_PER_LONG)];
    struct pi_desc pi_desc;

    unsigned long host_cr0;


    bool_t ept_spurious_misconfig;


    uint8_t vmx_realmode;

    uint8_t vmx_emulate;

    uint8_t lbr_flags;


    uint16_t vm86_segment_mask;

    struct segment_register vm86_saved_seg[x86_seg_tr + 1];

    uint32_t vm86_saved_eflags;
    int hostenv_migrated;


    struct page_info *vmread_bitmap;
    struct page_info *vmwrite_bitmap;

    struct page_info *pml_pg;


    unsigned long cr4_host_mask;






    struct pi_blocking_vcpu pi_blocking;
};

int vmx_create_vmcs(struct vcpu *v);
void vmx_destroy_vmcs(struct vcpu *v);
void vmx_vmcs_enter(struct vcpu *v);
bool_t __attribute__((__warn_unused_result__)) vmx_vmcs_try_enter(struct vcpu *v);
void vmx_vmcs_exit(struct vcpu *v);
void vmx_vmcs_reload(struct vcpu *v);
# 221 "/var/xen-dev/xen/xen/include/asm/hvm/vmx/vmcs.h"
extern u32 vmx_cpu_based_exec_control;






extern u32 vmx_pin_based_exec_control;
# 240 "/var/xen-dev/xen/xen/include/asm/hvm/vmx/vmcs.h"
extern u32 vmx_vmexit_control;
# 249 "/var/xen-dev/xen/xen/include/asm/hvm/vmx/vmcs.h"
extern u32 vmx_vmentry_control;
# 269 "/var/xen-dev/xen/xen/include/asm/hvm/vmx/vmcs.h"
extern u32 vmx_secondary_exec_control;
# 286 "/var/xen-dev/xen/xen/include/asm/hvm/vmx/vmcs.h"
extern u64 vmx_ept_vpid_cap;
# 368 "/var/xen-dev/xen/xen/include/asm/hvm/vmx/vmcs.h"
extern u64 vmx_basic_msr;
# 381 "/var/xen-dev/xen/xen/include/asm/hvm/vmx/vmcs.h"
enum vmcs_field {
    VIRTUAL_PROCESSOR_ID = 0x00000000,
    POSTED_INTR_NOTIFICATION_VECTOR = 0x00000002,
    EPTP_INDEX = 0x00000004,

    GUEST_ES_SELECTOR = 0x00000800,
    GUEST_CS_SELECTOR = 0x00000802,
    GUEST_SS_SELECTOR = 0x00000804,
    GUEST_DS_SELECTOR = 0x00000806,
    GUEST_FS_SELECTOR = 0x00000808,
    GUEST_GS_SELECTOR = 0x0000080a,
    GUEST_LDTR_SELECTOR = 0x0000080c,
    GUEST_TR_SELECTOR = 0x0000080e,
    GUEST_INTR_STATUS = 0x00000810,
    GUEST_PML_INDEX = 0x00000812,
    HOST_ES_SELECTOR = 0x00000c00,
    HOST_CS_SELECTOR = 0x00000c02,
    HOST_SS_SELECTOR = 0x00000c04,
    HOST_DS_SELECTOR = 0x00000c06,
    HOST_FS_SELECTOR = 0x00000c08,
    HOST_GS_SELECTOR = 0x00000c0a,
    HOST_TR_SELECTOR = 0x00000c0c,
    IO_BITMAP_A = 0x00002000,
    IO_BITMAP_B = 0x00002002,
    MSR_BITMAP = 0x00002004,
    VM_EXIT_MSR_STORE_ADDR = 0x00002006,
    VM_EXIT_MSR_LOAD_ADDR = 0x00002008,
    VM_ENTRY_MSR_LOAD_ADDR = 0x0000200a,
    PML_ADDRESS = 0x0000200e,
    TSC_OFFSET = 0x00002010,
    VIRTUAL_APIC_PAGE_ADDR = 0x00002012,
    APIC_ACCESS_ADDR = 0x00002014,
    PI_DESC_ADDR = 0x00002016,
    VM_FUNCTION_CONTROL = 0x00002018,
    EPT_POINTER = 0x0000201a,
    EOI_EXIT_BITMAP0 = 0x0000201c,

    EPTP_LIST_ADDR = 0x00002024,
    VMREAD_BITMAP = 0x00002026,
    VMWRITE_BITMAP = 0x00002028,
    VIRT_EXCEPTION_INFO = 0x0000202a,
    XSS_EXIT_BITMAP = 0x0000202c,
    TSC_MULTIPLIER = 0x00002032,
    GUEST_PHYSICAL_ADDRESS = 0x00002400,
    VMCS_LINK_POINTER = 0x00002800,
    GUEST_IA32_DEBUGCTL = 0x00002802,
    GUEST_PAT = 0x00002804,
    GUEST_EFER = 0x00002806,
    GUEST_PERF_GLOBAL_CTRL = 0x00002808,
    GUEST_PDPTE0 = 0x0000280a,

    GUEST_BNDCFGS = 0x00002812,
    HOST_PAT = 0x00002c00,
    HOST_EFER = 0x00002c02,
    HOST_PERF_GLOBAL_CTRL = 0x00002c04,
    PIN_BASED_VM_EXEC_CONTROL = 0x00004000,
    CPU_BASED_VM_EXEC_CONTROL = 0x00004002,
    EXCEPTION_BITMAP = 0x00004004,
    PAGE_FAULT_ERROR_CODE_MASK = 0x00004006,
    PAGE_FAULT_ERROR_CODE_MATCH = 0x00004008,
    CR3_TARGET_COUNT = 0x0000400a,
    VM_EXIT_CONTROLS = 0x0000400c,
    VM_EXIT_MSR_STORE_COUNT = 0x0000400e,
    VM_EXIT_MSR_LOAD_COUNT = 0x00004010,
    VM_ENTRY_CONTROLS = 0x00004012,
    VM_ENTRY_MSR_LOAD_COUNT = 0x00004014,
    VM_ENTRY_INTR_INFO = 0x00004016,
    VM_ENTRY_EXCEPTION_ERROR_CODE = 0x00004018,
    VM_ENTRY_INSTRUCTION_LEN = 0x0000401a,
    TPR_THRESHOLD = 0x0000401c,
    SECONDARY_VM_EXEC_CONTROL = 0x0000401e,
    PLE_GAP = 0x00004020,
    PLE_WINDOW = 0x00004022,
    VM_INSTRUCTION_ERROR = 0x00004400,
    VM_EXIT_REASON = 0x00004402,
    VM_EXIT_INTR_INFO = 0x00004404,
    VM_EXIT_INTR_ERROR_CODE = 0x00004406,
    IDT_VECTORING_INFO = 0x00004408,
    IDT_VECTORING_ERROR_CODE = 0x0000440a,
    VM_EXIT_INSTRUCTION_LEN = 0x0000440c,
    VMX_INSTRUCTION_INFO = 0x0000440e,

    GUEST_ES_LIMIT = 0x00004800,
    GUEST_CS_LIMIT = 0x00004802,
    GUEST_SS_LIMIT = 0x00004804,
    GUEST_DS_LIMIT = 0x00004806,
    GUEST_FS_LIMIT = 0x00004808,
    GUEST_GS_LIMIT = 0x0000480a,
    GUEST_LDTR_LIMIT = 0x0000480c,
    GUEST_TR_LIMIT = 0x0000480e,
    GUEST_GDTR_LIMIT = 0x00004810,
    GUEST_IDTR_LIMIT = 0x00004812,

    GUEST_ES_AR_BYTES = 0x00004814,
    GUEST_CS_AR_BYTES = 0x00004816,
    GUEST_SS_AR_BYTES = 0x00004818,
    GUEST_DS_AR_BYTES = 0x0000481a,
    GUEST_FS_AR_BYTES = 0x0000481c,
    GUEST_GS_AR_BYTES = 0x0000481e,
    GUEST_LDTR_AR_BYTES = 0x00004820,
    GUEST_TR_AR_BYTES = 0x00004822,
    GUEST_INTERRUPTIBILITY_INFO = 0x00004824,
    GUEST_ACTIVITY_STATE = 0x00004826,
    GUEST_SMBASE = 0x00004828,
    GUEST_SYSENTER_CS = 0x0000482a,
    GUEST_PREEMPTION_TIMER = 0x0000482e,
    HOST_SYSENTER_CS = 0x00004c00,
    CR0_GUEST_HOST_MASK = 0x00006000,
    CR4_GUEST_HOST_MASK = 0x00006002,
    CR0_READ_SHADOW = 0x00006004,
    CR4_READ_SHADOW = 0x00006006,
    CR3_TARGET_VALUE0 = 0x00006008,

    EXIT_QUALIFICATION = 0x00006400,
    GUEST_LINEAR_ADDRESS = 0x0000640a,
    GUEST_CR0 = 0x00006800,
    GUEST_CR3 = 0x00006802,
    GUEST_CR4 = 0x00006804,

    GUEST_ES_BASE = 0x00006806,
    GUEST_CS_BASE = 0x00006808,
    GUEST_SS_BASE = 0x0000680a,
    GUEST_DS_BASE = 0x0000680c,
    GUEST_FS_BASE = 0x0000680e,
    GUEST_GS_BASE = 0x00006810,
    GUEST_LDTR_BASE = 0x00006812,
    GUEST_TR_BASE = 0x00006814,
    GUEST_GDTR_BASE = 0x00006816,
    GUEST_IDTR_BASE = 0x00006818,
    GUEST_DR7 = 0x0000681a,
    GUEST_RSP = 0x0000681c,
    GUEST_RIP = 0x0000681e,
    GUEST_RFLAGS = 0x00006820,
    GUEST_PENDING_DBG_EXCEPTIONS = 0x00006822,
    GUEST_SYSENTER_ESP = 0x00006824,
    GUEST_SYSENTER_EIP = 0x00006826,
    HOST_CR0 = 0x00006c00,
    HOST_CR3 = 0x00006c02,
    HOST_CR4 = 0x00006c04,
    HOST_FS_BASE = 0x00006c06,
    HOST_GS_BASE = 0x00006c08,
    HOST_TR_BASE = 0x00006c0a,
    HOST_GDTR_BASE = 0x00006c0c,
    HOST_IDTR_BASE = 0x00006c0e,
    HOST_SYSENTER_ESP = 0x00006c10,
    HOST_SYSENTER_EIP = 0x00006c12,
    HOST_RSP = 0x00006c14,
    HOST_RIP = 0x00006c16,
};




enum vmx_insn_errno
{
    VMX_INSN_SUCCEED = 0,
    VMX_INSN_VMCLEAR_INVALID_PHYADDR = 2,
    VMX_INSN_VMCLEAR_WITH_VMXON_PTR = 3,
    VMX_INSN_VMLAUNCH_NONCLEAR_VMCS = 4,
    VMX_INSN_VMRESUME_NONLAUNCHED_VMCS = 5,
    VMX_INSN_INVALID_CONTROL_STATE = 7,
    VMX_INSN_INVALID_HOST_STATE = 8,
    VMX_INSN_VMPTRLD_INVALID_PHYADDR = 9,
    VMX_INSN_VMPTRLD_WITH_VMXON_PTR = 10,
    VMX_INSN_VMPTRLD_INCORRECT_VMCS_ID = 11,
    VMX_INSN_UNSUPPORTED_VMCS_COMPONENT = 12,
    VMX_INSN_VMXON_IN_VMX_ROOT = 15,
    VMX_INSN_VMENTRY_BLOCKED_BY_MOV_SS = 26,
    VMX_INSN_INVEPT_INVVPID_INVALID_OP = 28,
    VMX_INSN_FAIL_INVALID = ~0,
};


enum vmx_msr_list_type {
    VMX_MSR_HOST,
    VMX_MSR_GUEST,
    VMX_MSR_GUEST_LOADONLY,
};
# 570 "/var/xen-dev/xen/xen/include/asm/hvm/vmx/vmcs.h"
int vmx_add_msr(struct vcpu *v, uint32_t msr, uint64_t val,
                enum vmx_msr_list_type type);





int vmx_del_msr(struct vcpu *v, uint32_t msr, enum vmx_msr_list_type type);

static __inline__ int vmx_add_guest_msr(struct vcpu *v, uint32_t msr, uint64_t val)
{
    return vmx_add_msr(v, msr, val, VMX_MSR_GUEST);
}
static __inline__ int vmx_add_host_load_msr(struct vcpu *v, uint32_t msr,
                                        uint64_t val)
{
    return vmx_add_msr(v, msr, val, VMX_MSR_HOST);
}

struct vmx_msr_entry *vmx_find_msr(const struct vcpu *v, uint32_t msr,
                                   enum vmx_msr_list_type type);

static __inline__ int vmx_read_guest_msr(const struct vcpu *v, uint32_t msr,
                                     uint64_t *val)
{
    const struct vmx_msr_entry *ent = vmx_find_msr(v, msr, VMX_MSR_GUEST);

    if ( !ent )
    {
        *val = 0;
        return -ESRCH;
    }

    *val = ent->data;

    return 0;
}

static __inline__ int vmx_read_guest_loadonly_msr(
    const struct vcpu *v, uint32_t msr, uint64_t *val)
{
    const struct vmx_msr_entry *ent =
        vmx_find_msr(v, msr, VMX_MSR_GUEST_LOADONLY);

    if ( !ent )
    {
        *val = 0;
        return -ESRCH;
    }

    *val = ent->data;

    return 0;
}

static __inline__ int vmx_write_guest_msr(struct vcpu *v, uint32_t msr,
                                      uint64_t val)
{
    struct vmx_msr_entry *ent = vmx_find_msr(v, msr, VMX_MSR_GUEST);

    if ( !ent )
        return -ESRCH;

    ent->data = val;

    return 0;
}



enum vmx_msr_intercept_type {
    VMX_MSR_R = 1,
    VMX_MSR_W = 2,
    VMX_MSR_RW = VMX_MSR_R | VMX_MSR_W,
};

void vmx_clear_msr_intercept(struct vcpu *v, unsigned int msr,
                             enum vmx_msr_intercept_type type);
void vmx_set_msr_intercept(struct vcpu *v, unsigned int msr,
                           enum vmx_msr_intercept_type type);
void vmx_vmcs_switch(paddr_t from, paddr_t to);
void vmx_set_eoi_exit_bitmap(struct vcpu *v, u8 vector);
void vmx_clear_eoi_exit_bitmap(struct vcpu *v, u8 vector);
_Bool vmx_msr_is_intercepted(struct vmx_msr_bitmap *msr_bitmap,
                            unsigned int msr, _Bool is_write) __attribute__((__nonnull__(1)));
void virtual_vmcs_enter(const struct vcpu *);
void virtual_vmcs_exit(const struct vcpu *);
u64 virtual_vmcs_vmread(const struct vcpu *, u32 encoding);
enum vmx_insn_errno virtual_vmcs_vmread_safe(const struct vcpu *v,
                                             u32 vmcs_encoding, u64 *val);
void virtual_vmcs_vmwrite(const struct vcpu *, u32 encoding, u64 val);
enum vmx_insn_errno virtual_vmcs_vmwrite_safe(const struct vcpu *v,
                                              u32 vmcs_encoding, u64 val);

extern __typeof__(bool_t) per_cpu__vmxon;

bool_t vmx_vcpu_pml_enabled(const struct vcpu *v);
int vmx_vcpu_enable_pml(struct vcpu *v);
void vmx_vcpu_disable_pml(struct vcpu *v);
void vmx_vcpu_flush_pml_buffer(struct vcpu *v);
bool_t vmx_domain_pml_enabled(const struct domain *d);
int vmx_domain_enable_pml(struct domain *d);
void vmx_domain_disable_pml(struct domain *d);
void vmx_domain_flush_pml_buffers(struct domain *d);

void vmx_domain_update_eptp(struct domain *d);
# 27 "/var/xen-dev/xen/xen/include/asm/hvm/vcpu.h" 2
# 1 "/var/xen-dev/xen/xen/include/asm/hvm/vmx/vvmx.h" 1
# 25 "/var/xen-dev/xen/xen/include/asm/hvm/vmx/vvmx.h"
struct vvmcs_list {
    unsigned long vvmcs_mfn;
    struct list_head node;
};

struct nestedvmx {







    paddr_t vmxon_region_pa;
    void *iobitmap[2];
    void *msrbitmap;

    struct {
        unsigned long intr_info;
        u32 error_code;
        u8 source;
    } intr;
    struct {
        bool_t enabled;
        uint32_t exit_reason;
        uint32_t exit_qual;
    } ept;
    uint32_t guest_vpid;
    struct list_head launched_list;
};
# 68 "/var/xen-dev/xen/xen/include/asm/hvm/vmx/vvmx.h"
union vmx_inst_info {
    struct {
        unsigned int scaling :2;
        unsigned int __rsvd0 :1;
        unsigned int reg1 :4;
        unsigned int addr_size :3;
        unsigned int memreg :1;
        unsigned int __rsvd1 :4;
        unsigned int segment :3;
        unsigned int index_reg :4;
        unsigned int index_reg_invalid :1;
        unsigned int base_reg :4;
        unsigned int base_reg_invalid :1;
        unsigned int reg2 :4;
    } fields;
    u32 word;
};

int nvmx_vcpu_initialise(struct vcpu *v);
void nvmx_vcpu_destroy(struct vcpu *v);
int nvmx_vcpu_reset(struct vcpu *v);
uint64_t nvmx_vcpu_eptp_base(struct vcpu *v);
enum hvm_intblk nvmx_intr_blocked(struct vcpu *v);
bool_t nvmx_intercepts_exception(
    struct vcpu *v, unsigned int vector, int error_code);
void nvmx_domain_relinquish_resources(struct domain *d);

bool_t nvmx_ept_enabled(struct vcpu *v);






int
nvmx_hap_walk_L1_p2m(struct vcpu *v, paddr_t L2_gpa, paddr_t *L1_gpa,
                     unsigned int *page_order, uint8_t *p2m_acc,
                     bool_t access_r, bool_t access_w, bool_t access_x);
# 126 "/var/xen-dev/xen/xen/include/asm/hvm/vmx/vvmx.h"
struct vvmcs_header {
    u32 revision;
    u32 abort;
};

union vmcs_encoding {
    struct {
        u32 access_type : 1;
        u32 index : 9;
        u32 type : 2;
        u32 rsv1 : 1;
        u32 width : 2;
        u32 rsv2 : 17;
    };
    u32 word;
};

enum vvmcs_encoding_width {
    VVMCS_WIDTH_16 = 0,
    VVMCS_WIDTH_64,
    VVMCS_WIDTH_32,
    VVMCS_WIDTH_NATURAL,
};

enum vvmcs_encoding_type {
    VVMCS_TYPE_CONTROL = 0,
    VVMCS_TYPE_RO,
    VVMCS_TYPE_GSTATE,
    VVMCS_TYPE_HSTATE,
};

u64 get_vvmcs_virtual(void *vvmcs, u32 encoding);
u64 get_vvmcs_real(const struct vcpu *, u32 encoding);
void set_vvmcs_virtual(void *vvmcs, u32 encoding, u64 val);
void set_vvmcs_real(const struct vcpu *, u32 encoding, u64 val);
enum vmx_insn_errno get_vvmcs_virtual_safe(void *vvmcs, u32 encoding, u64 *val);
enum vmx_insn_errno get_vvmcs_real_safe(const struct vcpu *, u32 encoding,
                                        u64 *val);
enum vmx_insn_errno set_vvmcs_virtual_safe(void *vvmcs, u32 encoding, u64 val);
enum vmx_insn_errno set_vvmcs_real_safe(const struct vcpu *, u32 encoding,
                                        u64 val);
# 188 "/var/xen-dev/xen/xen/include/asm/hvm/vmx/vvmx.h"
void nvmx_destroy_vmcs(struct vcpu *v);
int nvmx_handle_vmx_insn(struct cpu_user_regs *regs, unsigned int exit_reason);
int nvmx_msr_read_intercept(unsigned int msr,
                                u64 *msr_content);

void nvmx_update_exec_control(struct vcpu *v, u32 value);
void nvmx_update_secondary_exec_control(struct vcpu *v,
                                        unsigned long value);
void nvmx_update_exception_bitmap(struct vcpu *v, unsigned long value);
void nvmx_switch_guest(void);
void nvmx_idtv_handling(void);
u64 nvmx_get_tsc_offset(struct vcpu *v);
int nvmx_n2_vmexit_handler(struct cpu_user_regs *regs,
                          unsigned int exit_reason);
void nvmx_set_cr_read_shadow(struct vcpu *v, unsigned int cr);

uint64_t nept_get_ept_vpid_cap(void);

int nept_translate_l2ga(struct vcpu *v, paddr_t l2ga,
                        unsigned int *page_order, uint32_t rwx_acc,
                        unsigned long *l1gfn, uint8_t *p2m_acc,
                        uint64_t *exit_qual, uint32_t *exit_reason);
int nvmx_cpu_up_prepare(unsigned int cpu);
void nvmx_cpu_dead(unsigned int cpu);
# 28 "/var/xen-dev/xen/xen/include/asm/hvm/vcpu.h" 2
# 1 "/var/xen-dev/xen/xen/include/asm/hvm/svm/vmcb.h" 1
# 23 "/var/xen-dev/xen/xen/include/asm/hvm/svm/vmcb.h"
# 1 "/var/xen-dev/xen/xen/include/asm/hvm/emulate.h" 1
# 15 "/var/xen-dev/xen/xen/include/asm/hvm/emulate.h"
# 1 "/var/xen-dev/xen/xen/include/xen/err.h" 1
# 19 "/var/xen-dev/xen/xen/include/xen/err.h"
static __inline__ void *__attribute__((__warn_unused_result__)) ERR_PTR(long error)
{
 return (void *)error;
}

static __inline__ long __attribute__((__warn_unused_result__)) PTR_ERR(const void *ptr)
{
 return (long)ptr;
}

static __inline__ long __attribute__((__warn_unused_result__)) IS_ERR(const void *ptr)
{
 return __builtin_expect(!!(((unsigned long)ptr) >= (unsigned long)-4095),0);
}

static __inline__ long __attribute__((__warn_unused_result__)) IS_ERR_OR_NULL(const void *ptr)
{
 return !ptr || __builtin_expect(!!(((unsigned long)ptr) >= (unsigned long)-4095),0);
}
# 46 "/var/xen-dev/xen/xen/include/xen/err.h"
static __inline__ void * __attribute__((__warn_unused_result__)) ERR_CAST(const void *ptr)
{

 return (void *)ptr;
}

static __inline__ int __attribute__((__warn_unused_result__)) PTR_RET(const void *ptr)
{
 return IS_ERR(ptr) ? PTR_ERR(ptr) : 0;
}
# 16 "/var/xen-dev/xen/xen/include/asm/hvm/emulate.h" 2



typedef _Bool hvm_emulate_validate_t(const struct x86_emulate_state *state,
                                    const struct x86_emulate_ctxt *ctxt);

struct hvm_emulate_ctxt {
    struct x86_emulate_ctxt ctxt;





    hvm_emulate_validate_t *validate;


    uint8_t insn_buf[16];
    unsigned long insn_buf_eip;
    unsigned int insn_buf_bytes;

    struct segment_register seg_reg[10];
    unsigned long seg_reg_accessed;
    unsigned long seg_reg_dirty;






    mfn_t mfn[2];

    uint32_t intr_shadow;

    bool_t set_context;
};

enum emul_kind {
    EMUL_KIND_NORMAL,
    EMUL_KIND_NOWRITE,
    EMUL_KIND_SET_CONTEXT_DATA,
    EMUL_KIND_SET_CONTEXT_INSN
};

_Bool __attribute__((__nonnull__(1, 2))) hvm_emulate_one_insn(
    hvm_emulate_validate_t *validate,
    const char *descr);
int hvm_emulate_one(
    struct hvm_emulate_ctxt *hvmemul_ctxt);
void hvm_emulate_one_vm_event(enum emul_kind kind,
    unsigned int trapnr,
    unsigned int errcode);

void hvm_emulate_init_once(
    struct hvm_emulate_ctxt *hvmemul_ctxt,
    hvm_emulate_validate_t *validate,
    struct cpu_user_regs *regs);

void hvm_emulate_init_per_insn(
    struct hvm_emulate_ctxt *hvmemul_ctxt,
    const unsigned char *insn_buf,
    unsigned int insn_bytes);
void hvm_emulate_writeback(
    struct hvm_emulate_ctxt *hvmemul_ctxt);
struct segment_register *hvmemul_get_seg_reg(
    enum x86_segment seg,
    struct hvm_emulate_ctxt *hvmemul_ctxt);
int hvm_emulate_one_mmio(unsigned long mfn, unsigned long gla);

static __inline__ _Bool handle_mmio(void)
{
    return hvm_emulate_one_insn(x86_insn_is_mem_access, "MMIO");
}

int hvmemul_insn_fetch(enum x86_segment seg,
                       unsigned long offset,
                       void *p_data,
                       unsigned int bytes,
                       struct x86_emulate_ctxt *ctxt);
int hvmemul_do_pio_buffer(uint16_t port,
                          unsigned int size,
                          uint8_t dir,
                          void *buffer);

void hvm_dump_emulation_state(const char *loglvl, const char *prefix,
                              struct hvm_emulate_ctxt *hvmemul_ctxt, int rc);
# 24 "/var/xen-dev/xen/xen/include/asm/hvm/svm/vmcb.h" 2



enum GenericIntercept1bits
{
    GENERAL1_INTERCEPT_INTR = 1 << 0,
    GENERAL1_INTERCEPT_NMI = 1 << 1,
    GENERAL1_INTERCEPT_SMI = 1 << 2,
    GENERAL1_INTERCEPT_INIT = 1 << 3,
    GENERAL1_INTERCEPT_VINTR = 1 << 4,
    GENERAL1_INTERCEPT_CR0_SEL_WRITE = 1 << 5,
    GENERAL1_INTERCEPT_IDTR_READ = 1 << 6,
    GENERAL1_INTERCEPT_GDTR_READ = 1 << 7,
    GENERAL1_INTERCEPT_LDTR_READ = 1 << 8,
    GENERAL1_INTERCEPT_TR_READ = 1 << 9,
    GENERAL1_INTERCEPT_IDTR_WRITE = 1 << 10,
    GENERAL1_INTERCEPT_GDTR_WRITE = 1 << 11,
    GENERAL1_INTERCEPT_LDTR_WRITE = 1 << 12,
    GENERAL1_INTERCEPT_TR_WRITE = 1 << 13,
    GENERAL1_INTERCEPT_RDTSC = 1 << 14,
    GENERAL1_INTERCEPT_RDPMC = 1 << 15,
    GENERAL1_INTERCEPT_PUSHF = 1 << 16,
    GENERAL1_INTERCEPT_POPF = 1 << 17,
    GENERAL1_INTERCEPT_CPUID = 1 << 18,
    GENERAL1_INTERCEPT_RSM = 1 << 19,
    GENERAL1_INTERCEPT_IRET = 1 << 20,
    GENERAL1_INTERCEPT_SWINT = 1 << 21,
    GENERAL1_INTERCEPT_INVD = 1 << 22,
    GENERAL1_INTERCEPT_PAUSE = 1 << 23,
    GENERAL1_INTERCEPT_HLT = 1 << 24,
    GENERAL1_INTERCEPT_INVLPG = 1 << 25,
    GENERAL1_INTERCEPT_INVLPGA = 1 << 26,
    GENERAL1_INTERCEPT_IOIO_PROT = 1 << 27,
    GENERAL1_INTERCEPT_MSR_PROT = 1 << 28,
    GENERAL1_INTERCEPT_TASK_SWITCH = 1 << 29,
    GENERAL1_INTERCEPT_FERR_FREEZE = 1 << 30,
    GENERAL1_INTERCEPT_SHUTDOWN_EVT = 1 << 31
};


enum GenericIntercept2bits
{
    GENERAL2_INTERCEPT_VMRUN = 1 << 0,
    GENERAL2_INTERCEPT_VMMCALL = 1 << 1,
    GENERAL2_INTERCEPT_VMLOAD = 1 << 2,
    GENERAL2_INTERCEPT_VMSAVE = 1 << 3,
    GENERAL2_INTERCEPT_STGI = 1 << 4,
    GENERAL2_INTERCEPT_CLGI = 1 << 5,
    GENERAL2_INTERCEPT_SKINIT = 1 << 6,
    GENERAL2_INTERCEPT_RDTSCP = 1 << 7,
    GENERAL2_INTERCEPT_ICEBP = 1 << 8,
    GENERAL2_INTERCEPT_WBINVD = 1 << 9,
    GENERAL2_INTERCEPT_MONITOR = 1 << 10,
    GENERAL2_INTERCEPT_MWAIT = 1 << 11,
    GENERAL2_INTERCEPT_MWAIT_CONDITIONAL = 1 << 12,
    GENERAL2_INTERCEPT_XSETBV = 1 << 13
};



enum CRInterceptBits
{
    CR_INTERCEPT_CR0_READ = 1 << 0,
    CR_INTERCEPT_CR1_READ = 1 << 1,
    CR_INTERCEPT_CR2_READ = 1 << 2,
    CR_INTERCEPT_CR3_READ = 1 << 3,
    CR_INTERCEPT_CR4_READ = 1 << 4,
    CR_INTERCEPT_CR5_READ = 1 << 5,
    CR_INTERCEPT_CR6_READ = 1 << 6,
    CR_INTERCEPT_CR7_READ = 1 << 7,
    CR_INTERCEPT_CR8_READ = 1 << 8,
    CR_INTERCEPT_CR9_READ = 1 << 9,
    CR_INTERCEPT_CR10_READ = 1 << 10,
    CR_INTERCEPT_CR11_READ = 1 << 11,
    CR_INTERCEPT_CR12_READ = 1 << 12,
    CR_INTERCEPT_CR13_READ = 1 << 13,
    CR_INTERCEPT_CR14_READ = 1 << 14,
    CR_INTERCEPT_CR15_READ = 1 << 15,
    CR_INTERCEPT_CR0_WRITE = 1 << 16,
    CR_INTERCEPT_CR1_WRITE = 1 << 17,
    CR_INTERCEPT_CR2_WRITE = 1 << 18,
    CR_INTERCEPT_CR3_WRITE = 1 << 19,
    CR_INTERCEPT_CR4_WRITE = 1 << 20,
    CR_INTERCEPT_CR5_WRITE = 1 << 21,
    CR_INTERCEPT_CR6_WRITE = 1 << 22,
    CR_INTERCEPT_CR7_WRITE = 1 << 23,
    CR_INTERCEPT_CR8_WRITE = 1 << 24,
    CR_INTERCEPT_CR9_WRITE = 1 << 25,
    CR_INTERCEPT_CR10_WRITE = 1 << 26,
    CR_INTERCEPT_CR11_WRITE = 1 << 27,
    CR_INTERCEPT_CR12_WRITE = 1 << 28,
    CR_INTERCEPT_CR13_WRITE = 1 << 29,
    CR_INTERCEPT_CR14_WRITE = 1 << 30,
    CR_INTERCEPT_CR15_WRITE = 1 << 31,
};



enum DRInterceptBits
{
    DR_INTERCEPT_DR0_READ = 1 << 0,
    DR_INTERCEPT_DR1_READ = 1 << 1,
    DR_INTERCEPT_DR2_READ = 1 << 2,
    DR_INTERCEPT_DR3_READ = 1 << 3,
    DR_INTERCEPT_DR4_READ = 1 << 4,
    DR_INTERCEPT_DR5_READ = 1 << 5,
    DR_INTERCEPT_DR6_READ = 1 << 6,
    DR_INTERCEPT_DR7_READ = 1 << 7,
    DR_INTERCEPT_DR8_READ = 1 << 8,
    DR_INTERCEPT_DR9_READ = 1 << 9,
    DR_INTERCEPT_DR10_READ = 1 << 10,
    DR_INTERCEPT_DR11_READ = 1 << 11,
    DR_INTERCEPT_DR12_READ = 1 << 12,
    DR_INTERCEPT_DR13_READ = 1 << 13,
    DR_INTERCEPT_DR14_READ = 1 << 14,
    DR_INTERCEPT_DR15_READ = 1 << 15,
    DR_INTERCEPT_DR0_WRITE = 1 << 16,
    DR_INTERCEPT_DR1_WRITE = 1 << 17,
    DR_INTERCEPT_DR2_WRITE = 1 << 18,
    DR_INTERCEPT_DR3_WRITE = 1 << 19,
    DR_INTERCEPT_DR4_WRITE = 1 << 20,
    DR_INTERCEPT_DR5_WRITE = 1 << 21,
    DR_INTERCEPT_DR6_WRITE = 1 << 22,
    DR_INTERCEPT_DR7_WRITE = 1 << 23,
    DR_INTERCEPT_DR8_WRITE = 1 << 24,
    DR_INTERCEPT_DR9_WRITE = 1 << 25,
    DR_INTERCEPT_DR10_WRITE = 1 << 26,
    DR_INTERCEPT_DR11_WRITE = 1 << 27,
    DR_INTERCEPT_DR12_WRITE = 1 << 28,
    DR_INTERCEPT_DR13_WRITE = 1 << 29,
    DR_INTERCEPT_DR14_WRITE = 1 << 30,
    DR_INTERCEPT_DR15_WRITE = 1 << 31,
};

enum VMEXIT_EXITCODE
{

    VMEXIT_CR0_READ = 0,
    VMEXIT_CR1_READ = 1,
    VMEXIT_CR2_READ = 2,
    VMEXIT_CR3_READ = 3,
    VMEXIT_CR4_READ = 4,
    VMEXIT_CR5_READ = 5,
    VMEXIT_CR6_READ = 6,
    VMEXIT_CR7_READ = 7,
    VMEXIT_CR8_READ = 8,
    VMEXIT_CR9_READ = 9,
    VMEXIT_CR10_READ = 10,
    VMEXIT_CR11_READ = 11,
    VMEXIT_CR12_READ = 12,
    VMEXIT_CR13_READ = 13,
    VMEXIT_CR14_READ = 14,
    VMEXIT_CR15_READ = 15,


    VMEXIT_CR0_WRITE = 16,
    VMEXIT_CR1_WRITE = 17,
    VMEXIT_CR2_WRITE = 18,
    VMEXIT_CR3_WRITE = 19,
    VMEXIT_CR4_WRITE = 20,
    VMEXIT_CR5_WRITE = 21,
    VMEXIT_CR6_WRITE = 22,
    VMEXIT_CR7_WRITE = 23,
    VMEXIT_CR8_WRITE = 24,
    VMEXIT_CR9_WRITE = 25,
    VMEXIT_CR10_WRITE = 26,
    VMEXIT_CR11_WRITE = 27,
    VMEXIT_CR12_WRITE = 28,
    VMEXIT_CR13_WRITE = 29,
    VMEXIT_CR14_WRITE = 30,
    VMEXIT_CR15_WRITE = 31,


    VMEXIT_DR0_READ = 32,
    VMEXIT_DR1_READ = 33,
    VMEXIT_DR2_READ = 34,
    VMEXIT_DR3_READ = 35,
    VMEXIT_DR4_READ = 36,
    VMEXIT_DR5_READ = 37,
    VMEXIT_DR6_READ = 38,
    VMEXIT_DR7_READ = 39,
    VMEXIT_DR8_READ = 40,
    VMEXIT_DR9_READ = 41,
    VMEXIT_DR10_READ = 42,
    VMEXIT_DR11_READ = 43,
    VMEXIT_DR12_READ = 44,
    VMEXIT_DR13_READ = 45,
    VMEXIT_DR14_READ = 46,
    VMEXIT_DR15_READ = 47,


    VMEXIT_DR0_WRITE = 48,
    VMEXIT_DR1_WRITE = 49,
    VMEXIT_DR2_WRITE = 50,
    VMEXIT_DR3_WRITE = 51,
    VMEXIT_DR4_WRITE = 52,
    VMEXIT_DR5_WRITE = 53,
    VMEXIT_DR6_WRITE = 54,
    VMEXIT_DR7_WRITE = 55,
    VMEXIT_DR8_WRITE = 56,
    VMEXIT_DR9_WRITE = 57,
    VMEXIT_DR10_WRITE = 58,
    VMEXIT_DR11_WRITE = 59,
    VMEXIT_DR12_WRITE = 60,
    VMEXIT_DR13_WRITE = 61,
    VMEXIT_DR14_WRITE = 62,
    VMEXIT_DR15_WRITE = 63,


    VMEXIT_EXCEPTION_DE = 64,
    VMEXIT_EXCEPTION_DB = 65,
    VMEXIT_EXCEPTION_NMI = 66,
    VMEXIT_EXCEPTION_BP = 67,
    VMEXIT_EXCEPTION_OF = 68,
    VMEXIT_EXCEPTION_BR = 69,
    VMEXIT_EXCEPTION_UD = 70,
    VMEXIT_EXCEPTION_NM = 71,
    VMEXIT_EXCEPTION_DF = 72,
    VMEXIT_EXCEPTION_09 = 73,
    VMEXIT_EXCEPTION_TS = 74,
    VMEXIT_EXCEPTION_NP = 75,
    VMEXIT_EXCEPTION_SS = 76,
    VMEXIT_EXCEPTION_GP = 77,
    VMEXIT_EXCEPTION_PF = 78,
    VMEXIT_EXCEPTION_15 = 79,
    VMEXIT_EXCEPTION_MF = 80,
    VMEXIT_EXCEPTION_AC = 81,
    VMEXIT_EXCEPTION_MC = 82,
    VMEXIT_EXCEPTION_XF = 83,




    VMEXIT_INTR = 96,
    VMEXIT_NMI = 97,
    VMEXIT_SMI = 98,
    VMEXIT_INIT = 99,
    VMEXIT_VINTR = 100,
    VMEXIT_CR0_SEL_WRITE = 101,
    VMEXIT_IDTR_READ = 102,
    VMEXIT_GDTR_READ = 103,
    VMEXIT_LDTR_READ = 104,
    VMEXIT_TR_READ = 105,
    VMEXIT_IDTR_WRITE = 106,
    VMEXIT_GDTR_WRITE = 107,
    VMEXIT_LDTR_WRITE = 108,
    VMEXIT_TR_WRITE = 109,
    VMEXIT_RDTSC = 110,
    VMEXIT_RDPMC = 111,
    VMEXIT_PUSHF = 112,
    VMEXIT_POPF = 113,
    VMEXIT_CPUID = 114,
    VMEXIT_RSM = 115,
    VMEXIT_IRET = 116,
    VMEXIT_SWINT = 117,
    VMEXIT_INVD = 118,
    VMEXIT_PAUSE = 119,
    VMEXIT_HLT = 120,
    VMEXIT_INVLPG = 121,
    VMEXIT_INVLPGA = 122,
    VMEXIT_IOIO = 123,
    VMEXIT_MSR = 124,
    VMEXIT_TASK_SWITCH = 125,
    VMEXIT_FERR_FREEZE = 126,
    VMEXIT_SHUTDOWN = 127,
    VMEXIT_VMRUN = 128,
    VMEXIT_VMMCALL = 129,
    VMEXIT_VMLOAD = 130,
    VMEXIT_VMSAVE = 131,
    VMEXIT_STGI = 132,
    VMEXIT_CLGI = 133,
    VMEXIT_SKINIT = 134,
    VMEXIT_RDTSCP = 135,
    VMEXIT_ICEBP = 136,
    VMEXIT_WBINVD = 137,
    VMEXIT_MONITOR = 138,
    VMEXIT_MWAIT = 139,
    VMEXIT_MWAIT_CONDITIONAL= 140,
    VMEXIT_XSETBV = 141,
    VMEXIT_NPF = 1024,
    VMEXIT_INVALID = -1
};

typedef union
{
    u64 bytes;
    struct
    {
        u64 vector: 8;
        u64 type: 3;
        u64 ev: 1;
        u64 resvd1: 19;
        u64 v: 1;
        u64 errorcode:32;
    } fields;
} eventinj_t;

typedef union
{
    u64 bytes;
    struct
    {
        u64 tpr: 8;
        u64 irq: 1;
        u64 vgif: 1;
        u64 rsvd0: 6;
        u64 prio: 4;
        u64 ign_tpr: 1;
        u64 rsvd1: 3;
        u64 intr_masking: 1;
        u64 vgif_enable: 1;
        u64 rsvd2: 6;
        u64 vector: 8;
        u64 rsvd3: 24;
    } fields;
} vintr_t;

typedef union
{
    u64 bytes;
    struct
    {
        u64 type: 1;
        u64 rsv0: 1;
        u64 str: 1;
        u64 rep: 1;
        u64 sz8: 1;
        u64 sz16: 1;
        u64 sz32: 1;
        u64 rsv1: 9;
        u64 port: 16;
    } fields;
} ioio_info_t;

typedef union
{
    u64 bytes;
    struct
    {
        u64 lbr_enable:1;
        u64 vloadsave_enable:1;
    } fields;
} virt_ext_t;

typedef union
{
    uint32_t bytes;
    struct
    {


        uint32_t intercepts: 1;

        uint32_t iopm: 1;

        uint32_t asid: 1;

        uint32_t tpr: 1;

        uint32_t np: 1;

        uint32_t cr: 1;

        uint32_t dr: 1;

        uint32_t dt: 1;

        uint32_t seg: 1;

        uint32_t cr2: 1;

        uint32_t lbr: 1;
        uint32_t resv: 21;
    } fields;
} vmcbcleanbits_t;




struct vmcb_struct {
    u32 _cr_intercepts;
    u32 _dr_intercepts;
    u32 _exception_intercepts;
    u32 _general1_intercepts;
    u32 _general2_intercepts;
    u32 res01;
    u64 res02;
    u64 res03;
    u64 res04;
    u64 res05;
    u32 res06;
    u16 _pause_filter_thresh;
    u16 _pause_filter_count;
    u64 _iopm_base_pa;
    u64 _msrpm_base_pa;
    u64 _tsc_offset;
    u32 _guest_asid;
    u8 tlb_control;
    u8 res07[3];
    vintr_t _vintr;
    u64 interrupt_shadow;
    u64 exitcode;
    u64 exitinfo1;
    u64 exitinfo2;
    eventinj_t exitintinfo;
    u64 _np_enable;
    u64 res08[2];
    eventinj_t eventinj;
    u64 _h_cr3;
    virt_ext_t virt_ext;
    vmcbcleanbits_t cleanbits;
    u32 res09;
    u64 nextrip;
    u8 guest_ins_len;
    u8 guest_ins[15];
    u64 res10a[100];

    union {
        struct segment_register sreg[6];
        struct {
            struct segment_register es;
            struct segment_register cs;
            struct segment_register ss;
            struct segment_register ds;
            struct segment_register fs;
            struct segment_register gs;
        };
    };
    struct segment_register gdtr;
    struct segment_register ldtr;
    struct segment_register idtr;
    struct segment_register tr;
    u64 res10[5];
    u8 res11[3];
    u8 _cpl;
    u32 res12;
    u64 _efer;
    u64 res13[14];
    u64 _cr4;
    u64 _cr3;
    u64 _cr0;
    u64 _dr7;
    u64 _dr6;
    u64 rflags;
    u64 rip;
    u64 res14[11];
    u64 rsp;
    u64 res15[3];
    u64 rax;
    u64 star;
    u64 lstar;
    u64 cstar;
    u64 sfmask;
    u64 kerngsbase;
    u64 sysenter_cs;
    u64 sysenter_esp;
    u64 sysenter_eip;
    u64 _cr2;
    u64 res16[4];
    u64 _g_pat;
    u64 _debugctlmsr;
    u64 _lastbranchfromip;
    u64 _lastbranchtoip;
    u64 _lastintfromip;
    u64 _lastinttoip;
    u64 res17[301];
};

struct svm_domain {

    union {
        uint64_t raw[2];
        struct {
            uint64_t length;
            uint64_t status;
        };
    } osvw;
};
# 512 "/var/xen-dev/xen/xen/include/asm/hvm/svm/vmcb.h"
enum vmcb_sync_state {
    vmcb_in_sync,
    vmcb_needs_vmsave,
    vmcb_needs_vmload
};

struct svm_vcpu {
    struct vmcb_struct *vmcb;
    u64 vmcb_pa;
    unsigned long *msrpm;
    int launch_core;

    uint8_t vmcb_sync_state;


    uint8_t cached_insn_len;






    uint64_t guest_sysenter_cs;
    uint64_t guest_sysenter_esp;
    uint64_t guest_sysenter_eip;
};

struct vmcb_struct *alloc_vmcb(void);
void free_vmcb(struct vmcb_struct *vmcb);

int svm_create_vmcb(struct vcpu *v);
void svm_destroy_vmcb(struct vcpu *v);

void setup_vmcb_dump(void);





void svm_intercept_msr(struct vcpu *v, uint32_t msr, int enable);
# 573 "/var/xen-dev/xen/xen/include/asm/hvm/svm/vmcb.h"
static __inline__ void vmcb_set_cr_intercepts(struct vmcb_struct *vmcb, typeof(vmcb->_cr_intercepts) value) { vmcb->_cr_intercepts = value; vmcb->cleanbits.fields.intercepts = 0; } static __inline__ typeof(alloc_vmcb()->_cr_intercepts) vmcb_get_cr_intercepts(const struct vmcb_struct *vmcb) { return vmcb->_cr_intercepts; }
static __inline__ void vmcb_set_dr_intercepts(struct vmcb_struct *vmcb, typeof(vmcb->_dr_intercepts) value) { vmcb->_dr_intercepts = value; vmcb->cleanbits.fields.intercepts = 0; } static __inline__ typeof(alloc_vmcb()->_dr_intercepts) vmcb_get_dr_intercepts(const struct vmcb_struct *vmcb) { return vmcb->_dr_intercepts; }
static __inline__ void vmcb_set_exception_intercepts(struct vmcb_struct *vmcb, typeof(vmcb->_exception_intercepts) value) { vmcb->_exception_intercepts = value; vmcb->cleanbits.fields.intercepts = 0; } static __inline__ typeof(alloc_vmcb()->_exception_intercepts) vmcb_get_exception_intercepts(const struct vmcb_struct *vmcb) { return vmcb->_exception_intercepts; }
static __inline__ void vmcb_set_general1_intercepts(struct vmcb_struct *vmcb, typeof(vmcb->_general1_intercepts) value) { vmcb->_general1_intercepts = value; vmcb->cleanbits.fields.intercepts = 0; } static __inline__ typeof(alloc_vmcb()->_general1_intercepts) vmcb_get_general1_intercepts(const struct vmcb_struct *vmcb) { return vmcb->_general1_intercepts; }
static __inline__ void vmcb_set_general2_intercepts(struct vmcb_struct *vmcb, typeof(vmcb->_general2_intercepts) value) { vmcb->_general2_intercepts = value; vmcb->cleanbits.fields.intercepts = 0; } static __inline__ typeof(alloc_vmcb()->_general2_intercepts) vmcb_get_general2_intercepts(const struct vmcb_struct *vmcb) { return vmcb->_general2_intercepts; }
static __inline__ void vmcb_set_pause_filter_count(struct vmcb_struct *vmcb, typeof(vmcb->_pause_filter_count) value) { vmcb->_pause_filter_count = value; vmcb->cleanbits.fields.intercepts = 0; } static __inline__ typeof(alloc_vmcb()->_pause_filter_count) vmcb_get_pause_filter_count(const struct vmcb_struct *vmcb) { return vmcb->_pause_filter_count; }
static __inline__ void vmcb_set_pause_filter_thresh(struct vmcb_struct *vmcb, typeof(vmcb->_pause_filter_thresh) value) { vmcb->_pause_filter_thresh = value; vmcb->cleanbits.fields.intercepts = 0; } static __inline__ typeof(alloc_vmcb()->_pause_filter_thresh) vmcb_get_pause_filter_thresh(const struct vmcb_struct *vmcb) { return vmcb->_pause_filter_thresh; }
static __inline__ void vmcb_set_tsc_offset(struct vmcb_struct *vmcb, typeof(vmcb->_tsc_offset) value) { vmcb->_tsc_offset = value; vmcb->cleanbits.fields.intercepts = 0; } static __inline__ typeof(alloc_vmcb()->_tsc_offset) vmcb_get_tsc_offset(const struct vmcb_struct *vmcb) { return vmcb->_tsc_offset; }
static __inline__ void vmcb_set_iopm_base_pa(struct vmcb_struct *vmcb, typeof(vmcb->_iopm_base_pa) value) { vmcb->_iopm_base_pa = value; vmcb->cleanbits.fields.iopm = 0; } static __inline__ typeof(alloc_vmcb()->_iopm_base_pa) vmcb_get_iopm_base_pa(const struct vmcb_struct *vmcb) { return vmcb->_iopm_base_pa; }
static __inline__ void vmcb_set_msrpm_base_pa(struct vmcb_struct *vmcb, typeof(vmcb->_msrpm_base_pa) value) { vmcb->_msrpm_base_pa = value; vmcb->cleanbits.fields.iopm = 0; } static __inline__ typeof(alloc_vmcb()->_msrpm_base_pa) vmcb_get_msrpm_base_pa(const struct vmcb_struct *vmcb) { return vmcb->_msrpm_base_pa; }
static __inline__ void vmcb_set_guest_asid(struct vmcb_struct *vmcb, typeof(vmcb->_guest_asid) value) { vmcb->_guest_asid = value; vmcb->cleanbits.fields.asid = 0; } static __inline__ typeof(alloc_vmcb()->_guest_asid) vmcb_get_guest_asid(const struct vmcb_struct *vmcb) { return vmcb->_guest_asid; }
static __inline__ void vmcb_set_vintr(struct vmcb_struct *vmcb, typeof(vmcb->_vintr) value) { vmcb->_vintr = value; vmcb->cleanbits.fields.tpr = 0; } static __inline__ typeof(alloc_vmcb()->_vintr) vmcb_get_vintr(const struct vmcb_struct *vmcb) { return vmcb->_vintr; }
static __inline__ void vmcb_set_np_enable(struct vmcb_struct *vmcb, typeof(vmcb->_np_enable) value) { vmcb->_np_enable = value; vmcb->cleanbits.fields.np = 0; } static __inline__ typeof(alloc_vmcb()->_np_enable) vmcb_get_np_enable(const struct vmcb_struct *vmcb) { return vmcb->_np_enable; }
static __inline__ void vmcb_set_h_cr3(struct vmcb_struct *vmcb, typeof(vmcb->_h_cr3) value) { vmcb->_h_cr3 = value; vmcb->cleanbits.fields.np = 0; } static __inline__ typeof(alloc_vmcb()->_h_cr3) vmcb_get_h_cr3(const struct vmcb_struct *vmcb) { return vmcb->_h_cr3; }
static __inline__ void vmcb_set_g_pat(struct vmcb_struct *vmcb, typeof(vmcb->_g_pat) value) { vmcb->_g_pat = value; vmcb->cleanbits.fields.np = 0; } static __inline__ typeof(alloc_vmcb()->_g_pat) vmcb_get_g_pat(const struct vmcb_struct *vmcb) { return vmcb->_g_pat; }
static __inline__ void vmcb_set_cr0(struct vmcb_struct *vmcb, typeof(vmcb->_cr0) value) { vmcb->_cr0 = value; vmcb->cleanbits.fields.cr = 0; } static __inline__ typeof(alloc_vmcb()->_cr0) vmcb_get_cr0(const struct vmcb_struct *vmcb) { return vmcb->_cr0; }
static __inline__ void vmcb_set_cr3(struct vmcb_struct *vmcb, typeof(vmcb->_cr3) value) { vmcb->_cr3 = value; vmcb->cleanbits.fields.cr = 0; } static __inline__ typeof(alloc_vmcb()->_cr3) vmcb_get_cr3(const struct vmcb_struct *vmcb) { return vmcb->_cr3; }
static __inline__ void vmcb_set_cr4(struct vmcb_struct *vmcb, typeof(vmcb->_cr4) value) { vmcb->_cr4 = value; vmcb->cleanbits.fields.cr = 0; } static __inline__ typeof(alloc_vmcb()->_cr4) vmcb_get_cr4(const struct vmcb_struct *vmcb) { return vmcb->_cr4; }
static __inline__ void vmcb_set_efer(struct vmcb_struct *vmcb, typeof(vmcb->_efer) value) { vmcb->_efer = value; vmcb->cleanbits.fields.cr = 0; } static __inline__ typeof(alloc_vmcb()->_efer) vmcb_get_efer(const struct vmcb_struct *vmcb) { return vmcb->_efer; }
static __inline__ void vmcb_set_dr6(struct vmcb_struct *vmcb, typeof(vmcb->_dr6) value) { vmcb->_dr6 = value; vmcb->cleanbits.fields.dr = 0; } static __inline__ typeof(alloc_vmcb()->_dr6) vmcb_get_dr6(const struct vmcb_struct *vmcb) { return vmcb->_dr6; }
static __inline__ void vmcb_set_dr7(struct vmcb_struct *vmcb, typeof(vmcb->_dr7) value) { vmcb->_dr7 = value; vmcb->cleanbits.fields.dr = 0; } static __inline__ typeof(alloc_vmcb()->_dr7) vmcb_get_dr7(const struct vmcb_struct *vmcb) { return vmcb->_dr7; }
static __inline__ void vmcb_set_cpl(struct vmcb_struct *vmcb, typeof(vmcb->_cpl) value) { vmcb->_cpl = value; vmcb->cleanbits.fields.seg = 0; } static __inline__ typeof(alloc_vmcb()->_cpl) vmcb_get_cpl(const struct vmcb_struct *vmcb) { return vmcb->_cpl; }
static __inline__ void vmcb_set_cr2(struct vmcb_struct *vmcb, typeof(vmcb->_cr2) value) { vmcb->_cr2 = value; vmcb->cleanbits.fields.cr2 = 0; } static __inline__ typeof(alloc_vmcb()->_cr2) vmcb_get_cr2(const struct vmcb_struct *vmcb) { return vmcb->_cr2; }
static __inline__ void vmcb_set_debugctlmsr(struct vmcb_struct *vmcb, typeof(vmcb->_debugctlmsr) value) { vmcb->_debugctlmsr = value; vmcb->cleanbits.fields.lbr = 0; } static __inline__ typeof(alloc_vmcb()->_debugctlmsr) vmcb_get_debugctlmsr(const struct vmcb_struct *vmcb) { return vmcb->_debugctlmsr; }
static __inline__ void vmcb_set_lastbranchfromip(struct vmcb_struct *vmcb, typeof(vmcb->_lastbranchfromip) value) { vmcb->_lastbranchfromip = value; vmcb->cleanbits.fields.lbr = 0; } static __inline__ typeof(alloc_vmcb()->_lastbranchfromip) vmcb_get_lastbranchfromip(const struct vmcb_struct *vmcb) { return vmcb->_lastbranchfromip; }
static __inline__ void vmcb_set_lastbranchtoip(struct vmcb_struct *vmcb, typeof(vmcb->_lastbranchtoip) value) { vmcb->_lastbranchtoip = value; vmcb->cleanbits.fields.lbr = 0; } static __inline__ typeof(alloc_vmcb()->_lastbranchtoip) vmcb_get_lastbranchtoip(const struct vmcb_struct *vmcb) { return vmcb->_lastbranchtoip; }
static __inline__ void vmcb_set_lastintfromip(struct vmcb_struct *vmcb, typeof(vmcb->_lastintfromip) value) { vmcb->_lastintfromip = value; vmcb->cleanbits.fields.lbr = 0; } static __inline__ typeof(alloc_vmcb()->_lastintfromip) vmcb_get_lastintfromip(const struct vmcb_struct *vmcb) { return vmcb->_lastintfromip; }
static __inline__ void vmcb_set_lastinttoip(struct vmcb_struct *vmcb, typeof(vmcb->_lastinttoip) value) { vmcb->_lastinttoip = value; vmcb->cleanbits.fields.lbr = 0; } static __inline__ typeof(alloc_vmcb()->_lastinttoip) vmcb_get_lastinttoip(const struct vmcb_struct *vmcb) { return vmcb->_lastinttoip; }
# 29 "/var/xen-dev/xen/xen/include/asm/hvm/vcpu.h" 2
# 1 "/var/xen-dev/xen/xen/include/asm/hvm/svm/nestedsvm.h" 1
# 28 "/var/xen-dev/xen/xen/include/asm/hvm/svm/nestedsvm.h"
struct nestedsvm {
    bool_t ns_gif;
    uint64_t ns_msr_hsavepa;




    uint64_t ns_ovvmcb_pa;




    uint64_t ns_tscratio;


    uint32_t ns_cr_intercepts;
    uint32_t ns_dr_intercepts;
    uint32_t ns_exception_intercepts;
    uint32_t ns_general1_intercepts;
    uint32_t ns_general2_intercepts;


    virt_ext_t ns_virt_ext;


    unsigned long *ns_cached_msrpm;

    unsigned long *ns_merged_msrpm;


    paddr_t ns_iomap_pa, ns_oiomap_pa;

    unsigned long *ns_iomap;

    uint64_t ns_cr0;
# 72 "/var/xen-dev/xen/xen/include/asm/hvm/svm/nestedsvm.h"
    uint64_t ns_vmcb_guestcr3, ns_vmcb_hostcr3;
    uint32_t ns_guest_asid;

    bool_t ns_hap_enabled;


    struct {
        uint64_t exitcode;
        uint64_t exitinfo1;
        uint64_t exitinfo2;
    } ns_vmexit;
    union {
        uint32_t bytes;
        struct {
            uint32_t rflagsif: 1;
            uint32_t vintrmask: 1;
            uint32_t reserved: 30;
        } fields;
    } ns_hostflags;
};







int nestedsvm_vmcb_map(struct vcpu *v, uint64_t vmcbaddr);
void nestedsvm_vmexit_defer(struct vcpu *v,
    uint64_t exitcode, uint64_t exitinfo1, uint64_t exitinfo2);
enum nestedhvm_vmexits
nestedsvm_vmexit_n2n1(struct vcpu *v, struct cpu_user_regs *regs);
enum nestedhvm_vmexits
nestedsvm_check_intercepts(struct vcpu *v, struct cpu_user_regs *regs,
    uint64_t exitcode);
void svm_nested_features_on_efer_update(struct vcpu *v);


void nsvm_vcpu_destroy(struct vcpu *v);
int nsvm_vcpu_initialise(struct vcpu *v);
int nsvm_vcpu_reset(struct vcpu *v);
int nsvm_vcpu_vmrun(struct vcpu *v, struct cpu_user_regs *regs);
int nsvm_vcpu_vmexit_event(struct vcpu *v, const struct x86_event *event);
uint64_t nsvm_vcpu_hostcr3(struct vcpu *v);
bool_t nsvm_vmcb_guest_intercepts_event(
    struct vcpu *v, unsigned int vector, int errcode);
bool_t nsvm_vmcb_hap_enabled(struct vcpu *v);
enum hvm_intblk nsvm_intr_blocked(struct vcpu *v);


int nsvm_rdmsr(struct vcpu *v, unsigned int msr, uint64_t *msr_content);
int nsvm_wrmsr(struct vcpu *v, unsigned int msr, uint64_t msr_content);


void svm_vmexit_do_clgi(struct cpu_user_regs *regs, struct vcpu *v);
void svm_vmexit_do_stgi(struct cpu_user_regs *regs, struct vcpu *v);
bool_t nestedsvm_gif_isset(struct vcpu *v);
int nsvm_hap_walk_L1_p2m(struct vcpu *v, paddr_t L2_gpa, paddr_t *L1_gpa,
                         unsigned int *page_order, uint8_t *p2m_acc,
                         bool_t access_r, bool_t access_w, bool_t access_x);





int nestedsvm_vcpu_interrupt(struct vcpu *v, const struct hvm_intack intack);
# 30 "/var/xen-dev/xen/xen/include/asm/hvm/vcpu.h" 2
# 1 "/var/xen-dev/xen/xen/include/asm/mtrr.h" 1
# 19 "/var/xen-dev/xen/xen/include/asm/mtrr.h"
enum {
    PAT_TYPE_UNCACHABLE=0,
    PAT_TYPE_WRCOMB=1,
    PAT_TYPE_WRTHROUGH=4,
    PAT_TYPE_WRPROT=5,
    PAT_TYPE_WRBACK=6,
    PAT_TYPE_UC_MINUS=7,
    PAT_TYPE_NUMS
};





typedef u8 mtrr_type;
# 46 "/var/xen-dev/xen/xen/include/asm/mtrr.h"
struct mtrr_var_range {
 uint64_t base;
 uint64_t mask;
};



struct mtrr_state {
 struct mtrr_var_range *var_ranges;
 mtrr_type fixed_ranges[88];
 _Bool enabled;
 _Bool fixed_enabled;
 _Bool have_fixed;
 mtrr_type def_type;

 u64 mtrr_cap;

 bool_t overlapped;
};
extern struct mtrr_state mtrr_state;

extern void mtrr_save_fixed_ranges(void *);
extern void mtrr_save_state(void);
extern int mtrr_add(unsigned long base, unsigned long size,
                    unsigned int type, char increment);
extern int mtrr_add_page(unsigned long base, unsigned long size,
                         unsigned int type, char increment);
extern int mtrr_del(int reg, unsigned long base, unsigned long size);
extern int mtrr_del_page(int reg, unsigned long base, unsigned long size);
extern void mtrr_centaur_report_mcr(int mcr, u32 lo, u32 hi);
extern u32 get_pat_flags(struct vcpu *v, u32 gl1e_flags, paddr_t gpaddr,
                  paddr_t spaddr, uint8_t gmtrr_mtype);
extern int epte_get_entry_emt(struct domain *, unsigned long gfn, mfn_t mfn,
                              unsigned int order, uint8_t *ipat,
                              bool_t direct_mmio);
extern void ept_change_entry_emt_with_range(
    struct domain *d, unsigned long start_gfn, unsigned long end_gfn);
extern unsigned char pat_type_2_pte_flags(unsigned char pat_type);
extern int hold_mtrr_updates_on_aps;
extern void mtrr_aps_sync_begin(void);
extern void mtrr_aps_sync_end(void);
extern void mtrr_bp_restore(void);

extern bool_t mtrr_var_range_msr_set(struct domain *, struct mtrr_state *,
                                     uint32_t msr, uint64_t msr_content);
extern bool_t mtrr_fix_range_msr_set(struct domain *, struct mtrr_state *,
                                     uint32_t row, uint64_t msr_content);
extern bool_t mtrr_def_type_msr_set(struct domain *, struct mtrr_state *,
                                    uint64_t msr_content);



static __inline__ void memory_type_changed(struct domain *d) {}


extern bool_t pat_msr_set(uint64_t *pat, uint64_t msr);

_Bool is_var_mtrr_overlapped(const struct mtrr_state *m);
_Bool mtrr_pat_not_equal(const struct vcpu *vd, const struct vcpu *vs);
# 31 "/var/xen-dev/xen/xen/include/asm/hvm/vcpu.h" 2

enum hvm_io_completion {
    HVMIO_no_completion,
    HVMIO_mmio_completion,
    HVMIO_pio_completion,
    HVMIO_realmode_completion
};

struct hvm_vcpu_asid {
    uint64_t generation;
    uint32_t asid;
};





struct hvm_mmio_cache {
    unsigned long gla;
    unsigned int size;
    uint8_t dir;
    uint8_t buffer[64] __attribute__((__aligned__(sizeof(long))));
};

struct hvm_vcpu_io {

    enum hvm_io_completion io_completion;
    ioreq_t io_req;







    struct npfec mmio_access;
    unsigned long mmio_gla;
    unsigned long mmio_gpfn;





    struct hvm_mmio_cache mmio_cache[3];
    unsigned int mmio_cache_count;


    unsigned int mmio_insn_bytes;
    unsigned char mmio_insn[16];




    bool_t mmio_retry;

    unsigned long msix_unmask_address;
    unsigned long msix_snoop_address;
    unsigned long msix_snoop_gpa;

    const struct g2m_ioport *g2m_ioport;
};

static __inline__ _Bool hvm_ioreq_needs_completion(const ioreq_t *ioreq)
{
    return ioreq->state == 1 &&
           !ioreq->data_is_ptr &&
           (ioreq->type != 0 || ioreq->dir != 0);
}

struct nestedvcpu {
    bool_t nv_guestmode;
    void *nv_vvmcx;
    void *nv_n1vmcx;
    void *nv_n2vmcx;

    uint64_t nv_vvmcxaddr;
    paddr_t nv_n1vmcx_pa;
    paddr_t nv_n2vmcx_pa;


    union {
        struct nestedsvm nsvm;
        struct nestedvmx nvmx;
    } u;

    bool_t nv_flushp2m;
    struct p2m_domain *nv_p2m;
    _Bool stale_np2m;
    uint64_t np2m_generation;

    struct hvm_vcpu_asid nv_n2asid;

    bool_t nv_vmentry_pending;
    bool_t nv_vmexit_pending;
    bool_t nv_vmswitch_in_progress;




    bool_t nv_ioport80;
    bool_t nv_ioportED;


    unsigned long guest_cr[5];
};



struct altp2mvcpu {





    struct page_info *veinfo_pg;
    uint16_t p2midx;
};



struct hvm_vcpu {

    unsigned long guest_cr[5];
    unsigned long guest_efer;







    unsigned long hw_cr[5];

    struct vlapic vlapic;
    s64 cache_tsc_offset;
    u64 guest_time;


    spinlock_t tm_lock;
    struct list_head tm_list;

    _Bool flag_dr_dirty;
    _Bool debug_state_latch;
    _Bool single_step;

    struct hvm_vcpu_asid n1asid;

    u64 msr_tsc_adjust;

    union {
        struct vmx_vcpu vmx;
        struct svm_vcpu svm;
    };

    struct tasklet assert_evtchn_irq_tasklet;

    struct nestedvcpu nvcpu;

    struct altp2mvcpu avcpu;

    struct mtrr_state mtrr;
    u64 pat_cr;


    int64_t stime_offset;

    u8 evtchn_upcall_vector;


    u8 cache_mode;

    struct hvm_vcpu_io hvm_io;


    struct x86_event inject_event;

    struct viridian_vcpu *viridian;
};
# 7 "/var/xen-dev/xen/xen/include/asm/domain.h" 2
# 1 "/var/xen-dev/xen/xen/include/asm/hvm/domain.h" 1
# 23 "/var/xen-dev/xen/xen/include/asm/hvm/domain.h"
# 1 "/var/xen-dev/xen/xen/include/xen/iommu.h" 1
# 23 "/var/xen-dev/xen/xen/include/xen/iommu.h"
# 1 "/var/xen-dev/xen/xen/include/xen/page-defs.h" 1
# 24 "/var/xen-dev/xen/xen/include/xen/iommu.h" 2
# 32 "/var/xen-dev/xen/xen/include/xen/iommu.h"
typedef struct { uint64_t dfn; } dfn_t; static __inline__ dfn_t _dfn(uint64_t n) { return (dfn_t) { n }; } static __inline__ uint64_t dfn_x(dfn_t n) { return n.dfn; };
# 45 "/var/xen-dev/xen/xen/include/xen/iommu.h"
static __inline__ dfn_t dfn_add(dfn_t dfn, unsigned long i)
{
    return _dfn(dfn_x(dfn) + i);
}

static __inline__ bool_t dfn_eq(dfn_t x, dfn_t y)
{
    return dfn_x(x) == dfn_x(y);
}

extern bool_t iommu_enable, iommu_enabled;
extern _Bool force_iommu, iommu_quarantine, iommu_verbose, iommu_igfx;
extern bool_t iommu_snoop, iommu_qinval, iommu_intremap, iommu_intpost;
# 67 "/var/xen-dev/xen/xen/include/xen/iommu.h"
static __inline__ void clear_iommu_hap_pt_share(void)
{





}

extern bool_t iommu_debug;
extern bool_t amd_iommu_perdev_intremap;

extern _Bool iommu_hwdom_strict, iommu_hwdom_passthrough, iommu_hwdom_inclusive;
extern int8_t iommu_hwdom_reserved;

extern unsigned int iommu_dev_iotlb_timeout;

int iommu_setup(void);
int iommu_hardware_setup(void);

int iommu_domain_init(struct domain *d, unsigned int opts);
void iommu_hwdom_init(struct domain *d);
void iommu_domain_destroy(struct domain *d);

void arch_iommu_domain_destroy(struct domain *d);
int arch_iommu_domain_init(struct domain *d);
void arch_iommu_check_autotranslated_hwdom(struct domain *d);
void arch_iommu_hwdom_init(struct domain *d);
# 115 "/var/xen-dev/xen/xen/include/xen/iommu.h"
enum
{
    _IOMMU_FLUSHF_added,
    _IOMMU_FLUSHF_modified,
};



int __attribute__((__warn_unused_result__)) iommu_map(struct domain *d, dfn_t dfn, mfn_t mfn,
                           unsigned int page_order, unsigned int flags,
                           unsigned int *flush_flags);
int __attribute__((__warn_unused_result__)) iommu_unmap(struct domain *d, dfn_t dfn,
                             unsigned int page_order,
                             unsigned int *flush_flags);

int __attribute__((__warn_unused_result__)) iommu_legacy_map(struct domain *d, dfn_t dfn, mfn_t mfn,
                                  unsigned int page_order,
                                  unsigned int flags);
int __attribute__((__warn_unused_result__)) iommu_legacy_unmap(struct domain *d, dfn_t dfn,
                                    unsigned int page_order);

int __attribute__((__warn_unused_result__)) iommu_lookup_page(struct domain *d, dfn_t dfn, mfn_t *mfn,
                                   unsigned int *flags);

int __attribute__((__warn_unused_result__)) iommu_iotlb_flush(struct domain *d, dfn_t dfn,
                                   unsigned int page_count,
                                   unsigned int flush_flags);
int __attribute__((__warn_unused_result__)) iommu_iotlb_flush_all(struct domain *d,
                                       unsigned int flush_flags);

enum iommu_feature
{
    IOMMU_FEAT_COHERENT_WALK,
    IOMMU_FEAT_count
};

bool_t iommu_has_feature(struct domain *d, enum iommu_feature feature);
# 201 "/var/xen-dev/xen/xen/include/xen/iommu.h"
struct page_info;







typedef int iommu_grdm_t(xen_pfn_t start, xen_ulong_t nr, u32 id, void *ctxt);

struct iommu_ops {
    int (*init)(struct domain *d);
    void (*hwdom_init)(struct domain *d);
    int (*quarantine_init)(struct domain *d);
    int (*add_device)(u8 devfn, device_t *dev);
    int (*enable_device)(device_t *dev);
    int (*remove_device)(u8 devfn, device_t *dev);
    int (*assign_device)(struct domain *, u8 devfn, device_t *dev, u32 flag);
    int (*reassign_device)(struct domain *s, struct domain *t,
                           u8 devfn, device_t *dev);






    void (*teardown)(struct domain *d);





    int __attribute__((__warn_unused_result__)) (*map_page)(struct domain *d, dfn_t dfn, mfn_t mfn,
                                 unsigned int flags,
                                 unsigned int *flush_flags);
    int __attribute__((__warn_unused_result__)) (*unmap_page)(struct domain *d, dfn_t dfn,
                                   unsigned int *flush_flags);
    int __attribute__((__warn_unused_result__)) (*lookup_page)(struct domain *d, dfn_t dfn, mfn_t *mfn,
                                    unsigned int *flags);

    void (*free_page_table)(struct page_info *);
# 255 "/var/xen-dev/xen/xen/include/xen/iommu.h"
    int __attribute__((__warn_unused_result__)) (*suspend)(void);
    void (*resume)(void);
    void (*share_p2m)(struct domain *d);
    void (*crash_shutdown)(void);
    int __attribute__((__warn_unused_result__)) (*iotlb_flush)(struct domain *d, dfn_t dfn,
                                    unsigned int page_count,
                                    unsigned int flush_flags);
    int __attribute__((__warn_unused_result__)) (*iotlb_flush_all)(struct domain *d);
    int (*get_reserved_device_memory)(iommu_grdm_t *, void *);
    void (*dump_p2m_table)(struct domain *d);
# 275 "/var/xen-dev/xen/xen/include/xen/iommu.h"
};

# 1 "/var/xen-dev/xen/xen/include/asm/iommu.h" 1
# 20 "/var/xen-dev/xen/xen/include/asm/iommu.h"
# 1 "/var/xen-dev/xen/xen/include/asm/apicdef.h" 1
# 129 "/var/xen-dev/xen/xen/include/asm/apicdef.h"
extern _Bool x2apic_enabled;
# 21 "/var/xen-dev/xen/xen/include/asm/iommu.h" 2






struct g2m_ioport {
    struct list_head list;
    unsigned int gport;
    unsigned int mport;
    unsigned int np;
};





typedef uint64_t daddr_t;







struct arch_iommu
{
    u64 pgd_maddr;
    spinlock_t mapping_lock;
    int agaw;
    u64 iommu_bitmap;
    struct list_head mapped_rmrrs;


    int paging_mode;
    struct page_info *root_table;
    struct guest_iommu *g_iommu;
};

extern struct iommu_ops iommu_ops;
# 75 "/var/xen-dev/xen/xen/include/asm/iommu.h"
static __inline__ const struct iommu_ops *iommu_get_ops(void)
{
    do { if (__builtin_expect(!!(!iommu_ops.init),0)) do { do { ({ _Static_assert(!((77) >> ((31 - 24) + (31 - 24))), "!(" "(77) >> (BUG_LINE_LO_WIDTH + BUG_LINE_HI_WIDTH)" ")"); }); ({ _Static_assert(!((2) >= 4), "!(" "(2) >= BUGFRAME_NR" ")"); }); asm volatile ( ".Lbug%=: ud2\n" ".pushsection .bug_frames.%c[bf_type], \"a\", @progbits\n" ".p2align 2\n" ".Lfrm%=:\n" ".long (.Lbug%= - .Lfrm%=) + %c[bf_line_hi]\n" ".long (%c[bf_ptr] - .Lfrm%=) + %c[bf_line_lo]\n" ".if " "0" "\n" ".long 0, %c[bf_msg] - .Lfrm%=\n" ".endif\n" ".popsection\n" :: [bf_type] "i" (2), [bf_ptr] "i" ("/var/xen-dev/xen/xen/include/asm/iommu.h"), [bf_msg] "i" (((void*)0)), [bf_line_lo] "i" ((77 & ((1 << (31 - 24)) - 1)) << 24), [bf_line_hi] "i" (((77) >> (31 - 24)) << 24) ); } while (0); __builtin_unreachable(); } while (0); } while (0);
    return &iommu_ops;
}

struct iommu_init_ops {
    const struct iommu_ops *ops;
    int (*setup)(void);
    _Bool (*supports_x2apic)(void);
};

extern const struct iommu_init_ops *iommu_init_ops;

void iommu_update_ire_from_apic(unsigned int apic, unsigned int reg, unsigned int value);
unsigned int iommu_read_apic_from_ire(unsigned int apic, unsigned int reg);
int iommu_setup_hpet_msi(struct msi_desc *);

static __inline__ int iommu_adjust_irq_affinities(void)
{
    return iommu_ops.adjust_irq_affinities
           ? iommu_ops.adjust_irq_affinities()
           : 0;
}


int __attribute__((__warn_unused_result__)) iommu_pte_flush(struct domain *d, u64 gfn, u64 *pte,
                                 int order, int present);

static __inline__ _Bool iommu_supports_x2apic(void)
{
    return iommu_init_ops && iommu_init_ops->supports_x2apic
           ? iommu_init_ops->supports_x2apic()
           : 0;
}

int iommu_enable_x2apic(void);

static __inline__ void iommu_disable_x2apic(void)
{
    if ( x2apic_enabled && iommu_ops.disable_x2apic )
        iommu_ops.disable_x2apic();
}

extern _Bool untrusted_msi;

int pi_update_irte(const struct pi_desc *pi_desc, const struct pirq *pirq,
                   const uint8_t gvec);
# 278 "/var/xen-dev/xen/xen/include/xen/iommu.h" 2






struct domain_iommu {
    struct arch_iommu arch;


    const struct iommu_ops *platform_ops;
# 301 "/var/xen-dev/xen/xen/include/xen/iommu.h"
    unsigned long features[(((IOMMU_FEAT_count)+BITS_PER_LONG-1)/BITS_PER_LONG)];


    _Bool hap_pt_share;







    _Bool need_sync;
};
# 329 "/var/xen-dev/xen/xen/include/xen/iommu.h"
int __attribute__((__warn_unused_result__)) iommu_suspend(void);
void iommu_resume(void);
void iommu_crash_shutdown(void);
int iommu_get_reserved_device_memory(iommu_grdm_t *, void *);

void iommu_share_p2m_table(struct domain *d);






int iommu_do_domctl(struct xen_domctl *, struct domain *d,
                    __guest_handle_xen_domctl_t);

void iommu_dev_iotlb_flush_timeout(struct domain *d, struct pci_dev *pdev);
# 356 "/var/xen-dev/xen/xen/include/xen/iommu.h"
extern __typeof__(bool_t) per_cpu__iommu_dont_flush_iotlb;

extern struct spinlock iommu_pt_cleanup_lock;
extern struct page_list_head iommu_pt_cleanup_list;
# 24 "/var/xen-dev/xen/xen/include/asm/hvm/domain.h" 2
# 32 "/var/xen-dev/xen/xen/include/asm/hvm/domain.h"
# 1 "/var/xen-dev/xen/xen/include/public/grant_table.h" 1
# 33 "/var/xen-dev/xen/xen/include/asm/hvm/domain.h" 2
# 1 "/var/xen-dev/xen/xen/include/public/hvm/params.h" 1
# 26 "/var/xen-dev/xen/xen/include/public/hvm/params.h"
# 1 "/var/xen-dev/xen/xen/include/public/hvm/hvm_op.h" 1
# 27 "/var/xen-dev/xen/xen/include/public/hvm/hvm_op.h"
# 1 "/var/xen-dev/xen/xen/include/public/hvm/../trace.h" 1
# 288 "/var/xen-dev/xen/xen/include/public/hvm/../trace.h"
struct t_rec {
    uint32_t event:28;
    uint32_t extra_u32:3;
    uint32_t cycles_included:1;
    union {
        struct {
            uint32_t cycles_lo, cycles_hi;
            uint32_t extra_u32[7];
        } cycles;
        struct {
            uint32_t extra_u32[7];
        } nocycles;
    } u;
};





struct t_buf {
# 316 "/var/xen-dev/xen/xen/include/public/hvm/../trace.h"
    uint32_t cons;
    uint32_t prod;

};





struct t_info {
    uint16_t tbuf_size;
    uint16_t mfn_offset[];

};
# 28 "/var/xen-dev/xen/xen/include/public/hvm/hvm_op.h" 2
# 1 "/var/xen-dev/xen/xen/include/public/hvm/../event_channel.h" 1
# 29 "/var/xen-dev/xen/xen/include/public/hvm/hvm_op.h" 2




struct xen_hvm_param {
    domid_t domid;
    uint32_t index;
    uint64_t value;
};
typedef struct xen_hvm_param xen_hvm_param_t;
typedef xen_hvm_param_t * __guest_handle_xen_hvm_param_t; typedef const xen_hvm_param_t * __guest_handle_const_xen_hvm_param_t;

struct xen_hvm_altp2m_suppress_ve {
    uint16_t view;
    uint8_t suppress_ve;
    uint8_t pad1;
    uint32_t pad2;
    uint64_t gfn;
};





struct xen_hvm_set_pci_intx_level {

    domid_t domid;

    uint8_t domain, bus, device, intx;

    uint8_t level;
};
typedef struct xen_hvm_set_pci_intx_level xen_hvm_set_pci_intx_level_t;
typedef xen_hvm_set_pci_intx_level_t * __guest_handle_xen_hvm_set_pci_intx_level_t; typedef const xen_hvm_set_pci_intx_level_t * __guest_handle_const_xen_hvm_set_pci_intx_level_t;



struct xen_hvm_set_isa_irq_level {

    domid_t domid;

    uint8_t isa_irq;

    uint8_t level;
};
typedef struct xen_hvm_set_isa_irq_level xen_hvm_set_isa_irq_level_t;
typedef xen_hvm_set_isa_irq_level_t * __guest_handle_xen_hvm_set_isa_irq_level_t; typedef const xen_hvm_set_isa_irq_level_t * __guest_handle_const_xen_hvm_set_isa_irq_level_t;


struct xen_hvm_set_pci_link_route {

    domid_t domid;

    uint8_t link;

    uint8_t isa_irq;
};
typedef struct xen_hvm_set_pci_link_route xen_hvm_set_pci_link_route_t;
typedef xen_hvm_set_pci_link_route_t * __guest_handle_xen_hvm_set_pci_link_route_t; typedef const xen_hvm_set_pci_link_route_t * __guest_handle_const_xen_hvm_set_pci_link_route_t;
# 101 "/var/xen-dev/xen/xen/include/public/hvm/hvm_op.h"
typedef enum {
    HVMMEM_ram_rw,
    HVMMEM_ram_ro,
    HVMMEM_mmio_dm,

    HVMMEM_mmio_write_dm,




    HVMMEM_ioreq_server






} hvmmem_type_t;





struct xen_hvm_pagetable_dying {

    domid_t domid;
    uint16_t pad[3];

    uint64_t gpa;
};
typedef struct xen_hvm_pagetable_dying xen_hvm_pagetable_dying_t;
typedef xen_hvm_pagetable_dying_t * __guest_handle_xen_hvm_pagetable_dying_t; typedef const xen_hvm_pagetable_dying_t * __guest_handle_const_xen_hvm_pagetable_dying_t;



struct xen_hvm_get_time {
    uint64_t now;
};
typedef struct xen_hvm_get_time xen_hvm_get_time_t;
typedef xen_hvm_get_time_t * __guest_handle_xen_hvm_get_time_t; typedef const xen_hvm_get_time_t * __guest_handle_const_xen_hvm_get_time_t;


struct xen_hvm_xentrace {
    uint16_t event, extra_bytes;
    uint8_t extra[7 * sizeof(uint32_t)];
};
typedef struct xen_hvm_xentrace xen_hvm_xentrace_t;
typedef xen_hvm_xentrace_t * __guest_handle_xen_hvm_xentrace_t; typedef const xen_hvm_xentrace_t * __guest_handle_const_xen_hvm_xentrace_t;
# 163 "/var/xen-dev/xen/xen/include/public/hvm/hvm_op.h"
struct xen_hvm_get_mem_type {

    domid_t domid;

    uint16_t mem_type;
    uint16_t pad[2];

    uint64_t pfn;
};
typedef struct xen_hvm_get_mem_type xen_hvm_get_mem_type_t;
typedef xen_hvm_get_mem_type_t * __guest_handle_xen_hvm_get_mem_type_t; typedef const xen_hvm_get_mem_type_t * __guest_handle_const_xen_hvm_get_mem_type_t;
# 203 "/var/xen-dev/xen/xen/include/public/hvm/hvm_op.h"
struct xen_hvm_evtchn_upcall_vector {
    uint32_t vcpu;
    uint8_t vector;
};
typedef struct xen_hvm_evtchn_upcall_vector xen_hvm_evtchn_upcall_vector_t;
typedef xen_hvm_evtchn_upcall_vector_t * __guest_handle_xen_hvm_evtchn_upcall_vector_t; typedef const xen_hvm_evtchn_upcall_vector_t * __guest_handle_const_xen_hvm_evtchn_upcall_vector_t;
# 219 "/var/xen-dev/xen/xen/include/public/hvm/hvm_op.h"
struct xen_hvm_altp2m_domain_state {

    uint8_t state;
};
typedef struct xen_hvm_altp2m_domain_state xen_hvm_altp2m_domain_state_t;
typedef xen_hvm_altp2m_domain_state_t * __guest_handle_xen_hvm_altp2m_domain_state_t; typedef const xen_hvm_altp2m_domain_state_t * __guest_handle_const_xen_hvm_altp2m_domain_state_t;

struct xen_hvm_altp2m_vcpu_enable_notify {
    uint32_t vcpu_id;
    uint32_t pad;

    uint64_t gfn;
};
typedef struct xen_hvm_altp2m_vcpu_enable_notify xen_hvm_altp2m_vcpu_enable_notify_t;
typedef xen_hvm_altp2m_vcpu_enable_notify_t * __guest_handle_xen_hvm_altp2m_vcpu_enable_notify_t; typedef const xen_hvm_altp2m_vcpu_enable_notify_t * __guest_handle_const_xen_hvm_altp2m_vcpu_enable_notify_t;

struct xen_hvm_altp2m_vcpu_disable_notify {
    uint32_t vcpu_id;
};
typedef struct xen_hvm_altp2m_vcpu_disable_notify xen_hvm_altp2m_vcpu_disable_notify_t;
typedef xen_hvm_altp2m_vcpu_disable_notify_t * __guest_handle_xen_hvm_altp2m_vcpu_disable_notify_t; typedef const xen_hvm_altp2m_vcpu_disable_notify_t * __guest_handle_const_xen_hvm_altp2m_vcpu_disable_notify_t;

struct xen_hvm_altp2m_view {

    uint16_t view;


    uint16_t hvmmem_default_access;
};
typedef struct xen_hvm_altp2m_view xen_hvm_altp2m_view_t;
typedef xen_hvm_altp2m_view_t * __guest_handle_xen_hvm_altp2m_view_t; typedef const xen_hvm_altp2m_view_t * __guest_handle_const_xen_hvm_altp2m_view_t;


struct xen_hvm_altp2m_set_mem_access {

    uint16_t view;

    uint16_t access;
    uint32_t pad;

    uint64_t gfn;
};
typedef struct xen_hvm_altp2m_set_mem_access xen_hvm_altp2m_set_mem_access_t;
typedef xen_hvm_altp2m_set_mem_access_t * __guest_handle_xen_hvm_altp2m_set_mem_access_t; typedef const xen_hvm_altp2m_set_mem_access_t * __guest_handle_const_xen_hvm_altp2m_set_mem_access_t;


struct xen_hvm_altp2m_mem_access {

    uint16_t view;

    uint16_t access;
    uint32_t pad;

    uint64_t gfn;
};
typedef struct xen_hvm_altp2m_mem_access xen_hvm_altp2m_mem_access_t;
typedef xen_hvm_altp2m_mem_access_t * __guest_handle_xen_hvm_altp2m_mem_access_t; typedef const xen_hvm_altp2m_mem_access_t * __guest_handle_const_xen_hvm_altp2m_mem_access_t;

struct xen_hvm_altp2m_set_mem_access_multi {

    uint16_t view;
    uint16_t pad;

    uint32_t nr;




    uint64_t opaque;

    __guest_handle_const_uint64 pfn_list;

    __guest_handle_const_uint8 access_list;
};

struct xen_hvm_altp2m_change_gfn {

    uint16_t view;
    uint16_t pad1;
    uint32_t pad2;

    uint64_t old_gfn;

    uint64_t new_gfn;
};
typedef struct xen_hvm_altp2m_change_gfn xen_hvm_altp2m_change_gfn_t;
typedef xen_hvm_altp2m_change_gfn_t * __guest_handle_xen_hvm_altp2m_change_gfn_t; typedef const xen_hvm_altp2m_change_gfn_t * __guest_handle_const_xen_hvm_altp2m_change_gfn_t;

struct xen_hvm_altp2m_get_vcpu_p2m_idx {
    uint32_t vcpu_id;
    uint16_t altp2m_idx;
};

struct xen_hvm_altp2m_op {
    uint32_t version;
    uint32_t cmd;
# 342 "/var/xen-dev/xen/xen/include/public/hvm/hvm_op.h"
    domid_t domain;
    uint16_t pad1;
    uint32_t pad2;
    union {
        struct xen_hvm_altp2m_domain_state domain_state;
        struct xen_hvm_altp2m_vcpu_enable_notify enable_notify;
        struct xen_hvm_altp2m_view view;

        struct xen_hvm_altp2m_set_mem_access set_mem_access;

        struct xen_hvm_altp2m_mem_access mem_access;
        struct xen_hvm_altp2m_change_gfn change_gfn;
        struct xen_hvm_altp2m_set_mem_access_multi set_mem_access_multi;
        struct xen_hvm_altp2m_suppress_ve suppress_ve;
        struct xen_hvm_altp2m_vcpu_disable_notify disable_notify;
        struct xen_hvm_altp2m_get_vcpu_p2m_idx get_vcpu_p2m_idx;
        uint8_t pad[64];
    } u;
};
typedef struct xen_hvm_altp2m_op xen_hvm_altp2m_op_t;
typedef xen_hvm_altp2m_op_t * __guest_handle_xen_hvm_altp2m_op_t; typedef const xen_hvm_altp2m_op_t * __guest_handle_const_xen_hvm_altp2m_op_t;
# 27 "/var/xen-dev/xen/xen/include/public/hvm/params.h" 2
# 34 "/var/xen-dev/xen/xen/include/asm/hvm/domain.h" 2

# 1 "/var/xen-dev/xen/xen/include/public/hvm/hvm_op.h" 1
# 36 "/var/xen-dev/xen/xen/include/asm/hvm/domain.h" 2


struct hvm_ioreq_page {
    gfn_t gfn;
    struct page_info *page;
    void *va;
};

struct hvm_ioreq_vcpu {
    struct list_head list_entry;
    struct vcpu *vcpu;
    evtchn_port_t ioreq_evtchn;
    _Bool pending;
};




struct hvm_ioreq_server {
    struct domain *target, *emulator;


    spinlock_t lock;

    struct hvm_ioreq_page ioreq;
    struct list_head ioreq_vcpu_list;
    struct hvm_ioreq_page bufioreq;


    spinlock_t bufioreq_lock;
    evtchn_port_t bufioreq_evtchn;
    struct rangeset *range[(XEN_DMOP_IO_RANGE_PCI + 1)];
    _Bool enabled;
    uint8_t bufioreq_handling;
};
# 82 "/var/xen-dev/xen/xen/include/asm/hvm/domain.h"
struct hvm_pi_ops {
    unsigned int flags;





    void (*vcpu_block)(struct vcpu *);
};



struct hvm_domain {

    struct {
        unsigned long base;
        unsigned long mask;
        unsigned long legacy_mask;
    } ioreq_gfn;


    struct {
        spinlock_t lock;
        struct hvm_ioreq_server *server[8];
    } ioreq_server;


    uint32_t pci_cf8;

    struct pl_time *pl_time;

    struct hvm_io_handler *io_handler;
    unsigned int io_handler_count;


    spinlock_t irq_lock;
    struct hvm_irq *irq;
    struct hvm_hw_vpic vpic[2];
    struct hvm_vioapic **vioapic;
    unsigned int nr_vioapics;
    struct hvm_hw_stdvga stdvga;
# 132 "/var/xen-dev/xen/xen/include/asm/hvm/domain.h"
    struct hvm_hw_pmtimer acpi;


    struct vcpu *i8259_target;


    struct radix_tree_root emuirq_pirq;

    uint64_t *params;


    struct list_head pinned_cacheattr_ranges;


    struct sh_dirty_vram *dirty_vram;




    spinlock_t uc_lock;
    bool_t is_in_uc_mode;


    struct list_head msixtbl_list;

    struct viridian_domain *viridian;

    bool_t mem_sharing_enabled;
    bool_t qemu_mapcache_invalidate;
    bool_t is_s3_suspended;





    uint64_t sync_tsc;

    uint64_t tsc_scaling_ratio;

    unsigned long *io_bitmap;


    struct list_head g2m_ioport_list;


    struct list_head mmcfg_regions;
    rwlock_t mmcfg_lock;


    struct list_head msix_tables;


    struct {
        spinlock_t lock;
        struct list_head list;
    } write_map;

    struct hvm_pi_ops pi_ops;

    union {
        struct vmx_domain vmx;
        struct svm_domain svm;
    };
};
# 8 "/var/xen-dev/xen/xen/include/asm/domain.h" 2
# 1 "/var/xen-dev/xen/xen/include/asm/e820.h" 1
# 13 "/var/xen-dev/xen/xen/include/asm/e820.h"
struct __attribute__((__packed__)) e820entry {
    uint64_t addr;
    uint64_t size;
    uint32_t type;
};



struct e820map {
    unsigned int nr_map;
    struct e820entry map[1024];
};

extern int sanitize_e820_map(struct e820entry *biosmap, unsigned int *pnr_map);
extern int e820_all_mapped(u64 start, u64 end, unsigned type);
extern int reserve_e820_ram(struct e820map *e820, uint64_t s, uint64_t e);
extern int e820_change_range_type(
    struct e820map *e820, uint64_t s, uint64_t e,
    uint32_t orig_type, uint32_t new_type);
extern int e820_add_range(
    struct e820map *, uint64_t s, uint64_t e, uint32_t type);
extern unsigned long init_e820(const char *, struct e820map *);
extern struct e820map e820;
extern struct e820map e820_raw;


extern unsigned int lowmem_kb, highmem_kb;
extern struct e820map bios_e820map[];
extern unsigned int bios_e820nr;
# 9 "/var/xen-dev/xen/xen/include/asm/domain.h" 2
# 1 "/var/xen-dev/xen/xen/include/asm/mce.h" 1
# 19 "/var/xen-dev/xen/xen/include/asm/mce.h"
struct vmce_bank {
    uint64_t mci_status;
    uint64_t mci_addr;
    uint64_t mci_misc;
    uint64_t mci_ctl2;
};


struct vmce {
    uint64_t mcg_cap;
    uint64_t mcg_status;
    uint64_t mcg_ext_ctl;
    spinlock_t lock;
    struct vmce_bank bank[2];
};


extern void vmce_init_vcpu(struct vcpu *);
extern int vmce_restore_vcpu(struct vcpu *, const struct hvm_vmce_vcpu *);
extern int vmce_wrmsr(uint32_t msr, uint64_t val);
extern int vmce_rdmsr(uint32_t msr, uint64_t *val);
extern _Bool vmce_has_lmce(const struct vcpu *v);
extern int vmce_enable_mca_cap(struct domain *d, uint64_t cap);

extern __typeof__(unsigned int) per_cpu__nr_mce_banks;
# 10 "/var/xen-dev/xen/xen/include/asm/domain.h" 2
# 1 "/var/xen-dev/xen/xen/include/asm/vpmu.h" 1
# 41 "/var/xen-dev/xen/xen/include/asm/vpmu.h"
struct arch_vpmu_ops {
    int (*do_wrmsr)(unsigned int msr, uint64_t msr_content,
                    uint64_t supported);
    int (*do_rdmsr)(unsigned int msr, uint64_t *msr_content);
    int (*do_interrupt)(struct cpu_user_regs *regs);
    void (*arch_vpmu_destroy)(struct vcpu *v);
    int (*arch_vpmu_save)(struct vcpu *v, bool_t to_guest);
    int (*arch_vpmu_load)(struct vcpu *v, bool_t from_guest);
    void (*arch_vpmu_dump)(const struct vcpu *);
};

int core2_vpmu_init(void);
int vmx_vpmu_initialise(struct vcpu *);
int amd_vpmu_init(void);
int hygon_vpmu_init(void);
int svm_vpmu_initialise(struct vcpu *);

struct vpmu_struct {
    u32 flags;
    u32 last_pcpu;
    u32 hw_lapic_lvtpc;
    void *context;
    void *priv_context;
    const struct arch_vpmu_ops *arch_vpmu_ops;
    struct xen_pmu_data *xenpmu_data;
    spinlock_t vpmu_lock;
};
# 84 "/var/xen-dev/xen/xen/include/asm/vpmu.h"
static __inline__ void vpmu_set(struct vpmu_struct *vpmu, const u32 mask)
{
    vpmu->flags |= mask;
}
static __inline__ void vpmu_reset(struct vpmu_struct *vpmu, const u32 mask)
{
    vpmu->flags &= ~mask;
}
static __inline__ void vpmu_clear(struct vpmu_struct *vpmu)
{

    vpmu->flags &= 0x80;
}
static __inline__ bool_t vpmu_is_set(const struct vpmu_struct *vpmu, const u32 mask)
{
    return !!(vpmu->flags & mask);
}
static __inline__ bool_t vpmu_are_all_set(const struct vpmu_struct *vpmu,
                                      const u32 mask)
{
    return !!((vpmu->flags & mask) == mask);
}

void vpmu_lvtpc_update(uint32_t val);
int vpmu_do_msr(unsigned int msr, uint64_t *msr_content,
                uint64_t supported, bool_t is_write);
void vpmu_do_interrupt(struct cpu_user_regs *regs);
void vpmu_initialise(struct vcpu *v);
void vpmu_destroy(struct vcpu *v);
void vpmu_save(struct vcpu *v);
int vpmu_load(struct vcpu *v, bool_t from_guest);
void vpmu_dump(struct vcpu *v);

static __inline__ int vpmu_do_wrmsr(unsigned int msr, uint64_t msr_content,
                                uint64_t supported)
{
    return vpmu_do_msr(msr, &msr_content, supported, 1);
}
static __inline__ int vpmu_do_rdmsr(unsigned int msr, uint64_t *msr_content)
{
    return vpmu_do_msr(msr, msr_content, 0, 0);
}

extern unsigned int vpmu_mode;
extern unsigned int vpmu_features;
extern _Bool opt_rtm_abort;


static __inline__ void vpmu_switch_from(struct vcpu *prev)
{
    if ( vpmu_mode & ((1<<0) | (1<<1)) )
        vpmu_save(prev);
}

static __inline__ void vpmu_switch_to(struct vcpu *next)
{
    if ( vpmu_mode & ((1<<0) | (1<<1)) )
        vpmu_load(next, 0);
}
# 11 "/var/xen-dev/xen/xen/include/asm/domain.h" 2

# 1 "/var/xen-dev/xen/xen/include/public/vcpu.h" 1
# 81 "/var/xen-dev/xen/xen/include/public/vcpu.h"
struct vcpu_runstate_info {

    int state;

    uint64_t state_entry_time;
# 96 "/var/xen-dev/xen/xen/include/public/vcpu.h"
    uint64_t time[4];
};
typedef struct vcpu_runstate_info vcpu_runstate_info_t;
typedef vcpu_runstate_info_t * __guest_handle_vcpu_runstate_info_t; typedef const vcpu_runstate_info_t * __guest_handle_const_vcpu_runstate_info_t;
# 133 "/var/xen-dev/xen/xen/include/public/vcpu.h"
struct vcpu_register_runstate_memory_area {
    union {
        __guest_handle_vcpu_runstate_info_t h;
        struct vcpu_runstate_info *v;
        uint64_t p;
    } addr;
};
typedef struct vcpu_register_runstate_memory_area vcpu_register_runstate_memory_area_t;
typedef vcpu_register_runstate_memory_area_t * __guest_handle_vcpu_register_runstate_memory_area_t; typedef const vcpu_register_runstate_memory_area_t * __guest_handle_const_vcpu_register_runstate_memory_area_t;
# 150 "/var/xen-dev/xen/xen/include/public/vcpu.h"
struct vcpu_set_periodic_timer {
    uint64_t period_ns;
};
typedef struct vcpu_set_periodic_timer vcpu_set_periodic_timer_t;
typedef vcpu_set_periodic_timer_t * __guest_handle_vcpu_set_periodic_timer_t; typedef const vcpu_set_periodic_timer_t * __guest_handle_const_vcpu_set_periodic_timer_t;







struct vcpu_set_singleshot_timer {
    uint64_t timeout_abs_ns;
    uint32_t flags;
};
typedef struct vcpu_set_singleshot_timer vcpu_set_singleshot_timer_t;
typedef vcpu_set_singleshot_timer_t * __guest_handle_vcpu_set_singleshot_timer_t; typedef const vcpu_set_singleshot_timer_t * __guest_handle_const_vcpu_set_singleshot_timer_t;
# 184 "/var/xen-dev/xen/xen/include/public/vcpu.h"
struct vcpu_register_vcpu_info {
    uint64_t mfn;
    uint32_t offset;
    uint32_t rsvd;
};
typedef struct vcpu_register_vcpu_info vcpu_register_vcpu_info_t;
typedef vcpu_register_vcpu_info_t * __guest_handle_vcpu_register_vcpu_info_t; typedef const vcpu_register_vcpu_info_t * __guest_handle_const_vcpu_register_vcpu_info_t;
# 202 "/var/xen-dev/xen/xen/include/public/vcpu.h"
struct vcpu_get_physid {
    uint64_t phys_id;
};
typedef struct vcpu_get_physid vcpu_get_physid_t;
typedef vcpu_get_physid_t * __guest_handle_vcpu_get_physid_t; typedef const vcpu_get_physid_t * __guest_handle_const_vcpu_get_physid_t;
# 227 "/var/xen-dev/xen/xen/include/public/vcpu.h"
typedef vcpu_time_info_t * __guest_handle_vcpu_time_info_t; typedef const vcpu_time_info_t * __guest_handle_const_vcpu_time_info_t;
struct vcpu_register_time_memory_area {
    union {
        __guest_handle_vcpu_time_info_t h;
        struct vcpu_time_info *v;
        uint64_t p;
    } addr;
};
typedef struct vcpu_register_time_memory_area vcpu_register_time_memory_area_t;
typedef vcpu_register_time_memory_area_t * __guest_handle_vcpu_register_time_memory_area_t; typedef const vcpu_register_time_memory_area_t * __guest_handle_const_vcpu_register_time_memory_area_t;
# 13 "/var/xen-dev/xen/xen/include/asm/domain.h" 2
# 1 "/var/xen-dev/xen/xen/include/public/hvm/hvm_info_table.h" 1
# 45 "/var/xen-dev/xen/xen/include/public/hvm/hvm_info_table.h"
struct hvm_info_table {
    char signature[8];
    uint32_t length;
    uint8_t checksum;


    uint8_t apic_mode;


    uint32_t nr_vcpus;
# 66 "/var/xen-dev/xen/xen/include/public/hvm/hvm_info_table.h"
    uint32_t low_mem_pgend;




    uint32_t reserved_mem_pgstart;




    uint32_t high_mem_pgend;


    uint8_t vcpu_online[(128 + 7)/8];
};
# 14 "/var/xen-dev/xen/xen/include/asm/domain.h" 2
# 32 "/var/xen-dev/xen/xen/include/asm/domain.h"
struct trap_bounce {
    uint32_t error_code;
    uint8_t flags;
    uint16_t cs;
    unsigned long eip;
};




struct mapcache_vcpu {

    unsigned int shadow_epoch;


    struct vcpu_maphash_entry {
        unsigned long mfn;
        uint32_t idx;
        uint32_t refcnt;
    } hash[8];
};

struct mapcache_domain {

    unsigned int entries;
    unsigned int cursor;


    spinlock_t lock;


    unsigned int epoch;
    u32 tlbflush_timestamp;


    unsigned long *inuse;
    unsigned long *garbage;
};

int mapcache_domain_init(struct domain *);
int mapcache_vcpu_init(struct vcpu *);
void mapcache_override_current(struct vcpu *);


void toggle_guest_mode(struct vcpu *);

void toggle_guest_pt(struct vcpu *);

void cpuid_policy_updated(struct vcpu *v);





void init_hypercall_page(struct domain *d, void *);




struct shadow_domain {
# 127 "/var/xen-dev/xen/xen/include/asm/domain.h"
};

struct shadow_vcpu {
# 155 "/var/xen-dev/xen/xen/include/asm/domain.h"
};




struct hap_domain {
    struct page_list_head freelist;
    unsigned int total_pages;
    unsigned int free_pages;
    unsigned int p2m_pages;
};




struct log_dirty_domain {

    mfn_t top;
    unsigned int allocs;
    unsigned int failed_allocs;


    unsigned int fault_count;
    unsigned int dirty_count;


    const struct log_dirty_ops {
        int (*enable )(struct domain *d, _Bool log_global);
        int (*disable )(struct domain *d);
        void (*clean )(struct domain *d);
    } *ops;
};

struct paging_domain {

    mm_lock_t lock;


    u32 mode;

    bool_t p2m_alloc_failed;

    struct shadow_domain shadow;

    struct hap_domain hap;

    struct log_dirty_domain log_dirty;


    struct {
        const struct domain *dom;
        unsigned int op;
        union {
            struct {
                unsigned long done:52 - 12;
                unsigned long i4:9;
                unsigned long i3:9;
            } log_dirty;
        };
    } preempt;



    struct page_info * (*alloc_page)(struct domain *d);
    void (*free_page)(struct domain *d, struct page_info *pg);
};

struct paging_vcpu {

    const struct paging_mode *mode;

    const struct paging_mode *nestedmode;

    unsigned int last_write_was_pt:1;

    unsigned int last_write_emul_ok:1;

    struct shadow_vtlb *vtlb;
    spinlock_t vtlb_lock;


    struct shadow_vcpu shadow;
};






struct p2m_domain;
struct time_scale {
    int shift;
    u32 mul_frac;
};

struct pv_domain
{
    l1_pgentry_t **gdt_ldt_l1tab;

    atomic_t nr_l4_pages;


    _Bool xpti;

    _Bool pcid;

    _Bool check_l1tf;


    struct mapcache_domain mapcache;

    struct cpuidmasks *cpuidmasks;
};

struct monitor_write_data {
    struct {
        unsigned int msr : 1;
        unsigned int cr0 : 1;
        unsigned int cr3 : 1;
        unsigned int cr4 : 1;
    } do_write;

    uint32_t msr;
    uint64_t value;
    uint64_t cr0;
    uint64_t cr3;
    uint64_t cr4;
};

struct arch_domain
{
    struct page_info *perdomain_l3_pg;

    unsigned int hv_compat_vstart;


    unsigned int physaddr_bitsize;


    struct rangeset *ioport_caps;
    uint32_t pci_cf8;
    uint8_t cmos_idx;

    union {
        struct pv_domain pv;
        struct hvm_domain hvm;
    };

    struct paging_domain paging;
    struct p2m_domain *p2m;


    int page_alloc_unlock_level;


    unsigned int rel_priv;
    struct page_list_head relmem_list;

    const struct arch_csw {
        void (*from)(struct vcpu *);
        void (*to)(struct vcpu *);
        void (*tail)(struct vcpu *);
    } *ctxt_switch;
# 332 "/var/xen-dev/xen/xen/include/asm/domain.h"
    struct radix_tree_root irq_pirq;


    bool_t is_32bit_pv;

    bool_t has_32bit_shinfo;


    bool_t auto_unmask;
# 355 "/var/xen-dev/xen/xen/include/asm/domain.h"
    uint8_t x87_fip_width;


    struct cpuid_policy *cpuid;
    struct msr_policy *msr;

    struct PITState vpit;


    int tsc_mode;
    bool_t vtsc;
    s_time_t vtsc_last;
    spinlock_t vtsc_lock;
    uint64_t vtsc_offset;
    uint32_t tsc_khz;

    struct time_scale vtsc_to_ns;

    struct time_scale ns_to_vtsc;

    uint32_t incarnation;


    uint64_t vtsc_kerncount;
    uint64_t vtsc_usercount;



    spinlock_t e820_lock;
    struct e820entry *e820;
    unsigned int nr_e820;


    unsigned int psr_rmid;

    unsigned int *psr_cos_ids;


    unsigned long *pirq_eoi_map;
    unsigned long pirq_eoi_map_mfn;


    struct {
        unsigned int write_ctrlreg_enabled : 4;
        unsigned int write_ctrlreg_sync : 4;
        unsigned int write_ctrlreg_onchangeonly : 4;
        unsigned int singlestep_enabled : 1;
        unsigned int software_breakpoint_enabled : 1;
        unsigned int debug_exception_enabled : 1;
        unsigned int debug_exception_sync : 1;
        unsigned int cpuid_enabled : 1;
        unsigned int descriptor_access_enabled : 1;
        unsigned int guest_request_userspace_enabled : 1;
        unsigned int emul_unimplemented_enabled : 1;




        unsigned int inguest_pagefault_disabled : 1;
        struct monitor_msr_bitmap *msr_bitmap;
        uint64_t write_ctrlreg_mask[4];
    } monitor;


    bool_t mem_access_emulate_each_rep;


    uint32_t emulation_flags;
} __attribute__((__aligned__((1 << (CONFIG_X86_L1_CACHE_SHIFT)))));
# 478 "/var/xen-dev/xen/xen/include/asm/domain.h"
struct pv_vcpu
{

    struct mapcache_vcpu mapcache;

    struct trap_info *trap_ctxt;

    unsigned long gdt_frames[14];
    unsigned long ldt_base;
    unsigned int gdt_ents, ldt_ents;

    unsigned long kernel_ss, kernel_sp;
    unsigned long ctrlreg[8];

    unsigned long event_callback_eip;
    unsigned long failsafe_callback_eip;
    union {
        unsigned long syscall_callback_eip;
        struct {
            unsigned int event_callback_cs;
            unsigned int failsafe_callback_cs;
        };
    };

    unsigned long syscall32_callback_eip;
    unsigned long sysenter_callback_eip;
    unsigned short syscall32_callback_cs;
    unsigned short sysenter_callback_cs;
    bool_t syscall32_disables_events;
    bool_t sysenter_disables_events;


    unsigned long fs_base;
    unsigned long gs_base_kernel;
    unsigned long gs_base_user;


    struct trap_bounce trap_bounce;


    __guest_handle_uint8 iobmp;
    unsigned int iobmp_limit;

    unsigned int iopl;
# 534 "/var/xen-dev/xen/xen/include/asm/domain.h"
    uint32_t dr7_emul;


    bool_t need_update_runstate_area;
    struct vcpu_time_info pending_system_time;
};

struct arch_vcpu
{





    void *fpu_ctxt;
    unsigned long vgc_flags;
    struct cpu_user_regs user_regs;


    unsigned long dr[4];
    unsigned long dr7;
    unsigned int dr6;



    unsigned long flags;

    struct vpmu_struct vpmu;


    union {
        struct pv_vcpu pv;
        struct hvm_vcpu hvm;
    };

    pagetable_t guest_table_user;
    pagetable_t guest_table;
    struct page_info *old_guest_table;
    struct page_info *old_guest_ptpg;

    _Bool old_guest_table_partial;



    pagetable_t shadow_table[4];
    pagetable_t monitor_table;
    unsigned long cr3;







    struct xsave_struct *xsave_area;
    uint64_t xcr0;







    uint64_t xcr0_accum;


    bool_t nonlazy_xstate_used;


    _Bool fully_eager_fpu;

    struct vmce vmce;

    struct paging_vcpu paging;

    uint32_t gdbsx_vcpu_event;


    __guest_handle_vcpu_time_info_t time_info_guest;

    struct arch_vm_event *vm_event;

    struct vcpu_msrs *msrs;

    struct {
        _Bool next_interrupt_enabled;
    } monitor;
};

struct guest_memory_policy
{
    _Bool nested_guest_mode;
};

void update_guest_memory_policy(struct vcpu *v,
                                struct guest_memory_policy *policy);

_Bool update_runstate_area(struct vcpu *);
_Bool update_secondary_system_time(struct vcpu *,
                                  struct vcpu_time_info *);

void vcpu_show_execution_state(struct vcpu *);
void vcpu_show_registers(const struct vcpu *);

static __inline__ struct vcpu_guest_context *alloc_vcpu_guest_context(void)
{
    return vmalloc(sizeof(struct vcpu_guest_context));
}

static __inline__ void free_vcpu_guest_context(struct vcpu_guest_context *vgc)
{
    vfree(vgc);
}

void arch_vcpu_regs_init(struct vcpu *v);

struct vcpu_hvm_context;
int arch_set_info_hvm_guest(struct vcpu *v, const struct vcpu_hvm_context *ctx);




static __inline__ void pv_inject_event(const struct x86_event *event)
{
    do { do { ({ _Static_assert(!((658) >> ((31 - 24) + (31 - 24))), "!(" "(658) >> (BUG_LINE_LO_WIDTH + BUG_LINE_HI_WIDTH)" ")"); }); ({ _Static_assert(!((3) >= 4), "!(" "(3) >= BUGFRAME_NR" ")"); }); asm volatile ( ".Lbug%=: ud2\n" ".pushsection .bug_frames.%c[bf_type], \"a\", @progbits\n" ".p2align 2\n" ".Lfrm%=:\n" ".long (.Lbug%= - .Lfrm%=) + %c[bf_line_hi]\n" ".long (%c[bf_ptr] - .Lfrm%=) + %c[bf_line_lo]\n" ".if " "1" "\n" ".long 0, %c[bf_msg] - .Lfrm%=\n" ".endif\n" ".popsection\n" :: [bf_type] "i" (3), [bf_ptr] "i" ("/var/xen-dev/xen/xen/include/asm/domain.h"), [bf_msg] "i" ("unreachable"), [bf_line_lo] "i" ((658 & ((1 << (31 - 24)) - 1)) << 24), [bf_line_hi] "i" (((658) >> (31 - 24)) << 24) ); } while (0); __builtin_unreachable(); } while (0);
}


static __inline__ void pv_inject_hw_exception(unsigned int vector, int errcode)
{
    const struct x86_event event = {
        .vector = vector,
        .type = X86_EVENTTYPE_HW_EXCEPTION,
        .error_code = errcode,
    };

    pv_inject_event(&event);
}

static __inline__ void pv_inject_page_fault(int errcode, unsigned long cr2)
{
    const struct x86_event event = {
        .vector = 14,
        .type = X86_EVENTTYPE_HW_EXCEPTION,
        .error_code = errcode,
        .cr2 = cr2,
    };

    pv_inject_event(&event);
}

static __inline__ void pv_inject_sw_interrupt(unsigned int vector)
{
    const struct x86_event event = {
        .vector = vector,
        .type = X86_EVENTTYPE_SW_INTERRUPT,
        .error_code = (-1),
    };

    pv_inject_event(&event);
}
# 9 "/var/xen-dev/xen/xen/include/xen/domain.h" 2


typedef union {
    struct vcpu_guest_context *nat;
    struct compat_vcpu_guest_context *cmp;
} vcpu_guest_context_u __attribute__((__transparent_union__));

struct vcpu *vcpu_create(struct domain *d, unsigned int vcpu_id);

unsigned int dom0_max_vcpus(void);
struct vcpu *alloc_dom0_vcpu0(struct domain *dom0);

int vcpu_reset(struct vcpu *);
int vcpu_up(struct vcpu *v);

void setup_system_domains(void);

struct xen_domctl_getdomaininfo;
void getdomaininfo(struct domain *d, struct xen_domctl_getdomaininfo *info);
void arch_get_domain_info(const struct domain *d,
                          struct xen_domctl_getdomaininfo *info);






struct domain *alloc_domain_struct(void);
void free_domain_struct(struct domain *d);


struct vcpu *alloc_vcpu_struct(const struct domain *d);
void free_vcpu_struct(struct vcpu *v);



struct pirq *alloc_pirq_struct(struct domain *);

void free_pirq_struct(void *);
# 57 "/var/xen-dev/xen/xen/include/xen/domain.h"
int arch_vcpu_create(struct vcpu *v);
void arch_vcpu_destroy(struct vcpu *v);

int map_vcpu_info(struct vcpu *v, unsigned long gfn, unsigned offset);
void unmap_vcpu_info(struct vcpu *v);

int arch_domain_create(struct domain *d,
                       struct xen_domctl_createdomain *config);

void arch_domain_destroy(struct domain *d);

void arch_domain_shutdown(struct domain *d);
void arch_domain_pause(struct domain *d);
void arch_domain_unpause(struct domain *d);

int arch_domain_soft_reset(struct domain *d);

void arch_domain_creation_finished(struct domain *d);

void arch_p2m_set_access_required(struct domain *d, _Bool access_required);

int arch_set_info_guest(struct vcpu *, vcpu_guest_context_u);
void arch_get_info_guest(struct vcpu *, vcpu_guest_context_u);

int arch_initialise_vcpu(struct vcpu *v, __guest_handle_void arg);
int default_initialise_vcpu(struct vcpu *v, __guest_handle_void arg);

int domain_relinquish_resources(struct domain *d);

void dump_pageframe_info(struct domain *d);

void arch_dump_vcpu_info(struct vcpu *v);

void arch_dump_domain_info(struct domain *d);

int arch_vcpu_reset(struct vcpu *);

bool_t domctl_lock_acquire(void);
void domctl_lock_release(void);







int continue_hypercall_on_cpu(
    unsigned int cpu, long (*func)(void *data), void *data);

extern unsigned int xen_processor_pmbits;

extern bool_t opt_dom0_vcpus_pin;
extern cpumask_t dom0_cpus;
extern _Bool dom0_affinity_relaxed;


struct vnuma_info {
    unsigned int nr_vnodes;
    unsigned int nr_vmemranges;
    unsigned int *vdistance;
    unsigned int *vcpu_to_vnode;
    nodeid_t *vnode_to_pnode;
    struct xen_vmemrange *vmemrange;
};

void vnuma_destroy(struct vnuma_info *vnuma);
# 12 "/var/xen-dev/xen/xen/include/xen/sched.h" 2



# 1 "/var/xen-dev/xen/xen/include/xen/nodemask.h" 1
# 58 "/var/xen-dev/xen/xen/include/xen/nodemask.h"
# 1 "/var/xen-dev/xen/xen/include/xen/numa.h" 1
# 59 "/var/xen-dev/xen/xen/include/xen/nodemask.h" 2

typedef struct { unsigned long bits[((((1 << 6))+BITS_PER_LONG-1)/BITS_PER_LONG)]; } nodemask_t;
# 70 "/var/xen-dev/xen/xen/include/xen/nodemask.h"
extern nodemask_t _unused_nodemask_arg_;


static __inline__ void __node_set(int node, volatile nodemask_t *dstp)
{
 ({ if ( (sizeof(*(dstp->bits)) < 4) ) __bitop_bad_size(); set_bit(node, dstp->bits); });
}


static __inline__ void __node_clear(int node, volatile nodemask_t *dstp)
{
 ({ if ( (sizeof(*(dstp->bits)) < 4) ) __bitop_bad_size(); clear_bit(node, dstp->bits); });
}


static __inline__ void __nodes_setall(nodemask_t *dstp, int nbits)
{
 bitmap_fill(dstp->bits, nbits);
}


static __inline__ void __nodes_clear(nodemask_t *dstp, int nbits)
{
 bitmap_zero(dstp->bits, nbits);
}

static __inline__ _Bool nodemask_test(unsigned int node, const nodemask_t *dst)
{
    return ({ if ( (sizeof(*(dst->bits)) < 4) ) __bitop_bad_size(); __builtin_constant_p(node) ? constant_test_bit(node, dst->bits) : variable_test_bit(node, dst->bits); });
}



static __inline__ int __node_test_and_set(int node, nodemask_t *addr)
{
 return ({ if ( (sizeof(*(addr->bits)) < 4) ) __bitop_bad_size(); test_and_set_bit(node, addr->bits); });
}



static __inline__ void __nodes_and(nodemask_t *dstp, const nodemask_t *src1p,
     const nodemask_t *src2p, int nbits)
{
 bitmap_and(dstp->bits, src1p->bits, src2p->bits, nbits);
}



static __inline__ void __nodes_or(nodemask_t *dstp, const nodemask_t *src1p,
     const nodemask_t *src2p, int nbits)
{
 bitmap_or(dstp->bits, src1p->bits, src2p->bits, nbits);
}



static __inline__ void __nodes_xor(nodemask_t *dstp, const nodemask_t *src1p,
     const nodemask_t *src2p, int nbits)
{
 bitmap_xor(dstp->bits, src1p->bits, src2p->bits, nbits);
}



static __inline__ void __nodes_andnot(nodemask_t *dstp, const nodemask_t *src1p,
     const nodemask_t *src2p, int nbits)
{
 bitmap_andnot(dstp->bits, src1p->bits, src2p->bits, nbits);
}



static __inline__ void __nodes_complement(nodemask_t *dstp,
     const nodemask_t *srcp, int nbits)
{
 bitmap_complement(dstp->bits, srcp->bits, nbits);
}



static __inline__ int __nodes_equal(const nodemask_t *src1p,
     const nodemask_t *src2p, int nbits)
{
 return bitmap_equal(src1p->bits, src2p->bits, nbits);
}



static __inline__ int __nodes_intersects(const nodemask_t *src1p,
     const nodemask_t *src2p, int nbits)
{
 return bitmap_intersects(src1p->bits, src2p->bits, nbits);
}



static __inline__ int __nodes_subset(const nodemask_t *src1p,
     const nodemask_t *src2p, int nbits)
{
 return bitmap_subset(src1p->bits, src2p->bits, nbits);
}


static __inline__ int __nodes_empty(const nodemask_t *srcp, int nbits)
{
 return bitmap_empty(srcp->bits, nbits);
}


static __inline__ int __nodes_full(const nodemask_t *srcp, int nbits)
{
 return bitmap_full(srcp->bits, nbits);
}


static __inline__ int __nodes_weight(const nodemask_t *srcp, int nbits)
{
 return bitmap_weight(srcp->bits, nbits);
}





static __inline__ int __first_node(const nodemask_t *srcp, int nbits)
{
 return ({ int __x = (nbits); int __y = (({ unsigned int r__; const unsigned long *a__ = (srcp->bits); unsigned int s__ = (nbits); unsigned int o__ = (0); if ( o__ >= s__ ) r__ = s__; else if ( __builtin_constant_p(nbits) && s__ <= BITS_PER_LONG ) r__ = o__ + __scanbit(*(const unsigned long *)(a__) >> o__, s__); else if ( __builtin_constant_p(0) && !o__ ) r__ = __find_first_bit(a__, s__); else r__ = __find_next_bit(a__, s__, o__); r__; })); __x < __y ? __x: __y; });
}


static __inline__ int __next_node(int n, const nodemask_t *srcp, int nbits)
{
 return ({ int __x = (nbits); int __y = (({ unsigned int r__; const unsigned long *a__ = (srcp->bits); unsigned int s__ = (nbits); unsigned int o__ = (n+1); if ( o__ >= s__ ) r__ = s__; else if ( __builtin_constant_p(nbits) && s__ <= BITS_PER_LONG ) r__ = o__ + __scanbit(*(const unsigned long *)(a__) >> o__, s__); else if ( __builtin_constant_p(n+1) && !o__ ) r__ = __find_first_bit(a__, s__); else r__ = __find_next_bit(a__, s__, o__); r__; })); __x < __y ? __x: __y; });
}


static __inline__ int __last_node(const nodemask_t *srcp, int nbits)
{
 int node, pnode = nbits;
 for (node = __first_node(srcp, nbits);
      node < nbits;
      node = __next_node(node, srcp, nbits))
  pnode = node;
 return pnode;
}
# 229 "/var/xen-dev/xen/xen/include/xen/nodemask.h"
static __inline__ int __cycle_node(int n, const nodemask_t *maskp, int nbits)
{
    int nxt = __next_node(n, maskp, nbits);

    if (nxt == nbits)
        nxt = __first_node(maskp, nbits);
    return nxt;
}
# 278 "/var/xen-dev/xen/xen/include/xen/nodemask.h"
extern nodemask_t node_online_map;
# 16 "/var/xen-dev/xen/xen/include/xen/sched.h" 2

# 1 "/var/xen-dev/xen/xen/include/xen/multicall.h" 1
# 14 "/var/xen-dev/xen/xen/include/xen/multicall.h"
struct mc_state {
    unsigned long flags;
    union {
        struct multicall_entry call;



    };
};

enum mc_disposition {
    mc_continue,
    mc_exit,
    mc_preempt,
} arch_do_multicall_call(struct mc_state *mc);
# 18 "/var/xen-dev/xen/xen/include/xen/sched.h" 2
# 1 "/var/xen-dev/xen/xen/include/xen/nospec.h" 1
# 11 "/var/xen-dev/xen/xen/include/xen/nospec.h"
# 1 "/var/xen-dev/xen/xen/include/asm/nospec.h" 1
# 10 "/var/xen-dev/xen/xen/include/asm/nospec.h"
static __inline__ __attribute__ ((__always_inline__)) _Bool barrier_nospec_true(void)
{



    return 1;
}


static __inline__ __attribute__ ((__always_inline__)) _Bool evaluate_nospec(_Bool condition)
{
    return condition ? barrier_nospec_true() : !barrier_nospec_true();
}


static __inline__ __attribute__ ((__always_inline__)) void block_speculation(void)
{
    barrier_nospec_true();
}
# 12 "/var/xen-dev/xen/xen/include/xen/nospec.h" 2
# 19 "/var/xen-dev/xen/xen/include/xen/sched.h" 2





# 1 "/var/xen-dev/xen/xen/include/xen/vpci.h" 1
# 215 "/var/xen-dev/xen/xen/include/xen/vpci.h"
struct vpci_vcpu {};

static __inline__ int vpci_add_handlers(struct pci_dev *pdev)
{
    return 0;
}

static __inline__ void vpci_dump_msi(void) { }

static __inline__ uint32_t vpci_read(pci_sbdf_t sbdf, unsigned int reg,
                                 unsigned int size)
{
    do { do { ({ _Static_assert(!((227) >> ((31 - 24) + (31 - 24))), "!(" "(227) >> (BUG_LINE_LO_WIDTH + BUG_LINE_HI_WIDTH)" ")"); }); ({ _Static_assert(!((3) >= 4), "!(" "(3) >= BUGFRAME_NR" ")"); }); asm volatile ( ".Lbug%=: ud2\n" ".pushsection .bug_frames.%c[bf_type], \"a\", @progbits\n" ".p2align 2\n" ".Lfrm%=:\n" ".long (.Lbug%= - .Lfrm%=) + %c[bf_line_hi]\n" ".long (%c[bf_ptr] - .Lfrm%=) + %c[bf_line_lo]\n" ".if " "1" "\n" ".long 0, %c[bf_msg] - .Lfrm%=\n" ".endif\n" ".popsection\n" :: [bf_type] "i" (3), [bf_ptr] "i" ("/var/xen-dev/xen/xen/include/xen/vpci.h"), [bf_msg] "i" ("unreachable"), [bf_line_lo] "i" ((227 & ((1 << (31 - 24)) - 1)) << 24), [bf_line_hi] "i" (((227) >> (31 - 24)) << 24) ); } while (0); __builtin_unreachable(); } while (0);
    return ~(uint32_t)0;
}

static __inline__ void vpci_write(pci_sbdf_t sbdf, unsigned int reg,
                              unsigned int size, uint32_t data)
{
    do { do { ({ _Static_assert(!((234) >> ((31 - 24) + (31 - 24))), "!(" "(234) >> (BUG_LINE_LO_WIDTH + BUG_LINE_HI_WIDTH)" ")"); }); ({ _Static_assert(!((3) >= 4), "!(" "(3) >= BUGFRAME_NR" ")"); }); asm volatile ( ".Lbug%=: ud2\n" ".pushsection .bug_frames.%c[bf_type], \"a\", @progbits\n" ".p2align 2\n" ".Lfrm%=:\n" ".long (.Lbug%= - .Lfrm%=) + %c[bf_line_hi]\n" ".long (%c[bf_ptr] - .Lfrm%=) + %c[bf_line_lo]\n" ".if " "1" "\n" ".long 0, %c[bf_msg] - .Lfrm%=\n" ".endif\n" ".popsection\n" :: [bf_type] "i" (3), [bf_ptr] "i" ("/var/xen-dev/xen/xen/include/xen/vpci.h"), [bf_msg] "i" ("unreachable"), [bf_line_lo] "i" ((234 & ((1 << (31 - 24)) - 1)) << 24), [bf_line_hi] "i" (((234) >> (31 - 24)) << 24) ); } while (0); __builtin_unreachable(); } while (0);
}

static __inline__ _Bool vpci_process_pending(struct vcpu *v)
{
    do { do { ({ _Static_assert(!((239) >> ((31 - 24) + (31 - 24))), "!(" "(239) >> (BUG_LINE_LO_WIDTH + BUG_LINE_HI_WIDTH)" ")"); }); ({ _Static_assert(!((3) >= 4), "!(" "(3) >= BUGFRAME_NR" ")"); }); asm volatile ( ".Lbug%=: ud2\n" ".pushsection .bug_frames.%c[bf_type], \"a\", @progbits\n" ".p2align 2\n" ".Lfrm%=:\n" ".long (.Lbug%= - .Lfrm%=) + %c[bf_line_hi]\n" ".long (%c[bf_ptr] - .Lfrm%=) + %c[bf_line_lo]\n" ".if " "1" "\n" ".long 0, %c[bf_msg] - .Lfrm%=\n" ".endif\n" ".popsection\n" :: [bf_type] "i" (3), [bf_ptr] "i" ("/var/xen-dev/xen/xen/include/xen/vpci.h"), [bf_msg] "i" ("unreachable"), [bf_line_lo] "i" ((239 & ((1 << (31 - 24)) - 1)) << 24), [bf_line_hi] "i" (((239) >> (31 - 24)) << 24) ); } while (0); __builtin_unreachable(); } while (0);
    return 0;
}
# 25 "/var/xen-dev/xen/xen/include/xen/sched.h" 2
# 1 "/var/xen-dev/xen/xen/include/xen/wait.h" 1
# 16 "/var/xen-dev/xen/xen/include/xen/wait.h"
struct waitqueue_head {
    spinlock_t lock;
    struct list_head list;
};
# 29 "/var/xen-dev/xen/xen/include/xen/wait.h"
void init_waitqueue_head(struct waitqueue_head *wq);
void destroy_waitqueue_head(struct waitqueue_head *wq);


void wake_up_nr(struct waitqueue_head *wq, unsigned int nr);
void wake_up_one(struct waitqueue_head *wq);
void wake_up_all(struct waitqueue_head *wq);
# 52 "/var/xen-dev/xen/xen/include/xen/wait.h"
int init_waitqueue_vcpu(struct vcpu *v);
void destroy_waitqueue_vcpu(struct vcpu *v);
void prepare_to_wait(struct waitqueue_head *wq);
void wait(void);
void finish_wait(struct waitqueue_head *wq);
void check_wakeup_from_wait(void);
# 26 "/var/xen-dev/xen/xen/include/xen/sched.h" 2




# 1 "/var/xen-dev/xen/xen/include/public/vm_event.h" 1
# 31 "/var/xen-dev/xen/xen/include/xen/sched.h" 2
# 51 "/var/xen-dev/xen/xen/include/xen/sched.h"
extern struct domain *hardware_domain;
# 84 "/var/xen-dev/xen/xen/include/xen/sched.h"
struct evtchn
{
    spinlock_t lock;







    u8 state;
    u8 xen_consumer:3;
    u8 pending:1;
    u16 notify_vcpu_id;
    u32 port;
    union {
        struct {
            domid_t remote_domid;
        } unbound;
        struct {
            evtchn_port_t remote_port;
            struct domain *remote_dom;
        } interdomain;
        struct {
            u32 irq;
            evtchn_port_t next_port;
            evtchn_port_t prev_port;
        } pirq;
        u16 virq;
    } u;
    u8 priority;
    u8 last_priority;
    u16 last_vcpu_id;
# 136 "/var/xen-dev/xen/xen/include/xen/sched.h"
} __attribute__((aligned(64)));

int evtchn_init(struct domain *d, unsigned int max_port);
void evtchn_destroy(struct domain *d);
void evtchn_destroy_final(struct domain *d);

struct waitqueue_vcpu;

struct vcpu
{
    int vcpu_id;

    int processor;

    vcpu_info_t *vcpu_info;

    struct domain *domain;

    struct vcpu *next_in_list;

    spinlock_t periodic_timer_lock;
    s_time_t periodic_period;
    s_time_t periodic_last_event;
    struct timer periodic_timer;
    struct timer singleshot_timer;

    struct timer poll_timer;

    struct sched_unit *sched_unit;

    struct vcpu_runstate_info runstate;


    __guest_handle_vcpu_runstate_info_t runstate_guest;







    unsigned int new_state;


    _Bool fpu_initialised;

    _Bool fpu_dirtied;

    _Bool is_initialised;

    _Bool is_running;

    _Bool is_urgent;

    _Bool force_context_switch;



    struct {
        _Bool pending;
        uint8_t old_mask;
    } async_exception_state[2];

    uint8_t async_exception_mask;



    _Bool defer_shutdown;

    _Bool paused_for_shutdown;

    uint8_t affinity_broken;




    _Bool hcall_preempted;







    unsigned int dirty_cpu;






    int poll_evtchn;


    int pirq_evtchn_head;

    unsigned long pause_flags;
    atomic_t pause_count;


    atomic_t vm_event_pause_count;

    int controller_pause_count;


    spinlock_t maptrack_freelist_lock;
    unsigned int maptrack_head;
    unsigned int maptrack_tail;


    evtchn_port_t virq_to_evtchn[24];
    spinlock_t virq_lock;


    struct tasklet continue_hypercall_tasklet;


    struct mc_state mc_state;

    struct waitqueue_vcpu *waitqueue_vcpu;


    mfn_t vcpu_info_mfn;

    struct evtchn_fifo_vcpu *evtchn_fifo;


    struct vpci_vcpu vpci;

    struct arch_vcpu arch;
};

struct sched_unit {
    struct domain *domain;
    struct vcpu *vcpu_list;
    void *priv;
    struct sched_unit *next_in_list;
    struct sched_resource *res;
    unsigned int unit_id;


    _Bool is_running;

    _Bool soft_aff_effective;

    _Bool migrated;


    uint64_t state_entry_time;

    unsigned int runstate_cnt[4];


    cpumask_var_t cpu_hard_affinity;

    cpumask_var_t cpu_hard_affinity_saved;

    cpumask_var_t cpu_soft_affinity;


    struct sched_unit *next_task;
    s_time_t next_time;


    unsigned int rendezvous_in_cnt;


    atomic_t rendezvous_out_cnt;
};
# 325 "/var/xen-dev/xen/xen/include/xen/sched.h"
struct vm_event_domain
{
    spinlock_t lock;

    unsigned char foreign_producers;
    unsigned char target_producers;

    void *ring_page;
    struct page_info *ring_pg_struct;

    vm_event_front_ring_t front_ring;

    int xen_port;

    int pause_flag;

    struct waitqueue_head wq;

    unsigned int blocked;

    unsigned int last_vcpu_wake_up;
};

struct evtchn_port_ops;

struct domain
{
    domid_t domain_id;

    unsigned int max_vcpus;
    struct vcpu **vcpu;

    shared_info_t *shared_info;

    spinlock_t domain_lock;

    spinlock_t page_alloc_lock;
    struct page_list_head page_list;
    struct page_list_head xenpage_list;
    unsigned int tot_pages;
    unsigned int xenheap_pages;
    unsigned int outstanding_pages;
    unsigned int max_pages;
    atomic_t shr_pages;
    atomic_t paged_pages;


    void *sched_priv;
    struct sched_unit *sched_unit_list;
    struct cpupool *cpupool;

    struct domain *next_in_list;
    struct domain *next_in_hashbucket;

    struct list_head rangesets;
    spinlock_t rangesets_lock;


    struct evtchn *evtchn;
    struct evtchn **evtchn_group[((((((sizeof(xen_ulong_t) * sizeof(xen_ulong_t) * 64)) > ((1 << 17)) ? ((sizeof(xen_ulong_t) * sizeof(xen_ulong_t) * 64)) : ((1 << 17)))) + (((((1L) << 12)/sizeof(struct evtchn *)) * (((1L) << 12) / ((( ( ( ( ((sizeof(struct evtchn))-1) | ( ((sizeof(struct evtchn))-1) >> 1)) | ( ( ((sizeof(struct evtchn))-1) | ( ((sizeof(struct evtchn))-1) >> 1)) >> 2)) | ( ( ( ((sizeof(struct evtchn))-1) | ( ((sizeof(struct evtchn))-1) >> 1)) | ( ( ((sizeof(struct evtchn))-1) | ( ((sizeof(struct evtchn))-1) >> 1)) >> 2)) >> 4)) | ( ( ( ( ((sizeof(struct evtchn))-1) | ( ((sizeof(struct evtchn))-1) >> 1)) | ( ( ((sizeof(struct evtchn))-1) | ( ((sizeof(struct evtchn))-1) >> 1)) >> 2)) | ( ( ( ((sizeof(struct evtchn))-1) | ( ((sizeof(struct evtchn))-1) >> 1)) | ( ( ((sizeof(struct evtchn))-1) | ( ((sizeof(struct evtchn))-1) >> 1)) >> 2)) >> 4)) >> 8)) | (( ( ( ( ((sizeof(struct evtchn))-1) | ( ((sizeof(struct evtchn))-1) >> 1)) | ( ( ((sizeof(struct evtchn))-1) | ( ((sizeof(struct evtchn))-1) >> 1)) >> 2)) | ( ( ( ((sizeof(struct evtchn))-1) | ( ((sizeof(struct evtchn))-1) >> 1)) | ( ( ((sizeof(struct evtchn))-1) | ( ((sizeof(struct evtchn))-1) >> 1)) >> 2)) >> 4)) | ( ( ( ( ((sizeof(struct evtchn))-1) | ( ((sizeof(struct evtchn))-1) >> 1)) | ( ( ((sizeof(struct evtchn))-1) | ( ((sizeof(struct evtchn))-1) >> 1)) >> 2)) | ( ( ( ((sizeof(struct evtchn))-1) | ( ((sizeof(struct evtchn))-1) >> 1)) | ( ( ((sizeof(struct evtchn))-1) | ( ((sizeof(struct evtchn))-1) >> 1)) >> 2)) >> 4)) >> 8)) >>16)) + 1)))) - 1) / (((((1L) << 12)/sizeof(struct evtchn *)) * (((1L) << 12) / ((( ( ( ( ((sizeof(struct evtchn))-1) | ( ((sizeof(struct evtchn))-1) >> 1)) | ( ( ((sizeof(struct evtchn))-1) | ( ((sizeof(struct evtchn))-1) >> 1)) >> 2)) | ( ( ( ((sizeof(struct evtchn))-1) | ( ((sizeof(struct evtchn))-1) >> 1)) | ( ( ((sizeof(struct evtchn))-1) | ( ((sizeof(struct evtchn))-1) >> 1)) >> 2)) >> 4)) | ( ( ( ( ((sizeof(struct evtchn))-1) | ( ((sizeof(struct evtchn))-1) >> 1)) | ( ( ((sizeof(struct evtchn))-1) | ( ((sizeof(struct evtchn))-1) >> 1)) >> 2)) | ( ( ( ((sizeof(struct evtchn))-1) | ( ((sizeof(struct evtchn))-1) >> 1)) | ( ( ((sizeof(struct evtchn))-1) | ( ((sizeof(struct evtchn))-1) >> 1)) >> 2)) >> 4)) >> 8)) | (( ( ( ( ((sizeof(struct evtchn))-1) | ( ((sizeof(struct evtchn))-1) >> 1)) | ( ( ((sizeof(struct evtchn))-1) | ( ((sizeof(struct evtchn))-1) >> 1)) >> 2)) | ( ( ( ((sizeof(struct evtchn))-1) | ( ((sizeof(struct evtchn))-1) >> 1)) | ( ( ((sizeof(struct evtchn))-1) | ( ((sizeof(struct evtchn))-1) >> 1)) >> 2)) >> 4)) | ( ( ( ( ((sizeof(struct evtchn))-1) | ( ((sizeof(struct evtchn))-1) >> 1)) | ( ( ((sizeof(struct evtchn))-1) | ( ((sizeof(struct evtchn))-1) >> 1)) >> 2)) | ( ( ( ((sizeof(struct evtchn))-1) | ( ((sizeof(struct evtchn))-1) >> 1)) | ( ( ((sizeof(struct evtchn))-1) | ( ((sizeof(struct evtchn))-1) >> 1)) >> 2)) >> 4)) >> 8)) >>16)) + 1)))))];
    unsigned int max_evtchns;
    unsigned int max_evtchn_port;
    unsigned int valid_evtchns;
    spinlock_t event_lock;
    const struct evtchn_port_ops *evtchn_port_ops;
    struct evtchn_fifo_domain *evtchn_fifo;

    struct grant_table *grant_table;





    struct radix_tree_root pirq_tree;
    unsigned int nr_pirqs;

    unsigned int options;


    enum { DOMDYING_alive, DOMDYING_dying, DOMDYING_dead } is_dying;


    int controller_pause_count;

    int64_t time_offset_seconds;
# 419 "/var/xen-dev/xen/xen/include/xen/sched.h"
    _Bool auto_node_affinity;

    _Bool is_privileged;

    _Bool is_console;

    _Bool disable_migrate;

    _Bool debugger_attached;




    _Bool creation_finished;


    struct domain *target;



    unsigned long poll_mask[(((MAX_VIRT_CPUS)+BITS_PER_LONG-1)/BITS_PER_LONG)];





    struct rangeset *iomem_caps;
    struct rangeset *irq_caps;


    spinlock_t shutdown_lock;
    _Bool is_shutting_down;
    _Bool is_shut_down;

    unsigned int shutdown_code;



    evtchn_port_t suspend_evtchn;

    atomic_t pause_count;
    atomic_t refcnt;

    unsigned long vm_assist;


    cpumask_var_t dirty_cpumask;

    struct arch_domain arch;

    void *ssid;


    xen_domain_handle_t handle;



    char *pbuf;
    unsigned pbuf_idx;
    spinlock_t pbuf_lock;


    struct xenoprof *xenoprof;



    spinlock_t watchdog_lock;
    uint32_t watchdog_inuse_map;
    struct timer watchdog_timer[2];

    struct rcu_head rcu;





    spinlock_t hypercall_deadlock_mutex;

    struct lock_profile_qhead profile_head;
# 510 "/var/xen-dev/xen/xen/include/xen/sched.h"
    struct vm_event_domain *vm_event_monitor;





    nodemask_t node_affinity;
    unsigned int last_alloc_node;
    spinlock_t node_affinity_lock;


    rwlock_t vnuma_rwlock;
    struct vnuma_info *vnuma;


    struct {
        unsigned int guest_request_enabled : 1;
        unsigned int guest_request_sync : 1;
    } monitor;





};


extern spinlock_t domlist_update_lock;
extern rcu_read_lock_t domlist_read_lock;

extern struct vcpu *idle_vcpu[NR_CPUS];



static __inline__ _Bool is_system_domain(const struct domain *d)
{
    return d->domain_id >= 0x7FF0U;
}
# 557 "/var/xen-dev/xen/xen/include/xen/sched.h"
static __inline__ __attribute__ ((__always_inline__)) int get_domain(struct domain *d)
{
    int old, seen = atomic_read(&d->refcnt);
    do
    {
        old = seen;
        if ( __builtin_expect(!!(old & (1u << 31)),0) )
            return 0;
        seen = atomic_cmpxchg(&d->refcnt, old, old + 1);
    }
    while ( __builtin_expect(!!(seen != old),0) );
    return 1;
}





static __inline__ void get_knownalive_domain(struct domain *d)
{
    atomic_inc(&d->refcnt);
    do { if ( __builtin_expect(!!(!(!(atomic_read(&d->refcnt) & (1u << 31)))),0) ) do { do { ({ _Static_assert(!((578) >> ((31 - 24) + (31 - 24))), "!(" "(578) >> (BUG_LINE_LO_WIDTH + BUG_LINE_HI_WIDTH)" ")"); }); ({ _Static_assert(!((3) >= 4), "!(" "(3) >= BUGFRAME_NR" ")"); }); asm volatile ( ".Lbug%=: ud2\n" ".pushsection .bug_frames.%c[bf_type], \"a\", @progbits\n" ".p2align 2\n" ".Lfrm%=:\n" ".long (.Lbug%= - .Lfrm%=) + %c[bf_line_hi]\n" ".long (%c[bf_ptr] - .Lfrm%=) + %c[bf_line_lo]\n" ".if " "1" "\n" ".long 0, %c[bf_msg] - .Lfrm%=\n" ".endif\n" ".popsection\n" :: [bf_type] "i" (3), [bf_ptr] "i" ("/var/xen-dev/xen/xen/include/xen/sched.h"), [bf_msg] "i" ("!(atomic_read(&d->refcnt) & DOMAIN_DESTROYED)"), [bf_line_lo] "i" ((578 & ((1 << (31 - 24)) - 1)) << 24), [bf_line_hi] "i" (((578) >> (31 - 24)) << 24) ); } while (0); __builtin_unreachable(); } while (0); } while (0);
}

int domain_set_node_affinity(struct domain *d, const nodemask_t *affinity);
void domain_update_node_affinity(struct domain *d);





int arch_sanitise_domain_config(struct xen_domctl_createdomain *config);





struct domain *domain_create(domid_t domid,
                             struct xen_domctl_createdomain *config,
                             _Bool is_priv);
# 605 "/var/xen-dev/xen/xen/include/xen/sched.h"
struct domain *rcu_lock_domain_by_id(domid_t dom);




struct domain *rcu_lock_domain_by_any_id(domid_t dom);





int rcu_lock_remote_domain_by_id(domid_t dom, struct domain **d);





int rcu_lock_live_remote_domain_by_id(domid_t dom, struct domain **d);

static __inline__ void rcu_unlock_domain(struct domain *d)
{
    if ( d != ((get_cpu_info()->current_vcpu))->domain )
        ({ ((void)(d)); do { __asm__ __volatile__("": : :"memory"); ((*({ unsigned long __ptr; __asm__ ("" : "=r"(__ptr) : "0"(&per_cpu____preempt_count)); (typeof(&per_cpu____preempt_count)) (__ptr + (get_cpu_info()->per_cpu_offset)); })))--; } while (0); });
}

static __inline__ struct domain *rcu_lock_domain(struct domain *d)
{
    if ( d != ((get_cpu_info()->current_vcpu))->domain )
        ({ ((void)(d)); do { ((*({ unsigned long __ptr; __asm__ ("" : "=r"(__ptr) : "0"(&per_cpu____preempt_count)); (typeof(&per_cpu____preempt_count)) (__ptr + (get_cpu_info()->per_cpu_offset)); })))++; __asm__ __volatile__("": : :"memory"); } while (0); });
    return d;
}

static __inline__ struct domain *rcu_lock_current_domain(void)
{
    return (((get_cpu_info()->current_vcpu))->domain);
}

struct domain *get_domain_by_id(domid_t dom);

struct domain *get_pg_owner(domid_t domid);

static __inline__ void put_pg_owner(struct domain *pg_owner)
{
    rcu_unlock_domain(pg_owner);
}

void domain_destroy(struct domain *d);
int domain_kill(struct domain *d);
int domain_shutdown(struct domain *d, u8 reason);
void domain_resume(struct domain *d);
void domain_pause_for_debugger(void);

int domain_soft_reset(struct domain *d);

int vcpu_start_shutdown_deferral(struct vcpu *v);
void vcpu_end_shutdown_deferral(struct vcpu *v);






void __domain_crash(struct domain *d);
# 678 "/var/xen-dev/xen/xen/include/xen/sched.h"
void __attribute__((__noreturn__)) asm_domain_crash_synchronous(unsigned long addr);

void scheduler_init(void);
int sched_init_vcpu(struct vcpu *v);
void sched_destroy_vcpu(struct vcpu *v);
int sched_init_domain(struct domain *d, int poolid);
void sched_destroy_domain(struct domain *d);
int sched_move_domain(struct domain *d, struct cpupool *c);
long sched_adjust(struct domain *, struct xen_domctl_scheduler_op *);
long sched_adjust_global(struct xen_sysctl_scheduler_op *);
int sched_id(void);
void sched_tick_suspend(void);
void sched_tick_resume(void);
void vcpu_wake(struct vcpu *v);
long vcpu_yield(void);
void vcpu_sleep_nosync(struct vcpu *v);
void vcpu_sleep_sync(struct vcpu *v);






void sync_vcpu_execstate(struct vcpu *v);


void sync_local_execstate(void);
# 713 "/var/xen-dev/xen/xen/include/xen/sched.h"
void context_switch(
    struct vcpu *prev,
    struct vcpu *next);







void sched_context_switched(struct vcpu *prev, struct vcpu *vnext);


void continue_running(
    struct vcpu *same);

void startup_cpu_idle_loop(void);
extern void (*pm_idle) (void);
extern void (*dead_idle) (void);
# 743 "/var/xen-dev/xen/xen/include/xen/sched.h"
unsigned long hypercall_create_continuation(
    unsigned int op, const char *format, ...);

static __inline__ void hypercall_cancel_continuation(struct vcpu *v)
{
    v->hcall_preempted = 0;
}
# 771 "/var/xen-dev/xen/xen/include/xen/sched.h"
extern struct domain *domain_list;


static __inline__ struct domain *first_domain_in_cpupool( struct cpupool *c)
{
    struct domain *d;
    for (d = (domain_list); d && d->cpupool != c;
         d = (d->next_in_list));
    return d;
}
static __inline__ struct domain *next_domain_in_cpupool(
    struct domain *d, struct cpupool *c)
{
    for (d = (d->next_in_list); d && d->cpupool != c;
         d = (d->next_in_list));
    return d;
}
# 835 "/var/xen-dev/xen/xen/include/xen/sched.h"
static __inline__ _Bool vcpu_runnable(const struct vcpu *v)
{
    return !(v->pause_flags |
             atomic_read(&v->pause_count) |
             atomic_read(&v->domain->pause_count));
}

static __inline__ _Bool is_vcpu_dirty_cpu(unsigned int cpu)
{
    ({ _Static_assert(!(NR_CPUS >= (~0u)), "!(" "NR_CPUS >= VCPU_CPU_CLEAN" ")"); });
    return cpu != (~0u);
}

static __inline__ _Bool vcpu_cpu_dirty(const struct vcpu *v)
{
    return is_vcpu_dirty_cpu(v->dirty_cpu);
}

void vcpu_block(void);
void vcpu_unblock(struct vcpu *v);
void vcpu_pause(struct vcpu *v);
void vcpu_pause_nosync(struct vcpu *v);
void vcpu_unpause(struct vcpu *v);
int vcpu_pause_by_systemcontroller(struct vcpu *v);
int vcpu_unpause_by_systemcontroller(struct vcpu *v);

void domain_pause(struct domain *d);
void domain_pause_nosync(struct domain *d);
void domain_unpause(struct domain *d);
int domain_unpause_by_systemcontroller(struct domain *d);
int __domain_pause_by_systemcontroller(struct domain *d,
                                       void (*pause_fn)(struct domain *d));
static __inline__ int domain_pause_by_systemcontroller(struct domain *d)
{
    return __domain_pause_by_systemcontroller(d, domain_pause);
}
static __inline__ int domain_pause_by_systemcontroller_nosync(struct domain *d)
{
    return __domain_pause_by_systemcontroller(d, domain_pause_nosync);
}


int __attribute__((__warn_unused_result__)) domain_pause_except_self(struct domain *d);
void domain_unpause_except_self(struct domain *d);
# 897 "/var/xen-dev/xen/xen/include/xen/sched.h"
static __inline__ struct vcpu *domain_vcpu(const struct domain *d,
                                       unsigned int vcpu_id)
{
    unsigned int idx = ((void)(d->max_vcpus), (vcpu_id));

    return vcpu_id >= d->max_vcpus ? ((void*)0) : d->vcpu[idx];
}

void cpu_init(void);






extern __typeof__(atomic_t) per_cpu__sched_urgent_count;
static __inline__ _Bool sched_has_urgent_vcpu(void)
{
    return atomic_read(&(*({ unsigned long __ptr; __asm__ ("" : "=r"(__ptr) : "0"(&per_cpu__sched_urgent_count)); (typeof(&per_cpu__sched_urgent_count)) (__ptr + (get_cpu_info()->per_cpu_offset)); })));
}

struct scheduler;

struct scheduler *scheduler_get_default(void);
struct scheduler *scheduler_alloc(unsigned int sched_id, int *perr);
void scheduler_free(struct scheduler *sched);
int schedule_cpu_add(unsigned int cpu, struct cpupool *c);
int schedule_cpu_rm(unsigned int cpu);
void vcpu_set_periodic_timer(struct vcpu *v, s_time_t value);
int cpu_disable_scheduler(unsigned int cpu);
void sched_setup_dom0_vcpus(struct domain *d);
int vcpu_temporary_affinity(struct vcpu *v, unsigned int cpu, uint8_t reason);
int vcpu_set_hard_affinity(struct vcpu *v, const cpumask_t *affinity);
int vcpu_set_soft_affinity(struct vcpu *v, const cpumask_t *affinity);
void restore_vcpu_affinity(struct domain *d);

void vcpu_runstate_get(struct vcpu *v, struct vcpu_runstate_info *runstate);
uint64_t get_cpu_idle_time(unsigned int cpu);
void sched_guest_idle(void (*idle) (void), unsigned int cpu);
void scheduler_enable(void);
void scheduler_disable(void);
# 955 "/var/xen-dev/xen/xen/include/xen/sched.h"
void watchdog_domain_init(struct domain *d);
void watchdog_domain_destroy(struct domain *d);
# 971 "/var/xen-dev/xen/xen/include/xen/sched.h"
static __inline__ __attribute__ ((__always_inline__)) _Bool is_pv_domain(const struct domain *d)
{
    return IS_ENABLED(CONFIG_PV) &&
        evaluate_nospec(!(d->options & (1U<<0)));
}

static __inline__ __attribute__ ((__always_inline__)) _Bool is_pv_vcpu(const struct vcpu *v)
{
    return is_pv_domain(v->domain);
}
# 1003 "/var/xen-dev/xen/xen/include/xen/sched.h"
static __inline__ __attribute__ ((__always_inline__)) _Bool is_hvm_domain(const struct domain *d)
{
    return IS_ENABLED(CONFIG_HVM) &&
        evaluate_nospec(d->options & (1U<<0));
}

static __inline__ __attribute__ ((__always_inline__)) _Bool is_hvm_vcpu(const struct vcpu *v)
{
    return is_hvm_domain(v->domain);
}

static __inline__ __attribute__ ((__always_inline__)) _Bool hap_enabled(const struct domain *d)
{

    return IS_ENABLED(CONFIG_HVM) &&
        evaluate_nospec(d->options & (1U<<1));
}

static __inline__ _Bool is_hwdom_pinned_vcpu(const struct vcpu *v)
{
    return (evaluate_nospec((v->domain) == hardware_domain) &&
            cpumask_weight(v->sched_unit->cpu_hard_affinity) == 1);
}

static __inline__ _Bool is_vcpu_online(const struct vcpu *v)
{
    return !({ if ( (sizeof(*(&v->pause_flags)) < 4) ) __bitop_bad_size(); __builtin_constant_p(1) ? constant_test_bit(1, &v->pause_flags) : variable_test_bit(1, &v->pause_flags); });
}

static __inline__ _Bool is_xenstore_domain(const struct domain *d)
{
    return d->options & (1U<<4);
}

static __inline__ __attribute__ ((__always_inline__)) _Bool is_iommu_enabled(const struct domain *d)
{
    return evaluate_nospec(d->options & (1U<<5));
}

extern _Bool sched_smt_power_savings;
extern _Bool sched_disable_smt_switching;

extern enum cpufreq_controller {
    FREQCTL_none, FREQCTL_dom0_kernel, FREQCTL_xen
} cpufreq_controller;



struct cpupool *cpupool_get_by_id(int poolid);
void cpupool_put(struct cpupool *pool);
int cpupool_add_domain(struct domain *d, int poolid);
void cpupool_rm_domain(struct domain *d);
int cpupool_move_domain(struct domain *d, struct cpupool *c);
int cpupool_do_sysctl(struct xen_sysctl_cpupool_op *op);
void schedule_dump(struct cpupool *c);
extern void dump_runq(unsigned char key);

void arch_do_physinfo(struct xen_sysctl_physinfo *pi);
# 30 "/var/xen-dev/xen/xen/include/asm/paging.h" 2

# 1 "/var/xen-dev/xen/xen/include/xen/domain_page.h" 1
# 17 "/var/xen-dev/xen/xen/include/xen/domain_page.h"
void clear_domain_page(mfn_t mfn);
void copy_domain_page(mfn_t dst, const mfn_t src);
# 61 "/var/xen-dev/xen/xen/include/xen/domain_page.h"
static __inline__ void *map_domain_page_global(mfn_t mfn)
{
    return (__maddr_to_virt((unsigned long)((paddr_t)(mfn_x(mfn)) << 12)));
}

static __inline__ void *__map_domain_page_global(const struct page_info *pg)
{
    return __page_to_virt(pg);
}

static __inline__ void unmap_domain_page_global(const void *va) {};
# 32 "/var/xen-dev/xen/xen/include/asm/paging.h" 2
# 95 "/var/xen-dev/xen/xen/include/asm/paging.h"
struct sh_emulate_ctxt;
struct shadow_paging_mode {
# 115 "/var/xen-dev/xen/xen/include/asm/paging.h"
    unsigned int shadow_levels;
};





struct paging_mode {
    int (*page_fault )(struct vcpu *v, unsigned long va,
                                            struct cpu_user_regs *regs);
    _Bool (*invlpg )(struct vcpu *v,
                                            unsigned long linear);
    unsigned long (*gva_to_gfn )(struct vcpu *v,
                                            struct p2m_domain *p2m,
                                            unsigned long va,
                                            uint32_t *pfec);
    unsigned long (*p2m_ga_to_gfn )(struct vcpu *v,
                                            struct p2m_domain *p2m,
                                            unsigned long cr3,
                                            paddr_t ga, uint32_t *pfec,
                                            unsigned int *page_order);
    void (*update_cr3 )(struct vcpu *v, int do_locking,
                                            _Bool noflush);
    void (*update_paging_modes )(struct vcpu *v);
    int (*write_p2m_entry )(struct p2m_domain *p2m,
                                            unsigned long gfn,
                                            l1_pgentry_t *p, l1_pgentry_t new,
                                            unsigned int level);

    unsigned int guest_levels;


    struct shadow_paging_mode shadow;
};





void paging_log_dirty_range(struct domain *d,
                            unsigned long begin_pfn,
                            unsigned long nr,
                            uint8_t *dirty_bitmap);


int paging_log_dirty_enable(struct domain *d, _Bool log_global);


void paging_log_dirty_init(struct domain *d, const struct log_dirty_ops *ops);


void paging_mark_dirty(struct domain *d, mfn_t gmfn);

void paging_mark_pfn_dirty(struct domain *d, pfn_t pfn);



int paging_mfn_is_dirty(struct domain *d, mfn_t gmfn);
# 193 "/var/xen-dev/xen/xen/include/asm/paging.h"
struct sh_dirty_vram {
    unsigned long begin_pfn;
    unsigned long end_pfn;
    paddr_t *sl1ma;
    uint8_t *dirty_bitmap;
    s_time_t last_dirty;
};






void paging_vcpu_init(struct vcpu *v);



int paging_domain_init(struct domain *d);




int paging_domctl(struct domain *d, struct xen_domctl_shadow_op *sc,
                  __guest_handle_xen_domctl_t u_domctl,
                  bool_t resuming);


long paging_domctl_continuation(__guest_handle_xen_domctl_t);


int paging_teardown(struct domain *d);


void paging_final_teardown(struct domain *d);



int paging_enable(struct domain *d, u32 mode);



const struct paging_mode *paging_get_mode(struct vcpu *v);
void paging_update_nestedmode(struct vcpu *v);
# 246 "/var/xen-dev/xen/xen/include/asm/paging.h"
static __inline__ int
paging_fault(unsigned long va, struct cpu_user_regs *regs)
{
    struct vcpu *v = ((get_cpu_info()->current_vcpu));
    return ((v)->arch.paging.mode)->page_fault(v, va, regs);
}


void paging_invlpg(struct vcpu *v, unsigned long va);
# 267 "/var/xen-dev/xen/xen/include/asm/paging.h"
unsigned long paging_gva_to_gfn(struct vcpu *v,
                                unsigned long va,
                                uint32_t *pfec);
# 278 "/var/xen-dev/xen/xen/include/asm/paging.h"
static __inline__ unsigned long paging_ga_to_gfn_cr3(struct vcpu *v,
                                                 unsigned long cr3,
                                                 paddr_t ga,
                                                 uint32_t *pfec,
                                                 unsigned int *page_order)
{
    struct p2m_domain *p2m = v->domain->arch.p2m;
    return ((v)->arch.paging.mode)->p2m_ga_to_gfn(v, p2m, cr3, ga, pfec,
        page_order);
}




static __inline__ void paging_update_cr3(struct vcpu *v, _Bool noflush)
{
    ((v)->arch.paging.mode)->update_cr3(v, 1, noflush);
}




static __inline__ void paging_update_paging_modes(struct vcpu *v)
{
    ((v)->arch.paging.mode)->update_paging_modes(v);
}
# 345 "/var/xen-dev/xen/xen/include/asm/paging.h"
static __inline__ void safe_write_pte(l1_pgentry_t *p, l1_pgentry_t new)
{
    *p = new;
}







struct p2m_domain;

int paging_write_p2m_entry(struct p2m_domain *p2m, unsigned long gfn,
                           l1_pgentry_t *p, l1_pgentry_t new,
                           unsigned int level);





void pagetable_dying(paddr_t gpa);


void paging_dump_domain_info(struct domain *d);
void paging_dump_vcpu_info(struct vcpu *v);





int paging_set_allocation(struct domain *d, unsigned int pages,
                          _Bool *preempted);


static __inline__ _Bool gfn_valid(const struct domain *d, gfn_t gfn)
{
    return !(gfn_x(gfn) >> (d->arch.cpuid->extd.maxphysaddr - 12));
}


static __inline__ __attribute__ ((__always_inline__)) unsigned int paging_max_paddr_bits(const struct domain *d)
{
    unsigned int bits = (!!((d)->arch.paging.mode & 0)) ? hap_paddr_bits : paddr_bits;

    if ( !IS_ENABLED(CONFIG_BIGMEM) && (!!((d)->arch.paging.mode & 0)) &&
         !is_pv_domain(d) )
    {

        bits = ({ const typeof(bits) _x = (bits); const typeof(32U + 12) _y = (32U + 12); (void) (&_x == &_y); _x < _y ? _x : _y; });
    }

    return bits;
}
# 13 "/var/xen-dev/xen/xen/include/asm/hypercall.h" 2

typedef unsigned long hypercall_fn_t(
    unsigned long, unsigned long, unsigned long,
    unsigned long, unsigned long, unsigned long);

typedef struct {
    hypercall_fn_t *native, *compat;
} hypercall_table_t;

typedef struct {
    uint8_t native, compat;
} hypercall_args_t;

extern const hypercall_args_t hypercall_args_table[NR_hypercalls];






void pv_ring1_init_hypercall_page(void *ptr);
void pv_ring3_init_hypercall_page(void *ptr);
# 43 "/var/xen-dev/xen/xen/include/asm/hypercall.h"
extern long
do_event_channel_op_compat(
    __guest_handle_evtchn_op_t uop);


extern long do_physdev_op_compat(
    __guest_handle_physdev_op_t uop);


extern long do_sched_op_compat(
    int cmd, unsigned long arg);

extern long
do_set_trap_table(
    __guest_handle_const_trap_info_t traps);

extern long
do_mmu_update(
    __guest_handle_mmu_update_t ureqs,
    unsigned int count,
    __guest_handle_uint pdone,
    unsigned int foreigndom);

extern long
do_set_gdt(
    __guest_handle_xen_ulong_t frame_list,
    unsigned int entries);

extern long
do_stack_switch(
    unsigned long ss,
    unsigned long esp);

extern long
do_fpu_taskswitch(
    int set);

extern long
do_set_debugreg(
    int reg,
    unsigned long value);

extern unsigned long
do_get_debugreg(
    int reg);

extern long
do_update_descriptor(
    uint64_t gaddr, seg_desc_t desc);

extern long
do_mca(__guest_handle_xen_mc_t u_xen_mc);

extern long
do_update_va_mapping(
    unsigned long va,
    u64 val64,
    unsigned long flags);

extern long
do_physdev_op(
    int cmd, __guest_handle_void arg);

extern long
do_update_va_mapping_otherdomain(
    unsigned long va,
    u64 val64,
    unsigned long flags,
    domid_t domid);

extern long
do_mmuext_op(
    __guest_handle_mmuext_op_t uops,
    unsigned int count,
    __guest_handle_uint pdone,
    unsigned int foreigndom);

extern long do_callback_op(
    int cmd, __guest_handle_const_void arg);

extern unsigned long
do_iret(
    void);

extern long
do_set_callbacks(
    unsigned long event_address,
    unsigned long failsafe_address,
    unsigned long syscall_address);

extern long
do_set_segment_base(
    unsigned int which,
    unsigned long base);
# 19 "/var/xen-dev/xen/xen/include/xen/hypercall.h" 2
# 1 "/var/xen-dev/xen/xen/include/xsm/xsm.h" 1
# 19 "/var/xen-dev/xen/xen/include/xsm/xsm.h"
# 1 "/var/xen-dev/xen/xen/include/xen/multiboot.h" 1
# 20 "/var/xen-dev/xen/xen/include/xen/multiboot.h"
# 1 "/var/xen-dev/xen/xen/include/xen/const.h" 1
# 21 "/var/xen-dev/xen/xen/include/xen/multiboot.h" 2
# 49 "/var/xen-dev/xen/xen/include/xen/multiboot.h"
typedef struct {
    u32 tabsize;
    u32 strsize;
    u32 addr;
    u32 reserved;
} aout_symbol_table_t;


typedef struct {
    u32 num;
    u32 size;
    u32 addr;
    u32 shndx;
} elf_section_header_table_t;


typedef struct {
    u32 flags;


    u32 mem_lower;
    u32 mem_upper;


    u32 boot_device;


    u32 cmdline;


    u32 mods_count;
    u32 mods_addr;


    union {
        aout_symbol_table_t aout_sym;
        elf_section_header_table_t elf_sec;
    } u;


    u32 mmap_length;
    u32 mmap_addr;


    u32 drives_length;
    u32 drives_addr;


    u32 config_table;


    u32 boot_loader_name;


    u32 apm_table;
} multiboot_info_t;


typedef struct {
    u32 mod_start;
    u32 mod_end;
    u32 string;
    u32 reserved;
} module_t;



typedef struct {
    u32 size;
    u32 base_addr_low;
    u32 base_addr_high;
    u32 length_low;
    u32 length_high;
    u32 type;
} memory_map_t;
# 20 "/var/xen-dev/xen/xen/include/xsm/xsm.h" 2

typedef void xsm_op_t;
typedef xsm_op_t * __guest_handle_xsm_op_t; typedef const xsm_op_t * __guest_handle_const_xsm_op_t;


typedef u32 xsm_magic_t;
# 36 "/var/xen-dev/xen/xen/include/xsm/xsm.h"
enum xsm_default {
    XSM_HOOK,
    XSM_DM_PRIV,
    XSM_TARGET,
    XSM_PRIV,
    XSM_XS_PRIV,
    XSM_OTHER
};
typedef enum xsm_default xsm_default_t;

struct xsm_operations {
    void (*security_domaininfo) (struct domain *d,
                                        struct xen_domctl_getdomaininfo *info);
    int (*domain_create) (struct domain *d, u32 ssidref);
    int (*getdomaininfo) (struct domain *d);
    int (*domctl_scheduler_op) (struct domain *d, int op);
    int (*sysctl_scheduler_op) (int op);
    int (*set_target) (struct domain *d, struct domain *e);
    int (*domctl) (struct domain *d, int cmd);
    int (*sysctl) (int cmd);
    int (*readconsole) (uint32_t clear);

    int (*evtchn_unbound) (struct domain *d, struct evtchn *chn, domid_t id2);
    int (*evtchn_interdomain) (struct domain *d1, struct evtchn *chn1,
                                        struct domain *d2, struct evtchn *chn2);
    void (*evtchn_close_post) (struct evtchn *chn);
    int (*evtchn_send) (struct domain *d, struct evtchn *chn);
    int (*evtchn_status) (struct domain *d, struct evtchn *chn);
    int (*evtchn_reset) (struct domain *d1, struct domain *d2);

    int (*grant_mapref) (struct domain *d1, struct domain *d2, uint32_t flags);
    int (*grant_unmapref) (struct domain *d1, struct domain *d2);
    int (*grant_setup) (struct domain *d1, struct domain *d2);
    int (*grant_transfer) (struct domain *d1, struct domain *d2);
    int (*grant_copy) (struct domain *d1, struct domain *d2);
    int (*grant_query_size) (struct domain *d1, struct domain *d2);

    int (*alloc_security_domain) (struct domain *d);
    void (*free_security_domain) (struct domain *d);
    int (*alloc_security_evtchn) (struct evtchn *chn);
    void (*free_security_evtchn) (struct evtchn *chn);
    char *(*show_security_evtchn) (struct domain *d, const struct evtchn *chn);
    int (*init_hardware_domain) (struct domain *d);

    int (*get_pod_target) (struct domain *d);
    int (*set_pod_target) (struct domain *d);
    int (*memory_exchange) (struct domain *d);
    int (*memory_adjust_reservation) (struct domain *d1, struct domain *d2);
    int (*memory_stat_reservation) (struct domain *d1, struct domain *d2);
    int (*memory_pin_page) (struct domain *d1, struct domain *d2, struct page_info *page);
    int (*add_to_physmap) (struct domain *d1, struct domain *d2);
    int (*remove_from_physmap) (struct domain *d1, struct domain *d2);
    int (*map_gmfn_foreign) (struct domain *d, struct domain *t);
    int (*claim_pages) (struct domain *d);

    int (*console_io) (struct domain *d, int cmd);

    int (*profile) (struct domain *d, int op);

    int (*kexec) (void);
    int (*schedop_shutdown) (struct domain *d1, struct domain *d2);

    char *(*show_irq_sid) (int irq);
    int (*map_domain_pirq) (struct domain *d);
    int (*map_domain_irq) (struct domain *d, int irq, const void *data);
    int (*unmap_domain_pirq) (struct domain *d);
    int (*unmap_domain_irq) (struct domain *d, int irq, const void *data);
    int (*bind_pt_irq) (struct domain *d, struct xen_domctl_bind_pt_irq *bind);
    int (*unbind_pt_irq) (struct domain *d, struct xen_domctl_bind_pt_irq *bind);
    int (*irq_permission) (struct domain *d, int pirq, uint8_t allow);
    int (*iomem_permission) (struct domain *d, uint64_t s, uint64_t e, uint8_t allow);
    int (*iomem_mapping) (struct domain *d, uint64_t s, uint64_t e, uint8_t allow);
    int (*pci_config_permission) (struct domain *d, uint32_t machine_bdf, uint16_t start, uint16_t end, uint8_t access);
# 121 "/var/xen-dev/xen/xen/include/xsm/xsm.h"
    int (*resource_plug_core) (void);
    int (*resource_unplug_core) (void);
    int (*resource_plug_pci) (uint32_t machine_bdf);
    int (*resource_unplug_pci) (uint32_t machine_bdf);
    int (*resource_setup_pci) (uint32_t machine_bdf);
    int (*resource_setup_gsi) (int gsi);
    int (*resource_setup_misc) (void);

    int (*page_offline)(uint32_t cmd);

    long (*do_xsm_op) (__guest_handle_xsm_op_t op);




    int (*hvm_param) (struct domain *d, unsigned long op);
    int (*hvm_control) (struct domain *d, unsigned long op);
    int (*hvm_param_nested) (struct domain *d);
    int (*hvm_param_altp2mhvm) (struct domain *d);
    int (*hvm_altp2mhvm_op) (struct domain *d, uint64_t mode, uint32_t op);
    int (*get_vnumainfo) (struct domain *d);

    int (*vm_event_control) (struct domain *d, int mode, int op);
# 157 "/var/xen-dev/xen/xen/include/xsm/xsm.h"
    int (*platform_op) (uint32_t cmd);
# 181 "/var/xen-dev/xen/xen/include/xsm/xsm.h"
    int (*xen_version) (uint32_t cmd);
    int (*domain_resource_map) (struct domain *d);







};
# 774 "/var/xen-dev/xen/xen/include/xsm/xsm.h"
# 1 "/var/xen-dev/xen/xen/include/xsm/dummy.h" 1
# 19 "/var/xen-dev/xen/xen/include/xsm/dummy.h"
# 1 "/var/xen-dev/xen/xen/include/xsm/xsm.h" 1
# 20 "/var/xen-dev/xen/xen/include/xsm/dummy.h" 2
# 41 "/var/xen-dev/xen/xen/include/xsm/dummy.h"
void __xsm_action_mismatch_detected(void);
# 71 "/var/xen-dev/xen/xen/include/xsm/dummy.h"
static __inline__ __attribute__ ((__always_inline__)) int xsm_default_action(
    xsm_default_t action, struct domain *src, struct domain *target)
{
    switch ( action ) {
    case XSM_HOOK:
        return 0;
    case XSM_TARGET:
        if ( src == target )
        {
            return 0;
    case XSM_XS_PRIV:
            if ( is_xenstore_domain(src) )
                return 0;
        }

    case XSM_DM_PRIV:
        if ( target && src->target == target )
            return 0;

    case XSM_PRIV:
        if ( src->is_privileged )
            return 0;
        return -EPERM;
    default:
        do { if (1) __xsm_action_mismatch_detected(); } while (0);
        return -EPERM;
    }
}

static __inline__ __attribute__ ((__always_inline__)) void xsm_security_domaininfo(struct domain *d,
                                    struct xen_domctl_getdomaininfo *info)
{
    return;
}

static __inline__ __attribute__ ((__always_inline__)) int xsm_domain_create(xsm_default_t action, struct domain *d, u32 ssidref)
{
    do { if (XSM_HOOK != action) __xsm_action_mismatch_detected(); } while (0);
    return xsm_default_action(action, ((get_cpu_info()->current_vcpu))->domain, d);
}

static __inline__ __attribute__ ((__always_inline__)) int xsm_getdomaininfo(xsm_default_t action, struct domain *d)
{
    do { if (XSM_HOOK != action) __xsm_action_mismatch_detected(); } while (0);
    return xsm_default_action(action, ((get_cpu_info()->current_vcpu))->domain, d);
}

static __inline__ __attribute__ ((__always_inline__)) int xsm_domctl_scheduler_op(xsm_default_t action, struct domain *d, int cmd)
{
    do { if (XSM_HOOK != action) __xsm_action_mismatch_detected(); } while (0);
    return xsm_default_action(action, ((get_cpu_info()->current_vcpu))->domain, d);
}

static __inline__ __attribute__ ((__always_inline__)) int xsm_sysctl_scheduler_op(xsm_default_t action, int cmd)
{
    do { if (XSM_HOOK != action) __xsm_action_mismatch_detected(); } while (0);
    return xsm_default_action(action, ((get_cpu_info()->current_vcpu))->domain, ((void*)0));
}

static __inline__ __attribute__ ((__always_inline__)) int xsm_set_target(xsm_default_t action, struct domain *d, struct domain *e)
{
    do { if (XSM_HOOK != action) __xsm_action_mismatch_detected(); } while (0);
    return xsm_default_action(action, ((get_cpu_info()->current_vcpu))->domain, ((void*)0));
}

static __inline__ __attribute__ ((__always_inline__)) int xsm_domctl(xsm_default_t action, struct domain *d, int cmd)
{
    do { if (XSM_OTHER != action) __xsm_action_mismatch_detected(); } while (0);
    switch ( cmd )
    {
    case 40:
    case 39:
    case 38:
    case 48:
        return xsm_default_action(XSM_DM_PRIV, ((get_cpu_info()->current_vcpu))->domain, d);
    case 5:
        return xsm_default_action(XSM_XS_PRIV, ((get_cpu_info()->current_vcpu))->domain, d);
    default:
        return xsm_default_action(XSM_PRIV, ((get_cpu_info()->current_vcpu))->domain, d);
    }
}

static __inline__ __attribute__ ((__always_inline__)) int xsm_sysctl(xsm_default_t action, int cmd)
{
    do { if (XSM_PRIV != action) __xsm_action_mismatch_detected(); } while (0);
    return xsm_default_action(action, ((get_cpu_info()->current_vcpu))->domain, ((void*)0));
}

static __inline__ __attribute__ ((__always_inline__)) int xsm_readconsole(xsm_default_t action, uint32_t clear)
{
    do { if (XSM_HOOK != action) __xsm_action_mismatch_detected(); } while (0);
    return xsm_default_action(action, ((get_cpu_info()->current_vcpu))->domain, ((void*)0));
}

static __inline__ __attribute__ ((__always_inline__)) int xsm_alloc_security_domain(struct domain *d)
{
    return 0;
}

static __inline__ __attribute__ ((__always_inline__)) void xsm_free_security_domain(struct domain *d)
{
    return;
}

static __inline__ __attribute__ ((__always_inline__)) int xsm_grant_mapref(xsm_default_t action, struct domain *d1, struct domain *d2,
                                                                uint32_t flags)
{
    do { if (XSM_HOOK != action) __xsm_action_mismatch_detected(); } while (0);
    return xsm_default_action(action, d1, d2);
}

static __inline__ __attribute__ ((__always_inline__)) int xsm_grant_unmapref(xsm_default_t action, struct domain *d1, struct domain *d2)
{
    do { if (XSM_HOOK != action) __xsm_action_mismatch_detected(); } while (0);
    return xsm_default_action(action, d1, d2);
}

static __inline__ __attribute__ ((__always_inline__)) int xsm_grant_setup(xsm_default_t action, struct domain *d1, struct domain *d2)
{
    do { if (XSM_TARGET != action) __xsm_action_mismatch_detected(); } while (0);
    return xsm_default_action(action, d1, d2);
}

static __inline__ __attribute__ ((__always_inline__)) int xsm_grant_transfer(xsm_default_t action, struct domain *d1, struct domain *d2)
{
    do { if (XSM_HOOK != action) __xsm_action_mismatch_detected(); } while (0);
    return xsm_default_action(action, d1, d2);
}

static __inline__ __attribute__ ((__always_inline__)) int xsm_grant_copy(xsm_default_t action, struct domain *d1, struct domain *d2)
{
    do { if (XSM_HOOK != action) __xsm_action_mismatch_detected(); } while (0);
    return xsm_default_action(action, d1, d2);
}

static __inline__ __attribute__ ((__always_inline__)) int xsm_grant_query_size(xsm_default_t action, struct domain *d1, struct domain *d2)
{
    do { if (XSM_TARGET != action) __xsm_action_mismatch_detected(); } while (0);
    return xsm_default_action(action, d1, d2);
}

static __inline__ __attribute__ ((__always_inline__)) int xsm_memory_exchange(xsm_default_t action, struct domain *d)
{
    do { if (XSM_TARGET != action) __xsm_action_mismatch_detected(); } while (0);
    return xsm_default_action(action, ((get_cpu_info()->current_vcpu))->domain, d);
}

static __inline__ __attribute__ ((__always_inline__)) int xsm_memory_adjust_reservation(xsm_default_t action, struct domain *d1,
                                                            struct domain *d2)
{
    do { if (XSM_TARGET != action) __xsm_action_mismatch_detected(); } while (0);
    return xsm_default_action(action, d1, d2);
}

static __inline__ __attribute__ ((__always_inline__)) int xsm_memory_stat_reservation(xsm_default_t action, struct domain *d1, struct domain *d2)
{
    do { if (XSM_TARGET != action) __xsm_action_mismatch_detected(); } while (0);
    return xsm_default_action(action, d1, d2);
}

static __inline__ __attribute__ ((__always_inline__)) int xsm_console_io(xsm_default_t action, struct domain *d, int cmd)
{
    do { if (XSM_OTHER != action) __xsm_action_mismatch_detected(); } while (0);
    if ( d->is_console )
        return xsm_default_action(XSM_HOOK, d, ((void*)0));




    return xsm_default_action(XSM_PRIV, d, ((void*)0));
}

static __inline__ __attribute__ ((__always_inline__)) int xsm_profile(xsm_default_t action, struct domain *d, int op)
{
    do { if (XSM_HOOK != action) __xsm_action_mismatch_detected(); } while (0);
    return xsm_default_action(action, d, ((void*)0));
}

static __inline__ __attribute__ ((__always_inline__)) int xsm_kexec(xsm_default_t action)
{
    do { if (XSM_PRIV != action) __xsm_action_mismatch_detected(); } while (0);
    return xsm_default_action(action, ((get_cpu_info()->current_vcpu))->domain, ((void*)0));
}

static __inline__ __attribute__ ((__always_inline__)) int xsm_schedop_shutdown(xsm_default_t action, struct domain *d1, struct domain *d2)
{
    do { if (XSM_DM_PRIV != action) __xsm_action_mismatch_detected(); } while (0);
    return xsm_default_action(action, d1, d2);
}

static __inline__ __attribute__ ((__always_inline__)) int xsm_memory_pin_page(xsm_default_t action, struct domain *d1, struct domain *d2,
                                          struct page_info *page)
{
    do { if (XSM_HOOK != action) __xsm_action_mismatch_detected(); } while (0);
    return xsm_default_action(action, d1, d2);
}

static __inline__ __attribute__ ((__always_inline__)) int xsm_claim_pages(xsm_default_t action, struct domain *d)
{
    do { if (XSM_PRIV != action) __xsm_action_mismatch_detected(); } while (0);
    return xsm_default_action(action, ((get_cpu_info()->current_vcpu))->domain, d);
}

static __inline__ __attribute__ ((__always_inline__)) int xsm_evtchn_unbound(xsm_default_t action, struct domain *d, struct evtchn *chn,
                                         domid_t id2)
{
    do { if (XSM_TARGET != action) __xsm_action_mismatch_detected(); } while (0);
    return xsm_default_action(action, ((get_cpu_info()->current_vcpu))->domain, d);
}

static __inline__ __attribute__ ((__always_inline__)) int xsm_evtchn_interdomain(xsm_default_t action, struct domain *d1, struct evtchn
                                *chan1, struct domain *d2, struct evtchn *chan2)
{
    do { if (XSM_HOOK != action) __xsm_action_mismatch_detected(); } while (0);
    return xsm_default_action(action, d1, d2);
}

static __inline__ __attribute__ ((__always_inline__)) void xsm_evtchn_close_post(struct evtchn *chn)
{
    return;
}

static __inline__ __attribute__ ((__always_inline__)) int xsm_evtchn_send(xsm_default_t action, struct domain *d, struct evtchn *chn)
{
    do { if (XSM_HOOK != action) __xsm_action_mismatch_detected(); } while (0);
    return xsm_default_action(action, d, ((void*)0));
}

static __inline__ __attribute__ ((__always_inline__)) int xsm_evtchn_status(xsm_default_t action, struct domain *d, struct evtchn *chn)
{
    do { if (XSM_TARGET != action) __xsm_action_mismatch_detected(); } while (0);
    return xsm_default_action(action, ((get_cpu_info()->current_vcpu))->domain, d);
}

static __inline__ __attribute__ ((__always_inline__)) int xsm_evtchn_reset(xsm_default_t action, struct domain *d1, struct domain *d2)
{
    do { if (XSM_TARGET != action) __xsm_action_mismatch_detected(); } while (0);
    return xsm_default_action(action, d1, d2);
}

static __inline__ __attribute__ ((__always_inline__)) int xsm_alloc_security_evtchn(struct evtchn *chn)
{
    return 0;
}

static __inline__ __attribute__ ((__always_inline__)) void xsm_free_security_evtchn(struct evtchn *chn)
{
    return;
}

static __inline__ __attribute__ ((__always_inline__)) char *xsm_show_security_evtchn(struct domain *d, const struct evtchn *chn)
{
    return ((void*)0);
}

static __inline__ __attribute__ ((__always_inline__)) int xsm_init_hardware_domain(xsm_default_t action, struct domain *d)
{
    do { if (XSM_HOOK != action) __xsm_action_mismatch_detected(); } while (0);
    return xsm_default_action(action, ((get_cpu_info()->current_vcpu))->domain, d);
}

static __inline__ __attribute__ ((__always_inline__)) int xsm_get_pod_target(xsm_default_t action, struct domain *d)
{
    do { if (XSM_PRIV != action) __xsm_action_mismatch_detected(); } while (0);
    return xsm_default_action(action, ((get_cpu_info()->current_vcpu))->domain, d);
}

static __inline__ __attribute__ ((__always_inline__)) int xsm_set_pod_target(xsm_default_t action, struct domain *d)
{
    do { if (XSM_PRIV != action) __xsm_action_mismatch_detected(); } while (0);
    return xsm_default_action(action, ((get_cpu_info()->current_vcpu))->domain, d);
}

static __inline__ __attribute__ ((__always_inline__)) int xsm_get_vnumainfo(xsm_default_t action, struct domain *d)
{
    do { if (XSM_TARGET != action) __xsm_action_mismatch_detected(); } while (0);
    return xsm_default_action(action, ((get_cpu_info()->current_vcpu))->domain, d);
}
# 388 "/var/xen-dev/xen/xen/include/xsm/dummy.h"
static __inline__ __attribute__ ((__always_inline__)) int xsm_resource_plug_core(xsm_default_t action)
{
    do { if (XSM_HOOK != action) __xsm_action_mismatch_detected(); } while (0);
    return xsm_default_action(action, ((get_cpu_info()->current_vcpu))->domain, ((void*)0));
}

static __inline__ __attribute__ ((__always_inline__)) int xsm_resource_unplug_core(xsm_default_t action)
{
    do { if (XSM_HOOK != action) __xsm_action_mismatch_detected(); } while (0);
    return xsm_default_action(action, ((get_cpu_info()->current_vcpu))->domain, ((void*)0));
}

static __inline__ __attribute__ ((__always_inline__)) int xsm_resource_plug_pci(xsm_default_t action, uint32_t machine_bdf)
{
    do { if (XSM_PRIV != action) __xsm_action_mismatch_detected(); } while (0);
    return xsm_default_action(action, ((get_cpu_info()->current_vcpu))->domain, ((void*)0));
}

static __inline__ __attribute__ ((__always_inline__)) int xsm_resource_unplug_pci(xsm_default_t action, uint32_t machine_bdf)
{
    do { if (XSM_PRIV != action) __xsm_action_mismatch_detected(); } while (0);
    return xsm_default_action(action, ((get_cpu_info()->current_vcpu))->domain, ((void*)0));
}

static __inline__ __attribute__ ((__always_inline__)) int xsm_resource_setup_pci(xsm_default_t action, uint32_t machine_bdf)
{
    do { if (XSM_PRIV != action) __xsm_action_mismatch_detected(); } while (0);
    return xsm_default_action(action, ((get_cpu_info()->current_vcpu))->domain, ((void*)0));
}

static __inline__ __attribute__ ((__always_inline__)) int xsm_resource_setup_gsi(xsm_default_t action, int gsi)
{
    do { if (XSM_PRIV != action) __xsm_action_mismatch_detected(); } while (0);
    return xsm_default_action(action, ((get_cpu_info()->current_vcpu))->domain, ((void*)0));
}

static __inline__ __attribute__ ((__always_inline__)) int xsm_resource_setup_misc(xsm_default_t action)
{
    do { if (XSM_PRIV != action) __xsm_action_mismatch_detected(); } while (0);
    return xsm_default_action(action, ((get_cpu_info()->current_vcpu))->domain, ((void*)0));
}

static __inline__ __attribute__ ((__always_inline__)) int xsm_page_offline(xsm_default_t action, uint32_t cmd)
{
    do { if (XSM_HOOK != action) __xsm_action_mismatch_detected(); } while (0);
    return xsm_default_action(action, ((get_cpu_info()->current_vcpu))->domain, ((void*)0));
}

static __inline__ __attribute__ ((__always_inline__)) long xsm_do_xsm_op(__guest_handle_xsm_op_t op)
{
    return -ENOSYS;
}
# 448 "/var/xen-dev/xen/xen/include/xsm/dummy.h"
static __inline__ __attribute__ ((__always_inline__)) char *xsm_show_irq_sid(int irq)
{
    return ((void*)0);
}

static __inline__ __attribute__ ((__always_inline__)) int xsm_map_domain_pirq(xsm_default_t action, struct domain *d)
{
    do { if (XSM_DM_PRIV != action) __xsm_action_mismatch_detected(); } while (0);
    return xsm_default_action(action, ((get_cpu_info()->current_vcpu))->domain, d);
}

static __inline__ __attribute__ ((__always_inline__)) int xsm_map_domain_irq(xsm_default_t action, struct domain *d,
                                         int irq, const void *data)
{
    do { if (XSM_HOOK != action) __xsm_action_mismatch_detected(); } while (0);
    return xsm_default_action(action, ((get_cpu_info()->current_vcpu))->domain, d);
}

static __inline__ __attribute__ ((__always_inline__)) int xsm_unmap_domain_pirq(xsm_default_t action, struct domain *d)
{
    do { if (XSM_DM_PRIV != action) __xsm_action_mismatch_detected(); } while (0);
    return xsm_default_action(action, ((get_cpu_info()->current_vcpu))->domain, d);
}

static __inline__ __attribute__ ((__always_inline__)) int xsm_bind_pt_irq(xsm_default_t action, struct domain *d, struct xen_domctl_bind_pt_irq *bind)
{
    do { if (XSM_HOOK != action) __xsm_action_mismatch_detected(); } while (0);
    return xsm_default_action(action, ((get_cpu_info()->current_vcpu))->domain, d);
}

static __inline__ __attribute__ ((__always_inline__)) int xsm_unbind_pt_irq(xsm_default_t action, struct domain *d, struct xen_domctl_bind_pt_irq *bind)
{
    do { if (XSM_HOOK != action) __xsm_action_mismatch_detected(); } while (0);
    return xsm_default_action(action, ((get_cpu_info()->current_vcpu))->domain, d);
}

static __inline__ __attribute__ ((__always_inline__)) int xsm_unmap_domain_irq(xsm_default_t action, struct domain *d,
                                           int irq, const void *data)
{
    do { if (XSM_HOOK != action) __xsm_action_mismatch_detected(); } while (0);
    return xsm_default_action(action, ((get_cpu_info()->current_vcpu))->domain, d);
}

static __inline__ __attribute__ ((__always_inline__)) int xsm_irq_permission(xsm_default_t action, struct domain *d, int pirq, uint8_t allow)
{
    do { if (XSM_HOOK != action) __xsm_action_mismatch_detected(); } while (0);
    return xsm_default_action(action, ((get_cpu_info()->current_vcpu))->domain, d);
}

static __inline__ __attribute__ ((__always_inline__)) int xsm_iomem_permission(xsm_default_t action, struct domain *d, uint64_t s, uint64_t e, uint8_t allow)
{
    do { if (XSM_HOOK != action) __xsm_action_mismatch_detected(); } while (0);
    return xsm_default_action(action, ((get_cpu_info()->current_vcpu))->domain, d);
}

static __inline__ __attribute__ ((__always_inline__)) int xsm_iomem_mapping(xsm_default_t action, struct domain *d, uint64_t s, uint64_t e, uint8_t allow)
{
    do { if (XSM_HOOK != action) __xsm_action_mismatch_detected(); } while (0);
    return xsm_default_action(action, ((get_cpu_info()->current_vcpu))->domain, d);
}

static __inline__ __attribute__ ((__always_inline__)) int xsm_pci_config_permission(xsm_default_t action, struct domain *d, uint32_t machine_bdf,
                                        uint16_t start, uint16_t end,
                                        uint8_t access)
{
    do { if (XSM_HOOK != action) __xsm_action_mismatch_detected(); } while (0);
    return xsm_default_action(action, ((get_cpu_info()->current_vcpu))->domain, d);
}

static __inline__ __attribute__ ((__always_inline__)) int xsm_add_to_physmap(xsm_default_t action, struct domain *d1, struct domain *d2)
{
    do { if (XSM_TARGET != action) __xsm_action_mismatch_detected(); } while (0);
    return xsm_default_action(action, d1, d2);
}

static __inline__ __attribute__ ((__always_inline__)) int xsm_remove_from_physmap(xsm_default_t action, struct domain *d1, struct domain *d2)
{
    do { if (XSM_TARGET != action) __xsm_action_mismatch_detected(); } while (0);
    return xsm_default_action(action, d1, d2);
}

static __inline__ __attribute__ ((__always_inline__)) int xsm_map_gmfn_foreign(xsm_default_t action, struct domain *d, struct domain *t)
{
    do { if (XSM_TARGET != action) __xsm_action_mismatch_detected(); } while (0);
    return xsm_default_action(action, d, t);
}

static __inline__ __attribute__ ((__always_inline__)) int xsm_hvm_param(xsm_default_t action, struct domain *d, unsigned long op)
{
    do { if (XSM_TARGET != action) __xsm_action_mismatch_detected(); } while (0);
    return xsm_default_action(action, ((get_cpu_info()->current_vcpu))->domain, d);
}

static __inline__ __attribute__ ((__always_inline__)) int xsm_hvm_control(xsm_default_t action, struct domain *d, unsigned long op)
{
    do { if (XSM_DM_PRIV != action) __xsm_action_mismatch_detected(); } while (0);
    return xsm_default_action(action, ((get_cpu_info()->current_vcpu))->domain, d);
}

static __inline__ __attribute__ ((__always_inline__)) int xsm_hvm_param_nested(xsm_default_t action, struct domain *d)
{
    do { if (XSM_PRIV != action) __xsm_action_mismatch_detected(); } while (0);
    return xsm_default_action(action, ((get_cpu_info()->current_vcpu))->domain, d);
}

static __inline__ __attribute__ ((__always_inline__)) int xsm_hvm_param_altp2mhvm(xsm_default_t action, struct domain *d)
{
    do { if (XSM_PRIV != action) __xsm_action_mismatch_detected(); } while (0);
    return xsm_default_action(action, ((get_cpu_info()->current_vcpu))->domain, d);
}

static __inline__ __attribute__ ((__always_inline__)) int xsm_hvm_altp2mhvm_op(xsm_default_t action, struct domain *d, uint64_t mode, uint32_t op)
{
    do { if (XSM_OTHER != action) __xsm_action_mismatch_detected(); } while (0);

    switch ( mode )
    {
    case 1:
        return xsm_default_action(XSM_TARGET, ((get_cpu_info()->current_vcpu))->domain, d);
    case 2:
        return xsm_default_action(XSM_DM_PRIV, ((get_cpu_info()->current_vcpu))->domain, d);
    case 3:
        if ( 3 == op )
            return xsm_default_action(XSM_TARGET, ((get_cpu_info()->current_vcpu))->domain, d);
        return xsm_default_action(XSM_DM_PRIV, ((get_cpu_info()->current_vcpu))->domain, d);
    default:
        return -EPERM;
    }
}

static __inline__ __attribute__ ((__always_inline__)) int xsm_vm_event_control(xsm_default_t action, struct domain *d, int mode, int op)
{
    do { if (XSM_PRIV != action) __xsm_action_mismatch_detected(); } while (0);
    return xsm_default_action(action, ((get_cpu_info()->current_vcpu))->domain, d);
}
# 608 "/var/xen-dev/xen/xen/include/xsm/dummy.h"
static __inline__ __attribute__ ((__always_inline__)) int xsm_platform_op(xsm_default_t action, uint32_t op)
{
    do { if (XSM_PRIV != action) __xsm_action_mismatch_detected(); } while (0);
    return xsm_default_action(action, ((get_cpu_info()->current_vcpu))->domain, ((void*)0));
}
# 743 "/var/xen-dev/xen/xen/include/xsm/dummy.h"
static __inline__ __attribute__ ((__always_inline__)) int xsm_xen_version (xsm_default_t action, uint32_t op)
{
    do { if (XSM_OTHER != action) __xsm_action_mismatch_detected(); } while (0);
    switch ( op )
    {
    case 0:
    case 5:
    case 6:

        return 0;
    case 1:
    case 2:
    case 3:
    case 4:
    case 7:
    case 8:

        return xsm_default_action(XSM_HOOK, ((get_cpu_info()->current_vcpu))->domain, ((void*)0));
    default:
        return xsm_default_action(XSM_PRIV, ((get_cpu_info()->current_vcpu))->domain, ((void*)0));
    }
}

static __inline__ __attribute__ ((__always_inline__)) int xsm_domain_resource_map(xsm_default_t action, struct domain *d)
{
    do { if (XSM_DM_PRIV != action) __xsm_action_mismatch_detected(); } while (0);
    return xsm_default_action(action, ((get_cpu_info()->current_vcpu))->domain, d);
}
# 775 "/var/xen-dev/xen/xen/include/xsm/xsm.h" 2
# 20 "/var/xen-dev/xen/xen/include/xen/hypercall.h" 2

extern long
do_sched_op(
    int cmd,
    __guest_handle_void arg);

extern long
do_domctl(
    __guest_handle_xen_domctl_t u_domctl);

extern long
arch_do_domctl(
    struct xen_domctl *domctl, struct domain *d,
    __guest_handle_xen_domctl_t u_domctl);

extern long
do_sysctl(
    __guest_handle_xen_sysctl_t u_sysctl);

extern long
arch_do_sysctl(
    struct xen_sysctl *sysctl,
    __guest_handle_xen_sysctl_t u_sysctl);

extern long
do_platform_op(
    __guest_handle_xen_platform_op_t u_xenpf_op);
# 61 "/var/xen-dev/xen/xen/include/xen/hypercall.h"
extern long
do_memory_op(
    unsigned long cmd,
    __guest_handle_void arg);

extern long
do_multicall(
    __guest_handle_multicall_entry_t call_list,
    unsigned int nr_calls);

extern long
do_set_timer_op(
    s_time_t timeout);

extern long
do_event_channel_op(
    int cmd, __guest_handle_void arg);

extern long
do_xen_version(
    int cmd,
    __guest_handle_void arg);

extern long
do_console_io(
    unsigned int cmd,
    unsigned int count,
    __guest_handle_char buffer);

extern long
do_grant_table_op(
    unsigned int cmd,
    __guest_handle_void uop,
    unsigned int count);

extern long
do_vm_assist(
    unsigned int cmd,
    unsigned int type);

extern long
do_vcpu_op(
    int cmd,
    unsigned int vcpuid,
    __guest_handle_void arg);

struct vcpu;
extern long
arch_do_vcpu_op(int cmd,
    struct vcpu *v,
    __guest_handle_void arg);

extern long
do_nmi_op(
    unsigned int cmd,
    __guest_handle_void arg);

extern long
do_hvm_op(
    unsigned long op,
    __guest_handle_void arg);

extern long
do_kexec_op(
    unsigned long op,
    __guest_handle_void uarg);

extern long
do_xsm_op(
    __guest_handle_xsm_op_t u_xsm_op);
# 141 "/var/xen-dev/xen/xen/include/xen/hypercall.h"
extern long
do_xenoprof_op(int op, __guest_handle_void arg);

extern long
do_xenpmu_op(unsigned int op, __guest_handle_xen_pmu_params_t arg);

extern long
do_dm_op(
    domid_t domid,
    unsigned int nr_bufs,
    __guest_handle_xen_dm_op_buf_t bufs);
# 221 "/var/xen-dev/xen/xen/include/xen/hypercall.h"
void arch_get_xen_caps(xen_capabilities_info_t *info);
# 24 "hypercall.c" 2

# 1 "/var/xen-dev/xen/xen/include/xen/trace.h" 1
# 32 "/var/xen-dev/xen/xen/include/xen/trace.h"
# 1 "/var/xen-dev/xen/xen/include/public/trace.h" 1
# 33 "/var/xen-dev/xen/xen/include/xen/trace.h" 2
# 1 "/var/xen-dev/xen/xen/include/asm/trace.h" 1





void __trace_pv_trap(int trapnr, unsigned long eip,
                     int use_error_code, unsigned error_code);
static __inline__ void trace_pv_trap(int trapnr, unsigned long eip,
                                 int use_error_code, unsigned error_code)
{
    if ( __builtin_expect(!!(0),0) )
        __trace_pv_trap(trapnr, eip, use_error_code, error_code);
}

void __trace_pv_page_fault(unsigned long addr, unsigned error_code);
static __inline__ void trace_pv_page_fault(unsigned long addr,
                                       unsigned error_code)
{
    if ( __builtin_expect(!!(0),0) )
        __trace_pv_page_fault(addr, error_code);
}

void __trace_trap_one_addr(unsigned event, unsigned long va);
static __inline__ void trace_trap_one_addr(unsigned event, unsigned long va)
{
    if ( __builtin_expect(!!(0),0) )
        __trace_trap_one_addr(event, va);
}

void __trace_trap_two_addr(unsigned event, unsigned long va1,
                           unsigned long va2);
static __inline__ void trace_trap_two_addr(unsigned event, unsigned long va1,
                                       unsigned long va2)
{
    if ( __builtin_expect(!!(0),0) )
        __trace_trap_two_addr(event, va1, va2);
}

void __trace_ptwr_emulation(unsigned long addr, l1_pgentry_t npte);
static __inline__ void trace_ptwr_emulation(unsigned long addr, l1_pgentry_t npte)
{
    if ( __builtin_expect(!!(0),0) )
        __trace_ptwr_emulation(addr, npte);
}
# 34 "/var/xen-dev/xen/xen/include/xen/trace.h" 2
# 60 "/var/xen-dev/xen/xen/include/xen/trace.h"
static __inline__ void init_trace_bufs(void) {}
static __inline__ int tb_control(struct xen_sysctl_tbuf_op *tbc)
{
    return -ENOSYS;
}

static __inline__ int trace_will_trace_event(uint32_t event)
{
    return 0;
}

static __inline__ void trace_var(uint32_t event, _Bool cycles, unsigned int extra,
                             const void *extra_data) {}
static __inline__ void __trace_var(uint32_t event, _Bool cycles, unsigned int extra,
                               const void *extra_data) {}
static __inline__ void __trace_hypercall(uint32_t event, unsigned long op,
                                     const xen_ulong_t *args) {}
# 26 "hypercall.c" 2
# 36 "hypercall.c"
const hypercall_table_t pv_hypercall_table[] = {
    [ 0 ] = { (hypercall_fn_t *) do_set_trap_table, (hypercall_fn_t *) compat_set_trap_table },
    [ 1 ] = { (hypercall_fn_t *) do_mmu_update, (hypercall_fn_t *) do_mmu_update },
    [ 2 ] = { (hypercall_fn_t *) do_set_gdt, (hypercall_fn_t *) compat_set_gdt },
    [ 3 ] = { (hypercall_fn_t *) do_stack_switch, (hypercall_fn_t *) do_stack_switch },
    [ 4 ] = { (hypercall_fn_t *) do_set_callbacks, (hypercall_fn_t *) compat_set_callbacks },
    [ 5 ] = { (hypercall_fn_t *) do_fpu_taskswitch, (hypercall_fn_t *) do_fpu_taskswitch },
    [ 6 ] = { (hypercall_fn_t *) do_sched_op_compat, (hypercall_fn_t *) do_sched_op_compat },
    [ 7 ] = { (hypercall_fn_t *) do_platform_op, (hypercall_fn_t *) compat_platform_op },
    [ 8 ] = { (hypercall_fn_t *) do_set_debugreg, (hypercall_fn_t *) do_set_debugreg },
    [ 9 ] = { (hypercall_fn_t *) do_get_debugreg, (hypercall_fn_t *) do_get_debugreg },
    [ 10 ] = { (hypercall_fn_t *) do_update_descriptor, (hypercall_fn_t *) compat_update_descriptor },
    [ 12 ] = { (hypercall_fn_t *) do_memory_op, (hypercall_fn_t *) compat_memory_op },
    [ 13 ] = { (hypercall_fn_t *) do_multicall, (hypercall_fn_t *) compat_multicall },
    [ 14 ] = { (hypercall_fn_t *) do_update_va_mapping, (hypercall_fn_t *) compat_update_va_mapping },
    [ 15 ] = { (hypercall_fn_t *) do_set_timer_op, (hypercall_fn_t *) compat_set_timer_op },
    [ 16 ] = { (hypercall_fn_t *) do_event_channel_op_compat, (hypercall_fn_t *) do_event_channel_op_compat },
    [ 17 ] = { (hypercall_fn_t *) do_xen_version, (hypercall_fn_t *) compat_xen_version },
    [ 18 ] = { (hypercall_fn_t *) do_console_io, (hypercall_fn_t *) do_console_io },
    [ 19 ] = { (hypercall_fn_t *) do_physdev_op_compat, (hypercall_fn_t *) compat_physdev_op_compat },



    [ 21 ] = { (hypercall_fn_t *) do_vm_assist, (hypercall_fn_t *) compat_vm_assist },
    [ 22 ] = { (hypercall_fn_t *) do_update_va_mapping_otherdomain, (hypercall_fn_t *) compat_update_va_mapping_otherdomain },
    [ 23 ] = { (hypercall_fn_t *) do_iret, (hypercall_fn_t *) compat_iret },
    [ 24 ] = { (hypercall_fn_t *) do_vcpu_op, (hypercall_fn_t *) compat_vcpu_op },
    [ 25 ] = { (hypercall_fn_t *) do_set_segment_base, (hypercall_fn_t *) do_set_segment_base },
    [ 26 ] = { (hypercall_fn_t *) do_mmuext_op, (hypercall_fn_t *) compat_mmuext_op },
    [ 27 ] = { (hypercall_fn_t *) do_xsm_op, (hypercall_fn_t *) compat_xsm_op },
    [ 28 ] = { (hypercall_fn_t *) do_nmi_op, (hypercall_fn_t *) compat_nmi_op },
    [ 6 ] = { (hypercall_fn_t *) do_sched_op, (hypercall_fn_t *) compat_sched_op },
    [ 30 ] = { (hypercall_fn_t *) do_callback_op, (hypercall_fn_t *) compat_callback_op },



    [ 16 ] = { (hypercall_fn_t *) do_event_channel_op, (hypercall_fn_t *) do_event_channel_op },
    [ 19 ] = { (hypercall_fn_t *) do_physdev_op, (hypercall_fn_t *) compat_physdev_op },
    [ 35 ] = { (hypercall_fn_t *) do_sysctl, (hypercall_fn_t *) do_sysctl },
    [ 36 ] = { (hypercall_fn_t *) do_domctl, (hypercall_fn_t *) do_domctl },






    [ 40 ] = { (hypercall_fn_t *) do_xenpmu_op, (hypercall_fn_t *) do_xenpmu_op },




    [ 48 ] = { (hypercall_fn_t *) do_mca, (hypercall_fn_t *) do_mca },
    [ 49 ] = { (hypercall_fn_t *) paging_domctl_continuation, (hypercall_fn_t *) paging_domctl_continuation },
};





void pv_hypercall(struct cpu_user_regs *regs)
{
    struct vcpu *curr = ((get_cpu_info()->current_vcpu));
    unsigned long eax;

    do { if ( __builtin_expect(!!(!((!is_pv_32bit_vcpu(curr) ? ((((regs)->cs & 3) == 3) && ((curr)->arch.flags & (1<<0))) : ((((regs)->cs & 3) == 1))))),0) ) do { do { ({ _Static_assert(!((100) >> ((31 - 24) + (31 - 24))), "!(" "(100) >> (BUG_LINE_LO_WIDTH + BUG_LINE_HI_WIDTH)" ")"); }); ({ _Static_assert(!((3) >= 4), "!(" "(3) >= BUGFRAME_NR" ")"); }); asm volatile ( ".Lbug%=: ud2\n" ".pushsection .bug_frames.%c[bf_type], \"a\", @progbits\n" ".p2align 2\n" ".Lfrm%=:\n" ".long (.Lbug%= - .Lfrm%=) + %c[bf_line_hi]\n" ".long (%c[bf_ptr] - .Lfrm%=) + %c[bf_line_lo]\n" ".if " "1" "\n" ".long 0, %c[bf_msg] - .Lfrm%=\n" ".endif\n" ".popsection\n" :: [bf_type] "i" (3), [bf_ptr] "i" ("hypercall.c"), [bf_msg] "i" ("guest_kernel_mode(curr, regs)"), [bf_line_lo] "i" ((100 & ((1 << (31 - 24)) - 1)) << 24), [bf_line_hi] "i" (((100) >> (31 - 24)) << 24) ); } while (0); __builtin_unreachable(); } while (0); } while (0);

    eax = is_pv_32bit_vcpu(curr) ? regs->eax : regs->rax;

    ({ _Static_assert(!((sizeof(pv_hypercall_table) / sizeof((pv_hypercall_table)[0]) + sizeof(struct { _Static_assert(!(__builtin_types_compatible_p(typeof(pv_hypercall_table), typeof(&pv_hypercall_table[0]))), "!(" "__builtin_types_compatible_p(typeof(pv_hypercall_table), typeof(&pv_hypercall_table[0]))" ")"); })) > (sizeof(hypercall_args_table) / sizeof((hypercall_args_table)[0]) + sizeof(struct { _Static_assert(!(__builtin_types_compatible_p(typeof(hypercall_args_table), typeof(&hypercall_args_table[0]))), "!(" "__builtin_types_compatible_p(typeof(hypercall_args_table), typeof(&hypercall_args_table[0]))" ")"); }))), "!(" "ARRAY_SIZE(pv_hypercall_table) > ARRAY_SIZE(hypercall_args_table)" ")"); })
                                                  ;

    if ( eax >= (sizeof(pv_hypercall_table) / sizeof((pv_hypercall_table)[0]) + sizeof(struct { _Static_assert(!(__builtin_types_compatible_p(typeof(pv_hypercall_table), typeof(&pv_hypercall_table[0]))), "!(" "__builtin_types_compatible_p(typeof(pv_hypercall_table), typeof(&pv_hypercall_table[0]))" ")"); })) )
    {
        regs->rax = -ENOSYS;
        return;
    }

    eax = ((void)((sizeof(pv_hypercall_table) / sizeof((pv_hypercall_table)[0]) + sizeof(struct { _Static_assert(!(__builtin_types_compatible_p(typeof(pv_hypercall_table), typeof(&pv_hypercall_table[0]))), "!(" "__builtin_types_compatible_p(typeof(pv_hypercall_table), typeof(&pv_hypercall_table[0]))" ")"); }))), (eax));

    if ( !pv_hypercall_table[eax].native )
    {
        regs->rax = -ENOSYS;
        return;
    }

    curr->hcall_preempted = 0;

    if ( !is_pv_32bit_vcpu(curr) )
    {
        unsigned long rdi = regs->rdi;
        unsigned long rsi = regs->rsi;
        unsigned long rdx = regs->rdx;
        unsigned long r10 = regs->r10;
        unsigned long r8 = regs->r8;
        unsigned long r9 = regs->r9;



        switch ( hypercall_args_table[eax].native )
        {
        case 0: rdi = 0xdeadbeefdeadf00dUL;
        case 1: rsi = 0xdeadbeefdeadf00dUL;
        case 2: rdx = 0xdeadbeefdeadf00dUL;
        case 3: r10 = 0xdeadbeefdeadf00dUL;
        case 4: r8 = 0xdeadbeefdeadf00dUL;
        case 5: r9 = 0xdeadbeefdeadf00dUL;
        }

        if ( __builtin_expect(!!(0),0) )
        {
            unsigned long args[6] = { rdi, rsi, rdx, r10, r8, r9 };

            __trace_hypercall((0x00201000 + 13), eax, args);
        }

        regs->rax = pv_hypercall_table[eax].native(rdi, rsi, rdx, r10, r8, r9);


        if ( !curr->hcall_preempted )
        {

            switch ( hypercall_args_table[eax].native )
            {
            case 6: regs->r9 = 0xdeadbeefdeadf00dUL;
            case 5: regs->r8 = 0xdeadbeefdeadf00dUL;
            case 4: regs->r10 = 0xdeadbeefdeadf00dUL;
            case 3: regs->rdx = 0xdeadbeefdeadf00dUL;
            case 2: regs->rsi = 0xdeadbeefdeadf00dUL;
            case 1: regs->rdi = 0xdeadbeefdeadf00dUL;
            }
        }

    }
    else
    {
        unsigned int ebx = regs->ebx;
        unsigned int ecx = regs->ecx;
        unsigned int edx = regs->edx;
        unsigned int esi = regs->esi;
        unsigned int edi = regs->edi;
        unsigned int ebp = regs->ebp;



        switch ( hypercall_args_table[eax].compat )
        {
        case 0: ebx = 0xdeadf00d;
        case 1: ecx = 0xdeadf00d;
        case 2: edx = 0xdeadf00d;
        case 3: esi = 0xdeadf00d;
        case 4: edi = 0xdeadf00d;
        case 5: ebp = 0xdeadf00d;
        }


        if ( __builtin_expect(!!(0),0) )
        {
            unsigned long args[6] = { ebx, ecx, edx, esi, edi, ebp };

            __trace_hypercall((0x00201000 + 13), eax, args);
        }

        curr->hcall_compat = 1;
        regs->eax = pv_hypercall_table[eax].compat(ebx, ecx, edx, esi, edi, ebp);
        curr->hcall_compat = 0;


        if ( !curr->hcall_preempted )
        {

            switch ( hypercall_args_table[eax].compat )
            {
            case 6: regs->ebp = 0xdeadf00d;
            case 5: regs->edi = 0xdeadf00d;
            case 4: regs->esi = 0xdeadf00d;
            case 3: regs->edx = 0xdeadf00d;
            case 2: regs->ecx = 0xdeadf00d;
            case 1: regs->ebx = 0xdeadf00d;
            }
        }

    }






    if ( curr->hcall_preempted )
        regs->rip -= 2;

    ((void)0);
}

enum mc_disposition arch_do_multicall_call(struct mc_state *state)
{
    struct vcpu *curr = ((get_cpu_info()->current_vcpu));
    unsigned long op;

    if ( !is_pv_32bit_vcpu(curr) )
    {
        struct multicall_entry *call = &state->call;

        op = call->op;
        if ( (op < (sizeof(pv_hypercall_table) / sizeof((pv_hypercall_table)[0]) + sizeof(struct { _Static_assert(!(__builtin_types_compatible_p(typeof(pv_hypercall_table), typeof(&pv_hypercall_table[0]))), "!(" "__builtin_types_compatible_p(typeof(pv_hypercall_table), typeof(&pv_hypercall_table[0]))" ")"); }))) &&
             pv_hypercall_table[op].native )
            call->result = pv_hypercall_table[op].native(
                call->args[0], call->args[1], call->args[2],
                call->args[3], call->args[4], call->args[5]);
        else
            call->result = -ENOSYS;
    }
# 264 "hypercall.c"
    return __builtin_expect(!!(op == 23),0)
           ? mc_exit
           : __builtin_expect(!!((!is_pv_32bit_vcpu(curr) ? (((((&get_cpu_info()->guest_cpu_user_regs))->cs & 3) == 3) && ((curr)->arch.flags & (1<<0))) : (((((&get_cpu_info()->guest_cpu_user_regs))->cs & 3) == 1)))),1)
             ? mc_continue : mc_preempt;
}

void pv_ring3_init_hypercall_page(void *p)
{
    unsigned int i;

    for ( i = 0; i < (((1L) << 12) / 32); i++, p += 32 )
    {
        if ( __builtin_expect(!!(i == 23),0) )
        {





            *(u8 *)(p+ 0) = 0x51;
            *(u16 *)(p+ 1) = 0x5341;
            *(u8 *)(p+ 3) = 0x50;
            *(u8 *)(p+ 4) = 0xb8;
            *(u32 *)(p+ 5) = 23;
            *(u16 *)(p+ 9) = 0x050f;

            continue;
        }

        *(u8 *)(p+ 0) = 0x51;
        *(u16 *)(p+ 1) = 0x5341;
        *(u8 *)(p+ 3) = 0xb8;
        *(u32 *)(p+ 4) = i;
        *(u16 *)(p+ 8) = 0x050f;
        *(u16 *)(p+10) = 0x5b41;
        *(u8 *)(p+12) = 0x59;
        *(u8 *)(p+13) = 0xc3;
    }
}

void pv_ring1_init_hypercall_page(void *p)
{
    unsigned int i;

    for ( i = 0; i < (((1L) << 12) / 32); i++, p += 32 )
    {
        if ( __builtin_expect(!!(i == 23),0) )
        {





            *(u8 *)(p+ 0) = 0x50;
            *(u8 *)(p+ 1) = 0xb8;
            *(u32 *)(p+ 2) = 23;
            *(u16 *)(p+ 6) = (0x82 << 8) | 0xcd;

            continue;
        }

        *(u8 *)(p+ 0) = 0xb8;
        *(u32 *)(p+ 1) = i;
        *(u16 *)(p+ 5) = (0x82 << 8) | 0xcd;
        *(u8 *)(p+ 7) = 0xc3;
    }
}
