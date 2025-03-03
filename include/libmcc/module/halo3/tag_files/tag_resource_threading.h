#pragma once

#include "../memory/wrapped_arrays.h"

namespace libmcc::halo3 {
    struct s_tag_resource_access_datum {

    };

    struct c_allocation_base {

    };

    struct c_tag_resource_cache_file_access_cache {
        c_wrapped_array<uint64_t> __unknown0;
        c_wrapped_array<s_tag_resource_access_datum*> m_cached_access_datums;
    };

    struct c_tag_resource_thread_access {

    };

}
