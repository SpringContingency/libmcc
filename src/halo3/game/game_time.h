#pragma once

namespace Halo3 {
    struct game_time_globals_struct {
        bool initialized;
        __int8 padding_1;
        __int8 flags;
        __int8 padding_2;
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
