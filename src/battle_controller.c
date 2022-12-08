#include "battle.h"
#include "battle_controller.h"
#include "constants/moves.h"

void ov12_02262098(BattleSystem *bsys, int a1, int a2, void *data, u8 size) {
    int i;
    SEND_DATA send;
    u8 *src;
    u8 *dest;
    u16 *unkA;
    u16 *unkB;

    if (a1 == 1) {
        dest = ov12_0223A948(bsys);
        unkA = ov12_0223A984(bsys);
        unkB = ov12_0223A990(bsys);
    } else {
        dest = ov12_0223A940(bsys);
        unkA = ov12_0223A960(bsys);
        unkB = ov12_0223A96C(bsys);
    }

    if (*unkA + sizeof(SEND_DATA) + size + 1 > 0x1000) {
        *unkB = *unkA;
        *unkA = 0;
    }

    send.unk0 = a1;
    send.unk1 = a2;
    send.size = size;

    src = (u8 *)&send;

    for (i = 0; i < sizeof(SEND_DATA); i++) {
        dest[*unkA] = src[i];
        *unkA += 1;
    }

    src = (u8 *)data;

    for (i = 0; i < size; i++) {
        dest[*unkA] = src[i];
        *unkA += 1;
    }
}

BOOL ov12_02262130(BattleSystem *bsys, void *data) {
    u8 *src = (u8 *)data;
    int i;
    BOOL ret = FALSE;

    u8 unkA = src[0];
    u8 unkB = src[1];
    int size = src[2] | (src[3] << 8);

    src += sizeof(SEND_DATA);

    if (unkA == 0) {
        if (bsys->ctx->unk_2300[unkB][0] == 0) {
            for (i = 0; i < size; i++) {
                bsys->ctx->unk_2300[unkB][i] = src[i];
            }
            ret = TRUE;
        }
    } else if (unkA == 1) {
        //TODO: unk84 split into unk94 as the starting point for this array
        if (bsys->opponentData[unkB]->unk84[0x10] == 0) {
            for (i = 0; i < size; i++) {
                bsys->opponentData[unkB]->unk84[i+0x10] = src[i];
            }
            ret = TRUE;
        }
    } else if (unkA == 2) {
        int index = src[0];
        int id = src[1];
        if (ov12_0223B688(bsys)) {
            ov12_0224ED00(bsys->ctx, id, unkB, index);
        }
        ret = TRUE;
    }

    return ret;
}

void ov12_022621C4(BattleSystem *bsys, int a1) {
    u8 *src;
    u16 *unkA;
    u16 *unkB;
    u16 *unkC;
    int size;

    if (a1 == 1) {
        src = ov12_0223A948(bsys);
        unkA = ov12_0223A978(bsys);
        unkB = ov12_0223A984(bsys);
        unkC = ov12_0223A990(bsys);
    } else {
        src = ov12_0223A940(bsys);
        unkA = ov12_0223A954(bsys);
        unkB = ov12_0223A960(bsys);
        unkC = ov12_0223A96C(bsys);
    }

    if (*unkA == *unkB) {
        return;
    }

    if (*unkA == *unkC) {
        *unkA = 0;
        *unkC = 0;
    }
    
    if (ov12_02262130(bsys, &src[*unkA]) == TRUE) {
        *unkA += sizeof(SEND_DATA) + (src[*unkA + 2] | (src[*unkA + 3] << 8));
    }
}

void ov12_02262240(BattleSystem *bsys, int a1, int a2, void *data, u8 size) {
    int i;
    u8 *src = (u8 *)data;

    if ((bsys->battleTypeFlags & 4) && !(bsys->unk240C & 16)) {
        if (a1 == 1) {
            for (i = 0; i < sub_02037454(); i++) {
                ov12_0224ECC4(bsys->ctx, i, a2, *src);
            }
        }
        sub_02074F9C(bsys, a1, a2, data, size);
    } else  {
        if (a1 == 1) {
            ov12_0224ECC4(bsys->ctx, 0, a2, *src);
        }
        ov12_02262098(bsys, a1, a2, data, size);
    }
}

typedef struct ENCOUNTER_ANIMATION_WORK {
    int cmd;
    u32 rand;
} ENCOUNTER_ANIMATION_WORK;

void BattleController_EmitPlayEncounterAnimation(BattleSystem *bsys, int battlerId) {
    ENCOUNTER_ANIMATION_WORK work;

    work.cmd = 1;
    work.rand = ov12_0223BDC4(bsys);

    ov12_02262240(bsys, 1, battlerId, &work, sizeof(ENCOUNTER_ANIMATION_WORK));
}

