#pragma once

namespace Halo3 {
    struct creature_datum {
        char buffer[572];
    };

    static_assert(sizeof(creature_datum) == 572);
}
