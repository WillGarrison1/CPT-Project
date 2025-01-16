#include <iostream>

/*
Note that this is SDL3, not SDL2. SDL3 is the lastest official
version of SDL, and apparently it is "extremely well documented" and easier to use.
Here is a link to see new features in SDL3 as well as the documentation:
https://wiki.libsdl.org/SDL3/NewFeatures
*/
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

#include <SDL3_image/SDL_image.h>

int main(int argc, char *argv[])
{
    if (!SDL_Init(SDL_INIT_VIDEO))
    {
        std::cerr << "SDL_Init Error: " << SDL_GetError() << std::endl;
        return 1;
    }

    SDL_Window *win = SDL_CreateWindow("Hello World!", 640, 480, SDL_WINDOW_MOUSE_FOCUS | SDL_WINDOW_RESIZABLE);

    if (win == nullptr)
    {
        std::cerr << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }

    SDL_SetWindowPosition(win, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED);
    SDL_ShowWindow(win);

    SDL_Renderer *ren = SDL_CreateRenderer(win, NULL);

    if (ren == nullptr)
    {
        SDL_DestroyWindow(win);
        std::cerr << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }

    SDL_Texture *t = IMG_LoadTexture(ren, "assets/test.png");
    SDL_FRect r = {0, 0, 80, 80};
    bool running = true;

    

    while (running)
    {
        SDL_Event e;
        while (SDL_PollEvent(&e))
        {
            if (e.type == SDL_EVENT_QUIT)
                running = false;
            if (e.type == SDL_EVENT_KEY_DOWN && e.key.key == SDLK_ESCAPE)
                running = false;
            if (e.type == SDL_EVENT_WINDOW_CLOSE_REQUESTED && e.window.windowID == SDL_GetWindowID(win))
                running = false;
        }
        if (SDL_GetWindowFlags(win) & SDL_WINDOW_MINIMIZED)
        {
            SDL_Delay(10);
            continue;
        }

        SDL_SetRenderDrawColor(ren, 0, 0, 0, 255);
        SDL_RenderClear(ren);

        SDL_SetRenderDrawColor(ren, 255, 255, 255, 150);

        float x, y = 0;
        int x1, y1 = 0;
        SDL_GetMouseState(&x, &y);
        SDL_GetWindowSize(win, &x1, &y1);

        SDL_RenderDebugText(ren, 20, 20, "Hello World!");

        SDL_RenderTexture(ren, t, NULL, &r);
        SDL_RenderLine(ren, x1 / 2, y1 / 2, x, y);

        SDL_RenderPresent(ren);
    }

    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(win);
    SDL_Quit();

    return 0;
}