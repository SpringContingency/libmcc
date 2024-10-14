#pragma once

#include "./real_math.h"

struct real_matrix3x3 {
    real_vector3d forward;
    real_vector3d left;
    real_vector3d up;
};

struct real_matrix4x3 {
    real scale;
    real_vector3d forward;
    real_vector3d left;
    real_vector3d up;
    real_point3d position;
};
