#pragma once

#include "Entity.h"

namespace Engine
{
    class Camera : public Entity
    {
    public:
        Camera();
        Camera(Vector2<float> pos, float rotation, float size);

        ~Camera();

        float GetSize() { return size; }

    private:
        float size; // the area the camera sees
    };
}