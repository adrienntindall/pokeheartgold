#include "battle/battle_display.h"
#include "constants/battle.h"

extern void ov12_02260668(SysTask *, void *);

void BattleDisplay_InitTaskSetupUI(BattleSystem *battleSys, OpponentData *opponentData)
{
    UISetupTaskData *uiSetupTaskData = (UISetupTaskData *)Heap_Alloc(HEAP_ID_BATTLE, sizeof(UISetupTaskData));
    uiSetupTaskData->battleSys = battleSys;
    uiSetupTaskData->step = 0;
    uiSetupTaskData->frameCount = 0;
    uiSetupTaskData->fadeStep = 0;

    SysTask_CreateOnMainQueue(ov12_02260668, uiSetupTaskData, 0);
}

typedef struct MonEncounterData {
    BattleSystem *battleSys;
    OpponentData *opponentData;
    Pokepic *sprite;
    UnkBattleSystemSub17C *terrain;
    u8 command;
    u8 battler;
    u8 state;
    u8 face;
    s16 targetPos;
    u16 species;
    int cryMod;
    int battlerType;
    int delay;
    int nature;
    BOOL isShiny;
    u8 formNum;
    u8 padding_2D[3];
} MonEncounterData;

extern const s16 ov07_022377F4[][3];
extern s16 ov07_022377DC[][2];

extern void ov12_0225B7B8(SysTask *, void *);
extern void ov12_0225B494(SysTask *, void *);

void BattleDisplay_InitTaskSetEncounter(BattleSystem *battleSys, OpponentData *opponentData, MonEncounterMessage *message)
{
    BOOL isShiny;
    PokepicTemplate spriteTemplate;
    PokepicManager *spriteMan = BattleSystem_GetPokepicManager(battleSys);
    PokepicAnimScript animScript[10];
    MonEncounterData *monEncounterData;
    int battleType = BattleSystem_GetBattleType(battleSys);
    u8 yOffset;
    s8 height;
    s8 shadowXOffset;
    u8 shadowSize;

    monEncounterData = Heap_Alloc(HEAP_ID_BATTLE, sizeof(MonEncounterData));

    monEncounterData->state = 0;

    if (opponentData->battlerType & 1) {
        monEncounterData->face = 2;
        monEncounterData->terrain = ov12_0223A8F4(battleSys, 1);
        ManagedSprite_SetPositionXY(monEncounterData->terrain->managedSprite, ov07_022377F4[opponentData->battlerType & 1][0], 8 * 11);
    } else {
        monEncounterData->face = 0;
        monEncounterData->terrain = ov12_0223A8F4(battleSys, 0);
        ManagedSprite_SetPositionXY(monEncounterData->terrain->managedSprite, ov07_022377F4[opponentData->battlerType & 1][0], 128 + 8);
    }

    isShiny = !!message->isShiny;

    GetMonSpriteCharAndPlttNarcIdsEx(&spriteTemplate, message->species, message->gender, monEncounterData->face, isShiny, message->formNum, message->personality);

    yOffset = GetMonPicHeightBySpeciesGenderForm(message->species, message->gender, monEncounterData->face, message->formNum, message->personality);

    sub_020729D8(opponentData->narc, &height, message->species);
    sub_020729FC(opponentData->narc, &shadowXOffset, message->species);
    sub_02072A20(opponentData->narc, &shadowSize, message->species);
    NARC_ReadPokepicAnimScript(opponentData->narc, &animScript[0], message->species, opponentData->battlerType);

    monEncounterData->sprite = opponentData->pokepic = ov12_022612A4(battleSys,
        spriteMan,
        &spriteTemplate,
        ov07_022377F4[opponentData->battlerType][0],
        ov07_022377F4[opponentData->battlerType][1],
        ov07_022377F4[opponentData->battlerType][2],
        yOffset,
        height,
        shadowXOffset,
        shadowSize,
        opponentData->battlerId,
        &animScript[0],
        NULL);

    if (monEncounterData->face == 2) {
        Pokepic_StartPaletteFade(monEncounterData->sprite, 8, 8, 0, 0);
    }

    if (monEncounterData->face == 2 && (BattleSystem_GetBattleSpecial(battleSys) & 0x40)) {
        int v10 = ((24 * 8) + 80) / 2;
        int spriteYCenter = Pokepic_GetAttr(monEncounterData->sprite, 1);

        Pokepic_SetAttr(monEncounterData->sprite, 46, 0);
        Pokepic_SetAttr(monEncounterData->sprite, 0, 256 - 64);
        Pokepic_SetAttr(monEncounterData->sprite, 1, spriteYCenter - v10);

        monEncounterData->targetPos = spriteYCenter;
    } else {
        monEncounterData->targetPos = ov07_022377DC[opponentData->battlerType][0];
    }

    monEncounterData->battleSys = battleSys;
    monEncounterData->opponentData = opponentData;
    monEncounterData->command = message->command;
    monEncounterData->battler = opponentData->battlerId;
    monEncounterData->species = message->species;
    monEncounterData->formNum = message->formNum;
    monEncounterData->cryMod = message->cryModulation;
    monEncounterData->battlerType = opponentData->battlerType;
    monEncounterData->nature = GetNatureFromPersonality(message->personality);
    monEncounterData->isShiny = message->isShiny;

    if (monEncounterData->face == 2 && (BattleSystem_GetBattleSpecial(battleSys) & 0x40)) {
        SysTask_CreateOnMainQueue(ov12_0225B7B8, monEncounterData, 0);
    } else {
        SysTask_CreateOnMainQueue(ov12_0225B494, monEncounterData, 0);
    }

    sub_02005B58(TRUE);
}

