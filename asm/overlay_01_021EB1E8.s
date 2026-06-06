#include "constants/sndseq.h"
#include "constants/moves.h"
#include "constants/std_script.h"
#include "constants/species.h"
#include "constants/sprites.h"
#include "constants/maps.h"
#include "constants/mmodel.h"
#include "constants/items.h"
#include "msgdata/msg/msg_0096_D31R0201.h"
#include "msgdata/msg/msg_0066_D23R0102.h"
	.include "asm/macros.inc"
	.include "overlay_01_021EB1E8.inc"
	.include "global.inc"

	.text
    .public WeatherDraw_Init
    .public WeatherDraw_Delete
    .public ov01_021EB5F4
    .public ov01_021EB68C
    .public ov01_021EB804
    .public ov01_021EB830
    .public ov01_021EB818
    .public ov01_021EB840
    .public ov01_021EB86C
    .public ov01_021EB898
    .public ov01_021EB968
    .public ov01_021EB9A8
    .public ov01_021EBCA4
    .public ov01_021EC1BC
    .public ov01_021EC1E4
    .public ov01_021EC1F4
    .public ov01_021EC29C
    .public ov01_021EC2E4
    .public ov01_021EC300
    .public ov01_021EC304
    .public ov01_021EC31C
    .public ov01_021EC470
    .public ov01_021EC504
    .public ov01_021EC52C
    .public ov01_021EC538
    .public ov01_021EC5FC
	.public ov01_021EC650
    .public ov01_021EC678
    .public ov01_021EC790
    .public ov01_021EC7AC
    .public ov01_021EC7C8
    .public ov01_021EC85C
	.public ov01_021EC8F8
	

	thumb_func_start ov01_021EC94C
