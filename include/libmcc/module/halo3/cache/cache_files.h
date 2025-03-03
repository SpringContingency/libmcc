#pragma once

#include "../native.h"
#include "../../../common.h"
#include "../memory/wrapped_arrays.h"

namespace libmcc::halo3 {
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
        uint32_t address;
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

    union cache_file_tag_instance_t {
        byte *base;
        cache_file_tag_instance *instance;
    };

    union s_cache_file_header {
        struct {
            uint32_t header_signature;
            uint32_t version;
            int un0;
            char halo_engine;
            int un1;
            int tag_memory_size; // [0, 2GB]
            uint16_t scenario_type; // [0, 6)

            char buffer0[710];

            cache_file_tag_instance_t* tag_instances;
            s_cache_file_tags_header* tags_header;

            char buffer1[15624];

            int footer_signature;
        };

        char data[0x4000];
    };

    static_assert(sizeof(s_cache_file_header) == 0x4000);

    struct s_cache_file_globals {
        bool tags_loaded;
        cache_file_tag_instance_t* tag_instances;
        uint64_t : 64;
        s_cache_file_header header;
    };

    inline s_cache_file_globals* g_cache_file_globals() {
        return REF<s_cache_file_globals>(_data_g_cache_file_globals);
    }
}
