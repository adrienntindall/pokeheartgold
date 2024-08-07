#include "constants/scrcmd.h"
#include "fielddata/script/scr_seq/event_0264.h"
#include "msgdata/msg/msg_0019.h"
	.include "asm/macros/script.inc"

	.rodata

	scrdef scr_seq_0264_000
	scrdef scr_seq_0264_001
	scrdef scr_seq_0264_002
	scrdef scr_seq_0264_003
	scrdef scr_seq_0264_004
	scrdef scr_seq_0264_005
	scrdef_end

scr_seq_0264_000:
	play_se SEQ_SE_DP_SELECT
	lockall
	setvar VAR_SPECIAL_x8000, 1
	goto _002E
	end

_002E:
	call _01EE
	call _01F5
	switch VAR_SPECIAL_x8001
	case 3, _0221
	case -2, _0221
	call _0229
	goto _002E
	end

scr_seq_0264_001:
	play_se SEQ_SE_DP_SELECT
	lockall
	setvar VAR_SPECIAL_x8000, 1
	goto _007C
	end

_007C:
	call _01EE
	call _01F5
	switch VAR_SPECIAL_x8001
	case 3, _0221
	case -2, _0221
	call _0229
	goto _007C
	end

scr_seq_0264_002:
	play_se SEQ_SE_DP_SELECT
	lockall
	setvar VAR_SPECIAL_x8000, 2
	goto _00CA
	end

_00CA:
	call _01EE
	call _01F5
	switch VAR_SPECIAL_x8001
	case 3, _0221
	case -2, _0221
	call _0229
	goto _00CA
	end

scr_seq_0264_003:
	play_se SEQ_SE_DP_SELECT
	lockall
	setvar VAR_SPECIAL_x8000, 5
	goto _0118
	end

_0118:
	call _01EE
	call _01F5
	switch VAR_SPECIAL_x8001
	case 3, _0221
	case -2, _0221
	call _0229
	goto _0118
	end

scr_seq_0264_004:
	play_se SEQ_SE_DP_SELECT
	lockall
	setvar VAR_SPECIAL_x8000, 4
	goto _0166
	end

_0166:
	call _01EE
	call _01F5
	switch VAR_SPECIAL_x8001
	case 3, _0221
	case -2, _0221
	call _0229
	goto _0166
	end

scr_seq_0264_005:
	play_se SEQ_SE_DP_SELECT
	lockall
	setvar VAR_SPECIAL_x8000, 6
	goto _01B4
	end

_01B4:
	call _01EE
	call _01F5
	switch VAR_SPECIAL_x8001
	case 3, _0221
	case -2, _0221
	call _0229
	goto _01B4
	end

_01EE:
	npc_msg msg_0019_00000
	touchscreen_menu_hide
	return

_01F5:
	menu_init 1, 1, 0, 1, VAR_SPECIAL_x8001
	menu_item_add 1, 255, 0
	menu_item_add 2, 255, 1
	menu_item_add 3, 255, 2
	menu_item_add 4, 255, 3
	menu_exec
	return

_0221:
	closemsg
	touchscreen_menu_show
	releaseall
	end

_0229:
	fade_screen 6, 1, 0, RGB_BLACK
	wait_fade
	closemsg
	call _023F
	return

_023F:
	scrcmd_631 VAR_SPECIAL_x8001, VAR_SPECIAL_x8000, VAR_SPECIAL_x8003
	restore_overworld
	fade_screen 6, 1, 1, RGB_BLACK
	wait_fade
	return
	.balign 4, 0
