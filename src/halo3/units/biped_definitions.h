#pragma once

#include "./unit_definitions.h"

namespace Halo3 {
    struct _biped_datum {
        word_flags flags;
        __int16 pathfinding_structure_index;
        int pathfinding_time;
        int pathfinding_surface_index;
        c_sector_ref pathfinding_sector;
        int pathfinding__unknown10;
        int pathfinding_object_index;
        dword pathfinding_bsp_reference;
        real_point3d pathfinding_point;
        byte __data28[24];
        int current_bump_object_index;
        int bump_object_index;
        char bump_ticks;
        char jump_control_ticks;
        byte stun_ticks;
        char last_known_speed_scale;
        real lean;
        real camera_offset_z;
        real camera_offset_y;
        real camera_height;
        int jump_time;
        int land_time;
        __int16 current_gate_type;
        __int16 current_gate_index;
        int current_gate_start_time;
        byte __data6C[40];
        c_character_physics_component physics;
        object_header_block_reference simulation_interpolation;
        object_header_block_reference last_node_matrices_storage;
        real_vector3d root_offset;
        real_vector3d ground_fit_normal;
        real pivot_on_foot_scale;
        real pivot_on_foot_scale_boost;
        real_point3d pivot_point;
        real_vector2d pivot_fixup;
        real_matrix4x3 __matrix150;
        real_matrix4x3 __matrix184;
        byte __data1B8[12];
        t_static_ring_buffer_real_matrix4x3_3 root_matrix_history;
        real landing_recovery_offset;
        real pendulum_scale;
        real_vector3d pendulum_vector;
        real gravity_scale;
        int customized_area_object_indices[10];
        __int16 customized_area_indices[10];
        int __unknown2C0;
        __int16 __unknown2C4;
        byte __data2C6[1];
        bool __unknown2C7;
    };

    struct biped_datum
    {
        int definition_index;
        _object_datum object;
        _motor_datum motor;
        _unit_datum unit;
        _biped_datum biped;
    };

    static_assert(sizeof(biped_datum) == 1744);
}
