#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480
#define STANDARD_VELOCITY (unit_size_norm * global_delta_time)
#define N_LIFE 3
#define MAX_HP 100.f

#define ENEMY_CONST_EXPLOSION_TIME 90.f
#define ENEMY_N 6




#include "global_variables.h"






SDL_Texture *create_texture(char *source_file)
{

    SDL_Surface *surface = IMG_Load(source_file);
    SDL_Texture *texture = SDL_CreateTextureFromSurface(global_renderer, surface);
    SDL_FreeSurface(surface);
    return texture;
}

SDL_Rect *create_rect(int x, int y, int w, int h)
{
    SDL_Rect *rect;
    rect = malloc(sizeof(SDL_Rect));
    rect->x = x;
    rect->y = y;
    rect->w = w;
    rect->h = h;

    return rect;
}

SDL_FRect *create_Frect(float x, float y, float w, float h)
{
    SDL_FRect *rect;
    rect = malloc(sizeof(SDL_FRect));
    rect->x = x;
    rect->y = y;
    rect->w = w;
    rect->h = h;
    return rect;
}

game_object *create_gameObject(SDL_Texture *texture, SDL_Rect *texture_rect, SDL_FRect *target_rect) 
{

    game_object *go = (game_object *)malloc(sizeof(game_object));

    go->texture = texture;
    go->texture_rect = texture_rect;
    go->target_rect = target_rect;
    go->collider_rect=NULL;

    return go;
}

void destroy_gameObject(game_object *go)
{

    free(go->target_rect);
    free(go->texture);
    free(go->texture_rect);
    free(go);
}

int RangedRandDemo(int range_min, int range_max)
{
    // Generate random numbers in the half-closed interval
    // [range_min, range_max). In other words,
    // range_min <= random number < range_max

    int u = (double)rand() / (RAND_MAX + 1) * (range_max - range_min) + range_min;
    return u;
}

boolean check_collision(SDL_FRect a, SDL_FRect b)
{
    float leftA, leftB;
    float rightA, rightB;
    float topA, topB;
    float bottomA, bottomB;

    leftA = a.x;
    rightA = a.x + a.w;
    topA = a.y;
    bottomA = a.y + a.h;

    leftB = b.x;
    rightB = b.x + b.w;
    topB = b.y;
    bottomB = b.y + b.h;

    if (bottomA <= topB)
    {
        return false;
    }
    if (topA >= bottomB)
    {
        return false;
    }
    if (rightA <= leftB)
    {
        return false;
    }
    if (leftA >= rightB)
    {
        return false;
    }
    return true;
}



int renderGameObject(game_object *go)
{
    SDL_RenderCopyF(global_renderer, go->texture, go->texture_rect, go->target_rect);
    return 0;
}

