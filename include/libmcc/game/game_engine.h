#pragma once

#include "../common.h"

#include "./game_manager.h"

#include "./game_options.h"

#include <d3d11.h>

#define GAME_ENGINE_COMMAND_PREFIX "HS: "
#define GAME_ENGINE_COMMAND(command) GAME_ENGINE_COMMAND_PREFIX command

namespace libmcc {
    enum e_game_engine_message_type {
		// no parameter
        _game_engine_message_type_resize = 14,

		// with parameter
        _game_engine_message_type_boot_player_0 = 16,
        _game_engine_message_type_boot_player_9 = 17,
        _game_engine_message_type_team_change = 18,
    };

    union s_game_engine_message_data {
        struct s_game_engine_message_data_boot_player { XUID player; };
        struct s_game_engine_message_data_team_change { XUID player; int team; };
		char n[16];
    };

	static_assert(sizeof(s_game_engine_message_data) == 16);

    class i_game_engine {
    public:
		DEF_PVF(void, free);
        DEF_PVF(void, initialize, ID3D11Device* device, ID3D11DeviceContext* context, IDXGISwapChain* swap_chain, IDXGISwapChain* unused);
		DEF_PVF(HANDLE, initialize_game, i_game_manager* game_manager, const s_game_options* game_options);
        DEF_PVF(PSLIST_ENTRY, insert_message, e_game_engine_message_type type, s_game_engine_message_data* data);
		DEF_PVF(void, unused_0);
		DEF_PVF(void, unused_1);
		DEF_PVF(void, unused_2);
		DEF_PVF(void, unused_3);
		DEF_PVF(void, unused_4);
		DEF_PVF(PSLIST_ENTRY, insert_command, const char* command = GAME_ENGINE_COMMAND_PREFIX);
        DEF_PVF(void, unused_5);
    };
}
