#pragma once

#include "../memory/array.h"

namespace libmcc::halo3 {
    enum e_saved_game_file_type : uint32_t {
        _saved_game_file_type_personal = 0x0,
        _saved_game_file_type_ctf = 0x1,
        _saved_game_file_type_slayer = 0x2,
        _saved_game_file_type_oddball = 0x3,
        _saved_game_file_type_king = 0x4,
        _saved_game_file_type_juggernaut = 0x5,
        _saved_game_file_type_territories = 0x6,
        _saved_game_file_type_assault = 0x7,
        _saved_game_file_type_infection = 0x8,
        _saved_game_file_type_vip = 0x9,
        _saved_game_file_type_usermap = 0xA,
        _saved_game_file_type_film = 0xB,
        _saved_game_file_type_clip = 0xC,
        _saved_game_file_type_screenshot = 0xD,
        k_saved_game_file_type_count = 0xE,
        _saved_game_file_type_none = 0xFFFFFFFF,
    };

    enum e_game_engine_type : __int32 {
        _game_engine_type_base = 0x0,
        _game_engine_type_ctf = 0x1,
        _game_engine_type_slayer = 0x2,
        _game_engine_type_oddball = 0x3,
        _game_engine_type_king = 0x4,
        _game_engine_type_sandbox = 0x5,
        _game_engine_type_vip = 0x6,
        _game_engine_type_juggernaut = 0x7,
        _game_engine_type_territories = 0x8,
        _game_engine_type_assault = 0x9,
        _game_engine_type_infection = 0xA,
        k_game_engine_type_count = 0xB,
    };

    enum CampaignDifficultyLevel : __int16 {
        eCampaignDifficultyLevelEasy = 0x0,
        eCampaignDifficultyLevelNormal = 0x1,
        eCampaignDifficultyLevelHeroic = 0x2,
        eCampaignDifficultyLevelLegendary = 0x3,
        eCampaignDifficultyLevelCount = 0x4,
    };

    struct s_saved_game_item_metadata {
        uint64_t unique_id;
        wchar_t name[16];
        char description[128];
        char author[16];
        e_saved_game_file_type file_type;
        bool author_is_xuid_online;
        char : 8;
        char : 8;
        char : 8;
        uint64_t author_id;
        uint64_t size_in_bytes;
        __time64_t date;
        int length_seconds;
        int campaign_id;
        int map_id;
        int game_engine_type;
        int campaign_difficulty;
        byte campaign_insertion_point;
        bool campaign_survival_enabled;
        char : 8;
        char : 8;
        uint64_t game_id;
    };

    static_assert(sizeof(s_saved_game_item_metadata) == 248);

    // _fsm
    enum e_saved_game_file_signature : int {
        _saved_game_file_signature_start_of_file = '_blf',
        _saved_game_file_signature_auther = 'athr',
        _saved_game_file_signature_map_variant = 'mvar',
        _saved_game_file_signature_end_of_file = '_eof',
        _saved_game_file_signature_content_header = 'chdr',
        _saved_game_file_signature_saved_film_header = 'flmh',
        _saved_game_file_signature_saved_film_data = 'flmd',
        _saved_game_file_signature_debuge = 'debg',
    };

#pragma pack(push, 1)
    struct s_blf_header {
        s_big_endian_int signature;
        s_big_endian_int chunk_size;
        __int16 major_version;
        __int16 minor_version;
    };

    static_assert(sizeof(s_blf_header) == 0xC);

    struct s_blf_chunk_author : s_blf_header {
        char build_name[16];
        uint64_t build_identifier;
        char build_string[28];
        char author_name[16];
    };

    static_assert(sizeof(s_blf_chunk_author) == 0x50);

    struct s_blf_chunk_content_header : s_blf_header {
        __int16 build_number;
        __int16 map_minor_version;
        s_saved_game_item_metadata metadata;
    };

    struct s_blf_chunk_start_of_file : s_blf_header {
        __int16 byte_order_marker;
        char name[34];
    };

    static_assert(sizeof(s_blf_chunk_start_of_file) == 0x30);

    struct s_blf_chunk_end_of_file : s_blf_header {
        int file_size;
        byte authentication_type;
    };

    static_assert(sizeof(s_blf_chunk_end_of_file) == 0x11);

    struct s_blf_chunk_fsm : s_blf_header {
        char __data[0x1C4];
    };

    static_assert(sizeof(s_blf_chunk_fsm) == 0x1D0);

#pragma pack(pop)
}