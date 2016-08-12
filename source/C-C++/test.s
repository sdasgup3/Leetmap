	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 10, 11
	.globl	__Z4funci
	.align	4, 0x90
__Z4funci:                              ## @_Z4funci
	.cfi_startproc
## BB#0:
	pushq	%rbp
Ltmp0:
	.cfi_def_cfa_offset 16
Ltmp1:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp2:
	.cfi_def_cfa_register %rbp
	subq	$32, %rsp
	movq	___stack_chk_guard@GOTPCREL(%rip), %rax
	movq	___stack_chk_guard@GOTPCREL(%rip), %rcx
	movq	(%rcx), %rcx
	movq	%rcx, -8(%rbp)
	movl	%edi, -12(%rbp)
	movl	-12(%rbp), %edi
	movl	%edi, %ecx
	movq	%rsp, %rdx
	movq	%rdx, -24(%rbp)
	leaq	15(,%rcx,4), %rcx
	movabsq	$34359738352, %rdx      ## imm = 0x7FFFFFFF0
	andq	%rdx, %rcx
	movq	%rsp, %rdx
	subq	%rcx, %rdx
	movq	%rdx, %rsp
	movl	$200, (%rdx)
	movl	-12(%rbp), %edi
	subl	$1, %edi
	movslq	%edi, %rcx
	movl	$300, (%rdx,%rcx,4)     ## imm = 0x12C
	movq	-24(%rbp), %rcx
	movq	%rcx, %rsp
	movq	(%rax), %rax
	cmpq	-8(%rbp), %rax
	jne	LBB0_2
## BB#1:
	xorl	%eax, %eax
                                        ## 
	movq	%rbp, %rsp
	popq	%rbp
	retq
LBB0_2:
	callq	___stack_chk_fail
	.cfi_endproc

	.globl	_main
	.align	4, 0x90
_main:                                  ## @main
	.cfi_startproc
## BB#0:
	pushq	%rbp
Ltmp3:
	.cfi_def_cfa_offset 16
Ltmp4:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp5:
	.cfi_def_cfa_register %rbp
	subq	$16, %rsp
	movl	$4, %edi
	movl	$0, -4(%rbp)
	callq	__Z4funci
	xorl	%edi, %edi
	movq	%rax, -16(%rbp)         ## 8-byte Spill
	movl	%edi, %eax
	addq	$16, %rsp
	popq	%rbp
	retq
	.cfi_endproc


.subsections_via_symbols
