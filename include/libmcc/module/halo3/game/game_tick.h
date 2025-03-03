#pragma once

#include <cstdint>

namespace libmcc::halo3 {
    struct game_time_globals_struct {
		// functions
        void pause(bool value) {
            if (value) flags |= (1 << 3);
            else flags &= ~(1 << 3);
        }

        // data
        bool initialized;
        char : 8;
        uint16_t flags;
        uint16_t tick_rate;
        float tick_length;
        int elapsed_ticks;
        float game_speed;
        float ticks_leftover; // [-1.0, 2.0]
    };
}
