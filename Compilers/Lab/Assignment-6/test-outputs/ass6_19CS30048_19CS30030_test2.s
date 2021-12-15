	.file	"output.s"

.STR0:	.string "\n"
.STR1:	.string "\n********************* Bubble Sort ***********************\n"
.STR2:	.string "\nEnter the number of elements\n"
.STR3:	.string "\nEnter the elements of the array one by one i.e. enter a new line after every element: \n"
.STR4:	.string "\nThe elements of the array in ascending order are : \n"
.STR5:	.string "\n**********************************************************\n"
	.text
	.globl	BubbleSort
	.type	BubbleSort, @function
BubbleSort:
.LFB0:
	pushq	%rbp
	movq	%rsp, %rbp
	subq	$192, %rsp
	movl	%edi, -4(%rbp)
	movq	%rsi, -12(%rbp)
# 0:res = t000 
	movl	$0, -28(%rbp)
# 1:res = i arg1 = t000 
	movl	-28(%rbp), %eax
	movl	%eax, -16(%rbp)
# 2:res = t001 arg1 = t000 
	movl	-28(%rbp), %eax
	movl	%eax, -32(%rbp)
# 3:res = t002 
.L3:
	movl	$1, -36(%rbp)
# 4:res = t003 arg1 = n arg2 = t002 
	movl	-4(%rbp), %eax
	movl	-36(%rbp), %edx
	subl	%edx, %eax
	movl	%eax, -40(%rbp)
# 5:arg1 = i arg2 = t003 
	movl	-16(%rbp), %eax
	movl	-40(%rbp), %edx
	cmpl	%edx, %eax
	jl .L1
# 6:
	jmp	.LRT0
# 7:
	jmp	.LRT0
# 8:res = t004 arg1 = i 
.L5:
	movl	-16(%rbp), %eax
	movl	%eax, -44(%rbp)
# 9:res = i arg1 = i 
	movl	-16(%rbp), %eax
	movl	$1, %edx
	addl	%edx, %eax
	movl	%eax, -16(%rbp)
# 10:
	jmp .L3
# 11:res = t005 
.L1:
	movl	$0, -48(%rbp)
# 12:res = j arg1 = t005 
	movl	-48(%rbp), %eax
	movl	%eax, -20(%rbp)
# 13:res = t006 arg1 = t005 
	movl	-48(%rbp), %eax
	movl	%eax, -52(%rbp)
# 14:res = t007 arg1 = n arg2 = i 
.L7:
	movl	-4(%rbp), %eax
	movl	-16(%rbp), %edx
	subl	%edx, %eax
	movl	%eax, -56(%rbp)
# 15:res = t008 
	movl	$1, -60(%rbp)
# 16:res = t009 arg1 = t007 arg2 = t008 
	movl	-56(%rbp), %eax
	movl	-60(%rbp), %edx
	subl	%edx, %eax
	movl	%eax, -64(%rbp)
# 17:arg1 = j arg2 = t009 
	movl	-20(%rbp), %eax
	movl	-64(%rbp), %edx
	cmpl	%edx, %eax
	jl .L4
# 18:
	jmp .L5
# 19:
	jmp .L6
# 20:res = t010 arg1 = j 
.L9:
	movl	-20(%rbp), %eax
	movl	%eax, -68(%rbp)
# 21:res = j arg1 = j 
	movl	-20(%rbp), %eax
	movl	$1, %edx
	addl	%edx, %eax
	movl	%eax, -20(%rbp)
# 22:
	jmp .L7
# 23:res = t011 
.L4:
	movl	$0, -72(%rbp)
# 24:res = t013 arg1 = j 
	movl	-20(%rbp), %eax
	movl	$4, %ecx
	imull	%ecx, %eax
	movl	%eax, -80(%rbp)
# 25:res = t012 arg1 = t011 arg2 = t013 
	movl	-72(%rbp), %eax
	movl	-80(%rbp), %edx
	addl	%edx, %eax
	movl	%eax, -76(%rbp)
# 26:res = t014 arg1 = arr arg2 = t012 
	movq	-12(%rbp), %rdx
	movslq	-76(%rbp), %rax
	addq	%rax, %rdx
	movl	(%rdx), %eax
	movl	%eax, -84(%rbp)
# 27:res = t015 
	movl	$0, -88(%rbp)
