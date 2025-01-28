#pragma once

#include "Engine/Math/Vector2.hpp"
#include <SDL3/SDL_render.h>

enum class ComponentID
{
    Component,
    Transform,
    Material,
    RigidBody,
};

struct Component
{
};

struct Transform : Component
{
    Vector2<float> position;
    float rotation;
};

/**
 * @brief Contains the texture to be rendered
 */
struct Material : Component
{
    
};

struct RigidBody : Component
{
    Vector2<float> velocity;
    float rotationalVeclocity;
    float mass;
};