#ifndef POKEHEARTGOLD_FIELD_WEATHER_MANAGER_H
#define POKEHEARTGOLD_FIELD_WEATHER_MANAGER_H

#include "global.h"
#include "task.h"

typedef struct UnkWeatherStruct_021EB968 {
    SpriteResource *charResObj[4];
    u8 unk10[0x54];
} UnkWeatherStruct_021EB968;

typedef struct WeatherDraw {
    GF_2DGfxResMan *resMan[4];
    GF_2DGfxResHeader *header;
    NNSG2dRendererInstance instance;
    NNSG2dRenderSurface surface;
    SpriteList *spriteList;
    SysTask *task;
} WeatherDraw;

typedef struct WeatherSystem WeatherSystem;
typedef struct WeatherSystem_Sub0 WeatherSystem_Sub0;
typedef struct WeatherSystem_Sub0_Sub8 WeatherSystem_Sub0_Sub8;
typedef struct WeatherSystem_Sub0_Sub8_LinkedList WeatherSystem_Sub0_Sub8_LinkedList;

typedef struct UnkStruct_ov01_021EB1E8 {
    u8 unk0[0x188];
    u32 unk188;
} UnkStruct_ov01_021EB1E8;

typedef struct WeatherManager {
    WeatherSystem *unk0;
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

void ov01_021EB1E8(UnkStruct_ov01_021EB1E8 *a0);
WeatherManager *WeatherManager_New(FieldSystem *fieldSystem);
void WeatherManager_Delete(WeatherManager* weatherManager);
void WeatherManager_SetWeather(WeatherManager* weatherManager, int a1);
BOOL WeatherManager_ChangeWeather(WeatherManager* weatherManager, s32 weather);
u32 WeatherManager_GetWeather(WeatherManager *weatherManager);
WeatherSystem* WeatherSystem_New(FieldSystem *fieldSystem);
void ov01_021EB68C(WeatherSystem** pWeatherSystem);
BOOL ov01_021EB700(WeatherSystem *weatherSystem, int state, int weather);

// Static functions
void WeatherTask_ChangeWeather(SysTask* task, void *data);
void ov01_021EB3F0(SysTask* task, void *data);
BOOL ov01_021EB4B4(u32 weather, u32 nextWeather);
void WeatherDraw_Init(WeatherDraw* weatherDraw);
void ov01_021EB56C(SysTask *task, void *data);
void ov01_021EB578(GF_2DGfxResHeader *headerList, u32 a1, u32 a2);
void WeatherDraw_Delete(WeatherDraw* weatherDraw);
void ov01_021EB5F4(Sprite *sprite, VecFx32* matrix);
u16 ov01_021EB804(WeatherSystem* weatherSystem, int weather);
void ov01_021EB818(u32 arg0, u32 arg1);
void ov01_021EB830(UnkWeatherStruct_021EB830* arg0, s32 arg1, s32 arg2, s32 arg3);
BOOL ov01_021EB840(UnkWeatherStruct_021EB830* a0);
void ov01_021EB86C(WeatherSystem *weatherSystem, s32 arg1, UnkWeatherStruct_021EB968 *arg2);
SpriteResource *ov01_021EB898(GF_2DGfxResHeader *headerList, s32 resIndex, s32 headerIndex, GF_2DGfxResMan *resMan, NARC *narc, BOOL atEnd);
void ov01_021EB968(WeatherSystem* weatherSystem, s32 a1, UnkWeatherStruct_021EB968* a2);
BOOL ov01_021EB9A8(WeatherSystem* weatherSystem, int weather);
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

// Not yet decompiled
void ov01_021EB3F0(SysTask *task, void *data);
void ov01_021EB56C(SysTask *task, void *data);
void ov01_021EB578(GF_2DGfxResHeader *header, u32 a1, u32 a2);
void ov01_021EA864(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5);
BOOL ov01_021EBA44(WeatherSystem *weatherSystem, int weather, u32 a2, u32 a3);
BOOL ov01_021EA854(u32 a0);
void ov01_021EC028(WeatherSystem_Sub0_Sub8 *a0);
void ov01_021EBD70(SysTask *task, void *data);
void ov01_021EC2CC(WeatherSystem_Sub0_Sub8_LinkedList *linkedList);
void ov01_021EC058(WeatherSystem_Sub0_Sub8 *a0);
void ov01_021EDAE0(WeatherSystem_Sub0_Sub8 *a0);
void ov01_021EC078(WeatherSystem *weatherSystem, u16 a1);
void ov01_021EC0C0(WeatherSystem *weatherSystem, u16 a1);
void ov01_021EC114(WeatherSystem *weatherSystem, u16 a1);
void ov01_021EBFD0(WeatherSystem *weatherSystem, WeatherSystem_Sub0 *a1);

#endif // POKEHEARTGOLD_FIELD_WEATHER_MANAGER_H
