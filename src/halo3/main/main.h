#pragma once

#include "../native.h"

#include <array>

namespace Halo3 {
    struct c_status_value {
        char status_type[0x100];
        char status_value[0x200];
    };

    static_assert(sizeof(c_status_value) == 0x300);

    c_status_value* status_values() {
        return reinterpret_cast<c_status_value*>(ADDRESS(0xA48170));
    }
}
