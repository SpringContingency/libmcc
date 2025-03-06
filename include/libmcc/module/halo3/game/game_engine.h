#pragma once

#include "../scenario/scenario_map_variant.h"

namespace libmcc::halo3 {
    union s_game_engine_globals {
        s_game_engine_globals() {

        }

        int* game_variant_game_type() {
            return reinterpret_cast<int*>(data + 81436);
        }


        struct {
            uint32_t flags;
            uint16_t valid_team_mask;
            uint16_t initial_teams;
            uint16_t valid_designators;
            uint16_t valid_teams;
            uint16_t active_teams;
            uint16_t game_simulation;
            uint16_t team_designator_to_team_index[9];
            char team_lives_per_round[8];
            uint16_t __unknown2A;
            uint32_t simulation_object_glue_index;
            uint32_t statborg_gamestate_index;
            uint32_t player_simulation_object_glue_indices[16];
            byte __data74[4];
            c_map_variant map_variant;
        };
        char data[0x159C0];
    };

    static_assert(sizeof(s_game_engine_globals) == 0x159C0);
}