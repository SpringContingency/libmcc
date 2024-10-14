#pragma once

namespace Halo3 {
    template <typename E, typename T, size_t max_value>
    struct c_flags {
        T data;

        inline bool test(E flag) const { return data & flag; }
    };
}
