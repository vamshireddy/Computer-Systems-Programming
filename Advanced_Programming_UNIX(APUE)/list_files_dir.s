	.file	"list_files_dir.c"
	.section	.rodata
.LC0:
	.string	"/etc"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movl	$.LC0, %edi
	call	opendir
	movq	%rax, -16(%rbp)
	jmp	.L2
.L3:
	movq	-8(%rbp), %rax
	addq	$19, %rax
	movq	%rax, %rdi
	call	puts
.L2:
	movq	-16(%rbp), %rax
	movq	%rax, %rdi
	call	readdir
	movq	%rax, -8(%rbp)
	cmpq	$0, -8(%rbp)
	jne	.L3
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (Ubuntu/Linaro 4.7.3-1ubuntu1) 4.7.3"
	.section	.note.GNU-stack,"",@progbits
