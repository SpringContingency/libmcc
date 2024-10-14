#pragma once

typedef unsigned char       int8;
typedef unsigned short      int16;
typedef unsigned int        int32;
typedef unsigned long long  int64;

union rectangle2d {
    struct {
        int16 y0;
        int16 x0;
        int16 y1;
        int16 x1;
    };
    struct {
        int16 top;
        int16 left;
        int16 bottom;
        int16 right;
    };
    int16 n[4];
};