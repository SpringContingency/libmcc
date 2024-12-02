#pragma once

#include "mcc/game/game_options.h"

class c_scenario_map_variant_interface {
public:
    virtual void free() = 0;
    virtual void unknown_01() = 0;
    virtual void unknown_02() = 0;
    virtual void unknown_03() = 0;
    virtual void unknown_04() = 0;
    virtual void unknown_05() = 0;
    virtual void unknown_06() = 0;
    virtual void initialize_game_options(s_game_options* game_options) = 0;
    virtual void unknown_08() = 0;
    virtual void unknown_09() = 0;
    virtual void unknown_10() = 0;
    virtual void unknown_11() = 0;
    virtual void unknown_12() = 0;
    virtual void unknown_13() = 0;
    virtual void set_map_id(const s_map_id* map_id) = 0;
};