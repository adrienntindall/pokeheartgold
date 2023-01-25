	.include "asm/macros.inc"
	.include "global.inc"

    .text

	thumb_func_start ov80_02233F40
ov80_02233F40: ; 0x02233F40
	push {r4, r5, lr}
	sub sp, #0x14
	add r4, r0, #0
	bl sub_02015504
	ldr r5, _02233FB4 ; =ov80_0223BE6C
	add r2, r0, #0
	ldmia r5!, {r0, r1}
	add r3, sp, #8
	stmia r3!, {r0, r1}
	ldr r0, [r5]
	str r0, [r3]
	ldr r0, _02233FB8 ; =0x00000A7A
	ldrb r0, [r2, r0]
	cmp r0, #1
	bne _02233FB0
	add r0, r4, #0
	add r1, sp, #0
	bl sub_02015538
	add r1, sp, #0
	mov r0, #0
	ldrsh r2, [r1, r0]
	sub r0, r0, #1
	mul r0, r2
	strh r0, [r1]
	add r0, r4, #0
	ldrh r2, [r1]
	add r0, #0x50
	strh r2, [r0]
	add r0, r4, #0
	ldrh r2, [r1, #2]
	add r0, #0x52
	strh r2, [r0]
	add r0, r4, #0
	ldrh r1, [r1, #4]
	add r0, #0x54
	strh r1, [r0]
	ldr r0, [r4, #0x20]
	ldr r1, [sp, #8]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	add r0, r1, r0
	str r0, [r4, #0x28]
	ldr r0, [r4, #0x20]
	ldr r1, [sp, #0xc]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	add r0, r1, r0
	str r0, [r4, #0x2c]
	ldr r0, [r4, #0x20]
	ldr r1, [sp, #0x10]
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	add r0, r1, r0
	str r0, [r4, #0x30]
_02233FB0:
	add sp, #0x14
	pop {r4, r5, pc}
	.balign 4, 0
_02233FB4: .word ov80_0223BE6C
_02233FB8: .word 0x00000A7A
	thumb_func_end ov80_02233F40

	thumb_func_start ov80_02233FBC
ov80_02233FBC: ; 0x02233FBC
	push {r3, r4, r5, lr}
	add r5, r0, #0
	bl FrontierScript_GetVarPointer
	add r4, r0, #0
	ldr r0, [r5]
	ldr r0, [r0]
	bl sub_02096810
	ldr r0, [r0, #0x28]
	strh r0, [r4]
	mov r0, #0
	pop {r3, r4, r5, pc}
	.balign 4, 0
	thumb_func_end ov80_02233FBC

	thumb_func_start ov80_02233FD8
ov80_02233FD8: ; 0x02233FD8
	push {r3, r4, r5, r6, r7, lr}
	add r5, r0, #0
	bl FrontierScript_ReadHalfword
	add r6, r0, #0
	add r0, r5, #0
	bl FrontierScript_ReadHalfword
	add r7, r0, #0
	add r0, r5, #0
	bl FrontierScript_GetVarPointer
	add r4, r0, #0
	ldr r0, [r5]
	ldr r0, [r0]
	bl sub_02096810
	add r1, r6, #0
	add r2, r7, #0
	bl ov80_02234E50
	strh r0, [r4]
	mov r0, #1
	pop {r3, r4, r5, r6, r7, pc}
	thumb_func_end ov80_02233FD8

	thumb_func_start ov80_02234008
ov80_02234008: ; 0x02234008
	push {r4, lr}
	add r4, r0, #0
	bl ov80_0222AC58
	add r1, r4, #0
	add r1, #0x78
	strh r0, [r1]
	ldr r1, _02234024 ; =ov80_02234028
	add r0, r4, #0
	bl ov80_0222AB84
	mov r0, #1
	pop {r4, pc}
	nop
_02234024: .word ov80_02234028
	thumb_func_end ov80_02234008

	thumb_func_start ov80_02234028
ov80_02234028: ; 0x02234028
	push {r4, lr}
	add r4, r0, #0
	add r1, r4, #0
	add r1, #0x78
	ldrh r1, [r1]
	bl ov80_0222BE9C
	ldr r0, [r4]
	ldr r0, [r0]
	bl sub_02096810
	ldr r1, _02234054 ; =0x00000A7C
	ldrb r2, [r0, r1]
	cmp r2, #2
	blo _0223404E
	mov r2, #0
	strb r2, [r0, r1]
	mov r0, #1
	pop {r4, pc}
_0223404E:
	mov r0, #0
	pop {r4, pc}
	nop
_02234054: .word 0x00000A7C
	thumb_func_end ov80_02234028

	thumb_func_start ov80_02234058
ov80_02234058: ; 0x02234058
	push {r3, r4, r5, lr}
	add r5, r0, #0
	ldr r0, [r5]
	ldr r0, [r0]
	bl sub_02096808
	ldr r1, [r5, #0x1c]
	add r0, r1, #1
	str r0, [r5, #0x1c]
	ldr r0, [r5]
	ldrb r4, [r1]
	ldr r0, [r0]
	bl sub_02096810
	add r2, r0, #0
	bne _0223407C
	mov r0, #0
	pop {r3, r4, r5, pc}
_0223407C:
	mov r1, #0x43
	lsl r1, r1, #2
	add r2, r2, r1
	lsl r1, r4, #4
	add r1, r4, r1
	lsl r1, r1, #4
	add r0, r5, #0
	add r1, r2, r1
	bl ov80_0222F44C
	mov r0, #1
	pop {r3, r4, r5, pc}
	thumb_func_end ov80_02234058

	thumb_func_start ov80_02234094
ov80_02234094: ; 0x02234094
	push {r3, lr}
	ldr r0, [r0]
	ldr r0, [r0]
	bl sub_02096810
	ldrb r1, [r0, #0x13]
	bl ov80_02234E98
	mov r0, #1
	pop {r3, pc}
	thumb_func_end ov80_02234094

	thumb_func_start ov80_022340A8
ov80_022340A8: ; 0x022340A8
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #8
	add r5, r0, #0
	ldr r0, [r5]
	bl ov80_0222AB34
	add r6, r0, #0
	add r0, r5, #0
	bl FrontierScript_ReadHalfword
	add r7, r0, #0
	add r0, r5, #0
	bl FrontierScript_ReadHalfword
	str r0, [sp, #4]
	add r0, r5, #0
	bl FrontierScript_ReadHalfword
	add r4, r0, #0
	ldr r0, [r5]
	ldr r0, [r0]
	bl sub_02096810
	ldr r3, [sp, #4]
	add r1, r6, #0
	add r2, r7, #0
	str r4, [sp]
	bl ov80_02234D04
	mov r0, #0
	add sp, #8
	pop {r3, r4, r5, r6, r7, pc}
	thumb_func_end ov80_022340A8
