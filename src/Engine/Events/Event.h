#pragma once

#include <SDL3/SDL_events.h>

namespace Engine
{

    enum class EventType
    {
        None = 0,

        KeyDown,
        KeyUp,
        MouseDown,
        MouseUp,
        Quit,
        PixelSizeChanged
    };

    struct Event
    {
        Event() : eventType(EventType::None) {}
        Event(const SDL_Event e);
        Event(EventType e);
        ~Event() {}

        EventType eventType;
    };
}