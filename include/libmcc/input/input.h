#pragma once

#include <Xinput.h>

namespace libmcc {
    struct s_keyboard_state {
        bool key_down[256];
    };

    static_assert(sizeof(s_keyboard_state) == 0x100);

    struct s_mouse_state {
        float lX;       // relative position in X
        float lY;       // relative position in Y
        float pX;       // absolute position in X
        float pY;       // absolute position in Y
        float lZ;       // relative position in Z
        float lZScale;  // relative position in Z scale
        union {
            struct {
                bool left_button : 1;
                bool right_button : 1;
                bool middle_button : 1;
                bool button_4 : 1;
                bool button_5 : 1;
            };
            int value;
        } buttons;
    };

    static_assert(sizeof(s_mouse_state) == 0x1C);

    struct s_gamepad_state {
        constexpr s_gamepad_state();
        constexpr s_gamepad_state(const XINPUT_STATE& state);

        union {
            struct {
                bool dpad_up : 1;
                bool dpad_down : 1;
                bool dpad_left : 1;
                bool dpad_right : 1;
                bool start : 1;
                bool back : 1;
                bool left_thumb : 1;
                bool right_thumb : 1;
                bool left_shoulder : 1;
                bool right_shoulder : 1;
                bool a : 1;
                bool b : 1;
                bool x : 1;
                bool y : 1;
            };
            int value;
        } buttons;

        unsigned char leftTrigger;
        unsigned char rightTrigger;
        short thumbLX;
        short thumbLY;
        short thumbRX;
        short thumbRY;
    };

    static_assert(sizeof(s_gamepad_state) == 0x10);

    struct s_input_state {
        int is_km;
        s_keyboard_state keyboard;
        s_mouse_state mouse;
        s_gamepad_state gamepad;
    };

    static_assert(sizeof(s_input_state) == 0x130);

    struct s_rumble_state {
        short left_motor_speed;
        short right_motor_speed;
    };
}

namespace libmcc {
    constexpr s_gamepad_state::s_gamepad_state() {}
    constexpr s_gamepad_state::s_gamepad_state(const XINPUT_STATE& state) {
        buttons.value = state.Gamepad.wButtons;
		leftTrigger = state.Gamepad.bLeftTrigger;
		rightTrigger = state.Gamepad.bRightTrigger;
		thumbLX = state.Gamepad.sThumbLX;
		thumbLY = state.Gamepad.sThumbLY;
        thumbRX = state.Gamepad.sThumbRX;
        thumbRY = state.Gamepad.sThumbRY;
    }
}
