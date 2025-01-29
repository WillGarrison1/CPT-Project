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
    const ComponentID ID = ComponentID::Component;
};

struct Transform : Component
{
    const ComponentID ID = ComponentID::Transform;
    Vector2<float> position;
    float rotation;
};

/**
 * @brief Contains the texture to be rendered
 */
struct Material : Component
{
    ComponentID ID = ComponentID::Material;
    SDL_Texture *texture;
};

struct RigidBody : Component
{
    ComponentID ID = ComponentID::RigidBody;
    Vector2<float> velocity;
    float rotationalVeclocity;
    float mass;
};