#define PLAYER_LIMIT_LEFT \
    SCREEN_HEIGHT * 0.01f
#define PLAYER_LIMIT_RIGHT \
    SCREEN_WIDTH - player_plane->go->target_rect->w - PLAYER_LIMIT_LEFT
#define PLAYER_LIMIT_UP \
    SCREEN_HEIGHT * 0.25f
#define PLAYER_LIMIT_DOWN \
    SCREEN_HEIGHT - gui->target_rect->h - player_plane->go->target_rect->h
#define PLAYER_RATIO_TIME 5.f
#define PLAYER_POWER_UP_RATIO_TIME 3.f
#define PLAYER_RESPAWN_TIME 150.f

#include "playerMng.h"
#include "player.h"
#include "GuiMng.h"

void playerInit(global_var *v)
{

    v->player_texture_plane = create_texture("resources/assets/player/myplane_strip3.png", v->global_renderer);
    v->player_texRect_plane = create_rect(0, 0, 65, 65);
    SDL_FRect *targetRect = create_Frect(SCREEN_WIDTH * 0.5f -UNIT_SIZE_X * 0.5f, SCREEN_HEIGHT * 0.65f, UNIT_SIZE_X, UNIT_SIZE_Y);

    for (size_t i = 0; i < 7; i++)
    {
        v->Player_explosionTexure_Rect[i] = create_rect(i * 65, 0, 65, 65);
    }

    v->player_plane = (type_player *)calloc(1, sizeof(type_player));

    v->player_plane->ExplosionTime = ENEMY_CONST_EXPLOSION_TIME;
    v->player_plane->respawn_time = PLAYER_RESPAWN_TIME;
    v->player_plane->state = player_live;
    v->player_plane->go = create_gameObject(v->player_texture_plane, v->player_texRect_plane, targetRect);
    v->player_plane->hp = 100;
    v->player_plane->life = 3;

    v->player_explosion_texture = create_texture("resources/assets/player/explosion2_strip7.png", v->global_renderer);
}

void _PlayerLive_Update(global_var *v)
{
    v->player_plane->player_ratioCont -= 0.01;

    if (v->player_plane->hp <= 0)
    {
        v->player_plane->go->texture = v->player_explosion_texture;
        v->player_plane->state = player_onDead;
        return;
    }
}

void _PlayerOndead_Update(type_player *player_plane)
{
    player_plane->ExplosionTime -= 0.05f;

    if (player_plane->ExplosionTime <= 0)
    {
        player_plane->state = player_dead;
    }
}

void _PlayerDead_Update(global_var *v)
{
    v->player_plane->respawn_time -= 0.03f;

    if (v->player_plane->respawn_time <= 0)
    {
        v->player_plane->life--;
        if (v->player_plane->life == 0)
        {
            v->done = true;
            return;
        }
        v->player_plane->hp = MAX_HP;
        v->player_plane->state = player_live;
        v->player_plane->go->texture = v->player_texture_plane;

        v->player_plane->go->texture_rect = v->player_texRect_plane;
        v->player_plane->go->texture_rect->x = 0;
        v->player_plane->go->texture_rect->y = 0;

        v->player_plane->ExplosionTime = ENEMY_CONST_EXPLOSION_TIME;
        v->player_plane->respawn_time = PLAYER_RESPAWN_TIME;

        v->player_plane->go->target_rect->x = SCREEN_WIDTH * 0.5f - UNIT_SIZE_X;
        v->player_plane->go->target_rect->y = SCREEN_HEIGHT * 0.65f;
        UpdateGui(v->player_plane);
    }
}

void UpdatePlayer(global_var* v)
{
    switch (v->player_plane->state)
    {
    case player_live:
        _PlayerLive_Update(v);
        break;

    case player_onDead:
        _PlayerOndead_Update(v->player_plane);
        break;

    case player_dead:
        _PlayerDead_Update(v);
        break;

    default:
        break;
    }
}

boolean MovePlayer(SDL_Keycode key,type_player* player_plane,game_object* gui)
{

    if (key == SDLK_LEFT)
    {
        if (player_plane->go->target_rect->x - 3 <= PLAYER_LIMIT_LEFT)
            return false;

        player_plane->go->target_rect->x -= 3;
        return true;
    }

    if (key == SDLK_RIGHT)
    {
        if (player_plane->go->target_rect->x + 3 >= PLAYER_LIMIT_RIGHT)
            return false;

        player_plane->go->target_rect->x += 3;
        return true;
    }
    if (key == SDLK_UP)
    {
        if (player_plane->go->target_rect->y - 3 <= PLAYER_LIMIT_UP)
            return false;

        player_plane->go->target_rect->y -= 3;
        return true;
    }
    if (key == SDLK_DOWN)
    {
        if (player_plane->go->target_rect->y + 3 >= PLAYER_LIMIT_DOWN)
            return false;

        player_plane->go->target_rect->y += 3;
        return true;
    }

    if (key == SDLK_e)
    {
        player_plane->hp -= 5;
        UpdateGui(player_plane);
        return true;
    }

    if (key == SDLK_t)
    {
        player_plane->life++;
        UpdateGui(player_plane);
        return true;
    }

    return false;
}

boolean ShootPlayer(SDL_KeyCode key,type_player* player,bullet_obj* player_bullet,Mix_Chunk* playerShoot_sound)
{

    if (key == SDLK_SPACE && player->player_ratioCont <= 0)
    {

        shoot_playerBullet(player_bullet,player,playerShoot_sound);
        player->player_ratioCont = PLAYER_RATIO_TIME;
        return true;
    }
    return false;
}