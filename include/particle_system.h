#ifndef POKEHEARTGOLD_PARTICLE_SYSTEM_H
#define POKEHEARTGOLD_PARTICLE_SYSTEM_H

typedef struct ParticleSystemEmitter_Sub8 {
    void *begin;
    int index;
    void *end;
} ParticleSystemEmitter_Sub8;

typedef struct ParticleSystemResource_Sub0 {
    u32 flag;
    VecFx32 pos;
} ParticleSystemResource_Sub0; 

typedef struct ParticleSystemResource {
    ParticleSystemResource_Sub0 *unk0;
} ParticleSystemResource; //incomplete

typedef struct ParticleSystemEmitter {
    struct ParticleSystemEmitter *next;
    struct ParticleSystemEmitter *prev;
    ParticleSystemEmitter_Sub8 unk8;
    ParticleSystemEmitter_Sub8 unk14;
    ParticleSystemResource *resource;
    u32 unk;
    VecFx32 emitPos;
    VecFx32 emitVelocity;
    VecFx32 emitVelocity0;
    u16 age;
    u16 fps;
    VecFx16 axis;
} ParticleSystemEmitter; //incomplete

inline void ParticleSystemEmitter_SetEmitPos(ParticleSystemEmitter* emit, const VecFx32* pos ) {
    emit->emitPos.x = pos->x + emit->resource->unk0->pos.x;
    emit->emitPos.y = pos->y + emit->resource->unk0->pos.y;
    emit->emitPos.z = pos->z + emit->resource->unk0->pos.z;
}

#endif //POKEHEARTGOLD_PARTICLE_SYSTEM_H
