#ifndef POKEHEARTGOLD_OVERLAY_01_021EB1E8_H
#define POKEHEARTGOLD_OVERLAY_01_021EB1E8_H

#include "global.h"
#include "task.h"

typedef struct UnkStruct_ov01_021EB1E8 {
    u8 unk0[0x188];
    u32 unk188;
} UnkStruct_ov01_021EB1E8;

typedef struct WeatherManager {
    u32 unk0;
    u32 unk4;
    u32 unk8;
    u32 unkC;
    u32 unk10;
    SysTask *task;
} WeatherManager;

void ov01_021EB1E8(UnkStruct_ov01_021EB1E8 *a0);
WeatherManager *ov01_021EB1F4(u32 a0);
void ov01_021EB234(WeatherManager* weatherManager);

// Not yet decompiled
u32 ov01_021EB64C(u32 a0);
void ov01_021EB68C(WeatherManager *weatherManager);
#endif // POKEHEARTGOLD_OVERLAY_01_021EB1E8_H
