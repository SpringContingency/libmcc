#pragma once

namespace Halo3 {
    struct equipment_datum {
        char buffer[396];
    };

    static_assert(sizeof(equipment_datum) == 396);
}
