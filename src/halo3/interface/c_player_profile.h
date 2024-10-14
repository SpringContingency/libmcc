#pragma once

namespace Halo3 {
    struct c_player_profile_interface {
        char padding[3360];
    };

    static_assert(sizeof(c_player_profile_interface) == 3360);
}

