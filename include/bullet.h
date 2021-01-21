#ifndef BULLET
#define BULLET


#include "global_variables.h"

typedef struct
{
    boolean free;
    game_object *go;

} type_bullet;


type_bullet *player_bullet;

type_bullet *enemy_bullet;




#endif