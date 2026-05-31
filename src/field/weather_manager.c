#include "field/weather_manager.h"
#include "heap.h"
#include "gf_gfx_planes.h"
#include "constants/weather.h"

void ov01_021EB1E8(UnkStruct_ov01_021EB1E8 *a0) {
    a0->unk188 = 1;
}

WeatherManager *WeatherManager_New(u32 a0) {
    WeatherManager *weatherManager = Heap_Alloc(HEAP_ID_FIELD1, sizeof(WeatherManager));

    memset(weatherManager, 0, sizeof(WeatherManager));
    
    weatherManager->unk0 = ov01_021EB64C(a0);
    weatherManager->weather = WEATHER_SUNNY;
    weatherManager->nextWeather = WEATHER_SUNNY;
    weatherManager->unkC = 6;
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
    GF_ASSERT(weatherManager->unkC == 6);
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

    if(weatherManager->unkC != 6) {
        weatherManager->unk10 = weather;
        return TRUE;
    }

    if (weatherManager->weather == weather) {
        return TRUE;
    }

    GF_ASSERT(weatherManager->task == NULL);

    weatherManager->nextWeather = weather;
    if (ov01_021EB4B4(weatherManager->weather, weatherManager->nextWeather) == 0) {
        weatherManager->unkC = 0;
        weatherManager->task = SysTask_CreateOnMainQueue(ov01_021EB320, weatherManager, 0);
    } else {
        weatherManager->unkC = 0;
        weatherManager->task = SysTask_CreateOnMainQueue(ov01_021EB3F0, weatherManager, 0);
    }

    return TRUE;
}
