#ifndef POKEHEARTGOLD_FIELD_WEATHER_MANAGER_H
#define POKEHEARTGOLD_FIELD_WEATHER_MANAGER_H

#include "global.h"
#include "task.h"
#include "sprite.h"
#include "field/fog.h"

typedef struct UnkWeatherStruct_021EB968 {
    SpriteResource *charResObj[4];
    SpriteTemplate unk10;
    SpriteResourcesHeader unk40;
} UnkWeatherStruct_021EB968;

typedef struct WeatherSystem_Sub4 {
    u32 unk0;
    u32 unk4;
    u32 unk8;
} WeatherSystem_Sub4;

typedef struct WeatherDraw {
    GF_2DGfxResMan *resMan[4];
    GF_2DGfxResHeader *header;
    NNSG2dRendererInstance instance;
    NNSG2dRenderSurface surface;
    SpriteList *spriteList;
    SysTask *task;
} WeatherDraw;

typedef struct UnkWeatherStruct_021EC078 {
    void *unk0;
    void *unk4;
    void *unk8;
    NNSG2dScreenData *unkC;
    NNSG2dCharacterData *unk10;
    NNSG2dPaletteData *unk14;
} UnkWeatherStruct_021EC078;

typedef struct WeatherSystem WeatherSystem;
typedef struct WeatherSystem_Sub0 WeatherSystem_Sub0;
typedef struct WeatherSystem_Sub0_Sub8 WeatherSystem_Sub0_Sub8;
typedef struct WeatherSystem_Sub0_Sub8_LinkedList WeatherSystem_Sub0_Sub8_LinkedList;
struct WeatherSystem_Sub0_Sub8_LinkedList {
    WeatherSystem *weatherSystem;
    Sprite *unk4;
    u32 *unk8;
    u32 unk10[10];
    WeatherSystem_Sub0_Sub8_LinkedList *next;
    WeatherSystem_Sub0_Sub8_LinkedList *prev;
};

typedef struct UnkStruct_ov01_021EB1E8 {
    u8 unk0[0x188];
    u32 unk188;
} UnkStruct_ov01_021EB1E8;

typedef struct WeatherManager {
    WeatherSystem *weatherSystem;
    u32 weather;
    u32 nextWeather;
    u32 state;
    u32 unk10;
    SysTask *task;
} WeatherManager;

typedef struct UnkWeatherStruct_021EB830 {
    u32 unk0;
    u32 unk4;
    u32 unk8;
    int unkC;
    int unk10;
} UnkWeatherStruct_021EB830;
typedef void (*UnkWeatherSystemSub0Sub8Func)(WeatherSystem_Sub0_Sub8 *, int);
typedef struct UnkStruct_021EC504 {
    WeatherSystem_Sub0_Sub8 *unk0;
    s16 unk4;
    s16 unk6;
    s16 unk8;
    s16 unkA;
    s16 unkC;
    s16 unkE;
    s16 unk10;
    s16 unk12;
    s32 unk14;
    UnkWeatherSystemSub0Sub8Func unk18;
} UnkStruct_021EC504;

typedef void (*UnkLinkedListFunc)(WeatherSystem_Sub0_Sub8_LinkedList *);

typedef struct UnkStruct_021EC5FC {
    FogData *fog;
    UnkWeatherStruct_021EB830 unk4;
    UnkWeatherStruct_021EB830 unk18;
    UnkWeatherStruct_021EB830 unk2C;
    UnkWeatherStruct_021EB830 unk40;
    UnkWeatherStruct_021EB830 unk54;
} UnkStruct_021EC5FC;

typedef struct UnkStruct_021EC774 {
    FogData *fog;
    u8 unk4[0x20];
    s32 unk24;
    s32 unk28;
    s16 unk2C;
    s16 unk2E;
} UnkStruct_021EC774;

typedef struct UnkStruct_021EC94C {
    UnkStruct_021EC504 unk0;
    UnkStruct_021EC774 unk1C;
    UnkStruct_021EC5FC unk50;
    s32 data[10];
} UnkStruct_021EC94C;

typedef struct UnkStruct_021ED474 {
    UnkStruct_021EC774 unk1C;
    UnkStruct_021EC5FC unk50;
    s32 data[10];
} UnkStruct_021ED474;

typedef struct UnkStruct_021ED584 {
    UnkWeatherStruct_021EB830 unk0;
    UnkStruct_021EC774 unk1C;
    UnkStruct_021EC5FC unk50;
} UnkStruct_021ED584;

