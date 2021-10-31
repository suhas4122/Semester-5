# Compiled by Mukul and Rashil on GNU / Linux with Love
# Free Software, Free Society
	.file	"output.s"

.STR0:	.string "Size of array: \n"
.STR1:	.string "Enter the elements of the array in sorted order (separated by newlines): \n"
.STR2:	.string "Search target: \n"
.STR3:	.string "Not found.\n"
.STR4:	.string "Found at position: \n"
.STR5:	.string "\n"
	.text
	.globl	binarySearch
	.type	binarySearch, @function
binarySearch:
.LFB0:
	pushq	%rbp
	movq	%rsp, %rbp
	subq	$112, %rsp
	movl	%edi, -4(%rbp)
	movl	%esi, -8(%rbp)
	movl	%edx, -12(%rbp)
	movl	%ecx, -16(%rbp)
	movq	%r8, -24(%rbp)
# 0:res = t000 
	movl	$0, -36(%rbp)
# 1:res = c arg1 = t000 
	movl	-36(%rbp), %eax
	movl	%eax, -32(%rbp)
# 2:arg1 = l arg2 = u 
	movl	-8(%rbp), %eax
	movl	-4(%rbp), %edx
	cmpl	%edx, %eax
	jg .L1
# 3:
	jmp .L2
# 4:
	jmp .L2
# 5:res = t001 
.L1:
	movl	$1, -40(%rbp)
# 6:res = t002 arg1 = t001 
	movl	-40(%rbp), %eax
	negl	%eax
	movl	%eax, -44(%rbp)
# 7:res = t002 
	movl	-44(%rbp), %eax
	jmp	.LRT0
# 8:
	jmp .L2
# 9:res = t003 arg1 = l arg2 = u 
.L2:
	movl	-8(%rbp), %eax
	movl	-4(%rbp), %edx
	addl	%edx, %eax
	movl	%eax, -48(%rbp)
# 10:res = t004 
	movl	$2, -52(%rbp)
# 11:res = t005 arg1 = t003 arg2 = t004 
	movl	-48(%rbp), %eax
	cltd
	idivl	-52(%rbp), %eax
	movl	%eax, -56(%rbp)
# 12:res = mid arg1 = t005 
	movl	-56(%rbp), %eax
	movl	%eax, -28(%rbp)
# 13:res = t006 arg1 = t005 
	movl	-56(%rbp), %eax
	movl	%eax, -60(%rbp)
# 14:res = t007 
	movl	$0, -68(%rbp)
# 15:res = t009 arg1 = mid 
	movl	-28(%rbp), %eax
	movl	$4, %ecx
	imull	%ecx, %eax
	movl	%eax, -76(%rbp)
# 16:res = t008 arg1 = t007 arg2 = t009 
	movl	-68(%rbp), %eax
	movl	-76(%rbp), %edx
	addl	%edx, %eax
	movl	%eax, -72(%rbp)
# 17:res = t010 arg1 = a arg2 = t008 
	movq	-24(%rbp), %rdx
	movslq	-72(%rbp), %rax
	addq	%rax, %rdx
	movl	(%rdx), %eax
	movl	%eax, -80(%rbp)
# 18:res = t arg1 = t010 
	movl	-80(%rbp), %eax
	movl	%eax, -64(%rbp)
# 19:arg1 = m arg2 = t 
	movl	-12(%rbp), %eax
	movl	-64(%rbp), %edx
	cmpl	%edx, %eax
	jl .L3
# 20:
	jmp .L4
# 21:
	jmp	.LRT0
# 22:res = t011 
.L3:
	movl	$0, -84(%rbp)
# 23:res = t012 
	movl	$1, -88(%rbp)
# 24:res = t013 arg1 = mid arg2 = t012 
	movl	-28(%rbp), %eax
	movl	-88(%rbp), %edx
	subl	%edx, %eax
	movl	%eax, -92(%rbp)
# 25:res = a 
# 26:res = n 
# 27:res = m 
# 28:res = l 
# 29:res = t013 
# 30:res = t014 
	pushq %rbp
	movl	-92(%rbp) , %edi
	movl	-8(%rbp) , %esi
	movl	-12(%rbp) , %edx
	movl	-16(%rbp) , %ecx
	movq	-24(%rbp), %r8
	call	binarySearch
	movl	%eax, -96(%rbp)
	addq $0 , %rsp
# 31:res = t014 
	movl	-96(%rbp), %eax
	jmp	.LRT0
# 32:
	jmp	.LRT0
# 33:arg1 = m arg2 = t 
.L4:
	movl	-12(%rbp), %eax
	movl	-64(%rbp), %edx
	cmpl	%edx, %eax
	jg .L6
# 34:
	jmp .L7
# 35:
	jmp .L8
# 36:res = t015 
.L6:
	movl	$0, -100(%rbp)
