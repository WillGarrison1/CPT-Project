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
        Material *mat1 = static_cast<Material*>(e1.getComponent<ComponentID::Material>());
        Material *mat2 = static_cast<Material*>(e2.getComponent<ComponentID::Material>());
        SDL_GetTextureSize(mat1->texture, &w1, &h1);
        SDL_GetTextureSize(mat1->texture, &w2, &h2);
        
        Transform *tran1 = static_cast<Transform*>(e1.getComponent<ComponentID::Transform>());
        Transform *tran2 = static_cast<Transform*>(e2.getComponent<ComponentID::Transform>());
        Vector2<float> pos1 = tran1->position;
        Vector2<float> pos2 = tran2->position;

        if(pos1.x + w1 > pos2.x && pos1.y > pos2.y+h2
           && pos1.x < pos2.x+w2 && pos1.y + h1 > pos1.y)
        {
            return true;
        }

        return false;
    }

    
}