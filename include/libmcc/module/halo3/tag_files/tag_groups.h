#pragma once

#include <cstdint>

namespace libmcc::halo3 {
#define TAG_GROUP(x)

    enum e_tag_group : uint32_t {
        CACHE_FILE_RESOURCE_LAYOUT_TAG = 'play',
        CACHE_FILE_RESOURCE_GESTALT_TAG = 'zone',
        SCENARIO_TAG = 'scnr',
		BITMAP_TAG = 'bitm',
		INVALID_TAG = 0xFFFFFFFF,
    };

	typedef e_tag_group tag;
}
