#pragma once

#include "./real_math.h"

namespace libmcc {
    union byte_rgb_color;
    union byte_argb_color;
    union byte_rgba_color;
    union real_rgb_color;
    union real_argb_color;
    union real_rgba_color;
    union real_hsv_color;
    union real_hsva_color;

    // byte color
    union byte_rgb_color {
        constexpr byte_rgb_color();
        constexpr byte_rgb_color(byte red, byte green, byte blue);
        constexpr byte_rgb_color(const real_rgb_color& color);

        int n;
        struct {byte blue, green, red;};
    };

    union byte_argb_color {
        constexpr byte_argb_color();
        constexpr byte_argb_color(byte alpha, const byte_rgb_color& color);
        constexpr byte_argb_color(const real_argb_color& color);
		constexpr operator int() const;

        int n;
        struct {byte_rgb_color rgb; byte alpha;};
    };

    union byte_rgba_color {
        constexpr byte_rgba_color();
        constexpr byte_rgba_color(const byte_rgb_color& rgb, byte alpha);

        int n;
        struct {byte alpha; byte_rgb_color rgb;};
    };

    // real color
    typedef real_rgb_color real_linear_rgb_color;

    union real_rgb_color {
        constexpr real_rgb_color();
        constexpr real_rgb_color(real red, real green, real blue);
        constexpr real_rgb_color(const byte_rgb_color& color);
        constexpr real_rgb_color(const real_hsv_color& color);

        void degamma(real_rgb_color& color) const;
        void regamma(const real_rgb_color& color);

        static real value_degamma(real value);
        static real value_regamma(real value);

        real n[3];
        struct {real red, green, blue;};
    };

    union real_argb_color {
        constexpr real_argb_color();
		constexpr real_argb_color(real alpha, const real_rgb_color& color);

        real n[4];
        struct {real alpha; real_rgb_color rgb;};
    };

    union real_rgba_color {
		constexpr real_rgba_color();
		constexpr real_rgba_color(const real_rgb_color& rgb, real alpha);

        real n[4];
        struct {real_rgb_color rgb;real alpha;};
    };

    union real_hsv_color {
        constexpr real_hsv_color();
        constexpr real_hsv_color(real hue, real saturation, real value);
        constexpr real_hsv_color(const real_rgb_color& rgb);

        real n[3];
        struct {real hue, saturation, value;};
    };

    union real_hsva_color {
        constexpr real_hsva_color();
        constexpr real_hsva_color(const real_hsv_color& hsv, real alpha);
        constexpr real_hsva_color(const real_rgb_color& rgb, real alpha);

        real n[4];
        struct {real_hsv_color hsv; real alpha;};
    };
}
