#pragma once

#include "array.h"

namespace libmcc::halo3 {
    template<typename T>
    struct c_wrapped_array {
        int m_count;
        T* m_elements;

        T* begin() { return m_elements; }
        T* end() { return m_elements + m_count; }
    };

    template<typename T>
    struct c_wrapped_array_no_init {
        int m_count;
        T* m_elements;

		T* begin() {return m_elements;}
        T* end() {return m_elements + m_count;}
    };
}
