#pragma once

namespace Halo3 {
    struct s_cluster_reference {
        char bsp_index;
        char cluster_index;
    };

    struct s_location {
        s_cluster_reference cluster_reference;
    };

}
