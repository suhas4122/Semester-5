# Compiled by Mukul and Rashil on GNU / Linux with Love
# Free Software, Free Society
	.file	"output.s"

.STR0:	.string " "
.STR1:	.string "\n"
.STR2:	.string "Number of numbers: \n"
.STR3:	.string "Enter the numbers (separated by newlines): \n"
.STR4:	.string "The sorted elements are:\n"
	.text
	.globl	swap
	.type	swap, @function
swap:
.LFB0:
	pushq	%rbp
	movq	%rsp, %rbp
	subq	$8, %rsp
	movq	%rdi, -4(%rbp)
	movq	%rsi, -8(%rbp)
.LRT0:
	addq	$-8, %rsp
	movq	%rbp, %rsp
	popq	%rbp
	ret
.LFE0:
	.size	swap, .-swap
	.globl	bubbleSort
	.type	bubbleSort, @function
bubbleSort:
.LFB1:
	pushq	%rbp
	movq	%rsp, %rbp
	subq	$104, %rsp
	movl	%edi, -4(%rbp)
	movq	%rsi, -12(%rbp)
# 0:res = t000 
	movl	$0, -24(%rbp)
# 1:res = i arg1 = t000 
	movl	-24(%rbp), %eax
	movl	%eax, -16(%rbp)
# 2:res = t001 arg1 = t000 
	movl	-24(%rbp), %eax
	movl	%eax, -28(%rbp)
# 3:res = t002 
.L3:
	movl	$1, -32(%rbp)
# 4:res = t003 arg1 = n arg2 = t002 
	movl	-4(%rbp), %eax
	movl	-32(%rbp), %edx
	subl	%edx, %eax
	movl	%eax, -36(%rbp)
# 5:arg1 = i arg2 = t003 
	movl	-16(%rbp), %eax
	movl	-36(%rbp), %edx
	cmpl	%edx, %eax
	jl .L1
# 6:
	jmp	.LRT1
# 7:
	jmp	.LRT1
# 8:res = t004 arg1 = i 
.L5:
	movl	-16(%rbp), %eax
	movl	%eax, -40(%rbp)
# 9:res = i arg1 = i 
	movl	-16(%rbp), %eax
	movl	$1, %edx
	addl	%edx, %eax
	movl	%eax, -16(%rbp)
# 10:
	jmp .L3
# 11:res = t005 
.L1:
	movl	$0, -44(%rbp)
# 12:res = j arg1 = t005 
	movl	-44(%rbp), %eax
	movl	%eax, -20(%rbp)
# 13:res = t006 arg1 = t005 
	movl	-44(%rbp), %eax
	movl	%eax, -48(%rbp)
# 14:res = t007 arg1 = n arg2 = i 
.L7:
	movl	-4(%rbp), %eax
	movl	-16(%rbp), %edx
	subl	%edx, %eax
	movl	%eax, -52(%rbp)
# 15:res = t008 
	movl	$1, -56(%rbp)
# 16:res = t009 arg1 = t007 arg2 = t008 
	movl	-52(%rbp), %eax
	movl	-56(%rbp), %edx
	subl	%edx, %eax
	movl	%eax, -60(%rbp)
# 17:arg1 = j arg2 = t009 
	movl	-20(%rbp), %eax
	movl	-60(%rbp), %edx
	cmpl	%edx, %eax
	jl .L4
# 18:
	jmp .L5
# 19:
	jmp .L6
# 20:res = t010 arg1 = j 
.L9:
	movl	-20(%rbp), %eax
	movl	%eax, -64(%rbp)
# 21:res = j arg1 = j 
	movl	-20(%rbp), %eax
	movl	$1, %edx
	addl	%edx, %eax
	movl	%eax, -20(%rbp)
# 22:
	jmp .L7
# 23:res = t011 
.L4:
	movl	$0, -68(%rbp)
# 24:res = t013 arg1 = j 
	movl	-20(%rbp), %eax
	movl	$4, %ecx
	imull	%ecx, %eax
	movl	%eax, -76(%rbp)
# 25:res = t012 arg1 = t011 arg2 = t013 
	movl	-68(%rbp), %eax
	movl	-76(%rbp), %edx
	addl	%edx, %eax
	movl	%eax, -72(%rbp)
