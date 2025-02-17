#include "Renderer.h"
#include "Engine/Scene/Component.h"
#include "Engine/Math/Matrix3x3.h"

#include <SDL3_image/SDL_image.h>

namespace Engine
{
    Renderer::Renderer()
    {
        scene = nullptr;
        window = nullptr;
        textureScaleFactor = 0;
        renderer = SDL_CreateRenderer(NULL, NULL);
    }

    Renderer::Renderer(Window *win)
    {
        window = win;

        renderer = SDL_CreateRenderer(window->getWindow(), NULL);

        if (window->getProps().vsync)
            SDL_SetRenderVSync(renderer, 1);

        textureScaleFactor = 0;
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

    void Renderer::RenderEntity(Entity *entity, bool recursive, Mat3x3<float> worldTransform) const
    {

        if (entity->hasComponent<ComponentID::Transform>())
        {
            // Three steps for applying matrix
            // 1. Translate
            // 2. Rotate
            // 3. Scale

            Mat3x3<float> matrix;
            Transform *transform = static_cast<Transform *>(entity->getComponent<ComponentID::Transform>());

            // Translate first
            matrix = matrix * Mat3x3<float>::translate(transform->position);

            // Rotate Next
            matrix = matrix * Mat3x3<float>::rotate(transform->rotation);

            matrix = worldTransform * matrix; // Apply parent matrix

            worldTransform = matrix;

            if (entity->hasComponent<ComponentID::Material>())
            {

                Material *entityMat = static_cast<Material *>(entity->getComponent<ComponentID::Material>());

                ASSERT(transform != nullptr);
                ASSERT(entityMat != nullptr);
                ASSERT(entityMat->texture != nullptr);

                Vector2<float> screenPos = matrix.apply({0, 0});

                float globalRotation = std::atan2(matrix[1][0], matrix[0][0]) * (180.0f / M_PI);

                float width, height; // should probably store the image dimensions in material struct
                SDL_GetTextureSize(entityMat->texture, &width, &height);
                SDL_FRect dest = {screenPos.x - width / 2, screenPos.y - height / 2, width * textureScaleFactor, height * textureScaleFactor};

                SDL_RenderTextureRotated(renderer, entityMat->texture, NULL, &dest, globalRotation, NULL, SDL_FLIP_NONE);
            }
        }
        if (recursive)
        {
            for (Entity *child : entity->getChildren())
            {
                RenderEntity(child, true, worldTransform);
            }
        }
    }

    void Renderer::RenderScene()
    {
        if (!scene->root)
            return;

        Camera *sceneCamera = scene->getCamera();
        float cameraSize = sceneCamera->GetSize();

        WinProps properties = window->getProps();
        Vector2<float> windowDimensions = Vector2<float>(properties.dimensions.x, properties.dimensions.y);

        if (!sceneCamera)
            return;

        Transform *cameraTransform = static_cast<Transform *>(sceneCamera->getComponent<ComponentID::Transform>());

        textureScaleFactor = windowDimensions.x / cameraSize;

        // Compute camera "view matrix"
        // The positions and rotations must be negated in order to create it

        Mat3x3<float> cameraMat;
        cameraMat = cameraMat * Mat3x3<float>::translate(-cameraTransform->position);
        cameraMat = cameraMat * Mat3x3<float>::rotate(-cameraTransform->rotation);
        cameraMat = cameraMat * Mat3x3<float>::scale({textureScaleFactor, textureScaleFactor});
        RenderEntity(scene->root, true, cameraMat);
    }

    Material *Renderer::loadMaterial(std::string path)
    {
        Material *img = new Material();
        img->texture = IMG_LoadTexture(renderer, path.c_str());
        return img;
    }

    void Renderer::Update()
    {
        Clear();

        if (scene)
            RenderScene();
        SDL_RenderPresent(renderer);
    }
}