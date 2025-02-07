#include <iostream>

#include "Engine/Core/Entry.h"
#include "Engine/Core/Engine.h"
#include "Engine/Graphics/Window.h"
#include "Engine/Graphics/Renderer.h"

/*
Note that this is SDL3, not SDL2. SDL3 is the lastest official
version of SDL, and apparently it is "extremely well documented" and easier to use.
Here is a link to see new features in SDL3 as well as the documentation:
https://wiki.libsdl.org/SDL3/NewFeatures
*/

#include <SDL3_image/SDL_image.h>

#include <chrono>
#include <math.h>

unsigned long long get_time()
{
    return std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
}

int GameInit(int argc, char **argv)
{

    Engine::WinProps properties = {"Game", nullptr};
    Engine::Window *gameWindow = new Engine::Window(properties);

    Engine::Renderer *renderer = new Engine::Renderer(*gameWindow);

    SDL_Texture *t = IMG_LoadTexture(ren, "assets/test.png");
    SDL_FRect r = {0, 0, 80, 80};
    bool running = true;

    unsigned long long prev_time = get_time();

    float fpsAvg = 0;
    unsigned long long fpsCount = 0;

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

        SDL_SetRenderDrawColor(ren, 255, 255, 255, 255);

        float x, y = 0;
        int x1, y1 = 0;
        SDL_GetMouseState(&x, &y);
        SDL_GetWindowSize(win, &x1, &y1);

        r.x = x - 40; // Set the position of the texture to the mouse position
        r.y = y - 40;

        char n_char[6 + sizeof(char)];
        std::sprintf(n_char, "%d", (int)(fpsAvg / fpsCount));

        SDL_RenderDebugText(ren, 20, 20, n_char);
        SDL_RenderTexture(ren, t, NULL, &r);
        SDL_RenderLine(ren, x1 / 2, y1 / 2, x, y);
        SDL_RenderLine(ren, x1 / 2, y1 / 2, x1 / 2, y);
        SDL_RenderLine(ren, x1 / 2, y, x, y);

        SDL_RenderPresent(ren);

        unsigned long long current_time = get_time();
        unsigned long long delta_time = current_time - prev_time;
        prev_time = current_time;

        fpsAvg += 1.0 / (delta_time / 1e9);
        fpsCount++;

        if (fpsCount % 1000 == 0)
            std::cout << "FPS: " << fpsAvg / fpsCount << std::endl;
    }

    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(win);

    return 0;
}