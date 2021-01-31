#define PLAYER_BULLET_N 30
#define ENEMY_BULLET_N 30
#define PLAYER_BULLET_VELOCITY 250.f
#define BULLET_ENEMY_VELOCITY 200.f

#include "bulletMng.h"
#include "enemy.h"
#include "player.h"
#include "GuiMng.h"

void bulletInit(global_var *v)
{

    vec2 global_unitSize = v->global_unitSize;
    SDL_Renderer* renderer=v->global_renderer;

    //init vector bullet player-------
    v->player_bullet.bullets = (bullet_obj *)malloc(sizeof(bullet_obj) * PLAYER_BULLET_N);
    bullet_obj *player_bullet = v->player_bullet.bullets;
    
    SDL_Texture *tex = create_texture("resources/assets/player/bullet.png", renderer);
    SDL_Rect *rect_Tex = create_rect(12, 5, 20, 20);

    for (size_t i = 0; i < PLAYER_BULLET_N; i++)
    {
        SDL_FRect *target_Rect = create_Frect(-100, -100, global_unitSize.x * 0.5f, global_unitSize.y * 0.5f);
        player_bullet[i].go = create_gameObject(tex, rect_Tex, target_Rect);
        player_bullet[i].free = true;
    }
    //--------------------------------

    //init vector bullet enemies-------
    v->enemy_bullet.bullets = (bullet_obj *)malloc(sizeof(bullet_obj) * ENEMY_BULLET_N);
    bullet_obj *enemy_bullet = v->enemy_bullet.bullets;
    
    tex = create_texture("resources/assets/enemy/enemybullet1.png", renderer);
    rect_Tex = create_rect(12, 5, 20, 20);

    for (size_t i = 0; i < ENEMY_BULLET_N; i++)
    {
        SDL_FRect *target_Rect = create_Frect(-100, -100, global_unitSize.x * 0.5f, global_unitSize.y * 0.5f);
        enemy_bullet[i].go = create_gameObject(tex, rect_Tex, target_Rect);
        enemy_bullet[i].free = true;
    }
    //--------------------------------
    v->shoot_player_sound = Mix_LoadWAV("resources/assets/audio/snd_explosion1.wav"); //load explosion sound
}

void shoot_playerBullet(bullet_obj *player_bullet, type_player *player_plane)
{

    for (size_t i = 0; i < PLAYER_BULLET_N; i++)
    {
        if (player_bullet[i].free)
        {
            //  Mix_PlayChannel(2, shoot_player_sound, 0);
            //  Mix_ExpireChannel(2,100);
            player_bullet[i]
                .go->target_rect->x = player_plane->go->target_rect->x + player_plane->go->target_rect->w * 0.16f + player_bullet[i].go->target_rect->w * 0.5f;
            player_bullet[i].go->target_rect->y = player_plane->go->target_rect->y - 30;
            player_bullet[i].free = false;
            return;
        }
    }
}

void shoot_enemyBullet(void *enemy, bullet_obj *enemy_bullet)
{
    type_enemy *e = (type_enemy *)enemy;

    for (size_t i = 0; i < 30; i++)
    {
        if (enemy_bullet[i].free)
        {
            enemy_bullet[i].go->target_rect->x = e->go->target_rect->x + e->go->target_rect->w * 0.16f + enemy_bullet[i].go->target_rect->w * 0.5f;
            enemy_bullet[i].go->target_rect->y = e->go->target_rect->y + 30;
            enemy_bullet[i].free = false;
            return;
        }
    }
}

void _updatePlayerBullet(group_bullet type_bullet_player, group_bullet type_bullet_enemy, type_enemy *enemy, float norm_velocity)
{
    for (size_t i = 0; i < PLAYER_BULLET_N; i++)
    {
        if (!type_bullet_player.bullets[i].free)
        {
            for (size_t j = 0; j < ENEMY_N; j++)
            {
                if (check_collision(*((type_bullet_player.bullets[i]).go)->target_rect, *((enemy[j].go)->target_rect)))
                {
                    if (enemy[j].state != dead)
                    {
                        enemy[j].hp -= type_bullet_player.damage;
                        type_bullet_player.bullets[i].free = true;
                        return;
                    }
                }
            }

            for (size_t j = 0; j < ENEMY_BULLET_N; j++)
            {
                if (check_collision(*((type_bullet_player.bullets[i]).go)->target_rect, *((type_bullet_enemy.bullets[j].go)->target_rect)))
                {
                    type_bullet_enemy.bullets[j].free = true;
                    type_bullet_player.bullets[i].free = true;
                    return;
                }
            }

            type_bullet_player.bullets[i].go->target_rect->y -= PLAYER_BULLET_VELOCITY * norm_velocity;

            if (type_bullet_player.bullets[i].go->target_rect->y <= -30)
            {
                type_bullet_player.bullets[i].free = true;
            }
        }
    }
}

void __checkFreeBullet(bullet_obj *bullet_type, int N_bullet)
{
    for (size_t i = 0; i < N_bullet; i++)
    {
        if (bullet_type[i].free)
        {
            bullet_type[i].go->target_rect->y = SCREEN_HEIGHT + 100;
        }
    }
}

void _updateGenericBullet(bullet_obj *enemy_bullet, bullet_obj *player_bullet)
{
    __checkFreeBullet(enemy_bullet, ENEMY_BULLET_N);
    __checkFreeBullet(player_bullet, PLAYER_BULLET_N);
}

void _updateEnemyBullet(bullet_obj *enemy_bullet, float enemy_bullet_damage, type_player *player_plane, float std_velocity)
{
    for (size_t i = 0; i < ENEMY_BULLET_N; i++)
    {
        if (!enemy_bullet[i].free)
        {

            if (check_collision(*((enemy_bullet[i]).go)->target_rect, *((player_plane->go)->target_rect)))
            {

                player_plane->hp -= enemy_bullet_damage;
                UpdateGui(player_plane);
                enemy_bullet[i].free = true;
                return;
            }

            enemy_bullet[i].go->target_rect->y += BULLET_ENEMY_VELOCITY * std_velocity;

            if (enemy_bullet[i].go->target_rect->y >= SCREEN_HEIGHT)
            {
                enemy_bullet[i].free = true;
            }
        }
    }
}

void updateBullet(group_bullet type_bullet_player, group_bullet type_bullet_enemy, type_enemy *enemy, float norm_velocity, type_player *player)
{
    _updateGenericBullet(type_bullet_enemy.bullets, type_bullet_player.bullets);
    _updatePlayerBullet(type_bullet_player, type_bullet_enemy, enemy, norm_velocity);
    _updateEnemyBullet(type_bullet_enemy.bullets, type_bullet_enemy.damage, player, norm_velocity);
}

int renderBullet(SDL_Renderer *renderer, bullet_obj *enemy_bullet, bullet_obj *player_bullet)
{

    for (size_t i = 0; i < PLAYER_BULLET_N; i++)
    {
        if (player_bullet[i].free)
            continue;
        renderGameObject(player_bullet[i].go, renderer);
    }

    for (size_t i = 0; i < ENEMY_BULLET_N; i++)
    {
        if (enemy_bullet[i].free)
            continue;
        renderGameObject(enemy_bullet[i].go, renderer);
    }

    return 0;
}
