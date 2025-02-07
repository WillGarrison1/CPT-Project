#include "Event.h"

namespace Engine
{
    Event::Event(EventType e) : eventType(e)
    {
    }

    Event::Event(SDL_Event e)
    {
        switch (e.type)
        {
        case SDL_EVENT_QUIT:
            eventType = EventType::Quit;
            break;
        case SDL_EVENT_KEY_DOWN:
            eventType = EventType::KeyDown;
            break;
        case SDL_EVENT_KEY_UP:
            eventType = EventType::KeyUp;
            break;
        case SDL_EVENT_MOUSE_BUTTON_DOWN:
            eventType = EventType::MouseDown;
            break;
        case SDL_EVENT_MOUSE_BUTTON_UP:
            eventType = EventType::MouseUp;
            break;
        default:
            eventType = EventType::None;
        }
    }
}