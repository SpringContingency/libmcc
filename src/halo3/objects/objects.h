#pragma once

#include "../native.h"

#include "../memory/static_arrays.h"

#include "./object_placement.h"

#include "../structures/structure_bsp_definitions.h"

#include "./object_definitions.h"

namespace Halo3 {
    struct object_header_datum {
        enum e_object_header {
            _object_header_active_bit = 1 << 0,
            _object_header_awake_bit = 1 << 1,
            _object_header_requires_motion_bit = 1 << 2,
            _object_header_post_update_bit = 1 << 3,
            _object_header_being_deleted_bit = 1 << 4,
            _object_header_connected_to_map_bit = 1 << 6,
            _object_header_child_bit = 1 << 7,
        };

        int16 un;
        c_flags<e_object_header, __int8, 255> flags;
        char un1;
        char cluster_reference;
        char type;
        int16 data_size;

        int64 v1;

        object_datum* datum;
    };

    inline datum_index object_new(object_placement_data* data) {
        return INVOKE<datum_index>(0x341738, data);
    }
}