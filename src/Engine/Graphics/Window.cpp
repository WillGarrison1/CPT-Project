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
}