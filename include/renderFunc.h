

#ifndef RENDER_FUNC
#define RENDER_FUNC

#include "global_variables.h"




int _renderSea(SDL_Texture *texture, SDL_Rect *texture_rect, SDL_FRect *target_rect,global_var* v);


void _setFrame(game_object *go,Uint32 plane_frame_n);


void _setPlaneFrame(global_var* v);


int _renderPlane(global_var* v);


int _renderIsland(game_object** island,SDL_Renderer* renderer);


int renderScene(global_var* v);


#endif