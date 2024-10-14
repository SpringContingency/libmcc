#pragma once

namespace Halo3 {
    struct crate_datum {
        char buffer[356];
    };

    static_assert(sizeof(crate_datum) == 356);
}
