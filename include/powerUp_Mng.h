

#ifndef POWER_UP_MNG
#define POWER_UP_MNG

#include "global_variables.h"
#include <stdlib.h>

typedef struct
{
    float hp;
    game_object *go; //life
    float finishPointY;
    float ExplosionTime;
    float shootCount;

} type_PowerUp;

type_PowerUp *power_up;

SDL_Texture *tex;

void powerUp_init()
{
    tex = create_texture("resources/assets/power_up/flame.png");

    SDL_Rect *tex_rect = create_rect(0, 0, 228, 321);
    SDL_FRect *target_rect = create_Frect(SCREEN_WIDTH * 0.5f, SCREEN_HEIGHT * 0.5f, global_unitSize.x*0.3f, global_unitSize.y*0.42f);

    power_up = (type_PowerUp *)calloc(1, sizeof(type_PowerUp));

    power_up->go = create_gameObject(tex, tex_rect, target_rect);

    return;
}

void Render_powerUp()
{
    renderGameObject(power_up->go);
}

void PowerUp_update()
{
}

#endif