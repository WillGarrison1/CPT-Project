#pragma once

#include <string>
#include <vector>

#include <SDL3/SDL_video.h>

#include "Engine/Events/Event.h"
#include "Engine/Math/Vector2.h"

#define DEFAULT_WIN_WIDTH 1080
#define DEFAULT_WIN_HEIGHT 720

namespace Engine
{

    struct WinProps
    {
        std::string title;
        union
        {
            struct
            {
                unsigned int width, height;
            };
            Vector2<unsigned int> dimensions;
        };
        bool vsync;

        WinProps()
            : title(""), width(0), height(0), vsync(0) {}

        WinProps(std::string title,
                 unsigned int width = DEFAULT_WIN_WIDTH,
                 unsigned int height = DEFAULT_WIN_HEIGHT,
                 bool vsync = false)
            : title(title), width(width), height(height), vsync(vsync) {}

        WinProps(std::string title,
                 Vector2<unsigned int> dimensions,
                 bool vsync = false)
            : title(title), width(dimensions.x), height(dimensions.y), vsync(vsync) {}

        WinProps(const WinProps &props)
            : title(props.title), width(props.width), height(props.height), vsync(props.vsync) {};

        WinProps &operator=(const WinProps &props)
        {
            title = props.title;
            dimensions = props.dimensions;
            vsync = props.vsync;

            return *this;
        }
    };

    class Window
    {
    public:
        Window() : m_Properties(), m_Window(nullptr) {}
        Window(WinProps &prop);

        ~Window()
        {
            SDL_DestroyWindow(m_Window);
        }

        WinProps getProps() const { return m_Properties; }

        SDL_Window *getWindow() const { return m_Window; }

        bool getEvent(Event& event);

        // Updates the window and calls events
        void Update();

    private:
        WinProps m_Properties;

        SDL_Window *m_Window;
    };
}