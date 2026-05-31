#include "overlay_01_021EB1E8.h"
#include "heap.h"
#include "gf_gfx_planes.h"
#include "constants/weather.h"

void ov01_021EB1E8(UnkStruct_ov01_021EB1E8 *a0) {
    a0->unk188 = 1;
}

WeatherManager *ov01_021EB1F4(u32 a0) {
    WeatherManager *weatherManager = Heap_Alloc(HEAP_ID_FIELD1, sizeof(WeatherManager));

    memset(weatherManager, 0, sizeof(WeatherManager));
    
    weatherManager->unk0 = ov01_021EB64C(a0);
    weatherManager->unk4 = WEATHER_SUNNY;
    weatherManager->unk8 = WEATHER_SUNNY;
    weatherManager->unkC = 6;
    weatherManager->task = NULL;
    weatherManager->unk10 = 14;
    
    GfGfx_EngineATogglePlanes(GX_PLANEMASK_OBJ, GF_PLANE_TOGGLE_ON);
    
    return weatherManager;
}

void ov01_021EB234(WeatherManager* weatherManager) {
    if (weatherManager->task) {
        SysTask_Destroy(weatherManager->task);
    }
    
    ov01_021EB68C(weatherManager);

    memset(weatherManager, 0, sizeof(WeatherManager));
    
    Heap_Free(weatherManager);
}
