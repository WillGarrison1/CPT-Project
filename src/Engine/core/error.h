#pragma once

#include <iostream>
#include <signal.h>

namespace Engine
{

#ifdef DEBUG_MODE
#define ASSERT(x)                                                         \
    if (x)                                                                \
    {                                                                     \
        ::std::cerr << "Failed assert at line: " __LINE__ << ::std::endl; \
        ::std::raise(SIGTRAP);                                            \
    }
#else
#define ASSERT(X)
#endif
}