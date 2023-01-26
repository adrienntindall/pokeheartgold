#include "battle_setup.h"
#include "frontier_command_battle_arcade.h"
#include "overlay_80.h"
#include "overlay_80_0222A84C.h"
#include "overlay_80_02238648.h"
#include "overlay_80_0222AB40.h"
#include "overlay_80_0222BDF4.h"
#include "palette.h"
#include "particle_system.h"
#include "constants/pokemon.h"

FS_EXTERN_OVERLAY(OVY_84);

static void ov80_02233944(GAME_BOARD_ARGS *args, BattleArcadeWork *work);
static void BattleArcade_FreeArgs(void *_args);


BOOL FrontierCmd_BattleArcadeAlloc(FRONTIER_CONTEXT *ctx) {
    BattleArcadeWork *work;
    FrontierExternalData *ptr;
    
    u32 init = FrontierScript_ReadWord(ctx);
    u32 type = FrontierScript_ReadWord(ctx);
    u32 pos1 = FrontierScript_ReadWord(ctx);
    u32 pos2 = FrontierScript_ReadWord(ctx);
    u32 pos3 = FrontierScript_ReadWord(ctx);
    u16 *a5 = FrontierScript_GetVarPointer(ctx);
    
    ptr = Frontier_GetExternalData(ctx->frsys->unk0);
    
    work = BattleArcade_Alloc(ptr->savedata, init, type, pos1, pos2, pos3, a5);
    Frontier_SetWork(ctx->frsys->unk0, work);
    
    return FALSE;
}

BOOL FrontierCmd_BattleArcadeInit(FRONTIER_CONTEXT *ctx) {
    BattleArcadeWork *work;
    u32 init = FrontierScript_ReadWord(ctx);
    
    work = Frontier_GetWork(ctx->frsys->unk0);
    BattleArcade_Init(work, init);
    
    return FALSE;
}

BOOL FrontierCmd_BattleArcadeFree(FRONTIER_CONTEXT *ctx) {
    BattleArcadeWork *work = Frontier_GetWork(ctx->frsys->unk0);
    BattleArcade_Free(work);
    
    return FALSE;
}

extern OVY_MGR_TEMPLATE sBattleArcadeGameBoardTemplate;

BOOL FrontierCmd_BattleArcadeRankUp(FRONTIER_CONTEXT *ctx) {
    BattleArcadeWork *work;
    GAME_BOARD_ARGS *args;
    FrontierExternalData *ptr = Frontier_GetExternalData(ctx->frsys->unk0);
    work = Frontier_GetWork(ctx->frsys->unk0);
    
    args = AllocFromHeap(HEAP_ID_FIELDMAP, sizeof(GAME_BOARD_ARGS));
    MI_CpuFill8(args, 0, sizeof(GAME_BOARD_ARGS));
    
    args->savedata = ptr->savedata;
    ov80_02233944(args, work);
    
    sub_02096820(ctx->frsys->unk0, &sBattleArcadeGameBoardTemplate, args, FALSE, BattleArcade_FreeArgs);
    
    return TRUE;
}

