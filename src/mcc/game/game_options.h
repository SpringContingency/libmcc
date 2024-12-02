#pragma once

#include "../common.h"

enum e_game_settings_games {
    _game_settings_games_NetworkSessionLayer = -2,
    _game_settings_games_none = -1,
    _game_settings_games_halo1 = 0,
    _game_settings_games_halo2 = 1,
    _game_settings_games_halo3 = 2,
    _game_settings_games_halo4 = 3,
    _game_settings_games_goundhog = 4,
    _game_settings_games_halo3odst = 5,
    _game_settings_games_halo_reach = 6,
};

enum e_game_mode : int {
    _game_mode_none,
    _game_mode_campaign,
    _game_mode_spartan_ops,
    _game_mode_multiplayer,
    _game_mode_ui_shell,
    _game_mode_firefight,

    k_game_mode_count,
};

enum e_campaign_difficulty_level : int {
    _campaign_difficulty_level_none = -1,
    _campaign_difficulty_level_easy = 0,
    _campaign_difficulty_level_normal = 1,
    _campaign_difficulty_level_hard = 2,
    _campaign_difficulty_level_impossible = 3,
};

enum e_game_data {
    _game_data_use_init_file = 1 << 1,
};

struct s_session_player {
    s_player_identifier identifier;
    __int64 data2;
    int data3;
    int data4;
    int data5;
    int data6;
};

#pragma pack(push, 1)

struct s_game_options {
    enum e_game_options : unsigned char {
        _game_option_debug = 1 << 1, // enable init.txt and terminal
        _game_option_bit_4 = 1 << 4,
        _game_option_bit_6 = 1 << 6,
        _game_option_bit_7 = 1 << 7,
    };

    char magic; // magic number: 8
    char flags;
    char option_1;
    char option_2;
    char option_3;
    char option_4;
    char option_5;
    char option_6;
    char network_option_1;
    char network_option_2;
    char game_tick;
    char un_0;
    e_game_mode game_mode;
    int legacy_map_id; // nobody wants you
    s_map_id map_id;
    s_map_id custom_campaign_map_id;
    e_campaign_difficulty_level difficulty_level;
    int un_1;
    int campaign_insertion_point;
    __int64 un_2;
    __int64 skulls;
    __int64 party_address;
    __int64 local_address;
    __int64 peer_address[17];
    size_t m_PeerCount;
    s_session_player players[16];
    size_t m_PlayerCount;
    __int64 un_3; // m_HostSAddr?
    char game_variant[117760];
    char un_4[1032];
    char map_variant[59392];
    char un_5[1032];
    int un_6;
    int padding_1;
    void* saved_game_state;
    const char* saved_film_path;
    __int64 un_7;
};

static_assert((sizeof(s_game_options) == 0x2BF30));

#pragma pack(pop)