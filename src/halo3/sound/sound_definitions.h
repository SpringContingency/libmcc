#pragma once

namespace Halo3 {
    struct sound_scenery_datum {
        char buffer[376];
    };

    static_assert(sizeof(sound_scenery_datum) == 376);
}