BOOL FrontierCmd_BattleArcadeGetResult(FRONTIER_CONTEXT *ctx) {
    u8 monCount;
    int i, partyIndex1, partyIndex2, partyMonCount, temp;
    u32 exp, level, item;
    
    BattleArcadeWork *work;
    BATTLE_SETUP *setup;
    POKEMON *mon;
    
    work = Frontier_GetWork(ctx->frsys->unk0);
    setup = work->setup;
    work->bp = ov80_02234848(work, setup->party[0], setup->party[2], setup->unk1B4);
    work->winResult = IsBattleResultWin(setup->winFlag);
    
    if (work->decide == 27) {
        partyIndex1 = 1;
        partyIndex2 = 3;
    } else {
        partyIndex1 = 0;
        partyIndex2 = 2;
    }
    
    ov80_02235364(setup->party[partyIndex1], work->playerParty, 0, 0);
    ov80_02235364(setup->party[partyIndex1], work->playerParty, 1, 1);
    
    if (ov80_02237D8C(work->type) == FALSE) {
        ov80_02235364(setup->party[partyIndex1], work->playerParty, 2, 2);
    } else {
        ov80_02235364(setup->party[partyIndex2], work->playerParty, 0, 2);
        ov80_02235364(setup->party[partyIndex2], work->playerParty, 1, 3);
    }
    
    if (work->decide == 17) {
        monCount = BattleArcade_GetMonCount(work->type, 1);
        for (i = 0; i < monCount; i++) {
            mon = GetPartyMonByIndex(work->playerParty, i);
            level = GetMonData(mon, MON_DATA_LEVEL, NULL);
            level -= 3;
            
            exp = GetMonExpBySpeciesAndLevel(GetMonData(mon, MON_DATA_SPECIES, NULL), level);
            SetMonData(mon, MON_DATA_EXPERIENCE, &exp);
            CalcMonLevelAndStats(mon);
        }
    }
    
    partyMonCount = GetPartyCount(work->playerParty);
    for (i = 0; i < partyMonCount; i++) {
        mon = GetPartyMonByIndex(work->playerParty, i);
        
        temp = work->hpTemp[i];
        SetMonData(mon, MON_DATA_MAXHP, &temp);
        SetMonData(mon, MON_DATA_HP, &temp);
        
        temp = work->atkTemp[i];
        SetMonData(mon, MON_DATA_ATK, &temp);

        temp = work->defTemp[i];
        SetMonData(mon, MON_DATA_DEF, &temp);
        
        temp = work->speedTemp[i];
        SetMonData(mon, MON_DATA_SPEED, &temp);
        
        temp = work->spAtkTemp[i];
        SetMonData(mon, MON_DATA_SPATK, &temp);
        
        temp = work->spDefTemp[i];
        SetMonData(mon, MON_DATA_SPDEF, &temp);
    }
    
    BattleSetup_Delete(setup);
    
    return FALSE;
}

extern OVY_MGR_TEMPLATE _020FA484;

BOOL FrontierCmd_BattleArcadeStartBattle(FRONTIER_CONTEXT *ctx) {
    BATTLE_SETUP *setup;
    BattleArcadeWork *work;
    FrontierExternalData *ptr = Frontier_GetExternalData(ctx->frsys->unk0);
    
    work = Frontier_GetWork(ctx->frsys->unk0);
    setup = ov80_02238150(work, ptr);
    work->setup = setup; 
    
    sub_02096820(ctx->frsys->unk0, &_020FA484, setup, FALSE, NULL);
    
    return TRUE;
}

static void ov80_02233944(GAME_BOARD_ARGS *args, BattleArcadeWork *work) {
    int i, monCount;
    POKEMON *mon;
    
    args->type = work->type;
    args->unk1E = ov80_02238498(work);
    args->unk14 = &work->randPos;
    args->unk10 = &work->decide;
    args->bp = work->bp;
    args->winstreak = work->winstreak;
    args->multiWinstreak = work->multiWinstreak;
    args->cursorSpeed = &work->cursorSpeed;
    args->playerParty = work->playerParty;
    args->opponentParty = work->opponentParty;
    args->work = work;
    work->weather = 0;
    args->weather = &work->weather;
    args->randomFlag = work->randomFlag;
    work->randomFlag = 0;
    work->unkFlag = 0;
    
    monCount = GetPartyCount(work->playerParty);
    for (i = 0; i < monCount; i++) {
        mon = GetPartyMonByIndex(work->playerParty, i);
        
        work->hpTemp[i] = GetMonData(mon, MON_DATA_MAXHP, NULL);
        work->atkTemp[i] = GetMonData(mon, MON_DATA_ATK, NULL);
        work->defTemp[i] = GetMonData(mon, MON_DATA_DEF, NULL);
        work->speedTemp[i] = GetMonData(mon, MON_DATA_SPEED, NULL);
        work->spAtkTemp[i] = GetMonData(mon, MON_DATA_SPATK, NULL);
        work->spDefTemp[i] = GetMonData(mon, MON_DATA_SPDEF, NULL);
    }
}

static void BattleArcade_FreeArgs(void *_args) {
    GAME_BOARD_ARGS *args = _args;
    ov80_02234550(args->work, args);
    FreeToHeap(args);
}

BOOL FrontierCmd_BattleArcadeSetPartyPreBattle(FRONTIER_CONTEXT *ctx) {
    BattleArcadeWork *work = Frontier_GetWork(ctx->frsys->unk0);
    BattleArcade_SetPartyPreBattle(work);
    return FALSE;
}

