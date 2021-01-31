//Per dire a SDL che si usera' il proprio main applicativo.
//Altrimenti SDL cerca di caricare il main da SDL2Main.lib
//NOTA: Si può passare anche come argomento di compilazione con -D
#define SDL_MAIN_HANDLED

#include "game.h"

int main()
{

   global_var* v= init();

    while (!v->done)
    {
        

        play(v);
    }

    //Clean Up
    exitGame(v);

    return 0;
}