
#ifndef GLOBAL_VAR
#define GLOBAL_VAR


#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480
#define STANDARD_VELOCITY (unit_size_norm * global_delta_time)
#define N_LIFE 3
#define MAX_HP 100.f

#define ENEMY_CONST_EXPLOSION_TIME 90.f
#define ENEMY_N 6



#include <SDL_image.h>
#include <SDL_mixer.h>
#include <stdlib.h>
#include "vec2.h"




enum boolean_enum
{
    false,
    true
};
typedef unsigned char boolean;



typedef struct
{
    SDL_Texture *texture;
    SDL_Rect *texture_rect;
    SDL_FRect *target_rect;
    SDL_FRect *collider_rect;
} game_object;



typedef struct
{
    SDL_Rect *texture_rect;
    SDL_FRect *target_rect;
} texture_rect;

vec2 global_unitSize;

float unit_size_norm;

int global_unitScreenWidth = 0;
int global_unitScreenHeight = 0;
float global_delta_time = 0;

Uint64 curr_count = 0;
Uint64 last_count = 0;

char title[100];
float update_time = 0.f;
float time_counter = 0.f;
boolean done = false;

SDL_Renderer *global_renderer;

SDL_Window *global_window;

Mix_Music *background_music;

//assets game variables

//texture

SDL_Texture *player_explosion_texture;
SDL_Rect *Player_explosionTexure_Rect[7];
SDL_Rect *Enemy_explosionTexure_Rect[6];

game_object *gui;








//--texture

//gameobj
game_object* island[3];
game_object* water;





SDL_Texture *create_texture(char *source_file);


SDL_Rect *create_rect(int x, int y, int w, int h);

SDL_FRect *create_Frect(float x, float y, float w, float h);


game_object *create_gameObject(SDL_Texture *texture, SDL_Rect *texture_rect, SDL_FRect *target_rect); 


void destroy_gameObject(game_object *go);


int RangedRandDemo(int range_min, int range_max);


boolean check_collision(SDL_FRect a, SDL_FRect b);




int renderGameObject(game_object *go);


#endif