#define N_LIFE 3
#define RECT_LIFE_BAR_WIDTH SCREEN_WIDTH * 0.2f
#define RECT_LIFE_BAR_HEIGHT SCREEN_HEIGHT * 0.03f
#define RECT_LIFE_BAR_X SCREEN_HEIGHT * 0.03f
#define RECT_LIFE_BAR_Y SCREEN_HEIGHT * 0.03f



#ifndef GUI_MNG
#define GUI_MNG


#include "global_variables.h"
#include <stdlib.h>



void GuiInit(global_var* v);

void UpdateGui(type_player* player_plane);

void RenderGui(global_var* v);


#endif