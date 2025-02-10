#include <iostream>
#include <chrono>
#include <math.h>

#include "Engine/Core/Entry.h"
#include "Engine/Core/Engine.h"
#include "Engine/Events/Event.h"
#include "Engine/Scene/Scene.h"
#include "Engine/Graphics/Window.h"
#include "Engine/Graphics/Renderer.h"

unsigned long long get_time()
{
    return std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
}

int GameInit(int argc, char **argv)
{

    Engine::Window *gameWindow = new Engine::Window({"Game", 1080, 720, false});

    Engine::Renderer *renderer = new Engine::Renderer(gameWindow);

    // Main scene
    Engine::Scene *mainScene = new Engine::Scene();

    Engine::Camera *camera = new Engine::Camera({100, 100}, {1080, 720});
    mainScene->root->addChild(camera);
    mainScene->setCamera(camera);

    Engine::Entity *square = new Engine::Entity();

    Engine::Transform *squareTransform = new Engine::Transform();

    squareTransform->position = Vector2<float>(80, 80);
    squareTransform->rotation = 0;

    square->addComponent<Engine::ComponentID::Transform>(squareTransform);

    Engine::Material *mat = renderer->loadMaterial("assets/Test.png");

    square->addComponent<Engine::ComponentID::Material>(mat);

    mainScene->root->addChild(square);

    bool running = true;

    unsigned long long prev_time = get_time();

    float fpsAvg = 0;
    unsigned long long fpsCount = 0;

    renderer->SetScene(mainScene);

    while (running)
    {

        Engine::Event e;
        while (gameWindow->getEvent(e))
        {
            if (e.eventType == Engine::EventType::Quit)
                running = false;
        }

        renderer->Update();

        char n_char[6 + sizeof(char)];
        std::sprintf(n_char, "%d", (int)(fpsAvg / fpsCount));

        unsigned long long current_time = get_time();
        unsigned long long delta_time = current_time - prev_time;
        prev_time = current_time;

        fpsAvg += 1.0 / (delta_time / 1e9);
        fpsCount++;

        if (fpsCount % 1000 == 0)
            std::cout << "FPS: " << fpsAvg / fpsCount << std::endl;
    }

    delete mainScene;
    delete renderer;
    delete gameWindow;

    return 0;
}