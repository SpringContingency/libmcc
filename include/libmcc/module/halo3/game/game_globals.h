#pragma once

#include "../../../common.h"
#include "./game_options.h"

namespace libmcc::halo3 {
    union s_skull {
        struct {
            int : 23;
            bool skull_bandana : 1;
            int : 21;
            bool skull_acrophobia : 1;
            int : 18;
            bool skull_iron : 1;
            bool skull_black_eye : 1;
            bool skull_tough_luck : 1;
            bool skull_catch : 1;
            bool skull_fog : 1;
            bool skull_famine : 1;
            bool skull_thunderstorm : 1;
            bool skull_tilt : 1;
            bool skull_mythic : 1;
            int : 23;
            bool skull_assassin : 1;
            bool skull_blind : 1;
            bool skull_cowbell : 1;
            bool skull_grunt_birthday_party : 1;
            bool skull_iwhbyd : 1;
        };
        struct {
            uint64_t primary_skulls;
            uint64_t secondary_skulls;
        };
        char data[0x10];
    };

    struct s_campaign_game_progression {
    };

    union game_globals_storage {
        s_skull* skull() {
            return reinterpret_cast<s_skull*>(data + 64392);
        }

        struct {
            bool initializing;
            bool map_active;
            uint8_t : 8;
            uint8_t : 8;
            uint32_t active_structure_bsp_mask;
            uint32_t active_designer_zone_mask;
            uint32_t active_cinematic_zone_mask;
            game_options options;
            bool game_in_progress;
        };
        char data[0x101A8];
    };

    static_assert(sizeof(game_globals_storage) == 0x101A8);
}