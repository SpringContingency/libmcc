#pragma once

#include "./real_math.h"

union real_rgb_color {
    struct {
        real red;
        real green;
        real blue;
    };
    real n[3];
};

union real_argb_color {
    struct {
        real alpha;
        real_rgb_color rgb;
    };
    real n[4];
};

union real_rgba_color {
    struct {
        real_rgb_color rgb;
        real alpha;
    };
    real n[4];
};

union real_hsv_color {
    struct {
        real hue;
        real saturation;
        real value;
    };
    real n[3];
};


inline const static real_rgba_color s_color_black = {0.0f, 0.0f, 0.0f, 1.0f};
inline const static real_rgba_color s_color_white = {1.0f, 1.0f, 1.0f, 1.0f};
inline const static real_rgba_color s_color_red = {1.0f, 0.0f, 0.0f, 1.0f};
inline const static real_rgba_color s_color_green = {0.0f, 1.0f, 0.0f, 1.0f};
inline const static real_rgba_color s_color_blue = {0.0f, 0.0f, 1.0f, 1.0f};