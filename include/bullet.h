#ifndef BULLET
#define BULLET

#include "common.h"

typedef struct
{
    boolean free;
    game_object *go;

} bullet_obj;

typedef struct
{
    bullet_obj* bullets;
    float damage;
}group_bullet;

#endif