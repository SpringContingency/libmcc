#include "halo3.h"

static uint64_t g_game_module;

uint64_t get_game_module() {
    return g_game_module;
}

void set_game_module(uint64_t module) {
    g_game_module = module;
}