void ov01_021EB1E8(UnkStruct_ov01_021EB1E8 *a0);
WeatherManager *WeatherManager_New(FieldSystem *fieldSystem);
void WeatherManager_Delete(WeatherManager* weatherManager);
void WeatherManager_SetWeather(WeatherManager* weatherManager, int a1);
BOOL WeatherManager_ChangeWeather(WeatherManager* weatherManager, s32 weather);
u32 WeatherManager_GetWeather(WeatherManager *weatherManager);
WeatherSystem* WeatherSystem_New(FieldSystem *fieldSystem);
void WeatherSystem_Delete(WeatherSystem** pWeatherSystem);
BOOL WeatherSystem_Process(WeatherSystem *weatherSystem, int state, int weather);

// Static functions
void WeatherTask_ChangeWeather(SysTask* task, void *data);
void ov01_021EB3F0(SysTask* task, void *data);
BOOL ov01_021EB4B4(u32 weather, u32 nextWeather);
void WeatherDraw_Init(WeatherDraw* weatherDraw);
void WeatherDrawTask_RendAndAnimateSprites(SysTask *task, void *data);
void Weather_Init2DGfxRes(GF_2DGfxResHeader *headerList, u32 a1, u32 a2);
void WeatherDraw_Delete(WeatherDraw* weatherDraw);
void WeatherDraw_SetSpriteMatrix(Sprite *sprite, VecFx32* matrix);
u16 ov01_021EB804(WeatherSystem* weatherSystem, int weather);
void ov01_021EB818(u32 arg0, u32 arg1);
void ov01_021EB830(UnkWeatherStruct_021EB830* arg0, s32 arg1, s32 arg2, s32 arg3);
BOOL ov01_021EB840(UnkWeatherStruct_021EB830* a0);
void ov01_021EB86C(WeatherSystem *weatherSystem, s32 arg1, UnkWeatherStruct_021EB968 *arg2);
SpriteResource *ov01_021EB898(GF_2DGfxResHeader *headerList, s32 resIndex, s32 headerIndex, GF_2DGfxResMan *resMan, NARC *narc, BOOL atEnd);
void ov01_021EB968(WeatherSystem* weatherSystem, s32 a1, UnkWeatherStruct_021EB968* a2);
BOOL WeatherSystem_Init(WeatherSystem* weatherSystem, int weather);
BOOL ov01_021EBA08(WeatherSystem *weatherSystem, int weather);
void ov01_021EBB40(WeatherSystem *weatherSystem, int weather, u16 a2);
void ov01_021EBB68(WeatherSystem *weatherSystem, int weather);
void ov01_021EBB90(WeatherSystem *weatherSystem, u32 weather);
void ov01_021EBCA4(WeatherSystem_Sub0* a0);
void ov01_021EBD18(WeatherSystem *weatherSystem, u16 a1);
BOOL ov01_021EBD34(WeatherSystem *weatherSystem, WeatherSystem_Sub0 *a1);
BOOL ov01_021EBE4C(WeatherSystem *weatherSystem, WeatherSystem_Sub0 *a1);
BOOL ov01_021EBEB8(WeatherSystem_Sub0 *a0);
void ov01_021EBEF0(WeatherSystem *weatherSystem, u32 a1, UnkWeatherStruct_021EB968 *a2);
void ov01_021EBF24(WeatherSystem *weatherSystem, u32 a1, UnkWeatherStruct_021EB968 *a2);
void ov01_021EBF58(WeatherSystem *weatherSystem, u32 a1, UnkWeatherStruct_021EB968 *a2);
void ov01_021EBF94(WeatherSystem *weatherSystem, u32 a1, UnkWeatherStruct_021EB968 *a2);
void ov01_021EBFD0(WeatherSystem *weatherSystem, WeatherSystem_Sub0 *a1);
void ov01_021EC028(WeatherSystem_Sub0_Sub8 *a0);
void ov01_021EC078(WeatherSystem *weatherSystem, u16 a1);
void ov01_021EC0C0(WeatherSystem *weatherSystem, u16 a1);
void ov01_021EC114(WeatherSystem* weatherSystem, u16 a1);
void ov01_021EC1BC(WeatherSystem_Sub0_Sub8_LinkedList* a0, int a1);
void ov01_021EC1E4(WeatherSystem_Sub0_Sub8_LinkedList* a0);
void ov01_021EC240(SpriteResourcesHeader *spriteTemplate, WeatherSystem *weatherSystem, UnkWeatherStruct_021EB968 *a2, u32 a3, u32 a4);
void ov01_021EC29C(WeatherSystem_Sub0_Sub8_LinkedList* a0);
void ov01_021EC2CC(WeatherSystem_Sub0_Sub8_LinkedList * a0);
void ov01_021EC2E4(WeatherSystem_Sub0_Sub8_LinkedList *a0, UnkLinkedListFunc func);
void ov01_021EC300(void *data);
VecFx32 ov01_021EC304(WeatherSystem_Sub0_Sub8_LinkedList *a0);
void ov01_021EC31C(fx32* x, fx32* z, WeatherSystem_Sub0_Sub8* a0);
void ov01_021EC470(WeatherSystem_Sub0_Sub8 *a0, int *xOut, int *zOut);
void ov01_021EC4A8(WeatherSystem_Sub0_Sub8 *a0, fx32 *x, fx32 *y);
void ov01_021EC504(UnkStruct_021EC504* arg0, WeatherSystem_Sub0_Sub8 *arg1, s16 arg2, s16 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8, UnkWeatherSystemSub0Sub8Func arg9);
void ov01_021EC52C(UnkStruct_021EC504* arg0, s16 arg1, s16 arg2, s16 arg3, s32 arg4);
s32 ov01_021EC538(UnkStruct_021EC504* arg0);
void ov01_021EC5FC(UnkStruct_021EC5FC *arg0, UnkStruct_021EC774* arg1, FogData *fog, GXFogSlope fogSlope, s32 fogOffset, GXRgb rgb, s32 arg6, s32 arg7);
BOOL ov01_021EC650(UnkStruct_021EC5FC *arg0, UnkStruct_021EC774 *arg1, s32 arg2);
void ov01_021EC678(FogData *fog, GXFogSlope fogSlope, s32 fogOffset, GXRgb rgb);
void ov01_021EC6A4(UnkStruct_021EC5FC* arg0, FogData *fog, s32 arg2, s32 arg3, GXRgb rgb, s32 arg5);
BOOL ov01_021EC728(UnkStruct_021EC5FC *arg0);
void ov01_021EC774(UnkStruct_021EC774* a0);
void ov01_021EC790(UnkStruct_021EC774* arg0, s32 arg1, s32 arg2);
s32 ov01_021EC7AC(UnkStruct_021EC774* arg0);
void ov01_021EC7C8(UnkStruct_021EC774* arg0);
s32 ov01_021EC7E8(UnkStruct_021EC774 *arg0);
void ov01_021EC828(UnkStruct_021EC774 *arg0);
void ov01_021EC85C(WeatherSystem_Sub0_Sub8 *a0, UnkWeatherSystemSub0Sub8Func a1, int a2, int a3, int a4, UnkLinkedListFunc a5);
WeatherSystem_Sub0_Sub8_LinkedList *ov01_021EC8D8(WeatherSystem_Sub0_Sub8 *a0);
void ov01_021EC8F8(SysTask *task, void* data);
void ov01_021EC94C(SysTask *task, void *data);
void ov01_021ECBB4(WeatherSystem_Sub0_Sub8 *, int);
void ov01_021ECC70(WeatherSystem_Sub0_Sub8_LinkedList *a0);
void ov01_021ECD08(SysTask *task, void* data);
void ov01_021ECF4C(WeatherSystem_Sub0_Sub8* a0, int a1);
void ov01_021ED070(WeatherSystem_Sub0_Sub8_LinkedList *a0);
void ov01_021ED0F0(SysTask *task, void* data);
void ov01_021ED31C(WeatherSystem_Sub0_Sub8 *a0, int a1);
void ov01_021ED44C(WeatherSystem_Sub0_Sub8_LinkedList *a0);
void ov01_021ED474(WeatherSystem_Sub0_Sub8* a0, UnkStruct_021ED474* a1, GXFogSlope fogSlope, s32 arg3, GXRgb arg4, s32 arg5, s32 arg6);
void ov01_021ED584(SysTask *task, void* data);

// Not yet decompiled
void ov01_021EB3F0(SysTask *task, void *data);
void WeatherDrawTask_RendAndAnimateSprites(SysTask *task, void *data);
void Weather_Init2DGfxRes(GF_2DGfxResHeader *header, u32 a1, u32 a2);
BOOL WeatherSystem_Start(WeatherSystem *weatherSystem, int weather, u32 a2, u32 a3);
void ov01_021EBD70(SysTask *task, void *data);
void ov01_021EC058(WeatherSystem_Sub0_Sub8 *a0);
void ov01_021EDAE0(WeatherSystem_Sub0_Sub8 *a0);
void* ov01_021EC1F4(WeatherSystem_Sub0_Sub8* a0, int a1);
void ov01_021EDA7C(SysTask *task, void *data);

#endif // POKEHEARTGOLD_FIELD_WEATHER_MANAGER_H