extern void ov12_0225B960(SysTask *, void *);
extern void ov12_0225BE38(SysTask *, void *);

typedef struct MonShowData {
    BattleSystem *battleSys;
    OpponentData *opponentData;
    void *ballCapsuleSealEffect;
    void *ballRotation;
    void *btlMonObjData;
    PokepicTemplate spriteTemplate;
    void *battleAnimSys;
    MoveAnimation moveAnim;
    u8 command;
    u8 battler;
    u8 battlerType;
    u8 state;
    u8 face;
    u8 yOffset;
    u16 species;
    int cryMod;
    u8 selectedPartySlot;
    u8 nature;
    u16 capturedBall;
    s8 height;
    s8 shadowXOffset;
    u8 isShiny;
    u8 shadowSize;
    u16 isQuickSendOut;
    u8 delay;
    u8 formNum;
    int isSubstitute;
} MonShowData;

void BattleDisplay_InitTaskShowEncounter(BattleSystem *battleSys, OpponentData *opponentData, MonShowMessage *message)
{
    BOOL isShiny;
    MonShowData *monShowData;
    int battleType = BattleSystem_GetBattleType(battleSys);
    monShowData = Heap_Alloc(HEAP_ID_BATTLE, sizeof(MonShowData));

    if (opponentData->battlerType & 1) {
        monShowData->face = 2;
    } else {
        monShowData->face = 0;
    }

    isShiny = !!message->isShiny;

    GetMonSpriteCharAndPlttNarcIdsEx(&monShowData->spriteTemplate, message->species, message->gender, monShowData->face, isShiny, message->formNum, message->personality);

    monShowData->yOffset = GetMonPicHeightBySpeciesGenderForm(message->species, message->gender, monShowData->face, message->formNum, message->personality);

    sub_020729D8(opponentData->narc, &monShowData->height, message->species);
    sub_020729FC(opponentData->narc, &monShowData->shadowXOffset, message->species);
    sub_02072A20(opponentData->narc, &monShowData->shadowSize, message->species);
    OpponentData_ClearSavedCursorPosition(opponentData);

    monShowData->battleSys = battleSys;
    monShowData->opponentData = opponentData;
    monShowData->state = 0;
    monShowData->delay = 0;
    monShowData->command = message->command;
    monShowData->battler = opponentData->battlerId;
    monShowData->species = message->species;
    monShowData->formNum = message->formNum;
    monShowData->battlerType = opponentData->battlerType;
    monShowData->cryMod = message->cryModulation;
    monShowData->selectedPartySlot = message->selectedPartySlot;
    monShowData->nature = GetNatureFromPersonality(message->personality);
    monShowData->capturedBall = message->capturedBall;
    monShowData->isShiny = message->isShiny;
    monShowData->isQuickSendOut = 0;

    sub_02005B58(TRUE);

    battleType = BattleSystem_GetBattleType(battleSys);
    
    if (ov12_0223C140(battleSys, opponentData->battlerId) != 255) {
        if ((battleType & 2) && !(battleType & 8) && opponentData->battlerType > 3) {
            SysTask_CreateOnMainQueue(ov12_0225B960, monShowData, 0);
        } else {
            SysTask_CreateOnMainQueue(ov12_0225BE38, monShowData, 0);
        }
    } else {
        SysTask_CreateOnMainQueue(ov12_0225B960, monShowData, 0);
    }
}

extern void ov12_0225C18C(SysTask *, void *);
extern void ov12_0225C6C8(SysTask *, void *);

