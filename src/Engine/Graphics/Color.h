#include <string>

namespace Engine
{
    struct Color
    {
        unsigned char r, g, b, a;

        Color(std::string c)
        {
            if(c == "black") r = g = b = a = 0;
            if(c == "white") r = g = b = a = 255;
        };

        Color(unsigned char r, unsigned char g, unsigned char b, unsigned char a) : r(r), g(g), b(b), a(a) {}
    };
}