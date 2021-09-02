####################################
## Suhas Jain
## 19CS30048
## Compilers Laboratory Assignment - 1
####################################

	.file	"ass1.c"                                # name of the source file
	.text											# code starts here 
	.section	.rodata								# denotes read-only data 
	.align 8										# 8 byte boundary alingment 
.LC0:												# label of format string for first printf
	.string	"Enter how many elements you want:"
.LC1:												# label of format string for second printf
	.string	"%d"
.LC2:												# label of format string for scanf
	.string	"Enter the %d elements:\n"
.LC3:												# label of format string for third printf
	.string	"\nEnter the item to search"
.LC4:												# label of format string for forth printf
	.string	"\n%d found in position: %d\n"
	.align 8
.LC5:												# label of format string for fifth printf
	.string	"\nItem is not present in the list."
	.text
	.globl	main									# declares main as a global name 
	.type	main, @function							# declares type of main (as a function)

main:												# start of main function 
.LFB0:
	.cfi_startproc							    # initialize internal structures and emit initial CFI
	endbr64
	pushq	%rbp								# put base pointer (which is rbp) in stack
	.cfi_def_cfa_offset 16 						# modifies the rule for computing CFA, the value of the register remains the same, but OFFSET is set to 16
	.cfi_offset 6, -16							# Previous value of register 6 is saved at offset 16 from CFA
	movq	%rsp, %rbp							# rbp <-- rsp, assign rsp to rbp
	.cfi_def_cfa_register 6						# modifies the rule for computing CFA, the register in the CFA is set to 6
	subq	$432, %rsp							# rsp -= 432, allocate some space (432 bytes) on the stack
	movq	%fs:40, %rax						# get canary 
	movq	%rax, -8(%rbp)						# place on stack 
	xorl	%eax, %eax							# remove canary

# This section represents "printf("Enter how many elements you want:\n");" in the C code
	leaq	.LC0(%rip), %rdi					# loading of address of .LC0(%rip) into rdi, rdi is the first argument of printf, so rdi = &(*(rip + .LC0))
	call	puts@PLT							# calling of printf with rdi as argument 
												
# This section represents "scanf("%d", &n);" in the C code
	leaq	-432(%rbp), %rax					# rax <-- rbp - 432, loads address of M[rbp - 432] into rax
	movq	%rax, %rsi							# rsi <-- rax, rsi (which is &n) is the second argument of scanf
	leaq	.LC1(%rip), %rdi					# load address of .LC1(%rip) into rdi, which is the first argument of scanf (%d), so rdi = &(*(rip + .LC1))
	movl	$0, %eax							# eax <-- 0
	call	__isoc99_scanf@PLT					# call scanf with rdi and rsi as arguments 

# This section represents "printf("Enter the %d elements:\n", n);" in the C code
	movl	-432(%rbp), %eax					# eax <-- M[rbp -432], eax is storing n
	movl	%eax, %esi							# esi <-- eax, esi (which stores n) is the second argument of printf
	leaq	.LC2(%rip), %rdi					# loads address of .LC2(%rip) into rdi, which is the first argument of the function (here printf), so rdi = &(*(rip + .LC2))
	movl	$0, %eax							# printf is a variable argument function, %al is expected to hold the number of vector register, since here printf has integer argument so eax = 0 (al is the first 8 bits of eax)
	call	printf@PLT							# call printf (with rdi and esi as arguments) via Procedure Linkage Table (used to call external procedures whose address isn't known at the time of linking)

# This section represents "for(i = 0; i < n; i++) scanf("%d", &a[i]);" in the C code	
	movl	$0, -424(%rbp)						# M[rbp - 424] <-- 0, eqvivalent to i = 0
	jmp	.L2										# unconditional jump to .L2
