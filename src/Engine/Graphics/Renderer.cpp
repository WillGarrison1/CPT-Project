#include "Renderer.h"
#include "Engine/Scene/Component.h"
#include <SDL3_image/SDL_image.h>

namespace Engine
{
    Renderer::Renderer()
    {
        scene = nullptr;
        renderer = SDL_CreateRenderer(NULL, NULL);
    }

    Renderer::Renderer(Window *window)
    {
        renderer = SDL_CreateRenderer(window->getWindow(), NULL);
        if (window->getProps().vsync)
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

    void Renderer::RenderEntity(Entity *entity, bool recursive, Vector2<float> parent, Camera *camera) const
    {

        if (entity->hasComponent<ComponentID::Transform>() && entity->hasComponent<ComponentID::Material>())
        {

            Transform *cameraTransform = static_cast<Transform *>(camera->getComponent<ComponentID::Transform>());

            Transform *transform = static_cast<Transform *>(entity->getComponent<ComponentID::Transform>());
            Material *entityMat = static_cast<Material *>(entity->getComponent<ComponentID::Material>());

            ASSERT(transform != nullptr);
            ASSERT(entityMat != nullptr);
            ASSERT(entityMat->texture != nullptr);

            // Render stuff here
            parent = transform->position + parent;

            Vector2<float> screenPos = parent - cameraTransform->position;

            float width, height; // should probably store the image dimensions in material struct
            SDL_GetTextureSize(entityMat->texture, &width, &height);
            SDL_FRect dest = {screenPos.x - width / 2, screenPos.y - height / 2, width, height};

            SDL_RenderTexture(renderer, entityMat->texture, NULL, &dest);
        }
        if (recursive)
        {
            for (Entity *child : entity->getChildren())
            {
                RenderEntity(child, true, parent, camera);
            }
        }
    }

    void Renderer::RenderScene() const
    {
        if (!scene->root)
            return;

        Camera *sceneCamera = scene->getCamera();

        if (!sceneCamera)
            return;

        RenderEntity(scene->root, true, {0, 0}, sceneCamera);
    }

    Material *Renderer::loadMaterial(std::string path)
    {
        Material *img = new Material();
        img->texture = IMG_LoadTexture(renderer, path.c_str());
        return img;
    }

    void Renderer::Update() const
    {
        if (scene)
            RenderScene();
        SDL_RenderPresent(renderer);
    }
}