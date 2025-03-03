#pragma once

#include "../native.h"

namespace libmcc::halo3 {
    struct render_camera {
        real_point3d position;
        real_vector3d forward;
        real_vector3d up;
        bool mirrored;
        real vertical_field_of_view;
        real horizontal_field_of_view;
        rectangle2d window_pixel_bounds;
        rectangle2d window_title_safe_pixel_bounds;
        __int16 __unknown40;
        __int16 __unknown42;
        rectangle2d render_pixel_bounds;
        rectangle2d render_title_safe_pixel_bounds;
        rectangle2d display_pixel_bounds;
        real z_near;
        real z_far;
        real_plane3d mirror_plane;
        bool __unknown74;
        real_rectangle2d __unknown78;
        uint64_t : 64;
    };

    static_assert(sizeof(render_camera) == 144);
}

