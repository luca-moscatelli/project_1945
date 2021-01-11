//Per dire a SDL che si usera' il proprio main applicativo.
//Altrimenti SDL cerca di caricare il main da SDL2Main.lib
//NOTA: Si può passare anche come argomento di compilazione con -D
#define SDL_MAIN_HANDLED

#include "game.h"

int main()
{

    init();

    while (!done)
    {
        

        play();
    }

    //Clean Up
    exitGame();

    return 0;
}