.L3:
	leaq	-416(%rbp), %rdx					# rdx <-- rbp - 416, load address of M[rbp - 416] into rdx
	movl	-424(%rbp), %eax					# edx <-- M[rbp - 424], here eax stores i
	cltq										# rax <-- eax, convert long to quad (signed extention)
	salq	$2, %rax							# rax <-- 2-bit arithmetic left shift 
	addq	%rdx, %rax							# rdx <-- rdx + rax (a + 4*i = &a[i])
	movq	%rax, %rsi							# rsi <-- rax, rsi (which is &a[i]) is the second argument of scanf
	leaq	.LC1(%rip), %rdi					# loads address of .LC2(%rip) into rdi, which is the first argument of the function (here scanf), so rdi = &(*(rip + .LC0))
	movl	$0, %eax							# eax <-- 0
	call	__isoc99_scanf@PLT					# call scanf with rdi and rsi as arguments 
	addl	$1, -424(%rbp)						# M[rbp - 424] = M[rbp - 424] + 1, increment i after the loop finishes 
.L2:
	movl	-432(%rbp), %eax					# eax = M[rbp - 432], eax is storing n here 
	cmpl	%eax, -424(%rbp)					# compares M[rbp - 432] with eax, ie. comparision of n with i
	jl	.L3										# jump to .L3 if i < n

# This section represents "inst_sort(a,n);" in the C code	
	movl	-432(%rbp), %edx					# edx <-- M[rbp - 432], edx is storing n
	leaq	-416(%rbp), %rax					# rax <-- rbp - 416, load address of M[rbp - 416] in rax 
	movl	%edx, %esi							# esi <-- edx, esi stores n, esi is the second argument of the function
	movq	%rax, %rdi							# rdi <-- rax, rdi stores a, rdi is the first argument of the function
	call	inst_sort							# call the function inst_sort with rdi and esi as arguments
	
# This section represents "printf("\nEnter the item to search\n");" in the C code	
	leaq	.LC3(%rip), %rdi					# loads address of .LC3(%rip) into rdi, which is the first argument of the function (here printf), so rdi = &(*(rip + .LC3))
	call	puts@PLT							# call printf with rdi as argument

# This section represents "scanf("%d", &item);" in the C code	
	leaq	-428(%rbp), %rax					# rax <-- rbp - 428, load address of M[rbp - 428] in rax, rax now stores &item
	movq	%rax, %rsi							# rsi <-- rax, rsi stores &item, rsi is the second argument of the function
	leaq	.LC1(%rip), %rdi					# loads address of .LC1(%rip) into rdi, which is the first argument of the function (here printf), so rdi = &(*(rip + .LC1))
	movl	$0, %eax							# eax <-- 0
	call	__isoc99_scanf@PLT					# call scanf with rdi and rsi as arguments 

# This section represents "loc=bsearch(a,n,item);" in the C code	
	movl	-428(%rbp), %edx                    # edx <-- M[rbp - 428], edx now stores item, edx is the third argument
	movl	-432(%rbp), %ecx					# ecx <-- M[rbp - 432], ecx now stores n, ecx is the second argument 
	leaq	-416(%rbp), %rax					# rax <-- rbp - 416, loads address of M[rbp - 416] into rax, rax now stores a
	movl	%ecx, %esi							# esi <-- ecx, esi now stores n, esi is the second argument  
	movq	%rax, %rdi							# rdi <-- rax, rdi now stores a, rdi is the first argument 
	call	bsearch								# call bsearch with rdi, esi and edx as arguments
	movl	%eax, -420(%rbp)					# M[rbp - 420] <-- eax, assigning the return value of the function (eax) to M[rbp - 420], which stores the variable loc
	
# This section represents "if (item == a[loc])" in the C code	
	movl	-420(%rbp), %eax					# eax <-- M[rbp - 420], eax stores loc
	cltq										# rax <-- eax, convert long to quad (signed extention)
	movl	-416(%rbp,%rax,4), %edx				# edx = M[rbp + 4*rax - 16], edx stores a[loc]
	movl	-428(%rbp), %eax					# eax <-- M[rbp - 428], eax stores item 
	cmpl	%eax, %edx							# compare eax (item) and edx (a[loc])
	jne	.L4										# jump to .L4, if eax (item) and edx (a[loc]) are equal

