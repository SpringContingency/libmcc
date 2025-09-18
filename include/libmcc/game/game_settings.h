#pragma once

namespace libmcc {
    enum e_game_setting {
        _game_setting_enable_subtitle = 5,
        _game_setting_new_font_package = 6, // use `_icon` suffix
    };

    union s_setting {
        struct {
            float scale;
            float offset;
        };
        float n[2];
    };

    struct s_render_settings {
        s_setting water_lod;
        s_setting decorator_fade_distance;
        s_setting effects_lod_distance_scale;
        s_setting instance_fade_modifier;
        s_setting object_fade_modifier;
        s_setting object_detail_modifier;
        s_setting object_imposter_cutoff_modifier;
        s_setting decal_fade_distance_scale;
        s_setting structure_instance_lod_modifier;
        s_setting cpu_dynamic_light_max_count;
        s_setting cpu_dynamic_light_scale;
        s_setting gpu_dynamic_light_max_count;
        s_setting gpu_dynamic_light_scale;
        s_setting screenspace_dynamic_light_max_count;
        s_setting screenspace_dynamic_light_scale;
        s_setting shadow_generate_count;
        s_setting shadow_quality_lod;
        s_setting _;
        int disable_object_prt;
        int disable_first_person_shadow;
        int disable_dynamic_lighting_shadows;
        int disable_patchy_fog;
        int disable_cheap_particles;
        int disable_ssao;
        int disable_chud_turbulence;
        int disable_decorator_type_instances;
        int disable_rain;
        int : 32;
    };

    static_assert(sizeof(s_render_settings) == 184);

    struct s_general_video_settings {
        int width;
        int width;
        char texture_resolution;
        char texture_filtering_quality;
        char lighting_quality;
        char effects_quality;
        char : 8;
        char details_quality;
        char post_processing_quality;
        char water_quality;
        char : 8;
        char anti_aliasing;
        char motion_blur;
        char blood;
        char vsync;
        char fps_lock;
        char fidelity_fx_super_resolution;
        char : 8;
    };

    static_assert(sizeof(s_general_video_settings) == 24);

    struct s_game_video_settings {
        s_general_video_settings general;
        char __[160];
        s_render_settings render;
    };

    static_assert(sizeof(s_game_video_settings) == 368);

    struct s_game_audio_settings {
        bool push_to_talk;
        char voice_chat_channel;
        uint16_t : 16;
        float voice_chat_volume;
        float _;
        char primary_user_preferred_input_device;
        uint8_t : 8;
        char voice_chat_input_device[256];
        char voice_chat_output_device[256];
        char audio_output_device[256];
        uint16_t : 16;
        float voice_chat_threshold;
    };

    static_assert(sizeof(s_game_audio_settings) == 788);
}
