#pragma once

#include "../native.h"

#include "../memory/array.h"
#include "../networking/network_game_definitions.h"
#include "../simulation/game_interface/simulation_game_engine_player.h"
#include "../simulation/simulation.h"

#include "../structures/structure_bsp_definitions.h"

#include "./aim_assist.h"

namespace Halo3 {
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

    struct players_globals_definition {
        __int32 player_count;
        bool disable_input;
    };

    struct s_damage_reporting_info {
        word type;
        byte modifier;
        byte_flags recyling_flags;
    };

    struct multiplayer_player_info
    {
        int target_player_index;
        __int16 __unknown4;
        char __unknown6;
        char __unknown7;
        char __unknown8;
        char __unknown9;
        char __unknownA;
        char __unknownB;
        __int16 __unknownC;
        __int16 lives_remaining;
        int griefer_player_index;
        int last_killed_round_time;
        c_player_traits player_traits;
        int powerup_pickup_time[3];
        int respawn_target_player_index;
        bool map_editor_rotating;
        real_point2d map_editor_throttle;
        real_euler_angles2d map_editor_rotation;
        __int16 __unknown58;
        __int16 __unknown5A;
        byte __data5C[4];
        __int16 nemesis_mechanics_nemesis_or_avenger_counts[16];
        bool revenge_shield_boost_unknown80;
        __int16 revenge_shield_boost_unknown82;
        int revenge_shield_boost_unknown84;
        int revenge_shield_boost_player_index;
        s_damage_reporting_info revenge_shield_boost_damage;
        bool revenge_shield_boost_unknown90;
        byte __data91[3];
    };

    struct s_simulation_biped_melee_damage_event_data {
        byte __data[60];
    };

    struct s_tracking_object {
        byte __data[4];
        int object_index;
        int __time8;
    };

    struct s_player_shot_info {
        __int16 shot_id;
        s_damage_reporting_info damage_reporting_info;
        byte __data6[2];
        dword __unknown8;
    };

#pragma pack(push, 1)

    struct players_definition {
        int Index;
        dword_flags flags;
        s_player_identifier player_identifier;
        int left_game_time;
        s_machine_identifier machine_identifier;
        int16 machine_index;
        int16 machine_user_index;
        int16 controller_index;
        int machine_controller_index;
        Structures::s_cluster_reference cluster_reference;
        char padding[2];
        datum_index unit_index; // 40
        datum_index dead_unit_index; // 0x2C

        // unsure
        datum_index failed_teleport_unit_index;
        dword_flags latched_control_flags;
        __int16 cooldown_reset_unknown40;
        __int16 cooldown_reset_unknown42;
        __int16 cooldown_reset_unknown44;
        word_flags latched_action_flags;
        byte outside_of_world_timer;
        byte next_spawn_control_context;
        int armor_loadout_index;
        int weapon_loadout_index;
        char melee_recovery_ticks;
        char melee_soft_recovery_ticks;
        // unsure

        real_point3d position;// 0x4C
        s_player_configuration configuration; // 88
        s_player_configuration desired_configuration;
        int single_player_respawn_timer;
        bool early_respawn_requested;
        bool respawn_in_progress;
        bool respawn_forced;
        byte __unknown2CB7;
        int respawn_timer; // 0x1A0

        int respawn_timer_countdown;
        int respawn_penalty;
        int telefrag_timer;
        int dead_timer;
        int __unknown2CCC;
        int __unknown2CD0;
        int __unknown2CD4;
        int grenade_recharge_timer;
        int aim_assist_object_index;
        int aim_assist_timestamp;
        __int16 momentum_timer;
        __int16 momemtum_unknown2CE6;
        __int16 momentum_decay_timer;
        __int16 momentum_falloff_timer;
        bool momemtum_suppressed;
        __int16 vehicle_ban_timer;
        c_aim_target_object cached_target;
        int cached_target_untargeted_ticks;
        s_tracking_object tracking_objects[8];
        __int16 recently_spawned_timer;
        bool recently_spawned_timer_is_initial_spawn;
        byte respawn_failure_reason;
        int tank_mode_time2D64;
        real tank_mode_duration;
        real tank_mode_unknown2D6C;
        real tank_mode_damage_absorption_scale;
        real tank_mode_unknown2D74;
        real tank_mode_unknown2D78;
        int reactive_armor_time2D7C;
        real reactive_armor_duration;
        real reactive_armor_damage_reflection_scale;
        real reactive_armor_unknown2D88;
        int stamina_restore_near_death_timer;
        bool grenade_scavenger_modifier_used;
        byte __data2D91[3];
        multiplayer_player_info multiplayer;

//        __int8 v6[0x33];// 0x1AC respawn_time_second
//        __int8 coop_index;// 0x1D7
//        __int8 v7[0x2];
//        __int8 v8[30];
//        c_player_traits traits; // 504
//        struct Multiplayer {
//            float powerup_pickup_time[4];
//        };
//        __int8 v11[128];
//        Vector3 position2;// 0x294
//        datum_index object_datum_index2;
//        datum_index restore_datum_index2;
//        float uk0, uk1, uk2;
//        __int8 v20[0x3C];
    };

    static_assert((sizeof(players_definition) == 0x2F0));

#pragma pack(pop)

    inline Memory::c_data_array<players_definition>* players() {
        return reinterpret_cast<Memory::c_data_array<players_definition>*>(MainThreadLocalStorage()->players);
    }
}