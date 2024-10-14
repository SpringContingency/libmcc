#pragma once

namespace Halo3 {
#pragma pack(push, 1)

    struct s_damage_owner {
        __int64 un0;
        int un1;
    };

    static_assert(sizeof(s_damage_owner) == 0xC);

#pragma pack(pop)
}
