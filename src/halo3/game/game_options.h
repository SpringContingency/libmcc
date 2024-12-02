#pragma once

#include "../native.h"

namespace Halo3 {
    struct campaign_weapon {
        uint16_t damage_reporting_type;
        uint16_t rounds_inventory;
        uint16_t rounds_loaded;
        uint16_t battery;
    };

#pragma pack(push, 1)

    struct player_armaments {
        bool enabled;
        char padding;
        campaign_weapon weapon1;
        campaign_weapon weapon2;
        campaign_weapon weapon3;
        int grenade_counts;
    };

#pragma pack(pop)

    struct game_machine_options {
        char buffer[116];
    };

    static_assert(sizeof(game_machine_options) == 116);

    struct game_player_options {
        char buffer[2944];
    };

    static_assert(sizeof(game_player_options) == 2944);

    struct game_options {
        char game_mode; // [0, 5)
        char game_simulation; // [0, 6)
        char game_network_type;
        bool matchmade_game;
        uint16_t game_tick_rate; // [0, 300)
        uint16_t padding1;
        void* game_instance;
        int random_seed;
        int language;
        int determinism_version; // 24
        uuid mcc_campaign_id;
        uuid mcc_map_id;
        int campaign_id;
        int map_id;
        char scenario_path[260]; // 68
        uint16_t initial_zone_set_index; // [0,  48)
        bool load_level_only;
        char dump_machine_index;
        bool dump_object_log;
        bool dump_random_seeds;
        char playtest_mode;
        char un0;
        char game_playback;
        bool record_saved_film;
        uint16_t un1;
        int playback_start_ticks;
        int playback_length_in_ticks;
        uint16_t campaign_difficulty;
        uint16_t campaign_insertion_point;
        uint16_t campaign_metagame_scoring;
        bool campaign_metagame_enabled;
        char un00;
        bool campaign_allow_persistent_storage;
        char un000;
        uint16_t unnn;
        int unnnnnn;
        int unnnnnnn;
        int campaign_active_primary_skulls;
        int campaign_active_secondary_skulls;
        player_armaments player_armaments[4];
        game_player_options player_options;
        game_machine_options machine_options;
        bool is_custom_games_browser;
        char custom_games_browser_minimum_desired_player_count;
        bool campaign_customization_enabled;
        bool un31;
        bool game_variant_fileshare_metadata_valid;
        char padding21[7];
        char game_variant_fileshare_metadata[1024];
        bool map_variant_fileshare_metadata_valid;
        char padding22[7];
        char map_variant_fileshare_metadata[1024];
        char buffer[58728];
    };

    static_assert(sizeof(game_options) == 64352);

    struct c_game_player_options {
        bool v_true;
        bool v_false;
        uint16_t user_input;
        int input_map;
        int respawn_flag; // 0x8
        int unun;
        uint64_t un_flag; // 0x10
        wchar name[0x10]; // 0x18
        char un1[0x1E];
        wchar id[0x3]; // 0x56
        char un2[0x34];
        wchar name2[0x10]; // 0x90
        char un3[0x8];
    };

    static_assert(sizeof(c_game_player_options) == 184);
}