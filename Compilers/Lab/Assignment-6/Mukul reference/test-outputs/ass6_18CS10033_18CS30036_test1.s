# Compiled by Mukul and Rashil on GNU / Linux with Love
# Free Software, Free Society
	.file	"output.s"

.STR0:	.string "This Program implements LCM\n"
.STR1:	.string "Enter the size of an array(<=100): \n"
.STR2:	.string "Enter the elements of the array one by one i.e. single element in a line: \n"
.STR3:	.string "lcm of given no is: "
.STR4:	.string "\n"
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
	jmp .L2
# 4:res = a 
.L1:
	movl	-8(%rbp), %eax
	jmp	.LRT0
# 5:
	jmp .L2
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
.LRT0:
	addq	$-20, %rsp
	movq	%rbp, %rsp
	popq	%rbp
	ret
.LFE0:
	.size	gcd, .-gcd
	.globl	findlcm
	.type	findlcm, @function
findlcm:
.LFB1:
	pushq	%rbp
	movq	%rsp, %rbp
	subq	$104, %rsp
	movl	%edi, -4(%rbp)
	movq	%rsi, -12(%rbp)
# 11:res = t003 
	movl	$0, -24(%rbp)
# 12:res = t004 
	movl	$0, -28(%rbp)
# 13:res = t006 arg1 = t004 
	movl	-28(%rbp), %eax
	movl	$4, %ecx
	imull	%ecx, %eax
	movl	%eax, -36(%rbp)
# 14:res = t005 arg1 = t003 arg2 = t006 
	movl	-24(%rbp), %eax
	movl	-36(%rbp), %edx
	addl	%edx, %eax
	movl	%eax, -32(%rbp)
# 15:res = t007 arg1 = arr arg2 = t005 
	movq	-12(%rbp), %rdx
	movslq	-32(%rbp), %rax
	addq	%rax, %rdx
	movl	(%rdx), %eax
	movl	%eax, -40(%rbp)
# 16:res = ans arg1 = t007 
	movl	-40(%rbp), %eax
	movl	%eax, -16(%rbp)
# 17:res = t008 arg1 = t007 
	movl	-40(%rbp), %eax
	movl	%eax, -44(%rbp)
# 18:res = t009 
	movl	$1, -48(%rbp)
# 19:res = i arg1 = t009 
	movl	-48(%rbp), %eax
	movl	%eax, -20(%rbp)
# 20:res = t010 arg1 = t009 
	movl	-48(%rbp), %eax
	movl	%eax, -52(%rbp)
# 21:arg1 = i arg2 = n 
.L5:
	movl	-20(%rbp), %eax
	movl	-4(%rbp), %edx
	cmpl	%edx, %eax
	jl .L3
# 22:
	jmp .L4
# 23:
	jmp .L4
# 24:res = t011 arg1 = i 
.L6:
	movl	-20(%rbp), %eax
	movl	%eax, -56(%rbp)
# 25:res = i arg1 = i 
	movl	-20(%rbp), %eax
	movl	$1, %edx
	addl	%edx, %eax
	movl	%eax, -20(%rbp)
# 26:
	jmp .L5
# 27:res = t012 
.L3:
	movl	$0, -60(%rbp)
# 28:res = t014 arg1 = i 
	movl	-20(%rbp), %eax
	movl	$4, %ecx
	imull	%ecx, %eax
	movl	%eax, -68(%rbp)
# 29:res = t013 arg1 = t012 arg2 = t014 
	movl	-60(%rbp), %eax
	movl	-68(%rbp), %edx
	addl	%edx, %eax
	movl	%eax, -64(%rbp)
# 30:res = t015 arg1 = arr arg2 = t013 
	movq	-12(%rbp), %rdx
	movslq	-64(%rbp), %rax
	addq	%rax, %rdx
	movl	(%rdx), %eax
	movl	%eax, -72(%rbp)
# 31:res = t016 arg1 = t015 arg2 = ans 
	movl	-72(%rbp), %eax
	imull	-16(%rbp), %eax
	movl	%eax, -76(%rbp)
# 32:res = t017 
	movl	$0, -80(%rbp)
# 33:res = t019 arg1 = i 
	movl	-20(%rbp), %eax
	movl	$4, %ecx
	imull	%ecx, %eax
	movl	%eax, -88(%rbp)
# 34:res = t018 arg1 = t017 arg2 = t019 
	movl	-80(%rbp), %eax
	movl	-88(%rbp), %edx
	addl	%edx, %eax
	movl	%eax, -84(%rbp)
# 35:res = t020 arg1 = arr arg2 = t018 
	movq	-12(%rbp), %rdx
	movslq	-84(%rbp), %rax
	addq	%rax, %rdx
	movl	(%rdx), %eax
	movl	%eax, -92(%rbp)
# 36:res = t020 
# 37:res = ans 
# 38:res = t021 
	pushq %rbp
	movl	-16(%rbp) , %edi
	movl	-92(%rbp) , %esi
	call	gcd
	movl	%eax, -96(%rbp)
	addq $0 , %rsp
# 39:res = t022 arg1 = t016 arg2 = t021 
	movl	-76(%rbp), %eax
	cltd
	idivl	-96(%rbp), %eax
	movl	%eax, -100(%rbp)
# 40:res = ans arg1 = t022 
	movl	-100(%rbp), %eax
	movl	%eax, -16(%rbp)
# 41:res = t023 arg1 = t022 
	movl	-100(%rbp), %eax
	movl	%eax, -104(%rbp)
# 42:
	jmp .L6
