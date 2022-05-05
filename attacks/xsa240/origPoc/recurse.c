#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/types.h>
#include <asm/xen/page.h>
#include <asm/xen/hypercall.h>

static int init_test(void) {
	int i;
	u64 *last_pt = NULL;
	u32 done;

	for (i = 0; i < 1000; i++) {
		u64 *new_pt = (void*)__get_free_pages(GFP_KERNEL, 0);
		struct mmuext_op pin_new_pt_op = {
			.cmd = MMUEXT_PIN_L4_TABLE,
			.arg1.mfn = virt_to_mfn(new_pt)
		};
		memset(new_pt, 0, 4096);
		if (HYPERVISOR_update_va_mapping((u64)new_pt, __pte(0x5 | virt_to_machine(new_pt).maddr), 0)) {
			pr_warn("update_va_mapping\n");
			return -EINVAL;
		}
		if (HYPERVISOR_mmuext_op(&pin_new_pt_op, 1, &done, DOMID_SELF)) {
			pr_warn("mmuext_op\n");
			return -EINVAL;
		}

		if (last_pt != NULL) {
			struct mmu_update pt_link_mmu_update = {
				.ptr = virt_to_machine(new_pt).maddr,
				.val = 0x5 | virt_to_machine(last_pt).maddr
			};
			struct mmuext_op unpin_op = {
				.cmd = MMUEXT_UNPIN_TABLE,
				.arg1.mfn = virt_to_mfn(last_pt)
			};
			if (HYPERVISOR_mmu_update(&pt_link_mmu_update, 1, &done, DOMID_SELF)) {
				pr_warn("mmu_update\n");
				return -EINVAL;
			}
			if (HYPERVISOR_mmuext_op(&unpin_op, 1, &done, DOMID_SELF)) {
				pr_warn("unpin\n");
				return -EINVAL;
			}
		}
		last_pt = new_pt;
	}

	{
		struct mmuext_op last_unpin_op = {
			.cmd = MMUEXT_UNPIN_TABLE,
			.arg1.mfn = virt_to_mfn(last_pt)
		};
		if (HYPERVISOR_mmuext_op(&last_unpin_op, 1, &done, DOMID_SELF)) {
			pr_warn("unpin last\n");
			return -EINVAL;
		}
	}

	return 0;
}

module_init(init_test);
MODULE_LICENSE("GPL v2");

