#include <nitro/fs/overlay.h>
#pragma once
.public TextFlags_SetCanTouchSpeedUpPrint
.public FontID_String_GetWidth
.public FontID_String_AllCharsValid
.public FontID_String_GetWidthMultiline
.public PaletteData_Init
.public PaletteData_Free
.public PaletteData_AllocBuffers
.public PaletteData_FreeBuffers
.public PaletteData_LoadPalette
.public PaletteData_LoadFromNarc
.public PaletteData_LoadNarc
.public PaletteData_LoadPaletteSlotFromHardware
.public PaletteData_GetFadedBuf
.public PaletteData_PushTransparentBuffers
.public PaletteData_SetAutoTransparent
.public PaletteData_BlendPalettes
.public PlaySE
.public StopSE
.public PlayCry
.public UnloadOverlayByID
.public HandleLoadOverlay
.public NARC_New
.public NARC_Delete
.public GfGfxLoader_LoadFromNarc_GetSizeOut
.public GfGfxLoader_LoadCharDataFromOpenNarc
.public GfGfxLoader_LoadScrnDataFromOpenNarc
.public PokepicManager_Create
.public PokepicManager_DrawAll
.public PokepicManager_Delete
.public PokepicManager_CreatePokepic
.public Pokepic_Delete
.public Pokepic_SetAttr
.public PokepicManager_HandleLoadImgAndOrPltt
.public G2dRenderer_SetSubSurfaceCoords
.public G2dRenderer_SetObjCharTransferReservedRegion
.public G2dRenderer_SetPlttTransferReservedRegion
.public NewMsgDataFromNarc
.public DestroyMsgData
.public ReadMsgDataIntoString
.public NewString_ReadMsgData
.public GetSpeciesNameIntoArray
.public MessageFormat_New_Custom
.public MessageFormat_Delete
.public BufferString
.public BufferCountryName
.public BufferCityName
.public BufferECWord
.public BufferMonthNameAbbr
.public StringExpandPlaceholders
.public MessageFormat_ResetBuffers
.public SpriteSystem_Alloc
.public SpriteManager_New
.public SpriteSystem_GetRenderer
.public SpriteSystem_Init
.public SpriteSystem_InitSprites
.public SpriteSystem_DrawSprites
.public SpriteSystem_TransferOam
.public SpriteSystem_Free
.public SpriteSystem_InitManagerWithCapacities
.public SpriteSystem_LoadCharResObjFromOpenNarc
.public SpriteSystem_LoadPaletteBuffer
.public SpriteSystem_LoadPaletteBufferFromOpenNarc
.public SpriteSystem_LoadCellResObj
.public SpriteSystem_LoadCellResObjFromOpenNarc
.public SpriteSystem_LoadAnimResObj
.public SpriteSystem_LoadAnimResObjFromOpenNarc
.public SpriteSystem_NewSprite
.public SpriteManager_FindPlttResourceProxy
.public SpriteManager_UnloadCharObjById
.public SpriteManager_UnloadPlttObjById
.public SpriteManager_UnloadCellObjById
.public SpriteManager_UnloadAnimObjById
.public SpriteSystem_FreeResourcesAndManager
.public Sprite_DeleteAndFreeResources
.public ManagedSprite_TickFrame
.public ManagedSprite_TickTwoFrames
.public ManagedSprite_SetAnim
.public ManagedSprite_GetActiveAnim
.public ManagedSprite_IsAnimated
.public ManagedSprite_SetDrawFlag
.public ManagedSprite_SetPaletteOverride
.public ManagedSprite_SetPaletteOverrideOffset
.public ManagedSprite_SetDrawPriority
.public ManagedSprite_SetPositionXY
.public ManagedSprite_SetPositionXYWithSubscreenOffset
.public ManagedSprite_GetPositionXY
.public ManagedSprite_GetPositionXYWithSubscreenOffset
.public ManagedSprite_OffsetPositionXY
.public ManagedSprite_SetPositonFxXY
.public ManagedSprite_GetSpritePositionFxXY
.public ManagedSprite_SetAffineOverwriteMode
.public ManagedSprite_SetAffineScale
.public ManagedSprite_SetFlipMode
.public ManagedSprite_SetOamMode
.public SpriteSystem_LoadCharResObjAtEndWithHardwareMappingType
.public SpriteSystem_LoadCharResObjFromOpenNarcWithHardwareMappingType
.public SpriteManager_GetSpriteList
.public SysTask_CreateOnMainQueue
.public SysTask_CreateOnVBlankQueue
.public SysTask_Destroy
.public BeginNormalPaletteFade
.public IsPaletteFadeFinished
.public FontSystem_NewInit
.public sub_020135AC
.public sub_02013688
.public sub_020136B4
.public FontOAM_SetDrawFlag
.public sub_020138E0
.public sub_02013910
.public sub_02013938
.public sub_02013950
.public sub_020139C8
.public sub_020139D0
.public sub_02013FD0
.public MailMsg_GetExpandedString
.public Main_SetVBlankIntrCB
.public HBlankInterruptDisable
.public sub_0201A728
.public sub_0201A738
.public AllocFromHeap
.public Heap_Free
.public BgConfig_Alloc
.public SetBothScreensModesAndDisable
.public InitBgFromTemplate
.public FreeBgTilemapBuffer
.public SetBgPriority
.public BgSetPosTextAndCommit
.public BgClearTilemapBufferAndCommit
.public InitWindow
.public WindowIsInUse
.public AddWindowParameterized
.public AddTextWindowTopLeftCorner
.public RemoveWindow
.public CopyWindowToVram
.public ScheduleWindowCopyToVram
.public ClearWindowTilemapAndCopyToVram
.public FillWindowPixelBuffer
.public GetWindowWidth
.public DoScheduledBgGpuUpdates
.public GF_SinDeg
.public GF_CosDeg
.public AddTextPrinterParameterizedWithColor
.public GF_CreateVramTransferManager
.public GF_DestroyVramTransferManager
.public GF_RunVramTransferTasks
.public sub_020210BC
.public sub_02021148
.public sub_02021238
.public sub_02021AC8
.public sub_02021B5C
.public GfGfx_SetBanks
.public GfGfx_DisableEngineAPlanes
.public GfGfx_EngineATogglePlanes
.public GfGfx_DisableEngineBPlanes
.public GfGfx_EngineBTogglePlanes
.public GfGfx_SwapDisplay
.public TouchscreenHitbox_TouchHeldIsIn
.public TouchscreenHitbox_TouchNewIsIn
.public System_GetTouchHeld
.public System_GetTouchNew
.public System_GetTouchHeldCoords
.public System_GetTouchNewCoords
.public GF_AssertFail
.public String_New
.public String_Delete
.public String_SetEmpty
.public String16_FormatInteger
.public String16_FormatUnsignedLongLong
.public String_CountLines
.public String_GetLineN
.public CopyU16ArrayToString
.public CopyStringToU16Array
.public String_Cat
.public TouchHitboxController_Create
.public TouchHitboxController_Destroy
.public TouchHitboxController_IsTriggered
.public Thunk_G3X_Reset
.public RequestSwap3DBuffers
.public GF_3DVramMan_Create
.public GF_3DVramMan_Delete
.public SaveArray_PCStorage_Get
.public sub_02027134
.public SaveGameNormal
.public Save_NumModifiedPCBoxesIsMany
.public SaveArray_CalcCRC16
.public Save_SysInfo_Get
.public Save_SysInfo_GetField4C
.public Save_PlayerData_GetOptionsAddr
.public Save_PlayerData_GetIGTAddr
.public Pokedex_CheckMonSeenFlag
.public Save_Pokedex_Get
.public Save_Misc_Get
.public sub_0202AC1C
.public sub_0202AC38
.public sub_0202AC60
.public sub_0202B998
.public sub_0202B9B8
.public sub_0202BC10
.public sub_0202BE60
.public sub_0202BE98
.public Save_FashionData_Get
.public GetIGTHours
.public GetIGTMinutes
.public GetIGTSeconds
.public Save_GameStats_Get
.public GameStats_GetCapped
.public GameStats_AddScore
.public FrontierData_BattlePointAction
.public Save_FrontierData_Get
.public sub_0202FBF0
.public sub_0202FC24
.public sub_0202FC48
.public sub_0202FC90
.public sub_0202FDA4
.public sub_0202FEB8
.public sub_02030250
.public sub_0203077C
.public sub_020307AC
.public sub_020307F8
.public sub_02030814
.public sub_0203088C
.public sub_02030920
.public sub_02030938
.public sub_020314A4
.public sub_020314BC
.public sub_020314C4
.public sub_020315B8
.public sub_020315D0
.public sub_020315E0
.public sub_020315F0
.public sub_02031610
.public sub_02031620
.public sub_0203162C
.public sub_0203164C
.public sub_020316F0
.public sub_02031700
.public sub_0203A4AC
.public sub_0203A86C
.public sub_0203A880
.public sub_0203A914
.public sub_0203A948
.public Save_VarsFlags_Get
.public Save_VarsFlags_GetBattleFactoryPrintProgress
.public Save_VarsFlags_GetBattleHallPrintProgress
.public Save_VarsFlags_GetBattleCastlePrintProgress
.public Save_VarsFlags_GetBattleArcadePrintProgress
.public Save_VarsFlags_GetBattleTowerPrintProgress
.public GetMonData
.public SetMonData
.public AllocAndLoadMonPersonal
.public FreeMonPersonal
.public GetGenderBySpeciesAndPersonality
.public CalcShininessByOtIdAndPersonality
.public GetMonSpriteCharAndPlttNarcIdsEx
.public GetMonPicHeightBySpeciesGenderForm
.public PCStorage_IsBonusWallpaperUnlocked
.public GetMonIconNaixEx
.public GetMonIconPaletteEx
.public sub_02074490
.public sub_0207449C
.public sub_020744A8
.public Party_GetCount
.public Party_GetMonByIndex
.public sub_02087284
.public sub_0208763C
.public sub_02087878
.public sub_020878B0
.public sub_020878B8
.public sub_020878EC
.public sub_02087948
.public sub_020879E0
.public sub_02087A08
.public sub_02087A30
.public sub_02087A54
.public sub_02087A84
.public sub_02087E1C
.public sub_02088030
.public NNS_G2dGetUnpackedPaletteData
.public NNS_G2dSetupSoftwareSpriteCamera
.public G2x_SetBlendAlpha_
.public OS_WaitVBlankIntr
.public MIi_CpuClear16
.public MIi_CpuClear32
.public MI_CpuFill8
.public MI_CpuCopy8
.public memset
.public _fadd
.public _fgr
.public _fsub
.public _ll_udiv
.public _ull_mod
.public _ll_mul
.public _s32_div_f
.public _u32_div_f
.public gSystem
.public _021D2AF8
.public ov39_02227080
.public ov39_02227088
.public ov39_022271C0
.public ov39_02227208
.public ov39_022272EC
.public ov39_022273B0
.public ov39_022273F8
.public ov39_02227420
.public ov39_0222748C
.public ov39_022274B4
.public ov39_022274D4
.public ov39_02227534
.public ov39_02227590
.public ov39_022275E8
.public ov39_02227648
.public ov39_022276A4
.public ov39_022276E0
.public ov39_02227720
.public ov39_0222774C
.public ov39_02227778
.public ov39_02227D44
.public ov39_02227DB8
.public ov39_02227E8C
.public ov39_02227F14
.public ov39_02227F74
.public ov39_02227FA8
.public ov39_02227FEC
.public ov39_0222801C
.public ov39_022280D4
.public ov40_0222B6E0
.public ov40_0222B934
.public ov40_0222BD30
.public ov40_0222C480
.public ov40_0222CA8C
.public ov40_0222CABC
.public ov40_0222CF94
.public ov40_0222D55C
.public ov40_0222DAC0
.public ov40_02244920
.public ov40_02244B3C
.public ov40_02244B70
.public ov41_0224B530
.public ov41_0224B554
.public ov41_0224B57C
.public ov41_0224B5C8
.public ov41_0224B5D0
