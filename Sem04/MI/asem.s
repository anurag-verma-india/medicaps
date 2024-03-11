.global _start
.intel_syntax noprefix

_start:
	// sys_write
	mov rax, 1
	// for read sys_call
	mov rdi, 1
	lea rsi, [hello_world]
	mov rdx, 14
	syscall

	// sys_exit
	mov rax, 60 
	// rax for system call
	mov rdi, 69
	syscall

hello_world:
	.asciz "\nThis is it!\n\n"
