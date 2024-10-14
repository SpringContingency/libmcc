#pragma once

#include <array>

extern std::array<const char*, 228> g_built_in_map_id;

// FE FF FF FF 00 00 88 88  00 00 00 00 00 00 00 00

union s_map_id {
    struct {
        int legacy_map_id;
        unsigned short data1;
        unsigned short data2;
        unsigned long long data3;
    };

    unsigned long long n[2];

    inline void initialize_legacy_map_id(int map_id) {
        legacy_map_id = map_id;
        data1 = 0;
        data2 = 0x8888;
        data3 = 0;
    }

    inline void initialize_new_map_id() {
        legacy_map_id = -2;
        data2 = 0;
    }

    inline bool is_not_null() {
        return n[0] != 0 || n[1] != 0;
    }

    inline bool is_custom_map() {
        return (data2 != 0x8888) | (data3 != 0);
    }

    inline bool test_1() {
        return (data2 != 0x1111) | is_not_null() | (data1 != 1) | (legacy_map_id > 6u);
    }
};