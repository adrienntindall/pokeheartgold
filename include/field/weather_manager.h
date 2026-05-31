#ifndef POKEHEARTGOLD_FIELD_WEATHER_MANAGER_H
#define POKEHEARTGOLD_FIELD_WEATHER_MANAGER_H

#include "global.h"
#include "task.h"

typedef struct UnkStruct_ov01_021EB1E8 {
    u8 unk0[0x188];
    u32 unk188;
} UnkStruct_ov01_021EB1E8;

typedef struct WeatherManager {
    u32 unk0;
    u32 weather;
    u32 nextWeather;
    u32 state;
    u32 unk10;
    SysTask *task;
} WeatherManager;

typedef struct WeatherDraw {
    GF_2DGfxResMan *resMan[4];
    GF_2DGfxResHeader *header;
    NNSG2dRendererInstance instance;
    NNSG2dRenderSurface surface;
    SpriteList *spriteList;
    SysTask *task;
} WeatherDraw;

void ov01_021EB1E8(UnkStruct_ov01_021EB1E8 *a0);
WeatherManager *WeatherManager_New(u32 a0);
void WeatherManager_Delete(WeatherManager* weatherManager);
void WeatherManager_SetWeather(WeatherManager* weatherManager, int a1);
BOOL WeatherManager_ChangeWeather(WeatherManager* weatherManager, s32 weather);
u32 WeatherManager_GetWeather(WeatherManager *weatherManager);

// Static functions
void WeatherTask_ChangeWeather(SysTask* task, void *data);
void ov01_021EB3F0(SysTask* task, void *data);
BOOL ov01_021EB4B4(u32 weather, u32 nextWeather);
void ov01_021EB4B8(WeatherDraw* weatherDraw);

// Not yet decompiled
u32 ov01_021EB64C(u32 a0);
void ov01_021EB68C(WeatherManager *weatherManager);
u32 ov01_021EB700(u32 a0, u32 a1, u32 weather);
void ov01_021EB3F0(SysTask *task, void *data);
u32 ov01_021EB804(u32 a0, u32 weather);
void ov01_021EB56C(SysTask *task, void *data);
void ov01_021EB578(GF_2DGfxResHeader *header, u32 a1, u32 a2);

#endif // POKEHEARTGOLD_FIELD_WEATHER_MANAGER_H
