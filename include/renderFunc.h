

#ifndef RENDER_FUNC
#define RENDER_FUNC

#include "global_variables.h"
#include "enemyMng.h"
#include "bulletMng.h"
#include "GuiMng.h"
#include "powerUp_Mng.h"

Uint32 plane_frame_n = 0;

float timePlaneFrame = 0.03f;

const float CONST_timePlaneFrame = 0.07f;

int _renderSea(SDL_Texture *texture, SDL_Rect *texture_rect, SDL_FRect *target_rect)
{
    SDL_FRect rect;

    rect.x = target_rect->x;
    rect.y = target_rect->y;
    rect.h = target_rect->h;
    rect.w = target_rect->w;

    while (rect.x <= SCREEN_WIDTH)
    {
        while (rect.y <= SCREEN_HEIGHT)
        {
            SDL_RenderCopyF(global_renderer, texture, texture_rect, &rect);

            rect.y += global_unitSize.y;
        }

        rect.x += global_unitSize.x;
        rect.y = target_rect->y;
    }

    return 0;
}

int __renderIsland(SDL_Texture *texture, SDL_Rect *texture_rect, SDL_FRect *target_rect)
{

    SDL_RenderCopyF(global_renderer, texture, NULL, target_rect);

    return 0;
}

void _setFrame(game_object *go)
{
    if (plane_frame_n == 0)
    {
        go->texture_rect->x = 0;
        return;
    }

    if (plane_frame_n == 1)
    {
        go->texture_rect->x = go->texture_rect->w * 1;
        return;
    }

    if (plane_frame_n == 2)
    {
        go->texture_rect->x = go->texture_rect->w * 2;
        return;
    }
}

void _setPlaneFrame()
{

    if (plane_frame_n == 0)
    {

        plane_frame_n = 1;
        return;
    }

    if (plane_frame_n == 1)
    {

        plane_frame_n = 2;
        return;
    }

    if (plane_frame_n == 2)
    {
        plane_frame_n = 0;
        return;
    }
}

int _renderPlane()
{

    if (timePlaneFrame <= 0)
    {
        _setPlaneFrame();

        timePlaneFrame = CONST_timePlaneFrame;
    }

    if (player_plane.state == player_live)
    {
        _setFrame(player_plane.go);
    }
    if (player_plane.state == player_onDead)
    {
        _SetFrameExplosion(player_plane.go, player_plane.ExplosionTime, Player_explosionTexure_Rect);
    }

    for (size_t i = 0; i <  ENEMY_N; i++)
    {
        if (enemy[i].state == dead)
        {
            _SetFrameExplosion(enemy[i].go, enemy[i].ExplosionTime, Enemy_explosionTexure_Rect);
            continue;
        }
        _setFrame(enemy[i].go);
    }

    if (player_plane.state != player_dead)
    {
        renderGameObject(player_plane.go);
    }

    timePlaneFrame -= global_delta_time;

    return 0;
}

int _renderIsland()
{

    for (size_t i = 0; i < 3; i++)
    {
        __renderIsland(island[i].texture, NULL, island[i].target_rect);
    }

    return 0;
}

int renderScene()
{
    //order to render

    _renderSea(water.texture, water.texture_rect, water.target_rect); //1
    _renderIsland();                                                  //2
    _renderPlane();                                                   //3
    renderEnemy();
    renderBullet();
  //  Render_powerUp();
    RenderGui();
    return 0;
}

#endif