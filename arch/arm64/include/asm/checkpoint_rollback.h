#ifndef _ASM_ARM64_CHECKPOINT_ROLLBACK_H
#define _ASM_ARM64_CHECKPOINT_ROLLBACK_H

#include <linux/kvm.h>
#include <asm/kvm.h>

struct kvm_vcpu;


typedef struct CPUARMState {

	/* standard registers */
	struct kvm_regs kvm_regs;

	/* FPU state */
	struct kvm_mp_state mp_state;

	/* Debug registers */
	struct kvm_guest_debug_arch dbgregs;

	struct kvm_debug_exit_arch dbgexitregs;

	/* segments */
	struct kvm_vcpu_events vcpu_events;

} CPUARMState;

int rr_do_vcpu_checkpoint(struct kvm_vcpu *vcpu);

int rr_do_vcpu_rollback(struct kvm_vcpu *vcpu);

#endif

