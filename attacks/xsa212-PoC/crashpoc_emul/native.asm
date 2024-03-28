global call_xen_memory_op
global read_idt_addr
global call_xen_update_va_mapping

call_xen_memory_op:
; no need to move around registers for the first two arguments (only arg4 is weird)
mov eax, 12 ; __HYPERVISOR_memory_op
syscall
ret

call_xen_update_va_mapping:
mov eax, 14 ; __HYPERVISOR_update_va_mapping
syscall
ret

read_idt_addr:
sub rsp, 10
mov qword [rsp+2], 0
sidt [rsp]
mov rax, [rsp+2]
add rsp, 10
ret

