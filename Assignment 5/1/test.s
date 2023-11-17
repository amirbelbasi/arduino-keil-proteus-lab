PIO_PER equ  0x400E0E00
PIO_SODR equ 0x400E0E30
PIO_CODR equ 0x400E0E34
PIO_OER equ  0x400E0E10
PIO_PDSR equ 0x400E0E3c
PIO_ISR equ  0x400E0E4c
	
		area mycode, code, readonly
		export __main
			entry
			
__main
	bl enable_pio1
	bl enable_pio2
	bl enable_pio3
	
blink
	ldr r1, =PIO_ISR
	ldr r2, [r1]
	cmp r2, #2_100000
	beq main_loop
	b blink
	
stop_blink
	bl led_off1
	bl led_off2
	bl led_off3
	b blink
	
main_loop
	ldr r1, =PIO_ISR
	ldr r2, [r1]
	cmp r2, #2_1000000
	beq stop_blink	
	bl led

enable_pio1
	mov r4, #2_1
	ldr r5, =PIO_PER
	str r4, [r5]
	ldr r5, =PIO_OER
	str r4, [r5]
	bx lr

enable_pio2
	mov r4, #2_10
	ldr r5, =PIO_PER
	str r4, [r5]
	ldr r5, =PIO_OER
	str r4, [r5]
	bx lr

enable_pio3
	mov r4, #2_100
	ldr r5, =PIO_PER
	str r4, [r5]
	ldr r5, =PIO_OER
	str r4, [r5]
	bx lr
	
led
	bl led_on1
	bl delay
	bl led_off1
	bl led_on2
	bl delay
	bl led_on1
	bl delay
	bl led_off1
	ldr r1, =PIO_ISR
	ldr r2, [r1]
	cmp r2, #2_1000000
	beq stop_blink
	bl delay
	bl led_on1
	bl led_off2
	bl led_on3
	bl delay
	bl led_off1
	bl delay
	bl led_on1
	bl delay
	bl led_off1
	ldr r1, =PIO_ISR
	ldr r2, [r1]
	cmp r2, #2_1000000
	beq stop_blink
	bl led_on2
	bl delay
	bl led_on1
	bl delay
	bl led_off1
	bl delay
	bl led_off3
	bl led_off2
	ldr r1, =PIO_ISR
	ldr r2, [r1]
	cmp r2, #2_1000000
	beq stop_blink
	bne led
	bx lr
	
led_on1
	mov r4, #2_1
	ldr r5, =PIO_SODR
	str r4, [r5]
	bx lr

led_on2
	mov r4, #2_10
	ldr r5, =PIO_SODR
	str r4, [r5]
	bx lr

led_on3
	mov r4, #2_100
	ldr r5, =PIO_SODR
	str r4, [r5]
	bx lr

led_off1
	mov r4, #2_1
	ldr r5, =PIO_CODR
	str r4, [r5]
	bx lr

led_off2
	mov r4, #2_10
	ldr r5, =PIO_CODR
	str r4, [r5]
	bx lr

led_off3
	mov r4, #2_100
	ldr r5, =PIO_CODR
	str r4, [r5]
	bx lr

delay
	mov r6, #0
	ldr r7, =0x00C0000
	
delay_loop
	add r6, r6, #1
	cmp r6, r7
	bne delay_loop
	bx lr