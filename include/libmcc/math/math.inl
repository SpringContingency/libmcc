#pragma once

#include "./color_math.h"
#include "./geometry.h"
#include "./integer_math.h"
#include "./matrix_math.h"
#include "./real_math.h"

// color math
namespace libmcc {
    // byte_rgb_color
    constexpr byte_rgb_color::byte_rgb_color() {}
    constexpr byte_rgb_color::byte_rgb_color(byte red, byte green, byte blue) : red(red), green(green), blue(blue) {}
    constexpr byte_rgb_color::byte_rgb_color(const real_rgb_color& color) : red(color.red * 255), green(color.green * 255), blue(color.blue * 255) {}

    // byte_argb_color
    constexpr byte_argb_color::byte_argb_color() {}
    constexpr byte_argb_color::byte_argb_color(byte alpha, const byte_rgb_color& color) : rgb(color), alpha(alpha) {}
    constexpr byte_argb_color::byte_argb_color(const real_argb_color& color) : rgb(color.rgb), alpha(color.alpha) {}
    constexpr byte_argb_color::operator int() const { return n; }

    // byte_rgba_color
    constexpr byte_rgba_color::byte_rgba_color() {}
    constexpr byte_rgba_color::byte_rgba_color(const byte_rgb_color& rgb, byte alpha) : rgb(rgb), alpha(alpha) {}

    // real_rgb_color
    constexpr real_rgb_color::real_rgb_color() {}
    constexpr real_rgb_color::real_rgb_color(real red, real green, real blue) : red(red), green(green), blue(blue) {}
    constexpr real_rgb_color::real_rgb_color(const byte_rgb_color& color) : red(color.red / 255.0f), green(color.green / 255.0f), blue(color.blue / 255.0f) {}
    constexpr real_rgb_color::real_rgb_color(const real_hsv_color& color) {
        real h = color.hue;
        real s = color.saturation;
        real v = color.value;

        if (s == 0.0f) {
            red = v;
            green = v;
            blue = v;
            return;
        }

        h /= 60.0f;
        int i = (int)h;
        real f = h - i;
        real p = v * (1.0f - s);
        real q = v * (1.0f - s * f);
        real t = v * (1.0f - s * (1.0f - f));

        switch (i) {
            case 0:
                red = v;
                green = t;
                blue = p;
                break;
            case 1:
                red = q;
                green = v;
                blue = p;
                break;
            case 2:
                red = p;
                green = v;
                blue = t;
                break;
            case 3:
                red = p;
                green = q;
                blue = v;
                break;
            case 4:
                red = t;
                green = p;
                blue = v;
                break;
            default:
                red = v;
                green = p;
                blue = q;
                break;
        }
    }

    inline void real_rgb_color::degamma(real_rgb_color& color) const {
        color.red = value_degamma(color.red);
        color.green = value_degamma(color.green);
        color.blue = value_degamma(color.blue);
    }
    inline void real_rgb_color::regamma(const real_rgb_color& color) {
        red = value_regamma(color.red);
        green = value_regamma(color.green);
        blue = value_regamma(color.blue);
    }
    inline real real_rgb_color::value_degamma(real value) {
        real v3 = value;
        if (value <= 0.0f)
            v3 = 0.0f;

        real v4 = value;
        if (value <= 0.0f)
            v4 = 0.0f;

        real v5 = v4;
        if (v3 >= 1.0f)
            v5 = 1.0f;

        return powf(v5, 2.2f);
    }
    inline real real_rgb_color::value_regamma(real value) {
        real v3 = value;
        if (value <= 0.0f)
            v3 = 0.0f;

        real v4 = value;
        if (value <= 0.0f)
            v4 = 0.0f;

        real v5 = v4;
        if (v3 >= 1.0f)
            v5 = 1.0f;

        return powf(v5, 0.45454544f);
    }

    // real_argb_color
    constexpr real_argb_color::real_argb_color() {}
    constexpr real_argb_color::real_argb_color(real alpha, const real_rgb_color& color) : rgb(color), alpha(alpha) {}

    // real_rgba_color
    constexpr real_rgba_color::real_rgba_color() {}
    constexpr real_rgba_color::real_rgba_color(const real_rgb_color& rgb, real alpha) : rgb(rgb), alpha(alpha) {}

    // real_hsv_color
    constexpr real_hsv_color::real_hsv_color() {}
    constexpr real_hsv_color::real_hsv_color(real hue, real saturation, real value) : hue(hue), saturation(saturation), value(value) {}
    constexpr real_hsv_color::real_hsv_color(const real_rgb_color& rgb) {
        real min = min(rgb.red, min(rgb.green, rgb.blue));
        real max = max(rgb.red, max(rgb.green, rgb.blue));
        real delta = max - min;

        value = max;
        if (max != 0.0f)
            saturation = delta / max;
        else {
            saturation = 0.0f;
            hue = -1.0f;
            return;
        }

        if (rgb.red == max)
            hue = (rgb.green - rgb.blue) / delta;
        else if (rgb.green == max)
            hue = 2.0f + (rgb.blue - rgb.red) / delta;
        else
            hue = 4.0f + (rgb.red - rgb.green) / delta;

        hue *= 60.0f;
        if (hue < 0.0f)
            hue += 360.0f;
    }

    // real_hsva_color
    constexpr real_hsva_color::real_hsva_color() {}
    constexpr real_hsva_color::real_hsva_color(const real_hsv_color& hsv, real alpha) : hsv(hsv), alpha(alpha) {}
	constexpr real_hsva_color::real_hsva_color(const real_rgb_color& rgb, real alpha) : hsv(rgb), alpha(alpha) {}