void BattleDisplay_InitTaskShowPokemon(BattleSystem *battleSys, OpponentData *opponentData, MonShowMessage *message)
{
    BOOL isShiny;
    MonShowData *monShowData;
    int battleType = BattleSystem_GetBattleType(battleSys);
    monShowData = Heap_Alloc(HEAP_ID_BATTLE, sizeof(MonShowData));
    monShowData->state = 0;

    if (opponentData->battlerType & 1) {
        monShowData->face = 2;
    } else {
        monShowData->face = 0;
    }

    isShiny = !!message->isShiny;

    GetMonSpriteCharAndPlttNarcIdsEx(&monShowData->spriteTemplate, message->species, message->gender, monShowData->face, isShiny, message->formNum, message->personality);

    monShowData->yOffset = GetMonPicHeightBySpeciesGenderForm(message->species, message->gender, monShowData->face, message->formNum, message->personality);

    sub_020729D8(opponentData->narc, &monShowData->height, message->species);
    sub_020729FC(opponentData->narc, &monShowData->shadowXOffset, message->species);
    sub_02072A20(opponentData->narc, &monShowData->shadowSize, message->species);
    OpponentData_ClearSavedCursorPosition(opponentData);

    monShowData->battleSys = battleSys;
    monShowData->opponentData = opponentData;
    monShowData->command = message->command;
    monShowData->battler = opponentData->battlerId;
    monShowData->species = message->species;
    monShowData->formNum = message->formNum;
    monShowData->battlerType = opponentData->battlerType;
    monShowData->cryMod = message->cryModulation;
    monShowData->selectedPartySlot = message->selectedPartySlot;
    monShowData->nature = GetNatureFromPersonality(message->personality);
    monShowData->capturedBall = message->capturedBall;
    monShowData->isShiny = message->isShiny;
    monShowData->isQuickSendOut = message->isQuickSendOut;
    monShowData->delay = 0;
    monShowData->isSubstitute = message->isSubstitute;

    for (int i = 0; i < 4; i++) {
        monShowData->moveAnim.species[i] = message->battleMonSpecies[i];
        monShowData->moveAnim.genders[i] = message->battleMonGenders[i];
        monShowData->moveAnim.isShiny[i] = message->battleMonIsShiny[i];
        monShowData->moveAnim.formNums[i] = message->battleMonFormNums[i];
        monShowData->moveAnim.personalities[i] = message->battleMonPersonalities[i];
    }

    u32 unk = ov12_0223C140(battleSys, opponentData->battlerId);
    
    if (unk == 255 || unk != monShowData->selectedPartySlot) {
        SysTask_CreateOnMainQueue(ov12_0225C18C, monShowData, 0);
    } else {
        SysTask_CreateOnMainQueue(ov12_0225C6C8, monShowData, 0);
    }
}

typedef struct MonReturnData {
    BattleSystem *battleSys;
    OpponentData *opponentData;
    Pokepic *monSprite;
    void *ballRotation;
    MoveAnimation moveAnim;
    u8 command;
    u8 battler;
    u8 battlerType;
    u8 state;
    u8 yOffset;
    u8 unused;
    u16 capturedBall;
    int isSubstitute;
    u32 unk_74;
} MonReturnData;

void ov12_0225C9BC(SysTask *, void *);
void ov12_0225CC58(SysTask *, void *);

void BattleDisplay_InitTaskReturnPokemon(BattleSystem *battleSys, OpponentData *opponentData, MonReturnMessage *message)
{
    MonReturnData *monReturnData = Heap_Alloc(HEAP_ID_BATTLE, sizeof(MonReturnData));
    monReturnData->battleSys = battleSys;
    monReturnData->opponentData = opponentData;
    monReturnData->monSprite = opponentData->pokepic;
    monReturnData->command = message->command;
    monReturnData->battler = opponentData->battlerId;
    monReturnData->battlerType = opponentData->battlerType;
    monReturnData->state = 0;
    monReturnData->yOffset = message->yOffset;
    monReturnData->capturedBall = message->capturedBall;
    monReturnData->isSubstitute = message->isSubstitute;
    monReturnData->unk_74 = message->unk2C;

    for (int i = 0; i < 4; i++) {
        monReturnData->moveAnim.species[i] = message->battleMonSpecies[i];
        monReturnData->moveAnim.genders[i] = message->battleMonGenders[i];
        monReturnData->moveAnim.isShiny[i] = message->battleMonIsShiny[i];
        monReturnData->moveAnim.formNums[i] = message->battleMonFormNums[i];
        monReturnData->moveAnim.personalities[i] = message->battleMonPersonalities[i];
    }

    u32 unk = ov12_0223C140(battleSys, opponentData->battlerId);
    
    if (unk == 255 || unk != monReturnData->unk_74) {
        SysTask_CreateOnMainQueue(ov12_0225C9BC, monReturnData, 0);
    } else {
        SysTask_CreateOnMainQueue(ov12_0225CC58, monReturnData, 0);
    }
}
