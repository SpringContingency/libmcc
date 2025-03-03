#pragma once

#include "./game_options.h"

namespace libmcc {
    struct s_game_globals {

    };

    enum e_game_globals_state {
        _game_globals_state_none = 0,
        _game_globals_state_launch = 1,
        _game_globals_state_start = 2,
        _game_globals_state_exit = 3,

        k_game_globals_state_count = 4,
    };

    typedef void (*t_game_globals_state)(s_game_globals* game_globals);

    struct s_game_globals_states {
        t_game_globals_state enter[k_game_globals_state_count];
        t_game_globals_state exit[k_game_globals_state_count];
        t_game_globals_state update[k_game_globals_state_count];
    };
}