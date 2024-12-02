#pragma once

#include "../common.h"

#include "damage_owner.h"
#include "../structures/structure_bsp_definitions.h"

namespace Halo3 {
    enum e_object_type {
        _object_type_biped,
        _object_type_vehicle,
        _object_type_weapon,
        _object_type_equipment,
        _object_type_terminal,
        _object_type_projectile,
        _object_type_scenery,
        _object_type_machine,
        _object_type_control,
        _object_type_soundscenery,
        _object_type_crate,
        _object_type_creature,
        _object_type_giant,
        _object_type_effectscenery
    };

    struct object_type_definition {
        const char *full_name;
        char group_tag[4];
        uint16_t size;
        uint16_t un[9];
        void *func[0x25];
        void *parent[0x13];
    };

    struct object_header_block_reference {
        uint16_t size;
        uint16_t offset;
    };

    static_assert(sizeof(object_header_block_reference) == 0x4);

    enum e_object_data_flags : dword_flags {
        _object_hidden_bit = 0x0,
        _object_always_active_bit = 0x1,
        _object_hidden_flag = 0x1,
        _object_being_created_bit = 0x2,
        _object_always_active_flag = 0x2,
        _object_underwater_bit = 0x3,
        _object_has_attached_lights_bit = 0x4,
        _object_being_created_flag = 0x4,
        _object_has_attached_looping_sounds_bit = 0x5,
        _object_has_unattached_lights_bit = 0x6,
        _object_in_limbo_bit = 0x7,
        _object_connected_to_map_bit = 0x8,
        _object_underwater_flag = 0x8,
        _object_uses_collidable_list_bit = 0x9,
        _object_mirrored_bit = 0xA,
        _object_render_model_has_instances_bit = 0xB,
        _object_static_lighting_recompute_bit = 0xC,
        _object_static_lighting_raycast_sideways_bit = 0xD,
        _object_render_time_node_matrices_complete_bit = 0xE,
        _object_clip_plane_bit = 0xF,
        _object_shadowless_bit = 0x10,
        _object_has_attached_lights_flag = 0x10,
        _object_deleted_when_deactivated_bit = 0x11,
        _object_outside_of_map_bit = 0x12,
        _object_cinematic_lod_bit = 0x13,
        _object_cinematic_collision_bit = 0x14,
        _object_cinematic_visibility_bit = 0x15,
        _object_static_pathfinding_bit = 0x16,
        _object_dynamic_pathfinding_disabled_bit = 0x17,
        _object_uses_cinematic_lighting_bit = 0x18,
        _object_has_override_bit = 0x19,
        _object_created_with_parent_bit = 0x1A,
        _object_reconnect_to_map_bit = 0x1B,
        _object_ever_referenced_by_hs_bit = 0x1C,
        _object_orientations_frozen_bit = 0x1D,
        _object_render_only_orientations_needed_bit = 0x1E,
        _object_is_prt_and_lightmapped_bit = 0x1F,
        k_object_data_flags = 0x20,
        _object_has_attached_looping_sounds_flag = 0x20,
        _object_has_unattached_lights_flag = 0x40,
        _object_in_limbo_flag = 0x80,
        _object_connected_to_map_flag = 0x100,
        _object_uses_collidable_list_flag = 0x200,
        _object_mirrored_flag = 0x400,
        _object_render_model_has_instances_flag = 0x800,
        _object_static_lighting_recompute_flag = 0x1000,
        _object_static_lighting_raycast_sideways_flag = 0x2000,
        _object_render_time_node_matrices_complete_flag = 0x4000,
        _object_clip_plane_flag = 0x8000,
        _object_shadowless_flag = 0x10000,
        _object_deleted_when_deactivated_flag = 0x20000,
        _object_outside_of_map_flag = 0x40000,
        _object_cinematic_lod_flag = 0x80000,
        _object_cinematic_collision_flag = 0x100000,
        _object_cinematic_visibility_flag = 0x200000,
        _object_static_pathfinding_flag = 0x400000,
        _object_dynamic_pathfinding_disabled_flag = 0x800000,
        _object_uses_cinematic_lighting_flag = 0x1000000,
        _object_has_override_flag = 0x2000000,
        _object_created_with_parent_flag = 0x4000000,
        _object_reconnect_to_map_flag = 0x8000000,
        _object_ever_referenced_by_hs_flag = 0x10000000,
        _object_orientations_frozen_flag = 0x20000000,
        _object_render_only_orientations_needed_flag = 0x40000000,
        _object_is_prt_and_lightmapped_flag = 0x80000000,
    };

    struct c_object_identifier {
        int m_unique_id;
        __int16 m_origin_bsp_index;
        char m_type;
        char m_source;
    };

