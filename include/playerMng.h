#define PLAYER_LIMIT_LEFT \
    SCREEN_HEIGHT * 0.01f
#define PLAYER_LIMIT_RIGHT \
    SCREEN_WIDTH - player_plane.go->target_rect->w - PLAYER_LIMIT_LEFT
#define PLAYER_LIMIT_UP \
    SCREEN_HEIGHT * 0.25f
#define PLAYER_LIMIT_DOWN \
    SCREEN_HEIGHT - gui->target_rect->h - player_plane.go->target_rect->h
#define PLAYER_RATIO_TIME 5.f
#define PLAYER_POWER_UP_RATIO_TIME 3.f
#define PLAYER_RESPAWN_TIME 150.f

#ifndef PLAYER_MNG
#define PLAYER_MNG

#include "global_variables.h"
#include <SDL_image.h>

float player_ratioCont;

SDL_Texture *texture_plane;
SDL_Rect *texRect_plane;

void playerInit()
{
    texture_plane = create_texture("resources/assets/player/myplane_strip3.png");
    texRect_plane = create_rect(0, 0, 195 / 3, 65);
    SDL_FRect *targetRect = create_Frect(SCREEN_WIDTH * 0.5f - global_unitSize.x * 0.5f, SCREEN_HEIGHT * 0.65f, global_unitSize.x, global_unitSize.y);

    for (size_t i = 0; i < 7; i++)
    {
        Player_explosionTexure_Rect[i] = create_rect(i * 65, 0, 65, 65);
    }

    player_plane.ExplosionTime = ENEMY_CONST_EXPLOSION_TIME;
    player_plane.respawn_time = PLAYER_RESPAWN_TIME;
    player_plane.state = player_live;
    player_plane.go = create_gameObject(texture_plane, texRect_plane, targetRect);
    player_plane.hp = 100;
    player_plane.life = 3;

    player_explosion_texture = create_texture("resources/assets/player/explosion2_strip7.png");
}

void PlayerLive_Update()
{
    player_ratioCont -= 0.01;

    if (player_plane.hp <= 0)
    {
        player_plane.go->texture = player_explosion_texture;
        player_plane.state = player_onDead;
        return;
    }
}

void PlayerOndead_Update()
{
    player_plane.ExplosionTime -= 0.05f;

    if (player_plane.ExplosionTime <= 0)
    {
        player_plane.state = player_dead;
    }
}

void PlayerDead_Update()
{
    player_plane.respawn_time -= 0.03f;

    if (player_plane.respawn_time <= 0)
    {
        player_plane.life--;
        if (player_plane.life == 0)
        {
            done = true;
            return;
        }
        player_plane.hp = MAX_HP;
        player_plane.state = player_live;
        player_plane.go->texture = texture_plane;

        player_plane.go->texture_rect = texRect_plane;
        player_plane.go->texture_rect->x = 0;
        player_plane.go->texture_rect->y = 0;

        player_plane.ExplosionTime = ENEMY_CONST_EXPLOSION_TIME;
        player_plane.respawn_time = PLAYER_RESPAWN_TIME;

        player_plane.go->target_rect->x = SCREEN_WIDTH * 0.5f - global_unitSize.x * 0.5f;
        player_plane.go->target_rect->y = SCREEN_HEIGHT * 0.65f;
        UpdateGui();
    }
}

void UpdatePlayer()
{
    switch (player_plane.state)
    {
    case player_live:
        PlayerLive_Update();
        break;

    case player_onDead:
        PlayerOndead_Update();
        break;

    case player_dead:
        PlayerDead_Update();
        break;

    default:
        break;
    }
}

boolean MovePlayer(SDL_Keycode key)
{
    if(player_plane.state!=player_live) return false;

    if (key == SDLK_LEFT)
    {
        if (player_plane.go->target_rect->x - 3 <= PLAYER_LIMIT_LEFT)
            return false;

        player_plane.go->target_rect->x -= 3;
        return true;
    }

    if (key == SDLK_RIGHT)
    {
        if (player_plane.go->target_rect->x + 3 >= PLAYER_LIMIT_RIGHT)
            return false;

        player_plane.go->target_rect->x += 3;
        return true;
    }
    if (key == SDLK_UP)
    {
        if (player_plane.go->target_rect->y - 3 <= PLAYER_LIMIT_UP)
            return false;

        player_plane.go->target_rect->y -= 3;
        return true;
    }
    if (key == SDLK_DOWN)
    {
        if (player_plane.go->target_rect->y + 3 >= PLAYER_LIMIT_DOWN)
            return false;

        player_plane.go->target_rect->y += 3;
        return true;
    }

    if (key == SDLK_e)
    {
        player_plane.hp-=5;
        UpdateGui();
        return true;
    }

    if (key == SDLK_ESCAPE)
    {
        done = true;
        return true;
    }

    return false;
}

boolean ShootPlayer(SDL_KeyCode key)
{
    if (key == SDLK_SPACE && player_ratioCont <= 0)
    {

        shoot_playerBullet();
        player_ratioCont = PLAYER_RATIO_TIME;
        return true;
    }
    return false;
}

#endif