# 26:res = t014 arg1 = arr arg2 = t012 
	movq	-12(%rbp), %rdx
	movslq	-72(%rbp), %rax
	addq	%rax, %rdx
	movl	(%rdx), %eax
	movl	%eax, -80(%rbp)
# 27:res = t015 
	movl	$0, -84(%rbp)
# 28:res = t016 
	movl	$1, -88(%rbp)
# 29:res = t017 arg1 = j arg2 = t016 
	movl	-20(%rbp), %eax
	movl	-88(%rbp), %edx
	addl	%edx, %eax
	movl	%eax, -92(%rbp)
# 30:res = t019 arg1 = t017 
	movl	-92(%rbp), %eax
	movl	$4, %ecx
	imull	%ecx, %eax
	movl	%eax, -100(%rbp)
# 31:res = t018 arg1 = t015 arg2 = t019 
	movl	-84(%rbp), %eax
	movl	-100(%rbp), %edx
	addl	%edx, %eax
	movl	%eax, -96(%rbp)
# 32:res = t020 arg1 = arr arg2 = t018 
	movq	-12(%rbp), %rdx
	movslq	-96(%rbp), %rax
	addq	%rax, %rdx
	movl	(%rdx), %eax
	movl	%eax, -104(%rbp)
# 33:arg1 = t014 arg2 = t020 
	movl	-80(%rbp), %eax
	movl	-104(%rbp), %edx
	cmpl	%edx, %eax
	jg .L8
# 34:
	jmp .L9
# 35:
	jmp .L10
# 36:
.L8:
	jmp .L9
# 37:
.L10:
	jmp .L9
# 38:
.L6:
	jmp .L5
.LRT1:
	addq	$-104, %rsp
	movq	%rbp, %rsp
	popq	%rbp
	ret
.LFE1:
	.size	bubbleSort, .-bubbleSort
	.globl	printArray
	.type	printArray, @function
printArray:
.LFB2:
	pushq	%rbp
	movq	%rsp, %rbp
	subq	$56, %rsp
	movl	%edi, -4(%rbp)
	movq	%rsi, -12(%rbp)
# 39:res = t021 
.L2:
	movl	$0, -20(%rbp)
# 40:res = i arg1 = t021 
	movl	-20(%rbp), %eax
	movl	%eax, -16(%rbp)
# 41:res = t022 arg1 = t021 
	movl	-20(%rbp), %eax
	movl	%eax, -24(%rbp)
# 42:arg1 = i arg2 = size 
.L13:
	movl	-16(%rbp), %eax
	movl	-4(%rbp), %edx
	cmpl	%edx, %eax
	jl .L11
# 43:
	jmp .L12
# 44:
	jmp .L12
# 45:res = t023 arg1 = i 
.L14:
	movl	-16(%rbp), %eax
	movl	%eax, -28(%rbp)
# 46:res = i arg1 = i 
	movl	-16(%rbp), %eax
	movl	$1, %edx
	addl	%edx, %eax
	movl	%eax, -16(%rbp)
# 47:
	jmp .L13
# 48:res = t024 
.L11:
	movl	$0, -32(%rbp)
# 49:res = t026 arg1 = i 
	movl	-16(%rbp), %eax
	movl	$4, %ecx
	imull	%ecx, %eax
	movl	%eax, -40(%rbp)
# 50:res = t025 arg1 = t024 arg2 = t026 
	movl	-32(%rbp), %eax
	movl	-40(%rbp), %edx
	addl	%edx, %eax
	movl	%eax, -36(%rbp)
# 51:res = t027 arg1 = arr arg2 = t025 
	movq	-12(%rbp), %rdx
	movslq	-36(%rbp), %rax
	addq	%rax, %rdx
	movl	(%rdx), %eax
	movl	%eax, -44(%rbp)
# 52:res = t027 
# 53:res = t028 
	pushq %rbp
	movl	-44(%rbp) , %edi
	call	printInt
	movl	%eax, -48(%rbp)
	addq $0 , %rsp
# 54:
	movq	$.STR0,	%rdi
# 55:res = t029 
	pushq %rbp
	call	printStr
	movl	%eax, -52(%rbp)
	addq $8 , %rsp
# 56:
	jmp .L14
# 57:
.L12:
	movq	$.STR1,	%rdi
# 58:res = t030 
	pushq %rbp
	call	printStr
	movl	%eax, -56(%rbp)
	addq $8 , %rsp
.LRT2:
	addq	$-56, %rsp
	movq	%rbp, %rsp
	popq	%rbp
	ret
