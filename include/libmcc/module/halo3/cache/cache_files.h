#pragma once

#include "security_functions.h"
#include "../native.h"
#include "../tag_files/files.h"
#include "../memory/wrapped_arrays.h"

namespace libmcc::halo3 {
    enum {
        k_cache_file_content_hash_count = 7,
    };

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

    struct s_cache_file_tags_name {
        uint32_t offset[0x8000];
        char buffer[0x800000];
        const char* name[0x8000];
    };

    static_assert(sizeof(s_cache_file_tags_name) == 0x860000);

    union cache_file_tag_instance_t {
        byte *base;
        cache_file_tag_instance *instance;
    };

    enum e_scenario_type : __int16 {
         _scenario_type_solo = 0x0,
         _scenario_type_multiplayer = 0x1,
         _scenario_type_main_menu = 0x2,
         _scenario_type_multiplayer_shared = 0x3,
         _scenario_type_single_player_shared = 0x4,
         k_scenario_type_count = 0x5,
     };

    enum e_cache_file_partition_type : __int32 {
        _cache_file_partition_type_resources = 0x0,
        _cache_file_partition_type_sound_resources = 0x1,
        _cache_file_partition_type_global_tags = 0x2,
        _cache_file_partition_type_shared_tags = 0x3,
        _cache_file_partition_type_base = 0x4,
        _cache_file_partition_type_map_tags = 0x5,
        k_number_of_cache_file_partition_types = 0x6,
    };

    struct s_cache_file_partition {
        uint64_t base_address;
        int32_t size;
    };

    static_assert(sizeof(s_cache_file_partition) == 0x10);

    enum e_cache_file_section : __int32 {
        _cache_file_section_debug = 0x0,
        _cache_file_section_resource = 0x1,
        _cache_file_section_tag = 0x2,
        _cache_file_section_localization = 0x3,
        k_number_of_cache_file_sections = 0x4,
    };

    struct s_cache_file_section_file_bounds {
        int offset;
        int size;
    };

    struct s_cache_file_interop {
        int section_offsets[k_number_of_cache_file_sections];
        s_cache_file_section_file_bounds original_section_bounds[k_number_of_cache_file_sections];
    };

    struct s_cache_file_insertion_point_resource_usage {
        char __data[184];
    };

    struct s_cache_file_shared_resource_usage {
        char __data[9000];
    };

    struct s_cache_file_header {
            tag header_signature;
            uint32_t version;
            int file_size;
            char halo_engine;
            int tag_buffer_offset;
            int total_tags_size; // [0, 2GB]
            e_scenario_type scenario_type; // [0, 6)
            int : 32;
            int file_table_count;
            int file_table_offset;
            int file_table_size;
            int file_index_table_offset;
            int string_table_count;
            int string_table_offset;
            int string_table_size;
            int string_index_table_offset;
            int string_namespace_table_count;
            int string_namespace_table_offset;
            int : 32;
            int : 32;
            s_file_last_modification_date last_modification_date;
            int : 32;
            int : 32;
            int : 32;
            int : 32;
            int : 32;
            int : 32;
            int : 32;
            int : 32;
            int : 32;
            int : 32;
            int : 32;
            int : 32;
            int : 32;
            int : 32;
            int : 32;
            int : 32;
            int : 32;
            int : 32;
            const char build[0x20];
            const char internal_name[0x20];
            const char source_file[0x100];
            char data0[256];
            cache_file_tag_instance_t* tag_instances; // 736
            s_cache_file_tags_header* tags_header;
            int xdk_version;
            uint64_t : 64;
			s_cache_file_partition partitions[k_number_of_cache_file_partition_types]; // 768
            int checksum1; // 864
            int content_hash_mask;
            uint64_t signature; // 0x17800EA664197BFCLL
            s_network_http_request_hash content_hashes[3]; // 880
            s_cache_file_header_hash hash;
            s_rsa_signature rsa_signature; // 972
            s_cache_file_interop interop; // 1228
            s_cache_file_shared_resource_usage shared_resource_usage; // 1276
            int insertion_point_count;
            s_cache_file_insertion_point_resource_usage insertion_point_resource_usage_storage[12]; // 10280
            char data1[3892];
            tag footer_signature; // 16380
    };

    static_assert(sizeof(s_cache_file_header) == 0x4000);

    struct s_cache_file_globals {
        bool tags_loaded;
        cache_file_tag_instance_t* tag_instances;
        uint64_t : 64;
        s_cache_file_header header;
    };

	inline s_cache_file_tags_name** g_cache_file_tags_name() {
		return REF<s_cache_file_tags_name*>(_data_g_cache_file_tags_name);
	}

    inline s_cache_file_globals* g_cache_file_globals() {
        return REF<s_cache_file_globals>(_data_g_cache_file_globals);
    }
}
