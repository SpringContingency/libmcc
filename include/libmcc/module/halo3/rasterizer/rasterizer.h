#pragma once

#include "../native.h"

#include "./rasterizer_globals.h"

namespace libmcc::halo3 {
    struct rasterizer_vertex_debug {
        rasterizer_vertex_debug() {
        }

        real_point3d point;
        byte_argb_color color;
    };

    inline int* g_current_cull_mode() {
        return REF<int>(_data_g_current_cull_mode);
    }

    inline int* g_cull_mode_changed() {
        return REF<int>(_data_g_cull_mode_changed);
    }

    class c_rasterizer_index_buffer {
    public:
        enum e_primitive_type : int {
            _primitive_type_point_list = 0x0,
            _primitive_type_line_list = 0x1,
            _primitive_type_list_strip = 0x2,
            _primitive_type_triangle_list = 0x3,
            _primitive_type_triangle_fan = 0x4,
            _primitive_type_triangle_strip = 0x5,
            _primitive_type_force_dword = 0x6,
            k_primitive_type_count = 0x7,
        };
    };

    struct c_rasterizer {
        enum e_z_buffer_mode : int {
            _z_buffer_mode_unknown0 = 0x0,
            _z_buffer_mode_unknown1 = 0x1,
            _z_buffer_mode_unknown2 = 0x2,
            _z_buffer_mode_unknown3 = 0x3,
            _z_buffer_mode_unknown4 = 0x4,
            _z_buffer_mode_unknown5 = 0x5,
            _z_buffer_mode_unknown6 = 0x6,
            _z_buffer_mode_unknown7 = 0x7,
            _z_buffer_mode_unknown8 = 0x8,
            k_z_buffer_mode_count = 0x9,
        };

        enum e_cull_mode : int {
            _cull_mode_none = 0x1,
            _cull_mode_clockwise = 0x2,
            _cull_mode_counter_clockwise = 0x3,
            _cull_mode_force_dword = 0x7FFFFFFF,
        };

        static bool set_explicit_shaders(c_rasterizer_globals::e_explicit_shader explicit_shader,
                                         e_vertex_type base_vertex_type,
                                         e_transfer_vector_vertex_types transfer_vertex_type,
                                         e_entry_point entry_point,
                                         void **shader) {
            return INVOKE<bool>(_func_c_rasterizer_set_explicit_shaders, explicit_shader, base_vertex_type,
                                transfer_vertex_type, entry_point, shader);
        }

        static void set_pixel_shader_constant(int start_register, int vector4f_count, real_vector4d *constant_data) {
            INVOKE<void>(_func_c_rasterizer_set_pixel_shader_constant, start_register, vector4f_count, constant_data);
        }

        static void set_cull_mode(e_cull_mode cull_mode) {
            auto current_cull_mode = g_current_cull_mode();
            auto cull_mode_changed = g_cull_mode_changed();
            auto new_value = *current_cull_mode & 0xFFFFFFF3 | (4 * cull_mode);

            if (new_value != *current_cull_mode) {
                *current_cull_mode = new_value;
                *cull_mode_changed |= 1;
            }
        }

        static void set_z_buffer_mode(e_z_buffer_mode z_buffer_mode) {
            INVOKE<void>(_func_c_rasterizer_set_z_buffer_mode, z_buffer_mode);
        }

        static void draw_primitive_up(c_rasterizer_index_buffer::e_primitive_type type, UINT primitive_count,
                                      const void *stream_data, UINT stride) {
            INVOKE<void>(_func_c_rasterizer_draw_primitive_up, type, primitive_count, stream_data, stride);
        }

        static bool draw_debug_linestrip2d(short_point2d *points, int point_count, uint32_t color) {
            return INVOKE<bool>(_func_c_rasterizer_draw_debug_linestrip2d, points, point_count, color);
        }

        static void set_indices(int) {
        }

        static void draw_debug_line_list2d_explicit(rasterizer_vertex_debug *vertex_debug, UINT primitive_count) {
            if (set_explicit_shaders(c_rasterizer_globals::_explicit_shader_debug2d, _vertex_type_debug,
                                     _transfer_vector_vertex_type_unknown0, _entry_point_default, nullptr)) {
                set_cull_mode(_cull_mode_none);
                set_z_buffer_mode(_z_buffer_mode_unknown2);

                real_vector4d constant{1.0f, 1.0f, 1.0f, 1.0f};
                set_pixel_shader_constant(0x120000LL, 1, &constant);
                set_indices(0);
                draw_primitive_up(
                    c_rasterizer_index_buffer::_primitive_type_line_list,
                    primitive_count,
                    vertex_debug,
                    sizeof(rasterizer_vertex_debug));
                set_cull_mode(_cull_mode_clockwise);
            }
        }

        static void draw_debug_line_list_explicit(rasterizer_vertex_debug *vertex_debug, UINT primitive_count) {
            if (set_explicit_shaders(c_rasterizer_globals::_explicit_shader_debug, _vertex_type_debug,
                                     _transfer_vector_vertex_type_unknown0, _entry_point_default, nullptr)) {
                set_cull_mode(_cull_mode_none);
                set_z_buffer_mode(_z_buffer_mode_unknown1);
                set_indices(0);
                draw_primitive_up(
                    c_rasterizer_index_buffer::_primitive_type_line_list,
                    primitive_count,
                    vertex_debug,
                    sizeof(rasterizer_vertex_debug));
                set_cull_mode(_cull_mode_clockwise);
            }
        }
    };
}
