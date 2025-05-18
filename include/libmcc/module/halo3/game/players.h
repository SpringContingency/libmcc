#pragma once

#include "../native.h"
#include "../../../game/players.h"

namespace libmcc::halo3 {
    typedef XUID s_player_identifier;

    struct s_player_appearance {
        bool female_voice;
        char primary_color;
        char secondary_color;
        char tertiary_color;
        bool player_model_choice;

        char un;

        char foreground_emblem;
        char background_emblem;
        char emblem_flags;
        char emblem_primary_color;
        char emblem_secondary_color;
        char emblem_background_color;

        unsigned short un2;

        struct model_area {
            char spartan_model_area0;
            char spartan_model_area1;
            char spartan_model_area2;
            char spartan_model_area3;

            char elite_model_area0;
            char elite_model_area1;
            char elite_model_area2;
            char elite_model_area3;
        } areas[2];

        unsigned short service_tag[4]; // 30
        char skin_assault_rifle;
        char skin_battle_rifle;
        char skin_needler;
        char skin_magnum_pistol;
        char skin_plasma_pistol;
        char skin_plasma_rifle;
        char skin_rocket_launcher;
        char skin_shotgun;
        char skin_sniper_rifle;
        char skin_flamethrower;
        char skin_fuel_rod_cannon;
        char skin_smg;
        char skin_carbine;
        char skin_energy_blade;
        char skin_visor;
        char skin_warthog;
        char skin_warthog_gauss;
        char skin_ghost;
        char skin_scorpion;
        char skin_banshee;
        char skin_hornet;
        char skin_mongoose;
        int pose;
    };

    static_assert(sizeof(s_player_appearance) == 64);

    struct s_player_configuration_from_client {
        unsigned short player_name[16];
        s_player_appearance player_appearance;
        unsigned long long player_xuid;
        bool is_controller_attached;
        char player_last_team;
        char player_is_griefer;
        char preferred_input_device;
        int cheat_flags;
        int ban_flags;
        int button_preset;
    };

    static_assert(sizeof(s_player_configuration_from_client) == 120);

    struct s_player_configuration_from_host {
        unsigned short player_name[16];
        int player_team;
        int player_assigned_team;
    };

    static_assert(sizeof(s_player_configuration_from_host) == 40);

    struct s_player_configuration {
        s_player_configuration_from_client client;
        s_player_configuration_from_host host;
    };

    static_assert(sizeof(s_player_configuration) == 160);

    struct s_game_results_player_data {
        bool player_exists;
        char machine_index;
        s_player_identifier player_identifier;
        s_player_configuration configuration;
        int ticks;
        int : 32;
        int : 32;
        int : 32;
        int : 32;
        int : 32;
    };

    static_assert(sizeof(s_game_results_player_data) == 200);
}