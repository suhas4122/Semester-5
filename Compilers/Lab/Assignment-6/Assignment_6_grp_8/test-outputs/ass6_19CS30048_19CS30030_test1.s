	.file	"output.s"

.STR0:	.string "\n************************ Average *********************\n"
.STR1:	.string "\nEnter the number of elements in array\n"
.STR2:	.string "\nEnter the elements of the array one by one i.e. enter a new line after every element: \n"
.STR3:	.string "\nThe Average of all elements in the array is: \n"
.STR4:	.string "\n\n*******************************************************\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	pushq	%rbp
	movq	%rsp, %rbp
	subq	$552, %rsp
# 0:res = t000 
	movl	$100, -404(%rbp)
# 1:res = t001 
	movl	$0, -424(%rbp)
# 2:res = sum arg1 = t001 
	movl	-424(%rbp), %eax
	movl	%eax, -420(%rbp)
# 3:res = t002 
	movl	$1, -432(%rbp)
# 4:res = err arg1 = t002 
	movl	-432(%rbp), %eax
	movl	%eax, -428(%rbp)
# 5:
	movq	$.STR0,	%rdi
# 6:res = t003 
	pushq %rbp
	call	printStr
	movl	%eax, -436(%rbp)
	addq $0 , %rsp
# 7:
	movq	$.STR1,	%rdi
# 8:res = t004 
	pushq %rbp
	call	printStr
	movl	%eax, -440(%rbp)
	addq $0 , %rsp
# 9:res = t005 arg1 = err 
	leaq	-428(%rbp), %rax
	movq	%rax, -448(%rbp)
# 10:res = t005 
# 11:res = t006 
	pushq %rbp
	movq	-448(%rbp), %rdi
	call	readInt
	movl	%eax, -452(%rbp)
	addq $0 , %rsp
# 12:res = n arg1 = t006 
	movl	-452(%rbp), %eax
	movl	%eax, -408(%rbp)
# 13:res = t007 arg1 = t006 
	movl	-452(%rbp), %eax
	movl	%eax, -456(%rbp)
# 14:
	movq	$.STR2,	%rdi
# 15:res = t008 
	pushq %rbp
	call	printStr
	movl	%eax, -460(%rbp)
	addq $0 , %rsp
# 16:res = t009 
	movl	$0, -464(%rbp)
# 17:res = i arg1 = t009 
	movl	-464(%rbp), %eax
	movl	%eax, -416(%rbp)
# 18:res = t010 arg1 = t009 
	movl	-464(%rbp), %eax
	movl	%eax, -468(%rbp)
# 19:arg1 = i arg2 = n 
.L3:
	movl	-416(%rbp), %eax
	movl	-408(%rbp), %edx
	cmpl	%edx, %eax
	jl .L1
# 20:
	jmp .L2
# 21:
	jmp .L2
# 22:res = t011 arg1 = i 
.L4:
	movl	-416(%rbp), %eax
	movl	%eax, -472(%rbp)
# 23:res = i arg1 = i 
	movl	-416(%rbp), %eax
	movl	$1, %edx
	addl	%edx, %eax
	movl	%eax, -416(%rbp)
# 24:
	jmp .L3
# 25:res = t012 
.L1:
	movl	$0, -476(%rbp)
# 26:res = t014 arg1 = i 
	movl	-416(%rbp), %eax
	movl	$4, %ecx
	imull	%ecx, %eax
	movl	%eax, -484(%rbp)
# 27:res = t013 arg1 = t012 arg2 = t014 
	movl	-476(%rbp), %eax
	movl	-484(%rbp), %edx
	addl	%edx, %eax
	movl	%eax, -480(%rbp)
# 28:res = t015 arg1 = err 
	leaq	-428(%rbp), %rax
	movq	%rax, -492(%rbp)
# 29:res = t015 
# 30:res = t016 
	pushq %rbp
	movq	-492(%rbp), %rdi
	call	readInt
	movl	%eax, -496(%rbp)
	addq $0 , %rsp
# 31:res = x arg1 = t013 arg2 = t016 
	leaq	-400(%rbp), %rdx
	movslq	-480(%rbp), %rax
	addq	%rax, %rdx
	movl	-496(%rbp), %eax
	movl	%eax, (%rdx)
# 32:res = t017 arg1 = t016 
	movl	-496(%rbp), %eax
	movl	%eax, -500(%rbp)
# 33:res = t018 
	movl	$0, -504(%rbp)
# 34:res = t020 arg1 = i 
	movl	-416(%rbp), %eax
	movl	$4, %ecx
	imull	%ecx, %eax
	movl	%eax, -512(%rbp)
# 35:res = t019 arg1 = t018 arg2 = t020 
	movl	-504(%rbp), %eax
	movl	-512(%rbp), %edx
	addl	%edx, %eax
	movl	%eax, -508(%rbp)
# 36:res = t021 arg1 = x arg2 = t019 
	leaq	-400(%rbp), %rdx
	movslq	-508(%rbp), %rax
	addq	%rax, %rdx
	movl	(%rdx), %eax
	movl	%eax, -516(%rbp)
# 37:res = t022 arg1 = sum arg2 = t021 
	movl	-420(%rbp), %eax
	movl	-516(%rbp), %edx
	addl	%edx, %eax
	movl	%eax, -520(%rbp)
# 38:res = sum arg1 = t022 
	movl	-520(%rbp), %eax
	movl	%eax, -420(%rbp)
# 39:res = t023 arg1 = t022 
	movl	-520(%rbp), %eax
	movl	%eax, -524(%rbp)
# 40:
	jmp .L4
# 41:res = t024 arg1 = sum arg2 = n 
.L2:
	movl	-420(%rbp), %eax
	cltd
	idivl	-408(%rbp), %eax
	movl	%eax, -532(%rbp)
# 42:res = len arg1 = t024 
	movl	-532(%rbp), %eax
	movl	%eax, -528(%rbp)
# 43:res = t025 arg1 = t024 
	movl	-532(%rbp), %eax
	movl	%eax, -536(%rbp)
# 44:
	movq	$.STR3,	%rdi
# 45:res = t026 
	pushq %rbp
	call	printStr
	movl	%eax, -540(%rbp)
	addq $0 , %rsp
# 46:res = len 
# 47:res = t027 
	pushq %rbp
	movl	-528(%rbp) , %edi
	call	printInt
	movl	%eax, -544(%rbp)
	addq $0 , %rsp
# 48:
	movq	$.STR4,	%rdi
# 49:res = t028 
	pushq %rbp
	call	printStr
	movl	%eax, -548(%rbp)
	addq $0 , %rsp
# 50:res = t029 
	movl	$0, -552(%rbp)
# 51:res = t029 
	movl	-552(%rbp), %eax
	jmp	.LRT0
.LRT0:
	addq	$-552, %rsp
	movq	%rbp, %rsp
	popq	%rbp
	ret
.LFE0:
	.size	main, .-main
