#pragma once

#include "./tag_groups.h"

namespace libmcc::halo3 {
    inline static int* g_tag_base_address;
	inline static cache_file_tag_instance* g_tag_instances;

	static void set_tag_instances(cache_file_tag_instance* tag_instances) { g_tag_instances = tag_instances; }
    static void set_tag_base_address(void* tag_base_address) { g_tag_base_address = reinterpret_cast<int*>(tag_base_address); }

    typedef int tag;

    struct s_tag_reference {
        e_group_tag group_tag;
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

        bool valid() {
			return count > 0 && address != 0;
        }
    };

    static_assert(sizeof(s_tag_block) == 0xC);

    template <typename T>
    struct c_typed_tag_block : s_tag_block {
        T* begin() {
            return reinterpret_cast<T*>(g_tag_base_address + address);
        }

        T* end() {
            return begin() + count;
        }
    };

    template <typename T>
    struct c_typed_tag_reference : s_tag_reference {
        T* get() {
            auto address = g_tag_instances[static_cast<uint16_t>(index)].address;
            return reinterpret_cast<T*>(g_tag_base_address + address);
        }
    };
};