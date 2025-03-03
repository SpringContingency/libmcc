#pragma once

#include <cmath>
#include <corecrt_math_defines.h>

namespace libmcc {
    typedef float real;
    typedef float angle;

    constexpr real RAD_TO_DEG = 180.0f / M_PI;
    constexpr real DEG_TO_RAD = M_PI / 180.0f;

    union real_vector3d;

    union real_point2d {
		real_point2d() {}
		real_point2d(real x, real y) : x(x), y(y) {}

        real_point2d operator * (real scalar) {return { x * scalar, y * scalar };}

        struct {
            real x, y;
        };
        struct {
            real u, v;
        };
        real n[2];
    };

    union real_point3d {
        real_point3d() {}
        real_point3d(real x, real y, real z) : x(x), y(y), z(z) {}
        real_point3d(const real_point3d& p, const real_vector3d& v, float f);

        struct {
            real x, y, z;
        };
        struct {
            real u, v, w;
        };
        real n[3];
    };

    union real_vector2d {
        constexpr real_vector2d() {}
		constexpr real_vector2d(real i, real j) : i(i), j(j) {}

		void operator += (const real_vector2d& other) {
			i += other.i;
			j += other.j;
		}

		real distance(const real_vector2d& other) const {
			real dx = i - other.i;
			real dy = j - other.j;
			return std::sqrt(dx * dx + dy * dy);
		}

        real normalize() {
			real length = std::sqrt(i * i + j * j);
			i /= length;
			j /= length;
			return length;
        }

        struct {
            real i, j;
        };
        real n[2];
    };

    union real_vector3d {
        real_vector3d() {}
        real_vector3d(real i, real j, real k) : i(i), j(j), k(k) {}
        real_vector3d(const real_point3d& p0, const real_point3d& p1);

        double magnitude_squared3d() const {return i * i + j * j + k * k;}
        real magnitude3d() const {return std::sqrt(magnitude_squared3d());}

        static real_vector3d cross_product3d(const real_vector3d& up, const real_vector3d& forward) {
            return {
                up.j * forward.k - up.k * forward.j,
                up.k * forward.i - up.i * forward.k,
                up.i * forward.j - up.j * forward.i
            };
        }

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
        real_euler_angles2d() {}
		real_euler_angles2d(angle yaw, angle pitch) : yaw(yaw), pitch(pitch) {}
        real_euler_angles2d(const real_vector3d& vector);

        struct {
            angle yaw;
            angle pitch;
        };
        angle n[2];
    };

    struct real_euler_angles3d {
        real yaw, pitch, roll;
    };

    struct real_quaternion {
        real_vector3d v;
        real w;
    };

    struct real_orientation {
        real_quaternion rotation;
        real_point3d translation;
        real scale;
    };

    inline real_vector3d::real_vector3d(const real_point3d& p0, const real_point3d& p1) {
        i = p1.x - p0.x;
        j = p1.y - p0.y;
        k = p1.z - p0.z;
    }

    inline real_point3d::real_point3d(const real_point3d& p, const real_vector3d& v, float f) {
        x = p.x + v.i * f;
        y = p.y + v.j * f;
        z = p.z + v.k * f;
    }

    inline real_euler_angles2d::real_euler_angles2d(const real_vector3d& vector) {
        yaw = std::atan2(vector.j, vector.i);
        real horizontal_length = std::sqrt(vector.i * vector.i + vector.j * vector.j);
        pitch = std::atan2(vector.k, horizontal_length);
    }
}
