#pragma once

#include "../common.h"

#include "./damage_owner.h"

namespace Halo3 {
    struct object_placement_data {
        t_definition_index Datum;//0X0
        uint8_t v0[0x8];
        uint32_t VariantID;//0xC
        uint8_t v1[0x8];
        uint8_t flags;//0x18 (0x10)
        Vector3 position;//0x1c
        Vector3 forward;
        Vector3 up;
        Vector3 translational_velocity;
        Vector3 angular_velocity;
        float scale;
        uint8_t v3[0x124];
    };

    static_assert(sizeof(object_placement_data) == 384);
}
