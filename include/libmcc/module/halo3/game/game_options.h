#pragma once

#include "../../../scenario/scenario_map_id.h"

namespace libmcc::halo3 {
     enum e_game_mode : char {
         _game_mode_none        = 0x0,
         _game_mode_campaign    = 0x1,
         _game_mode_multiplayer = 0x2,
         _game_mode_mainmenu    = 0x3,
         _game_mode_shared      = 0x4,
         k_game_mode_count      = 0x5,
     };

    enum network_game_simulation_protocol : char {
        _game_simulation_none        = 0x0,
        _game_simulation_local       = 0x1,
        _game_simulation_sync_client = 0x2,
        _game_simulation_sync_server = 0x3,
        _game_simulation_dist_client = 0x4,
        _game_simulation_dist_server = 0x5,
        k_number_of_game_simulations = 0x6,
    };
    
    union game_options {
        bool* game_playback() {
            return reinterpret_cast<bool*>(data + 0x150);
        }

        struct {
            e_game_mode game_mode;
            char game_simulation;
            network_game_simulation_protocol game_network_type;
        };
        char data[64352];
    };

    static_assert(sizeof(game_options) == 64352);
}