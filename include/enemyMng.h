
#ifndef ENEMY_MNG
#define ENEMY_MNG

#include <stdlib.h>
#include "bulletMng.h"
#include "global_variables.h"




void enemyInit(global_var* v);//init enemy 

void enemyUpdate(type_enemy* enemy,global_var* v);//update all enemy

void renderEnemy(global_var* v);//render all enemy

//void _SetFrameExplosion(game_object *go, float ExplosionTime, SDL_Rect *explosionTexure_Rect[]);

#endif