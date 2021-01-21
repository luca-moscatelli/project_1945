#ifndef PLAYER
#define PLAYER

#include "global_variables.h"

enum
{
    player_live,
    player_onDead,
    player_dead
};
typedef unsigned char player_state;


typedef struct
{
    game_object *go;
    int finishPointY;
    float ExplosionTime;
    float hp;
    float explosion_time;
    float respawn_time;
    player_state state;
    uint32_t life;

} type_player;


type_player player_plane;


#endif