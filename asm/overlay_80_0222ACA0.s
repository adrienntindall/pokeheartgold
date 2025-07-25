	.include "asm/macros.inc"
	.include "overlay_80_0222ACA0.inc"
	.include "global.inc"

    .text

	thumb_func_start ov80_0222ACA0
ov80_0222ACA0: ; 0x0222ACA0
	push {r3, lr}
	cmp r1, #0xd
	bhi _0222AD5A
	add r1, r1, r1
	add r1, pc
	ldrh r1, [r1, #6]
	lsl r1, r1, #0x10
	asr r1, r1, #0x10
	add pc, r1
_0222ACB2: ; jump table
	.short _0222ACCE - _0222ACB2 - 2 ; case 0
	.short _0222ACD8 - _0222ACB2 - 2 ; case 1
	.short _0222ACE2 - _0222ACB2 - 2 ; case 2
	.short _0222ACEC - _0222ACB2 - 2 ; case 3
	.short _0222ACF6 - _0222ACB2 - 2 ; case 4
	.short _0222AD00 - _0222ACB2 - 2 ; case 5
	.short _0222AD0A - _0222ACB2 - 2 ; case 6
	.short _0222AD14 - _0222ACB2 - 2 ; case 7
	.short _0222AD1E - _0222ACB2 - 2 ; case 8
	.short _0222AD28 - _0222ACB2 - 2 ; case 9
	.short _0222AD32 - _0222ACB2 - 2 ; case 10
	.short _0222AD3C - _0222ACB2 - 2 ; case 11
	.short _0222AD46 - _0222ACB2 - 2 ; case 12
	.short _0222AD50 - _0222ACB2 - 2 ; case 13
_0222ACCE:
	mov r1, #0x28
	mul r1, r0
	ldr r0, _0222AD64 ; =ov80_0223B724
	ldr r0, [r0, r1]
	pop {r3, pc}
_0222ACD8:
	mov r1, #0x28
	mul r1, r0
	ldr r0, _0222AD68 ; =ov80_0223B730
	ldrh r0, [r0, r1]
	pop {r3, pc}
_0222ACE2:
	mov r1, #0x28
	mul r1, r0
	ldr r0, _0222AD6C ; =ov80_0223B732
	ldrh r0, [r0, r1]
	pop {r3, pc}
_0222ACEC:
	mov r1, #0x28
	mul r1, r0
	ldr r0, _0222AD70 ; =ov80_0223B734
	ldrh r0, [r0, r1]
	pop {r3, pc}
_0222ACF6:
	mov r1, #0x28
	mul r1, r0
	ldr r0, _0222AD74 ; =ov80_0223B736
	ldrh r0, [r0, r1]
	pop {r3, pc}
_0222AD00:
	mov r1, #0x28
	mul r1, r0
	ldr r0, _0222AD78 ; =ov80_0223B738
	ldrh r0, [r0, r1]
	pop {r3, pc}
_0222AD0A:
	mov r1, #0x28
	mul r1, r0
	ldr r0, _0222AD7C ; =ov80_0223B73A
	ldrh r0, [r0, r1]
	pop {r3, pc}
_0222AD14:
	mov r1, #0x28
	mul r1, r0
	ldr r0, _0222AD80 ; =ov80_0223B73C
	ldrh r0, [r0, r1]
	pop {r3, pc}
_0222AD1E:
	mov r1, #0x28
	mul r1, r0
	ldr r0, _0222AD84 ; =ov80_0223B73E
	ldrh r0, [r0, r1]
	pop {r3, pc}
_0222AD28:
	mov r1, #0x28
	mul r1, r0
	ldr r0, _0222AD88 ; =ov80_0223B740
	ldrh r0, [r0, r1]
	pop {r3, pc}
_0222AD32:
	mov r1, #0x28
	mul r1, r0
	ldr r0, _0222AD8C ; =ov80_0223B742
	ldrh r0, [r0, r1]
	pop {r3, pc}
_0222AD3C:
	mov r1, #0x28
	mul r1, r0
	ldr r0, _0222AD90 ; =ov80_0223B744
	ldrh r0, [r0, r1]
	pop {r3, pc}
_0222AD46:
	mov r1, #0x28
	mul r1, r0
	ldr r0, _0222AD94 ; =ov80_0223B746
	ldrb r0, [r0, r1]
	pop {r3, pc}
_0222AD50:
	mov r1, #0x28
	mul r1, r0
	ldr r0, _0222AD98 ; =ov80_0223B747
	ldrb r0, [r0, r1]
	pop {r3, pc}
_0222AD5A:
	bl GF_AssertFail
	mov r0, #0
	pop {r3, pc}
	nop
_0222AD64: .word ov80_0223B724
_0222AD68: .word ov80_0223B730
_0222AD6C: .word ov80_0223B732
_0222AD70: .word ov80_0223B734
_0222AD74: .word ov80_0223B736
_0222AD78: .word ov80_0223B738
_0222AD7C: .word ov80_0223B73A
_0222AD80: .word ov80_0223B73C
_0222AD84: .word ov80_0223B73E
_0222AD88: .word ov80_0223B740
_0222AD8C: .word ov80_0223B742
_0222AD90: .word ov80_0223B744
_0222AD94: .word ov80_0223B746
_0222AD98: .word ov80_0223B747
	thumb_func_end ov80_0222ACA0

	thumb_func_start ov80_0222AD9C
ov80_0222AD9C: ; 0x0222AD9C
	push {r3, lr}
	mov r3, #0x28
	mul r3, r2
	ldr r2, _0222ADB0 ; =ov80_0223B728
	ldr r2, [r2, r3]
	cmp r2, #0
	beq _0222ADAC
	blx r2
_0222ADAC:
	pop {r3, pc}
	nop
_0222ADB0: .word ov80_0223B728
	thumb_func_end ov80_0222AD9C

	thumb_func_start ov80_0222ADB4
ov80_0222ADB4: ; 0x0222ADB4
	push {r3, lr}
	mov r3, #0x28
	mul r3, r2
	ldr r2, _0222ADC8 ; =ov80_0223B72C
	ldr r2, [r2, r3]
	cmp r2, #0
	beq _0222ADC4
	blx r2
_0222ADC4:
	pop {r3, pc}
	nop
_0222ADC8: .word ov80_0223B72C
	thumb_func_end ov80_0222ADB4

	thumb_func_start ov80_0222ADCC
ov80_0222ADCC: ; 0x0222ADCC
	push {r4, lr}
	add r4, r1, #0
	mov r0, #0x65
	mov r1, #0x20
	bl AllocFromHeap
	str r0, [r4]
	pop {r4, pc}
	thumb_func_end ov80_0222ADCC

	thumb_func_start ov80_0222ADDC
ov80_0222ADDC: ; 0x0222ADDC
	ldr r3, _0222ADE4 ; =Heap_Free
	ldr r0, [r1]
	bx r3
	nop
_0222ADE4: .word Heap_Free
	thumb_func_end ov80_0222ADDC

	thumb_func_start ov80_0222ADE8
ov80_0222ADE8: ; 0x0222ADE8
	push {r4, lr}
	add r2, r0, #0
	add r4, r1, #0
	ldr r0, [r2]
	ldr r1, [r2, #4]
	bl ov80_02239D74
	str r0, [r4]
	mov r0, #0
	mov r1, #1
	bl SetBgPriority
	mov r0, #2
	add r1, r0, #0
	bl SetBgPriority
	mov r0, #3
	add r1, r0, #0
	bl SetBgPriority
	mov r0, #4
	mov r1, #0
	bl GfGfx_EngineATogglePlanes
	pop {r4, pc}
	.balign 4, 0
	thumb_func_end ov80_0222ADE8

	thumb_func_start ov80_0222AE1C
ov80_0222AE1C: ; 0x0222AE1C
	ldr r3, _0222AE24 ; =ov80_02239DB8
	ldr r0, [r1]
	bx r3
	nop
_0222AE24: .word ov80_02239DB8
	thumb_func_end ov80_0222AE1C

	thumb_func_start ov80_0222AE28
ov80_0222AE28: ; 0x0222AE28
	bx lr
	.balign 4, 0
	thumb_func_end ov80_0222AE28

	thumb_func_start ov80_0222AE2C
ov80_0222AE2C: ; 0x0222AE2C
	bx lr
	.balign 4, 0
	thumb_func_end ov80_0222AE2C

	thumb_func_start ov80_0222AE30
ov80_0222AE30: ; 0x0222AE30
	push {r3, lr}
	mov r0, #0
	mov r1, #1
	bl SetBgPriority
	mov r0, #2
	add r1, r0, #0
	bl SetBgPriority
	mov r0, #3
	add r1, r0, #0
	bl SetBgPriority
	mov r3, #0x14
	ldr r0, _0222AE64 ; =0x04000050
	mov r1, #1
	mov r2, #0x3c
	str r3, [sp]
	bl G2x_SetBlendAlpha_
	mov r0, #4
	mov r1, #0
	bl GfGfx_EngineATogglePlanes
	pop {r3, pc}
	nop
_0222AE64: .word 0x04000050
	thumb_func_end ov80_0222AE30

	thumb_func_start ov80_0222AE68
ov80_0222AE68: ; 0x0222AE68
	bx lr
	.balign 4, 0
	thumb_func_end ov80_0222AE68

	thumb_func_start ov80_0222AE6C
ov80_0222AE6C: ; 0x0222AE6C
	push {r3, lr}
	mov r0, #2
	mov r1, #3
	bl SetBgPriority
	mov r0, #3
	mov r1, #2
	bl SetBgPriority
	pop {r3, pc}
	thumb_func_end ov80_0222AE6C

	thumb_func_start ov80_0222AE80
ov80_0222AE80: ; 0x0222AE80
	bx lr
	.balign 4, 0
	thumb_func_end ov80_0222AE80

	thumb_func_start ov80_0222AE84
ov80_0222AE84: ; 0x0222AE84
	push {r3, lr}
	ldr r0, _0222AE98 ; =0x04000050
	mov r3, #0x14
	mov r1, #1
	mov r2, #0x3c
	str r3, [sp]
	bl G2x_SetBlendAlpha_
	pop {r3, pc}
	nop
_0222AE98: .word 0x04000050
	thumb_func_end ov80_0222AE84

	thumb_func_start ov80_0222AE9C
ov80_0222AE9C: ; 0x0222AE9C
	bx lr
	.balign 4, 0
	thumb_func_end ov80_0222AE9C

	thumb_func_start ov80_0222AEA0
ov80_0222AEA0: ; 0x0222AEA0
	push {r4, lr}
	ldr r0, [r0]
	add r4, r1, #0
	bl ov80_022384D8
	str r0, [r4]
	pop {r4, pc}
	.balign 4, 0
	thumb_func_end ov80_0222AEA0

	thumb_func_start ov80_0222AEB0
ov80_0222AEB0: ; 0x0222AEB0
	ldr r3, _0222AEB8 ; =ov80_022385B0
	ldr r0, [r1]
	bx r3
	nop
_0222AEB8: .word ov80_022385B0
	thumb_func_end ov80_0222AEB0

	thumb_func_start ov80_0222AEBC
ov80_0222AEBC: ; 0x0222AEBC
	push {r3, lr}
	mov r0, #1
	mov r1, #0
	bl SetBgPriority
	mov r0, #0
	mov r1, #2
	bl SetBgPriority
	mov r0, #2
	add r1, r0, #0
	bl SetBgPriority
	mov r0, #3
	add r1, r0, #0
	bl SetBgPriority
	mov r3, #0x14
	ldr r0, _0222AEF0 ; =0x04000050
	mov r1, #1
	mov r2, #0x3c
	str r3, [sp]
	bl G2x_SetBlendAlpha_
	pop {r3, pc}
	nop
_0222AEF0: .word 0x04000050
	thumb_func_end ov80_0222AEBC

	thumb_func_start ov80_0222AEF4
ov80_0222AEF4: ; 0x0222AEF4
	bx lr
	.balign 4, 0
	thumb_func_end ov80_0222AEF4

    .rodata

ov80_0223B724: ; 0x0223B724
	.byte 0x00, 0x00, 0x00, 0x00

ov80_0223B728: ; 0x0223B728
	.word ov80_0222ADCC

ov80_0223B72C: ; 0x0223B72C
	.word ov80_0222ADDC

ov80_0223B730: ; 0x0223B730
	.byte 0x04, 0x00

ov80_0223B732: ; 0x0223B732
	.byte 0x23, 0x00

ov80_0223B734: ; 0x0223B734
	.byte 0x2E, 0x04

ov80_0223B736: ; 0x0223B736
	.byte 0x03, 0x00

ov80_0223B738: ; 0x0223B738
	.byte 0xB7, 0x00

ov80_0223B73A: ; 0x0223B73A
	.byte 0x01, 0x00

ov80_0223B73C: ; 0x0223B73C
	.byte 0x00, 0x00

ov80_0223B73E: ; 0x0223B73E
	.byte 0x94, 0x00

ov80_0223B740: ; 0x0223B740
	.byte 0x03, 0x00

ov80_0223B742: ; 0x0223B742
	.byte 0x00, 0x00

ov80_0223B744: ; 0x0223B744
	.byte 0x94, 0x00

ov80_0223B746: ; 0x0223B746
	.byte 0x00

ov80_0223B747: ; 0x0223B747
	.byte 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x23, 0x00, 0x2E, 0x04, 0x03, 0x00
	.byte 0xB7, 0x00, 0x02, 0x00, 0x00, 0x00, 0x94, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x01
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x05, 0x00, 0x24, 0x00, 0x2E, 0x04, 0x03, 0x00, 0xB7, 0x00, 0x01, 0x00, 0x00, 0x00, 0x94, 0x00
	.byte 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x05, 0x00, 0x00, 0x00
	.word ov80_0222AE6C
	.word ov80_0222AE80
	.byte 0x01, 0x00, 0xC3, 0x00, 0x77, 0x04, 0x04, 0x00
	.byte 0xB7, 0x00, 0x02, 0x00, 0x00, 0x00, 0x94, 0x00, 0x03, 0x00, 0x00, 0x00, 0x94, 0x00, 0x01, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x05, 0x00, 0x00, 0x00
	.word ov80_0222AE84
	.word ov80_0222AE9C
	.byte 0x01, 0x00, 0xC3, 0x00, 0x77, 0x04, 0x01, 0x00, 0xB7, 0x00, 0x01, 0x00, 0x00, 0x00, 0x94, 0x00
	.byte 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x05, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x00, 0x60, 0x00, 0x2E, 0x04, 0x04, 0x00
	.byte 0xB7, 0x00, 0x36, 0x00, 0x31, 0x00, 0xA0, 0x00, 0x37, 0x00, 0x31, 0x00, 0xA0, 0x00, 0x01, 0x01
	.byte 0x00, 0x00, 0x00, 0x00, 0x05, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x07, 0x00, 0x60, 0x00, 0x2E, 0x04, 0x04, 0x00, 0xB7, 0x00, 0x33, 0x00, 0x31, 0x00, 0xA0, 0x00
	.byte 0x34, 0x00, 0x31, 0x00, 0xA0, 0x00, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x05, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x61, 0x00, 0x2E, 0x04, 0x01, 0x00
	.byte 0xB7, 0x00, 0x35, 0x00, 0x31, 0x00, 0xA0, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x01, 0x01
	.byte 0x00, 0x00, 0x00, 0x00, 0x05, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x09, 0x00, 0x62, 0x00, 0x2E, 0x04, 0x01, 0x00, 0xB7, 0x00, 0x32, 0x00, 0x31, 0x00, 0xA0, 0x00
	.byte 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x05, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0xB9, 0x01, 0x78, 0x04, 0x01, 0x00
	.byte 0xB7, 0x00, 0x11, 0x00, 0x10, 0x00, 0x97, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x01, 0x01
	.byte 0x00, 0x00, 0x00, 0x00, 0x05, 0x00, 0x00, 0x00
	.word ov80_0222ADE8
	.word ov80_0222AE1C
	.byte 0x03, 0x00, 0xB9, 0x01, 0x78, 0x04, 0x04, 0x00, 0xB7, 0x00, 0x14, 0x00, 0x0E, 0x00, 0x96, 0x00
	.byte 0x16, 0x00, 0x13, 0x00, 0x98, 0x00, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x05, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x00, 0x7A, 0x04, 0x04, 0x00
	.byte 0xB7, 0x00, 0x1A, 0x00, 0x19, 0x00, 0x9A, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x01, 0x01
	.byte 0x00, 0x00, 0x00, 0x00, 0x05, 0x00, 0x00, 0x00
	.word ov80_0222AEBC
	.word ov80_0222AEF4
	.byte 0x00, 0x00, 0x20, 0x00, 0x7A, 0x04, 0x01, 0x00, 0xB7, 0x00, 0x1E, 0x00, 0x1D, 0x00, 0x9F, 0x00
	.byte 0x21, 0x00, 0x1D, 0x00, 0x9F, 0x00, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x05, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x00, 0x7A, 0x04, 0x01, 0x00
	.byte 0xB7, 0x00, 0x1C, 0x00, 0x1B, 0x00, 0x9B, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x01, 0x01
	.byte 0x00, 0x00, 0x00, 0x00, 0x05, 0x00, 0x00, 0x00
	.word ov80_0222AEA0
	.word ov80_0222AEB0
	.byte 0x0A, 0x00, 0x12, 0x00, 0x2E, 0x04, 0x01, 0x00, 0xB7, 0x00, 0x84, 0x00, 0x83, 0x00, 0xBF, 0x00
	.byte 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x05, 0x00, 0x00, 0x00
	.word ov80_0222AE28
	.word ov80_0222AE2C
	.byte 0x02, 0x00, 0xAA, 0x01, 0x79, 0x04, 0x01, 0x00
	.byte 0xB7, 0x00, 0x3B, 0x00, 0x3C, 0x00, 0xA2, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x01, 0x01
	.byte 0x00, 0x00, 0x00, 0x00, 0x05, 0x00, 0x00, 0x00
	.word ov80_0222AE30
	.word ov80_0222AE68
	.byte 0x02, 0x00, 0xAA, 0x01, 0x79, 0x04, 0x04, 0x00, 0xB7, 0x00, 0x38, 0x00, 0x3A, 0x00, 0xA1, 0x00
	.byte 0x3D, 0x00, 0x5D, 0x00, 0xBC, 0x00, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00
