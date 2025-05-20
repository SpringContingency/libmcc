#pragma once

#include "../geometry/geometry_definitions.h"

namespace libmcc::halo3 {
    struct c_rasterizer_vertex_buffer {
        
    };

    struct c_rasterizer_index_buffer {
        enum e_primitive_type : char {
            _primitive_type_default, // D3D_PRIMITIVE_TOPOLOGY_POINTLIST 
            _primitive_type_line_list, // D3D_PRIMITIVE_TOPOLOGY_LINELIST
            _primitive_type_line_strip, // D3D_PRIMITIVE_TOPOLOGY_LINESTRIP 
            _primitive_type_triangle_list, // D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST 
            _primitive_type_triangle_fan, // D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST | 2 : D3D_PRIMITIVE_TOPOLOGY_TRIANGLESTRIP
            _primitive_type_triangle_strip, // D3D_PRIMITIVE_TOPOLOGY_TRIANGLESTRIP
            _primitive_type_quad_list, // D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST
        };
    };

    enum e_transfer_vector_vertex_types : uint32_t {
        _transfer_vector_vertex_type_unknown0 = 0x0,
        _transfer_vector_vertex_type_unknown1 = 0x1,
        _transfer_vector_vertex_type_unknown2 = 0x2,
        _transfer_vector_vertex_type_unknown3 = 0x3,
        k_number_of_transfer_vertex_types = 0x4,
    };

    enum e_entry_point : uint32_t {
        _entry_point_default = 0x0,
        _entry_point_albedo = 0x1,
        _entry_point_static_default = 0x2,
        _entry_point_static_per_pixel = 0x3,
        _entry_point_static_per_vertex = 0x4,
        _entry_point_static_sh = 0x5,
        _entry_point_static_prt_ambient = 0x6,
        _entry_point_static_prt_linear = 0x7,
        _entry_point_static_prt_quadratic = 0x8,
        _entry_point_dynamic_light = 0x9,
        _entry_point_shadow_generate = 0xA,
        _entry_point_shadow_apply = 0xB,
        _entry_point_active_camo = 0xC,
        _entry_point_lightmap_debug_mode = 0xD,
        _entry_point_vertex_color_lighting = 0xE,
        _entry_point_water_tessellation = 0xF,
        _entry_point_water_shading = 0x10,
        _entry_point_dynamic_light_cinematic = 0x11,
        _entry_point_z_only = 0x12,
        _entry_point_sfx_distort = 0x13,
        k_entry_point_count = 0x14,
    };

