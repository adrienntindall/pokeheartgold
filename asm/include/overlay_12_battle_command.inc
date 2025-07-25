#include <nitro/fs/overlay.h>
#pragma once
.public PaletteData_LoadNarc
.public PaletteData_BeginPaletteFade
.public PaletteData_GetSelectedBuffersBitmask
.public PaletteData_SetAutoTransparent
.public PlayBGM
.public sub_0200602C
.public PlaySE
.public OverlayManager_New
.public OverlayManager_Delete
.public OverlayManager_Run
.public GfGfxLoader_LoadFromNarc
.public PokepicManager_CreatePokepic
.public PokepicManager_DeleteAllPics
.public Pokepic_SetAttr
.public Pokepic_GetAttr
.public Pokepic_AddAttr
.public Pokepic_StartPaletteFadeAll
.public NewString_ReadMsgData
.public BufferBoxMonNickname
.public BufferIntegerAsString
.public StringExpandPlaceholders
.public SpriteSystem_LoadCharResObj
.public SpriteSystem_LoadPaletteBuffer
.public SpriteSystem_LoadCellResObj
.public SpriteSystem_LoadAnimResObj
.public SpriteSystem_NewSprite
.public SpriteManager_FindPlttResourceProxy
.public SpriteManager_UnloadCharObjById
.public SpriteManager_UnloadPlttObjById
.public SpriteManager_UnloadCellObjById
.public SpriteManager_UnloadAnimObjById
.public Sprite_DeleteAndFreeResources
.public ManagedSprite_TickFrame
.public SpriteSystem_LoadCharResObjAtEndWithHardwareMappingType
.public SpriteManager_GetSpriteList
.public SysTask_Destroy
.public sub_0200E398
.public sub_0200E3D8
.public DrawFrameAndWindow1
.public sub_0200E5D4
.public sub_0200FBF4
.public FontSystem_NewInit
.public sub_020135AC
.public sub_020135D8
.public FontOAM_Delete
.public sub_02013688
.public sub_020138E0
.public sub_0201649C
.public AllocFromHeap
.public Heap_Free
.public SetBgPriority
.public InitWindow
.public AddWindowParameterized
.public AddTextWindowTopLeftCorner
.public RemoveWindow
.public FillWindowPixelBuffer
.public FillWindowPixelRect
.public TextPrinterCheckActive
.public AddTextPrinterParameterizedWithColor
.public sub_02021AC8
.public sub_02021B5C
.public ObjCharTransfer_PopTaskManager
.public ObjCharTransfer_PushTaskManager
.public Sprite_SetPalOffsetRespectVramOffset
.public System_GetTouchNew
.public GF_AssertFail
.public String_Delete
.public CalcMonStats
.public GetMonData
.public SetMonData
.public AllocAndLoadMonPersonal_HandleAlternateForm
.public GetPersonalAttr
.public FreeMonPersonal
.public GetMonBaseStat
.public GetMonBaseExperienceAtCurrentLevel
.public MonApplyFriendshipMod
.public GetPokemonSpriteCharAndPlttNarcIds
.public Mon_GetBoxMon
.public Pokemon_TryLevelUp
.public MonSetMoveInSlot
.public MonTryLearnMoveOnLevelUp
.public CopyPokemonToPokemon
.public Party_MaskMonsWithPokerus
.public Mon_UpdateGiratinaForm
.public MaskOfFlagNo
.public PCStorage_PlaceMonInBoxFirstEmptySlot
.public PCStorage_GetActiveBox
.public PCStorage_FindFirstBoxWithEmptySlot
.public PCStorage_SetActiveBox
.public Pokemon_GetIconNaix
.public Pokemon_GetIconPalette
.public sub_02074490
.public sub_0207449C
.public sub_020744A8
.public Party_AddMon
.public Party_GetMonByIndex
.public Pokedex_IsNatDexEnabled
.public GetItemAttr
.public NamingScreen_CreateArgs
.public NamingScreen_DeleteArgs
.public ApplyMonMoodModifier
.public _s32_div_f
.public _u32_div_f
.public gGameLanguage
.public gOverlayTemplate_NamingScreen
.public gSystem
.public ov07_02232F58
.public ov07_02232F60
.public ov07_02233DB8
.public ov07_02233ECC
.public ov07_02233F20
.public ov12_02237B6C
.public ov12_02237CC4
.public ov12_02237D00
.public BattleSystem_GetBgConfig
.public BattleSystem_GetWindow
.public BattleSystem_GetBattleType
.public BattleSystem_GetOpponentData
.public BattleSystem_GetMaxBattlers
.public BattleSystem_GetParty
.public BattleSystem_GetPartySize
.public BattleSystem_GetPartyMon
.public ov12_0223A8D4
.public BattleSystem_GetSpriteSystem
.public BattleSystem_GetSpriteManager
.public ov12_0223A8F4
.public BattleSystem_GetMessageLoader
.public BattleSystem_GetPaletteData
.public BattleSystem_GetPokedex
.public BattleSystem_GetMessageFormat
.public BattleSystem_GetMessageBuffer
.public ov12_0223AAB8
.public BattleSystem_GetBattlerFromBattlerType
.public BattleSystem_GetFieldSide
.public BattleSystem_GetMessageIcon
.public BattleSystem_GetPcStorage
.public BattleSystem_GetTerrainId
.public BattleSystem_GetLocation
.public BattleSystem_GetTimezone
.public BattleSystem_GetOptions
.public BattleSystem_GetTextFrameDelay
.public ov12_0223B870
.public ov12_0223BB1C
.public BattleSystem_GameStatIncrement
.public ov12_0223BB44
.public ov12_0223BBF0
.public BattleSystem_HpBar_Delete
.public BattleSystem_SetCriticalHpMusicFlag
.public ov12_0223BD8C
.public BattleSystem_Random
.public BattleSystem_GetBugContestCaughtMon
.public ov12_0223C224
.public BattleSystem_SetPokedexCaught
.public BattleSystem_CheckMonCaught
.public BattleSystem_PrintBattleMessage
.public ov12_0223C4E8
.public BtlCmd_PlayEncounterAnimation
.public BtlCmd_SetPokemonEncounter
.public BtlCmd_PokemonSlideIn
.public BtlCmd_PokemonSendOut
.public BtlCmd_RecallPokemon
.public BtlCmd_DeletePokemon
.public BtlCmd_SetTrainerEncounter
.public BtlCmd_ThrowPokeball
.public BtlCmd_TrainerSlideOut
.public BtlCmd_TrainerSlideIn
.public BtlCmd_BackgroundSlideIn
.public BtlCmd_HealthbarSlideIn
.public BtlCmd_HealthbarSlideInDelay
.public BtlCmd_HealthbarSlideOut
.public BtlCmd_Wait
.public BtlCmd_CalcDamage
.public BtlCmd_CalcDamageRaw
.public BtlCmd_PrintAttackMessage
.public BtlCmd_PrintMessage
.public BtlCmd_PrintGlobalMessage
.public BtlCmd_PrintBufferedMessage
.public BtlCmd_BufferMessage
.public BtlCmd_BufferLocalMessage
.public BtlCmd_PlayMoveAnimation
.public BtlCmd_PlayMoveAnimationOnMons
.public BtlCmd_FlickerMon
.public BtlCmd_UpdateHealthbarValue
.public BtlCmd_UpdateHealthbar
.public BtlCmd_TryFaintMon
.public BtlCmd_PlayFaintAnimation
.public BtlCmd_WaitButtonABTime
.public BtlCmd_PlaySound
.public BtlCmd_CompareVarToValue
.public BtlCmd_CompareMonDataToValue
.public BtlCmd_FadeOutBattle
.public BtlCmd_GoToSubscript
.public BtlCmd_GoToEffectScript
.public BtlCmd_GoToMoveScript
.public BtlCmd_CalcCrit
.public BtlCmd_CalcExpGain
.public BtlCmd_StartGetExpTask
.public BtlCmd_WaitGetExpTask
.public BtlCmd_WaitGetExpTaskLoop
.public BtlCmd_ShowParty
.public BtlCmd_WaitMonSelection
.public BtlCmd_SwitchAndUpdateMon
.public BtlCmd_GoToIfAnySwitches
.public BtlCmd_StartCatchMonTask
.public BtlCmd_WaitCatchMonTask
.public BtlCmd_SetMultiHit
.public BtlCmd_UpdateVar
.public BtlCmd_ChangeStatStage
.public BtlCmd_UpdateMonData
.public BtlCmd_ClearVolatileStatus
.public BtlCmd_ToggleVanish
.public BtlCmd_CheckAbility
.public BtlCmd_Random
.public BtlCmd_UpdateVar2
.public BtlCmd_UpdateMonDataFromVar
.public BtlCmd_Goto
.public BtlCmd_Call
.public BtlCmd_CallFromVar
.public BtlCmd_SetMirrorMove
.public BtlCmd_ResetAllStatChanges
.public BtlCmd_LockMoveChoice
.public BtlCmd_UnlockMoveChoice
.public BtlCmd_SetHealthbarStatus
.public BtlCmd_PrintTrainerMessage
.public BtlCmd_PayPrizeMoney
.public BtlCmd_PlayBattleAnimation
.public BtlCmd_PlayBattleAnimationOnMons
.public BtlCmd_PlayBattleAnimationFromVar
.public BtlCmd_PrintRecallMessage
.public BtlCmd_PrintSendOutMessage
.public BtlCmd_PrintEncounterMessage
.public BtlCmd_PrintFirstSendOutMessage
.public BtlCmd_PrintBufferedTrainerMessage
.public BtlCmd_TryConversion
.public BtlCmd_CompareVarToVar
.public BtlCmd_CompareMonDataToVar
.public BtlCmd_AddPayDayMoney
.public BtlCmd_TryLightScreen
.public BtlCmd_TryReflect
.public BtlCmd_TryMist
.public BtlCmd_TryOHKOMove
.public BtlCmd_DivideVarByValue
.public BtlCmd_DivideVarByVar
.public BtlCmd_TryMimic
.public BtlCmd_Metronome
.public BtlCmd_TryDisable
.public BtlCmd_Counter
.public BtlCmd_MirrorCoat
.public BtlCmd_TryEncore
.public BtlCmd_TryConversion2
.public BtlCmd_TrySketch
.public BtlCmd_TrySleepTalk
.public BtlCmd_CalcFlailPower
.public BtlCmd_TrySpite
.public BtlCmd_TryPartyStatusRefresh
.public BtlCmd_TryStealItem
.public BtlCmd_TryProtection
.public BtlCmd_TrySubstitute
.public BtlCmd_TryWhirlwind
.public BtlCmd_Transform
.public BtlCmd_TrySpikes
.public BtlCmd_CheckSpikes
.public BtlCmd_TryPerishSong
.public BtlCmd_GetTurnOrderBySpeed
.public BtlCmd_GoToIfValidMon
.public BtlCmd_EndOfTurnWeatherEffect
.public BtlCmd_CalcRolloutPower
.public BtlCmd_CalcFuryCutterPower
.public BtlCmd_TryAttract
.public BtlCmd_TrySafeguard
.public BtlCmd_Present
.public BtlCmd_CalcMagnitudePower
.public BtlCmd_TryReplaceFaintedMon
.public BtlCmd_RapidSpin
.public BtlCmd_WeatherHPRecovery
.public BtlCmd_CalcHiddenPowerParams
.public BtlCmd_CopyStatStages
.public BtlCmd_TryFutureSight
.public BtlCmd_CheckMoveHit
.public BtlCmd_TryTeleport
.public BtlCmd_BeatUp
.public BtlCmd_FollowMe
.public BtlCmd_TryHelpingHand
.public BtlCmd_TrySwapItems
.public BtlCmd_TryWish
.public BtlCmd_TryAssist
.public BtlCmd_TrySetMagicCoat
.public BtlCmd_MagicCoat
.public BtlCmd_CalcRevengeDamageMul
.public BtlCmd_TryBreakScreens
.public BtlCmd_TryYawn
.public BtlCmd_TryKnockOff
.public BtlCmd_CalcHPFalloffPower
.public BtlCmd_TryImprison
.public BtlCmd_TryGrudge
.public BtlCmd_TrySnatch
.public BtlCmd_CalcWeightBasedPower
.public BtlCmd_CalcWeatherBallParams
.public BtlCmd_TryPursuit
.public BtlCmd_ApplyTypeEffectiveness
.public BtlCmd_IfTurnFlag
.public BtlCmd_SetTurnFlag
.public BtlCmd_CalcGyroBallPower
.public BtlCmd_TryMetalBurst
.public BtlCmd_CalcPaybackPower
.public BtlCmd_CalcTrumpCardPower
.public BtlCmd_CalcWringOutPower
.public BtlCmd_TryMeFirst
.public BtlCmd_TryCopycat
.public BtlCmd_CalcPunishmentPower
.public BtlCmd_TrySuckerPunch
.public BtlCmd_CheckSideCondition
.public BtlCmd_TryFeint
.public BtlCmd_TryPyschoShift
.public BtlCmd_TryLastResort
.public BtlCmd_TryToxicSpikes
.public BtlCmd_CheckToxicSpikes
.public BtlCmd_CheckIgnorableAbility
.public BtlCmd_IfSameSide
.public BtlCmd_GenerateEndOfBattleItem
.public BtlCmd_TrickRoom
.public BtlCmd_IfMovedThisTurn
.public BtlCmd_CheckItemHoldEffect
.public BtlCmd_GetItemHoldEffect
.public BtlCmd_GetItemEffectParam
.public BtlCmd_TryCamouflage
.public BtlCmd_GetTerrainMove
.public BtlCmd_GetTerrainSecondaryEffect
.public BtlCmd_CalcNaturalGiftParams
.public BtlCmd_TryPluck
.public BtlCmd_TryFling
.public BtlCmd_YesNoMenu
.public BtlCmd_WaitYesNoResult
.public BtlCmd_ChoosePokemonMenu
.public BtlCmd_WaitPokemonMenuResult
.public BtlCmd_SetLinkBattleResult
.public BtlCmd_CheckStealthRock
.public BtlCmd_CheckEffectActivation
.public BtlCmd_CheckChatterActivation
.public BtlCmd_GetCurrentMoveData
.public BtlCmd_SetMosaic
.public BtlCmd_ChangeForm
.public BtlCmd_SetBattleBackground
.public BtlCmd_UseBagItem
.public BtlCmd_TryEscape
.public BtlCmd_ShowBattleStartPartyGauge
.public BtlCmd_HideBattleStartPartyGauge
.public BtlCmd_ShowPartyGauge
.public BtlCmd_HidePartyGauge
.public BtlCmd_LoadPartyGaugeGraphics
.public BtlCmd_FreePartyGaugeGraphics
.public BtlCmd_IncrementGameStat
.public BtlCmd_RestoreSprite
.public BtlCmd_TriggerAbilityOnHit
.public BtlCmd_SpriteToOAM
.public BtlCmd_OAMToSprite
.public BtlCmd_CheckWhiteout
.public BtlCmd_BoostRandomStatBy2
.public BtlCmd_RemoveItem
.public BtlCmd_TryRecycle
.public BtlCmd_CheckItemHoldEffectOnHit
.public BtlCmd_PrintBattleResultMessage
.public BtlCmd_PrintEscapeMessage
.public BtlCmd_PrintForfeitMessage
.public BtlCmd_CheckHoldOnWith1HP
.public BtlCmd_TryRestoreStatusOnSwitch
.public BtlCmd_CheckSubstitute
.public BtlCmd_CheckIgnoreWeather
.public BtlCmd_SetRandomTarget
.public BtlCmd_CheckItemHoldEffectOnUTurn
.public BtlCmd_RefreshSprite
.public BtlCmd_PlayMoveHitSound
.public BtlCmd_PlayBGM
.public BtlCmd_CheckSafariGameDone
.public BtlCmd_WaitTime
.public BtlCmd_CheckCurMoveIsType
.public BtlCmd_LoadArchivedMonData
.public BtlCmd_RefreshMonData
.public BtlCmd_222
.public BtlCmd_223
.public BtlCmd_EndScript
.public BattleScriptReadWord
.public Task_GetExp
.public Task_GetPokemon
.public GetBattlerIDBySide
.public InitBattleMsgData
.public InitBattleMsg
.public GetMoveMessageNo
.public UpdateFrienshipFainted
.public BattlerSetAbility
.public BattleSystem_ReloadMonData
.public Link_QueueNotEmpty
.public GetBattlerVar
.public ov12_022567D4
.public BattleBuffer_GetNext
.public ov12_022568B0
.public ov12_02261294
.public BattleController_EmitPokemonSendOut
.public ov12_022628A0
.public BattleController_EmitDrawYesNoBox
.public ov12_02263564
.public BattleController_EmitSetStatus2Effect
.public ov12_0226399C
.public ov12_02263A1C
.public ov12_02263D14
.public BattleController_EmitIncrementGameStat
.public ov12_02265FC4
.public sTrumpCardPowerTable
.public sProtectSuccessChance
.public sFlailDamageTable
.public sPickupTable2
.public sLowKickDamageTable
.public sNaturePowerMoveTable
.public sPickupTable1
.public sSecretPowerEffectTable
.public sPrizeMoneyTbl
.public sBattleScriptCommandTable
.public sPickupWeightTable
.public sHoneyGatherChanceTable
.public sCamouflageTypeTable
.public ov18_021F8974
.public ov18_021F89C8
.public ov18_021F89D0
.public ov18_021F95AC
.public ov18_021F95F8