# This section represents "printf("\n%d found in position: %d\n", item, loc + 1);" in the C code	
	movl	-420(%rbp), %eax					# eax <-- M[rbp - 420], eax stores loc
	leal	1(%rax), %edx						# edx <-- rax + 1, rax is the 64 bit version of eax thus it also stores loc, so loc + 1 is assigned to edx, which is the third argument of the function
	movl	-428(%rbp), %eax					# eax <-- M[rbp - 428], eax stores item
	movl	%eax, %esi							# esi <-- eax, esi stores item, esi is the second argument of the function
	leaq	.LC4(%rip), %rdi					# loads address of .LC4(%rip) into rdi, which is the first argument of the function (here printf), so rdi = &(*(rip + .LC4))
	movl	$0, %eax							# eax <-- 0
	call	printf@PLT							# call printf with rdi, esi and eax as the three arguments 
	jmp	.L5										# unconditional jump to .L5

.L4:
# This section represents "printf("\nItem is not present in the list.\n");" in the C code	
	leaq	.LC5(%rip), %rdi					# loads address of .LC5(%rip) into rdi, which is the first argument of the function (here printf), so rdi = &(*(rip + .LC5))
	call	puts@PLT							# calls printf with rdi as argument 

.L5:
# This section represents "return 0;" in the C code
	movl	$0, %eax							# eax <-- 0

	movq	-8(%rbp), %rcx						# rcx <-- M[rbp-8]
	subq	%fs:40, %rcx						# subract and check if we get 0 or not, if we get 0, that signifies that there is no buffer overflow
	je	.L7										# jump to .L7 if we get 0 in the previos condition 
	call	__stack_chk_fail@PLT				# if we reach here that indicates a overflow in the stack, it will terminate the function because of stack check failed

.L7:
	leave										# set rsp to rbp and pop top of the stack into rbp
	.cfi_def_cfa 7, 8							# defines a rule for computing CFA as, take address of register 7 and adds an offset 8 to it
	ret											# pop return address of stack and transfer
	.cfi_endproc								# closes its unwind entry previously opened by .cfi_startproc. and emits it to .eh_frame
.LFE0:
	.size	main, .-main						# size of main by taking the difference of start and end pointer
	.globl	inst_sort							# specifies that insertion sort is a global name 
	.type	inst_sort, @function				# specifies the type of insertion sort, which is a function
inst_sort:
.LFB1:
	.cfi_startproc								# initialize internal structures and emit initial CFI
	endbr64
	pushq	%rbp								# put base pointer (which is rbp) in stack
	.cfi_def_cfa_offset 16						# modifies the rule for computing CFA, the value of the register remains the same, but OFFSET is set to 16
	.cfi_offset 6, -16							# Previous value of register 6 is saved at offset 16 from CFA
	movq	%rsp, %rbp							# rbp <-- rsp, assign rsp to rbp
	.cfi_def_cfa_register 6						# modifies the rule for computing CFA, the register in the CFA is set to 6
	movq	%rdi, -24(%rbp)						# M[rbp - 24] <-- rdi, stores num (first argument), which is the array passed in insertion sort
	movl	%esi, -28(%rbp)						# M[rbp - 28] <-- esi, stores n (second argument), which is the size of the array passed in insertion sort

# This section represents "for(j=1;j<n;j++) {" in the C code
	movl	$1, -8(%rbp)						# M[rbp - 8] <-- 1, initialisation of variable j to 1
	jmp	.L9										# unconditional jump to .L9
.L13:

