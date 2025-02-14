#pragma once

#include "Engine/Math/Vector2.h"
#include <SDL3/SDL_mouse.h>

namespace Engine
{

    enum KeyButton
    {
        // Keycodes taken from SDL, do not use for Screenshots!

        KB_UNKNOWN = 0,

        KB_A = 4,
        KB_B = 5,
        KB_C = 6,
        KB_D = 7,
        KB_E = 8,
        KB_F = 9,
        KB_G = 10,
        KB_H = 11,
        KB_I = 12,
        KB_J = 13,
        KB_K = 14,
        KB_L = 15,
        KB_M = 16,
        KB_N = 17,
        KB_O = 18,
        KB_P = 19,
        KB_Q = 20,
        KB_R = 21,
        KB_S = 22,
        KB_T = 23,
        KB_U = 24,
        KB_V = 25,
        KB_W = 26,
        KB_X = 27,
        KB_Y = 28,
        KB_Z = 29,

        KB_1 = 30,
        KB_2 = 31,
        KB_3 = 32,
        KB_4 = 33,
        KB_5 = 34,
        KB_6 = 35,
        KB_7 = 36,
        KB_8 = 37,
        KB_9 = 38,
        KB_0 = 39,

        KB_RETURN = 40,
        KB_ESCAPE = 41,
        KB_BACKSPACE = 42,
        KB_TAB = 43,
        KB_SPACE = 44,

        KB_MINUS = 45,
        KB_EQUALS = 46,
        KB_LEFTBRACKET = 47,
        KB_RIGHTBRACKET = 48,
        KB_BACKSLASH = 49,

        KB_NONUSHASH = 50,
        KB_SEMICOLON = 51,
        KB_APOSTROPHE = 52,
        KB_GRAVE = 53,

        KB_COMMA = 54,
        KB_PERIOD = 55,
        KB_SLASH = 56,

        KB_CAPSLOCK = 57,

        KB_F1 = 58,
        KB_F2 = 59,
        KB_F3 = 60,
        KB_F4 = 61,
        KB_F5 = 62,
        KB_F6 = 63,
        KB_F7 = 64,
        KB_F8 = 65,
        KB_F9 = 66,
        KB_F10 = 67,
        KB_F11 = 68,
        KB_F12 = 69,

        KB_PRINTSCREEN = 70,
        KB_SCROLLLOCK = 71,
        KB_PAUSE = 72,
        KB_INSERT = 73,

        KB_HOME = 74,
        KB_PAGEUP = 75,
        KB_DELETE = 76,
        KB_END = 77,
        KB_PAGEDOWN = 78,
        KB_RIGHT = 79,
        KB_LEFT = 80,
        KB_DOWN = 81,
        KB_UP = 82,

        KB_NUMLOCK = 83
    };

    enum MouseButton
    {
        MB_LEFT,
        MB_MIDDLE,
        MB_RIGHT
    };

    class Input
    {
    public:
        Input();
        ~Input();

        void Update();

        Vector2<float> getMousePos() { return mousePos; }
        bool getMouseButton(MouseButton b) { return mouse[b]; }

        bool getKeyboardButton(KeyButton b) { return keyboard[b]; }

    private:
        bool keyboard[84];
        bool mouse[3];
        Vector2<float> mousePos;
    };
}