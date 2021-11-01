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
	subq	$28, %rsp
	movq	%rdi, -4(%rbp)
	movq	%rsi, -8(%rbp)
# 0:res = t000 arg1 = xp 
	movq	-8(%rbp), %rax
	movl	(%rax), %eax
	movl	%eax, -16(%rbp)
# 1:res = temp arg1 = t000 
	movl	-16(%rbp), %eax
	movl	%eax, -12(%rbp)
# 2:res = t001 arg1 = yp 
	movq	-4(%rbp), %rax
	movl	(%rax), %eax
	movl	%eax, -20(%rbp)
# 3:res = xp arg1 = t001 
	movq	-8(%rbp), %rax
	movl	-20(%rbp), %edx
	movl	%edx, (%rax)
# 4:res = t002 arg1 = t001 
	movl	-20(%rbp), %eax
	movl	%eax, -24(%rbp)
# 5:res = yp arg1 = temp 
	movq	-4(%rbp), %rax
	movl	-12(%rbp), %edx
	movl	%edx, (%rax)
# 6:res = t003 arg1 = temp 
	movl	-12(%rbp), %eax
	movl	%eax, -28(%rbp)
.LRT0:
	addq	$-28, %rsp
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
	subq	$152, %rsp
	movl	%edi, -4(%rbp)
	movq	%rsi, -12(%rbp)
# 7:res = t004 
	movl	$0, -24(%rbp)
# 8:res = i arg1 = t004 
	movl	-24(%rbp), %eax
	movl	%eax, -16(%rbp)
# 9:res = t005 arg1 = t004 
	movl	-24(%rbp), %eax
	movl	%eax, -28(%rbp)
# 10:res = t006 
.L3:
	movl	$1, -32(%rbp)
# 11:res = t007 arg1 = n arg2 = t006 
	movl	-4(%rbp), %eax
	movl	-32(%rbp), %edx
	subl	%edx, %eax
	movl	%eax, -36(%rbp)
# 12:arg1 = i arg2 = t007 
	movl	-16(%rbp), %eax
	movl	-36(%rbp), %edx
	cmpl	%edx, %eax
	jl .L1
# 13:
	jmp	.LRT1
# 14:
	jmp	.LRT1
# 15:res = t008 arg1 = i 
.L5:
	movl	-16(%rbp), %eax
	movl	%eax, -40(%rbp)
# 16:res = i arg1 = i 
	movl	-16(%rbp), %eax
	movl	$1, %edx
	addl	%edx, %eax
	movl	%eax, -16(%rbp)
# 17:
	jmp .L3
# 18:res = t009 
.L1:
	movl	$0, -44(%rbp)
# 19:res = j arg1 = t009 
	movl	-44(%rbp), %eax
	movl	%eax, -20(%rbp)
# 20:res = t010 arg1 = t009 
	movl	-44(%rbp), %eax
	movl	%eax, -48(%rbp)
# 21:res = t011 arg1 = n arg2 = i 
.L7:
	movl	-4(%rbp), %eax
	movl	-16(%rbp), %edx
	subl	%edx, %eax
	movl	%eax, -52(%rbp)
# 22:res = t012 
	movl	$1, -56(%rbp)
# 23:res = t013 arg1 = t011 arg2 = t012 
	movl	-52(%rbp), %eax
	movl	-56(%rbp), %edx
	subl	%edx, %eax
	movl	%eax, -60(%rbp)
# 24:arg1 = j arg2 = t013 
	movl	-20(%rbp), %eax
	movl	-60(%rbp), %edx
	cmpl	%edx, %eax
	jl .L4
# 25:
	jmp .L5
# 26:
	jmp .L6
# 27:res = t014 arg1 = j 
.L9:
	movl	-20(%rbp), %eax
	movl	%eax, -64(%rbp)
# 28:res = j arg1 = j 
	movl	-20(%rbp), %eax
	movl	$1, %edx
	addl	%edx, %eax
	movl	%eax, -20(%rbp)
# 29:
	jmp .L7
# 30:res = t015 
.L4:
	movl	$0, -68(%rbp)
# 31:res = t017 arg1 = j 
	movl	-20(%rbp), %eax
	movl	$4, %ecx
	imull	%ecx, %eax
	movl	%eax, -76(%rbp)
# 32:res = t016 arg1 = t015 arg2 = t017 
	movl	-68(%rbp), %eax
	movl	-76(%rbp), %edx
	addl	%edx, %eax
	movl	%eax, -72(%rbp)
# 33:res = t018 arg1 = arr arg2 = t016 
	movq	-12(%rbp), %rdx
	movslq	-72(%rbp), %rax
	addq	%rax, %rdx
	movl	(%rdx), %eax
	movl	%eax, -80(%rbp)
# 34:res = t019 
	movl	$0, -84(%rbp)
# 35:res = t020 
	movl	$1, -88(%rbp)
