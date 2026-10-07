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
extern s16 gBattlerEncounterX[][2];

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
        monEncounterData->targetPos = gBattlerEncounterX[opponentData->battlerType][0];
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
    Pokepic *pokepic;
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
    monReturnData->pokepic = opponentData->pokepic;
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

typedef struct OpenCaptureBallData {
    BattleSystem *battleSys;
    Pokepic *pokepic;
    u8 command;
    u8 battler;
    u8 battlerType;
    u8 state;
    u8 yOffset;
    u8 unused_0D;
    u16 unused_0E;
} OpenCaptureBallData;

extern u16 ov12_0226D15A[];
extern void ov12_0225CDB8(SysTask *, void *);

void BattleDisplay_InitTaskOpenCaptureBall(BattleSystem *battleSys, OpponentData *opponentData, OpenCaptureBallMessage *message)
{
    OpenCaptureBallData *captureOpenBallData = Heap_Alloc(HEAP_ID_BATTLE, sizeof(OpenCaptureBallData));

    captureOpenBallData->battleSys = battleSys;
    captureOpenBallData->pokepic = opponentData->pokepic;
    captureOpenBallData->command = message->command;
    captureOpenBallData->battler = opponentData->battlerId;
    captureOpenBallData->battlerType = opponentData->battlerType;
    captureOpenBallData->state = 0;
    captureOpenBallData->yOffset = message->yOffset;

    Pokepic_StartPaletteFade(captureOpenBallData->pokepic, 0, 16, 0, ov12_0226D15A[message->ball]);
    Pokepic_SetAttr(captureOpenBallData->pokepic, 0x2D, TRUE);
    SysTask_CreateOnMainQueue(ov12_0225CDB8, captureOpenBallData, 0);
}

typedef struct TrainerEncounterData {
    BattleSystem *battleSys;
    Pokepic *pokepic;
    UnkBattleSystemSub17C *terrain;
    ManagedSprite *managedSprite;
    u8 command;
    u8 battler;
    u8 state;
    u8 face;
    s16 targetX;
    u16 ballFlashStarted : 1;
    u16 padding_12_1 : 15;
    int battlerType;
    int delay;
    int enterFrameCount;
} TrainerEncounterData;

extern void ov12_0225CE28(SysTask *, void *);
extern u8 BattleDisplay_GetLinkTrainerClass(BattleSystem *battleSys, u8 battler, u8 trainerClass);

