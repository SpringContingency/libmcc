#pragma once

#include "../../native.h"

#include "../render.h"
#include "../render_cameras.h"

namespace libmcc::halo3 {
    enum e_splitscreen_res {
    };

    struct s_splitscreen_view_config {
        real_rectangle2d bounds;
        e_splitscreen_res splitscreen_res;
    };

    class c_splitscreen_config {
        std::array<std::array<std::array<s_splitscreen_view_config, 4>, 4>, 2>* m_config_table() {
            return REF<std::array<std::array<std::array<s_splitscreen_view_config, 4>, 4>, 2>>(s_data_offset_table::c_splitscreen_config__m_config_table);
        }
    };

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