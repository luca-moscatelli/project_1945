#define PLAYER_BULLET_N 30
#define ENEMY_BULLET_N 30
#define BULLET_ENEMY_VELOCITY 200.f

#ifndef BULLET_MNG
#define BULLET_MNG

#include "bullet.h"

#include "bulletMng.c"

void bulletInit();   //init all bullet


void shoot_playerBullet();//spawn player_bullet


void shoot_enemyBullet(type_enemy *e);//spawn enemy_bullet


void updateBullet();//update all bullet 


int renderBullet();//render all bullet




#endif