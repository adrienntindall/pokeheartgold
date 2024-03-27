#ifndef POKEHEARTGOLD_OVERLAY_80_02233688
#define POKEHEARTGOLD_OVERLAY_80_02233688

#include "overlay_80_0222BDF4.h"
#include "battle_arcade_game_board.h" //for static functions; remove later

BOOL FrtCmd_ArcadeAlloc(FrontierContext *ctx);
BOOL FrtCmd_ArcadeInit(FrontierContext  *ctx);
BOOL FrtCmd_ArcadeFree(FrontierContext *ctx);
BOOL ov80_0223371C(FrontierContext *ctx);
BOOL ov80_02233770(FrontierContext *ctx);
BOOL FrtCmd_ArcadeStartBattle(FrontierContext *ctx);

//static functions not yet decompiled
void GameBoardArgs_Set(GAME_BOARD_ARGS *args, void *a1);

#endif