#pragma once

#include "../native.h"

#include "./damage_owner.h"

namespace Halo3 {
    struct object_placement_data {
        t_datum_type Datum;//0X0
        __int8 v0[0x8];
        __int32 VariantID;//0xC
        __int8 v1[0x8];
        __int8 flags;//0x18 (0x10)
        Vector3 position;//0x1c
        Vector3 forward;
        Vector3 up;
        Vector3 translational_velocity;
        Vector3 angular_velocity;
        float scale;
        __int8 v3[0x124];
    };

    static_assert(sizeof(object_placement_data) == 384);

    inline void object_placement_data_new(object_placement_data* data, t_datum_type datum, datum_index parent, s_damage_owner const* damage_owner) {
        INVOKE<void>(0x341158, data, datum, parent, (int64)damage_owner);
    }
}
