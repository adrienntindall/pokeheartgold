#ifndef POKEHEARTGOLD_FRONTIER_CMD_BATTLE_ARCADE_H
#define POKEHEARTGOLD_FRONTIER_CMD_BATTLE_ARCADE_H

#include "battle_arcade_game_board.h"
#include "frontier_system.h"

typedef struct UnkIconStruct {
    void *unk0;
    void *unk4;
    void *unk8;
    int unkC;
} UnkIconStruct;

typedef struct BattleArcadeWork {
    HeapID heapId;
    SAVEDATA *savedata;
    void *unk8;
    BATTLE_SETUP *setup;
    u8 type;
    u8 round;
    u8 randomFlag;
    u8 decide;
    int weather;
    u16 winstreak;
    u16 lap;
    u8 cursorSpeed;
    u8 bp;
    u8 dahliaApproachFlag;
    u8 unkFlag;
    u16 randPos;
    u16 dummy;
    u32 winCount;
    int winResult;
    u8 entryMonPos[3];
    u8 clearFlag;
    UnkIconStruct *playerMonIcon[4];
    UnkIconStruct *opponentMonIcon[4];
    UnkIconStruct *playerItemIcon[4];
    UnkIconStruct *opponentItemIcon[4];
    PARTY *playerParty;
    PARTY *opponentParty;
    u16 trainerIndex[14];
    u32 hpTemp[4];
    u32 atkTemp[4];
    u32 defTemp[4];
    u32 speedTemp[4];
    u32 spAtkTemp[4];
    u32 spDefTemp[4];
    FRONTIER_PARTNER partner[2];
    u16 opponentMonIndex[4];
    u8 opponentAtkIvs[4];
    u32 opponentPersonalityValues[4];
    FRONTIER_MON opponentPokemon[4];
    u16 dummyOpponentData;
    u16 heldItems[3];
    u16 returnData[6];
    u16 sendBuffer[40];
    u8 buffer[512];
    u8 recvBuffer[2][512];
    u8 multiRetire;
    u8 pairTradeFlag;
    u16 pairLap;
    u16 multiWinstreak;
    u8 reverseFlag;
    u8 pairSelectType;
    u8 recvCnt;
    u8 unused;
    u16 *deleteWork;
    u32 dummyWork;
} BattleArcadeWork;

//Commands
BOOL FrontierCmd_BattleArcadeAlloc(FRONTIER_CONTEXT *ctx);
BOOL FrontierCmd_BattleArcadeInit(FRONTIER_CONTEXT *ctx);
BOOL FrontierCmd_BattleArcadeGetResult(FRONTIER_CONTEXT *ctx);
BOOL FrontierCmd_BattleArcadeStartBattle(FRONTIER_CONTEXT *ctx);
BOOL FrontierCmd_BattleArcadeSetPartyPreBattle(FRONTIER_CONTEXT *ctx);
BOOL FrontierCmd_BattleArcadeSetPartyPostBattle(FRONTIER_CONTEXT *ctx);
BOOL FrontierCmd_BattleArcadeScript(FRONTIER_CONTEXT *ctx);
BOOL FrontierCmd_BattleArcadeCheckLoss(FRONTIER_CONTEXT *ctx);
BOOL FrontierCmd_BattleArcadeSendBuffer(FRONTIER_CONTEXT *ctx);
BOOL FrontierCmd_BattleArcadeRecvBuffer(FRONTIER_CONTEXT *ctx);
BOOL FrontierCmd_BattleArcadeDisplayMessage(FRONTIER_CONTEXT *ctx);
BOOL FrontierCmd_BattleArcadeDecideEvent(FRONTIER_CONTEXT *ctx);

//Sub
BattleArcadeWork *BattleArcade_Alloc(SAVEDATA *, u32, u8, u32, u32, u32, u16 *);
BattleArcadeWork *BattleArcade_Init(BattleArcadeWork *, u32);
void BattleArcade_Free(BattleArcadeWork *work);

#endif