    // generated with ida from `eldorado`
    struct _object_datum {
        e_object_data_flags flags;
        int collision_damage_definition_index;
        int next_object_index;
        int child_object_index;
        int parent_object_index;
        byte parent_node_index;
        byte_flags inhibited_flags;
        __int16 scenario_datum_index;
        __int16 map_variant_index;
        s_location location;
        real_point3d bounding_sphere_center;
        real bounding_sphere_radius;
        real_point3d attached_bounds_center;
        real attached_bounds_radius;
        real_point3d attached_bounds_sphere_center;
        real attached_bounds_sphere_radius;
        int first_cluster_reference_index;
        real_point3d position;
        real_vector3d forward;
        real_vector3d up;
        real_vector3d transitional_velocity;
        real_vector3d angular_velocity;
        real scale;
        c_object_identifier object_identifier;
        __int16 name_index;
        char bsp_placement_policy;
        byte keyframed_object_collision_damage_ticks;
        int havok_component_index;
        int local_physics_space_object_index;
        int last_motion_time;
        dword_flags physics_flags;
        byte physics_deactivation_count;
        byte physically_attached_node;
        byte phantom_power_scale;
        byte phantom_speed_scale;
        __int16 in_water_ticks;
        char environment_interpenetration_ticks;
        byte brittle_collision_damage_timer;
        __int16 scale_intepolation_ticks;
        char variant_index;
        byte_flags object_ai_flags;
        dword melee_damage_unique_identifier;
        s_damage_owner damage_owner;
        __int16 structure_bsp_fake_lightprobe_index;
        bool created_at_rest;
        byte clusters_touched_on_connection;
        int simulation_object_glue_index;
        __int16 owner_team_index;
        byte_flags simulation_flags;
        char child_variant_index;
        int simulation_object_interpolation_time;
        real_point3d simulation_object_interpolation_position;
        int first_widget_index;
        word destroyed_constraints;
        __int16 loosened_constraints;
        real maximum_body_vitality;
        real maximum_shield_vitality;
        real shield_charge_delay;
        real body_vitality;
        real shield_vitality;
        real current_body_damage;
        real current_shield_damage;
        real recent_body_damage;
        real recent_shield_damage;
        real shield_impact_current_body_damage;
        real shield_impact_current_shield_damage;
        __int16 shield_stun_ticks;
        __int16 body_stun_ticks;
        dword_flags damage_flags;
        char damaged_explosion_timer;
        char body_damage_delay_ticks;
        char shield_impact_decay_timer;
        byte_flags recycling_flags;
        int next_recycling_object_index;
        int recycling_time;
        int parent_recycling_group;
        int next_recycling_group_member;
        int next_sync_action_participant_index;
        int sync_action_name;
        int sync_animation_id;
        int ai_sync_action_arranger_index;
        word_flags render_flags;
        object_header_block_reference original_node_orientations;
        object_header_block_reference node_orientations;
        object_header_block_reference node_matrices;
        object_header_block_reference region_information;
        object_header_block_reference attachments;
        object_header_block_reference damage_sections;
        object_header_block_reference change_colors;
        object_header_block_reference animation;
        object_header_block_reference multiplayer;
        byte __data16E[2];
        int air_probe_index;
        union
        {
            int scenery_air_probe_index;
            int device_machine_air_probe_index;
        };
    };

    struct object_datum {
        int definition_index;
        _object_datum object;
    };

    struct _motor_datum {
        object_header_block_reference motor_tasks;
        object_header_block_reference motor_state;
        object_header_block_reference action_state_storage;
    };

    struct motor_datum {
        int definition_index;
        _object_datum object;
        _motor_datum motor;
    };

//    struct c_object {
//        enum ePhysicsFlags : unsigned int {
//            _object_is_early_mover_bit = 0x1,
//            _object_has_proxy_bit =  0x4000,
//            _object_connected_to_physics_bit = 0x80,
//            _object_is_early_mover_child_bit = 0x10,
//        };
//
//        t_definition_index datum;//0x0
//        eObjectFlags object_flags; //0x4
//        int v0;
//        t_definition_index next_object_index;//0xC
//        t_definition_index parent_object_index;//0x10
//        uint8_t v1[0x3C];
//        Vector3 position;//0x50
//        Vector3 facing;//0x5C
//        Vector3 up;//0x68
//        uint8_t b2[0x16];//0x74
//        float scale;//0x8C
//        uint8_t v3[0x6];
//        uint8_t type;//0x96
//        uint8_t v4[0x11];
//        ePhysicsFlags physics_flags;//0xA8
//        uint8_t v5[0xA];
//        uint8_t variant_index;//0xB6
//        uint8_t v6[0x15];
//        unsigned int physics;//0xCC
//        uint8_t v7[0x24];
//        float health;//0xF4
//        float shield;//0xF8
//        uint8_t v8[0x14];
//        unsigned int damage_flags;//1<<4 0x110
//
//        /*
//            int flags;
//            int simulation_flags; 0xD2
//            int gamestate_index;
//            int havok_comonent_index; 0x9C
//            int next_recycling_group_member;
//            int object_identifier;
//            int scenario_datum_index;
//            int change_colors;
//            int attached_bounds_center;
//            int parent_recycling_group;
//            int parent_info;
//         * */
//
//        inline bool isUnit() { return (1 << type) & ((1 << OBJECTTYPE_BIPED) | (1 << OBJECTTYPE_GIANT) | (1 << OBJECTTYPE_VEHICLE)); }
//        // damage flags
//        inline bool CannotTakeDamage(){return damage_flags & 0x100u;}
//        inline void CannotTakeDamage(bool b){if(b)damage_flags |= 0x100u;else damage_flags &= ~0x100u;}
//        inline bool CannotDieFromDamage(){return damage_flags & 0x10000u;}
//        inline void CannotDieFromDamage(bool b){if(b)damage_flags |= 0x10000u;else damage_flags &= ~0x10000u;}
//
//        inline void kill() { damage_flags |= 0x40;}
//    };
}
