#pragma once

#include "../../../game/game_engine.h"

namespace libmcc::mcc {
    class i_game_engine : public libmcc::i_game_engine {
    public:
        
    };

    inline i_game_engine** g_game_engine() {
        return REF<i_game_engine*>(_data_p_game_engine);
    }
}