#pragma once

#include "../common.h"

#include "../memory/wrapped_arrays.h"

namespace Halo3 {
    enum e_cache_file_status : int {
        _cache_file_loaded = 2,
    };

    struct s_cache_file_global_tag_index {
        int type;
        int index;
    };

    struct s_cache_file_tag_group {
        int Magic;
        int ParentMagic;
        int GrandparentMagic;
        string_id Description;
    };

    struct cache_file_tag_instance {
        uint16_t tag_group_index;
        uint16_t datum_index_salt;
        uint32_t memory_address;
    };

    struct s_cache_file_tag_interop_type_fixup {
        int* in_out_interop;
        int type_index;
        int padding;
    };

    struct s_cache_file_tags_header {
        c_wrapped_array_no_init<s_cache_file_tag_group> tag_groups;
        c_wrapped_array_no_init<cache_file_tag_instance> tag_instances;
        c_wrapped_array_no_init<s_cache_file_global_tag_index> global_tag_index;
        c_wrapped_array_no_init<s_cache_file_tag_interop_type_fixup> tag_interop_type_fixups;
    };

    struct s_cache_file_header {
        int header_signature;
        int version;
        int un0;
        int halo_engine;
        int un1;
        int tag_memory_size; // [0, 2GB]
        uint16_t scenario_type; // [0, 6)

        char buffer0[710];

        void* tag_cache_base_address;
        s_cache_file_tags_header* tags_header;

        char buffer1[15624];

        int footer_signature;
    };

    static_assert(sizeof(s_cache_file_header) == 16384);

    struct s_cache_file_globals {
        bool tags_loaded;
        char padding[7];
        void* tag_cache_base_address;
        void* un;
        s_cache_file_header header;
    };
}