.LFE2:
	.size	printArray, .-printArray
	.globl	main
	.type	main, @function
main:
.LFB3:
	pushq	%rbp
	movq	%rsp, %rbp
	subq	$488, %rsp
# 59:res = t031 
	movl	$100, -404(%rbp)
# 60:res = t032 
	movl	$1, -420(%rbp)
# 61:res = err arg1 = t032 
	movl	-420(%rbp), %eax
	movl	%eax, -416(%rbp)
# 62:
	movq	$.STR2,	%rdi
# 63:res = t033 
	pushq %rbp
	call	printStr
	movl	%eax, -424(%rbp)
	addq $8 , %rsp
# 64:res = t034 arg1 = err 
	leaq	-416(%rbp), %rax
	movq	%rax, -428(%rbp)
# 65:res = t034 
# 66:res = t035 
	pushq %rbp
	movq	-428(%rbp), %rdi
	call	readInt
	movl	%eax, -432(%rbp)
	addq $0 , %rsp
# 67:res = n arg1 = t035 
	movl	-432(%rbp), %eax
	movl	%eax, -412(%rbp)
# 68:res = t036 arg1 = t035 
	movl	-432(%rbp), %eax
	movl	%eax, -436(%rbp)
# 69:
	movq	$.STR3,	%rdi
# 70:res = t037 
	pushq %rbp
	call	printStr
	movl	%eax, -440(%rbp)
	addq $8 , %rsp
# 71:res = t038 
	movl	$0, -444(%rbp)
# 72:res = i arg1 = t038 
	movl	-444(%rbp), %eax
	movl	%eax, -408(%rbp)
# 73:res = t039 arg1 = t038 
	movl	-444(%rbp), %eax
	movl	%eax, -448(%rbp)
# 74:arg1 = i arg2 = n 
.L17:
	movl	-408(%rbp), %eax
	movl	-412(%rbp), %edx
	cmpl	%edx, %eax
	jl .L15
# 75:
	jmp .L16
# 76:
	jmp .L16
# 77:res = t040 arg1 = i 
.L18:
	movl	-408(%rbp), %eax
	movl	%eax, -452(%rbp)
# 78:res = i arg1 = i 
	movl	-408(%rbp), %eax
	movl	$1, %edx
	addl	%edx, %eax
	movl	%eax, -408(%rbp)
# 79:
	jmp .L17
# 80:res = t041 
.L15:
	movl	$0, -456(%rbp)
# 81:res = t043 arg1 = i 
	movl	-408(%rbp), %eax
	movl	$4, %ecx
	imull	%ecx, %eax
	movl	%eax, -464(%rbp)
# 82:res = t042 arg1 = t041 arg2 = t043 
	movl	-456(%rbp), %eax
	movl	-464(%rbp), %edx
	addl	%edx, %eax
	movl	%eax, -460(%rbp)
# 83:res = t044 arg1 = err 
	leaq	-416(%rbp), %rax
	movq	%rax, -468(%rbp)
# 84:res = t044 
# 85:res = t045 
	pushq %rbp
	movq	-468(%rbp), %rdi
	call	readInt
	movl	%eax, -472(%rbp)
	addq $0 , %rsp
# 86:res = arr arg1 = t042 arg2 = t045 
	leaq	-400(%rbp), %rdx
	movslq	-460(%rbp), %rax
	addq	%rax, %rdx
	movl	-472(%rbp), %eax
	movl	%eax, (%rdx)
# 87:res = t046 arg1 = t045 
	movl	-472(%rbp), %eax
	movl	%eax, -476(%rbp)
# 88:
	jmp .L18
# 89:
.L16:
	movq	$.STR4,	%rdi
# 90:res = t047 
	pushq %rbp
	call	printStr
	movl	%eax, -480(%rbp)
	addq $8 , %rsp
# 91:res = t048 
	movl	$0, -484(%rbp)
# 92:res = arr 
# 93:res = n 
# 94:
	pushq %rbp
	movl	-412(%rbp) , %edi
	leaq	-400(%rbp), %rsi
	call	printArray
	addq $0 , %rsp
# 95:res = t049 
	movl	$0, -488(%rbp)
.LRT3:
	addq	$-488, %rsp
	movq	%rbp, %rsp
	popq	%rbp
	ret
.LFE3:
	.size	main, .-main
