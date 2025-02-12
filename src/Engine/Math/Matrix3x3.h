#pragma once

#include <iostream>
#include <cmath>
#include "vector2.h"

template <typename T>
struct Mat3x3
{
    T data[3][3];

    /*
    According to chatGPT, we need to use 3x3 matrices in order to
    fully control the transformations and scaling that is required
    for rendering Entities.

    Here is a breakdown of each of their capabilites

    2x2 matrix:
     - scaling
     - rotation

    3x3 matrix:
     - scaling
     - rotation
     - translation
     - shearing (slanting)

    We represent transformations as "homogeneous transformation matrices"

    They are formatted like so:
     [ sx, shx,  tx]
     [shy,  sy,  ty]
     [  0,   0,   0]

     sx,sy: Scaling factors
     shx,shy: shear values
     tx,ty: translation values

     Rotation is accomplished by using a combination of
     sx,sy,shx, and shy
     */

    // Initialize as identity matrix
    Mat3x3() : data{{1, 0, 0},
                    {0, 1, 0},
                    {0, 0, 1}} {}

    Mat3x3(T i) : data{{i, i, i},
                       {i, i, i},
                       {i, i, i}} {}

    Mat3x3(T **m) : data(m) {}

    T *operator[](const int i)
    {
        return data[i];
    }
    const T *operator[](const int i) const
    {
        return data[i];
    }

    // Matrix multiplication
    Mat3x3<T> operator*(const Mat3x3<T> &b) const
    {
        Mat3x3<T> t(static_cast<T>(0));
        for (int y = 0; y < 3; y++)
        {
            for (int x = 0; x < 3; x++)
            {
                t[y][x] =
                    data[y][0] * b[0][x] +
                    data[y][1] * b[1][x] +
                    data[y][2] * b[2][x];
            }
        }
        return t;
    }

    // Applies a transormation to a point
    Vector2<T> apply(const Vector2<T> point) const
    {
        return {data[0][0] * point.x + data[0][1] * point.y + data[0][2],
                data[1][0] * point.x + data[1][1] * point.y + data[1][2]};
    }

    static Mat3x3<T> translate(Vector2<T> pos)
    {
        Mat3x3<T> mat;
        mat[0][2] = pos.x;
        mat[1][2] = pos.y;
        return mat;
    }

    static Mat3x3<T> scale(Vector2<T> scale)
    {
        Mat3x3<T> mat(0);
        mat[0][0] = scale.x;
        mat[1][1] = scale.y;
        return mat;
    }

    static Mat3x3<T> rotate(T r)
    {
        Mat3x3<T> rot;
        T s = std::sin(r * (M_PI / 180.0));
        T c = std::cos(r * (M_PI / 180.0));

        rot[0][0] = c;
        rot[0][1] = -s;
        rot[1][0] = s;
        rot[1][1] = c;

        return rot;
    }

    // Write to buffer for debug
    friend void operator<<(std::ostream &out, const Mat3x3 b)
    {
        for (int y = 0; y < 3; y++)
        {
            for (int x = 0; x < 3; x++)
            {
                out << b[y][x] << " ";
            }
            out << "\n";
        }
        out << std::endl;
    }
};