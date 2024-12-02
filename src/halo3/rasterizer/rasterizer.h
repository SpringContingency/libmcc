#pragma once

namespace Halo3 {
    struct c_rasterizer {
        enum e_surface : uint32_t {
            _surface_none = 0x0,
            _surface_disable = 0x1,
            _surface_display = 0x2,
            _surface_shadow_1 = 0x3,
            _surface_depth_stencil = 0x4,
            _surface_depth_stencil_multisample = 0x5,
            _surface_screenshot_composite_16f = 0x6,
            _surface_accum_LDR = 0x7,
            _surface_accum_HDR = 0x8,
            _surface_albedo = 0x9,
            _surface_albedo_debug = 0xA,
            _surface_gbuf = 0xB,
            _surface_normal = 0xC,
            _surface_post_LDR = 0xD,
            _surface_post_HDR = 0xE,
            _surface_post_half_LDR = 0xF,
            _surface_post_half_HDR = 0x10,
            _surface_normal_half = 0x11,
            _surface_depth_half_fp32 = 0x12,
            _surface_color_half_fp16_0 = 0x13,
            _surface_color_half_fp16_1 = 0x14,
            _surface_fullscreen_blur = 0x15,
            _surface_shadow_color = 0x16,
            _surface_depth_fp32 = 0x17,
            _surface_aux_reflection = 0x18,
            _surface_aux_refraction = 0x19,
            _surface_hdr_retrieve = 0x1A,
            _surface_ssao_noise = 0x1B,
            _surface_screenshot_composite_8bit = 0x1C,
            _surface_screenshot_display = 0x1D,
            _surface_screenshot_composite_16i = 0x1E,
            _surface_aux_bloom = 0x1F,
            _surface_aux_chud = 0x20,
            _surface_aux_star = 0x21,
            _surface_aux_small = 0x22,
            _surface_aux_tiny = 0x23,
            _surface_aux_mini = 0x24,
            _surface_aux_exposure_0 = 0x25,
            _surface_aux_exposure_1 = 0x26,
            _surface_aux_exposure_2 = 0x27,
            _surface_aux_exposure_3 = 0x28,
            _surface_aux_exposure_4 = 0x29,
            _surface_aux_exposure_5 = 0x2A,
            _surface_aux_exposure_6 = 0x2B,
            _surface_aux_exposure_7 = 0x2C,
            _surface_aux_small2 = 0x2D,
            _surface_aux_tiny2 = 0x2E,
            _surface_aux_mini2 = 0x2F,
            _surface_aux_depth_of_field2 = 0x30,
            _surface_aux_depth_of_field = 0x31,
            _surface_distortion = 0x32,
            _surface_depth_camera_depth = 0x33,
            _surface_depth_camera = 0x34,
            _surface_aux_water_interaction_height = 0x35,
            _surface_aux_water_interaction_slope = 0x36,
            _surface_chud_turbulence = 0x37,
            _surface_cortana_effect_mua_haha = 0x38,
            _surface_surface_depth_camera_texture = 0x39,
            _surface_surface_weather_occlusion = 0x3A,
            _surface_surface_depth_visr = 0x3B,
            k_number_of_surfaces = 0x3C,
        };
    };

    struct rasterizer_game_states_definition {
        bool motion_blur;
        bool atmosphere_fog;
        bool patchy_fog;
        bool render_weather;
        bool cinematic_motion_blur;
    };
}