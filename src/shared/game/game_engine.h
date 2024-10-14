#pragma once

#include <d3d11.h>

#include "game_task.h"

#include "game_infrastructure.h"
#include "game_options.h"

#define HALO_SCRIPT_PREFIX "HS: "

class c_game_engine_interface {
public:
    virtual void free() = 0;
    virtual void initialize_render(ID3D11Device* device, ID3D11DeviceContext* context, IDXGISwapChain* swap_chain_1, IDXGISwapChain* swap_chain_2) = 0;
    virtual HANDLE initialize_game(i_game_infrastructure* game_manager, const s_game_options* game_options) = 0;
    virtual void game_task_insert(e_game_task task, s_game_task_data* data) = 0;
    virtual void unused_0() = 0;
    virtual void unused_1() = 0;
    virtual void unused_2() = 0;
    virtual void unused_3() = 0;
    virtual void unused_4() = 0;
    virtual void game_task_insert_hs(const char* command) = 0;
    virtual void unused_5() = 0;
};
