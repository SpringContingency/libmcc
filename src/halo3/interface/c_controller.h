#pragma once

#include "./c_player_profile.h"

namespace Halo3 {
    struct c_controller_interface {
        int un0;
        int un1;
        c_player_profile_interface player_profile;
        char buffer[80];
    };

    static_assert(sizeof(c_controller_interface) == 3448);
}
