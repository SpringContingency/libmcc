#pragma once

#include "../render.h"
#include "../render_cameras.h"

namespace libmcc::halo3 {

    struct c_view {
        virtual void render() = 0;
        virtual int render_setup() = 0;
        virtual int compute_visibility() = 0;
        virtual int render_submit_visibility() = 0;

        render_camera m_default_rasterizer_camera;
        render_projection m_default_rasterizer_projection;
        render_camera m_render_camera;
        render_projection m_render_projection;
    };

    struct c_world_view : c_view {

    };

    struct c_player_view : c_world_view {
        char data[9592];
    };

    static_assert(sizeof(c_player_view) == 10272);
}