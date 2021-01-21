#ifndef PHYSICS_MNG
#define PHYSICS_MNG

#include "aiv-list.h"
#include "global_variables.h"
#include "physicsMng.c"

alist *colliderList;

void physicsInit()
{
    colliderList = aiv_list_new();
}

void addCollider();


#endif