# 28:res = t016 
	movl	$1, -92(%rbp)
# 29:res = t017 arg1 = j arg2 = t016 
	movl	-20(%rbp), %eax
	movl	-92(%rbp), %edx
	addl	%edx, %eax
	movl	%eax, -96(%rbp)
# 30:res = t019 arg1 = t017 
	movl	-96(%rbp), %eax
	movl	$4, %ecx
	imull	%ecx, %eax
	movl	%eax, -104(%rbp)
# 31:res = t018 arg1 = t015 arg2 = t019 
	movl	-88(%rbp), %eax
	movl	-104(%rbp), %edx
	addl	%edx, %eax
	movl	%eax, -100(%rbp)
# 32:res = t020 arg1 = arr arg2 = t018 
	movq	-12(%rbp), %rdx
	movslq	-100(%rbp), %rax
	addq	%rax, %rdx
	movl	(%rdx), %eax
	movl	%eax, -108(%rbp)
# 33:arg1 = t014 arg2 = t020 
	movl	-84(%rbp), %eax
	movl	-108(%rbp), %edx
	cmpl	%edx, %eax
	jg .L8
# 34:
	jmp .L9
# 35:
	jmp .L10
# 36:res = t021 
.L8:
	movl	$0, -112(%rbp)
# 37:res = t023 arg1 = j 
	movl	-20(%rbp), %eax
	movl	$4, %ecx
	imull	%ecx, %eax
	movl	%eax, -120(%rbp)
# 38:res = t022 arg1 = t021 arg2 = t023 
	movl	-112(%rbp), %eax
	movl	-120(%rbp), %edx
	addl	%edx, %eax
	movl	%eax, -116(%rbp)
# 39:res = t024 arg1 = arr arg2 = t022 
	movq	-12(%rbp), %rdx
	movslq	-116(%rbp), %rax
	addq	%rax, %rdx
	movl	(%rdx), %eax
	movl	%eax, -124(%rbp)
# 40:res = tmp arg1 = t024 
	movl	-124(%rbp), %eax
	movl	%eax, -24(%rbp)
# 41:res = t025 arg1 = t024 
	movl	-124(%rbp), %eax
	movl	%eax, -128(%rbp)
# 42:res = t026 
	movl	$0, -132(%rbp)
# 43:res = t028 arg1 = j 
	movl	-20(%rbp), %eax
	movl	$4, %ecx
	imull	%ecx, %eax
	movl	%eax, -140(%rbp)
# 44:res = t027 arg1 = t026 arg2 = t028 
	movl	-132(%rbp), %eax
	movl	-140(%rbp), %edx
	addl	%edx, %eax
	movl	%eax, -136(%rbp)
# 45:res = t029 
	movl	$0, -144(%rbp)
# 46:res = t030 
	movl	$1, -148(%rbp)
# 47:res = t031 arg1 = j arg2 = t030 
	movl	-20(%rbp), %eax
	movl	-148(%rbp), %edx
	addl	%edx, %eax
	movl	%eax, -152(%rbp)
# 48:res = t033 arg1 = t031 
	movl	-152(%rbp), %eax
	movl	$4, %ecx
	imull	%ecx, %eax
	movl	%eax, -160(%rbp)
# 49:res = t032 arg1 = t029 arg2 = t033 
	movl	-144(%rbp), %eax
	movl	-160(%rbp), %edx
	addl	%edx, %eax
	movl	%eax, -156(%rbp)
# 50:res = t034 arg1 = arr arg2 = t032 
	movq	-12(%rbp), %rdx
	movslq	-156(%rbp), %rax
	addq	%rax, %rdx
	movl	(%rdx), %eax
	movl	%eax, -164(%rbp)
# 51:res = arr arg1 = t027 arg2 = t034 
	movq	-12(%rbp), %rdx
	movslq	-136(%rbp), %rax
	addq	%rax, %rdx
	movl	-164(%rbp), %eax
	movl	%eax, (%rdx)
# 52:res = t035 arg1 = t034 
	movl	-164(%rbp), %eax
	movl	%eax, -168(%rbp)
# 53:res = t036 
	movl	$0, -172(%rbp)
# 54:res = t037 
	movl	$1, -176(%rbp)
# 55:res = t038 arg1 = j arg2 = t037 
	movl	-20(%rbp), %eax
	movl	-176(%rbp), %edx
	addl	%edx, %eax
	movl	%eax, -180(%rbp)
