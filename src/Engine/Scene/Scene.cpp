#include "Scene.h"

namespace Engine
{

    Scene::Scene()
    {
        root = new Entity();
    }

    Scene::~Scene()
    {
        delete root;
    }
}