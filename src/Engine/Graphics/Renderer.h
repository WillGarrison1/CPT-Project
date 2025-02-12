#pragma once

#include <SDL3/SDL.h>

#include "Engine/Scene/Scene.h"
#include "Engine/Math/Matrix3x3.h"

#include "Window.h"
#include "Color.h"

namespace Engine
{
    class Renderer
    {
    public:
        Renderer();

        Renderer(Window *window);
        ~Renderer();

        void SetDrawColor(Color color) const;
        void SetScene(Scene *s) { scene = s; };

        void RenderEntity(Entity *entity, bool recursive, Mat3x3<float> worldTransform) const;
        void RenderScene() const;

        Material *loadMaterial(std::string path);

        void Clear() const;
        void Update() const;

    private:
        SDL_Renderer *renderer;

        Scene *scene;
    };
}