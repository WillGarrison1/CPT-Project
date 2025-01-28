#ifndef ENTRY_H
#define ENTRY_H

#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

extern int GameInit(int argc, char** argv);

int main(int argc, char** argv)
{

    if (!SDL_Init(SDL_INIT_VIDEO))
    {
        std::cerr << "SDL_Init Error: " << SDL_GetError() << std::endl;
        return 1;
    }

    int error = GameInit(argc, argv);

    if (error)
        return error;
    
    SDL_Quit();

    return 0;
}



#endif