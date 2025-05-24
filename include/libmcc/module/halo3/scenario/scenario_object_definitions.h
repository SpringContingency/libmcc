#pragma once

#include "../native.h"
#include "../tag_files/tag_files.h"

namespace libmcc::halo3 {
    enum class object_transform_flags {

    };

    enum class scenario_object_active_change_color_flags {

    };

    enum class scenario_object_bsp_placement_policy_definition {
 
    };

    struct c_object_identifier {
        int m_unique_id;
        short m_origin_bsp_index;
        char m_type;
        char m_source;
    };

    struct s_scenario_object_reference {
        // object index
        // scenario object index
    };

    struct s_scenario_object_parent {
        short : 16;
        short parent_object;
        string_id parent_marker;
        string_id connection_marker;
    };

    struct s_scenario_object_node_orientations {
        
    };

    struct s_scenario_object {
        short type;
        short name;
        int placement_flags;
        real_point3d position;
        real_euler_angles3d rotation;
        real scale;
        c_typed_tag_block<s_scenario_object_node_orientations> node_orientations;
        short transform_flags;
        short manual_bsp_flags;
        string_id light_airprobe_name;
        c_object_identifier object_id;
        char bsp_policy;
        char editing_bound_to_bsp;
        short editor_folder;
        s_scenario_object_parent parent_id;
        short can_attach_to_bsp_flags;
        short : 16;
    };

    static_assert(sizeof(s_scenario_object) == 84);

    struct s_scenario_object_permutation {};

    struct s_scenario_multiplayer_object_properties {};

    union s_scenario_scenery {
        struct {
            s_scenario_object object_data;
        };

        char __data[180];
    };
    union s_scenario_vehicle {
        struct {
            s_scenario_object object_data;
        };

        char __data[168];
    };
    union s_scenario_weapon {
        struct {
            s_scenario_object object_data;
        };

        char __data[168];
    };

    union s_scenario_equipment {
        struct {
            s_scenario_object object_data;
        };

        char __data[140];
    };

    struct s_scenario_crate_datum {};

    union s_scenario_crate {
        struct {
            s_scenario_object object_data;
            s_scenario_object_permutation permutation_data;
            s_scenario_crate_datum crate_data;
            s_scenario_multiplayer_object_properties multiplayer_data;
        };

        char __data[176];
    };
}