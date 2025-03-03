#pragma once

#include "../rasterizer/rasterizer.h"
#include "./view/render_player_view.h"

namespace libmcc::halo3 {
    struct c_render_debug_line_drawer {
        c_render_debug_line_drawer() : m_type(2), m_vertex_count(0){}
		~c_render_debug_line_drawer() {flush();}

        void set_color(const real_rgba_color* color) {
            color->rgb.degamma(m_real_color.rgb);
            m_real_color.alpha = color->alpha;
            m_byte_color = m_real_color;
        }

        void add_line_3d(const real_point3d* p0, const real_point3d* p1) {
            if (m_type != 2 || m_vertex_count + 2 >= 512) {
                flush();
                m_type = 2;
            }

            auto vertex = m_vertices + m_vertex_count;
            m_vertex_count += 2;

            vertex[0].point = *p0;
            vertex[0].color = m_byte_color;

            vertex[1].point = *p1;
            vertex[1].color = m_byte_color;
        }

        void add_line_3d_unclipped(const c_player_view* player_view, const real_point3d *p0, const real_point3d *p1) {
            auto point0 = *p0;
            auto point1 = *p1;

            auto render_camera = &player_view->m_render_camera;
            auto rasterizer_camera = &player_view->m_default_rasterizer_camera;

            real_matrix4x3 camera(render_camera->position, render_camera->forward, render_camera->up, 1.0f);

            real_vector3d vector0(camera.center, point0);
            real_vector3d vector1(camera.center, point1);

            real clip_distance = fmax(vector0.magnitude3d(), vector1.magnitude3d());

            if (clip_distance > (0.5f * rasterizer_camera->z_far)) {
                real distance = (0.5f * rasterizer_camera->z_far) / clip_distance;
                point0 = real_point3d(camera.center, vector0, distance);
                point1 = real_point3d(camera.center, vector1, distance);
            }

            add_line_3d(&point0, &point1);
        }

        void flush() {
            if (m_vertex_count <= 0) {
                return;
            }

            if (m_type == 1) {
                c_rasterizer::draw_debug_line_list2d_explicit(m_vertices, m_vertex_count / 2);
            } else if (m_type == 2) {
                c_rasterizer::draw_debug_line_list_explicit(m_vertices, m_vertex_count / 2);
            }

            m_vertex_count = 0;
        }

        int m_type;
        real_argb_color m_real_color;
        byte_argb_color m_byte_color;
        rasterizer_vertex_debug m_vertices[512];
        int m_vertex_count;
    };

}
