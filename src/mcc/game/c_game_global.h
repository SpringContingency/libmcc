#pragma once

#include <Windows.h>

#include "game_options.h"

namespace MCC {
    enum e_game : int {
        _game_halo1 = 0,
        _game_halo2 = 1,
        _game_halo3 = 2,
        _game_halo4 = 3,
        _game_groundhog = 4,
        _game_halo3odst = 5,
        _game_halo_reach = 6,
    };

    enum e_game_state : int {
        _game_state_exit = 1,
        _game_state_event_execute = 4,
    };

    enum e_game_event : int {
        _game_event_create_game_engine = 3,
        _game_event_initialize_graphics = 9,
        _game_event_game_start = 11,
        _game_event_in_game = 12,
    };

    struct c_game_global {
        char buffer[0xA8];
        s_game_options game_options;
        e_game_state current_state;
        e_game_state last_state;
        HMODULE hModule;
        e_game current_game;
        e_game last_game; // 0x2BFEC

        e_game_event* game_sate() {return (e_game_event*)(this + 0x2C038);}
        LARGE_INTEGER* PerformanceCounter() {return (LARGE_INTEGER*)(this + 0x2C040);}
        bool is_paused() {return *(bool*)(this + 0x2C064);}
    };
}