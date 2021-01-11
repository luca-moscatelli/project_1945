#define PLAYER_BULLET_N 30
#define ENEMY_BULLET_N 30

#ifndef BULLET_MNG
#define BULLET_MNG

#include "global_variables.h"
#include <SDL_image.h>
#include <SDL_mixer.h>
#include "enemyMng.h"
#include "GuiMng.h"



float player_bullet_damage = 20;
float enemy_bullet_damage = 10;
float player_bullet_velocity=150.f;
Mix_Chunk *soundExplosion;

void bulletInit()
{
    player_bullet = (type_bullet *)malloc(sizeof(type_bullet) * PLAYER_BULLET_N);
    SDL_Texture *tex = create_texture("resources/assets/player/bullet.png");
    SDL_Rect *rect_Tex = create_rect(12, 5, 20, 20);

    for (size_t i = 0; i < PLAYER_BULLET_N; i++)
    {
        SDL_FRect *target_Rect = create_Frect(-100, -100, global_unitSize.x * 0.5f, global_unitSize.y * 0.5f);
        player_bullet[i].go = create_gameObject(tex, rect_Tex, target_Rect);
        player_bullet[i].free = true;
    }

    enemy_bullet = (type_bullet *)malloc(sizeof(type_bullet) * ENEMY_BULLET_N);
    tex = create_texture("resources/assets/enemy/enemybullet1.png");
    rect_Tex = create_rect(12, 5, 20, 20);

    for (size_t i = 0; i < ENEMY_BULLET_N; i++)
    {
        SDL_FRect *target_Rect = create_Frect(-100, -100, global_unitSize.x * 0.5f, global_unitSize.y * 0.5f);
        enemy_bullet[i].go = create_gameObject(tex, rect_Tex, target_Rect);
        enemy_bullet[i].free = true;
    }

    soundExplosion = Mix_LoadWAV("resources/assets/audio/snd_explosion1.wav");
    Mix_VolumeChunk(soundExplosion,80);
}

void shoot_playerBullet()
{

    for (size_t i = 0; i < PLAYER_BULLET_N; i++)
    {
        if (player_bullet[i].free)
        {
            Mix_PlayChannel(-1, soundExplosion,0);
            player_bullet[i]
                .go->target_rect->x = player_plane.go->target_rect->x + player_plane.go->target_rect->w * 0.16f + player_bullet[i].go->target_rect->w * 0.5f;
            player_bullet[i].go->target_rect->y = player_plane.go->target_rect->y - 30;
            player_bullet[i].free = false;
            return;
        }
    }
}


void _updatePlayerBullet()
{
    for (size_t i = 0; i < PLAYER_BULLET_N; i++)
    {
        if (!player_bullet[i].free)
        {
            for (size_t j = 0; j < enemy_n; j++)
            {
                if (check_collision(*((player_bullet[i]).go)->target_rect, *((enemy[j].go)->target_rect)))
                {
                    if (enemy[j].state != dead)
                    {
                        enemy[j].hp -= player_bullet_damage;
                        player_bullet[i].free = true;
                        return;
                    }
                }
            }

            

            player_bullet[i].go->target_rect->y -=player_bullet_velocity*STANDARD_VELOCITY;
            float a =STANDARD_VELOCITY;



            if (player_bullet[i].go->target_rect->y <= -30)
            {
                player_bullet[i].free = true;
            }
        }
    }
}

void _updateEnemyBullet()
{
    for (size_t i = 0; i < ENEMY_BULLET_N; i++)
    {
        if (!enemy_bullet[i].free)
        {

            if (check_collision(*((enemy_bullet[i]).go)->target_rect, *((player_plane.go)->target_rect)))
            {

                player_plane.hp-=enemy_bullet_damage;
                UpdateGui();
                enemy_bullet[i].free = true;
                return;
            }

            enemy_bullet[i].go->target_rect->y += 0.05;

            if (enemy_bullet[i].go->target_rect->y >= SCREEN_HEIGHT)
            {
                enemy_bullet[i].free = true;
            }
        }
    }
}

void updateBullet()
{
    _updatePlayerBullet();
    _updateEnemyBullet();
}

int renderBullet()
{

    for (size_t i = 0; i < PLAYER_BULLET_N; i++)
    {
        if (player_bullet[i].free)
            continue;
        renderGameObject(player_bullet[i].go);
    }

    for (size_t i = 0; i < ENEMY_BULLET_N; i++)
    {
        if (enemy_bullet[i].free)
            continue;
        renderGameObject(enemy_bullet[i].go);
    }

    return 0;
}

#endif