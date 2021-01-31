
#ifndef BULLET_MNG
#define BULLET_MNG

#include "global_variables.h"




void bulletInit(global_var* v);   //init all bullet


void shoot_playerBullet(bullet_obj *player_bullet, type_player *player_plane);//spawn player_bullet


void shoot_enemyBullet(void *enemy,bullet_obj* enemy_bullet);//spawn enemy_bullet


void updateBullet(group_bullet type_bullet_player ,group_bullet type_bullet_enemy,type_enemy* enemy,float norm_velocity,type_player* player);//update all bullet 


int renderBullet(SDL_Renderer *renderer, bullet_obj *enemy_bullet, bullet_obj *player_bullet);//render all bullet




#endif