# 37:res = t016 
	movl	$1, -104(%rbp)
# 38:res = t017 arg1 = mid arg2 = t016 
	movl	-28(%rbp), %eax
	movl	-104(%rbp), %edx
	addl	%edx, %eax
	movl	%eax, -108(%rbp)
# 39:res = a 
# 40:res = n 
# 41:res = m 
# 42:res = t017 
# 43:res = u 
# 44:res = t018 
	pushq %rbp
	movl	-4(%rbp) , %edi
	movl	-108(%rbp) , %esi
	movl	-12(%rbp) , %edx
	movl	-16(%rbp) , %ecx
	movq	-24(%rbp), %r8
	call	binarySearch
	movl	%eax, -112(%rbp)
	addq $0 , %rsp
# 45:res = t018 
	movl	-112(%rbp), %eax
	jmp	.LRT0
# 46:
	jmp	.LRT0
# 47:res = mid 
.L7:
	movl	-28(%rbp), %eax
	jmp	.LRT0
# 48:
	jmp	.LRT0
# 49:
.L8:
	jmp	.LRT0
.LRT0:
	addq	$-112, %rsp
	movq	%rbp, %rsp
	popq	%rbp
	ret
.LFE0:
	.size	binarySearch, .-binarySearch
	.globl	main
	.type	main, @function
main:
.LFB1:
	pushq	%rbp
	movq	%rsp, %rbp
	subq	$228, %rsp
# 50:res = t019 
.L5:
	movl	$10, -44(%rbp)
# 51:res = t020 
	movl	$1, -76(%rbp)
# 52:res = err arg1 = t020 
	movl	-76(%rbp), %eax
	movl	%eax, -72(%rbp)
# 53:
	movq	$.STR0,	%rdi
# 54:res = t021 
	pushq %rbp
	call	printStr
	movl	%eax, -80(%rbp)
	addq $8 , %rsp
# 55:res = t022 arg1 = err 
	leaq	-72(%rbp), %rax
	movq	%rax, -84(%rbp)
# 56:res = t022 
# 57:res = t023 
	pushq %rbp
	movq	-84(%rbp), %rdi
	call	readInt
	movl	%eax, -88(%rbp)
	addq $0 , %rsp
# 58:res = n arg1 = t023 
	movl	-88(%rbp), %eax
	movl	%eax, -52(%rbp)
# 59:res = t024 arg1 = t023 
	movl	-88(%rbp), %eax
	movl	%eax, -92(%rbp)
# 60:
	movq	$.STR1,	%rdi
# 61:res = t025 
	pushq %rbp
	call	printStr
	movl	%eax, -96(%rbp)
	addq $8 , %rsp
# 62:res = t026 
	movl	$0, -100(%rbp)
# 63:res = i arg1 = t026 
	movl	-100(%rbp), %eax
	movl	%eax, -48(%rbp)
# 64:res = t027 arg1 = t026 
	movl	-100(%rbp), %eax
	movl	%eax, -104(%rbp)
# 65:arg1 = i arg2 = n 
.L11:
	movl	-48(%rbp), %eax
	movl	-52(%rbp), %edx
	cmpl	%edx, %eax
	jl .L9
# 66:
	jmp .L10
# 67:
	jmp .L10
# 68:res = t028 arg1 = i 
.L12:
	movl	-48(%rbp), %eax
	movl	%eax, -108(%rbp)
# 69:res = i arg1 = i 
	movl	-48(%rbp), %eax
	movl	$1, %edx
	addl	%edx, %eax
	movl	%eax, -48(%rbp)
# 70:
	jmp .L11
# 71:res = t029 
.L9:
	movl	$0, -112(%rbp)
# 72:res = t031 arg1 = i 
	movl	-48(%rbp), %eax
	movl	$4, %ecx
	imull	%ecx, %eax
	movl	%eax, -120(%rbp)
# 73:res = t030 arg1 = t029 arg2 = t031 
	movl	-112(%rbp), %eax
	movl	-120(%rbp), %edx
	addl	%edx, %eax
	movl	%eax, -116(%rbp)
# 74:res = t032 arg1 = err 
	leaq	-72(%rbp), %rax
	movq	%rax, -124(%rbp)
# 75:res = t032 
# 76:res = t033 
	pushq %rbp
	movq	-124(%rbp), %rdi
	call	readInt
	movl	%eax, -128(%rbp)
	addq $0 , %rsp
# 77:res = a arg1 = t030 arg2 = t033 
	leaq	-40(%rbp), %rdx
	movslq	-116(%rbp), %rax
	addq	%rax, %rdx
	movl	-128(%rbp), %eax
	movl	%eax, (%rdx)
# 78:res = t034 arg1 = t033 
	movl	-128(%rbp), %eax
	movl	%eax, -132(%rbp)
# 79:
	jmp .L12
# 80:
.L10:
	movq	$.STR2,	%rdi
