#pragma once

#include "./files.h"
#include "./tag_groups.h"
#include "../memory/data.h"
#include "tag_api_interop.h"

namespace libmcc::halo3 {
    struct s_tag_reference {
        e_tag_group group_tag;
        int : 32;
        int : 32;
        int index;
    };

    static_assert(sizeof(s_tag_reference) == 0x10);

    struct s_tag_data_definition {
        const char *name;
        int maximum_size;
    };

    struct s_tag_data {
        int size;
        int flags;
        int stream_position;
        uint32_t address;
        uint32_t definition;
    };

    static_assert(sizeof(s_tag_data) == 0x14);

    struct s_tag_field_definition {
        int type;
        const char *name;
        LPVOID definition;
    };

    struct s_tag_block_definition {
        const char *name;
        int element_size;
        int maximum_element_count;
        s_tag_field_definition *fields;
    };

    struct s_tag_block {
        int count;
        uint32_t address;
        uint32_t definition;
    };

    static_assert(sizeof(s_tag_block) == 0xC);

    template <typename T>
    struct c_typed_tag_block : s_tag_block {};

    template <typename T>
    struct c_typed_tag_reference : s_tag_reference {};

    struct s_tag_resource {
        union {
            int resource_handle;
            int resource_data;
        };
        int definition_address;
    };

	template <typename T>
	struct c_typed_tag_resource : s_tag_resource {};

    struct s_tag_resources_block {
        int count;
        s_tag_resource* address;
        s_tag_block_definition* definition;
    };
};
