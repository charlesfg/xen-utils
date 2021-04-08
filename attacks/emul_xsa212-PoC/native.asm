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
sub rsp, 10             ; allocate 10 bytes on the stack
mov qword [rsp+2], 0    ; clear the memory in the stack for the 8 bytes
sidt [rsp]              ; write the 6-byte IDT register to rsp
mov rax, [rsp+2]        ; copy the value of the to rax
add rsp, 10
ret

