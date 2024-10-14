#pragma once

#include "../../shared/input/input.h"

namespace MCC {
    class c_input_device {
    public:
        virtual void unknown_0() = 0;
        virtual void unknown_1() = 0;
        virtual void unknown_2() = 0;
        virtual void unknown_3() = 0;
        virtual void unknown_4() = 0;
        virtual void unknown_5() = 0;
        virtual void unknown_6() = 0;
        virtual __int64 set_state(float a2, s_player_input_data* a3) = 0;
        virtual void check() = 0;
        virtual void un_1() = 0;
        virtual bool sub_14087A6FC(float a2) = 0;
        virtual char input_mouse_update(float a2, void* p_mouse) = 0;

    public:
        char un0[2040];
        bool enable_mouse;
        char un[0x7];
        int input_user;// 0x808
        char un1[0x110];
        XINPUT_STATE state; // 0x91C

    };
}