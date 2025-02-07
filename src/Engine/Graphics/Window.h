#pragma once

#include <string>

#include <SDL3/SDL_video.h>

#include "Engine/Events/Callback.h"
#include "Engine/Math/Vector2.hpp"

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

        EventCallbackFunc callbackFunc;

        WinProps()
            : title(0), width(0), height(0), vsync(0), callbackFunc(0) {}

        WinProps(std::string title,
                 EventCallbackFunc callback,
                 unsigned int width = DEFAULT_WIN_WIDTH,
                 unsigned int height = DEFAULT_WIN_HEIGHT,
                 bool vsync = false)
            : title(title), width(width), height(height), vsync(vsync), callbackFunc(callback) {}

        WinProps(std::string title,
                 EventCallbackFunc callback,
                 Vector2<unsigned int> dimensions,
                 bool vsync = false)
            : title(title), width(dimensions.x), height(dimensions.y), vsync(vsync), callbackFunc(callback) {}

        WinProps(const WinProps &props)
            : title(props.title), width(props.width), height(props.height), vsync(props.vsync), callbackFunc(props.callbackFunc) {};

        WinProps &operator=(const WinProps &props)
        {
            title = props.title;
            callbackFunc = props.callbackFunc;
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

        // Updates the window and calls events
        void Update();

    private:
        WinProps m_Properties;

        SDL_Window *m_Window;
    };
}