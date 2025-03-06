#pragma once

namespace libmcc::halo3 {
    struct s_secure_signature {
        char __data[20];
    };

    typedef s_secure_signature s_network_http_request_hash;

    struct s_cache_file_header_hash {
        s_network_http_request_hash hash;
        int : 32;
        int : 32;
        int : 32;
    };

    static_assert(sizeof(s_cache_file_header_hash) == 32);

    struct s_rsa_signature {
        char __data[2][128];
    };

    static_assert(sizeof(s_rsa_signature) == 256);
}