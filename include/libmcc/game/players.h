#pragma once

#include "../math/math.h"

#include "./player_loadout.h"
#include "./player_mapping.h"
#include "./player_customization.h"

namespace libmcc {
    struct s_player_profile {
        bool subtitle_setting; // 0x0
        bool subtitle_size_setting; // 0x1
        bool subtitle_background_setting; // 0x2
        bool subtitle_shadow_color_setting; // 0x3
        bool dialogue_color_style_setting; // 0x4
        bool dialogue_color_setting; // 0x5
        bool dialogue_palette_setting; // 0x6
        bool speaker_setting; // 0x7
        bool speaker_color_style_setting; // 0x8
        bool speaker_color_setting; // 0x9
        bool speaker_palette_setting; // 0xA
        bool subtitle_font_setting; // 0xB
        float subtitle_background_opacity_setting; // 0xC
        float subtitle_shadow_opacity_setting; // 0x10

        int fov_setting; // 0x14
        int vehicle_fov_setting; // 0x18

        bool crosshair_location; // 0x1C
        bool look_controls_inverted; // 0x1D
        bool mouse_look_controls_inverted; // 0x1E
        bool vibration_disabled; // 0x1F
        bool impulse_triggers_disabled; // 0x20
        bool aircraft_controls_inverted; // 0x21
        bool mouse_aircraft_controls_inverted; // 0x22
        bool auto_center_enabled; // 0x23
        bool crouch_lock_enabled; // 0x24
        bool mk_crouch_lock_enabled; // 0x25
        bool clench_protection_enabled; // 0x26

        bool use_female_voice; // 0x27
        bool hold_to_zoom; // 0x28
        char padding_0[3];
        int player_model_primary_color_index; // 0x2C
        int player_model_secondary_color_index; // 0x30
        int player_model_tertiary_color_index; // 0x34
        bool use_elite_model; // 0x38
        bool lock_max_aspect_ratio; // 0x39
        char unknown_0; // 0x3A
        bool users_skins_enabled; // 0x3B
        int player_model_permutation; // 0x3C

		s_player_customization player_customization; // 0x40

        wchar_t service_tag[4]; // 0x1AC
        bool online_medal_flasher; // 0x1B4

        bool vertical_look_sensitivity; // 0x1B5
        bool horizontal_look_sensitivity; // 0x1B6
        bool look_acceleration; // 0x1B7
        float look_axial_dead_zone; // 0x1B8
        float look_radial_dead_zone; // 0x1BC
        float zoom_look_sensitivity_multiplier; // 0x1C0
        float vehicle_look_sensitivity_multiplier; // 0x1C4
        bool button_preset; // 0x1C8
        bool stick_preset; // 0x1C9
        bool lefty_toggle; // 0x1CA
        bool flying_camera_turn_sensitivity; // 0x1CB
        bool flying_camera_panning; // 0x1CC
        bool flying_camera_speed; // 0x1CD
        bool flying_camera_thrust; // 0x1CE
        bool theater_turn_sensitivity; // 0x1CF
        bool theater_panning; // 0x1D0
        bool theater_speed; // 0x1D1
        bool theater_thrust; // 0x1D2
        bool mk_theater_turn_sensitivity; // 0x1D3
        bool mk_theater_panning; // 0x1D4
        bool mk_theater_speed; // 0x1D5
        bool mk_theater_thrust; // 0x1D6
        bool swap_triggers_and_bumpers; // 0x1D7
        bool use_modern_aim_control; // 0x1D8
        bool use_double_press_jump_to_jetpack; // 0x1D9
        bool dual_wield_inverted; // 0x1DA
        bool controller_dual_wield_inverted; // 0x1DB
        bool controller_hornet_control_joystick; // 0x1DC
        bool controller_banshee_trick_buttons_swapped; // 0x1DD

        bool color_correction; // 0x1DE
        bool enemy_player_name_color; // 0x1DF
        int game_engine_timer; // 0x1E0

        s_player_loadout loadout_slots[5]; // 0x1E4

        char game_specific[0x100]; // 0x310
        float mouse_sensitivity; // 0x410
        bool mouse_smoothing; // 0x414
        bool mouse_acceleration; // 0x415
        uint16_t pixel_perfect_hud_scale; // 0x416
        float mouse_acceleration_min_rate; // 0x418
        float mouse_acceleration_max_accel; // 0x41C
        float mouse_acceleration_scale; // 0x420
        float mouse_acceleration_exp; // 0x424
        int keyboard_mouse_button_preset; // 0x428

        s_custom_keyboard_mouse_mapping_v2 custom_keyboard_mouse_mapping_v2[66]; // 0x42C

        float master_volume; // [0.0, 1.0] 0xA5C
        float music_volume; // [0.0, 1.0] 0xA60
        float sfx_volume; // [0.0, 1.0] 0xA64

        char unknown_1[0xC]; // 0xA68

        float brightness; // 0xA74

        real_point3d weapon_display_offset[5]; // 0xA78

        int color_blind_mode; // 0xAB4
        int color_blind_strength; // 0xAB8
        int color_blind_brightness; // 0xABC
        int color_blind_contrast; // 0xAC0
        int remastered_hud_setting; // 0xAC4
        float hud_scale; // 0xAC8
    };

    static_assert(sizeof(s_player_profile) == 0xACC);
}

