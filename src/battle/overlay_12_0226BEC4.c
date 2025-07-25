#include "battle/overlay_12_0226BEC4.h"

#include "global.h"

#include "battle/battle_input.h"
#include "battle/battle_system.h"
#include "battle/overlay_12_02266024.h"

#include "heap.h"
#include "sys_task.h"
#include "unk_02005D10.h"

static void ov12_0226BF04(SysTask *task, void *data);

SysTask *ov12_0226BEC4(BattleSystem *battleSystem) {
    UnkBattleStruct_0226BEC4 *unk;
    unk = AllocFromHeap(HEAP_ID_BATTLE, sizeof(UnkBattleStruct_0226BEC4));
    MI_CpuFill8(unk, 0, sizeof(UnkBattleStruct_0226BEC4));
    unk->battleSystem = battleSystem;
    return SysTask_CreateOnMainQueue(ov12_0226BF04, unk, 1000);
}

void ov12_0226BEF0(SysTask *task) {
    Heap_Free(SysTask_GetData(task));
    SysTask_Destroy(task);
}

static void ov12_0226BF04(SysTask *task, void *_data) {
    UnkBattleStruct_0226BEC4 *data = _data;
    BattleInput *battleInput = BattleSystem_GetBattleInput(data->battleSystem);

    switch (data->state) {
    case 0:
        GF_ASSERT(battleInput != NULL);
        {
            NARC *bgHandleNarc = NARC_New(NARC_a_0_0_7, HEAP_ID_BATTLE);
            NARC *objHandleNarc = NARC_New(NARC_a_0_0_8, HEAP_ID_BATTLE);
            BattleInput_ChangeMenu(bgHandleNarc, objHandleNarc, battleInput, 18, FALSE, NULL);
            NARC_Delete(bgHandleNarc);
            NARC_Delete(objHandleNarc);
        }
        data->state++;
        break;
    case 1:
        if (BattleInput_CheckFeedbackDone(battleInput) == TRUE) {
            data->state++;
        }
        break;
    case 2:
        if (ov12_0223C080(data->battleSystem) == TRUE && BattleInput_CheckTouch(battleInput) == TRUE) {
            PlaySE(1501);
            data->state++;
        }
        break;
    case 3:
        data->delay++;
        if (data->delay > 8) {
            ov12_0223BFFC(data->battleSystem, 0);
            data->state++;
        }
        break;
    case 4:
        break;
    }
}
