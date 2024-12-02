#pragma once

enum e_game_task : int {
    _game_task_pause = 0,
    _game_task_resume = 1,
    _game_task_exit = 2,
    _game_task_load_checkpoint = 3,
    _game_task_restart = 4,
    _game_task_load_setting = 5,
    _game_task_new_round = 12,
    _game_task_resize = 14,

    /// event: team change
    /// arg1: player identifier (xuid)
    /// arg2: team index
    _game_task_team_change = 18,

    _game_task_reload_setting = 23,
};

union s_game_task_data {
    struct {
        unsigned long long arg1;
        unsigned long long arg2;
    };

    char data[16];
};