BOOL FrontierCmd_BattleArcadeSetPartyPostBattle(FRONTIER_CONTEXT *ctx) {
    BattleArcadeWork *work = Frontier_GetWork(ctx->frsys->unk0);
    BattleArcade_SetPartyPostBattle(work);
    return FALSE;
}

static void BattleArcade_AddParticleEmitter(FRONTIER_CONTEXT *ctx, BattleArcadeWork *work, u16 emit);

BOOL FrontierCmd_BattleArcadeScript(FRONTIER_CONTEXT *ctx) {
    STRING *str;
    POKEMON *mon;
    PARTY *party;
    BattleArcadeWork *work;
    u8 playerMonCount, opponentMonCount, colour;
    u32 type, typeNumber;
    u16 yOffset;
    int i, j, flag;
    FrontierExternalData *ptr;
    UnkStruct_80_0222A84C *map;
    PLAYERPROFILE *profile;

    
    u8 var = FrontierScript_ReadByte(ctx);
    u8 a1 = FrontierScript_ReadWord(ctx);
    u8 a2 = FrontierScript_ReadWord(ctx);
    u16 *ret = FrontierScript_GetVarPointer(ctx);
    
    work = Frontier_GetWork(ctx->frsys->unk0);
    ptr = Frontier_GetExternalData(ctx->frsys->unk0);
    map = ov80_0222AB34(ctx->frsys);
    
    switch (var) {
    case 2:
        work->type = a1;
        break;
    case 3:
        *ret = work->returnData[a1];
        break;
    case 4:
        *ret = work->winstreak;
        break;
    case 5:
        if (work->winstreak < 9999) {
            work->winstreak++;
        }
        break;
    case 7:
        OS_ResetSystem(FALSE);
        break;
    case 9:
        *ret = sub_02030E98(work->unk8);
        break;
    case 10:
        ov80_02234588(work, 2);
        break;
    case 12:
        *ret = ov80_02238430(work, work->decide);
        break;
    case 14:    
        *ret = ov80_02234764(work);
        break;
    case 15:
        if (a1 == 0) {
            mon = GetPartyMonByIndex(work->playerParty, 0);
        } else {
            mon = GetPartyMonByIndex(work->opponentParty, 0);
        }
        *ret = GetMonData(mon, 6, NULL);
        break;
    case 16:
        *ret = work->decide;
        break;
    case 18:
        party = SavArray_PlayerParty_get(ptr->savedata);
        for (i = 0; i < 3; i++) {
            mon = GetPartyMonByIndex(party, work->entryMonPos[i]);
            SetMonData(mon, 6, &work->heldItems[i]);
        }
        break;
    case 19:
        *ret = ov80_02238498(work);
        break;
    case 20:
        *ret = ov80_02234774(work, a1);
        break;
    case 21:
        ov80_022347B8(work);
        break;
    case 22:
        ov80_022347C4(work);
        break;
    case 23:
        *ret = ov80_02234770(work);
        break;
    case 24:
        *ret = work->multiRetire;
        break;
    case 25:
        if (work->decide == 27) {
            playerMonCount = BattleArcade_GetMonCount(work->type, 1);
            opponentMonCount = BattleArcade_GetOpponentMonCount(work->type, 1);
            
            VecFx32 playerVec;
            VecFx32 opponentVec;
            void *playerUnkIconPtr;
            void *opponentUnkIconPtr;
            
            for (i = 0; i < playerMonCount; i++) {
                playerUnkIconPtr = work->playerMonIcon[i]->unk0;
                playerVec = *sub_020248AC(playerUnkIconPtr);
                
                opponentUnkIconPtr = work->opponentMonIcon[i]->unk0;
                opponentVec = *sub_020248AC(opponentUnkIconPtr);
                
                sub_020247D4(playerUnkIconPtr, &opponentVec);
                sub_020247D4(opponentUnkIconPtr, &playerVec);
                
                playerUnkIconPtr = work->playerItemIcon[i]->unk0;
                playerVec = *sub_020248AC(playerUnkIconPtr);
                
                opponentUnkIconPtr = work->opponentItemIcon[i]->unk0;
                opponentVec = *sub_020248AC(opponentUnkIconPtr);
                
                sub_020247D4(playerUnkIconPtr, &opponentVec);
                sub_020247D4(opponentUnkIconPtr, &playerVec);
            }
        }
        break;
    case 6:
        sub_02096910(work);
        break;
    case 28:
        *ret = BattleArcade_IsMultiplayer(work->type);
        break;
    case 17:
        *ret = work->type;
        break;
    case 29:
        ov80_0222F210(map);
        break;
    case 30:
        ov80_0222F278(map);
        break;
    case 31:
        ov80_02234A74(work, map, a1);
        
        playerMonCount = BattleArcade_GetMonCount(work->type, 1);
        opponentMonCount = BattleArcade_GetOpponentMonCount(work->type, 1);
        
        if (a1 == 0) {
            for (i = 0; i < playerMonCount; i++) {
                sub_02024A04(work->playerMonIcon[i]->unk0, 2);
            }
        } else {
            for (i = 0; i < opponentMonCount; i++) {
                sub_02024A04(work->opponentMonIcon[i]->unk0, 2);
            }
        }
        break;
    case 32:
        ov80_02234B24(work, map, a1);
        break;
    case 33:
        ov80_0222F33C(map);
        break;
    case 34:
        ov80_0222F3CC(map);
        break;
    case 35:
        ov80_02234BEC(work, map, a1);
        break;
    case 36:
        ov80_02234CB0(work, map, a1);
        break;
    case 11:
        ov80_02234968(work, map);
        break;
    case 37:
        if (BattleArcade_IsMultiplayer(work->type) == TRUE) {
            ov80_02234A38(work, map);
        }
        break;
    case 38:
        colour = BattleArcade_GetPanelColor(work->decide);
        
        if (colour == 0) {
            BufferFrontierOpponentName(ctx->frsys->msgfmt, a1, work->trainerIndex[ov80_022347A8(work, a2)]);
        } else {
            if (BattleArcade_IsMultiplayer(work->type) == FALSE) {
                profile = Sav2_PlayerData_GetProfileAddr(ptr->savedata);
            } else {
                profile = sub_02034818(a2);
            }
            BufferPlayersName(ctx->frsys->msgfmt, a1, profile);
        }
        break;
    case 39:
        work->reverseFlag = a2;
        BattleArcade_AddParticleEmitter(ctx, work, a1);
        break;
    case 40:
        ov80_0222A474(&work->partner[0], work->trainerIndex[work->round], HEAP_ID_FIELDMAP, 204);
        ov80_0222A474(&work->partner[1], work->trainerIndex[work->round + 7], HEAP_ID_FIELDMAP, 204);
        break;
    case 41:
        ov80_02234B7C(work, map, a1, a2);
        break;
    case 42:
        ov80_02234BB4(work, map, a1, a2);
        break;
    case 43:
        ov80_02234DC4(a1, a2);
        break;
    case 44:
        if (a1 == 0) {
            sub_02003E5C(map->unk4, 2, 0, 256, a1, 0);
        } else {
            u32 paletteIndex;
            UnkStruct_80_02238648 *unkPtr = ov80_02239938(ctx->frsys->unk0, a2);
            paletteIndex = ov42_02229248(unkPtr->unk4);
            sub_02003E5C(map->unk4, 2, paletteIndex*16, 16, a1, 0);
        }
        break;
    case 45:
        *ret = ov80_02235324(work);
        break;
    case 46:
        GX_EngineAToggleLayers(4, 0);
        break;
    case 47:
        *ret = work->unkFlag;
        break;
    case 48:
        *ret = 0;
        if (work->type == 0) {
            if (work->winstreak + 1 == 21) {
                *ret = 1;
            } else if (work->winstreak + 1 == 49) {
                *ret = 2;
            }
        }
        break;
    case 49:
        ov80_0222A52C(work->opponentPokemon, work->opponentMonIndex, work->opponentAtkIvs, work->opponentPersonalityValues, NULL, 4, HEAP_ID_FIELDMAP, 205);
        break;
    case 50:
        ov80_022383C0(work);
        break;
    case 51:
        *ret = work->dahliaApproachFlag;
        work->dahliaApproachFlag = TRUE;
        break;
    case 52:
        work->recvCnt = 0;
        break;
    }
    return FALSE;
}

