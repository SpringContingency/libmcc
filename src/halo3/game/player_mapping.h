#pragma once

#include "../base/base.h"

struct player_mapping_globals_definition {
    int un0;
    t_definition_index map_player[4]; // 0x4
    char un1[0x20];
    t_definition_index input_player[4]; // 0x34
    char un2[0x30];
    int index[4];// 0x74
    int un3[3 * 4];// 0x84
    int screen_count; // 0xB4
    t_definition_index player_datum_index[4]; // 0xB8
    t_definition_index object_datum_index[4]; // 0xC8
    uint8_t players[4]; // 0xD8
};