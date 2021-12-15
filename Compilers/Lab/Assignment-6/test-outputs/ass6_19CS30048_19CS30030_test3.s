	.file	"output.s"

.STR0:	.string "\n************* Contiguous subarray with the largest sum ***********\n"
.STR1:	.string "\nEnter size of array less than 100\n"
.STR2:	.string "\nEnter the elements of the first array one by one\n"
.STR3:	.string "\nLargest sum contiguous subarray is: "
.STR4:	.string "\n\n*********************************************************************\n"
	.text
	.globl	maxSubArraySum
	.type	maxSubArraySum, @function
maxSubArraySum:
.LFB0:
	pushq	%rbp
	movq	%rsp, %rbp
	subq	$88, %rsp
	movl	%edi, -4(%rbp)
	movq	%rsi, -12(%rbp)
# 0:res = t000 
	movl	$1000000000, -20(%rbp)
# 1:res = t001 arg1 = t000 
	movl	-20(%rbp), %eax
	negl	%eax
	movl	%eax, -24(%rbp)
# 2:res = max_so_far arg1 = t001 
	movl	-24(%rbp), %eax
	movl	%eax, -16(%rbp)
# 3:res = t002 
	movl	$0, -32(%rbp)
# 4:res = max_ending_here arg1 = t002 
	movl	-32(%rbp), %eax
	movl	%eax, -28(%rbp)
# 5:res = t003 
	movl	$0, -40(%rbp)
# 6:res = i arg1 = t003 
	movl	-40(%rbp), %eax
	movl	%eax, -36(%rbp)
# 7:res = t004 arg1 = t003 
	movl	-40(%rbp), %eax
	movl	%eax, -44(%rbp)
# 8:arg1 = i arg2 = size 
.L3:
	movl	-36(%rbp), %eax
	movl	-4(%rbp), %edx
	cmpl	%edx, %eax
	jl .L1
# 9:
	jmp .L2
# 10:
	jmp .L2
# 11:res = t005 arg1 = i 
.L7:
	movl	-36(%rbp), %eax
	movl	%eax, -48(%rbp)
# 12:res = i arg1 = i 
	movl	-36(%rbp), %eax
	movl	$1, %edx
	addl	%edx, %eax
	movl	%eax, -36(%rbp)
# 13:
	jmp .L3
# 14:res = t006 
.L1:
	movl	$0, -52(%rbp)
# 15:res = t008 arg1 = i 
	movl	-36(%rbp), %eax
	movl	$4, %ecx
	imull	%ecx, %eax
	movl	%eax, -60(%rbp)
# 16:res = t007 arg1 = t006 arg2 = t008 
	movl	-52(%rbp), %eax
	movl	-60(%rbp), %edx
	addl	%edx, %eax
	movl	%eax, -56(%rbp)
# 17:res = t009 arg1 = arr arg2 = t007 
	movq	-12(%rbp), %rdx
	movslq	-56(%rbp), %rax
	addq	%rax, %rdx
	movl	(%rdx), %eax
	movl	%eax, -64(%rbp)
# 18:res = t010 arg1 = max_ending_here arg2 = t009 
	movl	-28(%rbp), %eax
	movl	-64(%rbp), %edx
	addl	%edx, %eax
	movl	%eax, -68(%rbp)
# 19:res = max_ending_here arg1 = t010 
	movl	-68(%rbp), %eax
	movl	%eax, -28(%rbp)
# 20:res = t011 arg1 = t010 
	movl	-68(%rbp), %eax
	movl	%eax, -72(%rbp)
# 21:arg1 = max_so_far arg2 = max_ending_here 
	movl	-16(%rbp), %eax
	movl	-28(%rbp), %edx
	cmpl	%edx, %eax
	jl .L4
# 22:
	jmp .L5
# 23:
	jmp .L5
# 24:res = max_so_far arg1 = max_ending_here 
.L4:
	movl	-28(%rbp), %eax
	movl	%eax, -16(%rbp)
# 25:res = t012 arg1 = max_ending_here 
	movl	-28(%rbp), %eax
	movl	%eax, -76(%rbp)
# 26:
	jmp .L5
# 27:res = t013 
.L5:
	movl	$0, -80(%rbp)
# 28:arg1 = max_ending_here arg2 = t013 
	movl	-28(%rbp), %eax
	movl	-80(%rbp), %edx
	cmpl	%edx, %eax
	jl .L6
# 29:
	jmp .L7
# 30:
	jmp .L8
# 31:res = t014 
.L6:
	movl	$0, -84(%rbp)
# 32:res = max_ending_here arg1 = t014 
	movl	-84(%rbp), %eax
	movl	%eax, -28(%rbp)
# 33:res = t015 arg1 = t014 
	movl	-84(%rbp), %eax
	movl	%eax, -88(%rbp)
# 34:
	jmp .L7
# 35:
.L8:
	jmp .L7
# 36:res = max_so_far 
.L2:
	movl	-16(%rbp), %eax
	jmp	.LRT0
.LRT0:
	addq	$-88, %rsp
	movq	%rbp, %rsp
	popq	%rbp
	ret
.LFE0:
	.size	maxSubArraySum, .-maxSubArraySum
	.globl	main
	.type	main, @function
