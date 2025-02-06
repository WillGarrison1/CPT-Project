#pragma once

#include <functional>

#include "event.t"

namespace Engine
{


    using EventCallbackFunc = std::function<void(Event)>;

}