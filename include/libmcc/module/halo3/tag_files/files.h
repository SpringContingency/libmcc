#pragma once

#include "../../../common.h"

namespace libmcc::halo3 {
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
}
