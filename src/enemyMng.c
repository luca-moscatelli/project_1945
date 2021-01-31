

#include "global_variables.h"
#include "enemy.h"
// #include <stdlib.h>
#include "enemyMng.h"
// #include "bulletMng.h"

float _getSpawnVectX(boolean *enemyColumn,type_enemy* e)
{

    int i = 0;

   int count=0;

    while (count<=100)
    {
        i = RangedRandDemo(0, UNIT_SCREEN_WIDTH);

        if (enemyColumn[i])
        {
            enemyColumn[i]=false;
            e->column=i;
            return i*UNIT_SIZE_X+UNIT_SIZE_X*0.5f;
        }

        count++;
    }

    return 200.f;
}


int _getEnemyCellIndex(float x_position){

    int i=x_position/UNIT_SCREEN_WIDTH;

    return i;
}

void enemyInit(global_var *v)
{
    v->enemies = (type_enemy *)malloc(sizeof(type_enemy) * ENEMY_N);

    type_enemy *enemy = v->enemies;
    SDL_Renderer *renderer = v->global_renderer;

    for (size_t i = 0; i <UNIT_SCREEN_WIDTH ; i++)
    {
        v->Enemy_Column_State[i]=true;
    }
    

    for (size_t i = 0; i < ENEMY_N; i++)
    {
        v->Enemy_explosionTexure_Rect[i] = create_rect(i * (192 / 6), 0, 192 / 6, 32);
    }

    v->enemyPlane_texture[0] = create_texture("resources/assets/enemy/enemy1_strip3.png", renderer);
    v->enemyPlane_texture[1] = create_texture("resources/assets/enemy/enemy2_strip3.png", renderer);
    v->enemyPlane_texture[2] = create_texture("resources/assets/enemy/enemy3_strip3.png", renderer);

    v->enemyExplosion_texture = create_texture("resources/assets/enemy/explosion1_strip6.png", renderer);

    v->enemy_explosion_sound = Mix_LoadWAV("resources/assets/audio/snd_explosion2.wav");

    for (size_t i = 0; i < ENEMY_N; i++)
    {
        enemy[i].shootCount = RangedRandDemo(3, 5);
        enemy[i].hp = 100;
        SDL_Texture *tex = v->enemyPlane_texture[RangedRandDemo(0, 3)];
        SDL_Rect *texRect = create_rect(0, 0, 32, 32);
        SDL_FRect *targetRect = create_Frect(_getSpawnVectX(v->Enemy_Column_State,&enemy[i]), UNIT_SIZE_Y * RangedRandDemo(-20, -10), UNIT_SIZE_X, UNIT_SIZE_Y);
        enemy[i].go = create_gameObject(tex, texRect, targetRect);
        enemy[i].state = move;
        enemy[i].finishPointY = UNIT_SIZE_Y * RangedRandDemo(3, UNIT_SCREEN_HEIGHT - 5);
        enemy[i].ExplosionTime = ENEMY_CONST_EXPLOSION_TIME;
    }
}

void _destroyEnemy(type_enemy *enemy)
{
    destroy_gameObject(enemy->go);
    free(enemy);
}

void _moveUpdate(type_enemy *e, global_var *v)
{
    if (e->go->target_rect->y >= e->finishPointY)
    {
        e->state = attack;
        return;
    }

    e->go->target_rect->y += v->enemyVelocity * STANDARD_VELOCITY;
}

void _attackUpdate(type_enemy *e, global_var *v)
{
    e->shootCount -= v->global_delta_time;

    if (e->shootCount <= 0)
    {
        shoot_enemyBullet(e, v->enemy_bullet.bullets);
        e->shootCount = RangedRandDemo(300, 5000);
    }

    if (e->hp <= 0)
    {
        Mix_PlayChannel(-1, v->enemy_explosion_sound, 0);
        e->go->texture = v->enemyExplosion_texture;
        e->state = dead;
    }
}

void _deadUpdate(type_enemy* e, global_var *v)
{

    if (e->ExplosionTime <= 0)
    {
        e->hp = 100;
        e->go->target_rect->x = _getSpawnVectX(v->Enemy_Column_State,e);
        e->go->target_rect->y = UNIT_SIZE_Y * RangedRandDemo(-20, -10);
        e->go->texture = v->enemyPlane_texture[RangedRandDemo(0, 3)];
        e->state = move;
        e->finishPointY = UNIT_SIZE_Y * RangedRandDemo(3, UNIT_SCREEN_HEIGHT - 5);
        e->ExplosionTime = ENEMY_CONST_EXPLOSION_TIME;
        v->Enemy_Column_State[e->column]=true;


        return;
    }

    e->ExplosionTime -= STANDARD_VELOCITY;
}

void enemyUpdate(type_enemy *enemy, global_var *v)
{
    for (size_t i = 0; i < ENEMY_N; i++)
    {
        switch (enemy[i].state)
        {
        case move:
            _moveUpdate(&enemy[i], v);
            break;
        case attack:
            _attackUpdate(&enemy[i], v);
            break;
        case dead:
            _deadUpdate(&enemy[i], v);
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

void renderEnemy(global_var *v)
{
    for (size_t i = 0; i < ENEMY_N; i++)
    {
        renderGameObject(v->enemies[i].go, v->global_renderer);
    }
}
