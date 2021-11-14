	.file	"output.s"

.STR0:	.string "\n*************************** Fibonacci Triangle ***************************\n"
.STR1:	.string "\nEnter the upper limit: \n"
.STR2:	.string "\nThe required Fibonacci Triangle: \n"
.STR3:	.string "\t"
.STR4:	.string "\t"
.STR5:	.string "\n"
.STR6:	.string "\n*******************************************************************************\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	pushq	%rbp
	movq	%rsp, %rbp
	subq	$156, %rsp
# 0:res = t000 
	movl	$0, -8(%rbp)
# 1:res = a arg1 = t000 
	movl	-8(%rbp), %eax
	movl	%eax, -4(%rbp)
# 2:res = t001 
	movl	$1, -16(%rbp)
# 3:res = b arg1 = t001 
	movl	-16(%rbp), %eax
	movl	%eax, -12(%rbp)
# 4:
	movq	$.STR0,	%rdi
# 5:res = t002 
	pushq %rbp
	call	printStr
	movl	%eax, -36(%rbp)
	addq $0 , %rsp
# 6:
	movq	$.STR1,	%rdi
# 7:res = t003 
	pushq %rbp
	call	printStr
	movl	%eax, -40(%rbp)
	addq $0 , %rsp
# 8:res = t004 arg1 = err 
	leaq	-44(%rbp), %rax
	movq	%rax, -52(%rbp)
# 9:res = t004 
# 10:res = t005 
	pushq %rbp
	movq	-52(%rbp), %rdi
	call	readInt
	movl	%eax, -56(%rbp)
	addq $0 , %rsp
# 11:res = n arg1 = t005 
	movl	-56(%rbp), %eax
	movl	%eax, -28(%rbp)
# 12:res = t006 arg1 = t005 
	movl	-56(%rbp), %eax
	movl	%eax, -60(%rbp)
# 13:
	movq	$.STR2,	%rdi
# 14:res = t007 
	pushq %rbp
	call	printStr
	movl	%eax, -64(%rbp)
	addq $0 , %rsp
# 15:res = t008 
	movl	$0, -68(%rbp)
# 16:res = a arg1 = t008 
	movl	-68(%rbp), %eax
	movl	%eax, -4(%rbp)
# 17:res = t009 arg1 = t008 
	movl	-68(%rbp), %eax
	movl	%eax, -72(%rbp)
# 18:res = t010 
	movl	$1, -76(%rbp)
# 19:res = b arg1 = t010 
	movl	-76(%rbp), %eax
	movl	%eax, -12(%rbp)
# 20:res = t011 arg1 = t010 
	movl	-76(%rbp), %eax
	movl	%eax, -80(%rbp)
# 21:res = t012 
	movl	$1, -84(%rbp)
# 22:res = t013 arg1 = n arg2 = t012 
	movl	-28(%rbp), %eax
	movl	-84(%rbp), %edx
	addl	%edx, %eax
	movl	%eax, -88(%rbp)
# 23:res = n arg1 = t013 
	movl	-88(%rbp), %eax
	movl	%eax, -28(%rbp)
# 24:res = t014 arg1 = t013 
	movl	-88(%rbp), %eax
	movl	%eax, -92(%rbp)
# 25:res = t015 
	movl	$1, -96(%rbp)
# 26:res = i arg1 = t015 
	movl	-96(%rbp), %eax
	movl	%eax, -20(%rbp)
# 27:res = t016 arg1 = t015 
	movl	-96(%rbp), %eax
	movl	%eax, -100(%rbp)
# 28:arg1 = i arg2 = n 
.L3:
	movl	-20(%rbp), %eax
	movl	-28(%rbp), %edx
	cmpl	%edx, %eax
	jle .L1
# 29:
	jmp .L2
# 30:
	jmp .L2
# 31:res = t017 arg1 = i 
.L8:
	movl	-20(%rbp), %eax
	movl	%eax, -104(%rbp)
# 32:res = i arg1 = i 
	movl	-20(%rbp), %eax
	movl	$1, %edx
	addl	%edx, %eax
	movl	%eax, -20(%rbp)
# 33:
	jmp .L3
# 34:
.L1:
	movq	$.STR3,	%rdi
# 35:res = t018 
	pushq %rbp
	call	printStr
	movl	%eax, -108(%rbp)
	addq $0 , %rsp
# 36:res = t019 
	movl	$1, -112(%rbp)
# 37:res = j arg1 = t019 
	movl	-112(%rbp), %eax
	movl	%eax, -32(%rbp)
# 38:res = t020 arg1 = t019 
	movl	-112(%rbp), %eax
	movl	%eax, -116(%rbp)
# 39:arg1 = j arg2 = i 
.L6:
	movl	-32(%rbp), %eax
	movl	-20(%rbp), %edx
	cmpl	%edx, %eax
	jl .L4
# 40:
	jmp .L5
# 41:
	jmp .L5
# 42:res = t021 arg1 = j 
.L7:
	movl	-32(%rbp), %eax
	movl	%eax, -120(%rbp)
# 43:res = j arg1 = j 
	movl	-32(%rbp), %eax
	movl	$1, %edx
	addl	%edx, %eax
	movl	%eax, -32(%rbp)
# 44:
	jmp .L6
# 45:res = t022 arg1 = a arg2 = b 
.L4:
	movl	-4(%rbp), %eax
	movl	-12(%rbp), %edx
	addl	%edx, %eax
	movl	%eax, -124(%rbp)
# 46:res = c arg1 = t022 
	movl	-124(%rbp), %eax
	movl	%eax, -24(%rbp)
# 47:res = t023 arg1 = t022 
	movl	-124(%rbp), %eax
	movl	%eax, -128(%rbp)
# 48:res = b 
# 49:res = t024 
	pushq %rbp
	movl	-12(%rbp) , %edi
	call	printInt
	movl	%eax, -132(%rbp)
	addq $0 , %rsp
# 50:
	movq	$.STR4,	%rdi
# 51:res = t025 
	pushq %rbp
	call	printStr
	movl	%eax, -136(%rbp)
	addq $0 , %rsp
# 52:res = a arg1 = b 
	movl	-12(%rbp), %eax
	movl	%eax, -4(%rbp)
# 53:res = t026 arg1 = b 
	movl	-12(%rbp), %eax
	movl	%eax, -140(%rbp)
# 54:res = b arg1 = c 
	movl	-24(%rbp), %eax
	movl	%eax, -12(%rbp)
# 55:res = t027 arg1 = c 
	movl	-24(%rbp), %eax
	movl	%eax, -144(%rbp)
# 56:
	jmp .L7
# 57:
.L5:
	movq	$.STR5,	%rdi
# 58:res = t028 
	pushq %rbp
	call	printStr
	movl	%eax, -148(%rbp)
	addq $0 , %rsp
# 59:
	jmp .L8
# 60:
.L2:
	movq	$.STR6,	%rdi
# 61:res = t029 
	pushq %rbp
	call	printStr
	movl	%eax, -152(%rbp)
	addq $0 , %rsp
# 62:res = t030 
	movl	$0, -156(%rbp)
# 63:res = t030 
	movl	-156(%rbp), %eax
	jmp	.LRT0
.LRT0:
	addq	$-156, %rsp
	movq	%rbp, %rsp
	popq	%rbp
	ret
.LFE0:
	.size	main, .-main
