#pragma once

#include <Windows.h>
#include <d3d11.h>
#include <Xinput.h>
#include <cstring>
#include <cstdint>

#include "./math/real_math.h"
#include "./math/geometry.h"
#include "./math/matrix_math.h"
#include "./math/color_math.h"
#include "./math/integer_math.h"

#include "./scenario/scenario_map_id.h"

#include "./util/string.inl"

typedef uint8_t byte;
typedef uint16_t word;
typedef uint32_t dword;
typedef uint64_t qword;

typedef byte byte_flags;
typedef word word_flags;
typedef dword dword_flags;
typedef qword qword_flags;

typedef uint16_t wchar;
typedef uint64_t t_xuid;
typedef unsigned int string_id;
typedef uint32_t t_definition_index;

typedef real_vector3d Vector3;

union t_uuid {
    struct {
        unsigned long Data1;
        unsigned short Data2;
        unsigned short Data3;
        unsigned char Data4[8];
    };

    int n[4];
};

union s_player_identifier {
    struct {
        int parts[2];
    };

    t_xuid xuid;

    uint64_t n;
};
