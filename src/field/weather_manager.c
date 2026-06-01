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

struct WeatherSystem_Sub0_Sub8_LinkedList {
    u32 unk0;
    u32 unk4;
    u32 unk8;
    u32 unk10[10];
    WeatherSystem_Sub0_Sub8_LinkedList *next;
    WeatherSystem_Sub0_Sub8_LinkedList *prev;
};

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
    u32 *unk4;
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
extern u32 ov01_0220675C[];

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