void BattleDisplay_InitTaskSetTrainerEncounter(BattleSystem *battleSys, OpponentData *opponentData, TrainerEncounterMessage *message)
{
    TrainerEncounterData *trainerEncounterData = Heap_Alloc(HEAP_ID_BATTLE, sizeof(TrainerEncounterData));
    int side;

    trainerEncounterData->state = 0;

    if (opponentData->battlerType & 1) {
        trainerEncounterData->face = 2;
        trainerEncounterData->terrain = ov12_0223A8F4(battleSys, 1);
        ManagedSprite_SetPositionXY(trainerEncounterData->terrain->managedSprite, ov07_022377F4[opponentData->battlerType & 1][0], 8 * 11);
    } else {
        trainerEncounterData->face = 0;
        trainerEncounterData->terrain = ov12_0223A8F4(battleSys, 0);
        ManagedSprite_SetPositionXY(trainerEncounterData->terrain->managedSprite, ov07_022377F4[opponentData->battlerType & 1][0], 128 + 8);
    }

    if ((BattleSystem_GetBattleType(battleSys) & BATTLE_TYPE_MULTI)
        || (BattleSystem_GetBattleType(battleSys) & BATTLE_TYPE_TAG && opponentData->battlerType & BATTLE_TYPE_TRAINER)) {
        side = opponentData->battlerType;
    } else {
        side = opponentData->battlerType & 1;
    }

    message->trainerType = BattleDisplay_GetLinkTrainerClass(battleSys, opponentData->battlerId, message->trainerType);

    u32 battleType = BattleSystem_GetBattleType(battleSys);
    u32 flag = 0;
    
    if (ov12_0223C140(battleSys, opponentData->battlerId) != 255) {
        if (battleType & 2 && !(battleType & 8)) {
            flag = 0;
        } else {
            flag = 1;
        }
    } 
    
    trainerEncounterData->managedSprite = opponentData->managedSprite = BattleDisplay_NewManagedSpriteTrainer(battleSys,
        side,
        message->trainerType,
        opponentData->battlerType,
        flag,
        ov07_022377F4[side][0],
        ov07_022377F4[side][1]);

    if (trainerEncounterData->face == 0 
        && (BattleSystem_GetBattleType(battleSys) == 0 
        || BattleSystem_GetBattleType(battleSys) == 0x20 
        || BattleSystem_GetBattleType(battleSys) == (1 << 8) 
        || BattleSystem_GetBattleType(battleSys) == (1 << 9) 
        || BattleSystem_GetBattleType(battleSys) == (1 << 10) 
        || BattleSystem_GetBattleType(battleSys) == (1 << 12))) {
            PokepicManager *pokepicManager = BattleSystem_GetPokepicManager(battleSys);
            PokepicTemplate pokepicTemplate;
            UnkStruct_02070D3C unkStruct;
            sub_02070D84(message->trainerType, trainerEncounterData->face, &unkStruct);
            pokepicTemplate.narcID = unkStruct.narcId;
            pokepicTemplate.charDataID = unkStruct.ncbr_id;
            pokepicTemplate.palDataID = unkStruct.nclr_id;
            pokepicTemplate.species = SPECIES_NONE;
            pokepicTemplate.isAnimated = FALSE;
            pokepicTemplate.personality = 0;
            trainerEncounterData->pokepic = PokepicManager_CreatePokepic(pokepicManager, &pokepicTemplate, ov07_022377F4[side][0], ov07_022377F4[side][1], ov07_022377F4[side][2], opponentData->battlerId, 0, 0);
        
    } else {
        trainerEncounterData->pokepic = NULL;   
    }
    trainerEncounterData->targetX = gBattlerEncounterX[side][0];
    trainerEncounterData->battleSys = battleSys;
    trainerEncounterData->command = message->command;
    trainerEncounterData->battler = opponentData->battlerId;
    trainerEncounterData->battlerType = opponentData->battlerType;
    trainerEncounterData->enterFrameCount = 0;

    if (trainerEncounterData->battlerType == BATTLER_TYPE_SOLO_PLAYER
        || trainerEncounterData->battlerType == BATTLER_TYPE_PLAYER_SIDE_SLOT_1) {
        BgSetPosTextAndCommit(BattleSystem_GetBgConfig(battleSys), 3, 2, 4 * 33);
    }

    SysTask_CreateOnMainQueue(ov12_0225CE28, trainerEncounterData, 0);
}

typedef struct TrainerThrowBallData {
    BattleSystem *battleSys;
    OpponentData *opponentData;
    u8 command;
    u8 battler;
    u8 state;
    u8 face;
    int backSpriteIdx;
    int ballTypeIn;
    int delay;
    int ballTargetState;
} TrainerThrowBallData;

extern void ov12_0225D644(SysTask *, void *);
extern void ov12_0225D138(SysTask *, void *);

