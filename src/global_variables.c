
#include "SDL.h"

enum boolean_enum
{
    false,
    true
};
typedef unsigned char boolean;

typedef struct
{
    float x;
    float y;
} vec2;

typedef struct
{
    SDL_Texture *texture;
    SDL_Rect *texture_rect;
    SDL_FRect *target_rect;
} game_object;

typedef struct
{
    game_object *go;
    int finishPointY;
    float ExplosionTime;
    float hp;
    uint32_t life;

} type_player;

typedef struct
{
    SDL_Rect *texture_rect;
    SDL_FRect *target_rect;
} texture_rect;

vec2 global_unitSize = {40, 40};


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

//assets game variables

//texture



//--texture

//gameobj
game_object island[3];
game_object water;


type_player player_plane;


boolean _CheckPlayerLife()
{

    if (player_plane.hp <= 0)
    {
        player_plane.life--;
        if (player_plane.life == 0)
        {
            return true;
        }
        player_plane.hp=MAX_HP;
        return false;

    }
    return false;
}



void playerAddDamage(float damage){
    player_plane.hp-=damage;
    done=_CheckPlayerLife();
}


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




game_object* create_gameObject(SDL_Texture* texture,SDL_Rect* texture_rect,SDL_FRect* target_rect){

    game_object* go=(game_object*)malloc(sizeof(game_object));

    go->texture=texture;
    go->texture_rect=texture_rect;
    go->target_rect=target_rect;

    return go;
}

void destroy_gameObject(game_object* go){

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

