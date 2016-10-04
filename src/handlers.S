.code64

#define newHandler(n) \
handler##n:           \
	pushq $0;         \
	pushq $n;         \
	jmp handling      \


#define newErrHandler(n) \
handler##n:              \
	pushq $n;            \
	jmp handling         \


newHandler(0)
newHandler(1)
newHandler(2)
newHandler(3)
newHandler(4)
newHandler(5)
newHandler(6)
newHandler(7)
newErrHandler(8)
newHandler(9)
newErrHandler(10)
newErrHandler(11)
newErrHandler(12)
newErrHandler(13)
newErrHandler(14)
newHandler(15)
newHandler(16)
newErrHandler(17)
newHandler(18)
newHandler(19)
newHandler(20)
newHandler(21)
newHandler(22)
newHandler(23)
newHandler(24)
newHandler(25)
newHandler(26)
newHandler(27)
newHandler(28)
newHandler(29)
newHandler(30)
newHandler(31)
newHandler(32)
newHandler(33)
newHandler(34)
newHandler(35)
newHandler(36)
newHandler(37)
newHandler(38)
newHandler(39)
newHandler(40)
newHandler(41)
newHandler(42)
newHandler(43)
newHandler(44)
newHandler(45)
newHandler(46)
newHandler(47)


.global handlers

handlers:
	.quad handler0
	.quad handler1
	.quad handler2
	.quad handler3
	.quad handler4
	.quad handler5
	.quad handler6
	.quad handler7
	.quad handler8
	.quad handler9
	.quad handler10
	.quad handler11
	.quad handler12
	.quad handler13
	.quad handler14
	.quad handler15
	.quad handler16
	.quad handler17
	.quad handler18
	.quad handler19
	.quad handler20
	.quad handler21
	.quad handler22
	.quad handler23
	.quad handler24
	.quad handler25
	.quad handler26
	.quad handler27
	.quad handler28
	.quad handler29
	.quad handler30
	.quad handler31
	.quad handler32
	.quad handler33
	.quad handler34
	.quad handler35
	.quad handler36
	.quad handler37
	.quad handler38
	.quad handler39
	.quad handler40
	.quad handler41
	.quad handler42
	.quad handler43
	.quad handler44
	.quad handler45
	.quad handler46
	.quad handler47


handling:
	pushq %rdi

	movq 8(%rsp), %rdi 

	pushq %rax
	pushq %rbx
	pushq %rcx
	pushq %rdx
	pushq %rbp
	pushq %rsi
	pushq %r8
	pushq %r9
	pushq %r10
	pushq %r11
	pushq %r12
	pushq %r13
	pushq %r14
	pushq %r15

    cld
	call handle

	popq %r15
	popq %r14
	popq %r13
	popq %r12
	popq %r11
	popq %r10
	popq %r9
	popq %r8
	popq %rsi
	popq %rbp
	popq %rdx
	popq %rcx
	popq %rbx
	popq %rax
	popq %rdi

	addq $16, %rsp
	iretq