static void BattleArcade_ParticleCB(ParticleSystemEmitter *emit);

static void BattleArcade_AddParticleEmitter(FRONTIER_CONTEXT *ctx, BattleArcadeWork *work, u16 emit) {
    FrontierSystem *frsys = ctx->frsys;
    UnkStruct_80_0222A84C *map = ov80_0222AB34(ctx->frsys);
    ParticleSystemEmitter *particleSys = ov80_02239A60(map->unk10, 0);
    sub_02015494(particleSys, emit, BattleArcade_ParticleCB, work);
}

extern VecFx32 ov80_0223BE6C[1];

static void BattleArcade_ParticleCB(ParticleSystemEmitter *emit) {
    VecFx32 vec;
    VecFx16 axis;
    BattleArcadeWork *work = sub_02015504();

    vec = ov80_0223BE6C[0];
    
    if (work->reverseFlag == TRUE) {
        sub_02015538(emit, &axis);
        axis.x *= -1;
        emit->axis = axis;
        ParticleSystemEmitter_SetEmitPos(emit, &vec);
    }
}

BOOL FrontierCmd_BattleArcadeCheckLoss(FRONTIER_CONTEXT *ctx) {
    BattleArcadeWork *work;
    u16 *ret = FrontierScript_GetVarPointer(ctx);
    work = Frontier_GetWork(ctx->frsys->unk0);
    *ret = work->winResult;
    return FALSE;
}

