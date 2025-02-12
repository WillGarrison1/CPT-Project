#pragma once

#include "Entity.h"

namespace Engine
{
    class Camera : public Entity
    {
    public:
        Camera();
        Camera(Vector2<float> pos, float rotation, Vector2<float> dimensions);
        ~Camera();

    private:
        Vector2<float> dimensions; // the area the camera sees
    };
}