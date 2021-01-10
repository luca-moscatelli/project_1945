#define PLAYER_BULLET_N 30
#define ENEMY_BULLET_N 30





#ifndef BULLET_MNG
#define BULLET_MNG

#include"bulletMng.c"




void bulletInit();


void shoot_playerBullet();

void shoot_enemyBullet(type_enemy *e);

void _updatePlayerBullet();

void _updateEnemyBullet();

void updateBullet();

int renderBullet();


#endif