#pragma once

#include "../shared/shared.h"

#include "./tag_files/string_ids.h"

#include "./multithreading/threads.h"

namespace Halo3 {
#pragma pack(push, 1)
    struct s_machine_identifier {
        int un0;
        unsigned short un1;
    };
#pragma pack(pop)

    extern s_game_instance* g_game_instance;
    inline s_game_instance* GameInstance() { return g_game_instance; }

    inline int64 ADDRESS(int64 offset) {
        return g_game_instance->get_value(s_game_instance::_game_data_handle_module) + offset;
    }

    template<typename return_type, typename... Args>
    inline return_type INVOKE(int64 offset, Args... args) {
        return reinterpret_cast<return_type(__fastcall*)(...)>(ADDRESS(offset))(args...);
    }

    inline s_thread_local_storage* MainThreadLocalStorage() {
        return reinterpret_cast<s_thread_local_storage*>(g_game_instance->main_thread_local_storage_pointer());
    }
}