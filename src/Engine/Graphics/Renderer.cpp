#include "Renderer.h"

namespace Engine
{
    Renderer::Renderer()
    {
        renderer = SDL_CreateRenderer(NULL, NULL);
    }

    Renderer::Renderer(Window window)
    {
        renderer = SDL_CreateRenderer(window.getWindow(), NULL);
        if(window.getProps().vsync) SDL_SetRenderVSync(renderer, 1);
    }

    Renderer::~Renderer() { SDL_DestroyRenderer(renderer); }

    void Renderer::SetDrawColor(Color color) const
    {
        SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    }

    void Renderer::Clear() const {
        SDL_RenderClear(renderer);
    }

    void Renderer::Update() const 
    {
        SDL_RenderPresent(renderer);
    }
}