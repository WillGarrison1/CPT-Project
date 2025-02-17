#include "Camera.h"

namespace Engine
{
    Camera::Camera()
    {
        Transform *t = new Transform();
        addComponent<ComponentID::Transform>(t);
    }

    Camera::Camera(Vector2<float> pos, float rotation, float dim)
    {
        Transform *t = new Transform();
        t->position = pos;
        t->rotation = rotation;
        addComponent<ComponentID::Transform>(t);

        size = dim;
    }

    
}