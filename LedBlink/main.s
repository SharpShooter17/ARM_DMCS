	.file	"main.c"
	.text
	.align	2
	.global	dbgu_print_ascii
	.type	dbgu_print_ascii, %function
dbgu_print_ascii:
	@ args = 0, pretend = 0, frame = 4
	@ frame_needed = 1, uses_anonymous_args = 0
	mov	ip, sp
	stmfd	sp!, {fp, ip, lr, pc}
	sub	fp, ip, #4
	sub	sp, sp, #4
	str	r0, [fp, #-16]
	ldmfd	sp, {r3, fp, sp, pc}
	.size	dbgu_print_ascii, .-dbgu_print_ascii
	.align	2
	.global	sleep
	.type	sleep, %function
sleep:
	@ args = 0, pretend = 0, frame = 8
	@ frame_needed = 1, uses_anonymous_args = 0
	mov	ip, sp
	stmfd	sp!, {fp, ip, lr, pc}
	sub	fp, ip, #4
	sub	sp, sp, #8
	str	r0, [fp, #-20]
	mov	r3, #0
	str	r3, [fp, #-16]
	mov	r3, #0
	str	r3, [fp, #-16]
	b	.L4
.L5:
	ldr	r3, [fp, #-16]
	add	r3, r3, #1
	str	r3, [fp, #-16]
.L4:
	ldr	r1, [fp, #-20]
	mov	r3, r1
	mov	r3, r3, asl #3
	mov	r2, r3, asl #5
	rsb	r2, r3, r2
	mov	r3, r2, asl #6
	rsb	r3, r2, r3
	add	r3, r3, r1
	mov	r3, r3, asl #6
	mov	r2, r3
	ldr	r3, [fp, #-16]
	cmp	r2, r3
	bgt	.L5
	sub	sp, fp, #12
	ldmfd	sp, {fp, sp, pc}
	.size	sleep, .-sleep
	.align	2
	.global	main
	.type	main, %function
main:
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 1, uses_anonymous_args = 0
	mov	ip, sp
	stmfd	sp!, {fp, ip, lr, pc}
	sub	fp, ip, #4
	mov	r3, #-1610612736
	mov	r3, r3, asr #19
	mov	r2, #256
	str	r2, [r3, #0]
	mov	r3, #0
	sub	r3, r3, #3056
	mov	r2, #256
	str	r2, [r3, #0]
.L8:
	mvn	r3, #3008
	sub	r3, r3, #11
	mov	r2, #256
	str	r2, [r3, #0]
	mov	r0, #5
	bl	sleep
	mov	r3, #0
	sub	r3, r3, #3024
	mov	r2, #256
	str	r2, [r3, #0]
	mov	r0, #5
	bl	sleep
	b	.L8
	.size	main, .-main
	.ident	"GCC: (GNU) 4.3.2"