# 36:res = t021 arg1 = j arg2 = t020 
	movl	-20(%rbp), %eax
	movl	-88(%rbp), %edx
	addl	%edx, %eax
	movl	%eax, -92(%rbp)
# 37:res = t023 arg1 = t021 
	movl	-92(%rbp), %eax
	movl	$4, %ecx
	imull	%ecx, %eax
	movl	%eax, -100(%rbp)
# 38:res = t022 arg1 = t019 arg2 = t023 
	movl	-84(%rbp), %eax
	movl	-100(%rbp), %edx
	addl	%edx, %eax
	movl	%eax, -96(%rbp)
# 39:res = t024 arg1 = arr arg2 = t022 
	movq	-12(%rbp), %rdx
	movslq	-96(%rbp), %rax
	addq	%rax, %rdx
	movl	(%rdx), %eax
	movl	%eax, -104(%rbp)
# 40:arg1 = t018 arg2 = t024 
	movl	-80(%rbp), %eax
	movl	-104(%rbp), %edx
	cmpl	%edx, %eax
	jg .L8
# 41:
	jmp .L9
# 42:
	jmp .L10
# 43:res = t025 
.L8:
	movl	$0, -108(%rbp)
# 44:res = t027 arg1 = j 
	movl	-20(%rbp), %eax
	movl	$4, %ecx
	imull	%ecx, %eax
	movl	%eax, -116(%rbp)
# 45:res = t026 arg1 = t025 arg2 = t027 
	movl	-108(%rbp), %eax
	movl	-116(%rbp), %edx
	addl	%edx, %eax
	movl	%eax, -112(%rbp)
# 46:res = t028 arg1 = arr arg2 = t026 
	movq	-12(%rbp), %rdx
	movslq	-112(%rbp), %rax
	addq	%rax, %rdx
	movl	(%rdx), %eax
	movl	%eax, -120(%rbp)
# 47:res = t029 arg1 = t028 
	leaq	-120(%rbp), %rax
	movq	%rax, -124(%rbp)
# 48:res = t030 
	movl	$0, -128(%rbp)
# 49:res = t031 
	movl	$1, -132(%rbp)
# 50:res = t032 arg1 = j arg2 = t031 
	movl	-20(%rbp), %eax
	movl	-132(%rbp), %edx
	addl	%edx, %eax
	movl	%eax, -136(%rbp)
# 51:res = t034 arg1 = t032 
	movl	-136(%rbp), %eax
	movl	$4, %ecx
	imull	%ecx, %eax
	movl	%eax, -144(%rbp)
# 52:res = t033 arg1 = t030 arg2 = t034 
	movl	-128(%rbp), %eax
	movl	-144(%rbp), %edx
	addl	%edx, %eax
	movl	%eax, -140(%rbp)
# 53:res = t035 arg1 = arr arg2 = t033 
	movq	-12(%rbp), %rdx
	movslq	-140(%rbp), %rax
	addq	%rax, %rdx
	movl	(%rdx), %eax
	movl	%eax, -148(%rbp)
# 54:res = t036 arg1 = t035 
	leaq	-148(%rbp), %rax
	movq	%rax, -152(%rbp)
# 55:res = t029 
# 56:res = t036 
# 57:
	pushq %rbp
	movq	-152(%rbp), %rdi
	movq	-124(%rbp), %rsi
	call	swap
	movl	%eax, -152(%rbp)
	addq $0 , %rsp
# 58:
.L10:
	jmp	.LRT1
# 59:
.L6:
	jmp .L9
.LRT1:
	addq	$-152, %rsp
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
# 60:
.L2:
	jmp .L5
# 61:res = t037 
	movl	$0, -20(%rbp)
# 62:res = i arg1 = t037 
	movl	-20(%rbp), %eax
	movl	%eax, -16(%rbp)
# 63:arg1 = t037 
	movl	-20(%rbp), %eax
	movl	%eax, -16(%rbp)
# 64:arg1 = i arg2 = size 
	movl	-16(%rbp), %eax
	movl	-4(%rbp), %edx
	cmpl	%edx, %eax
	jl .L11
# 65:
	jmp .L11
# 66:
.L12:
	jmp	.LRT2
# 67:res = t039 arg1 = i 
	movl	-16(%rbp), %eax
	movl	%eax, -28(%rbp)
# 68:arg1 = i 
	movl	-16(%rbp), %eax
	movl	$1, %edx
	addl	%edx, %eax
	movl	%eax, -28(%rbp)
# 69:
	jmp	.LRT2
# 70:res = t040 
	movl	$0, -32(%rbp)
# 71:res = t042 arg1 = i 
	movl	-16(%rbp), %eax
	movl	$4, %ecx
	imull	%ecx, %eax
	movl	%eax, -40(%rbp)
# 72:res = t041 arg1 = t040 arg2 = t042 
	movl	-32(%rbp), %eax
	movl	-40(%rbp), %edx
	addl	%edx, %eax
	movl	%eax, -36(%rbp)
