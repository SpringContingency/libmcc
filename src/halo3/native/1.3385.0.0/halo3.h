#pragma once

#define GAME_VERSION "1.3385.0.0"

#include <cstdint>

#include "../../common.h"

#include "../../objects/objects.h"
#include "../../cache/cache_files.h"
#include "../../multithreading/threads.h"

namespace Halo3 {
    extern uint64_t g_game_module;
    extern uint64_t g_tls_pointer_main_thread;
    extern uint64_t g_tls_index;

    inline uint64_t get_game_module() {return g_game_module;}
    inline void set_game_module(uint64_t module) {g_game_module = module;}

    inline uint64_t ADDRESS(uint64_t offset) {return g_game_module + offset;}

    template<typename return_type, typename... Args>
    inline return_type INVOKE(uint64_t offset, Args... args) {
        return reinterpret_cast<return_type(__fastcall*)(...)>(ADDRESS(offset))(args...);
    }

    /* Object */
    inline void object_placement_data_new(object_placement_data* data, t_definition_index datum, t_definition_index parent, s_damage_owner const* damage_owner) {
        INVOKE<void>(0x341158, data, datum, parent, (uint64_t)damage_owner);
    }

    inline t_definition_index object_new(object_placement_data* data) {
        return INVOKE<t_definition_index>(0x341738, data);
    }

    inline object_type_definition** object_type_definitions() {
        return reinterpret_cast<object_type_definition**>(ADDRESS(0x814050));
    }

    inline s_thread_local_storage* MainThreadLocalStorage() {
        return reinterpret_cast<s_thread_local_storage*>(*(reinterpret_cast<uint64_t*>(g_tls_pointer_main_thread) + g_tls_index));
    }

    inline s_cache_file_globals* cache_file_globals() {
        return reinterpret_cast<s_cache_file_globals*>(ADDRESS(0x20A8040));
    }
}