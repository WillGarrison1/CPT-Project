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
            : title(0), callbackFunc(0),
              width(0), height(0), vsync(0) {}

        WinProps(std::string title,
                 EventCallbackFunc callback,
                 unsigned int width = DEFAULT_WIN_WIDTH,
                 unsigned int height = DEFAULT_WIN_HEIGHT,
                 bool vsync = false)
            : title(title), callbackFunc(callback),
              width(width), height(height), vsync(vsync) {}

        WinProps(std::string title,
                 EventCallbackFunc callback,
                 Vector2<unsigned int> dimensions,
                 bool vsync = false)
            : title(title), callbackFunc(callback),
              dimensions(dimensions), vsync(vsync) {}

        WinProps(const WinProps &props)
            : title(props.title), callbackFunc(props.callbackFunc),
              dimensions(props.dimensions), vsync(props.vsync) {};

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

    private:
        WinProps m_Properties;

        SDL_Window *m_Window;
    };
}