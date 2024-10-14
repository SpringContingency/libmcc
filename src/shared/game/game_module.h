#pragma once

#include "game_engine.h"
#include "game_language.h"
#include "game_data_access.h"

struct s_game_module {
    HMODULE module;
    union {
        struct {
            __int64 (__fastcall* CreateDataAccess)(OUT class c_game_data_access_interface**);
            __int64 (__fastcall* CreateGameEngine)(OUT class c_game_engine_interface**);
            errno_t (__fastcall* SetLibrarySettings)(IN class s_game_language_settings*);
        };
        FARPROC methods[3];
    } exports;
};