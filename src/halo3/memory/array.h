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
        __int32 actual_count;
        word next_identifier;
        word isolated_next_identifier; // 70
        char* data;
        dword* in_use_bit_vector;
        int offset_to_data;
        int offset_to_bit_vector;   // 92

        inline bool isValid(int16 index) const { return index >= 0 && index < size && index < maximum_count; }
        inline char* get(int16 index) const { return (char*)((int64)data + (int64)size * (int16)index); }
        inline __int32 datum_index(int16 index) const { return ((__int32)(*(int16*)((int64)data + index * size)) << 16) | index;}
    };
}
