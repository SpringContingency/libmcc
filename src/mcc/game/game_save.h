#pragma once

struct s_game_save_data {
    char buffer[381240];
};

static_assert(sizeof(s_game_save_data) == 381240);

struct s_player_state {
    char buffer[32];
};

static_assert(sizeof(s_player_state) == 32);

struct s_game_state {
    char buffer[16];
    s_player_state player_state[16];
    int un_1;
    int un_2;
    int un_3;
    char flags;
    char padding[3];
};

static_assert(sizeof(s_game_state) == 0x220);