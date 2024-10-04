global call_int_85
global backstop_85_handler

call_int_85:
int 0x85
ret

backstop_85_handler:
pop rax

; rax for userspace is passed to iret syscall on stack
mov rax, 0x7331
push rax

; r11 and rcx are also restored from the stack; their values don't matter
push rax
push rax

; iret via hypercall
mov rax, 23 ; __HYPERVISOR_iret
syscall

