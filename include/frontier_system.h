#ifndef POKEHEARTGOLD_FRONTIER_SYSTEM_H
#define POKEHEARTGOLD_FRONTIER_SYSTEM_H

#include "field_system.h"

typedef struct FrontierSystem FrontierSystem;

typedef struct FRONTIER_CONTEXT {
    FrontierSystem *frsys;
    u32 state;
    u16 work[8];
    u8 unk14;
    u8 unk15;
    u8 *scriptPtr;
    u8 *unk1C[20];
    void *unk5C;
    u32 unk60;
    u16 unk64[4];
    void *unk6C;
    void *unk70;
    void *unk74;
    u8 flag;
} FRONTIER_CONTEXT;

#define FrontierScript_ReadByte(ctx) (*(ctx->scriptPtr++))

struct FrontierSystem {
    void *unk0;
    FRONTIER_CONTEXT *unk4[8];
    void *work;
    HeapID heapId;
    u8 state;
    void *unk30;
    void *unk34;
    void *unk38;
    void *unk3C;
    void *unk40;
    MSGFMT *msgfmt;
    int dir;
    u8 unk4C;
    u8 unk4D;
    u8 unk4E;
    BOOL unk50;
    void *unk54;
    WINDOW unk58;
    void *unk68;
    u16 *unk6C;
    void *unk70;
    void *unk74;
    void *unk78;
    WINDOW unk7C;
    WINDOW unk8C;
    WINDOW *unk9C;
    WINDOW *unkA0;
    u16 unkA4;
    u16 unkA6;
    u16 unkA8;
    u16 unkAA;
    u16 *unkAC;
};

typedef struct FrontierExternalData {
    void *work;
    void *unk4;
    SAVEDATA *savedata;
    void *unkC;
    void *unk10;
} FrontierExternalData;

u32 FrontierScript_ReadWord(FRONTIER_CONTEXT *ctx);
u16 *FrontierScript_GetVarPointer(FRONTIER_CONTEXT *ctx);
FrontierExternalData *Frontier_GetExternalData(void *);
void *Frontier_GetWork(void *);

typedef struct FRONTIER_MON {
    u16 unk0;
    u16 heldItem;
    u16 moves[4];
    u32 id;
    u32 personality;
    u32 ivs;
    u8 evs[6];
    u8 pp;
    u8 country;
    u8 ability;
    u8 unk;
    u16 nickname[11];
} FRONTIER_MON;

typedef struct FRONTIER_TRAINER {
    u32 id;
    u16 trainerType;
    u16 dummy;
    u16 name[8];
    u16 encounterMessage[4];
    u16 winMessage[4];
    u16 loseMessage[4];
} FRONTIER_TRAINER;

typedef struct FRONTIER_PARTNER {
    FRONTIER_TRAINER trainer;
    FRONTIER_MON mons[4];
}FRONTIER_PARTNER;

enum FrontierScriptCodes {
    UNK_FRONTIER_CODE_0,
    UNK_FRONTIER_CODE_1,
    FRONTIER_CODE_SET_TYPE,
    FRONTIER_CODE_GET_RETURN_DATA,
    FRONTIER_CODE_GET_WINSTREAK,
    FRONTIER_CODE_INCREASE_WINSTREAK,
    UNK_FRONTIER_CODE_6,
    FRONTIER_CODE_SYSTEM_RESET,
    UNK_FRONTIER_CODE_8,
    FRONTIER_CODE_IS_SAVE_DATA_ENABLED,
    FRONTIER_CODE_REST_SAVE,
    UNK_FRONTIER_CODE_11,
    FRONTIER_CODE_GET_PANEL_BP,
    UNK_FRONTIER_CODE_13,
    FRONTIER_CODE_INCREASE_ROUND,
    FRONITER_CODE_GET_HELD_ITEM,
    FRONTIER_CODE_GET_PANEL_DECISION,
    FRONTIER_CODE_GET_TYPE,
    FRONITER_CODE_SET_TEMP_HELD_ITEM,
    UNK_FRONTIER_CODE_19,
    UNK_FRONTIER_CODE_20,
    FRONTIER_CODE_SET_LOSS,
    UNK_FRONTIER_CODE_22,
    FRONTIER_CODE_GET_ROUND,
    FRONTIER_CODE_GET_MULTI_RETIRE_FLAG,
    FRONTIER_CODE_CHANGE_MON_ICONS,
    UNK_FRONTIER_CODE_26,
    UNK_FRONTIER_CODE_27,
    UNK_FRONTIER_CODE_28,
    UNK_FRONTIER_CODE_29,
    UNK_FRONTIER_CODE_30,
    UNK_FRONTIER_CODE_31,
    UNK_FRONTIER_CODE_32,
    UNK_FRONTIER_CODE_33,
    UNK_FRONTIER_CODE_34,
    UNK_FRONTIER_CODE_35,
    UNK_FRONTIER_CODE_36,
    UNK_FRONTIER_CODE_37,
    UNK_FRONTIER_CODE_38,
    FRONTIER_CODE_ADD_PARTICLE_EMITTER,
    UNK_FRONTIER_CODE_40,
    UNK_FRONTIER_CODE_41,
    UNK_FRONTIER_CODE_42,
    UNK_FRONTIER_CODE_43,
    UNK_FRONTIER_CODE_44,
    UNK_FRONTIER_CODE_45,
    UNK_FRONTIER_CODE_46,
    UNK_FRONTIER_CODE_47,
    FRONTIER_CODE_CHECK_BRAIN,
    FRONTIER_CODE_CREATE_OPPONENT_MONS,
    FRONTIER_CODE_SET_OPPONENT_PARTY,
    FRONTIER_CODE_CHECK_BRAIN_MESSAGE,
    FRONTIER_CODE_CLEAR_RECV_CNT
};

#endif
