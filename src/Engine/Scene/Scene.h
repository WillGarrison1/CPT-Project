#pragma once

#include "Entity.h"

namespace Engine
{
    class Scene
    {
    public:
        Scene();
        ~Scene();

        // The root entity is the parent entity for everything in the scene,
        // all entities and components should be accessed through this
        Entity *root;

    private:
    };
}