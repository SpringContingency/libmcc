#pragma once

#include "./real_math.h"

struct real_plane2d
{
    real_vector2d n;
    real d;
};

struct real_plane3d
{
    real_vector3d n;
    real d;
};

union real_rectangle2d {
    real n[4];
    struct {
        real x0;
        real x1;
        real y0;
        real y1;
    } s1;
};

union real_rectangle3d {
    real n[6];
    struct {
        real x0;
        real x1;
        real y0;
        real y1;
        real z0;
        real z1;
    } s1;
};
