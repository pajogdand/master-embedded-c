	.file	"main.c"
	.section	.rodata
	.align 8
.LC1:
	.string	"sin (angle) = %lf cos (angle) = %lf\n"
	.align 8
.LC2:
	.string	"my_sin (angle) = %lf my_cos (angle) = %lf\n"
	.text
.globl main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movsd	pi.3592(%rip), %xmm0
	movsd	.LC0(%rip), %xmm1
	divsd	%xmm1, %xmm0
	movsd	%xmm0, -8(%rbp)
	movsd	-8(%rbp), %xmm0
	call	cos
	movsd	%xmm0, -32(%rbp)
	movsd	-8(%rbp), %xmm0
	call	sin
	movl	$.LC1, %eax
	movsd	-32(%rbp), %xmm1
	movq	%rax, %rdi
	movl	$2, %eax
	call	printf
	movsd	-8(%rbp), %xmm0
	call	my_cos
	movsd	%xmm0, -24(%rbp)
	movsd	-8(%rbp), %xmm0
	call	my_sin
	movl	$.LC2, %eax
	movsd	-24(%rbp), %xmm1
	movq	%rax, %rdi
	movl	$2, %eax
	call	printf
	movl	$0, %edi
	call	exit
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.data
	.align 8
	.type	pi.3592, @object
	.size	pi.3592, 8
pi.3592:
	.long	4028335726
	.long	1074340345
	.section	.rodata
	.align 8
.LC0:
	.long	0
	.long	1074266112
	.ident	"GCC: (GNU) 4.4.7 20120313 (Red Hat 4.4.7-17)"
	.section	.note.GNU-stack,"",@progbits
