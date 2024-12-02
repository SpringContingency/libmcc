#pragma once

#include "../native.h"

namespace Halo3 {
    enum e_skull {
        _skull_bandana = 23,
        _skull_acrophobia = 45,
        _skull_iron = 64,
        _skull_black_eye = 65,
        _skull_tough_luck = 66,
        _skull_catch = 67,
        _skull_fog = 68,
        _skull_famine = 69,
        _skull_thunderstorm = 70,
        _skull_tilt = 71,
        _skull_mythic = 72,
        _skull_assassin = 96,
        _skull_blind = 97,
        _skull_cowbell = 98,
        _skull_grunt_birthday_party = 99,
        _skull_iwhbyd = 100,
    };

    struct game_globals_definition {
        uint8_t un[0x10];
        // size: 0xFB60
        struct map_info_t {
            uint8_t game_type; // 1 campaign; 2 mp; 3 mainmenu
            uint8_t un1[0x43];
            char name[0x104];
            char un0[0xA8];
            // size: 0xB8
            struct player_init_t {
                bool v_true;
                bool v_false;
                uint16_t user_input;
                int input_map;
                int respawn_flag; // 0x8
                int unun;
                uint64_t un_flag; // 0x10
                wchar name[0x10]; // 0x18
                char un1[0x1E];
                wchar id[0x3]; // 0x56
                char un2[0x34];
                wchar name2[0x10]; // 0x90
                char un3[0x8];
            } playerInit[16]; // 0x200
            uint8_t un2[0xEE08];
            // 0xFB88 - 0xFB98
            uint8_t skulls[0x10];
        } map_info;

        inline bool get_skull(e_skull skull) { return map_info.skulls[skull / 8] & (1 << (skull % 8)); }

        inline void set_skull(e_skull skull, bool enable) {
            if (enable) map_info.skulls[skull / 8] |= (1 << (skull % 8));
            else map_info.skulls[skull / 8] &= ~(1 << (skull % 8));
        }
    };
}