void BattleDisplay_InitTaskThrowTrainerBall(BattleSystem *battleSys, OpponentData *opponentData, TrainerThrowBallMessage *message)
{
    TrainerThrowBallData *trainerThrowBallData = Heap_Alloc(HEAP_ID_BATTLE, sizeof(TrainerThrowBallData));

    trainerThrowBallData->state = 0;
    trainerThrowBallData->battleSys = battleSys;
    trainerThrowBallData->command = message->command;
    trainerThrowBallData->ballTypeIn = message->ballTypeIn;
    trainerThrowBallData->battler = opponentData->battlerId;
    trainerThrowBallData->opponentData = opponentData;

    if (opponentData->battlerType & 1) {
        trainerThrowBallData->face = 2;
        trainerThrowBallData->backSpriteIdx = 0;
    } else {
        Trainer *trainer = BattleSystem_GetTrainer(battleSys, opponentData->battlerId);
        trainerThrowBallData->face = 0;
        trainerThrowBallData->backSpriteIdx = TrainerClassToBackpicID(BattleDisplay_GetLinkTrainerClass(battleSys, opponentData->battlerId, trainer->data.trainerClass), 0);
    }

    u32 battleType = BattleSystem_GetBattleType(battleSys);

    if (ov12_0223C140(battleSys, opponentData->battlerId) != 255) {
        SysTask_CreateOnMainQueue(ov12_0225D644, trainerThrowBallData, 0);
    } else {
        SysTask_CreateOnMainQueue(ov12_0225D138, trainerThrowBallData, 0);
    }
}

typedef struct SlideTrainerOutData {
    BattleSystem *battleSys;
    OpponentData *opponentData;
    u8 command;
    u8 battler;
    u8 state;
    u8 face;
    int unused;
} SlideTrainerOutData;

extern void ov12_0225D890(SysTask *, void *);

void BattleDisplay_InitTaskSlideTrainerOut(BattleSystem *battleSys, OpponentData *opponentData)
{
    SlideTrainerOutData *slideTrainerOutData = Heap_Alloc(HEAP_ID_BATTLE, sizeof(SlideTrainerOutData));

    slideTrainerOutData->state = 0;
    slideTrainerOutData->battleSys = battleSys;
    slideTrainerOutData->command = opponentData->unk94[0];
    slideTrainerOutData->battler = opponentData->battlerId;
    slideTrainerOutData->opponentData = opponentData;

    if (opponentData->battlerType & 1) {
        slideTrainerOutData->face = 2;
    } else {
        slideTrainerOutData->face = 0;
    }

    SysTask_CreateOnMainQueue(ov12_0225D890, slideTrainerOutData, 0);
}

typedef struct SlideTrainerInData {
    BattleSystem *battleSys;
    ManagedSprite *managedSprite;
    u8 command;
    u8 battler;
    u8 state;
    u8 face;
    s16 x;
    u16 unused;
} SlideTrainerInData;

extern void ov12_0225D990(SysTask *, void *);
extern const s16 gSlideTrainerInCoords[][3];

void BattleDisplay_InitTaskSlideTrainerIn(BattleSystem *battleSys, OpponentData *opponentData, TrainerSlideInMessage *message)
{
    PokepicManager *unused = BattleSystem_GetPokepicManager(battleSys);
    SlideTrainerInData *slideTrainerInData = Heap_Alloc(HEAP_ID_BATTLE, sizeof(SlideTrainerInData));
    slideTrainerInData->state = 0;

    if (opponentData->battlerType & 1) {
        slideTrainerInData->face = 2;
    } else {
        slideTrainerInData->face = 0;
    }

    slideTrainerInData->managedSprite = opponentData->managedSprite = BattleDisplay_NewManagedSpriteTrainer(battleSys,
        opponentData->battlerType & 1,
        message->trainerType,
        opponentData->battlerType,
        0,
        gSlideTrainerInCoords[opponentData->battlerType & 1][0],
        gSlideTrainerInCoords[opponentData->battlerType & 1][1]);
    slideTrainerInData->x = gBattlerEncounterX[opponentData->battlerType & 1][message->posIn];
    slideTrainerInData->battleSys = battleSys;
    slideTrainerInData->command = message->command;
    slideTrainerInData->battler = opponentData->battlerId;

    SysTask_CreateOnMainQueue(ov12_0225D990, slideTrainerInData, 0);
}
