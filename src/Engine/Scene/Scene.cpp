#include "Scene.h"

namespace Engine
{

    Scene::Scene()
    {
        targetCamera = nullptr;
        root = new Entity();
    }

    Scene::~Scene()
    {
        delete root;
    }
}