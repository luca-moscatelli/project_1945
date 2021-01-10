

#ifndef ENEMY_MNG
#define ENEMY_MNG

#include "global_variables.h"
//#include "bulletMng.h"
#include <stdlib.h>

enum 
{
    move,
    attack,
    dead
};
typedef unsigned char enemy_state;

typedef struct 
{
    float hp;
    game_object* go;
    enemy_state state;
    float finishPointY;
    float ExplosionTime;
    

}type_enemy;

float enemy_n;

type_enemy* enemy;

const float CONST_ExplosionTime = 90.f;

float enemyVelocity = 0.08f;
SDL_Texture *enemyPlane_texture[3];
SDL_Texture *enemyExplosion_texture;
SDL_Rect *explosionTexure_Rect[6];

void enemyInit()
{
    enemy_n = 6;

    enemy = (type_enemy *)malloc(sizeof(type_enemy) * enemy_n);

    for (size_t i = 0; i < enemy_n; i++)
    {
        explosionTexure_Rect[i] = create_rect(i * (192 / 6), 0, 192 / 6, 32);
    }

    enemyPlane_texture[0] = create_texture("resources/assets/enemy/enemy1_strip3.png");
    enemyPlane_texture[1] = create_texture("resources/assets/enemy/enemy2_strip3.png");
    enemyPlane_texture[2] = create_texture("resources/assets/enemy/enemy3_strip3.png");

    enemyExplosion_texture = create_texture("resources/assets/enemy/explosion1_strip6.png");

    for (size_t i = 0; i < enemy_n; i++)
    {
        enemy[i].hp = 100;
        SDL_Texture *tex = enemyPlane_texture[RangedRandDemo(0, 3)];
        SDL_Rect *texRect = create_rect(0, 0, 32, 32);
        SDL_FRect *targetRect = create_Frect(global_unitSize.x * RangedRandDemo(0, 15), global_unitSize.y * RangedRandDemo(-20, -10), global_unitSize.x, global_unitSize.y);
        enemy[i].go = create_gameObject(tex, texRect, targetRect);
        enemy[i].state = move;
        enemy[i].finishPointY = global_unitSize.y * RangedRandDemo(3, global_unitScreenHeight - 5);
        enemy[i].ExplosionTime = CONST_ExplosionTime;
    }
}

void _destroyEnemy(type_enemy *enemy)
{
    destroy_gameObject(enemy->go);
    free(enemy);
}

void _moveUpdate(type_enemy *e)
{
    if (e->go->target_rect->y >= e->finishPointY)
    {
        e->state = attack;
        return;
    }

    e->go->target_rect->y += enemyVelocity;
}

void _attackUpdate(type_enemy *e)
{
      //  shoot_enemyBullet(e);

    if (e->hp <= 0)
    {
        e->go->texture = enemyExplosion_texture;
        e->state = dead;
    }
}

void _SetFrameExplosion(type_enemy *e)
{

    int index = 0;

    boolean set = false;

    if (e->ExplosionTime >= CONST_ExplosionTime * (0.83f) && !set)
    {
        index = 0;
        set = true;
    }
    if (e->ExplosionTime >= CONST_ExplosionTime * (0.66f) && !set)
    {
        index = 1;
        set = true;
    }
    if (e->ExplosionTime >= CONST_ExplosionTime * (0.50f) && !set)
    {
        index = 2;
        set = true;
    }
    if (e->ExplosionTime >= CONST_ExplosionTime * (0.33f) && !set)
    {
        index = 3;
        set = true;
    }
    if (e->ExplosionTime >= CONST_ExplosionTime * (0.16f) && !set)
    {
        index = 4;
        set = true;
    }

    if (!set)
    {
        index = 5;
    }

    e->go->texture_rect->h = explosionTexure_Rect[index]->h;
    e->go->texture_rect->w = explosionTexure_Rect[index]->w;
    e->go->texture_rect->x = explosionTexure_Rect[index]->x;
    e->go->texture_rect->y = explosionTexure_Rect[index]->y;
    return;
}

void _deadUpdate(type_enemy *e)
{

    if (e->ExplosionTime <= 0)
    {
        // _destroyEnemy(e);

        e->hp = 100;
        e->go->target_rect->x = global_unitSize.x * RangedRandDemo(0, 15);
        e->go->target_rect->y = global_unitSize.y * RangedRandDemo(-20, -10);
        e->go->texture = enemyPlane_texture[RangedRandDemo(0, 3)];
        e->state = move;
        e->finishPointY = global_unitSize.y * RangedRandDemo(3, global_unitScreenHeight - 5);
        e->ExplosionTime = CONST_ExplosionTime;

        return;
    }

    e->ExplosionTime -= 0.05f;
}

void enemyUpdate()
{
    for (size_t i = 0; i < enemy_n; i++)
    {
        switch (enemy[i].state)
        {
        case move:
            _moveUpdate(&enemy[i]);
            break;
        case attack:
            _attackUpdate(&enemy[i]);
            break;
        case dead:
            _deadUpdate(&enemy[i]);
            break;
        default:
            break;
        }
    }
}

void renderEnemy()
{
    for (size_t i = 0; i < enemy_n; i++)
    {
        renderGameObject(enemy[i].go);
    }
}

#endif