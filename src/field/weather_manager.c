#include "field/weather_manager.h"
#include "heap.h"
#include "gf_gfx_planes.h"
#include "constants/weather.h"
#include "unk_02025C44.h"
#include "unk_0200B150.h"
#include "gf_gfx_loader.h"

void ov01_021EB1E8(UnkStruct_ov01_021EB1E8 *a0) {
    a0->unk188 = 1;
}

WeatherManager *WeatherManager_New(FieldSystem *fieldSystem) {
    WeatherManager *weatherManager = Heap_Alloc(HEAP_ID_FIELD1, sizeof(WeatherManager));

    memset(weatherManager, 0, sizeof(WeatherManager));
    
    weatherManager->unk0 = ov01_021EB64C(fieldSystem);
    weatherManager->weather = WEATHER_SUNNY;
    weatherManager->nextWeather = WEATHER_SUNNY;
    weatherManager->state = 6;
    weatherManager->task = NULL;
    weatherManager->unk10 = WEATHER_MAX;
    
    GfGfx_EngineATogglePlanes(GX_PLANEMASK_OBJ, GF_PLANE_TOGGLE_ON);
    
    return weatherManager;
}

void WeatherManager_Delete(WeatherManager* weatherManager) {
    if (weatherManager->task) {
        SysTask_Destroy(weatherManager->task);
    }
    
    ov01_021EB68C(weatherManager);

    memset(weatherManager, 0, sizeof(WeatherManager));
    
    Heap_Free(weatherManager);
}

void WeatherManager_SetWeather(WeatherManager* weatherManager, int weather) {
    GF_ASSERT(weatherManager->state == 6);
    GF_ASSERT(weather < WEATHER_MAX);

    if (weatherManager->weather != weather) {
        GF_ASSERT(ov01_021EB700(weatherManager->unk0, 8, weatherManager->weather));
        GF_ASSERT(ov01_021EB700(weatherManager->unk0, 0, weather));
        GF_ASSERT(ov01_021EB700(weatherManager->unk0, 3, weather));
        weatherManager->weather = weather;
    }
}

BOOL WeatherManager_ChangeWeather(WeatherManager* weatherManager, s32 weather) {
    GF_ASSERT(weather < WEATHER_MAX);

    if(weatherManager->state != 6) {
        weatherManager->unk10 = weather;
        return TRUE;
    }

    if (weatherManager->weather == weather) {
        return TRUE;
    }

    GF_ASSERT(weatherManager->task == NULL);

    weatherManager->nextWeather = weather;
    if (ov01_021EB4B4(weatherManager->weather, weatherManager->nextWeather) == 0) {
        weatherManager->state = 0;
        weatherManager->task = SysTask_CreateOnMainQueue(WeatherTask_ChangeWeather, weatherManager, 0);
    } else {
        weatherManager->state = 0;
        weatherManager->task = SysTask_CreateOnMainQueue(ov01_021EB3F0, weatherManager, 0);
    }

    return TRUE;
}

u32 WeatherManager_GetWeather(WeatherManager *weatherManager) {
    return weatherManager->weather;
}

void WeatherTask_ChangeWeather(SysTask* task, void *data) {
    WeatherManager *weatherManager = data;
    switch (weatherManager->state) {
    case 0:
        GF_ASSERT(ov01_021EB700(weatherManager->unk0, 5, weatherManager->weather));
        weatherManager->state++;
        break;
    case 1:
        if (ov01_021EB804(weatherManager->unk0, weatherManager->weather) != 3) {
            GF_ASSERT(ov01_021EB700(weatherManager->unk0, 8, weatherManager->weather));
            weatherManager->state++;
        }
        break;
    case 2:
        GF_ASSERT(ov01_021EB700(weatherManager->unk0, 1, weatherManager->nextWeather));
        weatherManager->state++;
        break;
    case 3:
        if (ov01_021EB804(weatherManager->unk0, weatherManager->nextWeather) != 1) {
            weatherManager->state++;
        }
        break;
    case 4:
        GF_ASSERT(ov01_021EB700(weatherManager->unk0, 2, weatherManager->nextWeather));
        weatherManager->state++;
        weatherManager->weather = weatherManager->nextWeather;
        weatherManager->nextWeather = 0;
        break;
    case 5:
        weatherManager->state = 6;
        weatherManager->task = NULL;
        SysTask_Destroy(task);
        if (weatherManager->unk10 != 14) {
            WeatherManager_ChangeWeather(weatherManager, weatherManager->unk10);
            weatherManager->unk10 = 14;
        }
        break;
    }
}

void ov01_021EB3F0(SysTask* task, void *data) {
    WeatherManager *weatherManager = data;
    switch (weatherManager->state) {
    case 0:
        GF_ASSERT(ov01_021EB700(weatherManager->unk0, 1, weatherManager->nextWeather));
        weatherManager->state++;
        break;
    case 1:
        if (ov01_021EB804(weatherManager->unk0, weatherManager->nextWeather) != 1) {
            weatherManager->state++;
        }
        break;
    case 2:
        GF_ASSERT(ov01_021EB700(weatherManager->unk0, 7, weatherManager->weather));
        GF_ASSERT(ov01_021EB700(weatherManager->unk0, 4, weatherManager->nextWeather));
        weatherManager->state++;
        break;
    case 3:
        if (ov01_021EB804(weatherManager->unk0, weatherManager->weather) != 3) {
            GF_ASSERT(ov01_021EB700(weatherManager->unk0, 8, weatherManager->weather));
            weatherManager->state++;
        }
        break;
    case 4:
        weatherManager->weather = weatherManager->nextWeather;
        weatherManager->nextWeather = 0;
        weatherManager->state = 6;
        weatherManager->task = NULL;
        SysTask_Destroy(task);
        if (weatherManager->unk10 != 14) {
            WeatherManager_ChangeWeather(weatherManager, weatherManager->unk10);
            weatherManager->unk10 = 14;
        }
        break;
    }
}

BOOL ov01_021EB4B4(u32 weather, u32 nextWeather) {
    return FALSE;
}

void WeatherDraw_Init(WeatherDraw* weatherDraw) {
    GF_InitG2dRenderer(&weatherDraw->instance, 0xFFFFF000);
    
    NNSG2dViewRect rect;
    rect.posTopLeft.x = 0;
    rect.posTopLeft.y = 0;
    rect.sizeView.x = 0xFF000;
    rect.sizeView.y = 0xC0000;
    
    sub_0200B27C(&weatherDraw->surface, &rect, NNS_G2D_VRAM_TYPE_2DMAIN, &weatherDraw->instance);

    for (int i = 0; i < 4; i++) {
        weatherDraw->resMan[i] = Create2DGfxResObjMan(14, (GfGfxResType) i, HEAP_ID_FIELD1);
    }

    weatherDraw->header = Heap_Alloc(HEAP_ID_FIELD1, 4 * GF2DGfxResHeader_sizeof());

    ov01_021EB578(weatherDraw->header, 0, 0x39);
    ov01_021EB578(weatherDraw->header, 1, 0x3A);
    ov01_021EB578(weatherDraw->header, 2, 0x37);
    ov01_021EB578(weatherDraw->header, 3, 0x38);

    SpriteListParam param;
    param.num = 0x40;
    param.rendererInstance = &weatherDraw->instance;
    param.heapID = HEAP_ID_FIELD1;
    
    weatherDraw->spriteList = SpriteList_Create(&param);

    weatherDraw->task = SysTask_CreateOnMainQueue(ov01_021EB56C, weatherDraw, 10);
}

void ov01_021EB56C(SysTask *task, void *data) {
    WeatherDraw *weatherDraw = data;
    SpriteList_RenderAndAnimateSprites(weatherDraw->spriteList);
}

void ov01_021EB578(GF_2DGfxResHeader *headerList, u32 a1, u32 a2) {
    GF_2DGfxResHeader *header = GF2DGfxResHeader_GetByIndex(headerList, a1);
    GF_2DGfxResHeaderNarcList *headerNarcList = GfGfxLoader_LoadFromNarc(NARC_a_0_6_3, a2, 0, HEAP_ID_FIELD1, 1);
    GF2DGfxResHeader_Init(headerNarcList, header, HEAP_ID_FIELD1);
    Heap_Free(headerNarcList);
}

void WeatherDraw_Delete(WeatherDraw* weatherDraw) {
    for (int i = 0; i < 4; i++) {
        GF2DGfxResHeader_Reset(GF2DGfxResHeader_GetByIndex(weatherDraw->header, i));
        Destroy2DGfxResObjMan(weatherDraw->resMan[i]);
    }
    
    Heap_Free(weatherDraw->header);
    weatherDraw->header = NULL;
    
    SpriteList_Delete(weatherDraw->spriteList);
    weatherDraw->spriteList = NULL;
    
    SysTask_Destroy(weatherDraw->task);
    weatherDraw->task = NULL;
}

void ov01_021EB5F4(Sprite *sprite, VecFx32* matrix) {
    if (matrix->x > 0x13F000) {
        matrix->x %= 0x13F000;
    } else if (matrix->x < (int)0xFFFC0000) {
        matrix->x += 0x13F000;
    }

    if (matrix->y > 0x100000) {
        matrix->y %= 0x100000;
    } else if (matrix->y < (int)0xFFFC0000) {
        matrix->y += 0x100000;
    }
    
    Sprite_SetMatrix(sprite, matrix);
}

extern u32 ov01_022098B0[];
extern u32 ov01_0220675C[];

UnkWeatherStruct_021EB64C* ov01_021EB64C(FieldSystem *fieldSystem) {
    UnkWeatherStruct_021EB64C *v0 = Heap_Alloc(HEAP_ID_FIELD1, sizeof(UnkWeatherStruct_021EB64C));

    v0->fieldSystem = fieldSystem;
    
    WeatherDraw_Init(&v0->weatherDraw);

    v0->unk0 = ov01_022098B0;
    v0->unk4 = ov01_0220675C;
    
    v0->narc = NARC_New(NARC_a_0_6_3, HEAP_ID_FIELD1);

    return v0;
}
