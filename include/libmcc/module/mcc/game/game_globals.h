#pragma once

#include "../../../game/game_globals.h"

#include "../native.h"

namespace libmcc::mcc {
    struct s_game_globals : libmcc::s_game_globals {
        static s_game_globals_states* game_globals_states() {
            return REF<s_game_globals_states>(_data_game_globals_states);
        }

        int* state() {
            return reinterpret_cast<int*>(reinterpret_cast<uintptr_t>(this) + 180280);
        }

        LARGE_INTEGER* enter_time () {
            return reinterpret_cast<LARGE_INTEGER*>(reinterpret_cast<uintptr_t>(this) + 180288);
        }

        bool* paused() {
            return reinterpret_cast<bool*>(reinterpret_cast<uintptr_t>(this) + 180324);
        }

        union {
            struct {
                char data_0[168];
                s_game_options options;
                e_game_globals_state target_state;
                e_game_globals_state current_state; // 180188
                HMODULE current_module_handle;
                e_module current_module;
                e_module last_module;
            };

            char raw[0x2C0E8];
        } data;
    };

    static_assert(sizeof(s_game_globals) == 0x2C0E8);

    inline s_game_globals** g_game_globals() {
        return REF<s_game_globals*>(_data_p_game_globals);
    }
}