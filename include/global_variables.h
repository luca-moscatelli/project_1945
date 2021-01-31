
#ifndef GLOBAL_VAR
#define GLOBAL_VAR

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480
#define STANDARD_VELOCITY (v->unit_size_norm * v->global_delta_time)
#define N_LIFE 3
#define MAX_HP 100.f

#define ENEMY_CONST_EXPLOSION_TIME 90.f
#define ENEMY_N 6

#include <SDL_image.h>
#include <SDL_mixer.h>
#include <stdlib.h>
#include "vec2.h"
#include "player.h"
#include "bullet.h"
#include "enemy.h"

typedef struct
{
    vec2 global_unitSize;

    float unit_size_norm;

    int global_unitScreenWidth;
    int global_unitScreenHeight;
    float global_delta_time;

    Uint64 curr_count;
    Uint64 last_count;

    char title[100];
    float update_time;
    float time_counter;
    boolean done;

    SDL_Renderer *global_renderer;

    SDL_Window *global_window;

    Mix_Music *background_music;

    //assets game variables

    //texture

    SDL_Texture *player_explosion_texture;
    SDL_Rect *Player_explosionTexure_Rect[7];
    SDL_Rect *Enemy_explosionTexure_Rect[6];

    SDL_Texture *player_texture_plane;
    SDL_Rect *player_texRect_plane;

    type_player *player_plane;

    type_enemy *enemies;

    group_bullet player_bullet;

    group_bullet enemy_bullet;

    Mix_Chunk *shoot_player_sound;

    game_object *gui;

    //--texture

    //gameobj
    game_object *island[3];
    game_object *water;

    Uint32 plane_frame_n;

    float timePlaneFrame;

    float CONST_timePlaneFrame;

    float offset_background;

    float bgVelocity;

    float enemyVelocity;
    SDL_Texture *enemyPlane_texture[3];
    SDL_Texture *enemyExplosion_texture;
    //SDL_Rect *Enemy_explosionTexure_Rect[6];
    boolean *column;
    Mix_Chunk *enemy_explosion_sound;

} global_var;

SDL_Texture *create_texture(char *source_file, SDL_Renderer *renderer);

SDL_Rect *create_rect(int x, int y, int w, int h);

SDL_FRect *create_Frect(float x, float y, float w, float h);

game_object *create_gameObject(SDL_Texture *texture, SDL_Rect *texture_rect, SDL_FRect *target_rect);

void destroy_gameObject(game_object *go);

int RangedRandDemo(int range_min, int range_max);

boolean check_collision(SDL_FRect a, SDL_FRect b);

int renderGameObject(game_object *go, SDL_Renderer *renderer);

#endif