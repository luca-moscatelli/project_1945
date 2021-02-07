
#include "physicsMng.h"

void physicsInit(global_var* v){
    
    v->physics=(physicsMng_var*)malloc(sizeof(physicsMng_var));

    physicsMng_var* physics=v->physics;


    physics->colliderEnemyBullet_List=aiv_list_new();
    physics->colliderPlayerBullet_List=aiv_list_new();
    physics->collider_enemy_list=aiv_list_new();

}

void _PlayerBulletCollision(physicsMng_var* physics){

    alist* playerBullet_list=physics->colliderPlayerBullet_List;
    alist* enemy_list=physics->collider_enemy_list;

    for (size_t i = 0; i < aiv_list_size(playerBullet_list); i++)
    {
        for (size_t j = 0; j < aiv_list_size(enemy_list); j++)
        {
            SDL_FRect* collider1=(SDL_FRect*)aiv_list_item_at(playerBullet_list,i);
            SDL_FRect* collider2=(SDL_FRect*)aiv_list_item_at(enemy_list,j);


            if(check_collision(*collider1,*collider2)){
                SDL_LogDebug(1,"enter");
            }
        }
        
    }


    

}


void addCollider(alist* list,SDL_FRect* collider){
    aiv_list_add(list,collider);
}

void physicsUpdate(global_var* v){
    _PlayerBulletCollision(v->physics);
}