BOOL FrontierCmd_BattleArcadeSendBuffer(FRONTIER_CONTEXT *ctx) {
    BattleArcadeWork *work;
    u32 type = FrontierScript_ReadWord(ctx);
    u32 param = FrontierScript_ReadWord(ctx);
    u16 *ret = FrontierScript_GetVarPointer(ctx);
    work = Frontier_GetWork(ctx->frsys->unk0);
    *ret = ov80_02234E50(work, type, param);
    return TRUE;
}

static BOOL FrontierCmd_BattleArcadeWaitForRecvBuffer(FRONTIER_CONTEXT *ctx);

BOOL FrontierCmd_BattleArcadeRecvBuffer(FRONTIER_CONTEXT *ctx) {
    ctx->unk64[0] = ov80_0222AC58(ctx);
    ov80_0222AB84(ctx, FrontierCmd_BattleArcadeWaitForRecvBuffer);
    return TRUE;
}

static BOOL FrontierCmd_BattleArcadeWaitForRecvBuffer(FRONTIER_CONTEXT *ctx) {
    BattleArcadeWork *work;
    u16 type = ov80_0222BE9C(ctx, ctx->unk64[0]);
    work = Frontier_GetWork(ctx->frsys->unk0);
    
    if (work->recvCnt >= 2) {
        work->recvCnt = 0;
        return TRUE;
    }
    return FALSE;
}

BOOL FrontierCmd_BattleArcadeDisplayMessage(FRONTIER_CONTEXT *ctx) {
    u16 *msg;
    BattleArcadeWork *work;
    FrontierExternalData *ptr = Frontier_GetExternalData(ctx->frsys->unk0);
    u16 trainer = FrontierScript_ReadByte(ctx);
    work = Frontier_GetWork(ctx->frsys->unk0);
    
    if (work == NULL) {
        return FALSE;
    }
    
    msg = work->partner[trainer].trainer.encounterMessage;
    
    ov80_0222F44C(ctx, msg);
    return TRUE;
}

BOOL FrontierCmd_BattleArcadeDecideEvent(FRONTIER_CONTEXT *ctx) {
    BattleArcadeWork *work = Frontier_GetWork(ctx->frsys->unk0);
    BattleArcade_EventSet(work, work->decide);
    return TRUE;
}

BOOL FrontierCmd_BattleArcadeToggleHeldItemIcons(FRONTIER_CONTEXT *ctx) {
    BattleArcadeWork *work;
    UnkStruct_80_0222A84C *map = ov80_0222AB34(ctx->frsys);
    u32 icon1Toggle = FrontierScript_ReadWord(ctx);
    u32 icon2Toggle = FrontierScript_ReadWord(ctx);
    u32 icon3Toggle = FrontierScript_ReadWord(ctx);
    work = Frontier_GetWork(ctx->frsys->unk0);
    BattleArcade_ToggleHeldItemIcons(work, map, icon1Toggle, icon2Toggle, icon3Toggle);
    return FALSE;
}
