	.arch msp430g2553
	.p2align 1,0

	#include "msp430.h"
	
	.data
	blink:	.byte 2
	num:	.byte 0
	secCount:	.byte 0
	
	.text

	.global led_blink_as
	.extern switch_interrupt_handler
	
led_blink_as:
	add.b #1, &secCount
	cmp.b #125, &secCount
	jl led_blink_end
	mov.b #0, &secCount
	xor.b #1, P1OUT
	add.b #1, &num
	cmp.b &blink, &num
	jl led_blink_end
	add.b #2, &blink
	mov.b #0, &num
	call #switch_interrupt_handler
	cmp.b #10, &blink
	jnc led_blink_end
	mov.b #2, &blink
led_blink_end:
	ret
