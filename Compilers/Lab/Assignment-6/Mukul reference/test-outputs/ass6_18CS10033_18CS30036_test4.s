# Compiled by Mukul and Rashil on GNU / Linux with Love
# Free Software, Free Society
	.file	"output.s"

.STR0:	.string "FizzBuzz\t"
.STR1:	.string "Fizz\t"
.STR2:	.string "Buzz\t"
.STR3:	.string "\t"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	pushq	%rbp
	movq	%rsp, %rbp
	subq	$80, %rsp
# 0:res = t000 
	movl	$1, -8(%rbp)
# 1:res = i arg1 = t000 
	movl	-8(%rbp), %eax
	movl	%eax, -4(%rbp)
# 2:res = t001 arg1 = t000 
	movl	-8(%rbp), %eax
	movl	%eax, -12(%rbp)
# 3:res = t002 
.L3:
	movl	$100, -16(%rbp)
# 4:arg1 = i arg2 = t002 
	movl	-4(%rbp), %eax
	movl	-16(%rbp), %edx
	cmpl	%edx, %eax
	jle .L1
# 5:
	jmp .L2
# 6:
	jmp .L2
# 7:res = t003 arg1 = i 
.L7:
	movl	-4(%rbp), %eax
	movl	%eax, -20(%rbp)
# 8:res = i arg1 = i 
	movl	-4(%rbp), %eax
	movl	$1, %edx
	addl	%edx, %eax
	movl	%eax, -4(%rbp)
# 9:
	jmp .L3
# 10:res = t004 
.L1:
	movl	$15, -24(%rbp)
# 11:res = t005 arg1 = i arg2 = t004 
	movl	-4(%rbp), %eax
	cltd
	idivl	-24(%rbp), %eax
	movl	%edx, -28(%rbp)
# 12:res = t006 
	movl	$0, -32(%rbp)
# 13:arg1 = t005 arg2 = t006 
	movl	-28(%rbp), %eax
	movl	-32(%rbp), %edx
	cmpl	%edx, %eax
	je .L4
# 14:
	jmp .L5
# 15:
	jmp .L6
# 16:
.L4:
	movq	$.STR0,	%rdi
# 17:res = t007 
	pushq %rbp
	call	printStr
	movl	%eax, -36(%rbp)
	addq $8 , %rsp
# 18:
	jmp .L7
# 19:res = t008 
.L5:
	movl	$3, -40(%rbp)
# 20:res = t009 arg1 = i arg2 = t008 
	movl	-4(%rbp), %eax
	cltd
	idivl	-40(%rbp), %eax
	movl	%edx, -44(%rbp)
# 21:res = t010 
	movl	$0, -48(%rbp)
# 22:arg1 = t009 arg2 = t010 
	movl	-44(%rbp), %eax
	movl	-48(%rbp), %edx
	cmpl	%edx, %eax
	je .L8
# 23:
	jmp .L9
# 24:
	jmp .L10
# 25:
.L8:
	movq	$.STR1,	%rdi
# 26:res = t011 
	pushq %rbp
	call	printStr
	movl	%eax, -52(%rbp)
	addq $8 , %rsp
# 27:
	jmp .L7
# 28:res = t012 
.L9:
	movl	$5, -56(%rbp)
# 29:res = t013 arg1 = i arg2 = t012 
	movl	-4(%rbp), %eax
	cltd
	idivl	-56(%rbp), %eax
	movl	%edx, -60(%rbp)
# 30:res = t014 
	movl	$0, -64(%rbp)
# 31:arg1 = t013 arg2 = t014 
	movl	-60(%rbp), %eax
	movl	-64(%rbp), %edx
	cmpl	%edx, %eax
	je .L11
# 32:
	jmp .L12
# 33:
	jmp .L13
# 34:
.L11:
	movq	$.STR2,	%rdi
# 35:res = t015 
	pushq %rbp
	call	printStr
	movl	%eax, -68(%rbp)
	addq $8 , %rsp
# 36:
	jmp .L7
# 37:res = i 
.L12:
# 38:res = t016 
	pushq %rbp
	movl	-4(%rbp) , %edi
	call	printInt
	movl	%eax, -72(%rbp)
	addq $0 , %rsp
# 39:
	movq	$.STR3,	%rdi
# 40:res = t017 
	pushq %rbp
	call	printStr
	movl	%eax, -76(%rbp)
	addq $8 , %rsp
# 41:
	jmp .L7
# 42:
.L13:
	jmp .L7
# 43:
.L10:
	jmp .L7
# 44:
.L6:
	jmp .L7
# 45:res = t018 
.L2:
	movl	$0, -80(%rbp)
# 46:res = t018 
	movl	-80(%rbp), %eax
	jmp	.LRT0
.LRT0:
	addq	$-80, %rsp
	movq	%rbp, %rsp
	popq	%rbp
	ret
.LFE0:
	.size	main, .-main
