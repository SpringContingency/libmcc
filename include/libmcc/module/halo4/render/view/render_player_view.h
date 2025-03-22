#pragma once

#include "../../native.h"

namespace libmcc::halo4 {
    enum e_splitscreen_res {
    };

    struct s_splitscreen_view_config {
        real_rectangle2d bounds;
        e_splitscreen_res splitscreen_res;
    };

    class c_splitscreen_config {
        std::array<std::array<s_splitscreen_view_config, 4>, 5>* m_config_table() {
            return REF<std::array<std::array<s_splitscreen_view_config, 4>, 5>>(s_data_offset_table::c_splitscreen_config__m_config_table);
        }
    };

}