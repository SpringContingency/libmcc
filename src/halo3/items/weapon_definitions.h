#pragma once

namespace Halo3 {
    struct weapon_datum {
        char buffer[648];
    };

    static_assert(sizeof(weapon_datum) == 648);
}
