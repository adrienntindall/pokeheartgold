#ifndef POKEHEARTGOLD_UNK_02007FD8_H
#define POKEHEARTGOLD_UNK_02007FD8_H

#include "filesystem_files_def.h"
#include "unk_02016EDC.h"

typedef struct UnkStruct_02009264 {
    u8 unk_0;
    s8 unk_1;
    u8 unk_2;
    u8 unk_3;
    u8 unk_4[10];
    struct UnkStruct_02072914_sub_sub *unk_10;
} UnkStruct_02009264;

void sub_020087A4(u32 *a0, int a1, int dy);
void sub_02009264(UnkStruct_02009264 *a0, struct UnkStruct_02072914_sub_sub *a1);
int sub_02009284(UnkStruct_02009264 *a0);
void sub_02009D28(void *pRawData, NarcId narcId);
void sub_02009B60(void *pRawData, u32 pid, BOOL isAnimated);

#endif //POKEHEARTGOLD_UNK_02007FD8_H
