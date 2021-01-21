#define PLAYER_LIMIT_LEFT \
    SCREEN_HEIGHT * 0.01f
#define PLAYER_LIMIT_RIGHT \
    SCREEN_WIDTH - player_plane.go->target_rect->w - PLAYER_LIMIT_LEFT
#define PLAYER_LIMIT_UP \
    SCREEN_HEIGHT * 0.25f
#define PLAYER_LIMIT_DOWN \
    SCREEN_HEIGHT - gui->target_rect->h - player_plane.go->target_rect->h
#define PLAYER_RATIO_TIME 5.f
#define PLAYER_POWER_UP_RATIO_TIME 3.f
#define PLAYER_RESPAWN_TIME 150.f

#ifndef PLAYER_MNG
#define PLAYER_MNG

#include"playerMng.c"

void playerInit();


void UpdatePlayer();


boolean MovePlayer(SDL_Keycode key);

boolean ShootPlayer(SDL_KeyCode key);


#endif