#pragma once

#include "./real_math.h"

namespace libmcc {
    struct real_matrix3x3 {
        real_matrix3x3() {}
        real_matrix3x3(const real_vector3d& forward, const real_vector3d& up, const real_vector3d& left) : forward(forward), left(left), up(up) {}
        real_matrix3x3(const real_vector3d& forward, const real_vector3d& up) : forward(forward), left(real_vector3d::cross_product3d(up, forward)), up(up) {}

        real_vector3d forward;
        real_vector3d left;
        real_vector3d up;
    };

    struct real_matrix4x3 {
        real_matrix4x3() {}
        real_matrix4x3(const real_point3d& center, const real_vector3d& forward, const real_vector3d& up, real scale) : center(center), matrix(forward, up), scale(scale) {}

        real_point3d transform(const real_point3d& point) const {
            float forward = point.x * scale;
            float left = point.y * scale;
            float up = point.z * scale;

            return {
                matrix.left.i * left + matrix.forward.i * forward + matrix.up.i * up + center.x,
                matrix.left.j * left + matrix.forward.j * forward + matrix.up.j * up + center.y,
                matrix.left.k * left + matrix.forward.k * forward + matrix.up.k * up + center.z
            };
        }

        real scale;
        real_matrix3x3 matrix;
        real_point3d center;
    };
}
