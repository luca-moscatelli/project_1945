

#include "enemyMng.h"
#include "powerUp_Mng.h"
#include "GuiMng.h"
#include "renderFunc.h"

int _renderSea(SDL_Texture *texture, SDL_Rect *texture_rect, SDL_FRect *target_rect, global_var *v)
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
            SDL_RenderCopyF(v->global_renderer, texture, texture_rect, &rect);

            rect.y += v->global_unitSize.y;
        }

        rect.x += v->global_unitSize.x;
        rect.y = target_rect->y;
    }

    return 0;
}

void _setFrame(game_object *go, Uint32 plane_frame_n)
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

void _setPlaneFrame(global_var *v)
{
    Uint32 plane_frame_n = v->plane_frame_n;

    if (plane_frame_n == 0)
    {

        v->plane_frame_n = 1;
        return;
    }

    if (plane_frame_n == 1)
    {

        v->plane_frame_n = 2;
        return;
    }

    if (plane_frame_n == 2)
    {
        v->plane_frame_n = 0;
        return;
    }
}

void _SetFrameExplosion(game_object *go, float ExplosionTime, SDL_Rect *explosionTexure_Rect[])
{

    int index = 0;

    boolean set = false;

    if (ExplosionTime >= ENEMY_CONST_EXPLOSION_TIME * (0.83f) && !set)
    {
        index = 0;
        set = true;
    }
    if (ExplosionTime >= ENEMY_CONST_EXPLOSION_TIME * (0.66f) && !set)
    {
        index = 1;
        set = true;
    }
    if (ExplosionTime >= ENEMY_CONST_EXPLOSION_TIME * (0.50f) && !set)
    {
        index = 2;
        set = true;
    }
    if (ExplosionTime >= ENEMY_CONST_EXPLOSION_TIME * (0.33f) && !set)
    {
        index = 3;
        set = true;
    }
    if (ExplosionTime >= ENEMY_CONST_EXPLOSION_TIME * (0.16f) && !set)
    {
        index = 4;
        set = true;
    }

    if (!set)
    {
        index = 5;
    }

    go->texture_rect->h = explosionTexure_Rect[index]->h;
    go->texture_rect->w = explosionTexure_Rect[index]->w;
    go->texture_rect->x = explosionTexure_Rect[index]->x;
    go->texture_rect->y = explosionTexure_Rect[index]->y;
    return;
}

int _renderPlane(global_var *v)
{
    type_player *player_plane = v->player_plane;

    type_enemy *enemies = v->enemies;

    if (v->timePlaneFrame <= 0)
    {
        _setPlaneFrame(v);

        v->timePlaneFrame = v->CONST_timePlaneFrame;
    }

    if (player_plane->state == player_live)
    {
        _setFrame(player_plane->go, v->plane_frame_n);
    }
    if (player_plane->state == player_onDead)
    {
        _SetFrameExplosion(player_plane->go, player_plane->ExplosionTime, v->Player_explosionTexure_Rect);
    }

    for (size_t i = 0; i < ENEMY_N; i++)
    {
        if (enemies[i].state == dead)
        {
            _SetFrameExplosion(enemies[i].go, enemies[i].ExplosionTime, v->Enemy_explosionTexure_Rect);
            continue;
        }
        _setFrame(enemies[i].go, v->plane_frame_n);
    }

    if (player_plane->state != player_dead)
    {
        renderGameObject(player_plane->go, v->global_renderer);
    }

    v->timePlaneFrame -= v->global_delta_time;

    return 0;
}

int _renderIsland(game_object **island, SDL_Renderer *renderer)
{

    for (size_t i = 0; i < 3; i++)
    {
        renderGameObject(island[i], renderer);
    }

    return 0;
}

int renderScene(global_var* v)
{
    game_object* water=v->water;

    _renderSea(water->texture, water->texture_rect, water->target_rect,v); //1
    _renderIsland(v->island,v->global_renderer);                                                     //2
    _renderPlane(v);                                                      //3
    renderEnemy(v);
    renderBullet(v->global_renderer,v->enemy_bullet.bullets,v->player_bullet.bullets);
    //  Render_powerUp();
    RenderGui(v);
    return 0;
}
