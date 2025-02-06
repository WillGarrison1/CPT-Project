#pragma once

#include <vector>
#include <unordered_map>
#include "Engine/Core/Error.h"

#include "Component.h"

namespace Engine
{
    class Entity
    {
    public:
        Entity()
        {
            children = std::vector<Entity *>();
            components = std::unordered_map<ComponentID, Component *>();
        }

        ~Entity()
        {
            for (Entity *e : children)
            {
                delete e;
            }

            for (std::pair<ComponentID, Component *> component : components)
            {
                delete component.second;
            }

            children.clear();
            components.clear();
        }

        void addComponent(Component *component)
        {
            ASSERT(component.count(component->ID) == 0); // Should probably change to allow multiple components
            components.insert({component->ID, component});
        }

        template <ComponentID comp>
        Component *getComponent()
        {
            ASSERT(components.count(component->ID) != 0);
            return components[comp];
        }

        void addChild(Entity *child)
        {
            children.insert(children.end(), child);
        }

        std::vector<Entity *> getChildren()
        {
            return children;
        }

        Entity *getChild(int index)
        {
            return children[index];
        }

    private:
        std::vector<Entity *> children;
        std::unordered_map<ComponentID, Component *> components;
    };
}