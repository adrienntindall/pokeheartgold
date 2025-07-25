#include <nitro/fs/overlay.h>
#pragma once
.public TextFlags_SetCanABSpeedUpPrint
.public TextFlags_SetAutoScrollParam
.public TextFlags_SetCanTouchSpeedUpPrint
.public PaletteData_Init
.public PaletteData_Free
.public PaletteData_AllocBuffers
.public PaletteData_FreeBuffers
.public PaletteData_LoadNarc
.public PaletteData_LoadPaletteSlotFromHardware
.public PaletteData_PushTransparentBuffers
.public PaletteData_SetAutoTransparent
.public PaletteData_FillPaletteInBuffer
.public sub_02004AC8
.public NARC_New
.public NARC_Delete
.public GfGfxLoader_LoadCharDataFromOpenNarc
.public GfGfxLoader_LoadScrnDataFromOpenNarc
.public GfGfxLoader_GetPlttDataFromOpenNarc
.public G2dRenderer_SetMainSurfaceCoords
.public G2dRenderer_SetSubSurfaceCoords
.public G2dRenderer_SetObjCharTransferReservedRegion
.public G2dRenderer_SetPlttTransferReservedRegion
.public SpriteSystem_Alloc
.public SpriteManager_New
.public SpriteSystem_GetRenderer
.public SpriteSystem_Init
.public SpriteSystem_InitSprites
.public SpriteSystem_DrawSprites
.public SpriteSystem_TransferOam
.public SpriteSystem_UpdateTransfer
.public SpriteSystem_Free
.public SpriteSystem_InitManagerWithCapacities
.public SpriteManager_UnloadCharObjById
.public SpriteManager_UnloadPlttObjById
.public SpriteManager_UnloadCellObjById
.public SpriteManager_UnloadAnimObjById
.public SpriteSystem_FreeResourcesAndManager
.public Sprite_DeleteAndFreeResources
.public ManagedSprite_TickFrame
.public ManagedSprite_SetAnim
.public ManagedSprite_GetActiveAnim
.public ManagedSprite_SetAnimationFrame
.public ManagedSprite_GetAnimationFrame
.public ManagedSprite_SetDrawFlag
.public ManagedSprite_GetDrawFlag
.public ManagedSprite_SetPositionXY
.public ManagedSprite_GetPositionXY
.public SpriteManager_GetSpriteList
.public SysTask_CreateOnMainQueue
.public SysTask_CreateOnVBlankQueue
.public SysTask_Destroy
.public LoadUserFrameGfx1
.public LoadUserFrameGfx2
.public Main_SetVBlankIntrCB
.public HBlankInterruptDisable
.public SetKeyRepeatTimers
.public CreateHeap
.public DestroyHeap
.public AllocFromHeap
.public Heap_Free
.public BgConfig_Alloc
.public SetBothScreensModesAndDisable
.public InitBgFromTemplate
.public FreeBgTilemapBuffer
.public ToggleBgLayer
.public BgSetPosTextAndCommit
.public BgClearTilemapBufferAndCommit
.public DoScheduledBgGpuUpdates
.public ScheduleBgTilemapBufferTransfer
.public ScheduleSetBgPosText
.public GF_CreateVramTransferManager
.public GF_DestroyVramTransferManager
.public GF_RunVramTransferTasks
.public sub_020210BC
.public sub_02021148
.public sub_02021238
.public GfGfx_SetBanks
.public GfGfx_DisableEngineAPlanes
.public GfGfx_EngineATogglePlanes
.public GfGfx_DisableEngineBPlanes
.public GfGfx_EngineBTogglePlanes
.public GfGfx_BothDispOn
.public GF_AssertFail
.public RequestSwap3DBuffers
.public GF_3DVramMan_Create
.public GF_3DVramMan_Delete
.public Save_PlayerData_GetProfile
.public Options_GetFrame
.public sub_0203A880
.public sub_0203A914
.public sub_02055198
.public Frontier_GetLaunchParam
.public sub_02096864
.public sub_02096868
.public sub_0209686C
.public sub_02096878
.public sub_02096884
.public G3X_SetFog
.public G3X_SetClearColor
.public GX_BeginLoadBGExtPltt
.public GX_LoadBGExtPltt
.public GX_EndLoadBGExtPltt
.public DC_FlushRange
.public MIi_CpuClear16
.public MIi_CpuClear32
.public MI_CpuFill8
.public _fadd
.public _ffix
.public _fflt
.public _fsub
.public ov42_02227EE0
.public ov42_02227F28
.public ov42_02227F48
.public ov42_02228010
.public ov42_02228050
.public ov42_02228068
.public ov42_0222807C
.public ov42_022280B8
.public ov42_02228100
.public ov42_02228188
.public ov42_02228C80
.public ov42_02228F24
.public ov42_02228F94
.public ov42_02228FE0
.public ov42_02229004
.public ov42_0222903C
.public ov42_022290C4
.public ov42_022290DC
.public ov42_022291F4
.public ov42_02229200
.public ov42_02229358
.public ov42_02229394
.public ov42_022293A8
.public ov42_022293B0
.public ov42_022293B8
.public ov42_0222940C
.public ov42_02229420
.public ov42_02229974
.public ov42_022299AC
.public ov42_02229A08
.public ov42_02229A40
.public ov42_02229A78
.public ov42_02229AC8
.public ov80_0222A7EC
.public ov80_0222ACA0
.public ov80_0222AD9C
.public ov80_0222ADB4
.public FrontierMap_Init
.public FrontierMap_Free
.public ov80_022389C4
.public ov80_02238A18
.public ov80_0223947C
.public ov80_022394D8
.public ov80_02239510
.public ov80_02239590
.public ov80_022395E8
.public ov80_0223962C
.public ov80_0223965C
.public ov80_0223968C
.public ov80_022396D8
.public ov80_02239700
.public ov80_02239708
.public ov80_02239734
.public ov80_022398E4
.public ov80_02239938
.public ov80_02239960
.public ov80_02239980
.public ov80_02239A38
.public ov80_02239AF8
.public ov80_02239B7C
.public ov80_02239BB8
.public ov80_02239BE8
