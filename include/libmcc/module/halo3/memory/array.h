#pragma once

#include "./data.h"

namespace libmcc::halo3 {
    struct c_allocation_base {

    };

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

    template<typename T>
    struct s_data_array {
        char name[32];
        int maximum_count;
        int size;
        byte alignment_bits;
        bool valid;
        uint16_t flags;
        tag signature;
        c_allocation_base* allocation;
        int next_index;
        int first_unallocated;
        int actual_count;
        uint16_t next_identifier;
        uint16_t isolated_next_identifier;
        T* data;
        uint32_t* in_use_bit_vector;
        int offset_to_data;
        int offset_to_bit_vector;
    };
}
