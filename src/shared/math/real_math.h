#pragma once

typedef float real;

#define M_PI 3.14159265358979323846

#pragma region point

union real_point2d {
    real n[2];
    struct {
        real x, y;
    } s1;
    struct {
        real u, v;
    } s2;
};

union real_point3d {
    real n[3];
    struct {
        real x, y, z;
    } s1;
    struct {
        real u, v, w;
    } s2;
};

#pragma endregion

#pragma region vector

union real_vector2d {
    struct {
        real i, j;
    };
    real n[2];
};

union real_vector3d {
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

#pragma endregion

#pragma region angles

struct real_euler_angles2d {
    real yaw, pitch;
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

#pragma endregion
