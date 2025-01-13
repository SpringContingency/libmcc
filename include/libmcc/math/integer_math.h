#pragma once

#include <cstdint>

union rectangle2d {
    struct {
        uint16_t y0;
        uint16_t x0;
        uint16_t y1;
        uint16_t x1;
    };
    struct {
        uint16_t top;
        uint16_t left;
        uint16_t bottom;
        uint16_t right;
    };
    uint16_t n[4];
};