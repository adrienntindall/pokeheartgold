    .include "macros/btlcmd.inc"

    .data

_000:
    // {1} restored {0}’s HP!
    PrintMessage msg_0197_01030, TAG_NICKNAME_MOVE, BATTLER_CATEGORY_MSG_TEMP, BATTLER_CATEGORY_MSG_TEMP
    Wait 
    WaitButtonABTime 30
    UpdateVar OPCODE_FLAG_ON, BSCRIPT_VAR_BATTLE_STATUS, BATTLE_STATUS_NO_BLINK
    CheckItemHoldEffect CHECK_OPCODE_NOT_HAVE, BATTLER_CATEGORY_MSG_TEMP, HOLD_EFFECT_LEECH_BOOST, _031
    GetItemEffectParam BATTLER_CATEGORY_MSG_TEMP, BSCRIPT_VAR_CALC_TEMP
    UpdateVar OPCODE_ADD, BSCRIPT_VAR_CALC_TEMP, 0x00000064
    UpdateVarFromVar OPCODE_MUL, BSCRIPT_VAR_HP_CALC, BSCRIPT_VAR_CALC_TEMP
    UpdateVar OPCODE_DIV, BSCRIPT_VAR_HP_CALC, 100

_031:
    PlayBattleAnimation BATTLER_CATEGORY_MSG_TEMP, BATTLE_ANIMATION_RESTORE_HP
    Wait 
    Call BATTLE_SUBSCRIPT_UPDATE_HP
    End 
