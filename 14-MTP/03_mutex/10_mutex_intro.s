	.file	"10_mutex_intro.c"
	.text
	.globl	global_var
	.bss
	.align 4
	.type	global_var, @object
	.size	global_var, 4
global_var:
	.zero	4
	.comm	lock,40,32
	.section	.rodata
.LC0:
	.string	"Inside my_thread function"
	.text
	.globl	my_thread
	.type	my_thread, @function
my_thread:
.LFB0:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -24(%rbp)
	leaq	.LC0(%rip), %rdi
	call	puts@PLT
	movl	$0, -4(%rbp)
	jmp	.L2
.L3:
	leaq	lock(%rip), %rdi
	call	pthread_mutex_lock@PLT
	movl	global_var(%rip), %eax
	addl	$1, %eax
	movl	%eax, global_var(%rip)
	leaq	lock(%rip), %rdi
	call	pthread_mutex_unlock@PLT
	addl	$1, -4(%rbp)
.L2:
	cmpl	$999999, -4(%rbp)
	jle	.L3
	movl	$0, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	my_thread, .-my_thread
	.section	.rodata
.LC1:
	.string	"Creating thread %d\n"
.LC2:
	.string	"pthread_create failed"
	.align 8
.LC3:
	.string	"Final value of global_var: %d\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB1:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$48, %rsp
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movl	$0, %esi
	leaq	lock(%rip), %rdi
	call	pthread_mutex_init@PLT
	movl	$0, -40(%rbp)
	jmp	.L6
.L9:
	movl	-40(%rbp), %eax
	movl	%eax, %esi
	leaq	.LC1(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	leaq	-32(%rbp), %rax
	movl	-40(%rbp), %edx
	movslq	%edx, %rdx
	salq	$3, %rdx
	addq	%rdx, %rax
	movl	$0, %ecx
	leaq	my_thread(%rip), %rdx
	movl	$0, %esi
	movq	%rax, %rdi
	call	pthread_create@PLT
	testl	%eax, %eax
	je	.L7
	leaq	.LC2(%rip), %rdi
	call	perror@PLT
	movl	$1, %eax
	jmp	.L12
.L7:
	addl	$1, -40(%rbp)
.L6:
	cmpl	$1, -40(%rbp)
	jle	.L9
	movl	$0, -36(%rbp)
	jmp	.L10
.L11:
	movl	-36(%rbp), %eax
	cltq
	movq	-32(%rbp,%rax,8), %rax
	movl	$0, %esi
	movq	%rax, %rdi
	call	pthread_join@PLT
	addl	$1, -36(%rbp)
.L10:
	cmpl	$1, -36(%rbp)
	jle	.L11
	movl	global_var(%rip), %eax
	movl	%eax, %esi
	leaq	.LC3(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	leaq	lock(%rip), %rdi
	call	pthread_mutex_destroy@PLT
	movl	$0, %eax
.L12:
	movq	-8(%rbp), %rcx
	xorq	%fs:40, %rcx
	je	.L13
	call	__stack_chk_fail@PLT
.L13:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 9.4.0-1ubuntu1~20.04.2) 9.4.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	 1f - 0f
	.long	 4f - 1f
	.long	 5
0:
	.string	 "GNU"
1:
	.align 8
	.long	 0xc0000002
	.long	 3f - 2f
2:
	.long	 0x3
3:
	.align 8
4:
