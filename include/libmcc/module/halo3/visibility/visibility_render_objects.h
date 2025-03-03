#pragma once

#include "../structures/structures.h"

namespace libmcc::halo3 {
    union s_visible_object_hierarchy {
        struct {
            uint16_t flags;
        };

        char data[16];
    };

    static_assert(sizeof(s_visible_object_hierarchy) == 16);

    struct s_visible_object_render_visibility {
        char data[96];
    };

    static_assert(sizeof(s_visible_object_render_visibility) == 96);

    union s_visible_instance_list {
        struct {
            char structure_bsp_index;
        };

        char data[12];
    };

    static_assert(sizeof(s_visible_instance_list) == 12);

    struct s_visible_instances
    {
        __int16 flags;
        __int16 instanced_geometry_instances_index;
        __int16 structure_bsp_index;
        __int16 region_cluster_bitvector_start_index;
        __int8 __data8[4];
        int *part_bitvector_space;
    };

    static_assert(sizeof(s_visible_instances) == 24);

    struct s_visible_clusters
    {
        __int16 flags;
        s_cluster_reference cluster_reference;
        char __data4[4];
        __int16 mesh_index;
        char __dataA[2];
        int *part_visibility_bitvector;
    };

    static_assert(sizeof(s_visible_clusters) == 24);
}
