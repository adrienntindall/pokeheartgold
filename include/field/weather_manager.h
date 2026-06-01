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

typedef struct UnkWeatherStruct_021EB64C {
    u32 *unk0;
    u32 *unk4;
    WeatherDraw weatherDraw;
    FieldSystem *fieldSystem;
    NARC *narc;
} UnkWeatherStruct_021EB64C;


typedef struct UnkStruct_ov01_021EB1E8 {
    u8 unk0[0x188];
    u32 unk188;
} UnkStruct_ov01_021EB1E8;

typedef struct WeatherManager {
    UnkWeatherStruct_021EB64C *unk0;
    u32 weather;
    u32 nextWeather;
    u32 state;
    u32 unk10;
    SysTask *task;
} WeatherManager;



void ov01_021EB1E8(UnkStruct_ov01_021EB1E8 *a0);
WeatherManager *WeatherManager_New(FieldSystem *fieldSystem);
void WeatherManager_Delete(WeatherManager* weatherManager);
void WeatherManager_SetWeather(WeatherManager* weatherManager, int a1);
BOOL WeatherManager_ChangeWeather(WeatherManager* weatherManager, s32 weather);
u32 WeatherManager_GetWeather(WeatherManager *weatherManager);
UnkWeatherStruct_021EB64C* ov01_021EB64C(FieldSystem *fieldSystem);

// Static functions
void WeatherTask_ChangeWeather(SysTask* task, void *data);
void ov01_021EB3F0(SysTask* task, void *data);
BOOL ov01_021EB4B4(u32 weather, u32 nextWeather);
void WeatherDraw_Init(WeatherDraw* weatherDraw);
void ov01_021EB56C(SysTask *task, void *data);
void ov01_021EB578(GF_2DGfxResHeader *headerList, u32 a1, u32 a2);
void WeatherDraw_Delete(WeatherDraw* weatherDraw);
void ov01_021EB5F4(Sprite *sprite, VecFx32* matrix);

// Not yet decompiled
void ov01_021EB68C(WeatherManager *weatherManager);
u32 ov01_021EB700(UnkWeatherStruct_021EB64C *a0, u32 a1, u32 weather);
void ov01_021EB3F0(SysTask *task, void *data);
u32 ov01_021EB804(UnkWeatherStruct_021EB64C *a0, u32 weather);
void ov01_021EB56C(SysTask *task, void *data);
void ov01_021EB578(GF_2DGfxResHeader *header, u32 a1, u32 a2);

#endif // POKEHEARTGOLD_FIELD_WEATHER_MANAGER_H