# 56:res = t040 arg1 = t038 
	movl	-180(%rbp), %eax
	movl	$4, %ecx
	imull	%ecx, %eax
	movl	%eax, -188(%rbp)
# 57:res = t039 arg1 = t036 arg2 = t040 
	movl	-172(%rbp), %eax
	movl	-188(%rbp), %edx
	addl	%edx, %eax
	movl	%eax, -184(%rbp)
# 58:res = arr arg1 = t039 arg2 = tmp 
	movq	-12(%rbp), %rdx
	movslq	-184(%rbp), %rax
	addq	%rax, %rdx
	movl	-24(%rbp), %eax
	movl	%eax, (%rdx)
# 59:res = t041 arg1 = tmp 
	movl	-24(%rbp), %eax
	movl	%eax, -192(%rbp)
# 60:
	jmp .L9
# 61:
.L10:
	jmp .L9
# 62:
.L6:
	jmp .L5
.LRT0:
	addq	$-192, %rsp
	movq	%rbp, %rsp
	popq	%rbp
	ret
.LFE0:
	.size	BubbleSort, .-BubbleSort
	.globl	PrintArray
	.type	PrintArray, @function
PrintArray:
.LFB1:
	pushq	%rbp
	movq	%rsp, %rbp
	subq	$52, %rsp
	movl	%edi, -4(%rbp)
	movq	%rsi, -12(%rbp)
# 63:res = t042 
.L2:
	movl	$0, -20(%rbp)
# 64:res = i arg1 = t042 
	movl	-20(%rbp), %eax
	movl	%eax, -16(%rbp)
# 65:res = t043 arg1 = t042 
	movl	-20(%rbp), %eax
	movl	%eax, -24(%rbp)
# 66:arg1 = i arg2 = size 
.L13:
	movl	-16(%rbp), %eax
	movl	-4(%rbp), %edx
	cmpl	%edx, %eax
	jl .L11
# 67:
	jmp	.LRT1
# 68:
	jmp	.LRT1
# 69:res = t044 arg1 = i 
.L14:
	movl	-16(%rbp), %eax
	movl	%eax, -28(%rbp)
# 70:res = i arg1 = i 
	movl	-16(%rbp), %eax
	movl	$1, %edx
	addl	%edx, %eax
	movl	%eax, -16(%rbp)
# 71:
	jmp .L13
# 72:res = t045 
.L11:
	movl	$0, -32(%rbp)
# 73:res = t047 arg1 = i 
	movl	-16(%rbp), %eax
	movl	$4, %ecx
	imull	%ecx, %eax
	movl	%eax, -40(%rbp)
# 74:res = t046 arg1 = t045 arg2 = t047 
	movl	-32(%rbp), %eax
	movl	-40(%rbp), %edx
	addl	%edx, %eax
	movl	%eax, -36(%rbp)
# 75:res = t048 arg1 = arr arg2 = t046 
	movq	-12(%rbp), %rdx
	movslq	-36(%rbp), %rax
	addq	%rax, %rdx
	movl	(%rdx), %eax
	movl	%eax, -44(%rbp)
# 76:res = t048 
# 77:res = t049 
	pushq %rbp
	movl	-44(%rbp) , %edi
	call	printInt
	movl	%eax, -48(%rbp)
	addq $0 , %rsp
# 78:
	movq	$.STR0,	%rdi
# 79:res = t050 
	pushq %rbp
	call	printStr
	movl	%eax, -52(%rbp)
	addq $0 , %rsp
# 80:
	jmp .L14
.LRT1:
	addq	$-52, %rsp
	movq	%rbp, %rsp
	popq	%rbp
	ret
.LFE1:
	.size	PrintArray, .-PrintArray
	.globl	main
	.type	main, @function
main:
.LFB2:
	pushq	%rbp
	movq	%rsp, %rbp
	subq	$508, %rsp
# 81:res = t051 
.L12:
	movl	$100, -404(%rbp)
# 82:res = t052 
	movl	$1, -420(%rbp)
# 83:res = err arg1 = t052 
	movl	-420(%rbp), %eax
	movl	%eax, -416(%rbp)
# 84:
	movq	$.STR1,	%rdi
# 85:res = t053 
	pushq %rbp
	call	printStr
	movl	%eax, -424(%rbp)
	addq $0 , %rsp
