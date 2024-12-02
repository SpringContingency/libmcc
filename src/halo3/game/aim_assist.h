#pragma once

#include "../native.h"

namespace Halo3 {
    struct c_aim_target_base {
        byte m_target_type;
        byte padding[3];
        int m_model_index;
    };

    struct c_aim_target_object : c_aim_target_base {
        union
        {
            int m_object_index;
            int m_laser_designation;
        };
    };

    struct s_aim_assist_targeting_result {
        t_definition_index target_player;
        t_definition_index target_object;
        t_definition_index model_target;
        real primary_autoaim_level; // [0, 1]
        real secondary_autoaim_level; // [0, 1]
        real_vector3d lead_vector;
        dword_flags flags;

        inline bool autoaim_exits() {return (flags & 2) != 0 || target_object != -1;}
    };
}