ov01_021EC94C: ; 0x021EC94C
	push {r4, r5, r6, lr}
	sub sp, #0x18
	ldr r0, _021ECB8C ; =0x00000F58
	add r4, r1, #0
	add r2, r0, #0
	add r2, #0xa
	ldrh r2, [r4, r2]
	ldr r5, [r4, r0]
	cmp r2, #5
	bhi _021ECA1A
	add r2, r2, r2
	add r2, pc
	ldrh r2, [r2, #6]
	lsl r2, r2, #0x10
	asr r2, r2, #0x10
	add pc, r2
_021EC96C: ; jump table
	.short _021EC978 - _021EC96C - 2 ; case 0
	.short _021EC9E2 - _021EC96C - 2 ; case 1
	.short _021ECA24 - _021EC96C - 2 ; case 2
	.short _021ECA96 - _021EC96C - 2 ; case 3
	.short _021ECAF4 - _021EC96C - 2 ; case 4
	.short _021ECB42 - _021EC96C - 2 ; case 5
_021EC978:
	mov r0, #0x14
	str r0, [sp]
	mov r2, #1
	str r2, [sp, #4]
	sub r0, r2, #2
	str r0, [sp, #8]
	str r2, [sp, #0xc]
	mov r0, #2
	str r0, [sp, #0x10]
	ldr r0, _021ECB90 ; =ov01_021ECBB4
	mov r3, #8
	str r0, [sp, #0x14]
	add r0, r5, #0
	bl ov01_021EC504
	ldr r0, _021ECB94 ; =0x0000726F
	mov r2, #0x41
	str r0, [sp]
	ldr r0, _021ECB98 ; =0x00006B5A
	lsl r2, r2, #2
	str r0, [sp, #4]
	mov r0, #1
	str r0, [sp, #8]
	ldr r0, _021ECB9C ; =0x00000F64
	add r1, r5, #0
	ldrh r0, [r4, r0]
	add r1, #0x1c
	str r0, [sp, #0xc]
	ldr r3, [r4]
	add r0, r5, #0
	ldr r2, [r3, r2]
	add r0, #0x4c
	ldr r2, [r2, #0x4c]
	mov r3, #3
	bl ov01_021EC5FC
	mov r0, #0
	add r5, #0xb4
	str r0, [r5]
	ldr r0, _021ECBA0 ; =ov01_021EDA7C
	add r1, r4, #0
	mov r2, #0x64
	bl SysTask_CreateOnMainQueue
	ldr r1, _021ECBA4 ; =0x00000F6C
	mov r2, #0x1e
	str r0, [r4, r1]
	sub r0, r1, #4
	str r2, [r4, r0]
	mov r0, #1
	sub r1, #0xa
	strh r0, [r4, r1]
	b _021ECB60
_021EC9E2:
	add r0, r5, #0
	bl ov01_021EC538
	add r6, r0, #0
	add r0, r5, #0
	add r0, #0xb4
	ldr r0, [r0]
	cmp r0, #0
	ble _021ECA02
	add r0, r5, #0
	add r0, #0xb4
	ldr r0, [r0]
	add r5, #0xb4
	sub r0, r0, #1
	str r0, [r5]
	b _021ECB60
_021ECA02:
	ldr r2, _021ECB9C ; =0x00000F64
	add r0, r5, #0
	ldrh r2, [r4, r2]
	add r5, #0x1c
	add r0, #0x4c
	add r1, r5, #0
	bl ov01_021EC650
	cmp r0, #1
	bne _021ECA1A
	cmp r6, #3
	beq _021ECA1C
_021ECA1A:
	b _021ECB60
_021ECA1C:
	ldr r0, _021ECBA8 ; =0x00000F62
	mov r1, #3
	strh r1, [r4, r0]
	b _021ECB60
_021ECA24:
	mov r2, #0x14
	mov r3, #1
	str r2, [sp]
	str r3, [sp, #4]
	sub r0, r3, #2
	str r0, [sp, #8]
	str r3, [sp, #0xc]
	mov r0, #2
	str r0, [sp, #0x10]
	ldr r0, _021ECB90 ; =ov01_021ECBB4
	str r0, [sp, #0x14]
	add r0, r5, #0
	bl ov01_021EC504
	ldr r0, _021ECB9C ; =0x00000F64
	ldrh r0, [r4, r0]
	cmp r0, #0
	beq _021ECA66
	mov r0, #0x41
	ldr r1, [r4]
	lsl r0, r0, #2
	ldr r0, [r1, r0]
	ldr r2, _021ECB94 ; =0x0000726F
	ldr r0, [r0, #0x4c]
	ldr r3, _021ECB98 ; =0x00006B5A
	mov r1, #3
	str r0, [r5, #0x1c]
	bl ov01_021EC678
	add r5, #0x1c
	add r0, r5, #0
	bl ov01_021EC7C8
_021ECA66:
	mov r0, #1
	str r0, [sp]
	ldr r0, _021ECBAC ; =ov01_021ECC70
	ldr r1, _021ECB90 ; =ov01_021ECBB4
	str r0, [sp, #4]
	add r0, r4, #0
	mov r2, #0x14
	mov r3, #0xa
	bl ov01_021EC85C
	ldr r0, _021ECBA0 ; =ov01_021EDA7C
	add r1, r4, #0
	mov r2, #0x64
	bl SysTask_CreateOnMainQueue
	ldr r1, _021ECBA4 ; =0x00000F6C
	mov r2, #0x1e
	str r0, [r4, r1]
	sub r0, r1, #4
	str r2, [r4, r0]
	mov r0, #3
	sub r1, #0xa
	strh r0, [r4, r1]
	b _021ECB60
_021ECA96:
	mov r0, #6
	ldrsh r1, [r5, r0]
	sub r0, r1, #1
	strh r0, [r5, #6]
	cmp r1, #0
	bgt _021ECAB2
	mov r1, #4
	ldrsh r1, [r5, r1]
	add r0, r4, #0
	bl ov01_021ECBB4
	mov r0, #8
	ldrsh r0, [r5, r0]
	strh r0, [r5, #6]
_021ECAB2:
	ldr r0, _021ECBB0 ; =0x00000F66
	ldrh r0, [r4, r0]
	cmp r0, #5
	bne _021ECB60
	mov r0, #1
	mvn r0, r0
	str r0, [sp]
	add r0, r5, #0
	mov r1, #0
	mov r2, #8
	mov r3, #1
	bl ov01_021EC52C
	ldr r0, _021ECB9C ; =0x00000F64
	ldrh r0, [r4, r0]
	cmp r0, #0
	beq _021ECAE0
	add r0, r5, #0
	add r0, #0x1c
	mov r1, #1
	mov r2, #0
	bl ov01_021EC790
_021ECAE0:
	mov r0, #0
	add r5, #0xb4
	str r0, [r5]
	ldr r0, _021ECBA8 ; =0x00000F62
	mov r1, #4
	strh r1, [r4, r0]
	add r0, r4, #0
	bl ov01_021EDAE0
	b _021ECB60
_021ECAF4:
	add r0, r5, #0
	bl ov01_021EC538
	add r6, r0, #0
	add r0, r5, #0
	add r0, #0xb4
	ldr r0, [r0]
	cmp r0, #0
	ble _021ECB14
	add r0, r5, #0
	add r0, #0xb4
	ldr r0, [r0]
	add r5, #0xb4
	sub r0, r0, #1
	str r0, [r5]
	b _021ECB60
_021ECB14:
	ldr r0, _021ECB9C ; =0x00000F64
	ldrh r0, [r4, r0]
	cmp r0, #0
	beq _021ECB26
	add r5, #0x1c
	add r0, r5, #0
	bl ov01_021EC7AC
	b _021ECB28
_021ECB26:
	mov r0, #1
_021ECB28:
	cmp r0, #1
	bne _021ECB60
	cmp r6, #3
	bne _021ECB60
	add r0, r4, #0
	ldr r1, [r4, #0x40]
	add r0, #0xc
	cmp r1, r0
	bne _021ECB60
	ldr r0, _021ECBA8 ; =0x00000F62
	mov r1, #5
	strh r1, [r4, r0]
	b _021ECB60
_021ECB42:
	add r0, #0xc
	ldrh r0, [r4, r0]
	cmp r0, #0
	beq _021ECB5A
	mov r2, #0
	str r2, [sp]
	str r2, [sp, #4]
	ldr r0, [r5, #0x1c]
	mov r1, #1
	add r3, r2, #0
	bl ov01_021EA864
_021ECB5A:
	ldr r0, [r4, #4]
	bl ov01_021EBCA4
_021ECB60:
	ldr r0, _021ECBA8 ; =0x00000F62
	ldrh r0, [r4, r0]
	cmp r0, #5
	beq _021ECB86
	cmp r0, #0
	beq _021ECB86
	add r0, r4, #0
	ldr r1, _021ECBAC ; =ov01_021ECC70
	add r0, #0xc
	bl ov01_021EC2E4
	mov r1, #0
	add r0, r4, #0
	add r2, r1, #0
	bl ov01_021EC470
	add r0, r4, #0
	bl ov01_021EC300
_021ECB86:
	add sp, #0x18
	pop {r4, r5, r6, pc}
	nop
_021ECB8C: .word 0x00000F58
_021ECB90: .word ov01_021ECBB4
_021ECB94: .word 0x0000726F
_021ECB98: .word 0x00006B5A
_021ECB9C: .word 0x00000F64
_021ECBA0: .word ov01_021EDA7C
_021ECBA4: .word 0x00000F6C
_021ECBA8: .word 0x00000F62
_021ECBAC: .word ov01_021ECC70
_021ECBB0: .word 0x00000F66
	thumb_func_end ov01_021EC94C

	thumb_func_start ov01_021ECBB4
ov01_021ECBB4: ; 0x021ECBB4
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x18
	str r0, [sp]
	mov r0, #0
	str r0, [sp, #8]
	add r0, r1, #0
	str r1, [sp, #4]
	cmp r0, #0
	ble _021ECC62
_021ECBC6:
	ldr r0, [sp]
	mov r1, #0x20
	bl ov01_021EC1F4
	add r6, r0, #0
	beq _021ECC62
	ldr r4, [r6, #8]
	bl MTRandom
	mov r1, #0
	str r1, [r4]
	mov r1, #3
	add r7, r0, #0
	bl _u32_div_f
	add r5, r1, #0
	lsl r1, r5, #0x10
	ldr r0, [r6, #4]
	lsr r1, r1, #0x10
	bl Sprite_SetAnimationFrame
	add r0, r7, #0
	mov r1, #0x14
	bl _u32_div_f
	add r2, r5, #1
	mov r0, #0xa
	mul r0, r2
	add r0, r1, r0
	str r0, [r4, #8]
	cmp r5, #2
	bne _021ECC0C
	ldr r0, [r4, #8]
	add r0, #0xa
	str r0, [r4, #8]
_021ECC0C:
	add r0, r1, #0
	mov r1, #4
	mvn r1, r1
	bl _s32_div_f
	mov r1, #4
	add r2, r5, #1
	mvn r1, r1
	mul r1, r2
	add r0, r0, r1
	str r0, [r4, #0x10]
	cmp r5, #2
	bne _021ECC2C
	ldr r0, [r4, #0x10]
	sub r0, r0, #5
	str r0, [r4, #0x10]
_021ECC2C:
	mov r0, #0
	str r0, [r4, #0xc]
	add r0, r5, #1
	str r0, [r4, #4]
	ldr r1, _021ECC68 ; =0x0000010E
	add r0, r7, #0
	bl _u32_div_f
	mov r0, #0xf
	mul r0, r5
	add r0, r1, r0
	lsl r0, r0, #0xc
	str r0, [sp, #0xc]
	ldr r0, _021ECC6C ; =0xFFFA0000
	add r1, sp, #0xc
	str r0, [sp, #0x10]
	mov r0, #0
	str r0, [sp, #0x14]
	ldr r0, [r6, #4]
	bl ov01_021EB5F4
	ldr r0, [sp, #8]
	add r1, r0, #1
	ldr r0, [sp, #4]
	str r1, [sp, #8]
	cmp r1, r0
	blt _021ECBC6
_021ECC62:
	add sp, #0x18
	pop {r3, r4, r5, r6, r7, pc}
	nop
_021ECC68: .word 0x0000010E
_021ECC6C: .word 0xFFFA0000
	thumb_func_end ov01_021ECBB4

	thumb_func_start ov01_021ECC70
ov01_021ECC70: ; 0x021ECC70
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	add r6, r0, #0
	ldr r5, [r6, #8]
	add r0, sp, #0
	add r1, r6, #0
	bl ov01_021EC304
	ldr r0, [r5, #0xc]
	cmp r0, #0
	beq _021ECC92
	cmp r0, #1
	beq _021ECCEA
	cmp r0, #2
	beq _021ECCFC
	add sp, #0xc
	pop {r4, r5, r6, r7, pc}
_021ECC92:
	mov r4, #0
	mov r7, #2
_021ECC96:
	ldr r0, [r5, #0x10]
	ldr r1, [sp]
	lsl r0, r0, #0xc
	add r0, r1, r0
	str r0, [sp]
	ldr r0, [r5, #8]
	ldr r1, [sp, #4]
	lsl r0, r0, #0xc
	add r0, r1, r0
	str r0, [sp, #4]
	ldr r1, [r5]
	add r0, r1, #1
	str r0, [r5]
	ldr r0, [r5, #4]
	cmp r1, r0
	ble _021ECCD8
	bl MTRandom
	mov r1, #0xa
	bl _u32_div_f
	cmp r1, #7
	bhs _021ECCC8
	str r7, [r5, #0xc]
	b _021ECCD8
_021ECCC8:
	mov r0, #1
	str r0, [r5, #0xc]
	mov r0, #4
	str r0, [r5]
	ldr r0, [r6, #4]
	mov r1, #3
	bl Sprite_SetAnimationFrame
_021ECCD8:
	add r4, r4, #1
	cmp r4, #2
	blt _021ECC96
	ldr r0, [r6, #4]
	add r1, sp, #0
	bl ov01_021EB5F4
	add sp, #0xc
	pop {r4, r5, r6, r7, pc}
_021ECCEA:
	ldr r1, [r5]
	sub r0, r1, #1
	str r0, [r5]
	cmp r1, #0
	bgt _021ECD02
	mov r0, #2
	add sp, #0xc
	str r0, [r5, #0xc]
	pop {r4, r5, r6, r7, pc}
_021ECCFC:
	add r0, r6, #0
	bl ov01_021EC29C
_021ECD02:
	add sp, #0xc
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov01_021ECC70

	thumb_func_start ov01_021ECD08
ov01_021ECD08: ; 0x021ECD08
	push {r4, r5, r6, lr}
	sub sp, #0x18
	ldr r0, _021ECF2C ; =0x00000F58
	add r5, r1, #0
	add r2, r0, #0
	add r2, #0xa
	ldrh r2, [r5, r2]
	ldr r4, [r5, r0]
	cmp r2, #5
	bhi _021ECDCC
	add r2, r2, r2
	add r2, pc
	ldrh r2, [r2, #6]
	lsl r2, r2, #0x10
	asr r2, r2, #0x10
	add pc, r2
_021ECD28: ; jump table
	.short _021ECD34 - _021ECD28 - 2 ; case 0
	.short _021ECD94 - _021ECD28 - 2 ; case 1
	.short _021ECDD6 - _021ECD28 - 2 ; case 2
	.short _021ECE3E - _021ECD28 - 2 ; case 3
	.short _021ECE96 - _021ECD28 - 2 ; case 4
	.short _021ECEE4 - _021ECD28 - 2 ; case 5
_021ECD34:
	mov r0, #6
	str r0, [sp]
	mov r0, #3
	str r0, [sp, #4]
	sub r0, #8
	str r0, [sp, #8]
	mov r0, #2
	str r0, [sp, #0xc]
	mov r2, #1
	ldr r0, _021ECF30 ; =ov01_021ECF4C
	str r2, [sp, #0x10]
	str r0, [sp, #0x14]
	add r0, r4, #0
	mov r3, #0x1e
	bl ov01_021EC504
	ldr r0, _021ECF34 ; =0x0000726F
	mov r2, #0x41
	str r0, [sp]
	ldr r0, _021ECF38 ; =0x00006318
	add r1, r4, #0
	str r0, [sp, #4]
	mov r0, #2
	str r0, [sp, #8]
	ldr r0, _021ECF3C ; =0x00000F64
	lsl r2, r2, #2
	ldrh r0, [r5, r0]
	add r1, #0x1c
	str r0, [sp, #0xc]
	ldr r3, [r5]
	add r0, r4, #0
	ldr r2, [r3, r2]
	add r0, #0x4c
	ldr r2, [r2, #0x4c]
	mov r3, #3
	bl ov01_021EC5FC
	add r0, r4, #0
	mov r1, #8
	add r0, #0xb4
	str r1, [r0]
	mov r0, #0
	add r4, #0xb8
	str r0, [r4]
	ldr r0, _021ECF40 ; =0x00000F62
	mov r1, #1
	strh r1, [r5, r0]
	b _021ECF02
_021ECD94:
	add r0, r4, #0
	bl ov01_021EC538
	add r6, r0, #0
	add r0, r4, #0
	add r0, #0xb4
	ldr r0, [r0]
	cmp r0, #0
	ble _021ECDB4
	add r0, r4, #0
	add r0, #0xb4
	ldr r0, [r0]
	add r4, #0xb4
	sub r0, r0, #1
	str r0, [r4]
	b _021ECF02
_021ECDB4:
	ldr r2, _021ECF3C ; =0x00000F64
	add r0, r4, #0
	ldrh r2, [r5, r2]
	add r4, #0x1c
	add r0, #0x4c
	add r1, r4, #0
	bl ov01_021EC650
	cmp r0, #1
	bne _021ECDCC
	cmp r6, #3
	beq _021ECDCE
_021ECDCC:
	b _021ECF02
_021ECDCE:
	ldr r0, _021ECF40 ; =0x00000F62
	mov r1, #3
	strh r1, [r5, r0]
	b _021ECF02
_021ECDD6:
	mov r2, #6
	mov r3, #3
	str r2, [sp]
	add r0, r3, #0
	str r3, [sp, #4]
	sub r0, #8
	str r0, [sp, #8]
	mov r0, #2
	str r0, [sp, #0xc]
	mov r0, #1
	str r0, [sp, #0x10]
	ldr r0, _021ECF30 ; =ov01_021ECF4C
	str r0, [sp, #0x14]
	add r0, r4, #0
	bl ov01_021EC504
	ldr r0, _021ECF3C ; =0x00000F64
	ldrh r0, [r5, r0]
	cmp r0, #0
	beq _021ECE1C
	mov r0, #0x41
	ldr r1, [r5]
	lsl r0, r0, #2
	ldr r0, [r1, r0]
	ldr r2, _021ECF34 ; =0x0000726F
	ldr r0, [r0, #0x4c]
	ldr r3, _021ECF38 ; =0x00006318
	mov r1, #3
	str r0, [r4, #0x1c]
	bl ov01_021EC678
	add r0, r4, #0
	add r0, #0x1c
	bl ov01_021EC7C8
_021ECE1C:
	mov r0, #0
	add r4, #0xb8
	str r0, [r4]
	mov r0, #3
	str r0, [sp]
	ldr r0, _021ECF44 ; =ov01_021ED070
	ldr r1, _021ECF30 ; =ov01_021ECF4C
	str r0, [sp, #4]
	add r0, r5, #0
	mov r2, #0x14
	mov r3, #2
	bl ov01_021EC85C
	ldr r0, _021ECF40 ; =0x00000F62
	mov r1, #3
	strh r1, [r5, r0]
	b _021ECF02
_021ECE3E:
	mov r0, #6
	ldrsh r1, [r4, r0]
	sub r0, r1, #1
	strh r0, [r4, #6]
	cmp r1, #0
	bgt _021ECE5A
	mov r1, #4
	ldrsh r1, [r4, r1]
	add r0, r5, #0
	bl ov01_021ECF4C
	mov r0, #8
	ldrsh r0, [r4, r0]
	strh r0, [r4, #6]
_021ECE5A:
	ldr r0, _021ECF48 ; =0x00000F66
	ldrh r0, [r5, r0]
	cmp r0, #5
	bne _021ECF02
	mov r0, #2
	mvn r0, r0
	str r0, [sp]
	add r0, r4, #0
	mov r1, #0
	mov r2, #0x1e
	mov r3, #5
	bl ov01_021EC52C
	ldr r0, _021ECF3C ; =0x00000F64
	ldrh r0, [r5, r0]
	cmp r0, #0
	beq _021ECE88
	add r0, r4, #0
	add r0, #0x1c
	mov r1, #1
	mov r2, #0
	bl ov01_021EC790
_021ECE88:
	mov r0, #0
	add r4, #0xb4
	str r0, [r4]
	ldr r0, _021ECF40 ; =0x00000F62
	mov r1, #4
	strh r1, [r5, r0]
	b _021ECF02
_021ECE96:
	add r0, r4, #0
	bl ov01_021EC538
	add r6, r0, #0
	add r0, r4, #0
	add r0, #0xb4
	ldr r0, [r0]
	cmp r0, #0
	ble _021ECEB6
	add r0, r4, #0
	add r0, #0xb4
	ldr r0, [r0]
	add r4, #0xb4
	sub r0, r0, #1
	str r0, [r4]
	b _021ECF02
_021ECEB6:
	ldr r0, _021ECF3C ; =0x00000F64
	ldrh r0, [r5, r0]
	cmp r0, #0
	beq _021ECEC8
	add r4, #0x1c
	add r0, r4, #0
	bl ov01_021EC7AC
	b _021ECECA
_021ECEC8:
	mov r0, #1
_021ECECA:
	cmp r0, #1
	bne _021ECF02
	cmp r6, #3
	bne _021ECF02
	add r0, r5, #0
	ldr r1, [r5, #0x40]
	add r0, #0xc
	cmp r1, r0
	bne _021ECF02
	ldr r0, _021ECF40 ; =0x00000F62
	mov r1, #5
	strh r1, [r5, r0]
	b _021ECF02
_021ECEE4:
	add r0, #0xc
	ldrh r0, [r5, r0]
	cmp r0, #0
	beq _021ECEFC
	mov r2, #0
	str r2, [sp]
	str r2, [sp, #4]
	ldr r0, [r4, #0x1c]
	mov r1, #1
	add r3, r2, #0
	bl ov01_021EA864
_021ECEFC:
	ldr r0, [r5, #4]
	bl ov01_021EBCA4
_021ECF02:
	ldr r0, _021ECF40 ; =0x00000F62
	ldrh r0, [r5, r0]
	cmp r0, #5
	beq _021ECF28
	cmp r0, #0
	beq _021ECF28
	add r0, r5, #0
	ldr r1, _021ECF44 ; =ov01_021ED070
	add r0, #0xc
	bl ov01_021EC2E4
	mov r1, #0
	add r0, r5, #0
	add r2, r1, #0
	bl ov01_021EC470
	add r0, r5, #0
	bl ov01_021EC300
_021ECF28:
	add sp, #0x18
	pop {r4, r5, r6, pc}
	.balign 4, 0
_021ECF2C: .word 0x00000F58
_021ECF30: .word ov01_021ECF4C
_021ECF34: .word 0x0000726F
_021ECF38: .word 0x00006318
_021ECF3C: .word 0x00000F64
_021ECF40: .word 0x00000F62
_021ECF44: .word ov01_021ED070
_021ECF48: .word 0x00000F66
	thumb_func_end ov01_021ECD08

	thumb_func_start ov01_021ECF4C
ov01_021ECF4C: ; 0x021ECF4C
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x58
	ldr r3, _021ED064 ; =ov01_0220673C
	add r2, sp, #0x48
	str r0, [sp]
	str r1, [sp, #4]
	ldmia r3!, {r0, r1}
	str r2, [sp, #0x10]
	stmia r2!, {r0, r1}
	ldmia r3!, {r0, r1}
	stmia r2!, {r0, r1}
	ldr r3, _021ED068 ; =ov01_0220674C
	add r2, sp, #0x38
	str r2, [sp, #0x14]
	ldmia r3!, {r0, r1}
	stmia r2!, {r0, r1}
	ldmia r3!, {r0, r1}
	stmia r2!, {r0, r1}
	ldr r1, _021ED06C ; =0x00000F58
	ldr r0, [sp]
	ldr r6, [r0, r1]
	mov r0, #0
	str r0, [sp, #0xc]
	ldr r0, [sp, #4]
	cmp r0, #0
	ble _021ED060
	add r0, r6, #0
	str r0, [sp, #0x18]
	add r0, #0xb8
	str r0, [sp, #0x18]
	mov r0, #7
	mvn r0, r0
	lsl r0, r0, #0xc
	str r0, [sp, #0x1c]
_021ECF90:
	ldr r0, [sp]
	mov r1, #0x20
	bl ov01_021EC1F4
	add r4, r0, #0
	beq _021ED060
	ldr r0, [sp, #0x18]
	ldr r5, [r4, #8]
	ldr r0, [r0]
	add r1, r0, #1
	ldr r0, [sp, #0x18]
	str r1, [r0]
	add r0, r6, #0
	add r0, #0xb8
	ldr r1, [r0]
	mov r0, #0x32
	lsl r0, r0, #4
	cmp r1, r0
	blt _021ECFBE
	add r1, r6, #0
	add r1, #0xb8
	mov r0, #0
	str r0, [r1]
_021ECFBE:
	add r0, r6, #0
	add r0, #0xb8
	ldr r0, [r0]
	mov r1, #0xc8
	bl _s32_div_f
	lsl r0, r0, #2
	ldr r1, [sp, #0x10]
	str r0, [sp, #8]
	ldr r0, [r1, r0]
	str r0, [r5, #0x14]
	mov r0, #0
	str r0, [r5]
	bl MTRandom
	mov r1, #0x2a
	bl _u32_div_f
	add r0, r1, #4
	str r0, [r5, #4]
	sub r0, r0, #4
	mov r1, #0xf
	bl _s32_div_f
	add r7, r0, #0
	lsl r1, r7, #0x10
	ldr r0, [r4, #4]
	lsr r1, r1, #0x10
	bl Sprite_SetAnimationFrame
	add r0, r7, #1
	neg r1, r0
	str r1, [r5, #0x10]
	ldr r2, [sp, #0x14]
	ldr r1, [sp, #8]
	ldr r1, [r2, r1]
	mul r1, r0
	str r1, [r5, #8]
	mov r0, #0
	str r0, [r5, #0xc]
	add r0, sp, #0x20
	add r1, r4, #0
	bl ov01_021EC304
	add r3, sp, #0x20
	ldmia r3!, {r0, r1}
	add r2, sp, #0x2c
	stmia r2!, {r0, r1}
	ldr r0, [r3]
	str r0, [r2]
	bl MTRandom
	mov r1, #0x69
	lsl r1, r1, #2
	bl _u32_div_f
	mov r0, #1
	sub r2, r0, r7
	sub r0, #0x15
	mul r0, r2
	add r1, r0, r1
	mov r0, #7
	mvn r0, r0
	str r0, [sp, #0x30]
	mov r0, #0
	str r0, [sp, #0x34]
	str r1, [sp, #0x2c]
	lsl r0, r1, #0xc
	str r0, [sp, #0x2c]
	ldr r0, [sp, #0x1c]
	add r1, sp, #0x2c
	str r0, [sp, #0x30]
	ldr r0, [r4, #4]
	bl ov01_021EB5F4
	ldr r0, [sp, #0xc]
	add r1, r0, #1
	ldr r0, [sp, #4]
	str r1, [sp, #0xc]
	cmp r1, r0
	blt _021ECF90
_021ED060:
	add sp, #0x58
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_021ED064: .word ov01_0220673C
_021ED068: .word ov01_0220674C
_021ED06C: .word 0x00000F58
	thumb_func_end ov01_021ECF4C

	thumb_func_start ov01_021ED070
ov01_021ED070: ; 0x021ED070
	push {r3, r4, r5, lr}
	sub sp, #0x18
	add r5, r0, #0
	add r0, sp, #0
	add r1, r5, #0
	ldr r4, [r5, #8]
	bl ov01_021EC304
	add r3, sp, #0
	ldmia r3!, {r0, r1}
	add r2, sp, #0xc
	stmia r2!, {r0, r1}
	ldr r0, [r3]
	str r0, [r2]
	ldr r0, [r4, #0xc]
	cmp r0, #0
	beq _021ED09A
	cmp r0, #1
	beq _021ED0E6
	add sp, #0x18
	pop {r3, r4, r5, pc}
_021ED09A:
	ldr r0, [r4, #0x10]
	ldr r1, [sp, #0xc]
	lsl r0, r0, #0xc
	add r0, r1, r0
	str r0, [sp, #0xc]
	ldr r0, [r4, #8]
	ldr r1, [sp, #0x10]
	lsl r0, r0, #0xc
	add r0, r1, r0
	str r0, [sp, #0x10]
	ldr r1, [r4]
	add r0, r1, #1
	str r0, [r4]
	ldr r0, [r4, #4]
	cmp r1, r0
	ble _021ED0BE
	mov r0, #1
	str r0, [r4, #0xc]
_021ED0BE:
	ldr r0, [r4]
	ldr r1, [r4, #0x14]
	bl _s32_div_f
	cmp r1, #0
	bne _021ED0DA
	ldr r0, [r4, #0x10]
	sub r0, r0, #1
	str r0, [r4, #0x10]
	ldr r0, [r4, #8]
	cmp r0, #1
	ble _021ED0DA
	sub r0, r0, #1
	str r0, [r4, #8]
_021ED0DA:
	ldr r0, [r5, #4]
	add r1, sp, #0xc
	bl ov01_021EB5F4
	add sp, #0x18
	pop {r3, r4, r5, pc}
_021ED0E6:
	add r0, r5, #0
	bl ov01_021EC29C
	add sp, #0x18
	pop {r3, r4, r5, pc}
	thumb_func_end ov01_021ED070

	thumb_func_start ov01_021ED0F0
ov01_021ED0F0: ; 0x021ED0F0
	push {r4, r5, r6, lr}
	sub sp, #0x18
	ldr r0, _021ED2FC ; =0x00000F58
	add r5, r1, #0
	add r2, r0, #0
	add r2, #0xa
	ldrh r2, [r5, r2]
	ldr r4, [r5, r0]
	cmp r2, #5
	bhi _021ED1AA
	add r2, r2, r2
	add r2, pc
	ldrh r2, [r2, #6]
	lsl r2, r2, #0x10
	asr r2, r2, #0x10
	add pc, r2
_021ED110: ; jump table
	.short _021ED11C - _021ED110 - 2 ; case 0
	.short _021ED172 - _021ED110 - 2 ; case 1
	.short _021ED1B4 - _021ED110 - 2 ; case 2
	.short _021ED212 - _021ED110 - 2 ; case 3
	.short _021ED26A - _021ED110 - 2 ; case 4
	.short _021ED2B4 - _021ED110 - 2 ; case 5
_021ED11C:
	mov r0, #0x14
	str r0, [sp]
	mov r2, #2
	str r2, [sp, #4]
	sub r0, r2, #4
	str r0, [sp, #8]
	mov r0, #4
	str r0, [sp, #0xc]
	ldr r0, _021ED300 ; =ov01_021ED31C
	str r2, [sp, #0x10]
	str r0, [sp, #0x14]
	add r0, r4, #0
	mov r3, #0x10
	bl ov01_021EC504
	ldr r0, _021ED304 ; =0x0000716F
	mov r2, #0x41
	str r0, [sp]
	ldr r0, _021ED308 ; =0x00006B5A
	lsl r2, r2, #2
	str r0, [sp, #4]
	mov r0, #1
	str r0, [sp, #8]
	ldr r0, _021ED30C ; =0x00000F64
	add r1, r4, #0
	ldrh r0, [r5, r0]
	add r1, #0x1c
	str r0, [sp, #0xc]
	ldr r3, [r5]
	add r0, r4, #0
	ldr r2, [r3, r2]
	add r0, #0x4c
	ldr r2, [r2, #0x4c]
	mov r3, #3
	bl ov01_021EC5FC
	mov r0, #0
	add r4, #0xb4
	str r0, [r4]
	ldr r0, _021ED310 ; =0x00000F62
	mov r1, #1
	strh r1, [r5, r0]
	b _021ED2D2
_021ED172:
	add r0, r4, #0
	bl ov01_021EC538
	add r6, r0, #0
	add r0, r4, #0
	add r0, #0xb4
	ldr r0, [r0]
	cmp r0, #0
	ble _021ED192
	add r0, r4, #0
	add r0, #0xb4
	ldr r0, [r0]
	add r4, #0xb4
	sub r0, r0, #1
	str r0, [r4]
	b _021ED2D2
_021ED192:
	ldr r2, _021ED30C ; =0x00000F64
	add r0, r4, #0
	ldrh r2, [r5, r2]
	add r4, #0x1c
	add r0, #0x4c
	add r1, r4, #0
	bl ov01_021EC650
	cmp r0, #1
	bne _021ED1AA
	cmp r6, #3
	beq _021ED1AC
_021ED1AA:
	b _021ED2D2
_021ED1AC:
	ldr r0, _021ED310 ; =0x00000F62
	mov r1, #3
	strh r1, [r5, r0]
	b _021ED2D2
_021ED1B4:
	mov r2, #0x14
	mov r3, #2
	str r2, [sp]
	str r3, [sp, #4]
	sub r0, r3, #4
	str r0, [sp, #8]
	mov r0, #4
	str r0, [sp, #0xc]
	ldr r0, _021ED300 ; =ov01_021ED31C
	str r3, [sp, #0x10]
	str r0, [sp, #0x14]
	add r0, r4, #0
	bl ov01_021EC504
	ldr r0, _021ED30C ; =0x00000F64
	ldrh r0, [r5, r0]
	cmp r0, #0
	beq _021ED1F6
	mov r0, #0x41
	ldr r1, [r5]
	lsl r0, r0, #2
	ldr r0, [r1, r0]
	ldr r2, _021ED304 ; =0x0000716F
	ldr r0, [r0, #0x4c]
	ldr r3, _021ED308 ; =0x00006B5A
	mov r1, #3
	str r0, [r4, #0x1c]
	bl ov01_021EC678
	add r4, #0x1c
	add r0, r4, #0
	bl ov01_021EC7C8
_021ED1F6:
	mov r0, #1
	str r0, [sp]
	ldr r0, _021ED314 ; =ov01_021ED44C
	ldr r1, _021ED300 ; =ov01_021ED31C
	str r0, [sp, #4]
	add r0, r5, #0
	mov r2, #0x14
	mov r3, #0xa
	bl ov01_021EC85C
	ldr r0, _021ED310 ; =0x00000F62
	mov r1, #3
	strh r1, [r5, r0]
	b _021ED2D2
_021ED212:
	mov r0, #6
	ldrsh r1, [r4, r0]
	sub r0, r1, #1
	strh r0, [r4, #6]
	cmp r1, #0
	bgt _021ED22E
	mov r1, #4
	ldrsh r1, [r4, r1]
	add r0, r5, #0
	bl ov01_021ED31C
	mov r0, #8
	ldrsh r0, [r4, r0]
	strh r0, [r4, #6]
_021ED22E:
	ldr r0, _021ED318 ; =0x00000F66
	ldrh r0, [r5, r0]
	cmp r0, #5
	bne _021ED2D2
	mov r0, #9
	mvn r0, r0
	str r0, [sp]
	add r0, r4, #0
	mov r1, #0
	mov r2, #0x10
	mov r3, #6
	bl ov01_021EC52C
	ldr r0, _021ED30C ; =0x00000F64
	ldrh r0, [r5, r0]
	cmp r0, #0
	beq _021ED25C
	add r0, r4, #0
	add r0, #0x1c
	mov r1, #1
	mov r2, #0
	bl ov01_021EC790
_021ED25C:
	mov r0, #0x14
	add r4, #0xb4
	str r0, [r4]
	ldr r0, _021ED310 ; =0x00000F62
	mov r1, #4
	strh r1, [r5, r0]
	b _021ED2D2
_021ED26A:
	add r0, r4, #0
	bl ov01_021EC538
	add r6, r0, #0
	add r0, r4, #0
	add r0, #0xb4
	ldr r0, [r0]
	cmp r0, #0
	ble _021ED28A
	add r0, r4, #0
	add r0, #0xb4
	ldr r0, [r0]
	add r4, #0xb4
	sub r0, r0, #1
	str r0, [r4]
	b _021ED2D2
_021ED28A:
	ldr r2, _021ED30C ; =0x00000F64
	add r0, r4, #0
	ldrh r2, [r5, r2]
	add r4, #0x1c
	add r0, #0x4c
	add r1, r4, #0
	bl ov01_021EC650
	cmp r0, #1
	bne _021ED2D2
	cmp r6, #3
	bne _021ED2D2
	add r0, r5, #0
	ldr r1, [r5, #0x40]
	add r0, #0xc
	cmp r1, r0
	bne _021ED2D2
	ldr r0, _021ED310 ; =0x00000F62
	mov r1, #5
	strh r1, [r5, r0]
	b _021ED2D2
_021ED2B4:
	add r0, #0xc
	ldrh r0, [r5, r0]
	cmp r0, #0
	beq _021ED2CC
	mov r2, #0
	str r2, [sp]
	str r2, [sp, #4]
	ldr r0, [r4, #0x1c]
	mov r1, #1
	add r3, r2, #0
	bl ov01_021EA864
_021ED2CC:
	ldr r0, [r5, #4]
	bl ov01_021EBCA4
_021ED2D2:
	ldr r0, _021ED310 ; =0x00000F62
	ldrh r0, [r5, r0]
	cmp r0, #5
	beq _021ED2F8
	cmp r0, #0
	beq _021ED2F8
	add r0, r5, #0
	ldr r1, _021ED314 ; =ov01_021ED44C
	add r0, #0xc
	bl ov01_021EC2E4
	mov r1, #0
	add r0, r5, #0
	add r2, r1, #0
	bl ov01_021EC470
	add r0, r5, #0
	bl ov01_021EC300
_021ED2F8:
	add sp, #0x18
	pop {r4, r5, r6, pc}
	.balign 4, 0
_021ED2FC: .word 0x00000F58
_021ED300: .word ov01_021ED31C
_021ED304: .word 0x0000716F
_021ED308: .word 0x00006B5A
_021ED30C: .word 0x00000F64
_021ED310: .word 0x00000F62
_021ED314: .word ov01_021ED44C
_021ED318: .word 0x00000F66
	thumb_func_end ov01_021ED0F0

	thumb_func_start ov01_021ED31C
ov01_021ED31C: ; 0x021ED31C
	push {r4, r5, r6, r7, lr}
	sub sp, #0x1c
	str r0, [sp]
	mov r0, #0
	str r0, [sp, #0xc]
	add r0, r1, #0
	str r1, [sp, #4]
	cmp r0, #0
	bgt _021ED330
	b _021ED448
_021ED330:
	ldr r0, [sp]
	mov r1, #0x20
	bl ov01_021EC1F4
	add r4, r0, #0
	bne _021ED33E
	b _021ED448
_021ED33E:
	ldr r5, [r4, #8]
	mov r0, #0
	str r0, [r5]
	bl MTRandom
	mov r1, #5
	bl _u32_div_f
	add r0, r1, #7
	str r0, [r5, #4]
	bl MTRandom
	mov r1, #0xfa
	lsl r1, r1, #2
	bl _u32_div_f
	lsr r2, r1, #0x1f
	lsl r1, r1, #0x1f
	sub r1, r1, r2
	mov r0, #0x1f
	ror r1, r0
	add r0, r2, r1
	bne _021ED370
	mov r0, #1
	b _021ED374
_021ED370:
	mov r0, #0
	mvn r0, r0
_021ED374:
	str r0, [r5, #8]
	mov r0, #1
	str r0, [r5, #0xc]
	bl MTRandom
	mov r1, #6
	bl _u32_div_f
	add r0, r1, #3
	str r0, [r5, #0x10]
	bl MTRandom
	mov r1, #5
	bl _u32_div_f
	add r0, r1, #4
	str r0, [r5, #0x14]
	bl MTRandom
	mov r1, #0x14
	bl _u32_div_f
	str r1, [sp, #8]
	add r0, sp, #0x10
	add r1, r4, #0
	bl ov01_021EC304
	bl MTRandom
	mov r1, #6
	lsl r1, r1, #6
	bl _u32_div_f
	sub r1, #0x40
	str r1, [sp, #0x10]
	bl MTRandom
	lsl r0, r0, #0x18
	lsr r1, r0, #0x18
	ldr r0, [sp, #0x10]
	sub r1, #8
	lsl r0, r0, #0xc
	str r0, [sp, #0x10]
	str r1, [sp, #0x14]
	lsl r0, r1, #0xc
	str r0, [sp, #0x14]
	mov r0, #0
	str r0, [sp, #0x18]
	ldr r0, [r4, #4]
	add r1, sp, #0x10
	bl ov01_021EB5F4
	ldr r1, [sp, #0x14]
	ldr r0, [sp, #0x10]
	asr r1, r1, #0xc
	asr r0, r0, #0xc
	str r1, [sp, #0x14]
	mov r1, #3
	str r0, [sp, #0x10]
	bl _s32_div_f
	mov r1, #0x32
	sub r6, r1, r0
	mov r1, #0xce
	sub r7, r1, r0
	bpl _021ED406
	bl MTRandom
	neg r1, r7
	bl _u32_div_f
	sub r1, r6, r1
	b _021ED412
_021ED406:
	bl MTRandom
	add r1, r7, #0
	bl _u32_div_f
	add r1, r6, r1
_021ED412:
	ldr r0, [sp, #0x14]
	cmp r6, r0
	bgt _021ED424
	cmp r1, r0
	blt _021ED424
	ldr r0, [r5, #4]
	lsl r0, r0, #1
	str r0, [r5, #4]
	b _021ED42E
_021ED424:
	bl MTRandom
	mov r1, #3
	and r0, r1
	str r0, [sp, #8]
_021ED42E:
	ldr r1, [sp, #8]
	ldr r0, [r4, #4]
	lsl r1, r1, #0x10
	lsr r1, r1, #0x10
	bl Sprite_SetAnimationFrame
	ldr r0, [sp, #0xc]
	add r1, r0, #1
	ldr r0, [sp, #4]
	str r1, [sp, #0xc]
	cmp r1, r0
	bge _021ED448
	b _021ED330
_021ED448:
	add sp, #0x1c
	pop {r4, r5, r6, r7, pc}
	thumb_func_end ov01_021ED31C

	thumb_func_start ov01_021ED44C
ov01_021ED44C: ; 0x021ED44C
	push {r4, r5, lr}
	sub sp, #0xc
	add r5, r0, #0
	ldr r4, [r5, #8]
	add r0, sp, #0
	add r1, r5, #0
	bl ov01_021EC304
	ldr r0, [r4]
	add r1, r0, #1
	str r1, [r4]
	ldr r0, [r4, #4]
	cmp r1, r0
	blt _021ED46E
	add r0, r5, #0
	bl ov01_021EC29C
_021ED46E:
	add sp, #0xc
	pop {r4, r5, pc}
	.balign 4, 0
	thumb_func_end ov01_021ED44C

	thumb_func_start ov01_021ED474
ov01_021ED474: ; 0x021ED474
	push {r4, r5, r6, lr}
	sub sp, #0x10
	add r6, r2, #0
	ldr r2, _021ED580 ; =0x00000F62
	add r4, r0, #0
	ldrh r0, [r4, r2]
	add r5, r1, #0
	cmp r0, #5
	bhi _021ED57A
	add r0, r0, r0
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_021ED492: ; jump table
	.short _021ED49E - _021ED492 - 2 ; case 0
	.short _021ED4CE - _021ED492 - 2 ; case 1
	.short _021ED4E8 - _021ED492 - 2 ; case 2
	.short _021ED518 - _021ED492 - 2 ; case 3
	.short _021ED53C - _021ED492 - 2 ; case 4
	.short _021ED55C - _021ED492 - 2 ; case 5
_021ED49E:
	str r3, [sp]
	add r0, sp, #0x10
	ldrh r0, [r0, #0x10]
	add r5, #0x30
	str r0, [sp, #4]
	ldr r0, [sp, #0x24]
	str r0, [sp, #8]
	add r0, r2, #2
	ldrh r0, [r4, r0]
	mov r2, #0x41
	lsl r2, r2, #2
	str r0, [sp, #0xc]
	ldr r3, [r4]
	add r0, r5, #0
	ldr r2, [r3, r2]
	add r3, r6, #0
	ldr r2, [r2, #0x4c]
	bl ov01_021EC5FC
	ldr r0, _021ED580 ; =0x00000F62
	mov r1, #1
	add sp, #0x10
	strh r1, [r4, r0]
	pop {r4, r5, r6, pc}
_021ED4CE:
	add r2, r2, #2
	ldrh r2, [r4, r2]
	add r5, #0x30
	add r0, r5, #0
	bl ov01_021EC650
	cmp r0, #1
	bne _021ED57A
	ldr r0, _021ED580 ; =0x00000F62
	mov r1, #3
	add sp, #0x10
	strh r1, [r4, r0]
	pop {r4, r5, r6, pc}
_021ED4E8:
	add r0, r2, #2
	ldrh r0, [r4, r0]
	cmp r0, #0
	beq _021ED50E
	mov r0, #0x41
	ldr r1, [r4]
	lsl r0, r0, #2
	ldr r0, [r1, r0]
	add r2, r3, #0
	ldr r0, [r0, #0x4c]
	add r3, sp, #0x10
	str r0, [r5]
	ldrh r3, [r3, #0x10]
	add r1, r6, #0
	bl ov01_021EC678
	add r0, r5, #0
	bl ov01_021EC7C8
_021ED50E:
	ldr r0, _021ED580 ; =0x00000F62
	mov r1, #3
	add sp, #0x10
	strh r1, [r4, r0]
	pop {r4, r5, r6, pc}
_021ED518:
	add r0, r2, #4
	ldrh r0, [r4, r0]
	cmp r0, #5
	bne _021ED57A
	add r0, r2, #2
	ldrh r0, [r4, r0]
	cmp r0, #0
	beq _021ED532
	ldr r1, [sp, #0x28]
	add r0, r5, #0
	mov r2, #0
	bl ov01_021EC790
_021ED532:
	ldr r0, _021ED580 ; =0x00000F62
	mov r1, #4
	add sp, #0x10
	strh r1, [r4, r0]
	pop {r4, r5, r6, pc}
_021ED53C:
	add r0, r2, #2
	ldrh r0, [r4, r0]
	cmp r0, #0
	beq _021ED54C
	add r0, r5, #0
	bl ov01_021EC7AC
	b _021ED54E
_021ED54C:
	mov r0, #1
_021ED54E:
	cmp r0, #1
	bne _021ED57A
	ldr r0, _021ED580 ; =0x00000F62
	mov r1, #5
	add sp, #0x10
	strh r1, [r4, r0]
	pop {r4, r5, r6, pc}
_021ED55C:
	add r0, r2, #2
	ldrh r0, [r4, r0]
	cmp r0, #0
	beq _021ED574
	mov r2, #0
	str r2, [sp]
	str r2, [sp, #4]
	ldr r0, [r5]
	mov r1, #1
	add r3, r2, #0
	bl ov01_021EA864
_021ED574:
	ldr r0, [r4, #4]
	bl ov01_021EBCA4
_021ED57A:
	add sp, #0x10
	pop {r4, r5, r6, pc}
	nop
_021ED580: .word 0x00000F62
	thumb_func_end ov01_021ED474

	thumb_func_start ov01_021ED584
ov01_021ED584: ; 0x021ED584
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x10
	ldr r0, _021ED700 ; =0x00000F58
	add r4, r1, #0
	add r1, r0, #0
	add r1, #0xa
	ldrh r1, [r4, r1]
	ldr r5, [r4, r0]
	cmp r1, #5
	bls _021ED59A
	b _021ED6FC
_021ED59A:
	add r1, r1, r1
	add r1, pc
	ldrh r1, [r1, #6]
	lsl r1, r1, #0x10
	asr r1, r1, #0x10
	add pc, r1
_021ED5A6: ; jump table
	.short _021ED5B2 - _021ED5A6 - 2 ; case 0
	.short _021ED602 - _021ED5A6 - 2 ; case 1
	.short _021ED630 - _021ED5A6 - 2 ; case 2
	.short _021ED670 - _021ED5A6 - 2 ; case 3
	.short _021ED6A4 - _021ED5A6 - 2 ; case 4
	.short _021ED6DE - _021ED5A6 - 2 ; case 5
_021ED5B2:
	ldr r1, _021ED704 ; =0x00007555
	mov r2, #0x41
	str r1, [sp]
	ldr r1, _021ED708 ; =0x00007FFF
	add r0, #0xc
	str r1, [sp, #4]
	mov r1, #1
	str r1, [sp, #8]
	ldrh r0, [r4, r0]
	add r1, r5, #0
	lsl r2, r2, #2
	str r0, [sp, #0xc]
	ldr r3, [r4]
	add r0, r5, #0
	ldr r2, [r3, r2]
	add r0, #0x44
	ldr r2, [r2, #0x4c]
	add r1, #0x14
	mov r3, #6
	bl ov01_021EC5FC
	add r0, r5, #0
	mov r1, #0
	mov r2, #9
	mov r3, #0x1e
	bl ov01_021EB830
	mov r0, #0
	mov r1, #0x10
	bl ov01_021EB818
	mov r0, #4
	mov r1, #1
	bl GfGfx_EngineATogglePlanes
	ldr r0, _021ED70C ; =0x00000F62
	mov r1, #1
	add sp, #0x10
	strh r1, [r4, r0]
	pop {r3, r4, r5, r6, r7, pc}
_021ED602:
	add r0, r5, #0
	add r0, #0x14
	bl ov01_021EC7AC
	add r6, r0, #0
	add r0, r5, #0
	bl ov01_021EB840
	add r7, r0, #0
	ldr r0, [r5]
	mov r1, #0x10
	sub r1, r1, r0
	bl ov01_021EB818
	cmp r6, #1
	bne _021ED6FC
	cmp r7, #1
	bne _021ED6FC
	ldr r0, _021ED70C ; =0x00000F62
	mov r1, #3
	add sp, #0x10
	strh r1, [r4, r0]
	pop {r3, r4, r5, r6, r7, pc}
_021ED630:
	add r0, #0xc
	ldrh r0, [r4, r0]
	cmp r0, #0
	beq _021ED656
	mov r0, #0x41
	ldr r1, [r4]
	lsl r0, r0, #2
	ldr r0, [r1, r0]
	ldr r2, _021ED704 ; =0x00007555
	ldr r0, [r0, #0x4c]
	ldr r3, _021ED708 ; =0x00007FFF
	mov r1, #6
	str r0, [r5, #0x14]
	bl ov01_021EC678
	add r5, #0x14
	add r0, r5, #0
	bl ov01_021EC7C8
_021ED656:
	mov r0, #9
	mov r1, #7
	bl ov01_021EB818
	mov r0, #4
	mov r1, #1
	bl GfGfx_EngineATogglePlanes
	ldr r0, _021ED70C ; =0x00000F62
	mov r1, #3
	add sp, #0x10
	strh r1, [r4, r0]
	pop {r3, r4, r5, r6, r7, pc}
_021ED670:
	add r1, r0, #0
	add r1, #0xe
	ldrh r1, [r4, r1]
	cmp r1, #5
	bne _021ED6FC
	add r0, #0xc
	ldrh r0, [r4, r0]
	cmp r0, #0
	beq _021ED68E
	add r0, r5, #0
	add r0, #0x14
	mov r1, #1
	mov r2, #0
	bl ov01_021EC790
_021ED68E:
	add r0, r5, #0
	mov r1, #9
	mov r2, #0
	mov r3, #0x1e
	bl ov01_021EB830
	ldr r0, _021ED70C ; =0x00000F62
	mov r1, #4
	add sp, #0x10
	strh r1, [r4, r0]
	pop {r3, r4, r5, r6, r7, pc}
_021ED6A4:
	add r0, #0xc
	ldrh r0, [r4, r0]
	cmp r0, #0
	beq _021ED6B8
	add r0, r5, #0
	add r0, #0x14
	bl ov01_021EC7AC
	add r6, r0, #0
	b _021ED6BA
_021ED6B8:
	mov r6, #1
_021ED6BA:
	add r0, r5, #0
	bl ov01_021EB840
	add r7, r0, #0
	ldr r0, [r5]
	mov r1, #0x10
	sub r1, r1, r0
	bl ov01_021EB818
	cmp r6, #1
	bne _021ED6FC
	cmp r7, #1
	bne _021ED6FC
	ldr r0, _021ED70C ; =0x00000F62
	mov r1, #5
	add sp, #0x10
	strh r1, [r4, r0]
	pop {r3, r4, r5, r6, r7, pc}
_021ED6DE:
	add r0, #0xc
	ldrh r0, [r4, r0]
	cmp r0, #0
	beq _021ED6F6
	mov r2, #0
	str r2, [sp]
	str r2, [sp, #4]
	ldr r0, [r5, #0x14]
	mov r1, #1
	add r3, r2, #0
	bl ov01_021EA864
_021ED6F6:
	ldr r0, [r4, #4]
	bl ov01_021EBCA4
_021ED6FC:
	add sp, #0x10
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_021ED700: .word 0x00000F58
_021ED704: .word 0x00007555
_021ED708: .word 0x00007FFF
_021ED70C: .word 0x00000F62
	thumb_func_end ov01_021ED584

	thumb_func_start ov01_021ED710
ov01_021ED710: ; 0x021ED710
	push {r3, r4, r5, r6, lr}
	sub sp, #0x4c
	add r6, r1, #0
	mov r0, #0x41
	ldr r1, [r6]
	lsl r0, r0, #2
	ldr r5, [r1, r0]
	ldr r0, _021ED900 ; =0x00000F58
	add r1, r0, #0
	add r1, #0xa
	ldrh r1, [r6, r1]
	ldr r4, [r6, r0]
	cmp r1, #5
	bls _021ED72E
	b _021ED8FA
_021ED72E:
	add r1, r1, r1
	add r1, pc
	ldrh r1, [r1, #6]
	lsl r1, r1, #0x10
	asr r1, r1, #0x10
	add pc, r1
_021ED73A: ; jump table
	.short _021ED746 - _021ED73A - 2 ; case 0
	.short _021ED79E - _021ED73A - 2 ; case 1
	.short _021ED7A8 - _021ED73A - 2 ; case 2
	.short _021ED800 - _021ED73A - 2 ; case 3
	.short _021ED81A - _021ED73A - 2 ; case 4
	.short _021ED8F4 - _021ED73A - 2 ; case 5
_021ED746:
	ldr r0, [r5, #0x40]
	bl PlayerAvatar_GetMapObject
	bl ov01_02203EA0
	ldr r1, _021ED904 ; =0x0000062C
	mov r3, #0
	str r0, [r4, r1]
	mov r0, #0xa
	str r0, [sp]
	str r3, [sp, #4]
	ldr r0, [r5, #0x4c]
	sub r1, r3, #1
	mov r2, #1
	bl ov01_021EA864
	mov r1, #0
	mov r2, #0
	ldr r0, [r5, #0x4c]
	mvn r1, r1
	add r3, r2, #0
	bl ov01_021EA89C
	mov r1, #0
	add r2, sp, #0x2c
	sub r0, r1, #1
_021ED77A:
	add r1, r1, #1
	strb r0, [r2]
	add r2, r2, #1
	cmp r1, #0x20
	blt _021ED77A
	ldr r0, [r5, #0x4c]
	add r1, sp, #0x2c
	bl ov01_021EA8C4
	mov r0, #0x63
	mov r1, #0
	lsl r0, r0, #4
	strh r1, [r4, r0]
	ldr r0, _021ED908 ; =0x00000F62
	mov r1, #1
	add sp, #0x4c
	strh r1, [r6, r0]
	pop {r3, r4, r5, r6, pc}
_021ED79E:
	mov r1, #3
	add r0, #0xa
	add sp, #0x4c
	strh r1, [r6, r0]
	pop {r3, r4, r5, r6, pc}
_021ED7A8:
	ldr r0, [r5, #0x40]
	bl PlayerAvatar_GetMapObject
	bl ov01_02203EA0
	ldr r1, _021ED904 ; =0x0000062C
	mov r3, #0
	str r0, [r4, r1]
	mov r0, #0xa
	str r0, [sp]
	str r3, [sp, #4]
	ldr r0, [r5, #0x4c]
	sub r1, r3, #1
	mov r2, #1
	bl ov01_021EA864
	mov r1, #0
	mov r2, #0
	ldr r0, [r5, #0x4c]
	mvn r1, r1
	add r3, r2, #0
	bl ov01_021EA89C
	mov r1, #0
	add r2, sp, #0xc
	sub r0, r1, #1
_021ED7DC:
	add r1, r1, #1
	strb r0, [r2]
	add r2, r2, #1
	cmp r1, #0x20
	blt _021ED7DC
	ldr r0, [r5, #0x4c]
	add r1, sp, #0xc
	bl ov01_021EA8C4
	mov r0, #0x63
	mov r1, #0
	lsl r0, r0, #4
	strh r1, [r4, r0]
	ldr r0, _021ED908 ; =0x00000F62
	mov r1, #3
	add sp, #0x4c
	strh r1, [r6, r0]
	pop {r3, r4, r5, r6, pc}
_021ED800:
	add r1, r0, #0
	add r1, #0xe
	ldrh r1, [r6, r1]
	cmp r1, #5
	bne _021ED8FA
	ldr r1, _021ED90C ; =0x00000632
	mov r2, #0
	strh r2, [r4, r1]
	mov r1, #4
	add r0, #0xa
	add sp, #0x4c
	strh r1, [r6, r0]
	pop {r3, r4, r5, r6, pc}
_021ED81A:
	ldr r0, _021ED90C ; =0x00000632
	ldrh r1, [r4, r0]
	cmp r1, #3
	bhi _021ED8FA
	add r1, r1, r1
	add r1, pc
	ldrh r1, [r1, #6]
	lsl r1, r1, #0x10
	asr r1, r1, #0x10
	add pc, r1
_021ED82E: ; jump table
	.short _021ED836 - _021ED82E - 2 ; case 0
	.short _021ED85A - _021ED82E - 2 ; case 1
	.short _021ED884 - _021ED82E - 2 ; case 2
	.short _021ED898 - _021ED82E - 2 ; case 3
_021ED836:
	mov r0, #6
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	mov r0, #4
	mov r1, #0
	str r0, [sp, #8]
	ldr r3, _021ED910 ; =0x00007FFF
	mov r0, #3
	add r2, r1, #0
	bl BeginNormalPaletteFade
	ldr r0, _021ED90C ; =0x00000632
	add sp, #0x4c
	ldrh r1, [r4, r0]
	add r1, r1, #1
	strh r1, [r4, r0]
	pop {r3, r4, r5, r6, pc}
_021ED85A:
	bl IsPaletteFadeFinished
	cmp r0, #0
	beq _021ED8FA
	mov r0, #6
	str r0, [sp]
	mov r1, #1
	str r1, [sp, #4]
	mov r0, #4
	str r0, [sp, #8]
	ldr r3, _021ED910 ; =0x00007FFF
	mov r0, #3
	add r2, r1, #0
	bl BeginNormalPaletteFade
	ldr r0, _021ED90C ; =0x00000632
	add sp, #0x4c
	ldrh r1, [r4, r0]
	add r1, r1, #1
	strh r1, [r4, r0]
	pop {r3, r4, r5, r6, pc}
_021ED884:
	bl IsPaletteFadeFinished
	cmp r0, #0
	beq _021ED8FA
	ldr r0, _021ED90C ; =0x00000632
	add sp, #0x4c
	ldrh r1, [r4, r0]
	add r1, r1, #1
	strh r1, [r4, r0]
	pop {r3, r4, r5, r6, pc}
_021ED898:
	sub r1, r0, #2
	ldrh r1, [r4, r1]
	add r2, r1, #1
	sub r1, r0, #2
	strh r2, [r4, r1]
	sub r0, r0, #2
	ldrh r0, [r4, r0]
	bl _dfltu
	add r3, r1, #0
	add r2, r0, #0
	ldr r1, _021ED914 ; =0x40080000
	mov r0, #0
	bl _dmul
	ldr r3, _021ED918 ; =0x40380000
	mov r2, #0
	bl _ddiv
	add r3, r1, #0
	add r2, r0, #0
	ldr r1, _021ED91C ; =0x3FF00000
	mov r0, #0
	bl _dadd
	bl _d2f
	add r5, r0, #0
	ldr r0, _021ED904 ; =0x0000062C
	add r1, r5, #0
	ldr r0, [r4, r0]
	bl ov01_02203F2C
	add r0, r5, #0
	bl _f2d
	ldr r3, _021ED920 ; =0x40100000
	mov r2, #0
	bl _dgeq
	blo _021ED8FA
	ldr r0, _021ED908 ; =0x00000F62
	mov r1, #5
	add sp, #0x4c
	strh r1, [r6, r0]
	pop {r3, r4, r5, r6, pc}
_021ED8F4:
	ldr r0, [r6, #4]
	bl ov01_021EBCA4
_021ED8FA:
	add sp, #0x4c
	pop {r3, r4, r5, r6, pc}
	nop
_021ED900: .word 0x00000F58
_021ED904: .word 0x0000062C
_021ED908: .word 0x00000F62
_021ED90C: .word 0x00000632
_021ED910: .word 0x00007FFF
_021ED914: .word 0x40080000
_021ED918: .word 0x40380000
_021ED91C: .word 0x3FF00000
_021ED920: .word 0x40100000
	thumb_func_end ov01_021ED710

	thumb_func_start ov01_021ED924
ov01_021ED924: ; 0x021ED924
	push {r4, r5, r6, lr}
	sub sp, #0x48
	add r5, r1, #0
	mov r0, #0x41
	ldr r1, [r5]
	lsl r0, r0, #2
	ldr r4, [r1, r0]
	ldr r0, _021EDA40 ; =0x00000F58
	add r1, r0, #0
	add r1, #0xa
	ldrh r1, [r5, r1]
	ldr r6, [r5, r0]
	cmp r1, #5
	bhi _021EDA3A
	add r1, r1, r1
	add r1, pc
	ldrh r1, [r1, #6]
	lsl r1, r1, #0x10
	asr r1, r1, #0x10
	add pc, r1
_021ED94C: ; jump table
	.short _021ED958 - _021ED94C - 2 ; case 0
	.short _021ED9B2 - _021ED94C - 2 ; case 1
	.short _021ED9BC - _021ED94C - 2 ; case 2
	.short _021EDA16 - _021ED94C - 2 ; case 3
	.short _021EDA2A - _021ED94C - 2 ; case 4
	.short _021EDA34 - _021ED94C - 2 ; case 5
_021ED958:
	ldr r0, [r4, #0x40]
	bl PlayerAvatar_GetMapObject
	bl ov01_02203EA0
	ldr r1, _021EDA44 ; =0x0000062C
	mov r3, #0
	str r0, [r6, r1]
	mov r0, #0xa
	str r0, [sp]
	str r3, [sp, #4]
	ldr r0, [r4, #0x4c]
	sub r1, r3, #1
	mov r2, #1
	bl ov01_021EA864
	mov r1, #0
	mov r2, #0
	ldr r0, [r4, #0x4c]
	mvn r1, r1
	add r3, r2, #0
	bl ov01_021EA89C
	mov r1, #0
	add r2, sp, #0x28
	sub r0, r1, #1
_021ED98C:
	add r1, r1, #1
	strb r0, [r2]
	add r2, r2, #1
	cmp r1, #0x20
	blt _021ED98C
	ldr r0, [r4, #0x4c]
	add r1, sp, #0x28
	bl ov01_021EA8C4
	ldr r0, _021EDA44 ; =0x0000062C
	ldr r1, _021EDA48 ; =0x40800000
	ldr r0, [r6, r0]
	bl ov01_02203F2C
	ldr r0, _021EDA4C ; =0x00000F62
	mov r1, #1
	add sp, #0x48
	strh r1, [r5, r0]
	pop {r4, r5, r6, pc}
_021ED9B2:
	mov r1, #3
	add r0, #0xa
	add sp, #0x48
	strh r1, [r5, r0]
	pop {r4, r5, r6, pc}
_021ED9BC:
	ldr r0, [r4, #0x40]
	bl PlayerAvatar_GetMapObject
	bl ov01_02203EA0
	ldr r1, _021EDA44 ; =0x0000062C
	mov r3, #0
	str r0, [r6, r1]
	mov r0, #0xa
	str r0, [sp]
	str r3, [sp, #4]
	ldr r0, [r4, #0x4c]
	sub r1, r3, #1
	mov r2, #1
	bl ov01_021EA864
	mov r1, #0
	mov r2, #0
	ldr r0, [r4, #0x4c]
	mvn r1, r1
	add r3, r2, #0
	bl ov01_021EA89C
	mov r1, #0
	add r2, sp, #8
	sub r0, r1, #1
_021ED9F0:
	add r1, r1, #1
	strb r0, [r2]
	add r2, r2, #1
	cmp r1, #0x20
	blt _021ED9F0
	ldr r0, [r4, #0x4c]
	add r1, sp, #8
	bl ov01_021EA8C4
	ldr r0, _021EDA44 ; =0x0000062C
	ldr r1, _021EDA48 ; =0x40800000
	ldr r0, [r6, r0]
	bl ov01_02203F2C
	ldr r0, _021EDA4C ; =0x00000F62
	mov r1, #3
	add sp, #0x48
	strh r1, [r5, r0]
	pop {r4, r5, r6, pc}
_021EDA16:
	add r1, r0, #0
	add r1, #0xe
	ldrh r1, [r5, r1]
	cmp r1, #5
	bne _021EDA3A
	mov r1, #4
	add r0, #0xa
	add sp, #0x48
	strh r1, [r5, r0]
	pop {r4, r5, r6, pc}
_021EDA2A:
	mov r1, #5
	add r0, #0xa
	add sp, #0x48
	strh r1, [r5, r0]
	pop {r4, r5, r6, pc}
_021EDA34:
	ldr r0, [r5, #4]
	bl ov01_021EBCA4
_021EDA3A:
	add sp, #0x48
	pop {r4, r5, r6, pc}
	nop
_021EDA40: .word 0x00000F58
_021EDA44: .word 0x0000062C
_021EDA48: .word 0x40800000
_021EDA4C: .word 0x00000F62
	thumb_func_end ov01_021ED924

	thumb_func_start ov01_021EDA50
ov01_021EDA50: ; 0x021EDA50
	push {lr}
	sub sp, #0xc
	ldr r0, _021EDA70 ; =0x00000421
	ldr r2, _021EDA74 ; =0x00000F58
	str r0, [sp]
	mov r0, #0
	str r0, [sp, #4]
	str r0, [sp, #8]
	add r0, r1, #0
	ldr r1, [r1, r2]
	ldr r3, _021EDA78 ; =0x00004B6F
	mov r2, #1
	bl ov01_021ED474
	add sp, #0xc
	pop {pc}
	.balign 4, 0
_021EDA70: .word 0x00000421
_021EDA74: .word 0x00000F58
_021EDA78: .word 0x00004B6F
	thumb_func_end ov01_021EDA50

	thumb_func_start ov01_021EDA7C
ov01_021EDA7C: ; 0x021EDA7C
	push {r3, r4, r5, lr}
	add r5, r0, #0
	ldr r0, _021EDAA8 ; =0x00000F68
	add r4, r1, #0
	ldr r1, [r4, r0]
	sub r1, r1, #1
	str r1, [r4, r0]
	ldr r0, [r4, r0]
	cmp r0, #0
	bgt _021EDAA4
	ldr r1, _021EDAAC ; =0x00000638
	add r0, r4, #0
	bl ov01_021EDAB4
	add r0, r5, #0
	bl SysTask_Destroy
	ldr r0, _021EDAB0 ; =0x00000F6C
	mov r1, #0
	str r1, [r4, r0]
_021EDAA4:
	pop {r3, r4, r5, pc}
	nop
_021EDAA8: .word 0x00000F68
_021EDAAC: .word 0x00000638
_021EDAB0: .word 0x00000F6C
	thumb_func_end ov01_021EDA7C

	thumb_func_start ov01_021EDAB4
ov01_021EDAB4: ; 0x021EDAB4
	push {r3, r4, r5, lr}
	add r5, r0, #0
	ldr r0, _021EDADC ; =0x00000F5C
	add r4, r1, #0
	ldr r0, [r5, r0]
	cmp r0, #0
	beq _021EDAC6
	bl GF_AssertFail
_021EDAC6:
	ldr r1, _021EDADC ; =0x00000F5C
	mov r0, #1
	str r0, [r5, r1]
	lsl r0, r4, #0x10
	lsr r0, r0, #0x10
	add r1, r1, #4
	strh r0, [r5, r1]
	bl PlaySE
	pop {r3, r4, r5, pc}
	nop
_021EDADC: .word 0x00000F5C
	thumb_func_end ov01_021EDAB4

	thumb_func_start ov01_021EDAE0
ov01_021EDAE0: ; 0x021EDAE0
	push {r4, lr}
	add r4, r0, #0
	mov r0, #0xf6
	lsl r0, r0, #4
	ldrh r0, [r4, r0]
	mov r1, #0
	bl StopSE
	ldr r0, _021EDAF8 ; =0x00000F5C
	mov r1, #0
	str r1, [r4, r0]
	pop {r4, pc}
	.balign 4, 0
_021EDAF8: .word 0x00000F5C
	thumb_func_end ov01_021EDAE0

	.rodata

ov01_0220673C: ; 0x0220673C
	.word 16, 32, 16, 10

ov01_0220674C: ; 0x0220674C
	.word 2, 2, 2, 2
.public ov01_0220675C
ov01_0220675C: ; 0x0220675C
	.byte 0x15, 0x00, 0x00, 0x00
	.byte 0x24, 0x00, 0x00, 0x00, 0x26, 0x00, 0x00, 0x00, 0x25, 0x00, 0x00, 0x00, 0x24, 0x00, 0x00, 0x00
	.byte 0x26, 0x00, 0x00, 0x00, 0x09, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x0A, 0x00, 0x00, 0x00
	.byte 0x2A, 0x00, 0x00, 0x00, 0x2C, 0x00, 0x00, 0x00, 0x2B, 0x00, 0x00, 0x00, 0x1E, 0x00, 0x00, 0x00
	.byte 0x1D, 0x00, 0x00, 0x00, 0x1F, 0x00, 0x00, 0x00, 0x2E, 0x00, 0x00, 0x00, 0x2D, 0x00, 0x00, 0x00
	.byte 0x2F, 0x00, 0x00, 0x00, 0x33, 0x00, 0x00, 0x00, 0x2D, 0x00, 0x00, 0x00, 0x2F, 0x00, 0x00, 0x00
	.byte 0x34, 0x00, 0x00, 0x00, 0x35, 0x00, 0x00, 0x00, 0x36, 0x00, 0x00, 0x00, 0x31, 0x00, 0x00, 0x00
	.byte 0x30, 0x00, 0x00, 0x00, 0x32, 0x00, 0x00, 0x00

	.data
.public ov01_022098B0

	.balign 4, 0
ov01_022098B0:
	.byte 0xFF, 0xFF, 0xFF, 0xFF, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.word ov01_021EC8F8
	.byte 0x00, 0x00, 0xFF, 0xFF, 0xDC, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.word ov01_021EC94C
	.byte 0x00, 0x00, 0xFF, 0xFF, 0xDC, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.word ov01_021EC94C
	.byte 0x00, 0x00, 0xFF, 0xFF, 0xDC, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.word ov01_021EC94C
	.byte 0x01, 0x00, 0xFF, 0xFF, 0xDC, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.word ov01_021ECD08
	.byte 0x01, 0x00, 0xFF, 0xFF, 0xDC, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.word ov01_021ECD08
	.byte 0x01, 0x00, 0xFF, 0xFF, 0xDC, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.word ov01_021ECD08
	.byte 0xFF, 0xFF, 0xFF, 0xFF, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.word ov01_021EC8F8
	.byte 0x04, 0x00, 0xFF, 0xFF, 0xDC, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.word ov01_021ED0F0
	.byte 0xFF, 0xFF, 0x06, 0x00, 0xAC, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.word ov01_021ED584
	.byte 0xFF, 0xFF, 0x06, 0x00, 0xAC, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.word ov01_021ED584
	.byte 0xFF, 0xFF, 0xFF, 0xFF, 0x34, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.word ov01_021ED710
	.byte 0xFF, 0xFF, 0xFF, 0xFF, 0x34, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.word ov01_021ED924
	.byte 0xFF, 0xFF, 0xFF, 0xFF, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.word ov01_021EDA50