main:
.LFB1:
	pushq	%rbp
	movq	%rsp, %rbp
	subq	$520, %rsp
# 37:res = t016 
	movl	$100, -408(%rbp)
# 38:
	movq	$.STR0,	%rdi
# 39:res = t017 
	pushq %rbp
	call	printStr
	movl	%eax, -412(%rbp)
	addq $0 , %rsp
# 40:
	movq	$.STR1,	%rdi
# 41:res = t018 
	pushq %rbp
	call	printStr
	movl	%eax, -416(%rbp)
	addq $0 , %rsp
# 42:res = t019 
	movl	$1, -424(%rbp)
# 43:res = err arg1 = t019 
	movl	-424(%rbp), %eax
	movl	%eax, -420(%rbp)
# 44:res = t020 arg1 = err 
	leaq	-420(%rbp), %rax
	movq	%rax, -432(%rbp)
# 45:res = t020 
# 46:res = t021 
	pushq %rbp
	movq	-432(%rbp), %rdi
	call	readInt
	movl	%eax, -436(%rbp)
	addq $0 , %rsp
# 47:res = n arg1 = t021 
	movl	-436(%rbp), %eax
	movl	%eax, -4(%rbp)
# 48:res = t022 arg1 = t021 
	movl	-436(%rbp), %eax
	movl	%eax, -440(%rbp)
# 49:
	movq	$.STR2,	%rdi
# 50:res = t023 
	pushq %rbp
	call	printStr
	movl	%eax, -444(%rbp)
	addq $0 , %rsp
# 51:res = t024 
	movl	$0, -452(%rbp)
# 52:res = i arg1 = t024 
	movl	-452(%rbp), %eax
	movl	%eax, -448(%rbp)
# 53:res = t025 arg1 = t024 
	movl	-452(%rbp), %eax
	movl	%eax, -456(%rbp)
# 54:arg1 = i arg2 = n 
.L11:
	movl	-448(%rbp), %eax
	movl	-4(%rbp), %edx
	cmpl	%edx, %eax
	jl .L9
# 55:
	jmp .L10
# 56:
	jmp .L10
# 57:res = t026 arg1 = i 
.L12:
	movl	-448(%rbp), %eax
	movl	%eax, -460(%rbp)
# 58:res = i arg1 = i 
	movl	-448(%rbp), %eax
	movl	$1, %edx
	addl	%edx, %eax
	movl	%eax, -448(%rbp)
# 59:
	jmp .L11
# 60:res = t027 
.L9:
	movl	$0, -464(%rbp)
# 61:res = t029 arg1 = i 
	movl	-448(%rbp), %eax
	movl	$4, %ecx
	imull	%ecx, %eax
	movl	%eax, -472(%rbp)
# 62:res = t028 arg1 = t027 arg2 = t029 
	movl	-464(%rbp), %eax
	movl	-472(%rbp), %edx
	addl	%edx, %eax
	movl	%eax, -468(%rbp)
# 63:res = t030 arg1 = err 
	leaq	-420(%rbp), %rax
	movq	%rax, -480(%rbp)
# 64:res = t030 
# 65:res = t031 
	pushq %rbp
	movq	-480(%rbp), %rdi
	call	readInt
	movl	%eax, -484(%rbp)
	addq $0 , %rsp
# 66:res = arr arg1 = t028 arg2 = t031 
	leaq	-404(%rbp), %rdx
	movslq	-468(%rbp), %rax
	addq	%rax, %rdx
	movl	-484(%rbp), %eax
	movl	%eax, (%rdx)
# 67:res = t032 arg1 = t031 
	movl	-484(%rbp), %eax
	movl	%eax, -488(%rbp)
# 68:
	jmp .L12
# 69:res = t033 
.L10:
	movl	$0, -496(%rbp)
# 70:res = arr 
# 71:res = n 
# 72:res = t034 
	pushq %rbp
	movl	-4(%rbp) , %edi
	leaq	-404(%rbp), %rsi
	call	maxSubArraySum
	movl	%eax, -500(%rbp)
	addq $0 , %rsp
# 73:res = s arg1 = t034 
	movl	-500(%rbp), %eax
	movl	%eax, -492(%rbp)
# 74:res = t035 arg1 = t034 
	movl	-500(%rbp), %eax
	movl	%eax, -504(%rbp)
# 75:
	movq	$.STR3,	%rdi
# 76:res = t036 
	pushq %rbp
	call	printStr
	movl	%eax, -508(%rbp)
	addq $0 , %rsp
# 77:res = s 
# 78:res = t037 
	pushq %rbp
	movl	-492(%rbp) , %edi
	call	printInt
	movl	%eax, -512(%rbp)
	addq $0 , %rsp
# 79:
	movq	$.STR4,	%rdi
# 80:res = t038 
	pushq %rbp
	call	printStr
	movl	%eax, -516(%rbp)
	addq $0 , %rsp
# 81:res = t039 
	movl	$0, -520(%rbp)
# 82:res = t039 
	movl	-520(%rbp), %eax
	jmp	.LRT1
.LRT1:
	addq	$-520, %rsp
	movq	%rbp, %rsp
	popq	%rbp
	ret
.LFE1:
	.size	main, .-main
