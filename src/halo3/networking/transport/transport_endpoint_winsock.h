#pragma once


namespace Halo3 {
    enum {
        _transport_type_unix = 3,
    };


    struct transport_endpoint {
        int type; // 4
    };

    static_assert(sizeof(transport_endpoint) == 32);
}
