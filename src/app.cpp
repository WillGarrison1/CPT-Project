#include <iostream>
#include <chrono>
#include <math.h>

#include "Engine/Core/Entry.h"
#include "Engine/Core/Engine.h"
#include "Engine/Events/Event.h"
#include "Engine/Input/Input.h"
#include "Engine/Scene/Scene.h"
#include "Engine/Graphics/Window.h"
#include "Engine/Graphics/Renderer.h"

unsigned long long get_time()
{
    return std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
}

int GameInit(int argc, char **argv)
{

    Mat3x3<float> f = Mat3x3<float>::rotate(90);

    std::cout << f;

    Engine::Window *gameWindow = new Engine::Window({"Game", 1080, 720, false});

    Engine::Renderer *renderer = new Engine::Renderer(gameWindow);

    // Main scene
    Engine::Scene *mainScene = new Engine::Scene();

    Engine::Camera *camera = new Engine::Camera({0, 0}, 0, {1080, 720});
    mainScene->root->addChild(camera);
    mainScene->setCamera(camera);

    Engine::Entity *square = new Engine::Entity();

    Engine::Transform *squareTransform = new Engine::Transform();

    squareTransform->position = Vector2<float>(400, 300);
    squareTransform->rotation = 45;
    square->addComponent<Engine::ComponentID::Transform>(squareTransform);

    Engine::Material *mat = renderer->loadMaterial("assets/Test.png");
    square->addComponent<Engine::ComponentID::Material>(mat);

    mainScene->root->addChild(square);

    Engine::Entity *child = new Engine::Entity();

    Engine::Transform *childTransform = new Engine::Transform();

    childTransform->position = Vector2<float>(150, 0);
    childTransform->rotation = 0;
    child->addComponent<Engine::ComponentID::Transform>(childTransform);

    Engine::Material *mat2 = renderer->loadMaterial("assets/Test.png");
    child->addComponent<Engine::ComponentID::Material>(mat2);

    square->addChild(child);

    bool running = true;

    unsigned long long prev_time = get_time();

    float fpsAvg = 0;
    unsigned long long fpsCount = 0;

    renderer->SetScene(mainScene);

    Engine::Input *inputManager = new Engine::Input();

    Engine::Transform *cameraTransform = static_cast<Engine::Transform *>(camera->getComponent<Engine::ComponentID::Transform>());

    while (running)
    {

        Engine::Event e;
        while (gameWindow->getEvent(e))
        {
            if (e.eventType == Engine::EventType::Quit)
                running = false;
        }

        inputManager->Update();

        if (inputManager->getKeyboardButton(Engine::KB_UP))
            squareTransform->rotation += 0.1f;
        if (inputManager->getKeyboardButton(Engine::KB_DOWN))
            squareTransform->rotation -= 0.1f;

        if (inputManager->getKeyboardButton(Engine::KB_W))
            cameraTransform->position.y -= 0.1f;
        if (inputManager->getKeyboardButton(Engine::KB_S))
            cameraTransform->position.y += 0.1f;
        if (inputManager->getKeyboardButton(Engine::KB_A))
            cameraTransform->position.x -= 0.1f;
        if (inputManager->getKeyboardButton(Engine::KB_D))
            cameraTransform->position.x += 0.1f;

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