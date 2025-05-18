#pragma once

#include "../native.h"

namespace libmcc::halo3 {
    enum : size_t {
        k_tag_cache_minimum_address = 0x150000000,
        k_tag_cache_maximum_address = 0x1D0000000,
    };

    class c_physical_memory_contiguous_region_listener {
    public:
        virtual void initialize_resize_buffer(void *a1, int a2) = 0;
        virtual void resize_no_fail(void *a1, int a2, void *a3, int a4) = 0;
        virtual void dispose_resize_buffer(void *a1, int a2) = 0;
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
        char* allocation_base_address;
        char* allocation_end_address;
        uint64_t no_mans_land;
        int current_stage;
        s_physical_memory_stage memory_stages[8];
    };

    static_assert(sizeof(s_physical_memory_globals) == 296);

    inline s_physical_memory_globals* physical_memory_globals() {
        return REF<s_physical_memory_globals>(s_data_offset_table::physical_memory_globals);
    }
}
