#define PLAYER_LIMIT_LEFT \
    SCREEN_HEIGHT * 0.01f
#define PLAYER_LIMIT_RIGHT \
    SCREEN_WIDTH - player_plane.go->target_rect->w - PLAYER_LIMIT_LEFT
#define PLAYER_LIMIT_UP \
    SCREEN_HEIGHT * 0.25f
#define PLAYER_LIMIT_DOWN \
    SCREEN_HEIGHT - gui->target_rect->h - player_plane.go->target_rect->h
#define PLAYER_RATIO_TIME 3.f


#ifndef PLAYER_MNG
#define PLAYER_MNG


#include "global_variables.h"
#include "SDL.h"

float player_ratioCont;

void playerInit()
{
    SDL_Texture *tex = create_texture("resources/assets/player/myplane_strip3.png");
    SDL_Rect *texRect = create_rect(0, 0, 195 / 3, 65);
    SDL_FRect *targetRect = create_Frect(SCREEN_WIDTH * 0.5f, SCREEN_HEIGHT * 0.65f, global_unitSize.x, global_unitSize.y);

    player_plane.go = create_gameObject(tex, texRect, targetRect);
    player_plane.hp = 100;
    player_plane.life = 3;
}

void UpdatePlayerCounter()
{
    player_ratioCont -= 0.01;
}


boolean MovePlayer(SDL_Keycode key)
{

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
        playerAddDamage(5);
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