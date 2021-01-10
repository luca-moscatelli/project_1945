#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480
#define N_LIFE 3
#define MAX_HP 100.f




#ifndef GLOBAL_VAR
#define GLOBAL_VAR

#include "global_variables.c"


//--gameboj


//end var

//common function


boolean _CheckPlayerLife();


void playerAddDamage(float damage);

SDL_Texture *create_texture(char *source_file);

SDL_Rect *create_rect(int x, int y, int w, int h);


SDL_FRect *create_Frect(float x, float y, float w, float h);




game_object* create_gameObject(SDL_Texture* texture,SDL_Rect* texture_rect,SDL_FRect* target_rect);

void destroy_gameObject(game_object* go);



int RangedRandDemo(int range_min, int range_max);

boolean check_collision(SDL_FRect a, SDL_FRect b);



int renderGameObject(game_object *go);


#endif