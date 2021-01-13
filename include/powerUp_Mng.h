


#ifndef POWER_UP_MNG
#define POWER_UP_MNG


#include "global_variables.h"
#include <stdlib.h>

typedef struct
{
    float hp;
    game_object *go; //life
    float finishPointY;
    float ExplosionTime;
    float shootCount;

} type_PowerUp;

type_PowerUp *power_up;

SDL_Texture *tex;



powerUp_init(){

    power_up=(*type_PowerUp)calloc(sizeof(type_PowerUp));


    

    


}















#endif