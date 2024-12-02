#pragma once

#include <stdint.h>
#include <Windows.h>
#include <Xinput.h>

union s_keyboard_state {
    struct {
        bool keys_pressed[256];
    };
    struct {
        unsigned char keys[256];
    };
};

struct s_mouse_state {
    float lX;
    float lY;
    float pX;
    float pY;
    float lZ;
    float lZScale;
    union {
        uint32_t value;
        struct {
            uint8_t left_button : 1;
            uint8_t right_button : 1;
            uint8_t middle_button : 1;
            uint8_t button_4 : 1;
            uint8_t button_5 : 1;
        };
    } buttons;
};

struct s_gamepad_state {
    union {
        int value;
        struct {
            uint8_t dpad_up : 1;
            uint8_t dpad_down : 1;
            uint8_t dpad_left : 1;
            uint8_t dpad_right : 1;
            uint8_t start : 1;
            uint8_t back : 1;
            uint8_t left_thumb : 1;
            uint8_t right_thumb : 1;
            uint8_t left_shoulder : 1;
            uint8_t right_shoulder : 1;
            uint8_t a : 1;
            uint8_t b : 1;
            uint8_t x : 1;
            uint8_t y : 1;
        };
    } buttons;

    unsigned char leftTrigger;
    unsigned char rightTrigger;
    short thumbLX;
    short thumbLY;
    short thumbRX;
    short thumbRY;

    void set_value(XINPUT_GAMEPAD gamepad) {
        buttons.value = gamepad.wButtons;
        leftTrigger = gamepad.bLeftTrigger;
        rightTrigger = gamepad.bRightTrigger;
        thumbLX = gamepad.sThumbLX;
        thumbLY = gamepad.sThumbLY;
        thumbRX = gamepad.sThumbRX;
        thumbRY = gamepad.sThumbRY;
    }
};

static_assert(sizeof(s_gamepad_state) == 0x10);

struct s_player_input_state {
    int is_km;
    s_keyboard_state keyboard;
    s_mouse_state mouse;
    s_gamepad_state gamepad; // 0x130
};

static_assert(sizeof(s_player_input_state) == 0x130);
