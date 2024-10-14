#pragma once

#define GAME_VERSION "1.3385.0.0"

#include <Windows.h>
#include <d3d11.h>
#include <Xinput.h>
#include <cstring>

#include "./math/real_math.h"
#include "./math/geometry.h"
#include "./math/matrix_math.h"
#include "./math/color_math.h"
#include "./math/integer_math.h"

typedef int8 byte;
typedef int16 word;
typedef int32 dword;
typedef int64 qword;

typedef byte byte_flags;
typedef word word_flags;
typedef dword dword_flags;
typedef qword qword_flags;

typedef int16 wchar;
typedef int64 t_xuid;
typedef unsigned int datum_index;

union uuid {
    struct {
        unsigned long Data1;
        unsigned short Data2;
        unsigned short Data3;
        unsigned char Data4[8];
    };

    int n[4];
};

struct s_game_instance {
    enum e_game_data {
        _game_data_handle_module,
        _game_data_tls_index,
        _game_data_tls_pointer_main_thread,
        _game_data_tls_pointer_render_thread,

        k_game_data_count = 4,
    };

    inline int64 get_value(e_game_data type) {
        return data[type];
    }

    inline void set_value(e_game_data type, int64 value) {
        data[type] = value;
    }

    inline int64 main_thread_local_storage_pointer() {
        return *(reinterpret_cast<int64*>(data[_game_data_tls_pointer_main_thread]) + data[_game_data_tls_index]);
    }

    int64 data[k_game_data_count];
};
