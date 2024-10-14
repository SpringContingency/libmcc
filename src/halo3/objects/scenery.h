#pragma once

namespace Halo3 {
    struct scenery_datum {
        char buffer[364];
    };

    static_assert(sizeof(scenery_datum) == 364);

    struct effect_scenery_datum {
        char buffer[352];
    };

    static_assert(sizeof(effect_scenery_datum) == 352);
}
