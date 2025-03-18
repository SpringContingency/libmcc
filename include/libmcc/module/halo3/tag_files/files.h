#pragma once

#include "../../../common.h"

namespace libmcc::halo3 {
    typedef char long_string[256];
    typedef FILETIME s_file_last_modification_date;

    struct c_basic_buffer {
        void* m_buffer;
        int m_size;
    };

    struct s_indirect_file {
        HANDLE handle;
    };

    struct s_file_handle {
        HANDLE handle;
    };

    struct file_reference_info {
        uint32_t signature;
        uint16_t flags;
        uint16_t location;
        long_string path;
    };

    struct s_file_reference : file_reference_info {
        s_file_handle handle;
        int position;
        int : 32;
    };

    static_assert(sizeof(s_file_reference) == 280);
}
