#ifndef POKEHEARTGOLD_FIELD_WEATHER_MANAGER_H
#define POKEHEARTGOLD_FIELD_WEATHER_MANAGER_H

#include "global.h"
#include "task.h"

typedef struct WeatherDraw {
    GF_2DGfxResMan *resMan[4];
    GF_2DGfxResHeader *header;
    NNSG2dRendererInstance instance;
    NNSG2dRenderSurface surface;
    SpriteList *spriteList;
    SysTask *task;
} WeatherDraw;

typedef struct WeatherSystem WeatherSystem;


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
    u32 unkC;
    u32 unk10;
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

// Not yet decompiled
void ov01_021EB3F0(SysTask *task, void *data);
void ov01_021EB56C(SysTask *task, void *data);
void ov01_021EB578(GF_2DGfxResHeader *header, u32 a1, u32 a2);
void ov01_021EBB90(WeatherSystem *weatherSystem, u32 a1);
void ov01_021EA864(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5);
BOOL ov01_021EB9A8(WeatherSystem *weatherSystem, int weather);
BOOL ov01_021EBA08(WeatherSystem *weatherSystem, int weather);
BOOL ov01_021EBB68(WeatherSystem *weatherSystem, int weather);
BOOL ov01_021EBB40(WeatherSystem *weatherSystem, int weather, u32 a2);
BOOL ov01_021EBA44(WeatherSystem *weatherSystem, int weather, u32 a2, u32 a3);
BOOL ov01_021EA854(u32 a0);

#endif // POKEHEARTGOLD_FIELD_WEATHER_MANAGER_H
