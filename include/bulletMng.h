
#ifndef BULLET_MNG
#define BULLET_MNG

// #include "bullet.h"
// #include "player.h"
// #include "enemy.h"
// #include "GuiMng.h"



void bulletInit();   //init all bullet


void shoot_playerBullet();//spawn player_bullet


void shoot_enemyBullet(void *e);//spawn enemy_bullet


void updateBullet();//update all bullet 


int renderBullet();//render all bullet




#endif