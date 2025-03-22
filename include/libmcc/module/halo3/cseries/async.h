#pragma once

#include "../tag_files/files.h"

namespace libmcc::halo3 {
    struct c_synchronized_long {
        volatile int m_value;
    };

    struct s_async_buffer {
        void *data;
        int data_allocation_size;
        bool use_external_storage;
        int __unknownC;
        int data_size;
        c_synchronized_long __unknown14;
        int __unknown18;
        c_synchronized_long async_ready;
    };

    static_assert(sizeof(s_async_buffer) == 40);

    struct c_async_buffer_set_base {
        int m_buffer_count;
        s_async_buffer m_buffer[3];
    };

    struct c_async_buffer_set : c_async_buffer_set_base {
        bool __unknown64;
        int m_file_access;
        int m_state;
        s_file_handle m_async_file_handle;
        int : 32;
        int m_file_position;
        int m_file_size;
        int m_buffer_index;
        bool m_storage_initialized;
        bool m_at_end_of_file;
        bool m_fatal_error_occurred;
    };

    static_assert(sizeof(c_async_buffer_set) == 176);
}
