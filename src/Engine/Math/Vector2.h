#pragma once

#include <iostream>

template <typename T>
struct Vector2
{
    T x, y;

    Vector2() : x(0), y(0) {}
    Vector2(T x, T y) : x(x), y(y) {}
    Vector2(const Vector2 &vec2) : x(vec2.x), y(vec2.y) {}

    Vector2 operator+(const Vector2 &other)
    {
        return Vector2(x + other.x, y + other.y);
    }

    Vector2 operator-(const Vector2 &other)
    {
        return Vector2(x - other.x, y - other.y);
    }

    void operator=(const Vector2 &other)
    {
        x = other.x;
        y = other.y;
    }

    bool operator==(const Vector2 &other)
    {
        return (x == other.x && y == other.y);
    }

    friend std::ostream &operator<<(std::ostream &os, const Vector2<T> &vector);
};

template <typename T>
std::ostream &operator<<(std::ostream &os, const Vector2<T> &vector)
{
    os << "(" << vector.x << ", " << vector.y << ")";
    return os;
}