#pragma once

#include <SDL3/SDL.h>

#include "Window.h"
#include "Color.h"

namespace Engine
{
    class Renderer
    {
    public:
        Renderer() = default;
        ~Renderer() = default;

        Renderer(Window window);
        ~Renderer();
        
        void SetDrawColor(Color color) const;
        void Clear() const;
        void Update() const;

    private:
        SDL_Renderer* renderer;
    };
}