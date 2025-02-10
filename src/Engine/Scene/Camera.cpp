#include "Camera.h"

namespace Engine
{
    Camera::Camera()
    {
        Transform *t = new Transform();
        addComponent<ComponentID::Transform>(t);
    }

    Camera::Camera(Vector2<float> pos, Vector2<float> dim)
    {
        Transform *t = new Transform();
        t->position = pos;
        addComponent<ComponentID::Transform>(t);

        dimensions = dim;
    }
}