#pragma once

#include "../native.h"

namespace Halo3 {
    enum {
        _data_array_can_disconnect_bit = 1 << 0,
        _data_array_disconnected_bit = 1 << 1,
    };

    enum tag : int {

    };

    struct c_allocation_base {
        struct vtbl {
            void *(__thiscall *allocate)(c_allocation_base *, dword, const char *);
            void (__thiscall *deallocate)(c_allocation_base *, void *);
        };

        vtbl* __vftable /*VFT*/;
    };

    struct s_data_array {
        char m_name[32];
        int maximum_count;
        int size;
        char alignment_bits;
        bool valid;
        word_flags flags;
        tag signature;
        c_allocation_base *allocation;
        int next_index;
        int first_unallocated;
        uint32_t actual_count;
        word next_identifier;
        word isolated_next_identifier; // 70
        char* data;
        dword* in_use_bit_vector;
        int offset_to_data;
        int offset_to_bit_vector;   // 92

        inline bool isValid(uint16_t index) const { return index >= 0 && index < size && index < maximum_count; }
        inline char* get(uint16_t index) const { return (char*)((uint64_t)data + (uint64_t)size * (uint16_t)index); }
        inline uint32_t t_definition_index(uint16_t index) const { return ((uint32_t)(*(uint16_t*)((uint64_t)data + index * size)) << 16) | index;}
    };
}
