
#ifndef ENEMY_MNG
#define ENEMY_MNG

#include <stdlib.h>
#include "bulletMng.h"
#include "global_variables.h"




void enemyInit();//init enemy 

void enemyUpdate();//update all enemy

void renderEnemy();//render all enemy

void _SetFrameExplosion(game_object *go, float ExplosionTime, SDL_Rect *explosionTexure_Rect[]);

#endif