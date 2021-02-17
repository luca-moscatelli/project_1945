
#include "global_variables.h"
#include "playerMng.h"
#include <stdlib.h>
#include "enemyMng.h"
#include "powerUp_Mng.h"
#include "updateObj.h"
#include "bulletMng.h"
#include "physicsMng.h"





int _updateIsland(game_object** island,float bgVelocity,global_var* v)
{

    static boolean eneter_ricardo_mode=false;
    static boolean change_ricardo_texture[3]={false,false,false};

    if(v->nemesis_destroy>=5&&!v->first){
        Mix_PlayMusic(v->ricardo_music, -1);
        v->first=true;
        eneter_ricardo_mode=true;
    }

    
    for (size_t i = 0; i < 3; i++)
    {


        if (island[i]->target_rect->y >= SCREEN_HEIGHT)
        {   
            if(eneter_ricardo_mode&&!change_ricardo_texture[i]){
                island[i]->texture=v->ricardo_texture;
                change_ricardo_texture[i]=true;
            }


            island[i]->target_rect->y = RangedRandDemo(-600, -100);
            island[i]->target_rect->x = RangedRandDemo(10, SCREEN_WIDTH - 40);
        }

        island[i]->target_rect->y += bgVelocity * STANDARD_VELOCITY;
    }

    return 0;
}

int _updateSea(global_var* v)
{
    if (v->offset_background >= UNIT_SIZE_Y - 70)
    {
        v->offset_background = -70;
    }

    v->water->target_rect->y = v->offset_background;

    v->offset_background += v->bgVelocity * STANDARD_VELOCITY;

    return 0;
}

void update(global_var* v)
{
    _updateIsland(v->island,v->bgVelocity,v);

    enemyUpdate(v->enemies,v);

    updateBullet(v->player_bullet,v->enemy_bullet,v->enemies,STANDARD_VELOCITY,v->player_plane);

    _updateSea(v);

    UpdatePlayer(v);

    physicsUpdate(v);

 //   PowerUp_update();

}