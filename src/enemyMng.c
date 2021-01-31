

#include "global_variables.h"
#include "enemy.h"
// #include <stdlib.h>
#include "enemyMng.h"
// #include "bulletMng.h"



void enemyInit(global_var *v)
{
    v->enemies = (type_enemy *)malloc(sizeof(type_enemy) * ENEMY_N);

    type_enemy* enemy=v->enemies;
    vec2 global_unitSize=v->global_unitSize;
    SDL_Renderer* renderer=v->global_renderer;

    for (size_t i = 0; i < ENEMY_N; i++)
    {
        v->Enemy_explosionTexure_Rect[i] = create_rect(i * (192 / 6), 0, 192 / 6, 32);
    }

    v->enemyPlane_texture[0] = create_texture("resources/assets/enemy/enemy1_strip3.png",renderer);
    v->enemyPlane_texture[1] = create_texture("resources/assets/enemy/enemy2_strip3.png",renderer);
    v->enemyPlane_texture[2] = create_texture("resources/assets/enemy/enemy3_strip3.png",renderer);

    v->enemyExplosion_texture = create_texture("resources/assets/enemy/explosion1_strip6.png",renderer);

    v->enemy_explosion_sound = Mix_LoadWAV("resources/assets/audio/snd_explosion2.wav");

    for (size_t i = 0; i < ENEMY_N; i++)
    {
        enemy[i].shootCount = RangedRandDemo(3, 5);
        enemy[i].hp = 100;
        SDL_Texture *tex = v->enemyPlane_texture[RangedRandDemo(0, 3)];
        SDL_Rect *texRect = create_rect(0, 0, 32, 32);
        SDL_FRect *targetRect = create_Frect(global_unitSize.x * RangedRandDemo(0, 15), global_unitSize.y * RangedRandDemo(-20, -10), global_unitSize.x, global_unitSize.y);
        enemy[i].go = create_gameObject(tex, texRect, targetRect);
        enemy[i].state = move;
        enemy[i].finishPointY = global_unitSize.y * RangedRandDemo(3, v->global_unitScreenHeight - 5);
        enemy[i].ExplosionTime = ENEMY_CONST_EXPLOSION_TIME;
    }
}

void _destroyEnemy(type_enemy *enemy)
{
    destroy_gameObject(enemy->go);
    free(enemy);
}

void _moveUpdate(type_enemy *e,global_var* v)
{
    if (e->go->target_rect->y >= e->finishPointY)
    {
        e->state = attack;
        return;
    }

    float a = v->enemyVelocity * STANDARD_VELOCITY;

    e->go->target_rect->y += v->enemyVelocity * STANDARD_VELOCITY;
}

void _attackUpdate(type_enemy *e,global_var* v)
{
    e->shootCount -= v->global_delta_time;

    if (e->shootCount <= 0)
    {
        shoot_enemyBullet(e,v->enemy_bullet.bullets);
        e->shootCount = RangedRandDemo(300, 5000);
    }

    if (e->hp <= 0)
    {
        Mix_PlayChannel(-1, v->enemy_explosion_sound, 0);
        e->go->texture = v->enemyExplosion_texture;
        e->state = dead;
    }
}

// void _SetFrameExplosion(game_object *go, float ExplosionTime, SDL_Rect *explosionTexure_Rect[])
// {

//     int index = 0;

//     boolean set = false;

//     if (ExplosionTime >= ENEMY_CONST_EXPLOSION_TIME * (0.83f) && !set)
//     {
//         index = 0;
//         set = true;
//     }
//     if (ExplosionTime >= ENEMY_CONST_EXPLOSION_TIME * (0.66f) && !set)
//     {
//         index = 1;
//         set = true;
//     }
//     if (ExplosionTime >= ENEMY_CONST_EXPLOSION_TIME * (0.50f) && !set)
//     {
//         index = 2;
//         set = true;
//     }
//     if (ExplosionTime >= ENEMY_CONST_EXPLOSION_TIME * (0.33f) && !set)
//     {
//         index = 3;
//         set = true;
//     }
//     if (ExplosionTime >= ENEMY_CONST_EXPLOSION_TIME * (0.16f) && !set)
//     {
//         index = 4;
//         set = true;
//     }

//     if (!set)
//     {
//         index = 5;
//     }

//     go->texture_rect->h = explosionTexure_Rect[index]->h;
//     go->texture_rect->w = explosionTexure_Rect[index]->w;
//     go->texture_rect->x = explosionTexure_Rect[index]->x;
//     go->texture_rect->y = explosionTexure_Rect[index]->y;
//     return;
// }

void _deadUpdate(type_enemy *e,global_var* v)
{
    vec2 global_unitSize=v->global_unitSize;

    if (e->ExplosionTime <= 0)
    {
        // _destroyEnemy(e);

        e->hp = 100;
        e->go->target_rect->x = global_unitSize.x * RangedRandDemo(0, 15);
        e->go->target_rect->y = global_unitSize.y * RangedRandDemo(-20, -10);
        e->go->texture = v->enemyPlane_texture[RangedRandDemo(0, 3)];
        e->state = move;
        e->finishPointY = global_unitSize.y * RangedRandDemo(3, v->global_unitScreenHeight - 5);
        e->ExplosionTime = ENEMY_CONST_EXPLOSION_TIME;

        return;
    }

    e->ExplosionTime -= 0.05f;
}

void enemyUpdate(type_enemy* enemy,global_var* v)
{
    for (size_t i = 0; i < ENEMY_N; i++)
    {
        switch (enemy[i].state)
        {
        case move:
            _moveUpdate(&enemy[i],v);
            break;
        case attack:
            _attackUpdate(&enemy[i],v);
            break;
        case dead:
            _deadUpdate(&enemy[i],v);
            break;
        default:
            break;
        }

        if (enemy[i].go->target_rect->y >= SCREEN_HEIGHT)
        {
            enemy[i].state = dead;
        }
    }
}

void renderEnemy(global_var* v)
{
    for (size_t i = 0; i < ENEMY_N; i++)
    {
        renderGameObject(v->enemies[i].go,v->global_renderer);
    }
}
