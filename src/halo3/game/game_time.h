#pragma once

namespace Halo3 {
    struct game_time_globals_struct {
        bool initialized;
        uint8_t padding_1;
        uint8_t flags;
        uint8_t padding_2;
        __int16 tick_rate;
        float tick_length;
        int elapsed_ticks;
        float game_speed;
        float ticks_leftover; // [-1.0, 2.0]

        void pause(bool value) {
            if (value) flags |= (1 << 3);
            else flags &= ~(1 << 3);
        }
    };
}
