#pragma once

#include "../shared/shared.h"

#include "./tag_files/string_ids.h"

namespace Halo3 {

#pragma pack(push, 1)
    struct s_machine_identifier {
        int un0;
        unsigned short un1;
    };
#pragma pack(pop)

}