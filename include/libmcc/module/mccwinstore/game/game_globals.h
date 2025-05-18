#pragma once

#include "../../../game/game_globals.h"

#include "../native.h"

namespace libmcc::mccwinstore {
	struct s_game_globals : libmcc::s_game_globals {

        int* state() {
            return reinterpret_cast<int*>(__data + 180248);
        }

        LARGE_INTEGER* enter_time() {
            return reinterpret_cast<LARGE_INTEGER*>(__data + 180256);
        }

        bool* paused() {
            return reinterpret_cast<bool*>(__data + 180292);
        }

        union {
            struct {
                char data[136];
				s_game_options options;
                e_game_globals_state target_state;
                e_game_globals_state current_state; // 180188
                HMODULE current_module_handle;
                e_module current_module;
                e_module last_module;
            };

            char __data[0x2C0C8];
        };
	};

	static_assert(sizeof(s_game_globals) == 0x2C0C8);
}
