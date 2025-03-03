#pragma once

#include "../memory/array.h"

namespace libmcc::halo3 {
#pragma pack(push, 1)

    struct s_blf_header {
        int signature;
        int chunk_size;
        __int16 major_version;
        __int16 minor_version;
    };

    struct s_blf_chunk_author : s_blf_header {
        char build_name[16];
        uint64_t build_identifier;
        char build_string[28];
        char author_name[16];
    };

    struct s_blf_chunk_content_header : s_blf_header {
        __int16 build_number;
        __int16 map_minor_version;
        s_saved_game_item_metadata metadata;
    };

    struct s_blf_chunk_start_of_file : s_blf_header {
        __int16 byte_order_marker;
        char name[34];
    };

    struct s_blffile_saved_game_file {
        s_blf_chunk_start_of_file start_of_file_chunk;
        s_blf_chunk_content_header content_header_chunk;
    };

#pragma pack(pop)
}