#define N_LIFE 3
#define RECT_LIFE_BAR_WIDTH SCREEN_WIDTH * 0.2f
#define RECT_LIFE_BAR_HEIGHT SCREEN_HEIGHT * 0.03f
#define RECT_LIFE_BAR_X SCREEN_HEIGHT * 0.03f
#define RECT_LIFE_BAR_Y SCREEN_HEIGHT * 0.03f



#ifndef GUI_MNG
#define GUI_MNG

#include "global_variables.h"
#include <stdlib.h>


game_object *gui;
game_object *life_icon[N_LIFE];
game_object *life_bar;

void GuiInit()
{
    SDL_Texture *tex = create_texture("resources/assets/ui/bottom.png");
    SDL_FRect *Frect = create_Frect(0, SCREEN_HEIGHT * 0.80f,SCREEN_WIDTH, SCREEN_HEIGHT * 0.20f);
    gui = create_gameObject(tex, NULL, Frect);

    tex = create_texture("resources/assets/ui/lifeBar.png");
    Frect = create_Frect(SCREEN_WIDTH * 0.017f, gui->target_rect->y + gui->target_rect->h * 0.575f,
                         RECT_LIFE_BAR_WIDTH, RECT_LIFE_BAR_HEIGHT);

    life_bar = create_gameObject(tex, NULL, Frect);

    for (size_t i = 0; i < N_LIFE; i++)
    {
        tex = create_texture("resources/assets/ui/life.png");
        Frect = create_Frect(SCREEN_WIDTH * 0.02f + (i * SCREEN_WIDTH * 0.07f), gui->target_rect->y + gui->target_rect->h * 0.20f,
                             global_unitSize.x, global_unitSize.y);
        life_icon[i] = create_gameObject(tex, NULL, Frect);
    }
}

void UpdateGui()
{

    life_bar->target_rect->w = RECT_LIFE_BAR_WIDTH * (player_plane.hp / MAX_HP);
}

void RenderGui()
{
    renderGameObject(gui);
    for (size_t i = 0; i < player_plane.life; i++)
    {
        renderGameObject(life_icon[i]);
    }
    renderGameObject(life_bar);
}

#endif