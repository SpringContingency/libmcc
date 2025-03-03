#pragma once

#include <cstdint>

namespace libmcc::halo3 {
    template<size_t S>
    struct c_static_string {
        char m_data[S];
    };

    template<typename T, size_t S>
    struct c_static_array {
        T* begin() { return m_elements; }
        T* end() { return m_elements + S; }
        size_t size() { return S; }

        T m_elements[S];
    };

    template<typename T, size_t S>
    struct c_simple_list {
        c_simple_list() : m_count(0), m_maximum_count(S) {}

        T* begin() { return m_elements; }
        T* end() { return m_elements + m_count; }

        uint16_t m_maximum_count;
        uint16_t m_count;
        T m_elements[S];
    };
}
