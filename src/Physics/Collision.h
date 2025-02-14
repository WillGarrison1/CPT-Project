#pragma once

#include <vector>

#include "Scene/Entity.h"

namespace Engine
{
    bool checkCollision(Entity& e1, Entity& e2)
    {
        std::vector<Entity*> c1 = e1.getChildren();
        std::vector<Entity*> c2 = e2.getChildren();

        bool hasCollider1 = false;
        bool hasCollider2 = false;

        for(Entity* e : c1)
        {
            if(e->hasComponent<ComponentID::Collider>())
            {
                hasCollider1 = true;
                break;
            }
        }

        for(Entity* e : c2)
        {
            if(e->hasComponent<ComponentID::Collider>())
            {
                hasCollider2 = true;
                break;
            }
        }
        
        if(!hasCollider1 || !hasCollider2) return false;

        float w1, h1, w2, h2;
        Material *mat = static_cast<Material*>(e1.getComponent<ComponentID::Material>())
        SDL_GetTextureSize(.texture, &w1, &h1);
        
    }
}