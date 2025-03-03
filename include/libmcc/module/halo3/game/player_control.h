#pragma once

#include "../../../common.h"

namespace libmcc::halo3 {
    union s_player_control_non_deterministic_input_user_state {
        struct {

        };
        char data[0x30];
    };

    static_assert(sizeof(s_player_control_non_deterministic_input_user_state) == 0x30);


    union s_player_control_state {
        struct {

        };
        char data[0x78];
    };

    static_assert(sizeof(s_player_control_state) == 0x78);

    struct s_player_control_output_state {
        int unit_index;
        int : 32;
        s_player_control_state output;
    };

    static_assert(sizeof(s_player_control_output_state) == 0x80);

    union s_player_control_input_state {
        struct {
            s_player_control_output_state output;
        };
        char data[0x110];
    };

    static_assert(sizeof(s_player_control_input_state) == 0x110);

    struct s_player_control_globals {
        s_player_control_non_deterministic_input_user_state input_user_states[4];
        s_player_control_input_state input_states[4];
        s_player_control_output_state output_state[4];
        int : 32;
        int : 32;
        bool machinima_camera_enabled;
        bool machinima_camera_use_old_controls;
        bool machinima_camera_debug;
        char : 8;
        int : 32;
    };

    static_assert(sizeof(s_player_control_globals) == 0x710);
}