#include <iostream>

/*
Note that this is SDL3, not SDL2. SDL3 is the lastest official
version of SDL, and apparently it is "extremely well documented" and easier to use.
Here is a link to see new features in SDL3 as well as the documentation:
https://wiki.libsdl.org/SDL3/NewFeatures
*/
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

int main(int argc, char *argv[])
{
    if (!SDL_Init(SDL_INIT_VIDEO))
    {
        std::cerr << "SDL_Init Error: " << SDL_GetError() << std::endl;
        return 1;
    }

    SDL_Window *win = SDL_CreateWindow("Hello World!", 640, 480, SDL_WINDOW_MOUSE_FOCUS);

    if (win == nullptr)
    {
        std::cerr << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }

    SDL_Renderer *ren = SDL_CreateRenderer(win, NULL);

    if (ren == nullptr)
    {
        SDL_DestroyWindow(win);
        std::cerr << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }

    while (true)
    {
        SDL_Event e;
        if (SDL_PollEvent(&e))
        {
            if (e.type == SDL_EVENT_QUIT)
            {
                break;
            }
        }

        SDL_SetRenderDrawColor(ren, 0, 0, 0, 255);
        SDL_RenderClear(ren);

        SDL_RenderPresent(ren);
    }

    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(win);
    SDL_Quit();

    return 0;
}