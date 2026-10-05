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