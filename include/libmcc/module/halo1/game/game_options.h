#pragma once

namespace libmcc::halo1 {
    enum e_game_mode : char {
        _game_mode_none = 0x0,
        _game_mode_campaign = 0x1,
        _game_mode_multiplayer = 0x2,
        _game_mode_mainmenu = 0x3,
        k_game_mode_count = 0x4,
    };

}