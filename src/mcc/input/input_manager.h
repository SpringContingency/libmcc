#pragma once

#include "./input_device.h"

namespace MCC {
    class c_input_manager {
    public:
        virtual c_input_manager* initialize(bool value) = 0;
        virtual bool input_update(int player_index, s_player_input_state* input_data, bool un) = 0;
        virtual bool mouse_update(int player_index, s_mouse_state* input_data) = 0;
        virtual void gamepad_set_state(int player_index, XINPUT_VIBRATION* state) = 0;
        virtual void clear_state() = 0;
        virtual bool unknown() = 0;
        virtual int new_device(int device_index) = 0;
        virtual void update(float time1, float time2, bool un = false);
        virtual bool unused() {return 1;}

    public:
        c_input_device* p_input_device[5];
        char buffer[0x90];
        HWND hwnd; // 0xC0
        LARGE_INTEGER qpc; // 0xC8
    };
}