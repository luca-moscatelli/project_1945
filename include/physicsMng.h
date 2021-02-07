#ifndef PHYSICS_MNG
#define PHYSICS_MNG


#include "global_variables.h"





void physicsInit(global_var* v);


void addPlayerCollider(SDL_FRect* player_collider);
void addCollider(alist* list,SDL_FRect* collider);

void physicsUpdate(global_var* v);


#endif