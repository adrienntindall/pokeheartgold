#include <nitro/fs/overlay.h>
#pragma once
.public GF_SndSetState
.public GetSoundDataPointer
.public GF_SdatGetAttrPtr
.public GF_Snd_SaveState
.public GF_Snd_LoadState
.public GF_Snd_LoadGroup
.public GF_Snd_LoadSeqEx
.public GF_Snd_LoadWaveArc
.public GF_Snd_LoadBank
.public GF_GetSoundHandle
.public GF_GetSndHandleByPlayerNo
.public GF_SndWorkMicCounterFull
.public GF_SndWorkMicCounterReset
.public GF_SndWorkSetGbSoundsVolume
.public GF_SndWorkGetGbSoundsVolume
.public GF_SND_BGM_DisableSet
.public GF_SND_BGM_DisableCheck
.public sub_02004A60
.public GF_GetCurrentPlayingBGM
.public GF_SetCurrentPlayingBGM
.public sub_02004AB8
.public sub_02004AC8
.public sub_02004AD8
.public sub_02004B10
.public sub_02004B24
.public sub_02004EB4
.public Sound_SetSceneAndPlayBGM
.public sub_020051A4
.public BGM_SaveStateAndPlayNew
.public sub_02005328
.public sub_020053A8
.public sub_020053F0
.public GF_SndHandleMoveVolume
.public GF_SndHandleSetInitialVolume
.public sub_02005448
.public sub_02005464
.public GF_GetVolumeBySeqNo
.public GF_SetVolumeBySeqNo
.public GF_SndPlayerCountPlayingSeqByPlayerNo
.public GF_GetPlayerNoBySeq
.public GF_NNS_SndPlayerGetSeqNo
.public GF_GetBankInfoBySeqNo
.public GF_GetBankBySeqNo
.public sub_02005518
.public GF_MIC_StartAutoSampling
.public GF_MIC_StopAutoSampling
.public GF_MicPauseOnLidClose
.public GF_MicResumeOnLidOpen
.public sub_020055AC
.public sub_02005600
.public sub_02005680
.public sub_020056E8
.public sub_02005728
.public sub_02005738
.public sub_02005748
.public sub_02005760
.public sub_02005774
.public sub_020057AC
.public sub_020058B8
.public GF_SndHandleSetTrackPitch
.public sub_0200592C
.public sub_02005944
.public GF_SndHandleSetTrackPan
.public GF_SndHandleSetTempoRatio
.public GF_SndSetMonoFlag
.public sub_02005990
.public GF_SndGetAfterFadeDelayTimer
.public Sound_SetMasterVolume
.public sub_020059D8
.public sub_020059E0
.public GF_NowStartMusicId
.public GF_FadeStartMusicId
.public sub_02005AF8
.public GF_SndHandleSetPlayerVolume
.public sub_02005B58
.public sub_02005B68
.public sub_02005B78
.public sub_02005BA8
.public sub_02005BEC
.public sub_02005BFC
.public SoundSys_GetGBSoundsState
.public SoundSys_ToggleGBSounds
.public GBSounds_GetGBSeqNoByDSSeqNo
.public GBSounds_SetAllocatableChannels
.public sub_02005CF4
.public sub_02005D00
.public PlayBGM
.public GF_SndStartFadeInBGM
.public GF_SndStartFadeOutBGM
.public GF_SndGetFadeTimer
.public Sound_Stop
.public sub_02005FD8
.public AllocFromHeap
.public Heap_Free
.public GF_AssertFail
.public sub_020378CC
.public NNS_SndSetMasterVolume
.public NNS_SndSetMonoFlag
.public NNS_SndWaveOutAllocChannel
.public NNS_SndWaveOutFreeChannel
.public NNS_SndWaveOutStart
.public NNS_SndWaveOutStop
.public NNS_SndWaveOutSetVolume
.public NNS_SndWaveOutSetSpeed
.public NNS_SndWaveOutSetPan
.public NNS_SndWaveOutIsPlaying
.public NNS_SndPlayerSetPlayerVolume
.public NNS_SndPlayerSetAllocatableChannel
.public NNS_SndPlayerPause
.public NNS_SndPlayerCountPlayingSeqByPlayerNo
.public NNS_SndPlayerSetInitialVolume
.public NNS_SndPlayerMoveVolume
.public NNS_SndPlayerSetTrackPitch
.public NNS_SndPlayerSetTrackPan
.public NNS_SndPlayerSetTrackAllocatableChannel
.public NNS_SndPlayerSetTempoRatio
.public NNS_SndPlayerGetSeqNo
.public NNS_SndPlayerReadVariable
.public NNS_SndCaptureStopReverb
.public NNS_SndCaptureIsActive
.public NNS_SndCaptureGetCaptureType
.public NNS_SndArcGetSeqParam
.public NNS_SndArcGetBankInfo
.public NNS_SndArcGetWaveArcInfo
.public NNS_SndArcGetFileSize
.public NNS_SndArcReadFile
.public MIC_StartAutoSampling
.public MIC_StopAutoSampling
.public memset
.public _s32_div_f
