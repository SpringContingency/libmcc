#pragma once

#include "player_profile_settings.h"

union s_player_identifier {
    struct {
        int parts[2];
    };
    __int64 n;
};