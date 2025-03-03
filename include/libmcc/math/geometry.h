#pragma once

#include "./real_math.h"

namespace libmcc {
    struct real_plane2d {
        real_vector2d n;
        real d;
    };

    struct real_plane3d {
        real_vector3d n;
        real d;
    };

    union real_rectangle2d {
        real n[4];
        struct {real x0, x1, y0, y1;};
    };

    union real_rectangle3d {
        real n[6];
        struct {real x0, x1, y0, y1, z0, z1;};
    };
}