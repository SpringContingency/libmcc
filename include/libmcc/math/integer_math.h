#pragma once

namespace libmcc {
    union short_point2d {
        struct {
            short x, y;
        };
        short n[2];
    };

    union rectangle2d {
        struct {
            short y0;
            short x0;
            short y1;
            short x1;
        };
        struct {
            short top;
            short left;
            short bottom;
            short right;
        };
        short n[4];
    };
}