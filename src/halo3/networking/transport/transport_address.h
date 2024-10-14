#pragma once

#include "WinSock2.h"
#include "ws2ipdef.h"

namespace Halo3 {
    enum _transport_type : short {
        _transport_type_ipv4 = 4,
        _transport_type_ipv6 = 16,
    };

    struct transport_address {
        WORD address[8];
        WORD port;
        short sin_family;
    };
}
