#pragma once

#include "../objects/object_definitions.h"

namespace Halo3 {
    struct c_sector_ref
    {
        __int16 structure_bsp_index;
        word sector_index;
    };


    struct s_damage_reporting_info
    {
        word type;
        byte modifier;
        byte_flags recyling_flags;
    };

    /* 4375 */
    struct _unit_datum {
        int awake_tick_count;
        int actor_index;
        int simulation_actor_index;
        dword_flags flags;
        int team;
        int player_index;
        int last_weak_player_index;
        int game_time_at_last_unit_effect;
        dword_flags unit_control_flags;
        int desired_mode;
        real_vector3d facing_vector;
        real_vector3d desired_aiming_vector;
        real_vector3d aiming_vector;
        real_vector3d aiming_velocity;
        real_vector3d desired_looking_vector;
        real_vector3d looking_vector;
        real_vector3d looking_velocity;
        real_point3d gaze_position;
        real_vector3d throttle;
        real_vector3d control_throttle;
        byte control_context_identifier;
        char aiming_speed;
        s_damage_reporting_info special_death_damage_reporting_info;
        char special_death_type;
        __int16 special_death_node_index;
        bool __unknownAA;
        byte __padAB[1];
        real_vector3d special_death_node_acceleration;
        real primary_trigger;
        real secondary_trigger;
        s_aim_assist_targeting_result aim_assist_data;
        c_target_tracking_system target_tracking;
        dword_flags persistent_control_flags;
        char weapon_drop_delay_ticks;
        char left_eye_node;
        char right_eye_node;
        byte horizontal_aiming_change;
        byte primary_fire_timer;
        byte secondary_fire_timer;
        __int16 parent_seat_index;
        real ambient_illumination;
        real self_illumination;
        real mouth_aperture;
        real mouth_time;
        s_unit_weapon_set current_weapon_set;
        s_unit_weapon_set desired_weapon_set;
        int weapon_object_indices[4];
        int weapon_last_used_at_game_time[4];
        int equipment_object_indices[4];
        int active_equipment_object_indices[4];
        int equipment_pickup_time;
        int consumable_energy_level;
        int consumable_energy_restored_game_time;
        __int16 weapon_firing_time;
        char current_grenade_index;
        char desired_grenade_index;
        char grenade_counts[4];
        char current_zoom_level;
        char desired_zoom_level;
        char __unknown1A2;
        char aiming_change;
        int weapon_control_last_active_time;
        int driver_object_index;
        int gunner_object_index;
        int last_vehicle_index;
        int last_vehicle_exit_game_time;
        __int16 fake_squad_index;
        char impulse_vehicle_from_seat_ticks;
        byte_flags seat_power_valid_flags;
        real seat_power[1];
        real integrated_light_power;
        real integrated_light_battery;
        real integrated_night_vision_power;
        real open_state;
        real_vector3d seat_acceleration;
        real_point3d seat_acceleration_memory[6];
        __int16 seat_acceleration_memory_index;
        byte seat_acceleration__data226[2];
        int seat_acceleration_reset_time;
        __int16 predicted_seat_index;
        byte __data22E[2];
        int predicted_vehicle_index;
        int __unknown234;
        int __unknown238;
        int predicted_player_index;
        int predicted_simulation_actor_index;
        int predicted_simulation_actor_squad_index;
        int predicted_simulation_actor_cell_index;
        int predicted_simulation_actor_spawn_point_index;
        const s_unit_predicted_weapon_state predicted_weapon_state[4];
        real active_camouflage;
        real recent_active_camouflage;
        real active_camouflage_regrowth;
        int active_camouflage_end_time;
        real last_used_healthpack_time;
        real healthpack_vitality;
        real healthpack_shield;
        byte_flags map_editor_helper_flags;
        byte __data28D[1];
        __int16 emp_timer;
        __int16 emp_campaign_metagame_timer;
        byte __data292[2];
        real crouch;
        __int16 delayed_damage_category;
        __int16 delayed_damage_timer;
        real delayed_body_damage_peak;
        int delayed_damage_owner_weak_object_index;
        int flaming_death_attacker_object_index;
        real run_blindly_angle;
        real run_blindly_angular_velocity;
        int hologram_creator_weak_unit_index;
        int hologram_creation_time;
        int hologram_ticks_left;
        int hologram_definition_index;
        real hologram_shimmer_value;
        real_point3d hologram_destination;
        int sync_action_type;
        real_point3d sync_action_origin;
        real_vector3d sync_action_forward;
        real_vector3d sync_action_up;
        bool sync_action_critical_participant;
        char __pad2F9[3];
        s_unknown_unit_struct_sizeof_14 __unknown2FC;
        s_unknown_unit_struct_sizeof_14 __unknown310;
        int time_of_death;
        real movement_stun;
        __int16 movement_stun_ticks;
        __int16 __unknown32E;
        int __unknown330;
        __int16 melee_inhibit_ticks;
        byte __data336[2];
        const unit_attacker attackers[4];
        int attacker_weapon_unit_indices[4];
        real boost_power_meter;
        real boost_recharge_delay;
        int last_enemies_moving_nearby_tick;
        int last_damaged_tick;
        int last_in_soft_kill_volume_time;
        int last_in_phantom_volume_time;
        int __unknown3A0_team_index_update_time;
        int __unknown3A4_team_index;
        int __unknown3A8_object_index;
        object_header_block_reference debug_unit_input_storage;
        object_header_block_reference seat_storage;
        object_header_block_reference speech_storage;
        c_sector_ref pathfinding_sector;
        byte __data3BC[64];
        bool __unknown3FC;
        byte __pad3FD[3];
        int __unknown400[2];
        byte __data408[4];
    };

    struct unit_datum
    {
        int definition_index;
        _object_datum object;
        _motor_datum motor;
        _unit_datum unit;
    };
}
