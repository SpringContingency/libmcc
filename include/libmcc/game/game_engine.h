#pragma once

#include "../common.h"

#include "./game_manager.h"

#include "./game_options.h"

#include <d3d11.h>

#define GAME_ENGINE_COMMAND_PREFIX "HS: "
#define GAME_ENGINE_COMMAND_PREFIX_LENGTH 4
#define GAME_ENGINE_COMMAND(command) GAME_ENGINE_COMMAND_PREFIX command

namespace libmcc {
    enum e_game_message {
        _game_message_pause = 0,
        _game_message_resume = 1,
        _game_message_quit = 13,
		// no parameter
        _game_message_resize = 14,

		// with parameter
        _game_message_boot_player_0 = 16,
        _game_message_boot_player_9 = 17,
        _game_message_team_change = 18,
    };

    union s_game_message_parameter {
        struct s_boot_player { XUID player; };
        struct s_change_team { XUID player; int team; };
		char __data[16];
    };

	static_assert(sizeof(s_game_message_parameter) == 16);

    class i_game_engine : public i_unknown {
    public:
        virtual void __fastcall initialize(
            ID3D11Device*, 
            ID3D11DeviceContext*, 
            IDXGISwapChain*, 
            IDXGISwapChain* = nullptr
        ) = 0;
        virtual HANDLE __fastcall initialize_game(
            i_game_manager*, 
            const s_game_options*
        ) = 0;
        virtual PSLIST_ENTRY __fastcall post_message(
            e_game_message,
            const s_game_message_parameter*
        ) = 0;
        virtual void __fastcall _() = 0;
        virtual void __fastcall __() = 0;
        virtual void __fastcall ___() = 0;
        virtual void __fastcall ____() = 0;
        virtual void __fastcall _____() = 0;
        virtual PSLIST_ENTRY __fastcall post_command(const char* = "HS: ") = 0;
        virtual void __fastcall ______() = 0;
    };
}
