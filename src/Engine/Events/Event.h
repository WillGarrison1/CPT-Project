#pragma once

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
    };

    struct Event
    {
        Event(EventType e) : eventType(e) {}
        ~Event();

        EventType eventType;
    };
}