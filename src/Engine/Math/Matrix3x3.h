#pragma once

#include <iostream>
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

    // Matrix multiplication
    Mat3x3 operator*(const Mat3x3 &b) const
    {
    }

    // Applies a transormation to a point
    Vector<T> apply(const Vector<T> point) const
    {
    }

    // Write to buffer for debug
    std::ostream &operator<<() const
    {
    }
};