#pragma once

#include "../native.h"

namespace libmcc::halo3 {
    inline void process_game_engine_globals_messages() {
        return INVOKE<void>(_func_process_game_engine_globals_messages)();
    }
}
