#ifndef STRUCT_GLOBAL_H
#define STRUCT_GLOBAL_H


#include "aiv-list.h"



typedef struct
{
    alist *colliderPlayerBullet_List;
    alist *colliderEnemyBullet_List;
    alist *collider_enemy_list;
    SDL_FRect* collider_player;

    void  (*playerBullet_collision_with_enemy_func)();

} physicsMng_var;




#endif
