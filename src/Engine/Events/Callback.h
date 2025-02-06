#pragma once

#include <functional>

#include "Event.h"

namespace Engine
{


    using EventCallbackFunc = std::function<void(Event)>;

}