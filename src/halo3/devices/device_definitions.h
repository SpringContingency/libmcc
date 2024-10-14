#pragma once

namespace Halo3 {
    // terminal
    struct device_datum {
        char buffer[668];
    };

    static_assert(sizeof(device_datum) == 668);

    struct machine_datum {
        char buffer[564];
    };

    static_assert(sizeof(machine_datum) == 564);

    struct control_datum {
        char buffer[552];
    };

    static_assert(sizeof(control_datum) == 552);
}
