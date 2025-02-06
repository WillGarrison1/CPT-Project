#include "Renderer.h"
#include "Engine/Scene/Component.h"

namespace Engine
{
    Renderer::Renderer()
    {
        scene = nullptr;
        renderer = SDL_CreateRenderer(NULL, NULL);
    }

    Renderer::Renderer(Window window)
    {
        renderer = SDL_CreateRenderer(window.getWindow(), NULL);
        if (window.getProps().vsync)
            SDL_SetRenderVSync(renderer, 1);
    }

    Renderer::~Renderer() { SDL_DestroyRenderer(renderer); }

    void Renderer::SetDrawColor(Color color) const
    {
        SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    }

    void Renderer::Clear() const
    {
        SDL_RenderClear(renderer);
    }

    void Renderer::RenderEntity(Entity *entity, bool recursive) const
    {
        Transform *tranform = static_cast<Transform *>(entity->getComponent<ComponentID::Transform>());
        Material *entityMat = static_cast<Material *>(entity->getComponent<ComponentID::Material>());

        // Render stuff here

        if (recursive)
        {
            for (Entity *child : entity->getChildren())
            {
                RenderEntity(child, true);
            }
        }
    }

    void Renderer::RenderScene() const
    {
        if (scene->root)
        {
        }
    }

    void Renderer::Update() const
    {
        if (scene)
            RenderScene();
        SDL_RenderPresent(renderer);
    }
}