	.file	"output.s"

.STR0:	.string "\n************************ GCD **************************\n"
.STR1:	.string "\nEnter two numbers:\n"
.STR2:	.string "\nGCD of the entered numbers is:\n"
.STR3:	.string "\n*******************************************************\n"
	.text
	.globl	gcd
	.type	gcd, @function
gcd:
.LFB0:
	pushq	%rbp
	movq	%rsp, %rbp
	subq	$20, %rsp
	movl	%edi, -4(%rbp)
	movl	%esi, -8(%rbp)
# 0:res = t000 
	movl	$0, -12(%rbp)
# 1:arg1 = b arg2 = t000 
	movl	-4(%rbp), %eax
	movl	-12(%rbp), %edx
	cmpl	%edx, %eax
	je .L1
# 2:
	jmp .L2
# 3:
	jmp	.LRT0
# 4:res = a 
.L1:
	movl	-8(%rbp), %eax
	jmp	.LRT0
# 5:
	jmp	.LRT0
# 6:res = t001 arg1 = a arg2 = b 
.L2:
	movl	-8(%rbp), %eax
	cltd
	idivl	-4(%rbp), %eax
	movl	%edx, -16(%rbp)
# 7:res = b 
# 8:res = t001 
# 9:res = t002 
	pushq %rbp
	movl	-16(%rbp) , %edi
	movl	-4(%rbp) , %esi
	call	gcd
	movl	%eax, -20(%rbp)
	addq $0 , %rsp
# 10:res = t002 
	movl	-20(%rbp), %eax
	jmp	.LRT0
# 11:
	jmp	.LRT0
.LRT0:
	addq	$-20, %rsp
	movq	%rbp, %rsp
	popq	%rbp
	ret
.LFE0:
	.size	gcd, .-gcd
	.globl	main
	.type	main, @function
main:
.LFB1:
	pushq	%rbp
	movq	%rsp, %rbp
	subq	$80, %rsp
# 12:
.L3:
	movq	$.STR0,	%rdi
# 13:res = t003 
	pushq %rbp
	call	printStr
	movl	%eax, -20(%rbp)
	addq $0 , %rsp
# 14:
	movq	$.STR1,	%rdi
# 15:res = t004 
	pushq %rbp
	call	printStr
	movl	%eax, -24(%rbp)
	addq $0 , %rsp
# 16:res = t005 arg1 = err 
	leaq	-16(%rbp), %rax
	movq	%rax, -32(%rbp)
# 17:res = t005 
# 18:res = t006 
	pushq %rbp
	movq	-32(%rbp), %rdi
	call	readInt
	movl	%eax, -36(%rbp)
	addq $0 , %rsp
# 19:res = a arg1 = t006 
	movl	-36(%rbp), %eax
	movl	%eax, -4(%rbp)
# 20:res = t007 arg1 = t006 
	movl	-36(%rbp), %eax
	movl	%eax, -40(%rbp)
# 21:res = t008 arg1 = err 
	leaq	-16(%rbp), %rax
	movq	%rax, -48(%rbp)
# 22:res = t008 
# 23:res = t009 
	pushq %rbp
	movq	-48(%rbp), %rdi
	call	readInt
	movl	%eax, -52(%rbp)
	addq $0 , %rsp
# 24:res = b arg1 = t009 
	movl	-52(%rbp), %eax
	movl	%eax, -8(%rbp)
# 25:res = t010 arg1 = t009 
	movl	-52(%rbp), %eax
	movl	%eax, -56(%rbp)
# 26:res = a 
# 27:res = b 
# 28:res = t011 
	pushq %rbp
	movl	-8(%rbp) , %edi
	movl	-4(%rbp) , %esi
	call	gcd
	movl	%eax, -60(%rbp)
	addq $0 , %rsp
# 29:res = c arg1 = t011 
	movl	-60(%rbp), %eax
	movl	%eax, -12(%rbp)
# 30:res = t012 arg1 = t011 
	movl	-60(%rbp), %eax
	movl	%eax, -64(%rbp)
# 31:
	movq	$.STR2,	%rdi
# 32:res = t013 
	pushq %rbp
	call	printStr
	movl	%eax, -68(%rbp)
	addq $0 , %rsp
# 33:res = c 
# 34:res = t014 
	pushq %rbp
	movl	-12(%rbp) , %edi
	call	printInt
	movl	%eax, -72(%rbp)
	addq $0 , %rsp
# 35:
	movq	$.STR3,	%rdi
# 36:res = t015 
	pushq %rbp
	call	printStr
	movl	%eax, -76(%rbp)
	addq $0 , %rsp
# 37:res = t016 
	movl	$0, -80(%rbp)
# 38:res = t016 
	movl	-80(%rbp), %eax
	jmp	.LRT1
.LRT1:
	addq	$-80, %rsp
	movq	%rbp, %rsp
	popq	%rbp
	ret
.LFE1:
	.size	main, .-main
