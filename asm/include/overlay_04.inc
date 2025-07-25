#include <nitro/fs/overlay.h>
#pragma once
.public PlaySE
.public StopSE
.public IsSEPlaying
.public SysTask_CreateOnMainQueue
.public SysTask_Destroy
.public CreateCameraTranslationWrapper
.public DeleteCameraTranslationWrapper
.public SetCameraTranslationPath
.public IsCameraTranslationFinished
.public AllocFromHeap
.public AllocFromHeapAtEnd
.public Heap_Free
.public GF_ExpHeap_FndInitAllocator
.public Camera_OffsetLookAtPosAndTarget
.public Camera_GetPerspectiveAngle
.public Camera_GetDistance
.public Camera_GetAngle
.public sub_02023F90
.public GF_AssertFail
.public Save_GetGymmickPtr
.public Save_Gymmick_AssertMagic_GetData
.public Save_Gymmick_GetType
.public FieldSystem_GetSaveData
.public FieldSysGetAttrAddr
.public FieldSystem_CreateTask
.public TaskManager_Call
.public TaskManager_GetFieldSystem
.public TaskManager_GetEnvironment
.public TaskManager_GetStatePtr
.public sub_020548C0
.public GetMetatileBehavior
.public sub_0205BAC4
.public PlayerAvatar_GetFacingDirection
.public GetPlayerXCoord
.public GetPlayerZCoord
.public PlayerAvatar_GetPositionVec
.public PlayerAvatar_GetPositionVecConst
.public PlayerAvatar_GetMapObject
.public sub_0205C838
.public PlayerAvatar_ToggleAutomaticHeightUpdating
.public PlayerAvatar_ToggleAutomaticHeightUpdating_NowApply
.public MapObjectManager_GetFirstActiveObjectByID
.public MapObjectManager_GetObjectCount
.public MapObjectManager_GetObjects
.public MapObjectArray_NextObject2
.public MapObject_GetID
.public MapObject_CheckActive
.public MapObject_GetCurrentX
.public MapObject_SetCurrentX
.public MapObject_SetCurrentY
.public MapObject_GetCurrentZ
.public MapObject_SetCurrentZ
.public MapObject_CopyPositionVector
.public MapObject_SetPositionVector
.public sub_02060F78
.public MapObject_AreBitsSetForMovementScriptInit
.public MapObject_SetHeldMovement
.public MapObject_ClearHeldMovement
.public FollowMon_GetMapObject
.public FollowMon_IsActive
.public NNS_G3dMdlSetMdlFogEnableFlagAll
.public VEC_Add
.public VEC_DotProduct
.public VEC_Normalize
.public VEC_MultAdd
.public G3X_SetEdgeColorTable
.public MI_CpuFill8
.public _s32_div_f
.public ov01_021E8970
.public ov01_021E8A8C
.public ov01_021E8B04
.public ov01_021E8B60
.public ov01_021E8B6C
.public ov01_021E8B78
.public ov01_021E8B84
.public ov01_021E8B90
.public ov01_021E8BAC
.public ov01_021E8DE8
.public ov01_021E8E70
.public ov01_021E8ED0
.public ov01_021EA864
.public ov01_021EA89C
.public ov01_021EA8C4
.public ov01_021F3B04
.public ov01_021F3B08
.public ov01_021F3B0C
.public ov01_021F3B1C
.public ov01_021F3B2C
.public ov01_021F3B38
.public ov01_021F3B3C
.public ov01_021F3B44
.public ov01_021F3B4C
.public ov01_021F3C0C
.public ov01_021F62E8
.public ov01_021F6304
.public ov01_021F72DC
.public ov01_021FA2D4
.public ov01_021FA930
.public ov01_021FB3E4
.public ov01_021FB4A0
.public ov01_021FB9E0
.public Field3dModel_LoadFromFilesystem
.public Field3dModel_Unload
.public Field3dModelAnimation_LoadFromFilesystem
.public Field3dModelAnimation_Unload
.public Field3dModelAnimation_FrameAdvanceAndLoop
.public Field3dModelAnimation_FrameAdvanceAndCheck
.public Field3dModelAnimation_FrameSet
.public ov01_021FBF28
.public Field3dObject_InitFromModel
.public Field3dObject_AddAnimation
.public Field3dObject_Draw
.public Field3dObject_SetActiveFlag
.public Field3dObject_GetActiveFlag
.public Field3dObject_SetPosEx
.public Field3dObjectList_GetRenderObjectByID
.public ov01_02205A34
.public ov01_02205A60
.public ov04_02253E20
.public ov04_02253ED4
.public ov04_02254190
.public FlipAzaleaGymSwitch
.public BeginAzaleaGymSpinarakRide
.public ov04_02254710
.public ov04_02254CBC
.public ov04_02254D84
.public ov04_02254D98
.public ov04_02254DD0
.public ov04_02254DE0
.public ov04_02254F8C
.public ov04_0225507C
.public ov04_02255090
.public ov04_022550D4
.public ov04_02255FC0
.public ov04_02256044
.public ov04_02256058
.public ov04_02256304
.public ov04_022563B0
.public ov04_022563C4
.public ov04_0225640C
.public ov04_02256650
.public ov04_022566A0
.public ov04_022566EC
.public ov04_02256B64
.public ov04_02256BA0
.public ov04_02256BE4
.public ov04_02256E60
.public ov04_02256EB0
.public ov04_02256ED8
.public ov04_02256F00
