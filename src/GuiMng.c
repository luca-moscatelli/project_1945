
 #include "GuiMng.h"
// #include "global_variables.h"
// #include "player.h"
// #include <stdlib.h>


static game_object *life_icon[N_LIFE];
static game_object *life_bar;

void GuiInit(global_var *v)
{
    SDL_Texture *tex = create_texture("resources/assets/ui/bottom.png",v->global_renderer);
    SDL_FRect *Frect = create_Frect(0, SCREEN_HEIGHT * 0.80f,SCREEN_WIDTH, SCREEN_HEIGHT * 0.20f);
    v->gui = create_gameObject(tex, NULL, Frect);

    tex = create_texture("resources/assets/ui/lifeBar.png",v->global_renderer);
    Frect = create_Frect(SCREEN_WIDTH * 0.017f, v->gui->target_rect->y + v->gui->target_rect->h * 0.575f,
                         RECT_LIFE_BAR_WIDTH, RECT_LIFE_BAR_HEIGHT);

    life_bar = create_gameObject(tex, NULL, Frect);

    for (size_t i = 0; i < N_LIFE; i++)
    {
        tex = create_texture("resources/assets/ui/life.png",v->global_renderer);
        Frect = create_Frect(SCREEN_WIDTH * 0.02f + (i * SCREEN_WIDTH * 0.07f), v->gui->target_rect->y + v->gui->target_rect->h * 0.20f,
                             (float)UNIT_SIZE_X,UNIT_SIZE_Y);
        life_icon[i] = create_gameObject(tex, NULL, Frect);
    }
}

void UpdateGui(type_player* player_plane)
{

    life_bar->target_rect->w = RECT_LIFE_BAR_WIDTH * (player_plane->hp / MAX_HP);
}

void RenderGui(global_var* v)
{
    renderGameObject(v->gui,v->global_renderer);
    for (size_t i = 0; i < v->player_plane->life; i++)
    {
        renderGameObject(life_icon[i],v->global_renderer);
    }
    renderGameObject(life_bar,v->global_renderer);
}

