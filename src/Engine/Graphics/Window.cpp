#include <vector>

#include <SDL3/SDL_events.h>

#include "Window.h"

namespace Engine
{
    Window::Window(WinProps &properties)
    {
        m_Properties = properties;

        m_Window = SDL_CreateWindow(m_Properties.title.c_str(),
                                    m_Properties.width,
                                    m_Properties.height,
                                    0);
    }

    std::vector<Event> Window::getEvents()
    {
        std::vector<Event> events;

        SDL_Event e;
        while (SDL_PollEvent(&e))
        {
            events.push_back(e);
        }

        return events;
    }
}