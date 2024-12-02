#pragma once

#include "../base/base.h"

struct observer_globals_definition {
    struct raw_data_t {
        uint8_t un0[0x11C];
        struct data_t {
            Vector3 position;
            float un;
            Vector3 velocity;
            Vector3 v_rotation;
            Vector3 components;
        } data;
        uint8_t un1[0x280];
    } data[MAX_LOCAL_PLAYERS];
    static_assert(sizeof(raw_data_t) == 0x3D0);
};