    struct c_rasterizer_globals {
        enum e_explicit_shader : uint32_t {
            _explicit_shader_debug = 0x0,
            _explicit_shader_debug2d = 0x1,
            _explicit_shader_copy_with_scale = 0x2,
            _explicit_shader_bloom_spike_blur_vertical = 0x3,
            _explicit_shader_bloom_spike_blur_horizontal = 0x4,
            _explicit_shader_bloom_downsample_4x4_with_bloom_curve = 0x5,
            _explicit_shader_bloom_downsample_4x4 = 0x6,
            _explicit_shader_bloom_copy_rgbe_to_rgb = 0x7,
            _explicit_shader_bloom_update_persistence = 0x8,
            _explicit_shader_bloom_add_downsampled = 0x9,
            _explicit_shader_bloom_add = 0xA,
            _explicit_shader_bloom_kernel_blur_11_horizontal = 0xB,
            _explicit_shader_bloom_kernel_blur_11_vertical = 0xC,
            _explicit_shader_cubemap_blur_phi = 0xD,
            _explicit_shader_cubemap_blur_theta = 0xE,
            _explicit_shader_cubemap_clamp = 0xF,
            _explicit_shader_cubemap_divide = 0x10,
            _explicit_shader_write_depth = 0x11,
            _explicit_shader_final_composite = 0x12,
            _explicit_shader_sky_dome_simple = 0x13,
            _explicit_shader_transparent = 0x14,
            _explicit_shader_legacy_shield_meter = 0x15,
            _explicit_shader_legacy_general_meter = 0x16,
            _explicit_shader_overhead_map_geometry = 0x17,
            _explicit_shader_legacy_hud_bitmap = 0x18,
            _explicit_shader_bloom_blend_3_textures = 0x19,
            _explicit_shader_particle_update = 0x1A,
            _explicit_shader_particle_spawn = 0x1B,
            _explicit_shader_screenshot_combine = 0x1C,
            _explicit_shader_downsample_2x2 = 0x1D,
            _explicit_shader_rotate_2d = 0x1E,
            _explicit_shader_bspline_resample = 0x1F,
            _explicit_shader_bloom_downsample_4x4_with_bloom_curve_and_dof = 0x20,
            _explicit_shader_final_composite_with_dof = 0x21,
            _explicit_shader_convolve_5_tap_kernel = 0x22,
            _explicit_shader_exposure_downsample = 0x23,
            _explicit_shader_yuv_to_rgb = 0x24,
            _explicit_shader_displacement = 0x25,
            _explicit_shader_screenshot_display = 0x26,
            _explicit_shader_downsample_4x4_block = 0x27,
            _explicit_shader_crop = 0x28,
            _explicit_shader_screenshot_combine_with_dof = 0x29,
            _explicit_shader_gamma_correction = 0x2A,
            _explicit_shader_contrail_spawn = 0x2B,
            _explicit_shader_contrail_update = 0x2C,
            _explicit_shader_stencil_8x8_dither_pattern = 0x2D,
            _explicit_shader_lens_flare_render = 0x2E,
            _explicit_shader_decorator_render = 0x2F,
            _explicit_shader_bloom_new_downsample_4x4_block_with_bloom_curve = 0x30,
            _explicit_shader_bloom_new_downsample_4x4_gaussian = 0x31,
            _explicit_shader_apply_color_matrix = 0x32,
            _explicit_shader_copy = 0x33,
            _explicit_shader_shadow_geometry = 0x34,
            _explicit_shader_shadow_apply = 0x35,
            _explicit_shader_gradient = 0x36,
            _explicit_shader_alpha_test = 0x37,
            _explicit_shader_patchy_fog = 0x38,
            _explicit_shader_light_volume = 0x39,
            _explicit_shader_water_ripple = 0x3A,
            _explicit_shader_double_gradient = 0x3B,
            _explicit_shader_sniper_scope = 0x3C,
            _explicit_shader_shield_impact = 0x3D,
            _explicit_shader_player_emblem_world = 0x3E,
            _explicit_shader_player_emblem_screen = 0x3F,
            _explicit_shader_implicit_hill = 0x40,
            _explicit_shader_chud_overlay_blend = 0x41,
            _explicit_shader_bloom_add_alpha1 = 0x42,
            _explicit_shader_bloom_new_downsample_4x4_block_with_bloom_curve_ldr = 0x43,
            _explicit_shader_restore_ldr_hdr_and_depth_to_edram = 0x44,
            _explicit_shader_beam = 0x45,
            _explicit_shader_decorators_no_wind = 0x46,
            _explicit_shader_decorators_static = 0x47,
            _explicit_shader_decorators_sun_only = 0x48,
            _explicit_shader_decorators_wavy = 0x49,
            _explicit_shader_final_composite_zoom = 0x4A,
            _explicit_shader_final_composite_debug = 0x4B,
            _explicit_shader_displacement_with_motion_blur = 0x4C,
            _explicit_shader_screenshot_memexport = 0x4D,
            _explicit_shader_bloom_new_downsample_4x4_gauss_with_curve_ldr = 0x4E,
            _explicit_shader_decorators_edit = 0x4F,
            _explicit_shader_smirnov_test = 0x50,
            _explicit_shader_fxaa = 0x51,
            _explicit_shader_sniper_scope_stencil_pc = 0x52,
            _explicit_shader_ssao = 0x53,
            _explicit_shader_ssao_blur = 0x54,
            _explicit_shader_lightshafts = 0x55,
            _explicit_shader_radial_blur = 0x56,
            _explicit_shader_clear_letterbox = 0x57,
            _explicit_shader_rigid_world_geometry = 0x58,
            _explicit_shader_copy_depth = 0x59,
            _explicit_shader_fsr_easu_with_half_precision = 0x5A,
            _explicit_shader_fsr_easu_without_half_precision = 0x5B,
            _explicit_shader_fsr_rcas_with_half_precision = 0x5C,
            _explicit_shader_fsr_rcas_without_half_precision = 0x5D,
            _explicit_shader_fsr_bilinear = 0x5E,
        };
    };
}