# This section represents "k=num[j];" in the C code
	movl	-8(%rbp), %eax						# eax <-- M[rbp - 8], eax stores the variable j
	cltq										# rax <-- eax, convert long to quad (signed extention)
	leaq	0(,%rax,4), %rdx					# rdx <-- rax*4, rdx stores 4*j
	movq	-24(%rbp), %rax						# rax <-- M[rbp - 24], rax stores the variable num
	addq	%rdx, %rax							# rax <-- rax + rdx, rax stores num + 4*j
	movl	(%rax), %eax						# eax <-- M[rax], eax stores num[j]
	movl	%eax, -4(%rbp)						# M[rbp - 4] <-- eax, M[rbp - 4] was storing k before which is equates to num[j], so M[rbp - 4] now stoes num[j]

# This section represents "for(i=j-1;i>=0 && k<num[i];i--) num[i+1]=num[i];" in the C code
	movl	-8(%rbp), %eax						# eax <-- M[rbp - 8], eax stores the variable j
	subl	$1, %eax							# eax <-- eax - 1, eax now becomes j - 1
	movl	%eax, -12(%rbp)						# M[rbp - 12] <-- eax, M[rbp - 12] stores i, so i is now assigned j - 1 
	jmp	.L10									# unconditional jump to .L10

.L12:
	movl	-12(%rbp), %eax						# eax <-- M[rbp - 12], eax stores i
	cltq										# rax <-- eax, convert long to quad (signed extention)
	leaq	0(,%rax,4), %rdx					# rdx <-- rax*4, rdx stores 4*i
	movq	-24(%rbp), %rax						# rax <-- M[rbp - 24], rax stores num
	addq	%rdx, %rax							# rax <-- rax + rdx, rax now stores num + 4*i
	movl	-12(%rbp), %edx						# edx <-- M[rbp - 12], edx stores i
	movslq	%edx, %rdx							# rdx <-- edx, sign extrention of 32-bit to 64-bit
	addq	$1, %rdx							# rdx <-- rdx + 1, rdx now stores i + 1
	leaq	0(,%rdx,4), %rcx					# rcx <-- rdx*4, rcx stores 4*(i+1)
	movq	-24(%rbp), %rdx						# rdx <-- M[rbp - 24], rdx now stores num
	addq	%rcx, %rdx							# rdx <-- rdx + rcx, rax now stores num + 4*(i+1)
	movl	(%rax), %eax						# eax <-- M[rax], eax now stores num[i+1]
	movl	%eax, (%rdx)						# M[rdx] <-- eax
	subl	$1, -12(%rbp)						# 
.L10:
	cmpl	$0, -12(%rbp)						# compare the value of M[rbp - 12] with 0, comparision of i with 0
	js	.L11									# if i is smaller than 0 then jump to .L11
	movl	-12(%rbp), %eax						# eax <-- M[rbp - 12], eax stores i
	cltq										# rax <-- eax, convert long to quad (signed extention)
	leaq	0(,%rax,4), %rdx					# rdx <-- rax*4, rdx stores 4*i
	movq	-24(%rbp), %rax						# rax <-- M[rbp - 24], rax stores num
	addq	%rdx, %rax							# rax <-- rax + rdx, rax now stores num + 4*i
	movl	(%rax), %eax						# eax <-- M[rax], eax now stores num[i]
	cmpl	%eax, -4(%rbp)						# compare M[rbp - 4] with eax, i.e. comparision of k with num[i]
	jl	.L12									# if k is less than num[i], jump to .L12

.L11:
# This section represents "num[i+1]=k;" in the C code
	movl	-12(%rbp), %eax						# eax <-- M[rbp - 12], eax stores i
	cltq										# rax <-- eax, convert long to quad (signed extention)
	addq	$1, %rax							# rax <-- rax + 1, rdx now stores i + 1
	leaq	0(,%rax,4), %rdx					# rdx <-- rax*4, rdx stores 4*(i+1)
	movq	-24(%rbp), %rax						# rax <-- M[rbp - 24], rax stores num
	addq	%rax, %rdx							# rax <-- rax + rdx, rax now stores num + 4*(i+1)
	movl	-4(%rbp), %eax						# eax <-- M[rbp - 4], eax stores num
	movl	%eax, (%rdx)						# M[rdx] <-- eax, same as num[i+1]=k
	addl	$1, -8(%rbp)						# M[rbp - 8] <-- M[rbp - 8] + 1, increment j by 1, due to j++ (end of the loop)

