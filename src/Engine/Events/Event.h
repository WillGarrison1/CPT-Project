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

    class Event
    {
    public:
        Event(EventType);
        ~Event();

    private:
        
    };
}