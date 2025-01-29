#pragma once

#include <unordered_map>
#include "Component.h"

class Entity
{
public:
    Entity() = default;
    ~Entity() = default;

    bool addComponent(Component component)
    {
        
        componentList.insert(component.ID,component);
    }

private:
    std::unordered_map<ComponentID, Component> componentList;
};


