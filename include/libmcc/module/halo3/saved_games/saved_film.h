#pragma once

#include "../cseries/async.h"

#include "../game/game_options.h"

#include "./saved_game_files.h"
#include "./saved_film_history.h"
#include "./saved_film_snippet.h"

namespace libmcc::halo3 {
#pragma pack(push, 1)
    struct s_blf_saved_film : s_blffile_saved_game_file {
        struct s_blf_chunk_saved_film_header : s_blf_header {
            // length_in_ticks
            char unknown_0[140];
            int length_in_ticks;
            char unknown_1[132];
            game_options game_options;
        };

        struct s_blf_chunk_saved_film_data : s_blf_header {

        };

        s_blf_chunk_author author_chunk;
        s_blf_chunk_saved_film_header saved_film_header_chunk; // 396
        s_blf_chunk_saved_film_data saved_film_data_chunk;
    };

    static_assert(sizeof(s_blf_saved_film) == 65044);
#pragma pack(pop)

    struct c_saved_film {
        int initialized;
        s_blf_saved_film film_data;
        int __unknown1;
        int __unknown2;
        int current_tick;
        c_async_buffer_set async_buffer_set; // 65064
        s_file_reference file_reference; // 65240
        int __unknown4;
        int __unknown5; // 65524
    };

    static_assert(sizeof(c_saved_film) == 0xFFF8);

    struct s_saved_film_globals {
        int get_length_in_ticks() {
            return saved_film.film_data.saved_film_header_chunk.length_in_ticks;
        }

        game_options* get_game_options() {
            return &saved_film.film_data.saved_film_header_chunk.game_options;
        }

        int get_ticks_remaining() {
            return get_length_in_ticks() - get_current_tick();
        }

        int get_current_tick() {
            return saved_film.current_tick;
        }

        char film_name[64];
        c_saved_film saved_film;
        char __unknown0;
        int file_position;
        char __unknown2;
        char __unknown3;
        float playback_game_speed;
        char unknown_0;
        char unknown_1;
        uint16_t unknown_2;
        uint32_t unknown_3;
        uint32_t unknown_4;
        char unknown_5;
        uint32_t revert_count;
        uint32_t unknown_7;
        uint32_t unknown_8;
        uint32_t unknown_9;

        struct s_unknown {
            uint32_t unknown_0;
            char unknown_1[0x20];
            int unknown_2;
        };

        s_unknown unknown_10;
        char unknown_11;
        int unknown_12;

        uint16_t unknown_13;
        char unknown_14;
        char unknown_15;
        uint32_t unknown_16;
    };

    inline s_saved_film_globals* saved_film_globals() {
        return REF<s_saved_film_globals>(_data_saved_film_globals);
    }

};