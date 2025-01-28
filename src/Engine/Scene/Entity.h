#pragma once

#include <unordered_map>
#include "Component.h"

class Entity
{
public:
    Entity() = default;
    ~Entity() = default;

private:
    std::unordered_map<ComponentID, Component> componentList;
};


