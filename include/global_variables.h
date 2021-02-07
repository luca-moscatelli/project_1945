
#ifndef GLOBAL_VAR
#define GLOBAL_VAR

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480
#define UNIT_SIZE_NORM (SCREEN_HEIGHT/SCREEN_HEIGHT)
#define UNIT_SIZE_X (float)(40*UNIT_SIZE_NORM)
#define UNIT_SIZE_Y (float)(40*UNIT_SIZE_NORM)
#define UNIT_SCREEN_WIDTH (int)(SCREEN_WIDTH/UNIT_SIZE_X)
#define UNIT_SCREEN_HEIGHT (int)(SCREEN_HEIGHT/UNIT_SIZE_Y)


#define STANDARD_VELOCITY (UNIT_SIZE_NORM * v->global_delta_time)
#define N_LIFE 3
#define MAX_HP 100.f





#include <SDL_image.h>
#include <SDL_mixer.h>
#include <stdlib.h>
#include "vec2.h"
#include "player.h"
#include "bullet.h"
#include "enemy.h"
#include "struct_global.h"

typedef struct
{
   
    //variables gameEngine
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

    //----------------------

    //assets game variables

    //texture

    SDL_Texture *player_explosion_texture;
    SDL_Texture *enemyPlane_texture[3];
    SDL_Texture *enemyExplosion_texture;
    SDL_Texture *player_texture_plane;
    SDL_Texture *ricardo_texture;

    //rect
    SDL_Rect *Player_explosionTexure_Rect[7];
    SDL_Rect *Enemy_explosionTexure_Rect[6];
    SDL_Rect *player_texRect_plane;

    boolean Enemy_Column_State[UNIT_SCREEN_WIDTH]; //true is free false is locked 

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

    boolean first;

    int nemesis_destroy;
    //SDL_Rect *Enemy_explosionTexure_Rect[6];
    boolean *column;
    Mix_Chunk *enemy_explosion_sound;

    physicsMng_var* physics;




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