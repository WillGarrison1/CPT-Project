#pragma once

#include <iostream>
#include <csignal>

namespace Engine
{

#ifdef DEBUG_MODE
#define ASSERT(x)                                                            \
    if (x)                                                                   \
    {                                                                        \
        ::std::cerr << "Failed assert at line: " << __LINE__ << ::std::endl; \
        __debugbreak();                                                      \
    }
#else
#define ASSERT(X)
#endif
}