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
    .public ov01_021EC94C
    .public ov01_021ECD08
    .public ov01_021ECD08
    .public ov01_021ED0F0
    .public ov01_021ED31C
    .public ov01_021ED474
    .public ov01_021ED584

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

.public ov01_0220673C
ov01_0220673C: ; 0x0220673C
	.word 16, 32, 16, 10
.public ov01_0220674C
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
