#pragma once

#include <array>

enum e_button_mapping : char {
    _button_mapping_none = -1,
    _button_mapping_left_trigger = 0,
    _button_mapping_right_trigger = 1,
    _button_mapping_dpad_up = 2,
    _button_mapping_dpad_down = 3,
    _button_mapping_dpad_left = 4,
    _button_mapping_dpad_right = 5,
    _button_mapping_start = 6,
    _button_mapping_back = 7,
    _button_mapping_left_thumb = 8,
    _button_mapping_right_thumb = 9,
    _button_mapping_left_shoulder = 10,
    _button_mapping_right_shoulder = 11,
    _button_mapping_a = 12,
    _button_mapping_b = 13,
    _button_mapping_x = 14,
    _button_mapping_y = 15,
};

struct s_gamepad_input_preferences {
    e_button_mapping actions[66];
};

extern std::array<const char*, 16> g_button_names;
extern std::array<const char*, 66> g_action_names;

inline const std::array<const char*, 16>* button_names() {return &g_button_names;}
inline const std::array<const char*, 66>* action_names() {return &g_action_names;}