# 81:res = t035 
	pushq %rbp
	call	printStr
	movl	%eax, -136(%rbp)
	addq $8 , %rsp
# 82:res = t036 arg1 = err 
	leaq	-72(%rbp), %rax
	movq	%rax, -140(%rbp)
# 83:res = t036 
# 84:res = t037 
	pushq %rbp
	movq	-140(%rbp), %rdi
	call	readInt
	movl	%eax, -144(%rbp)
	addq $0 , %rsp
# 85:res = m arg1 = t037 
	movl	-144(%rbp), %eax
	movl	%eax, -56(%rbp)
# 86:res = t038 arg1 = t037 
	movl	-144(%rbp), %eax
	movl	%eax, -148(%rbp)
# 87:res = t039 
	movl	$0, -152(%rbp)
# 88:res = l arg1 = t039 
	movl	-152(%rbp), %eax
	movl	%eax, -64(%rbp)
# 89:res = t040 arg1 = t039 
	movl	-152(%rbp), %eax
	movl	%eax, -156(%rbp)
# 90:res = t041 
	movl	$1, -160(%rbp)
# 91:res = t042 arg1 = n arg2 = t041 
	movl	-52(%rbp), %eax
	movl	-160(%rbp), %edx
	subl	%edx, %eax
	movl	%eax, -164(%rbp)
# 92:res = u arg1 = t042 
	movl	-164(%rbp), %eax
	movl	%eax, -68(%rbp)
# 93:res = t043 arg1 = t042 
	movl	-164(%rbp), %eax
	movl	%eax, -168(%rbp)
# 94:res = t044 
	movl	$0, -172(%rbp)
# 95:res = c arg1 = t044 
	movl	-172(%rbp), %eax
	movl	%eax, -60(%rbp)
# 96:res = t045 arg1 = t044 
	movl	-172(%rbp), %eax
	movl	%eax, -176(%rbp)
# 97:res = t046 
	movl	$0, -180(%rbp)
# 98:res = a 
# 99:res = n 
# 100:res = m 
# 101:res = l 
# 102:res = u 
# 103:res = t047 
	pushq %rbp
	movl	-68(%rbp) , %edi
	movl	-64(%rbp) , %esi
	movl	-56(%rbp) , %edx
	movl	-52(%rbp) , %ecx
	leaq	-40(%rbp), %r8
	call	binarySearch
	movl	%eax, -184(%rbp)
	addq $0 , %rsp
# 104:res = c arg1 = t047 
	movl	-184(%rbp), %eax
	movl	%eax, -60(%rbp)
# 105:res = t048 arg1 = t047 
	movl	-184(%rbp), %eax
	movl	%eax, -188(%rbp)
# 106:res = t049 
	movl	$1, -192(%rbp)
# 107:res = t050 arg1 = t049 
	movl	-192(%rbp), %eax
	negl	%eax
	movl	%eax, -196(%rbp)
# 108:arg1 = c arg2 = t050 
	movl	-60(%rbp), %eax
	movl	-196(%rbp), %edx
	cmpl	%edx, %eax
	je .L13
# 109:
	jmp .L14
# 110:
	jmp .L15
# 111:
.L13:
	movq	$.STR3,	%rdi
# 112:res = t051 
	pushq %rbp
	call	printStr
	movl	%eax, -200(%rbp)
	addq $8 , %rsp
# 113:
	jmp .L15
# 114:
.L14:
	movq	$.STR4,	%rdi
# 115:res = t052 
	pushq %rbp
	call	printStr
	movl	%eax, -204(%rbp)
	addq $8 , %rsp
# 116:res = t053 
	movl	$1, -208(%rbp)
# 117:res = t054 arg1 = c arg2 = t053 
	movl	-60(%rbp), %eax
	movl	-208(%rbp), %edx
	addl	%edx, %eax
	movl	%eax, -212(%rbp)
# 118:res = c arg1 = t054 
	movl	-212(%rbp), %eax
	movl	%eax, -60(%rbp)
# 119:res = t055 arg1 = t054 
	movl	-212(%rbp), %eax
	movl	%eax, -216(%rbp)
# 120:res = c 
# 121:res = t056 
	pushq %rbp
	movl	-60(%rbp) , %edi
	call	printInt
	movl	%eax, -220(%rbp)
	addq $0 , %rsp
# 122:
	movq	$.STR5,	%rdi
# 123:res = t057 
	pushq %rbp
	call	printStr
	movl	%eax, -224(%rbp)
	addq $8 , %rsp
# 124:
	jmp .L15
# 125:res = t058 
.L15:
	movl	$0, -228(%rbp)
# 126:res = t058 
	movl	-228(%rbp), %eax
	jmp	.LRT1
.LRT1:
	addq	$-228, %rsp
	movq	%rbp, %rsp
	popq	%rbp
	ret
.LFE1:
	.size	main, .-main
