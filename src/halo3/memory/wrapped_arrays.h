#pragma once

namespace Halo3 {
    template<typename T>
    struct c_wrapped_array_no_init {
        int count;
        int padding;
        T* data;
    };
}
