#pragma once

#include <cmath>
#include <corecrt_math_defines.h>

namespace libmcc {
    typedef float real;
    typedef float angle;

    constexpr real RAD_TO_DEG = 180.0f * M_1_PI;
    constexpr real DEG_TO_RAD = M_PI / 180.0f;

    union real_vector3d;
    union real_matrix3x3;

    union real_point2d {
        constexpr real_point2d();
        constexpr real_point2d(real x, real y);
        constexpr real_point2d operator * (real scalar);

        struct {
            real x, y;
        };
        struct {
            real u, v;
        };
        real n[2];
    };

    union real_point3d {
        constexpr real_point3d();
        constexpr real_point3d(real x, real y, real z);
        constexpr real_point3d(const real_point3d& p, const real_vector3d& v, float f);

        struct {
            real x, y, z;
        };
        struct {
            real u, v, w;
        };
        real n[3];
    };

    union real_vector2d {
        constexpr real_vector2d();
        constexpr real_vector2d(real i, real j);
        constexpr void operator += (const real_vector2d& other);
        real distance(const real_vector2d& other) const;
        real normalize();

        struct {
            real i, j;
        };
        real n[2];
    };

    union real_vector3d {
        constexpr real_vector3d();
        constexpr real_vector3d(real i, real j, real k);
        constexpr real_vector3d(const real_point3d& p0, const real_point3d& p1);
        constexpr real_vector3d(const real_vector3d& up, const real_vector3d& forward);
        real magnitude3d() const;
        constexpr double magnitude_squared3d() const;

        struct {
            real i, j, k;
        };
        real n[3];
    };

    union real_vector4d {
        struct {
            real i, j, k, w;
        };
        real n[4];
    };

    union real_euler_angles2d {
        constexpr real_euler_angles2d();
        constexpr real_euler_angles2d(angle yaw, angle pitch);
        real_euler_angles2d(const real_vector3d& vector);

        struct {
            angle yaw;
            angle pitch;
        };
        angle n[2];
    };

    struct real_euler_angles3d {
        constexpr real_euler_angles3d();
		constexpr real_euler_angles3d(angle yaw, angle pitch, angle roll);

        real yaw, pitch, roll;
    };

    union real_quaternion {
        constexpr real_quaternion();
        constexpr real_quaternion(const real_matrix3x3& matrix);

        struct {
            real i, j, k, w;
        };

        real n[4];
    };

    struct real_orientation {
        real_quaternion rotation;
        real_point3d translation;
        real scale;
    };

	union real_bounds {
        struct {
            real lower;
            real upper;
        };
		real n[2];
	};
}
