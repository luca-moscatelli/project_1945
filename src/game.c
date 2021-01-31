

#include "SDL.h"
#include <SDL_mixer.h>
#include <SDL_ttf.h>
#include <SDL_image.h>
#include <stdlib.h>
#include "renderFunc.h"
#include "updateObj.h"
#include "playerMng.h"
#include "enemyMng.h"
#include <stdio.h>
#include "GuiMng.h"

void _initGameAsset(global_var *v)
{
    vec2 global_unitSize = vec2_new(v->global_unitSize.x, v->global_unitSize.y);

    SDL_Texture *tex = create_texture("resources/assets/map/water.png", v->global_renderer);
    SDL_Rect *rect = create_rect(0, 0, 32, 32);
    SDL_FRect *frect = create_Frect(0, 0, global_unitSize.x, global_unitSize.y);
    v->water = create_gameObject(tex, rect, frect);

    tex = create_texture("resources/assets/map/island1.png", v->global_renderer);
    rect = NULL;
    frect = create_Frect(0, 0, global_unitSize.x * 1.5f, global_unitSize.y * 1.5f);
    v->island[0] = create_gameObject(tex, rect, frect);

    tex = create_texture("resources/assets/map/island2.png", v->global_renderer);
    rect = NULL;
    frect = create_Frect(120, 150, global_unitSize.x * 1.5f, global_unitSize.y * 1.5f);
    v->island[1] = create_gameObject(tex, rect, frect);

    tex = create_texture("resources/assets/map/island3.png", v->global_renderer);
    rect = NULL;
    frect = create_Frect(200, 200, global_unitSize.x * 1.5f, global_unitSize.y * 1.5f);

    v->island[2] = create_gameObject(tex, rect, frect);
    playerInit(v);
    bulletInit(v);
    GuiInit(v);
    enemyInit(v);
    //  powerUp_init();
}

boolean __exit_game(SDL_KeyCode key, global_var *v)
{
    if (key == SDLK_ESCAPE)
    {

        v->done = true;
        return true;
    }

    return false;
}

void _input(global_var *v)
{
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
        case SDL_QUIT:
            v->done = true;
            break;
        case SDL_KEYDOWN:

            if (v->player_plane->state == player_live)
            {

                if (MovePlayer(event.key.keysym.sym, v->player_plane, v->gui))
                    break;

                if (ShootPlayer(event.key.keysym.sym, v->player_plane,v->player_bullet.bullets))
                    break;
            }

            if (__exit_game(event.key.keysym.sym, v))
                break;

            break;
        default:
            break;
        }

        if (event.type == SDL_QUIT)
            break;
    }
}

global_var *init()
{
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Init(SDL_INIT_AUDIO);
    Mix_Init(MIX_INIT_OGG);
    Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, 1, 4096);

    global_var *global_v = (global_var *)calloc(1, sizeof(global_var));

    global_v->background_music = Mix_LoadMUS("resources/assets/audio/background.mp3");

    Mix_VolumeMusic(70);

    Mix_PlayMusic(global_v->background_music, -1);

    Mix_Volume(-1, 20); //general volume
    Mix_Volume(2, 40);  //player bullet  volume

    global_v->unit_size_norm = (float)SCREEN_HEIGHT / 480.f;

    global_v->global_unitSize.x = 40 * global_v->unit_size_norm;
    global_v->global_unitSize.y = 40 * global_v->unit_size_norm;

    global_v->global_unitScreenWidth = SCREEN_WIDTH / global_v->global_unitSize.x;
    global_v->global_unitScreenHeight = SCREEN_HEIGHT / global_v->global_unitSize.y;

    global_v->global_window = SDL_CreateWindow(
        "Project “1945”",
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        SCREEN_WIDTH,
        SCREEN_HEIGHT,
        0);

    if (global_v->global_window == NULL)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Could not create window: %s\n", SDL_GetError());
        return NULL;
    }

    global_v->global_renderer = SDL_CreateRenderer(global_v->global_window, -1, SDL_RENDERER_ACCELERATED);
    if (global_v->global_renderer == NULL)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Could not create renderer: %s\n", SDL_GetError());
        return NULL;
    }

    global_v->curr_count = SDL_GetPerformanceCounter();
    global_v->last_count = global_v->curr_count;
    global_v->last_count = global_v->curr_count;
    global_v->curr_count = SDL_GetPerformanceCounter();
    global_v->global_delta_time = (float)(global_v->curr_count - global_v->last_count) / ((float)SDL_GetPerformanceFrequency());

    global_v->timePlaneFrame = 0.03f;

    global_v->CONST_timePlaneFrame = 0.07f;

    global_v->bgVelocity = 100.f;

    global_v->enemyVelocity=300.f;

    // SDL_RWops* file = SDL_RWFromFile("resources/assets/extra/Icon.ico","r+");

    // SDL_Surface *icon = IMG_LoadICO_RW(file);

    SDL_Surface *icon = IMG_Load("resources/assets/extra/Icon.png");

    global_v->enemy_bullet.damage=30;

    global_v->player_bullet.damage=30;


    SDL_SetWindowIcon(global_v->global_window, icon);

    SDL_FreeSurface(icon);

    _initGameAsset(global_v);

    return global_v;
}

void exitGame(global_var *v)
{
    SDL_DestroyRenderer(v->global_renderer);
    SDL_DestroyWindow(v->global_window);
    Mix_CloseAudio();
    Mix_Quit();
    SDL_Quit();
}

void play(global_var *v)
{
    // Clear
    SDL_SetRenderDrawColor(v->global_renderer, 0, 0, 0, 255);
    SDL_RenderClear(v->global_renderer);
    //--clear

    v->last_count = v->curr_count;
    v->curr_count = SDL_GetPerformanceCounter();
    v->global_delta_time = (float)(v->curr_count - v->last_count) / ((float)SDL_GetPerformanceFrequency());
    int fps = (int)(1.f / v->global_delta_time);

    v->update_time += v->global_delta_time;
    if (v->update_time >= 1.f)
    {
        v->update_time -= 1.f;
        sprintf_s(v->title, sizeof(v->title), "Project “1945”  Delta Time: %.4f - Fps: %d", v->global_delta_time, fps);
        SDL_SetWindowTitle(v->global_window, v->title);
    }

    _input(v); //input

    update(v); //update

    renderScene(v); //renderized

    // Blit
    SDL_RenderPresent(v->global_renderer);
}
