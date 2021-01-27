#ifndef GAME
#define GAME

#include "SDL.h"
#include <SDL_mixer.h>
#include <SDL_ttf.h>
#include <SDL_image.h>
#include <stdlib.h>
#include "renderFunc.h"
#include "updateObj.h"
#include "playerMng.h"
#include <stdio.h>

void _initGameAsset()
{

    SDL_Texture *tex = create_texture("resources/assets/map/water.png");
    SDL_Rect *rect = create_rect(0, 0, 32, 32);
    SDL_FRect *frect = create_Frect(0, 0, global_unitSize.x, global_unitSize.y);
    water = create_gameObject(tex, rect, frect);

    tex = create_texture("resources/assets/map/island1.png");
    rect = NULL;
    frect = create_Frect(0, 0, global_unitSize.x * 1.5f, global_unitSize.y * 1.5f);
    island[0] = create_gameObject(tex, rect, frect);

    tex = create_texture("resources/assets/map/island2.png");
    rect = NULL;
    frect = create_Frect(120, 150, global_unitSize.x * 1.5f, global_unitSize.y * 1.5f);
    island[1] = create_gameObject(tex, rect, frect);

    tex = create_texture("resources/assets/map/island3.png");
    rect = NULL;
    frect = create_Frect(200, 200, global_unitSize.x * 1.5f, global_unitSize.y * 1.5f);

    island[2] = create_gameObject(tex, rect, frect);

    playerInit();
    bulletInit();
    GuiInit();
    enemyInit();
    powerUp_init();
}

boolean __exit_game(SDL_KeyCode key)
{
    if (key == SDLK_ESCAPE)
    {
        done = true;
        return true;
    }

    return false;
}

void _input()
{
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
        case SDL_QUIT:
            done = true;
            break;
        case SDL_KEYDOWN:

            if (player_plane.state == player_live)
            {

                if (MovePlayer(event.key.keysym.sym))
                    break;

                if (ShootPlayer(event.key.keysym.sym))
                    break;
            }

            if (__exit_game(event.key.keysym.sym))
                break;

            break;
        default:
            break;
        }

        if (event.type == SDL_QUIT)
            break;
    }
}

int init()
{
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Init(SDL_INIT_AUDIO);
    Mix_Init(MIX_INIT_OGG);
    Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, 1, 4096);

    background_music = Mix_LoadMUS("resources/assets/audio/background.mp3");

    Mix_VolumeMusic(70);

    Mix_PlayMusic(background_music, -1);

    Mix_Volume(-1, 20); //general volume
    Mix_Volume(2, 40);  //player bullet  volume

    unit_size_norm = (float)SCREEN_HEIGHT / 480.f;

    global_unitSize.x = 40 * unit_size_norm;
    global_unitSize.y = 40 * unit_size_norm;

    global_unitScreenWidth = SCREEN_WIDTH / global_unitSize.x;
    global_unitScreenHeight = SCREEN_HEIGHT / global_unitSize.y;

    global_window = SDL_CreateWindow(
        "Project “1945”",
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        SCREEN_WIDTH,
        SCREEN_HEIGHT,
        0);

    if (global_window == NULL)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Could not create window: %s\n", SDL_GetError());
        return 1;
    }

    global_renderer = SDL_CreateRenderer(global_window, -1, SDL_RENDERER_ACCELERATED);
    if (global_renderer == NULL)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Could not create renderer: %s\n", SDL_GetError());
        return 2;
    }

    curr_count = SDL_GetPerformanceCounter();
    last_count = curr_count;

    update_time = 0.f;
    time_counter = 0.f;

    last_count = curr_count;
    curr_count = SDL_GetPerformanceCounter();
    global_delta_time = (float)(curr_count - last_count) / ((float)SDL_GetPerformanceFrequency());

    done = false;

    // SDL_RWops* file = SDL_RWFromFile("resources/assets/extra/Icon.ico","r+");

    // SDL_Surface *icon = IMG_LoadICO_RW(file);

    SDL_Surface *icon = IMG_Load("resources/assets/extra/Icon.png");

    SDL_SetWindowIcon(global_window, icon);

    SDL_FreeSurface(icon);

    _initGameAsset();

    return 0;
}

void exitGame()
{
    SDL_DestroyRenderer(global_renderer);
    SDL_DestroyWindow(global_window);
    Mix_CloseAudio();
    Mix_Quit();
    SDL_Quit();
}

void play()
{
    // Clear
    SDL_SetRenderDrawColor(global_renderer, 0, 0, 0, 255);
    SDL_RenderClear(global_renderer);
    //--clear

    last_count = curr_count;
    curr_count = SDL_GetPerformanceCounter();
    global_delta_time = (float)(curr_count - last_count) / ((float)SDL_GetPerformanceFrequency());
    int fps = (int)(1.f / global_delta_time);

    update_time += global_delta_time;
    if (update_time >= 1.f)
    {
        update_time -= 1.f;
        sprintf_s(title, sizeof(title), "Project “1945”  Delta Time: %.4f - Fps: %d", global_delta_time, fps);
        SDL_SetWindowTitle(global_window, title);
    }

    _input(); //input

    update(); //update

    renderScene(); //renderized

    // Blit
    SDL_RenderPresent(global_renderer);
}

#endif