typedef struct POKEMON_ENCOUNTER_WORK {
    u8 cmd;
    u8 gender : 2,
       shiny  : 1,
       forme  : 5;
    u16 species;
    u32 personality;
    int cry;
    u16 moves[LEARNED_MOVES_MAX];
    u16 movePP[LEARNED_MOVES_MAX];
    u16 movePPMax[LEARNED_MOVES_MAX];
    u8 nickname[24];
} POKEMON_ENCOUNTER_WORK;

void BattleController_EmitPokemonEncounter(BattleSystem *bsys, int battlerId) {
    POKEMON_ENCOUNTER_WORK work;
    int i;

    work.cmd = 2;
    work.gender = bsys->ctx->battleMons[battlerId].gender;
    work.shiny = bsys->ctx->battleMons[battlerId].unk26_5;
    work.species = bsys->ctx->battleMons[battlerId].species;
    work.personality = bsys->ctx->battleMons[battlerId].personality;
    work.cry = ov12_02256748(bsys->ctx, battlerId, ov12_0223AB0C(bsys, battlerId), TRUE);
    work.forme = bsys->ctx->battleMons[battlerId].forme;

    for (i = 0; i < LEARNED_MOVES_MAX; i++) {
        work.moves[i] = GetBattlerVar(bsys->ctx, battlerId, 6 + i, 0);
        work.movePP[i] = GetBattlerVar(bsys->ctx, battlerId, 31 + i, 0);
        work.movePPMax[i] = GetBattlerVar(bsys->ctx, battlerId, 39 + i, 0);
    }

    GetBattlerVar(bsys->ctx, battlerId, 45, &work.nickname);

    ov12_02262240(bsys, 1, battlerId, &work, sizeof(POKEMON_ENCOUNTER_WORK));
}

typedef struct POKEMON_ENTER_BATTLE_WORK {
    u8 cmd;
    u8 gender : 2,
       shiny  : 1,
       forme  : 5;
    u16 species;
    u32 personality;
    int cry;
    int selectedMonIndex;
    int ball;
    int flag;
    u16 moves[LEARNED_MOVES_MAX];
    u16 movePP[LEARNED_MOVES_MAX];
    u16 movePPMax[LEARNED_MOVES_MAX];
    u8 nickname[24];
    int selectedPartnerIndex;
    int substituteFlag;
    u16 battlerIdOther[BATTLERS_MAX];
    u8 otherGender[BATTLERS_MAX];
    u8 otherShiny[BATTLERS_MAX];
    u8 otherForme[BATTLERS_MAX];
    u32 otherPersonality[BATTLERS_MAX];
} POKEMON_ENTER_BATTLE_WORK;

void BattleController_EmitPokemonSlideIn(BattleSystem *bsys, int battlerId) {
    POKEMON_ENTER_BATTLE_WORK work;
    int i;

    work.cmd = 3;
    work.gender = bsys->ctx->battleMons[battlerId].gender;
    work.shiny = bsys->ctx->battleMons[battlerId].unk26_5;
    work.species = bsys->ctx->battleMons[battlerId].species;
    work.personality = bsys->ctx->battleMons[battlerId].personality;
    work.cry = ov12_02256748(bsys->ctx, battlerId, ov12_0223AB0C(bsys, battlerId), TRUE);
    work.selectedMonIndex = bsys->ctx->selectedMonIndex[battlerId];
    work.forme = bsys->ctx->battleMons[battlerId].forme;
    work.ball = bsys->ctx->battleMons[battlerId].unk7B;
    work.selectedPartnerIndex = bsys->ctx->selectedMonIndex[BattleSys_GetBattlerIdPartner(bsys, battlerId)];

    ov12_0223B854(bsys, battlerId, work.selectedMonIndex);

    for (i = 0; i < LEARNED_MOVES_MAX; i++) {
        work.moves[i] = GetBattlerVar(bsys->ctx, battlerId, 6 + i, 0);
        work.movePP[i] = GetBattlerVar(bsys->ctx, battlerId, 31 + i, 0);
        work.movePPMax[i] = GetBattlerVar(bsys->ctx, battlerId, 39 + i, 0);
    }

    GetBattlerVar(bsys->ctx, battlerId, 45, &work.nickname);

    ov12_02262240(bsys, 1, battlerId, &work, sizeof(POKEMON_ENTER_BATTLE_WORK));
}
