#pragma once

namespace libmcc {
    struct s_custom_keyboard_mouse_mapping_v2 {
        int abstract_button;
        int virtual_key_codes[5];
    };

    static_assert(sizeof(s_custom_keyboard_mouse_mapping_v2) == 0x18);

    enum e_gamepad_button : char {
        _gamepad_button_left_trigger,
        _gamepad_button_right_trigger,
        _gamepad_button_dpad_up,
        _gamepad_button_dpad_down,
        _gamepad_button_dpad_left,
        _gamepad_button_dpad_right,
        _gamepad_button_start,
        _gamepad_button_back,
        _gamepad_button_left_thumb,
        _gamepad_button_right_thumb,
        _gamepad_button_left_shoulder,
        _gamepad_button_right_shoulder,
        _gamepad_button_a,
        _gamepad_button_b,
        _gamepad_button_x,
        _gamepad_button_y,

        k_gamepad_button_count,
        k_gamepad_button_none = -1,
    };

    enum e_gamepad_button_action : char {
        _gamepad_button_action_jump,
        _gamepad_button_action_switch_grenades_1,
        _gamepad_button_action_action,
        _gamepad_button_action_reload_right_weapon,
        _gamepad_button_action_change_weapon,
        _gamepad_button_action_melee,
        _gamepad_button_action_toggle_flashlight,
        _gamepad_button_action_throw_grenade,
        _gamepad_button_action_use_right_weapon,
        _gamepad_button_action_crouch,
        _gamepad_button_action_player_zoom,
        _gamepad_button_action_unknown_1,
        _gamepad_button_action_unknown_2,
        _gamepad_button_action_swap_reload_left_weapon,
        _gamepad_button_action_sprint,
        _gamepad_button_action_banshee_bomb,
        _gamepad_button_action_player_move_forward,
        _gamepad_button_action_player_move_backward,
        _gamepad_button_action_player_move_left,
        _gamepad_button_action_player_move_right,
        _gamepad_button_action_multiplayer_scoreboard,
        _gamepad_button_action_vehicle_function_2,
        _gamepad_button_action_vehicle_function_3,
        _gamepad_button_action_use_equipment,
        _gamepad_button_action_vehicle_function_1,
        _gamepad_button_action_editor_ascend,
        _gamepad_button_action_editor_descend,
        _gamepad_button_action_drop_pickup,
        _gamepad_button_action_thrust,
        _gamepad_button_action_precision_mode,
        _gamepad_button_action_delete,
        _gamepad_button_action_object_options,
        _gamepad_button_action_tools,
        _gamepad_button_action_play_edit,
        _gamepad_button_action_editor_zoom,
        _gamepad_button_action_rotate,
        _gamepad_button_action_toggle_panel,
        _gamepad_button_action_toggle_interface,
        _gamepad_button_action_toggle_first_third_person,
        _gamepad_button_action_camera_reset,
        _gamepad_button_action_jump_forward,
        _gamepad_button_action_jump_back,
        _gamepad_button_action_pause_resume_playback,
        _gamepad_button_action_fast_forward,
        _gamepad_button_action_toggle_freecam,
        _gamepad_button_action_boost,
        _gamepad_button_action_theater_panning,
        _gamepad_button_action_theater_ascend,
        _gamepad_button_action_theater_descend,
        _gamepad_button_action_use_left_weapon,
        _gamepad_button_action_theater_zoom,
        _gamepad_button_action_toggle_rotation_axes,
        _gamepad_button_action_duplicate,
        _gamepad_button_action_lock,
        _gamepad_button_action_reset,
        _gamepad_button_action_select_next_grenades_2,
        _gamepad_button_action_select_previous_grenades_2,
        _gamepad_button_action_special_action,
        _gamepad_button_action_open_loadouts_menu,
        _gamepad_button_action_toggle_display_waypoint_markers,
        _gamepad_button_action_toggle_display_waypoint_markers_alternative,
        _gamepad_button_action_push_to_talk,
        _gamepad_button_action_vehicle_ascend,
        _gamepad_button_action_vehicle_descend,
        _gamepad_button_action_select_previous_grenades,
        _gamepad_button_action_select_next_grenades,

		k_gamepad_button_action_count,
		k_gamepad_button_action_none = -1,
    };

    struct s_gamepad_mapping {
        e_gamepad_button actions[k_gamepad_button_action_count];
    };

    static_assert(sizeof(s_gamepad_mapping) == 0x42);
}