	// global colors
    constexpr byte_argb_color g_byte_argb_white(255, { 255, 255, 255 });
    constexpr byte_argb_color g_byte_argb_black(255, { 0, 0, 0 });
    constexpr byte_argb_color g_byte_argb_red(255, { 255, 0, 0 });
    constexpr byte_argb_color g_byte_argb_green(255, { 0, 255, 0 });
    constexpr byte_argb_color g_byte_argb_blue(255, { 0, 0, 255 });
    constexpr byte_argb_color g_byte_argb_yellow(255, { 255, 255, 0 });

    constexpr real_rgba_color g_real_rgba_white({ 1.0f, 1.0f, 1.0f }, 1.0f);
    constexpr real_rgba_color g_real_rgba_black({ 0.0f, 0.0f, 0.0f }, 1.0f);
    constexpr real_rgba_color g_real_rgba_red({ 1.0f, 0.0f, 0.0f }, 1.0f);
    constexpr real_rgba_color g_real_rgba_green({ 0.0f, 1.0f, 0.0f }, 1.0f);
    constexpr real_rgba_color g_real_rgba_blue({ 0.0f, 0.0f, 1.0f }, 1.0f);
    constexpr real_rgba_color g_real_rgba_yellow({ 1.0f, 1.0f, 0.0f }, 1.0f);
}

// real math
namespace libmcc {
    constexpr real_point2d::real_point2d() {}
    constexpr real_point2d::real_point2d(real x, real y) : x(x), y(y) {}
    constexpr real_point2d real_point2d::operator * (real scalar) { return { x * scalar, y * scalar }; }

    constexpr real_point3d::real_point3d() {}
    constexpr real_point3d::real_point3d(real x, real y, real z) : x(x), y(y), z(z) {}
    constexpr real_point3d::real_point3d(const real_point3d& p, const real_vector3d& v, float f) {
        x = p.x + v.i * f;
        y = p.y + v.j * f;
        z = p.z + v.k * f;
    }

    constexpr real_vector2d::real_vector2d() {}
    constexpr real_vector2d::real_vector2d(real i, real j) : i(i), j(j) {}
    constexpr void real_vector2d::operator += (const real_vector2d& other) {
        i += other.i;
        j += other.j;
    }
    inline real real_vector2d::distance(const real_vector2d& other) const {
        real dx = i - other.i;
        real dy = j - other.j;
        return std::sqrt(dx * dx + dy * dy);
    }
    inline real real_vector2d::normalize() {
        real length = std::sqrt(i * i + j * j);
        i /= length;
        j /= length;
        return length;
    }

    constexpr real_vector3d::real_vector3d() {}
    constexpr real_vector3d::real_vector3d(real i, real j, real k) : i(i), j(j), k(k) {}
    constexpr real_vector3d::real_vector3d(const real_point3d& p0, const real_point3d& p1) : i(p1.x - p0.x), j(p1.y - p0.y), k(p1.z - p0.z) {}
    constexpr real_vector3d::real_vector3d(const real_vector3d& up, const real_vector3d& forward) : i(up.j* forward.k - up.k * forward.j), j(up.k* forward.i - up.i * forward.k), k(up.i* forward.j - up.j * forward.i) {}
    constexpr double real_vector3d::magnitude_squared3d() const { return i * i + j * j + k * k; }
    inline real real_vector3d::magnitude3d() const { return std::sqrt(magnitude_squared3d()); }

    constexpr real_euler_angles2d::real_euler_angles2d() {}
    constexpr real_euler_angles2d::real_euler_angles2d(angle yaw, angle pitch) : yaw(yaw), pitch(pitch) {}
    inline real_euler_angles2d::real_euler_angles2d(const real_vector3d& vector) : yaw(std::atan2(vector.j, vector.i)), pitch(std::atan2(vector.k, std::sqrt(vector.i* vector.i + vector.j * vector.j))) {}

    constexpr real_euler_angles3d::real_euler_angles3d() {}
	constexpr real_euler_angles3d::real_euler_angles3d(angle yaw, angle pitch, angle roll) : yaw(yaw), pitch(pitch), roll(roll) {}

    constexpr real_quaternion::real_quaternion() {}
    constexpr real_quaternion::real_quaternion(const real_matrix3x3& matrix) {
        double trace, r, s;

        trace = matrix.forward.i + matrix.left.j + matrix.up.k;

        if (trace > 0.0f) {
            r = std::sqrt(trace + 1.0);
            s = 0.5 / r;

            this->w = 0.5 * r;
			this->i = (matrix.left.k - matrix.up.j) * s;
			this->j = (matrix.up.i - matrix.forward.k) * s;
			this->k = (matrix.forward.j - matrix.left.i) * s;
        } else {
            int x = matrix.left.j > matrix.forward.i;

            if (matrix.up.k > matrix.n[x][x]) {
                x = 2;
            }

            int y = (x + 1) % 3;
            int z = (x + 2) % 3;

            trace = matrix.n[x][x] - matrix.n[y][y] - matrix.n[z][z];

            r = std::sqrt(trace + 1.0);
            s = 0.5 / r;

            this->n[x] = 0.5 * r;
            this->n[y] = (matrix.n[x][y] + matrix.n[y][x]) * s;
            this->n[z] = (matrix.n[z][x] + matrix.n[x][z]) * s;
            this->w = (matrix.n[y][z] - matrix.n[z][y]) * s;
        }

        if (this->w < 0.0f) {
            this->w = -this->w;
            this->i = -this->i;
            this->j = -this->j;
            this->k = -this->k;
        }
    }
}