.L9:
	movl	-8(%rbp), %eax						# eax <-- M[rbp - 8], eax now stores the variable j
	cmpl	-28(%rbp), %eax						# comparision of eax with M[rbp - 28], ie. comparision of j with n
	jl	.L13									# if j is less than n then jump to .L13
	nop											# no-operation, does nothing
	nop											# no-operation, does nothing 
	popq	%rbp								# pops top of the stack into rbp
	.cfi_def_cfa 7, 8							# defines a rule for computing CFA as, take address of register 7 and adds an offset 8 to it
	ret											# return to the previous address 
	.cfi_endproc								# closes its unwind entry previously opened by .cfi_startproc. and emits it to .eh_frame
.LFE1:
	.size	inst_sort, .-inst_sort
	.globl	bsearch
	.type	bsearch, @function	

bsearch:										# start of binary search
.LFB2:											# initialize internal structures and emit initial CFI
	.cfi_startproc
	endbr64
	pushq	%rbp								# put base pointer (which is rbp) in stack
	.cfi_def_cfa_offset 16						# modifies the rule for computing CFA, the value of the register remains the same, but OFFSET is set to 16
	.cfi_offset 6, -16							# Previous value of register 6 is saved at offset 16 from CFA
	movq	%rsp, %rbp							# rbp <-- rsp, assign rsp to rbp
	.cfi_def_cfa_register 6   					# modifies the rule for computing CFA, the register in the CFA is set to 6
	movq	%rdi, -24(%rbp)						# M[rbp - 24] <-- rdi, stores the first argument a (the array in which we are searching)
	movl	%esi, -28(%rbp)						# M[rbp - 28] <-- esi, stores the second argument n (the size of the array a)
	movl	%edx, -32(%rbp)						# M[rbp - 32] <-- edx, stores the third argument item (the value we are searching for)

# This section represents "bottom = 1;" in the C code
	movl	$1, -8(%rbp)						# M[rbp - 8] <-- 1, M[rbp - 12] stores bottom which is initialised to 1

# This section represents "top = n;" in the C code
	movl	-28(%rbp), %eax						# eax <-- M[rbp - 28], eax now stores n
	movl	%eax, -12(%rbp)						# M[rbp - 12] <-- eax, M[rbp - 12] now stores top (value equal to n)

.L18:
# This section represents "mid = (bottom + top) / 2;" in the C code
	movl	-8(%rbp), %edx                      # edx <-- M[rbp - 8], edx stores bottom
	movl	-12(%rbp), %eax						# eax <-- M[rbp - 12], eax stores top
	addl	%edx, %eax							# eax <-- eax + edx, eax now stores bottom + top
	movl	%eax, %edx						    # edx <-- eax, edx stores top + bottom 
	shrl	$31, %edx   						# right shift edx by 31 bits, since edx is a 32 bit register we only get the sign bit
	addl	%edx, %eax                          # eax <-- eax + edx, add 1 to the eax if edx was negative, 0 if positive
	sarl	%eax								# right shift eax by 1, which is same as division by 2
	movl	%eax, -4(%rbp)						# M[rbp - 4] <-- eax, M[rbp - 4] stores mid, so the value of (bottom + top)/2 is assigned to it
	
# This section represents "if (item < a[mid])" in the C code
	movl	-4(%rbp), %eax                		# eax <-- M[rbp - 4], eax now stores mid
	cltq										# rax <-- eax, convert long to quad (signed extention)
	leaq	0(,%rax,4), %rdx					# rdx <-- rax*4, rdx stores 4*mid
	movq	-24(%rbp), %rax						# rax <-- M[rbp - 24], rax stores a
	addq	%rdx, %rax							# rax <-- rax + rdx, rax now stores a + 4*mid
	movl	(%rax), %eax						# eax <-- M[rax], eax now stores a[mid]
	cmpl	%eax, -32(%rbp)						# compare M[rbp - 32] with eax, i.e. comparision of item with a[mid]
	jge	.L15									# if item is greater than equal to a[mid], jump to .L15

