#pragma once

namespace libmcc::halo3 {
    template<typename T>
    struct c_wrapped_array {
        int m_count;
        T* m_elements;
    };

    template<typename T>
    struct c_wrapped_array_no_init {
        int m_count;
        T* m_elements;
    };
}
