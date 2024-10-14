#pragma once

#include "../native.h"

namespace Halo3 {
    struct s_physical_memory {
        struct {
            char buffer[0x1370000];
        } v1;
        struct {
            char buffer[0x400000];
        } v2;
        struct {
            unsigned int offset[0x8000];
            const char buffer[0x800000];
            const char *ptr[0x8000];
        } tag_names;
        char buffer[0x7E030000];
    };

    static_assert(sizeof(s_physical_memory) == 0x80000000);

    struct c_physical_memory_contiguous_region_listener {
        struct vtbl {
            void (__thiscall *initialize_resize_buffer)(c_physical_memory_contiguous_region_listener *, void *, int);
            void (__thiscall *resize_no_fail)(c_physical_memory_contiguous_region_listener *, void *, int, void *, int);
            void (__thiscall *dispose_resize_buffer)(c_physical_memory_contiguous_region_listener *, void *, int);
        };

        vtbl* vftable;
    };

    struct s_physical_memory_stage {
        void* low_address;
        void* high_address;
        unsigned int next_available_zero_allocation;
        unsigned int __unknownC;
        unsigned int __unknown10;
    };

    struct s_physical_memory_globals {
        c_physical_memory_contiguous_region_listener* resize_region_listener;
        int current_stage;
        char* allocation_base_address;
        char* allocation_end_address;
        unsigned int no_mans_land;
        s_physical_memory_stage memory_stages[8];
    };

    static_assert(sizeof(s_physical_memory_globals) == 296);

    inline s_physical_memory_globals* physical_memory_globals() {
        return reinterpret_cast<s_physical_memory_globals*>(ADDRESS(0xA4E170));
    }
}
