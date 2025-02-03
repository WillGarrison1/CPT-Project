#pragma once

#include <functional>

namespace Engine
{
    class Event
    {
        
    };

    using EventCallbackFunc = std::function<void(Event)>;

}