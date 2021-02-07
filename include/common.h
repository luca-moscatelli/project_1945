#ifndef COMMON_H
#define COMMON_H

#include "SDL.h"


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



#endif