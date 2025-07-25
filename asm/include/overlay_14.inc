#include <nitro/fs/overlay.h>
#pragma once
.public FontID_Alloc
.public FontID_Release
.public FontID_String_GetWidth
.public LoadFontPal0
.public LoadFontPal1
.public FontID_String_GetWidthMultiline
.public PaletteData_Init
.public PaletteData_Free
.public PaletteData_AllocBuffers
.public PaletteData_FreeBuffers
.public PaletteData_LoadNarc
.public PaletteData_LoadPaletteSlotFromHardware
.public PaletteData_BeginPaletteFade
.public PaletteData_PushTransparentBuffers
.public PaletteData_GetSelectedBuffersBitmask
.public PlaySE
.public UnloadOverlayByID
.public HandleLoadOverlay
.public OverlayManager_New
.public OverlayManager_Delete
.public OverlayManager_CreateAndGetData
.public OverlayManager_GetData
.public OverlayManager_FreeData
.public OverlayManager_GetArgs
.public OverlayManager_Run
.public AllocAtEndAndReadWholeNarcMemberByIdPair
.public NARC_New
.public NARC_Delete
.public GfGfxLoader_LoadCharData
.public GfGfxLoader_LoadScrnData
.public GfGfxLoader_GXLoadPal
.public GfGfxLoader_GetCharData
.public GfGfxLoader_GetScrnData
.public GfGfxLoader_GetCharDataFromOpenNarc
.public G2dRenderer_SetSubSurfaceCoords
.public NewMsgDataFromNarc
.public DestroyMsgData
.public NewString_ReadMsgData
.public MessageFormat_New
.public MessageFormat_Delete
.public BufferBoxMonSpeciesName
.public BufferBoxMonNickname
.public BufferIntegerAsString
.public BufferAbilityName
.public BufferNatureName
.public BufferItemName
.public StringExpandPlaceholders
.public MessagePrinter_New
.public MessagePrinter_Delete
.public sub_0200CDAC
.public SpriteSystem_Alloc
.public SpriteManager_New
.public SpriteSystem_GetRenderer
.public SpriteSystem_Init
.public SpriteSystem_InitSprites
.public SpriteSystem_DrawSprites
.public SpriteSystem_TransferOam
.public SpriteSystem_Free
.public SpriteSystem_InitManagerWithCapacities
.public SpriteSystem_LoadCharResObj
.public SpriteSystem_LoadPlttResObj
.public SpriteSystem_LoadCellResObj
.public SpriteSystem_LoadAnimResObj
.public SpriteSystem_NewSprite
.public SpriteSystem_NewSpriteWithYOffset
.public SpriteManager_FindPlttResourceProxy
.public SpriteSystem_FreeResourcesAndManager
.public Sprite_DeleteAndFreeResources
.public ManagedSprite_TickFrame
.public ManagedSprite_SetAnim
.public ManagedSprite_IsAnimated
.public ManagedSprite_SetAnimationFrame
.public ManagedSprite_SetDrawFlag
.public ManagedSprite_GetDrawFlag
.public ManagedSprite_SetPaletteOverride
.public ManagedSprite_GetPaletteOverrideOffset
.public ManagedSprite_GetPriority
.public ManagedSprite_SetPriority
.public ManagedSprite_SetDrawPriority
.public ManagedSprite_GetDrawPriority
.public ManagedSprite_SetPositionXY
.public ManagedSprite_GetPositionXY
.public ManagedSprite_SetAffineOverwriteMode
.public ManagedSprite_SetAffineScale
.public ManagedSprite_SetAffineTranslation
.public ManagedSprite_SetOamMode
.public SpriteManager_GetSpriteList
.public SysTask_CreateOnVBlankQueue
.public SysTask_Destroy
.public LoadUserFrameGfx2
.public sub_0200E948
.public ClearFrameAndWindow2
.public BeginNormalPaletteFade
.public IsPaletteFadeFinished
.public FontSystem_NewInit
.public sub_020135AC
.public sub_020135D8
.public FontOAM_Delete
.public sub_02013688
.public sub_020136B4
.public FontOAM_SetDrawFlag
.public sub_020137F0
.public sub_020138B0
.public sub_020138E0
.public sub_02013910
.public sub_02013938
.public sub_020139D0
.public sub_02014510
.public YesNoPrompt_Create
.public YesNoPrompt_Destroy
.public YesNoPrompt_InitFromTemplate
.public YesNoPrompt_HandleInput
.public YesNoPrompt_Reset
.public MenuInputStateMgr_SetState
.public sub_0201956C
.public sub_020195C0
.public sub_020195F4
.public sub_02019688
.public sub_020196E8
.public sub_020197F4
.public sub_0201980C
.public sub_020198FC
.public sub_02019978
.public sub_020199E4
.public sub_020199F4
.public sub_02019A60
.public sub_02019B08
.public sub_02019B10
.public sub_02019B1C
.public sub_02019B44
.public sub_02019BA4
.public sub_02019BDC
.public sub_02019D18
.public sub_02019F74
.public sub_02019F78
.public sub_02019F7C
.public sub_02019F88
.public sub_02019F90
.public sub_02019F94
.public sub_02019FC4
.public sub_02019FD0
.public sub_0201A018
.public Main_SetVBlankIntrCB
.public HBlankInterruptDisable
.public CreateHeap
.public DestroyHeap
.public AllocFromHeap
.public AllocFromHeapAtEnd
.public Heap_Free
.public BgConfig_Alloc
.public SetBothScreensModesAndDisable
.public InitBgFromTemplate
.public FreeBgTilemapBuffer
.public BG_LoadCharTilesData
.public BG_ClearCharDataRange
.public LoadRectToBgTilemapRect
.public CopyToBgTilemapRect
.public FillBgTilemapRect
.public BgTilemapRectChangePalette
.public BgClearTilemapBufferAndCommit
.public InitWindow
.public AddWindowParameterized
.public AddTextWindowTopLeftCorner
.public AddWindow
.public RemoveWindow
.public CopyWindowToVram
.public ScheduleWindowCopyToVram
.public CopyWindowPixelsToVram_TextMode
.public ClearWindowTilemapAndScheduleTransfer
.public FillWindowPixelBuffer
.public BlitBitmapRect
.public GetWindowBgId
.public GetWindowWidth
.public GetWindowHeight
.public GetWindowX
.public GetWindowY
.public GetWindowBaseTile
.public DoScheduledBgGpuUpdates
.public ScheduleBgTilemapBufferTransfer
.public ScheduleSetBgPosText
.public AddTextPrinterParameterizedWithColor
.public sub_02020A0C
.public sub_020210BC
.public sub_02021148
.public sub_02021238
.public sub_02021AC8
.public sub_02021B5C
.public GfGfx_SetBanks
.public GfGfx_EngineATogglePlanes
.public GfGfx_EngineASetPlanes
.public GfGfx_EngineBTogglePlanes
.public GfGfx_EngineBSetPlanes
.public Sprite_SetImageProxy
.public Sprite_GetImageProxy
.public Sprite_GetPaletteProxy
.public TouchscreenHitbox_FindRectAtTouchNew
.public TouchscreenHitbox_TouchNewIsIn
.public System_GetTouchNew
.public System_GetTouchHeldCoords
.public System_GetTouchNewCoords
.public String_New
.public String_Delete
.public SaveArray_PCStorage_Get
.public Save_PlayerData_GetProfile
.public Save_PlayerData_GetOptionsAddr
.public Options_GetFrame
.public Save_SpecialRibbons_Get
.public AllocMonZeroed
.public AcquireBoxMonLock
.public ReleaseBoxMonLock
.public GetMonData
.public GetBoxMonData
.public SetMonData
.public SetBoxMonData
.public GetMonBaseStatEx_HandleAlternateForm
.public GetBoxMonNature
.public GetBoxMonGender
.public GetBoxmonSpriteCharAndPlttNarcIds
.public Mon_GetBoxMon
.public CopyBoxPokemonToPokemon
.public CopyPokemonToPokemon
.public BoxMon_UpdateArceusForm
.public BoxMon_UpdateGiratinaForm
.public Mon_UpdateShayminForm
.public BoxMon_UpdateShayminForm
.public PCStorage_PlaceMonInBoxFirstEmptySlot
.public PCStorage_PlaceMonInBoxByIndexPair
.public PCStorage_SwapMonsInBoxByIndexPair
.public PCStorage_DeleteBoxMonByIndexPair
.public PCStorage_GetActiveBox
.public PCStorage_FindFirstEmptySlot
.public PCStorage_CountEmptySpotsInBox
.public PCStorage_SetActiveBox
.public PCStorage_GetBoxWallpaper
.public PCStorage_SetBoxWallpaper
.public PCStorage_GetBoxName
.public PCStorage_SetBoxName
.public PCStorage_CountMonsAndEggsInBox
.public PCStorage_CountMonsInBox
.public PCStorage_GetMonDataByIndexPair
.public PCStorage_GetMonByIndexPair
.public PCStorage_IsBonusWallpaperUnlocked
.public PCStorage_SetBoxModified
.public Boxmon_GetIconNaix
.public Boxmon_GetIconPalette
.public sub_02074490
.public sub_0207449C
.public sub_020744A8
.public Party_AddMon
.public Party_RemoveMon
.public Party_GetCount
.public Party_GetMonByIndex
.public Party_GetUnkSubSlot
.public Party_SetUnkSubSlot
.public Party_SafeCopyMonToSlot_ResetUnkSub
.public SaveArray_Party_Get
.public SaveArray_IsNatDexEnabled
.public Pokedex_ConvertToCurrentDexNo
.public sub_02077678
.public sub_0207769C
.public sub_020776B4
.public sub_0207789C
.public BagView_GetItemId
.public GetItemIndexMapping
.public GetItemNameIntoString
.public GetItemDescIntoString
.public ItemIdIsMail
.public Bag_AddItem
.public Bag_TakeItem
.public Bag_CreateView
.public Save_Bag_Get
.public NamingScreen_CreateArgs
.public NamingScreen_DeleteArgs
.public sub_02088288
.public sub_0208828C
.public sub_02089D40
.public sub_0208AD34
.public NNS_G2dGetUnpackedCharacterData
.public NNS_G2dGetImageLocation
.public NNS_G2dGetImagePaletteLocation
.public G2x_SetBlendAlpha_
.public GX_LoadOBJ
.public GXS_LoadOBJ
.public DC_FlushRange
.public MIi_CpuClear16
.public MIi_CpuCopy32
.public MI_CpuFill8
.public MI_CpuCopy8
.public _fadd
.public _fsub
.public _s32_div_f
.public _u32_div_f
.public gOverlayTemplate_NamingScreen
.public gOverlayTemplate_PokemonSummary
.public gSystem
.public PCBox_Init
.public PCBox_Main
.public PCBox_Exit
.public ov15_022008B8
