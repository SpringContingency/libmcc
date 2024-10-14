#pragma once


namespace Halo3 {
    struct vehicle_datum {
        char buffer[1952];
    };

    static_assert(sizeof(vehicle_datum) == 1952);
}
