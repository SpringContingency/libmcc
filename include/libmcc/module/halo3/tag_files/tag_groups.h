#pragma once

#include <cstdint>

namespace libmcc::halo3 {
    enum e_group_tag : uint32_t {
        _group_tag_scenario = 'rncs',
        k_group_tag_invalid = 0xFFFFFFFF,
    };
}