# This section represents "top = mid - 1;" in the C code
	movl	-4(%rbp), %eax						# eax <-- M[rbp - 4], eax now stores mid
	subl	$1, %eax							# eax <-- eax - 1, eax now stores mid - 1
	movl	%eax, -12(%rbp)						# M[rbp - 12] <-- eax, M[rbp - 12] now stores top
	jmp	.L16									# unconditional jump to .L16

.L15:
# This section represents "else if (item > a[mid])" in the C code
	movl	-4(%rbp), %eax						# eax <-- M[rbp - 4], eax now stores mid
	cltq										# rax <-- eax, convert long to quad (signed extention)
	leaq	0(,%rax,4), %rdx					# rdx <-- rax*4, rdx stores 4*mid
	movq	-24(%rbp), %rax						# rax <-- M[rbp - 24], rax stores a
	addq	%rdx, %rax							# rax <-- rax + rdx, rax now stores a + 4*mid
	movl	(%rax), %eax						# eax <-- M[rax], eax now stores a[mid]
	cmpl	%eax, -32(%rbp)						# compare M[rbp - 32] with eax, i.e. comparision of item with a[mid]
	jle	.L16									# if item is less than equal to a[mid], jump to .L16

# This section represents "bottom = mid + 1;" in the C code
	movl	-4(%rbp), %eax						# eax <-- M[rbp - 4], eax now stores mid
	addl	$1, %eax							# eax <-- eax + 1, eax stores mid + 1
	movl	%eax, -8(%rbp)						# M[rbp - 8] <-- eax, M[rbp - 8] which is bottom stores mid + 1

.L16:
# This section represents "while (item != a[mid] && bottom <= top);" in the C code
	movl	-4(%rbp), %eax						# eax <-- M[rbp - 4], eax now stores mid
	cltq										# rax <-- eax, convert long to quad (signed extention)
	leaq	0(,%rax,4), %rdx					# rdx <-- rax*4, rdx stores 4*mid
	movq	-24(%rbp), %rax						# rax <-- M[rbp - 24], rax stores a
	addq	%rdx, %rax							# rax <-- rax + rdx, rax now stores a + 4*mid
	movl	(%rax), %eax						# eax <-- M[rax], eax now stores a[mid]
	cmpl	%eax, -32(%rbp)						# compare M[rbp - 32] with eax, i.e. comparision of item with a[mid]
	je	.L17									# if item is equal to a[mid], jump to .L17
	movl	-8(%rbp), %eax                    	# eax <-- M[rbp - 4], eax now stores bottom
	cmpl	-12(%rbp), %eax						# compare M[rbp - 12] with eax, i.e. comparision of bottom with top
	jle	.L18									# if bottom is less than equal to top, jump to .L18

.L17:
# This section represents "return mid;" in the C code
	movl	-4(%rbp), %eax						# eax <-- M[rbp - 4], eax now stores mid
	popq	%rbp								# pops top of the stack into rbp
	.cfi_def_cfa 7, 8							# defines a rule for computing CFA as, take address of register 7 and adds an offset 8 to it
	ret											# return to the control address 
	.cfi_endproc								# closes its unwind entry previously opened by .cfi_startproc. and emits it to .eh_frame
.LFE2:
	.size	bsearch, .-bsearch					# size of the binary search by taking differemce between its start and end pointers
	.ident	"GCC: (Ubuntu 10.3.0-1ubuntu1) 10.3.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	 1f - 0f
	.long	 4f - 1f
	.long	 5
0:
	.string	 "GNU"
1:
	.align 8
	.long	 0xc0000002
	.long	 3f - 2f
2:
	.long	 0x3
3:
	.align 8
4:
