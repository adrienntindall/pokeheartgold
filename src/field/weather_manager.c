#include "field/weather_manager.h"
#include "heap.h"
#include "gf_gfx_planes.h"
#include "constants/weather.h"
#include "unk_02025C44.h"
#include "unk_0200B150.h"
#include "gf_gfx_loader.h"
#include "field_system.h"
#include "unk_02005D10.h"
#include "unk_0200ACF0.h"
#include "unk_02020B8C.h"

struct WeatherSystem_Sub0_Sub8 {
    WeatherSystem *weatherSystem;
    WeatherSystem_Sub0 *unk4;
    UnkWeatherStruct_021EB968 *unk8;
    WeatherSystem_Sub0_Sub8_LinkedList linkedListDummy;
    WeatherSystem_Sub0_Sub8_LinkedList linkedList[64];
    SysTask *unkF48;
    VecFx32 cameraTarget;
    void *unkF58;
    u32 unkF5C;
    u16 sndSeq;
    u16 unkF62;
    u16 unkF64;
    u16 unkF66;
    u32 unkF68;
    SysTask *unkF6C;
};

struct WeatherSystem_Sub0 {
    u16 unk0;
    u16 unk2;
    int unk4;
    WeatherSystem_Sub0_Sub8 *unk8;
    UnkWeatherStruct_021EB968 *unkC;
    u16 unk10;
    u16 unk12;
    SysTask *task;
    SysTaskFunc unk18;
};

struct WeatherSystem {
    WeatherSystem_Sub0 *unk0;
    WeatherSystem_Sub4 *unk4;
    WeatherDraw weatherDraw;
    FieldSystem *fieldSystem;
    NARC *narc;
};


void ov01_021EB1E8(UnkStruct_ov01_021EB1E8 *a0) {
    a0->unk188 = 1;
}

WeatherManager *WeatherManager_New(FieldSystem *fieldSystem) {
    WeatherManager *weatherManager = Heap_Alloc(HEAP_ID_FIELD1, sizeof(WeatherManager));

    memset(weatherManager, 0, sizeof(WeatherManager));
    
    weatherManager->unk0 = WeatherSystem_New(fieldSystem);
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
    
    ov01_021EB68C(&weatherManager->unk0);

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

extern WeatherSystem_Sub0 ov01_022098B0[];
extern WeatherSystem_Sub4 ov01_0220675C[];

WeatherSystem* WeatherSystem_New(FieldSystem *fieldSystem) {
    WeatherSystem *v0 = Heap_Alloc(HEAP_ID_FIELD1, sizeof(WeatherSystem));

    v0->fieldSystem = fieldSystem;
    
    WeatherDraw_Init(&v0->weatherDraw);

    v0->unk0 = ov01_022098B0;
    v0->unk4 = ov01_0220675C;
    
    v0->narc = NARC_New(NARC_a_0_6_3, HEAP_ID_FIELD1);

    return v0;
}

void ov01_021EB68C(WeatherSystem** pWeatherSystem) {
    if (*pWeatherSystem != NULL) {
        for (int i = 0; i < 14; i++) {
            ov01_021EBB90(*pWeatherSystem, i);
        }

        ov01_021EA864((*pWeatherSystem)->fieldSystem->unk_4C, 1, 0, 0, 0, 0);

        reg_G2_BG0CNT = (reg_G2_BG0CNT & ~3) | 1;

        GfGfx_EngineATogglePlanes(4, 0);

        WeatherDraw_Delete(&(*pWeatherSystem)->weatherDraw);

        NARC_Delete((*pWeatherSystem)->narc);
        Heap_FreeExplicit(HEAP_ID_FIELD1, *pWeatherSystem);

        *pWeatherSystem = NULL;
    }
}

BOOL ov01_021EB700(WeatherSystem *weatherSystem, int state, int weather) {
   BOOL ret = TRUE;
    
    if (weather > 14) {
        return FALSE;
    }

    switch (state) {
    case 0:
        ret = ov01_021EB9A8(weatherSystem, weather);
        break;
    case 1:
        ret = ov01_021EBA08(weatherSystem, weather);
        break;
    case 2:
        ret = ov01_021EBA44(weatherSystem, weather, 0, 1);
        break;
    case 3:
        ret = ov01_021EBA44(weatherSystem, weather, 2, 1);
        break;
    case 4:
        if (ov01_021EA854(weatherSystem->fieldSystem->unk_4C) == 1) {
            ret = ov01_021EBA44(weatherSystem, weather, 0, 2);
        } else {
            ret = ov01_021EBA44(weatherSystem, weather, 0, 1);
        }
        break;
    case 5:
        ov01_021EBB40(weatherSystem, weather, 1);
        break;
    case 6:
        ov01_021EBB68(weatherSystem, weather);
        break;
    case 7:
        ov01_021EBB40(weatherSystem, weather, 0);
        break;
    case 8:
        ov01_021EBB90(weatherSystem, weather);
        break;
    case 9:
        WeatherSystem_Sub0 *v1 = &weatherSystem->unk0[weather];
        if (v1->unk8 && v1->unk8->unkF5C == TRUE) {
            PlaySE(v1->unk8->sndSeq);
        }
        break;
    case 10:
        WeatherSystem_Sub0 *v2 = &weatherSystem->unk0[weather];
        if (v2->unk8 && v2->unk8->unkF5C == TRUE) {
            StopSE(v2->unk8->sndSeq, 0);
        }
        break;
    default:
        break;
    }
    
    return ret;
}

u16 ov01_021EB804(WeatherSystem* weatherSystem, int weather) {
    if (weather >= 14) {
        return 0;
    }
    WeatherSystem_Sub0 *v0 = &weatherSystem->unk0[weather];
    return v0->unk10;
}

void ov01_021EB818(u32 arg0, u32 arg1) {
    G2x_SetBlendAlpha_(0x04000050, 4, 0x21, arg0, arg1);
}

void ov01_021EB830(UnkWeatherStruct_021EB830* arg0, s32 arg1, s32 arg2, s32 arg3) {
    arg0->unk0 = arg1;
    arg0->unk4 = arg1;
    arg0->unk8 = arg2 - arg1;
    arg0->unk10 = arg3;
    arg0->unkC = 0;
}

BOOL ov01_021EB840(UnkWeatherStruct_021EB830* a0) {
    int v0 = a0->unk8 * a0->unkC;
    v0 /= a0->unk10;

    a0->unk0 = v0 + a0->unk4;

    if (a0->unkC + 1 <= a0->unk10) {
        a0->unkC++;
        return FALSE;
    }

    a0->unkC = a0->unk10;
    return TRUE;
}

void ov01_021EB86C(WeatherSystem *weatherSystem, s32 arg1, UnkWeatherStruct_021EB968 *arg2) {
    ov01_021EBEF0(weatherSystem, arg1, arg2);
    ov01_021EBF24(weatherSystem, arg1, arg2);
    ov01_021EBF58(weatherSystem, arg1, arg2);
    ov01_021EBF94(weatherSystem, arg1, arg2);
}

SpriteResource *ov01_021EB898(GF_2DGfxResHeader *headerList, s32 resourceType, s32 headerIndex, GF_2DGfxResMan *resMan, NARC *narc, BOOL atEnd) {
    GF_2DGfxResHeader *header = GF2DGfxResHeader_GetByIndex(headerList, resourceType);
    u32 member = GF2DGfxResHeader_GetNarcMemberIdByIndex(header, headerIndex);
    u32 compressFlag = GF2DGfxResHeader_GetCompressFlagByIndex(header, headerIndex);
    u32 exDat0 = GF2DGfxResHeader_GetExDat0ByIndex(header, headerIndex);
    u32 exDat1 = GF2DGfxResHeader_GetExDat1ByIndex(header, headerIndex);
    u32 objID = GF2dGfxResHeader_GetObjIdByIndex(header, headerIndex);

    SpriteResource *ret;
    switch (resourceType) {
    case GF_GFX_RES_TYPE_CHAR:
        ret = AddCharResObjFromOpenNarcWithAtEndFlag(resMan, narc, member, compressFlag, objID, exDat0, HEAP_ID_FIELD1, atEnd);
        break;
    case GF_GFX_RES_TYPE_PLTT:
        ret = AddPlttResObjFromOpenNarcWithAtEndFlag(resMan, narc, member, compressFlag, objID, exDat0, exDat1, HEAP_ID_FIELD1, atEnd);
        break;
    case GF_GFX_RES_TYPE_CELL:
        ret = AddCellOrAnimResObjFromOpenNarc(resMan, narc, member, compressFlag, objID, GF_GFX_RES_TYPE_CELL, HEAP_ID_FIELD1);
        break;
    case GF_GFX_RES_TYPE_ANIM:
        ret = AddCellOrAnimResObjFromOpenNarc(resMan, narc, member, compressFlag, objID, GF_GFX_RES_TYPE_ANIM, HEAP_ID_FIELD1);
        break;
    }

    return ret;
}

void ov01_021EB968(WeatherSystem* weatherSystem, s32 a1, UnkWeatherStruct_021EB968* a2) {
    if (a1 != 0xFFFF) {
        if (a2->charResObj[0] != 0) {
            sub_0200AEB0(a2->charResObj[0]);
        }
        if (a2->charResObj[1] != 0) {
            sub_0200B0A8(a2->charResObj[1]);
        }

        for (int i = 0; i < 4; i++) {
            if (a2->charResObj[i] != 0) {
                DestroySingle2DGfxResObj(weatherSystem->weatherDraw.resMan[i], a2->charResObj[i]);
            }
        }
    }
}

BOOL ov01_021EB9A8(WeatherSystem* weatherSystem, int weather) {
    WeatherSystem_Sub0 *v0 = &weatherSystem->unk0[weather];
    if (v0->unk8 == 0) {
        if (ov01_021EBE4C(weatherSystem, v0) == FALSE) {
            return FALSE;
        }

        if (ov01_021EBD34(weatherSystem, v0) == FALSE) {
            Heap_Free(v0->unk8);
            v0->unk8 = NULL;
            return FALSE;
        }

        v0->unk8->unk8 = v0->unkC;
        
        if (v0->unk0 != 0xFFFF) {
            ov01_021EC028(v0->unk8);
        }

        ov01_021EBD18(weatherSystem, v0->unk2);
        v0->unk10 = 2;
    }

    return TRUE;
}

BOOL ov01_021EBA08(WeatherSystem *weatherSystem, int weather) {
    WeatherSystem_Sub0 *v0 = &weatherSystem->unk0[weather];
    if (v0->unk8) {
        return TRUE;
    }

    if (ov01_021EBE4C(weatherSystem, v0) == 0) {
        return FALSE;
    }

    v0->task = SysTask_CreateOnMainQueue(ov01_021EBD70, v0, 1);
    v0->unk10 = 1;
    v0->unk12 = 0;

    return TRUE;
}

BOOL ov01_021EBA44(WeatherSystem *weatherSystem, int weather, u32 a2, u32 a3) {
    WeatherSystem_Sub0 *v0 = &weatherSystem->unk0[weather];

    if (v0->unk0 != 0xFFFF && v0->unkC == 0) {
        return FALSE;
    }

    if (v0->unk8 == NULL) {
        return FALSE;
    }

    if (v0->unk10 != 2) {
        return FALSE;
    }
    
    v0->unk8->unkF48 = SysTask_CreateOnMainQueue(v0->unk18, v0->unk8, 4);

    if (v0->unk8->unkF48 == NULL) {
        return FALSE;
    }

    v0->unk10 = 3;
    v0->unk8->unkF62 = a2;
    v0->unk8->unkF66 = 0;
    v0->unk8->linkedListDummy.next = &v0->unk8->linkedListDummy;
    v0->unk8->linkedListDummy.prev = &v0->unk8->linkedListDummy;
    v0->unk8->unkF64 = a3;
    v0->unk8->unkF5C = 0;
    
    v0->unk8->cameraTarget = NNS_G3dGlb.camTarget;
    
    if (v0->unk4 > 0) {
        v0->unk8->unkF58 = Heap_Alloc(HEAP_ID_FIELD1, v0->unk4);
        memset(v0->unk8->unkF58, 0, v0->unk4);
    } else {
        v0->unk8->unkF58 = NULL;
    }
    
    if (v0->unk2 != 0xFFFF) {
        GfGfx_EngineATogglePlanes(4, 0);
        G2_SetBG2Priority(1);
        G2_SetBG0Priority(2);
    }
    
    return TRUE;
}

void ov01_021EBB40(WeatherSystem *weatherSystem, int weather, u16 a2) {
    WeatherSystem_Sub0 *v0 = &weatherSystem->unk0[weather];
    if (v0->unk10 == 3) {
        v0->unk8->unkF66 = 5;
        v0->unk8->unkF64 = a2;
    }
}

void ov01_021EBB68(WeatherSystem *weatherSystem, int weather) {
    WeatherSystem_Sub0 *v0 = &weatherSystem->unk0[weather];
    if (ov01_021EB804(weatherSystem, weather) == 3) {
        v0->unk8->unkF62 = 5;
        v0->unk18(NULL, v0->unk8);
    }
}


void ov01_021EBB90(WeatherSystem *weatherSystem, u32 weather) {
    WeatherSystem_Sub0 *v0 = &weatherSystem->unk0[weather];

    if (v0->unk2 != 0xFFFF) {
        GfGfx_EngineATogglePlanes(4, 0);
        
        G2_SetBG2Priority(3);
		G2_SetBG0Priority(1);
        G2_BlendNone();
    }
    
    if (v0->unkC) {
        ov01_021EB968(weatherSystem, v0->unk0, v0->unkC);
        Heap_FreeExplicit(HEAP_ID_FIELD1, v0->unkC);
        v0->unkC = NULL;
        if (v0->task) {
            SysTask_Destroy(v0->task);
            v0->task = NULL;
        }
    }
    
    if (v0->unk8) {
        ov01_021EC2CC(&v0->unk8->linkedListDummy);

        if (v0->unk0 != 0xFFFF) {
            ov01_021EC058(v0->unk8);
        }

        if (v0->unk8->unkF5C == 1) {
            ov01_021EDAE0(v0->unk8);
        }

        if (v0->unk8->unkF58) {
            Heap_FreeExplicit(HEAP_ID_FIELD1, v0->unk8->unkF58);
            v0->unk8->unkF58 = NULL;
        }

        if (v0->unk10 == 1) {
            if (v0->task) {
                SysTask_Destroy(v0->task);
            }
        } else if (v0->unk10 == 3) {
            SysTask_Destroy(v0->unk8->unkF48);
        }

        if (v0->unk8->unkF6C) {
            SysTask_Destroy(v0->unk8->unkF6C);
        }

        Heap_FreeExplicit(HEAP_ID_FIELD1, v0->unk8);
        v0->unk8 = NULL;
    }

    ov01_021EA864(weatherSystem->fieldSystem->unk_4C, 1, 0, 0, 0, 0);
}

void ov01_021EBCA4(WeatherSystem_Sub0* a0) {
    if (a0->unk2 != 0xFFFF) {
        GfGfx_EngineATogglePlanes(4, 0);
        G2_SetBG2Priority(3);
		G2_SetBG0Priority(1);
		G2_BlendNone();
    }

    if (a0->unk8 != NULL) {
        ov01_021EC2CC(&a0->unk8->linkedListDummy);

        if (a0->unk8->unkF5C == 1) {
            ov01_021EDAE0(a0->unk8);
        }

        if (a0->unk10 == 3) {
            SysTask_Destroy(a0->unk8->unkF48);
            a0->unk10 = 2;
        }
    }
}

void ov01_021EBD18(WeatherSystem *weatherSystem, u16 a1) {
    ov01_021EC078(weatherSystem, a1);
    ov01_021EC0C0(weatherSystem, a1);
    ov01_021EC114(weatherSystem, a1);
}

BOOL ov01_021EBD34(WeatherSystem *weatherSystem, WeatherSystem_Sub0 *a1) {
    if (a1->unk0 != 0xFFFF && a1->unkC == NULL) {
        if (ov01_021EBEB8(a1) == FALSE) {
            return FALSE;
        }
        ov01_021EB86C(weatherSystem, a1->unk0, a1->unkC);
        ov01_021EBFD0(weatherSystem, a1);
    }
    return TRUE;
}

void ov01_021EBD70(SysTask *task, void *data) {
    WeatherSystem_Sub0 *v0 = data;
    WeatherSystem *weatherSystem = v0->unk8->weatherSystem;
    switch (v0->unk12) {
    case 0:
        GF_ASSERT(ov01_021EBEB8(v0));
        v0->unk12++;
        break;
    case 1:
        ov01_021EBEF0(weatherSystem, v0->unk0, v0->unkC);
        v0->unk12++;
        break;
    case 2:
        ov01_021EC078(weatherSystem, v0->unk2);
        v0->unk12++;
        break;
    case 3:
        ov01_021EBF24(weatherSystem, v0->unk0, v0->unkC);
        v0->unk12++;
        break;
    case 4:
        ov01_021EC0C0(weatherSystem, v0->unk2);
        v0->unk12++;
        break;
    case 5:
        ov01_021EBF58(weatherSystem, v0->unk0, v0->unkC);
        v0->unk12++;
        break;
    case 6:
        ov01_021EC114(weatherSystem, v0->unk2);
        v0->unk12++;
        break;
    case 7:
        ov01_021EBF94(weatherSystem, v0->unk0, v0->unkC);
        v0->unk12++;
        break;
    case 8:
        ov01_021EBFD0(weatherSystem, v0);
        v0->unk8->unk8 = v0->unkC;
        if (v0->unk0 != 0xFFFF) {
            ov01_021EC028(v0->unk8);
        }
        v0->unk10 = 2;
        v0->unk12 = 0;
        v0->task = 0;
        SysTask_Destroy(task);
    }
}

BOOL ov01_021EBE4C(WeatherSystem *weatherSystem, WeatherSystem_Sub0 *a1) {
    if (a1->unk8) {
        return TRUE;
    }

    a1->unk8 = Heap_Alloc(HEAP_ID_FIELD1, sizeof(WeatherSystem_Sub0_Sub8));
    if (a1->unk8 == NULL) {
        return FALSE;
    }
    memset(a1->unk8, 0, sizeof(WeatherSystem_Sub0_Sub8));

    a1->unk8->weatherSystem = weatherSystem;
    a1->unk8->unkF62 = 0;
    a1->unk8->unkF66 = 0;
    a1->unk8->linkedListDummy.next = &a1->unk8->linkedListDummy;
    a1->unk8->linkedListDummy.prev = &a1->unk8->linkedListDummy;
    a1->unk8->unkF58 = NULL;
    a1->unk8->unk4 = a1;
    a1->unk8->unkF6C = NULL;

    return TRUE;
}

BOOL ov01_021EBEB8(WeatherSystem_Sub0 *a0) {
    if (a0->unk0 != 0xFFFF) {
        if (a0->unkC != NULL) {
            return TRUE;
        }
        a0->unkC = Heap_Alloc(HEAP_ID_FIELD1, sizeof(UnkWeatherStruct_021EB968));
        if (a0->unkC == NULL) {
            return FALSE;
        }
        memset(a0->unkC, 0, sizeof(UnkWeatherStruct_021EB968));
    }
    return TRUE;
}

void ov01_021EBEF0(WeatherSystem *weatherSystem, u32 a1, UnkWeatherStruct_021EB968 *a2) {
    if (a1 != 0xFFFF) {
        a2->charResObj[2] = ov01_021EB898(weatherSystem->weatherDraw.header, 2, a1, weatherSystem->weatherDraw.resMan[2], weatherSystem->narc, 0);
    }
}

void ov01_021EBF24(WeatherSystem *weatherSystem, u32 a1, UnkWeatherStruct_021EB968 *a2) {
    if (a1 != 0xFFFF) {
        a2->charResObj[3] = ov01_021EB898(weatherSystem->weatherDraw.header, 3, a1, weatherSystem->weatherDraw.resMan[3], weatherSystem->narc, 0);
    }
}

void ov01_021EBF58(WeatherSystem *weatherSystem, u32 a1, UnkWeatherStruct_021EB968 *a2) {
    if (a1 != 0xFFFF) {
        a2->charResObj[0] = ov01_021EB898(weatherSystem->weatherDraw.header, 0, a1, weatherSystem->weatherDraw.resMan[0], weatherSystem->narc, 1);
        sub_0200ADA4(a2->charResObj[0]);
        sub_0200A740(a2->charResObj[0]);
    }
}

void ov01_021EBF94(WeatherSystem *weatherSystem, u32 a1, UnkWeatherStruct_021EB968 *a2) {
    if (a1 != 0xFFFF) {
        a2->charResObj[1] = ov01_021EB898(weatherSystem->weatherDraw.header, 1, a1, weatherSystem->weatherDraw.resMan[1], weatherSystem->narc, 1);
        sub_0200B00C(a2->charResObj[1]);
        sub_0200A740(a2->charResObj[1]);
    }
}

void ov01_021EBFD0(WeatherSystem *weatherSystem, WeatherSystem_Sub0 *a1) {
    if (a1->unk0 != 0xFFFF) {
        ov01_021EC240(&a1->unkC->unk40, weatherSystem, a1->unkC, 0, 1);
        memset(&a1->unkC->unk10, 0, sizeof(SpriteTemplate));
        a1->unkC->unk10.spriteList = weatherSystem->weatherDraw.spriteList;
        a1->unkC->unk10.header = &a1->unkC->unk40;
        a1->unkC->unk10.scale.x = 1 << 12;
        a1->unkC->unk10.scale.y = 1 << 12;
        a1->unkC->unk10.scale.z = 1 << 12;
        a1->unkC->unk10.whichScreen = NNS_G2D_VRAM_TYPE_2DMAIN;
    }
}

void ov01_021EC028(WeatherSystem_Sub0_Sub8 *a0) {
    for (int i = 0; i < 64; i++) {
        a0->linkedList[i].unk4 = Sprite_CreateAffine(&a0->unk8->unk10);
        Sprite_SetDrawFlag(a0->linkedList[i].unk4, 0);
        GF_ASSERT(a0->linkedList[i].unk4);
    }
}

void ov01_021EC058(WeatherSystem_Sub0_Sub8 *a0) {
    for (int i = 0; i < 64; i++) {
        if (a0->linkedList[i].unk4) {
            Sprite_Delete(a0->linkedList[i].unk4);
            a0->linkedList[i].unk4 = NULL;
        }
    }
}

void ov01_021EC078(WeatherSystem* weatherSystem, u16 a1) {
    UnkWeatherStruct_021EC078 v0;
    if (a1 != 0xFFFF) {
        v0.unk0 = NARC_AllocAndReadWholeMember(weatherSystem->narc, weatherSystem->unk4[a1].unk0, HEAP_ID_FIELD1);
        NNS_G2dGetUnpackedPaletteData(v0.unk0, &v0.unk14);
        BG_LoadPlttData(2, v0.unk14->pRawData, 32, 0xc0);
        Heap_Free(v0.unk0);
        v0.unk0 = NULL;
    }
}

void ov01_021EC0C0(WeatherSystem* weatherSystem, u16 a1) {
    UnkWeatherStruct_021EC078 v0;
    if (a1 != 0xFFFF) {
        v0.unk4 = NARC_AllocAndReadWholeMember(weatherSystem->narc, weatherSystem->unk4[a1].unk4, HEAP_ID_FIELD1);
        NNS_G2dGetUnpackedCharacterData(v0.unk4, &v0.unk10);
        BG_LoadCharTilesData(weatherSystem->fieldSystem->bgConfig, 2, v0.unk10->pRawData, v0.unk10->szByte, 0);
        Heap_Free(v0.unk4);
        v0.unk4 = NULL;
    }
}

void ov01_021EC114(WeatherSystem* weatherSystem, u16 a1) {
    UnkWeatherStruct_021EC078 v0;
    if (a1 != 0xFFFF) {
        GfGfx_EngineATogglePlanes(4, 0);
        v0.unk8 = NARC_AllocAndReadWholeMember(weatherSystem->narc, weatherSystem->unk4[a1].unk8, HEAP_ID_FIELD1);
        GF_ASSERT(v0.unk8);
        NNS_G2dGetUnpackedScreenData(v0.unk8, &v0.unkC);
        BgCopyOrUncompressTilemapBufferRangeToVram(weatherSystem->fieldSystem->bgConfig, 2, v0.unkC->rawData, v0.unkC->szByte, 0);
        BG_LoadScreenTilemapData(weatherSystem->fieldSystem->bgConfig, 2, v0.unkC->rawData, v0.unkC->szByte);
        BgTilemapRectChangePalette(weatherSystem->fieldSystem->bgConfig, 2, 0, 0, 32, 32, 6);
        BgCommitTilemapBufferToVram(weatherSystem->fieldSystem->bgConfig, 2);
        Heap_Free(v0.unk8);
        v0.unk8 = NULL;
    }
}

void ov01_021EC1BC(WeatherSystem_Sub0_Sub8_LinkedList* a0, int a1) {
    GF_ASSERT(a0->unk8 == 0);
    GF_ASSERT(a1 > 0);
    GF_ASSERT(a1 <= 0x28u);
    a0->unk8 = a0->unk10;
}

void ov01_021EC1E4(WeatherSystem_Sub0_Sub8_LinkedList* a0) {
    a0->unk8 = NULL;
    memset(a0->unk10, 0, 10 * sizeof(u32));
}

void* ov01_021EC1F4(WeatherSystem_Sub0_Sub8* a0, int a1) {
    WeatherSystem *weatherSystem = a0->weatherSystem;
    WeatherSystem_Sub0_Sub8_LinkedList *v0 = ov01_021EC8D8(a0);
    if (v0 == NULL) {
        return NULL;
    }
    v0->weatherSystem = weatherSystem;
    v0->next = &a0->linkedListDummy;
    v0->prev = a0->linkedListDummy.prev;
    a0->linkedListDummy.prev->next = v0;
    a0->linkedListDummy.prev = v0;

    ov01_021EC1BC(v0, a1);
    if (v0->unk8 == NULL) {
        return NULL;
    }

    GF_ASSERT(v0->unk4);
    Sprite_SetDrawFlag(v0->unk4, 1);
    return v0;
}

void ov01_021EC240(SpriteResourcesHeader *header, WeatherSystem *weatherSystem, UnkWeatherStruct_021EB968 *a2, u32 a3, u32 a4) {
    int resID[4];

    for (int i = 0; i < 4; i++) {
        resID[i] = GF2DGfxResObj_GetResID(a2->charResObj[i]);
    }

    CreateSpriteResourcesHeader(header, resID[0], resID[1], resID[2], resID[3], -1, -1, a3, a4, weatherSystem->weatherDraw.resMan[0], weatherSystem->weatherDraw.resMan[1], weatherSystem->weatherDraw.resMan[2], weatherSystem->weatherDraw.resMan[3], NULL, NULL);
}

void ov01_021EC29C(WeatherSystem_Sub0_Sub8_LinkedList* a0) {
    a0->prev->next = a0->next;
    a0->next->prev = a0->prev;
    
    Sprite_SetDrawFlag(a0->unk4, 0);
    ov01_021EC1E4(a0);

    Sprite *temp = a0->unk4;
    memset(a0, 0, sizeof(WeatherSystem_Sub0_Sub8_LinkedList));
    a0->unk4 = temp;
}

void ov01_021EC2CC(WeatherSystem_Sub0_Sub8_LinkedList * a0) {
    WeatherSystem_Sub0_Sub8_LinkedList *cur = a0->next;
    WeatherSystem_Sub0_Sub8_LinkedList *next;

    while (cur != a0) {
        next = cur->next;
        ov01_021EC29C(cur);
        cur = next;
    }
}

void ov01_021EC2E4(WeatherSystem_Sub0_Sub8_LinkedList *a0, UnkLinkedListFunc func) {
    WeatherSystem_Sub0_Sub8_LinkedList *cur = a0->next;
    WeatherSystem_Sub0_Sub8_LinkedList *next = cur->next;

    while (cur != a0) {
        func(cur);
        cur = next;
        next = cur->next;
    }
}

void ov01_021EC300(void *data) {
    
}

VecFx32 ov01_021EC304(WeatherSystem_Sub0_Sub8_LinkedList *a0) {
    return *Sprite_GetMatrixPtr(a0->unk4);
}

void ov01_021EC31C(fx32* x, fx32* z, WeatherSystem_Sub0_Sub8* a0) {
    VecFx32 cameraTarget = NNS_G3dGlb.camTarget;
    fx32 xScale, zScale;
    fx32 dx, dz;
    fx32 xDist, zDist;
    int v7;
    fx32 aspect;

    xDist = (cameraTarget.x - a0->cameraTarget.x);
    zDist = (cameraTarget.z - a0->cameraTarget.z);

    aspect = FX_Div(FX32_CONST(4), FX32_CONST(3));
    
    sub_02020E10(Camera_GetPerspectiveAngle(a0->weatherSystem->fieldSystem->camera), Camera_GetDistance(a0->weatherSystem->fieldSystem->camera), aspect, &dx, &dz);

    dx = FX_Div(dx, 256*FX32_ONE);

    if (zDist <= 0) {
        dz = FX_Div(dz, 0xbe8d0);
    } else {
        dz = FX_Div(dz, 0xbe811);
    }
    
    v7 = FX32_ONE;
    if (xDist < 0) {
        v7 = -FX32_ONE;
        xDist = FX_MUL(xDist, -FX32_ONE);
    }
    xScale = FX_Div(xDist, dx);
    if (v7 < 0) {
        xScale = FX_MUL(xScale, v7);
    }

    v7 = FX32_ONE;
    if (zDist < 0) {
        v7 = -FX32_ONE;
        zDist = FX_MUL(zDist, -FX32_ONE);
    }
    zScale = FX_Div(zDist, dz);
    if (v7 < 0) {
        zScale = FX_MUL(zScale, v7);
    }

    if (xScale + zScale != 0) {
        a0->cameraTarget = cameraTarget;
    }

    *x = xScale;
    *z = zScale;
}

void ov01_021EC470(WeatherSystem_Sub0_Sub8 *a0, int *xOut, int *zOut) {
    fx32 x, z;
    ov01_021EC4A8(a0, &x, &z);

    if (xOut) {
        *xOut = x >> FX32_SHIFT;
        if (*xOut < 0) {
            *xOut += FX32_ONE;
        }
    }
    if (zOut) {
        *zOut = z >> FX32_SHIFT;
        if (*zOut < 0) {
            *zOut += 1;
        }
    }
}

void ov01_021EC4A8(WeatherSystem_Sub0_Sub8 *a0, fx32 *x, fx32 *y) {
    WeatherSystem_Sub0_Sub8_LinkedList *cur;
    fx32 xScale, yScale;
    VecFx32 matrix;
    ov01_021EC31C(&xScale, &yScale, a0);

    cur = a0->linkedListDummy.next;
    while (cur != &a0->linkedListDummy) {
        matrix = ov01_021EC304(cur);

        matrix.x -= xScale;
        matrix.y -= yScale;

        ov01_021EB5F4(cur->unk4, &matrix);

        cur = cur->next;
    }

    if (x != NULL) {
        *x = xScale;
    }
    if (y != NULL) {
        *y = yScale;
    }
}

void ov01_021EC504(UnkStruct_021EC504* arg0, s32 arg1, s16 arg2, s16 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8, UnkFunc_021EC504 arg9) {
    arg0->unk0 = arg1;
    arg0->unk4 = arg2;
    arg0->unk6 = 0;
    arg0->unk8 = arg3;
    arg0->unkA = 0;
    arg0->unkC = (s16) arg4;
    arg0->unkE = (s16) arg5;
    arg0->unk10 = (s16) arg6;
    arg0->unk12 = (s16) arg7;
    arg0->unk14 = arg8;
    arg0->unk18 = arg9;
}

void ov01_021EC52C(UnkStruct_021EC504* arg0, s16 arg1, s16 arg2, s16 arg3, s32 arg4) {
    arg0->unkC = arg1;
    arg0->unkE = arg2;
    arg0->unk10 = arg3;
    arg0->unk14 = arg4;
}

s32 ov01_021EC538(UnkStruct_021EC504* arg0) {
    s16 temp_r0;
    s16 temp_r0_2;
    s16 temp_r0_4;
    s16 temp_r1;
    s16 temp_r1_2;
    s32 temp_r0_3;
    s32 var_r2;
    s32 var_r2_2;
    s32 var_r4;

    temp_r0 = arg0->unk10;
    var_r4 = 0;
    if (temp_r0 == 0) {
        var_r4 |= 1;
    } else {
        if ((s32) temp_r0 <= 0) {
            var_r2 = 1;
        } else {
            var_r2 = 0;
        }
        temp_r1 = arg0->unkE;
        temp_r0_2 = arg0->unk8;
        if ((((s32) temp_r0_2 >= (s32) temp_r1) && (var_r2 == 0)) || (((s32) temp_r0_2 <= (s32) temp_r1) && (var_r2 == 1))) {
            var_r4 |= 1;
            arg0->unk8 = temp_r1;
        }
    }
    temp_r0_3 = arg0->unk14;
    if (temp_r0_3 == 0) {
        var_r4 |= 2;
    } else {
        if (temp_r0_3 <= 0) {
            var_r2_2 = 1;
        } else {
            var_r2_2 = 0;
        }
        temp_r1_2 = arg0->unkC;
        temp_r0_4 = arg0->unk4;
        if ((((s32) temp_r0_4 >= (s32) temp_r1_2) && (var_r2_2 == 0)) || (((s32) temp_r0_4 <= (s32) temp_r1_2) && (var_r2_2 == 1))) {
            var_r4 |= 2;
            arg0->unk4 = temp_r1_2;
        }
    }
    arg0->unk6 = (s16) (arg0->unk6 - 1);
    if ((s32) arg0->unk6 <= 0) {
        arg0->unk18(arg0->unk0, arg0->unk4);
        arg0->unk6 = (s16) arg0->unk8;
        if (!(1 & var_r4)) {
            arg0->unk8 = (s16) (arg0->unk8 + arg0->unk10);
        }
        if (!(2 & var_r4)) {
            arg0->unkA = (s16) (arg0->unkA + 1);
            if ((s32) arg0->unkA >= (s32) arg0->unk12) {
                arg0->unkA = 0;
                arg0->unk4 = (s16) (arg0->unk4 + arg0->unk14);
            }
        }
    }
    return var_r4;
}

void ov01_021EC5FC(UnkStruct_021EC5FC *arg0, UnkStruct_021EC774* arg1, s32 arg2, s32 arg3, s32 arg4, GXRgb rgb, s32 arg6, s32 arg7) {
    arg1->unk0 = arg2;
    if (arg7 != 0) {
        if (arg7 == 1) {
            ov01_021EC678(arg2, arg3, arg4, rgb);
            ov01_021EC774(arg1);
            ov01_021EC790(arg1, arg6, 1);
        } else if (arg7 == 2) {
            ov01_021EC6A4(arg0, arg2, arg3, arg4, rgb, 0x7F * arg6);
        }
    }
}

BOOL ov01_021EC650(UnkStruct_021EC5FC *arg0, UnkStruct_021EC774 *arg1, s32 arg2) {
    s32 var_r4;

    var_r4 = 1;
    if (arg2 != 0) {
        if (arg2 == 1) {
            var_r4 = ov01_021EC7AC(arg1);
        } else if (arg2 == 2) {
            if (ov01_021EC728(arg0) == 0) {
                var_r4 = 0;
            }
        }
    }
    return var_r4;
}

void ov01_021EC678(s32 arg0, s32 arg1, s32 arg2, GXRgb rgb) {
    ov01_021EA864(arg0, -1, 1, 0, arg1, arg2);
    ov01_021EA89C(arg0, -1, rgb, 0x1F);
}

void ov01_021EC6A4(UnkStruct_021EC5FC* arg0, s32 a1, s32 arg2, s32 arg3, GXRgb rgb, s32 arg5) {
    int v0 = ov01_021EA858(a1);
    int v1 = ov01_021EA85C(a1);
    GXRgb v2 = ov01_021EA860(a1);

    arg0->unk0 = a1;

    ov01_021EB830(&arg0->unk4, v1, arg3, arg5);
    ov01_021EB830(&arg0->unk18, v2 & GX_RGB_R_MASK, rgb & GX_RGB_R_MASK, arg5);
    ov01_021EB830(&arg0->unk2C, (v2 >> GX_RGB_G_SHIFT) & 0x1F, (rgb >> GX_RGB_G_SHIFT) & 0x1F, arg5);
    ov01_021EB830(&arg0->unk40, (v2 >> GX_RGB_B_SHIFT) & 0x1F, (rgb >> GX_RGB_B_SHIFT) & 0x1F, arg5);
    ov01_021EB830(&arg0->unk54, v0, arg2, arg5);
}

BOOL ov01_021EC728(UnkStruct_021EC5FC *arg0) {
    BOOL ret = ov01_021EB840(&arg0->unk4);
    ov01_021EB840(&arg0->unk18);
    ov01_021EB840(&arg0->unk2C);
    ov01_021EB840(&arg0->unk40);
    ov01_021EB840(&arg0->unk54);
    ov01_021EC678(arg0->unk0, arg0->unk54.unk0, arg0->unk4.unk0, GX_RGB(arg0->unk18.unk0, arg0->unk2C.unk0, arg0->unk40.unk0));

    return ret;
}

void ov01_021EC774(UnkStruct_021EC774* a0) {
    for (int i = 0; i < 32; i++) {
        a0->unk4[i] = 0;
    }
    ov01_021EA8C4(a0->unk0, a0->unk4);
}

void ov01_021EC790(UnkStruct_021EC774* arg0, s32 arg1, s32 arg2) {
    arg0->unk24 = 0x7F;
    arg0->unk28 = 0;
    arg0->unk2C = arg1;
    if (arg2 == 1) {
        arg0->unk2E = 1;
        return;
    }
    arg0->unk2E = -1;
}

s32 ov01_021EC7AC(UnkStruct_021EC774* arg0) {
    s32 temp_r4;

    temp_r4 = ov01_021EC7E8(arg0);
    if (arg0->unk28 == 0) {
        ov01_021EA8C4(arg0->unk0, arg0->unk4);
    }
    return temp_r4;
}

void ov01_021EC7C8(UnkStruct_021EC774* arg0) {
    arg0->unk24 = 1;
    arg0->unk28 = 0;
    arg0->unk2C = 0;
    arg0->unk2E = 1;
    ov01_021EC828(arg0);
    ov01_021EA8C4(arg0->unk0, arg0->unk4);
}

s32 ov01_021EC7E8(UnkStruct_021EC774* arg0) {
    s32 temp_r0;
    s32 temp_r2;
    s32 var_r4;

    var_r4 = 0;
    if (arg0->unk2E == 0) {
        var_r4 = 1;
    } else if ((s32) arg0->unk24 <= 0) {
        var_r4 = 1;
    } else {
        temp_r2 = arg0->unk28 + 1;
        arg0->unk28 = temp_r2;
        if (temp_r2 >= (s32) arg0->unk2C) {
            arg0->unk28 = 0;
            ov01_021EC828(arg0);
            temp_r0 = arg0->unk24 - 1;
            arg0->unk24 = temp_r0;
            if (temp_r0 <= 0) {
                var_r4 = 1;
            }
        }
    }
    return var_r4;
}

void ov01_021EC828(UnkStruct_021EC774 *arg0) {
    int i;
    int v0;
    int v1;
    
    if (arg0->unk2E < 0) {
        v1 = 0x7F - arg0->unk24;
    } else {
        v1 = arg0->unk24;
    }

    v0 = v1/4;
    for (i = 31; i > v0; i--) {
        arg0->unk4[i] = (i - v0)*4;
    }
}

void ov01_021EC85C(WeatherSystem_Sub0_Sub8 *a0, UnkWeatherSystemSub0Sub8Func a1, int a2, int a3, int a4, UnkLinkedListFunc a5) {
    a1(a0, a2);
    
    int i, j;
    int v0 = 0;
    WeatherSystem_Sub0_Sub8_LinkedList *cur = a0->linkedListDummy.next;
    WeatherSystem_Sub0_Sub8_LinkedList *next = cur->next;

    for (i = 0; i < a2; i++) {
        if (cur == &a0->linkedListDummy) {
            break;
        }

        for (j = 0; j < v0; j++) {
            a5(cur);

            if (cur->unk8 == NULL) {
                break;
            }
        }

        cur = next;
        next = cur->next;

        if (i >= a3 && (i % a3) == 0) {
            v0 += a4;
        }
    }
}

WeatherSystem_Sub0_Sub8_LinkedList *ov01_021EC8D8(WeatherSystem_Sub0_Sub8 * a0) {
    for (int i = 0; i < 64; i++) {
        if (a0->linkedList[i].weatherSystem == NULL) {
            return &a0->linkedList[i];
        }
    }
    return NULL;
}

void ov01_021EC8F8(SysTask *task, void* data) {
    WeatherSystem_Sub0_Sub8 *arg1 = data;
    u16 temp_r2 = arg1->unkF62;
    switch (temp_r2) {
    case 0:
        arg1->unkF62 = 1;
        break;
    case 1:
        arg1->unkF62 = 3;
        break;
    case 2:
        arg1->unkF62 = 3;
        break;
    case 3:
        if (arg1->unkF66 == 5) {
            arg1->unkF62 = 4;
        }
        break;
    case 4:
        arg1->unkF62 = 5;
        break;
    case 5:
        ov01_021EBCA4(arg1->unk4);
        break;
    }
}
