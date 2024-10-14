#pragma once

namespace Halo3 {
    struct projectile_datum {
        char buffer[504];
    };

    static_assert(sizeof(projectile_datum) == 504);
}
