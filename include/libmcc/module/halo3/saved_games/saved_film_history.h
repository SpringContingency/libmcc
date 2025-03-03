#pragma once

namespace libmcc::halo3 {
    struct s_saved_film_history_archive_record {
        uint32_t film_position;
        uint32_t film_tick;
        uint32_t history_file_position;
        uint32_t current_tick;
        uint64_t unknown_4;
    };

    static_assert(sizeof(s_saved_film_history_archive_record) == 24);

    template<size_t S>
    struct c_saved_film_history_record_manager {
        s_saved_film_history_archive_record records[S];
    };

    struct s_saved_film_history_globals {
        void* data_ptr;
        c_saved_film_history_record_manager<16> record_manager;
        int dword_182285078;
        int time;
        char byte_182285080;
    };

    static_assert(sizeof(s_saved_film_history_globals) == 408);
}