# 86:
	movq	$.STR2,	%rdi
# 87:res = t054 
	pushq %rbp
	call	printStr
	movl	%eax, -428(%rbp)
	addq $0 , %rsp
# 88:res = t055 arg1 = err 
	leaq	-416(%rbp), %rax
	movq	%rax, -436(%rbp)
# 89:res = t055 
# 90:res = t056 
	pushq %rbp
	movq	-436(%rbp), %rdi
	call	readInt
	movl	%eax, -440(%rbp)
	addq $0 , %rsp
# 91:res = n arg1 = t056 
	movl	-440(%rbp), %eax
	movl	%eax, -412(%rbp)
# 92:res = t057 arg1 = t056 
	movl	-440(%rbp), %eax
	movl	%eax, -444(%rbp)
# 93:
	movq	$.STR3,	%rdi
# 94:res = t058 
	pushq %rbp
	call	printStr
	movl	%eax, -448(%rbp)
	addq $0 , %rsp
# 95:res = t059 
	movl	$0, -452(%rbp)
# 96:res = i arg1 = t059 
	movl	-452(%rbp), %eax
	movl	%eax, -408(%rbp)
# 97:res = t060 arg1 = t059 
	movl	-452(%rbp), %eax
	movl	%eax, -456(%rbp)
# 98:arg1 = i arg2 = n 
.L17:
	movl	-408(%rbp), %eax
	movl	-412(%rbp), %edx
	cmpl	%edx, %eax
	jl .L15
# 99:
	jmp .L16
# 100:
	jmp .L16
# 101:res = t061 arg1 = i 
.L18:
	movl	-408(%rbp), %eax
	movl	%eax, -460(%rbp)
# 102:res = i arg1 = i 
	movl	-408(%rbp), %eax
	movl	$1, %edx
	addl	%edx, %eax
	movl	%eax, -408(%rbp)
# 103:
	jmp .L17
# 104:res = t062 
.L15:
	movl	$0, -464(%rbp)
# 105:res = t064 arg1 = i 
	movl	-408(%rbp), %eax
	movl	$4, %ecx
	imull	%ecx, %eax
	movl	%eax, -472(%rbp)
# 106:res = t063 arg1 = t062 arg2 = t064 
	movl	-464(%rbp), %eax
	movl	-472(%rbp), %edx
	addl	%edx, %eax
	movl	%eax, -468(%rbp)
# 107:res = t065 arg1 = err 
	leaq	-416(%rbp), %rax
	movq	%rax, -480(%rbp)
# 108:res = t065 
# 109:res = t066 
	pushq %rbp
	movq	-480(%rbp), %rdi
	call	readInt
	movl	%eax, -484(%rbp)
	addq $0 , %rsp
# 110:res = arr arg1 = t063 arg2 = t066 
	leaq	-400(%rbp), %rdx
	movslq	-468(%rbp), %rax
	addq	%rax, %rdx
	movl	-484(%rbp), %eax
	movl	%eax, (%rdx)
# 111:res = t067 arg1 = t066 
	movl	-484(%rbp), %eax
	movl	%eax, -488(%rbp)
# 112:
	jmp .L18
# 113:res = t068 
.L16:
	movl	$0, -492(%rbp)
# 114:res = arr 
# 115:res = n 
# 116:
	pushq %rbp
	movl	-412(%rbp) , %edi
	leaq	-400(%rbp), %rsi
	call	BubbleSort
	addq $0 , %rsp
# 117:
	movq	$.STR4,	%rdi
# 118:res = t069 
	pushq %rbp
	call	printStr
	movl	%eax, -496(%rbp)
	addq $0 , %rsp
# 119:res = t070 
	movl	$0, -500(%rbp)
# 120:res = arr 
# 121:res = n 
# 122:
	pushq %rbp
	movl	-412(%rbp) , %edi
	leaq	-400(%rbp), %rsi
	call	PrintArray
	addq $0 , %rsp
# 123:
	movq	$.STR5,	%rdi
# 124:res = t071 
	pushq %rbp
	call	printStr
	movl	%eax, -504(%rbp)
	addq $0 , %rsp
.LRT2:
	addq	$-508, %rsp
	movq	%rbp, %rsp
	popq	%rbp
	ret
.LFE2:
	.size	main, .-main
