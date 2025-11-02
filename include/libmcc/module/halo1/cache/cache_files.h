#pragma once
#include <cstdint>
#include "libmcc/module/halo1/tag_files/tag_groups.h"


namespace libmcc::halo1 {

    enum e_scenario_type : uint8_t {
          _scenario_type_solo = 0x0,
          _scenario_type_multiplayer = 0x1,
          _scenario_type_main_menu = 0x2,
          k_scenario_type_count = 0x3,
      };

    struct cache_file_tag_instance
    {
        int32_t group_tag;
        int32_t parent_group_tags[2];
        int32_t tag_index;
        uint32_t name;
        uint32_t base_address;
        uint32_t unused[2];
    };

    static_assert(sizeof(cache_file_tag_instance) == 0x20);

    struct s_cache_file_header {
        int32_t header_signature;
        int32_t version;
        int32_t size;
        int32_t compressed_file_padding;
        int32_t tags_offset;
        int32_t tags_size;
        int32_t index_buffer_count;
        int32_t index_buffers_offset;
        char name[32];
        char build_number[32];
        int16_t scenario_type;
        uint16_t pad;
        uint32_t checksum;
        uint32_t unused2[485];
        int32_t footer_signature;
    };

    static_assert(sizeof(s_cache_file_header) == 0x800);

    struct cache_file_tags_header
    {
        uint32_t tag_instances_ptr;
        int32_t scenario_tag_index;
        uint32_t tags_checksum;
        int32_t tag_count;
        int32_t vertex_buffer_count;
        uint32_t vertex_buffers_ptr;
        int32_t index_buffer_count;
        uint32_t index_buffers_ptr;
        int32_t vertex_index_buffer_size;
        uint32_t signature;
    };
    static_assert(sizeof(cache_file_tags_header) == 0x28);



}