# 43:res = ans 
.L4:
	movl	-16(%rbp), %eax
	jmp	.LRT1
.LRT1:
	addq	$-104, %rsp
	movq	%rbp, %rsp
	popq	%rbp
	ret
.LFE1:
	.size	findlcm, .-findlcm
	.globl	main
	.type	main, @function
main:
.LFB2:
	pushq	%rbp
	movq	%rsp, %rbp
	subq	$524, %rsp
# 44:res = t024 
	movl	$100, -404(%rbp)
# 45:res = t025 
	movl	$1, -436(%rbp)
# 46:res = err arg1 = t025 
	movl	-436(%rbp), %eax
	movl	%eax, -432(%rbp)
# 47:
	movq	$.STR0,	%rdi
# 48:res = t026 
	pushq %rbp
	call	printStr
	movl	%eax, -440(%rbp)
	addq $8 , %rsp
# 49:
	movq	$.STR1,	%rdi
# 50:res = t027 
	pushq %rbp
	call	printStr
	movl	%eax, -444(%rbp)
	addq $8 , %rsp
# 51:res = t028 arg1 = err 
	leaq	-432(%rbp), %rax
	movq	%rax, -448(%rbp)
# 52:res = t028 
# 53:res = t029 
	pushq %rbp
	movq	-448(%rbp), %rdi
	call	readInt
	movl	%eax, -452(%rbp)
	addq $0 , %rsp
# 54:res = n arg1 = t029 
	movl	-452(%rbp), %eax
	movl	%eax, -412(%rbp)
# 55:res = t030 arg1 = t029 
	movl	-452(%rbp), %eax
	movl	%eax, -456(%rbp)
# 56:
	movq	$.STR2,	%rdi
# 57:res = t031 
	pushq %rbp
	call	printStr
	movl	%eax, -460(%rbp)
	addq $8 , %rsp
# 58:res = t032 
	movl	$0, -464(%rbp)
# 59:res = i arg1 = t032 
	movl	-464(%rbp), %eax
	movl	%eax, -408(%rbp)
# 60:res = t033 arg1 = t032 
	movl	-464(%rbp), %eax
	movl	%eax, -468(%rbp)
# 61:arg1 = i arg2 = n 
.L9:
	movl	-408(%rbp), %eax
	movl	-412(%rbp), %edx
	cmpl	%edx, %eax
	jl .L7
# 62:
	jmp .L8
# 63:
	jmp .L8
# 64:res = t034 arg1 = i 
.L10:
	movl	-408(%rbp), %eax
	movl	%eax, -472(%rbp)
# 65:res = i arg1 = i 
	movl	-408(%rbp), %eax
	movl	$1, %edx
	addl	%edx, %eax
	movl	%eax, -408(%rbp)
# 66:
	jmp .L9
# 67:res = t035 
.L7:
	movl	$0, -476(%rbp)
# 68:res = t037 arg1 = i 
	movl	-408(%rbp), %eax
	movl	$4, %ecx
	imull	%ecx, %eax
	movl	%eax, -484(%rbp)
# 69:res = t036 arg1 = t035 arg2 = t037 
	movl	-476(%rbp), %eax
	movl	-484(%rbp), %edx
	addl	%edx, %eax
	movl	%eax, -480(%rbp)
# 70:res = t038 arg1 = err 
	leaq	-432(%rbp), %rax
	movq	%rax, -488(%rbp)
# 71:res = t038 
# 72:res = t039 
	pushq %rbp
	movq	-488(%rbp), %rdi
	call	readInt
	movl	%eax, -492(%rbp)
	addq $0 , %rsp
# 73:res = a arg1 = t036 arg2 = t039 
	leaq	-400(%rbp), %rdx
	movslq	-480(%rbp), %rax
	addq	%rax, %rdx
	movl	-492(%rbp), %eax
	movl	%eax, (%rdx)
# 74:res = t040 arg1 = t039 
	movl	-492(%rbp), %eax
	movl	%eax, -496(%rbp)
# 75:
	jmp .L10
# 76:res = t041 
.L8:
	movl	$0, -500(%rbp)
# 77:res = a 
# 78:res = n 
# 79:res = t042 
	pushq %rbp
	movl	-412(%rbp) , %edi
	leaq	-400(%rbp), %rsi
	call	findlcm
	movl	%eax, -504(%rbp)
	addq $0 , %rsp
# 80:res = l arg1 = t042 
	movl	-504(%rbp), %eax
	movl	%eax, -424(%rbp)
# 81:res = t043 arg1 = t042 
	movl	-504(%rbp), %eax
	movl	%eax, -508(%rbp)
# 82:
	movq	$.STR3,	%rdi
# 83:res = t044 
	pushq %rbp
	call	printStr
	movl	%eax, -512(%rbp)
	addq $8 , %rsp
# 84:res = l 
# 85:res = t045 
	pushq %rbp
	movl	-424(%rbp) , %edi
	call	printInt
	movl	%eax, -516(%rbp)
	addq $0 , %rsp
# 86:
	movq	$.STR4,	%rdi
# 87:res = t046 
	pushq %rbp
	call	printStr
	movl	%eax, -520(%rbp)
	addq $8 , %rsp
# 88:res = t047 
	movl	$0, -524(%rbp)
# 89:res = t047 
	movl	-524(%rbp), %eax
	jmp	.LRT2
.LRT2:
	addq	$-524, %rsp
	movq	%rbp, %rsp
	popq	%rbp
	ret
.LFE2:
	.size	main, .-main