# 73:res = t043 arg1 = arr arg2 = t041 
	movq	-12(%rbp), %rdx
	movslq	-36(%rbp), %rax
	addq	%rax, %rdx
	movl	(%rdx), %eax
	movl	%eax, -44(%rbp)
# 74:res = t043 
# 75:res = t044 
	pushq %rbp
	movl	-44(%rbp) , %edi
	call	printInt
	movl	%eax, -48(%rbp)
	addq $0 , %rsp
# 76:
	movq	$.STR0,	%rdi
# 77:res = t045 
	pushq %rbp
	call	printStr
	movl	%eax, -52(%rbp)
	addq $8 , %rsp
# 78:
.L11:
	jmp .L12
# 79:
	movq	$.STR1,	%rdi
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
	subq	$492, %rsp
# 80:
	pushq %rbp
	call	printStr
	movl	%eax, -451144977(%rbp)
	addq $8 , %rsp
# 81:res = t047 
	movl	$100, -404(%rbp)
# 82:res = t048 
	movl	$1, -420(%rbp)
# 83:res = err arg1 = t048 
	movl	-420(%rbp), %eax
	movl	%eax, -416(%rbp)
# 84:
	movq	$.STR2,	%rdi
# 85:res = t049 
	pushq %rbp
	call	printStr
	movl	%eax, -424(%rbp)
	addq $8 , %rsp
# 86:res = t050 arg1 = err 
	leaq	-416(%rbp), %rax
	movq	%rax, -428(%rbp)
# 87:res = t050 
# 88:res = t051 
	pushq %rbp
	movq	-428(%rbp), %rdi
	call	readInt
	movl	%eax, -432(%rbp)
	addq $0 , %rsp
# 89:res = n arg1 = t051 
	movl	-432(%rbp), %eax
	movl	%eax, -412(%rbp)
# 90:res = t052 arg1 = t051 
	movl	-432(%rbp), %eax
	movl	%eax, -436(%rbp)
# 91:
	movq	$.STR3,	%rdi
# 92:res = t053 
	pushq %rbp
	call	printStr
	movl	%eax, -440(%rbp)
	addq $8 , %rsp
# 93:res = t054 
	movl	$0, -444(%rbp)
# 94:res = i arg1 = t054 
	movl	-444(%rbp), %eax
	movl	%eax, -408(%rbp)
# 95:arg1 = t054 
	movl	-444(%rbp), %eax
	movl	%eax, -408(%rbp)
# 96:arg1 = i arg2 = n 
	movl	-408(%rbp), %eax
	movl	-412(%rbp), %edx
	cmpl	%edx, %eax
	jl .L13
# 97:
	jmp .L13
# 98:
.L14:
	jmp	.LRT3
# 99:res = t056 arg1 = i 
	movl	-408(%rbp), %eax
	movl	%eax, -452(%rbp)
# 100:arg1 = i 
	movl	-408(%rbp), %eax
	movl	$1, %edx
	addl	%edx, %eax
	movl	%eax, -452(%rbp)
# 101:
	jmp	.LRT3
# 102:res = t057 
	movl	$0, -456(%rbp)
# 103:res = t059 arg1 = i 
	movl	-408(%rbp), %eax
	movl	$4, %ecx
	imull	%ecx, %eax
	movl	%eax, -464(%rbp)
# 104:res = t058 arg1 = t057 arg2 = t059 
	movl	-456(%rbp), %eax
	movl	-464(%rbp), %edx
	addl	%edx, %eax
	movl	%eax, -460(%rbp)
# 105:res = t060 arg1 = err 
	leaq	-416(%rbp), %rax
	movq	%rax, -468(%rbp)
# 106:res = t060 
# 107:res = t061 
	pushq %rbp
	movq	-468(%rbp), %rdi
	call	readInt
	movl	%eax, -472(%rbp)
	addq $0 , %rsp
# 108:res = arr arg1 = t058 arg2 = t061 
	leaq	-400(%rbp), %rdx
	movslq	-460(%rbp), %rax
	addq	%rax, %rdx
	movl	-472(%rbp), %eax
	movl	%eax, (%rdx)
# 109:res = t062 arg1 = t061 
	movl	-472(%rbp), %eax
	movl	%eax, -476(%rbp)
# 110:
.L13:
	jmp .L14
# 111:res = t063 
	movl	$0, -480(%rbp)
# 112:res = arr 
# 113:res = n 
# 114:
	pushq %rbp
	movl	-412(%rbp) , %edi
	leaq	-400(%rbp), %rsi
	call	bubbleSort
	addq $0 , %rsp
# 115:
	movq	$.STR4,	%rdi
# 116:res = t064 
	pushq %rbp
	call	printStr
	movl	%eax, -484(%rbp)
	addq $8 , %rsp
# 117:res = t065 
	movl	$0, -488(%rbp)
# 118:res = arr 
# 119:res = n 
.LRT3:
	addq	$-492, %rsp
	movq	%rbp, %rsp
	popq	%rbp
	ret
.LFE3:
	.size	main, .-main
