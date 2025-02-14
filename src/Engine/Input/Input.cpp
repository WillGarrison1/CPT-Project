#include "Input.h"

#include <SDL3/SDL_keyboard.h>
#include <SDL3/SDL_Events.h>
#include <memory>

namespace Engine
{
    Input::Input()
    {
        for (int i = 0; i < 84; i++)
            keyboard[i] = false;

        mousePos = Vector2<float>();
        mouse[0] = false;
        mouse[1] = false;
        mouse[2] = false;
    }

    Input::~Input()
    {
        delete mouse;
        delete keyboard;
    }

    void Input::Update()
    {

        const bool *keys = SDL_GetKeyboardState(nullptr);

        std::copy(keys, keys + 84, keyboard);

        SDL_MouseButtonFlags mouseFlags = SDL_GetMouseState(&mousePos.x, &mousePos.y);

        mouse[0] = mouseFlags & 1;
        mouse[1] = mouseFlags & 2;
        mouse[2] = mouseFlags & 4;
    }
}