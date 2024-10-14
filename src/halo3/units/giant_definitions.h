#pragma once

namespace Halo3 {
    struct giant_datum {
        char buffer[13928];
    };

    static_assert(sizeof(giant_datum) == 13928);
}
