#pragma once

#include "../common.h"

#include "./players.h"
#include "./game_results.h"
#include "./game_event_manager.h"
#include "./game_engine_variant.h"

#include "../scenario/scenario_map_id.h"
#include "../scenario/scenario_map_variant.h"

#include <d3d11.h>

namespace libmcc {

	enum e_game_state {
		_game_state_exit = 0x5,
		_game_state_restart = 0x5,
	};

	enum e_game_restart_reason {
	};

    class i_game_manager {
    public:
        /// <summary>
        /// [Render Thread] Called at the start of the game frame
        /// </summary>
        DEF_PVF(void, signal_begin_frame);

        /// <summary>
        /// [Render Thread] Called at the end of the game frame
        /// </summary>
        /// <param name="pSwapChain">[IN] swap chain</param>
        /// <param name="flags">[OUT] present flags</param>
        DEF_PVF(void, signal_end_frame, IDXGISwapChain* pSwapChain, UINT* flags);

        /// <summary>
        /// [Main Thread] Called when the game resizes
        /// </summary>
        DEF_PVF(void, signal_resize);

        /// <summary>
        /// [Main Thread] Set state
        /// </summary>
        /// <param name="state">[IN]</param>
        DEF_PVF(void, game_set_state, e_game_state state);

        /// <summary>
        /// [Main Thread] Called right before the game exits
        /// </summary>
        /// <param name="reason">[IN]</param>
        /// <param name="debug_reason">[IN OPT]</param>
        DEF_PVF(void, signal_restart, e_game_restart_reason reason, const char* debug_reason);

        /// <summary>
        /// [Main Thread] Auto save game state
        /// </summary>
        /// <param name="data">[IN]</param>
        /// <param name="size">[IN]</param>
        DEF_PVF(void, game_auto_save, const char* data, unsigned int size);

        /// <summary>
        /// [Main Thread] Set game result
        /// </summary>
        /// <param name="result">[IN]</param>
        DEF_PVF(void, game_set_result, s_game_result* result);

        /// <summary>
        /// [Main Thread] Pause the game
        /// </summary>
        /// <param name="a1">[IN] always 0</param>
        DEF_PVF(void, game_pause_0, int a1);

        /// <summary>
        /// Similar to game_pause_0, but never used
        /// </summary>
        /// <param name="a1"></param>
        DEF_PVF(void, game_pause_1, int a1);

        /// <summary>
        /// [Main Thread] Set game objective, right before calling game_pause_0
        /// </summary>
        /// <param name="primary_objectives"></param>
        /// <param name="primary_objectives"></param>
        DEF_PVF(void, game_set_objectives, const wchar_t* primary_objectives, const wchar_t* secondary_objectives);

        /// <summary>
        /// [Main Thread] Get game event manager
        /// </summary>
        /// <returns>game event manager</returns>
        DEF_PVF(i_game_event_manager*, game_event_manager);

        /// <summary>
        /// [Pre Launch] Set game variant
        /// </summary>
        /// <param name="variant">game engine variant</param>
        DEF_PVF(void, game_set_game_variant, i_game_engine_variant* variant);

        /// <summary>
        /// [Pre Launch] Set map variant
        /// </summary>
        /// <param name="variant">scenario map variant</param>
        DEF_PVF(void, game_set_map_variant, i_scenario_map_variant* variant);

        /// <summary>
        /// Do nothing
        /// </summary>
        DEF_PVF(void, unused_0);

        /// <summary>
        /// [Main Thread] Set the player's look control inverted via HS
        /// </summary>
        /// <param name="player">player index [0,3]</param>
        /// <param name="inverted"></param>
        DEF_PVF(void, player_set_look_control, int player, bool inverted);

        /// <summary>
        /// [Main Thread] Set player profile
        /// </summary>
        /// <param name="player"></param>
        /// <returns></returns>
        DEF_PVF(void, player_set_profile, int player, s_player_profile* profile);

        /// <summary>
        /// [Main Thread] Need further research
        /// </summary>
        /// <param name="id"></param>
        /// <param name="a3"></param>
        /// <param name="a4"></param>
        /// <param name="a5"></param>
        DEF_PVF(void, level_get_map, s_scenario_map_id* id, void* a3, void* a4, void* a5);

        /// <summary>
        /// [Main Thread] Get campaign map info
        /// </summary>
        /// <param name="id">[IN]</param>
        /// <param name="info">[OUT]</param>
        /// <param name="size">[OUT]</param>
        DEF_PVF(void, level_get_campaign_map_info, s_scenario_map_id* map_id, char** map_info, int* size);

        /// <summary>
        /// [Main Thread] Get multiplayer map info
        /// </summary>
        /// <param name="map_id">[IN]</param>
        /// <param name="map_info">[OUT]</param>
        /// <param name="size">[OUT]</param>
        DEF_PVF(void, level_get_multiplayer_map_info, s_scenario_map_id* map_id, char** map_info, int* size);

        DEF_PVF(void, sub_1401E3EB0);
        DEF_PVF(void, sub_1401E518C);
        DEF_PVF(void, sub_1401E4044);
        DEF_PVF(void, sub_1401E440C);
        DEF_PVF(void, sub_1401E4544);
        DEF_PVF(void, sub_1401E4ED4);
        DEF_PVF(void, unused_1);
        DEF_PVF(void, sub_1401F6630);
        DEF_PVF(void, sub_1401E4F44);
        DEF_PVF(void, sub_1401E4F58);
        DEF_PVF(void, sub_1401E4FCC);
        DEF_PVF(void, sub_1401E50C0);
        DEF_PVF(void, sub_1401E51A4);
        DEF_PVF(void, sub_1401E51AC);
        DEF_PVF(void, sub_1401E78FC);
        DEF_PVF(void, sub_1401E5404);
        DEF_PVF(void, sub_1401E4EC4);
        DEF_PVF(void, sub_1401E5424);
        DEF_PVF(void, sub_1401E550C);
        DEF_PVF(void, sub_1401E5584);
        DEF_PVF(void, sub_1401E5568);
        DEF_PVF(void, sub_1401E5AD8);
        DEF_PVF(void, sub_1401E5B70);
        DEF_PVF(void, sub_1401E5BBC);
        DEF_PVF(void, sub_1401E5C0C);
        DEF_PVF(void, sub_1401E62C8);
        DEF_PVF(void, sub_1401E62F0);
        DEF_PVF(void, sub_1401E5C4C);
        DEF_PVF(void, sub_1401E5CB0);
        DEF_PVF(void, sub_1401E5DA4);
        DEF_PVF(void, sub_1401E5F00);
        DEF_PVF(void, sub_1401E5FD8);
        DEF_PVF(void, sub_1401E63E0);
        DEF_PVF(void, sub_1401E64D0);
        DEF_PVF(void, sub_1401E6664);
        DEF_PVF(void, sub_1401E66C4);
        DEF_PVF(void, sub_1401E67A8);
        DEF_PVF(void, sub_1401E67D4);
        DEF_PVF(void, sub_1401E6938);
        DEF_PVF(void, sub_1401E6A98);
        DEF_PVF(void, sub_1401E6C0C);
        DEF_PVF(void, sub_1401E6C2C);
        DEF_PVF(void, sub_1401E6C48);
        DEF_PVF(void, sub_1401E6C94);
        DEF_PVF(void, sub_1401E6CEC);
        DEF_PVF(void, sub_1401E6D14);
        DEF_PVF(void, sub_1401E6D60);
        DEF_PVF(void, sub_1401E6DB8);
        DEF_PVF(void, sub_1401E6E40);
        DEF_PVF(void, sub_1401E6E94);
        DEF_PVF(void, sub_1401E6154);
        DEF_PVF(void, sub_1401E615C);
        DEF_PVF(void, sub_1401E3EF0);
        DEF_PVF(void, sub_1401E2348);
        DEF_PVF(void, sub_1401E4418);
        DEF_PVF(void, sub_1401E44C8);
        DEF_PVF(void, sub_1401E6EB4);
        DEF_PVF(void, sub_1401E72BC);
        DEF_PVF(void, sub_1401E72C4);
        DEF_PVF(void, sub_1401E72CC);
        DEF_PVF(void, sub_1401E731C);
        DEF_PVF(void, sub_1401E7324);
        DEF_PVF(void, sub_1401E732C);
        DEF_PVF(void, sub_1401E7354);
        DEF_PVF(void, sub_1401E73AC);
        DEF_PVF(void, sub_1401E7484);
        DEF_PVF(void, sub_1401E74C0);
        DEF_PVF(void, sub_1401E7500);
        DEF_PVF(void, sub_1401E750C);
        DEF_PVF(void, sub_1401E572C);
        DEF_PVF(void, sub_1401E7540);
        DEF_PVF(void, sub_1401E75B0);
        DEF_PVF(void, sub_1401E75E8);
        DEF_PVF(void, sub_1401E7618);
        DEF_PVF(void, sub_1401E763C);
        DEF_PVF(void, sub_1401E7668);
        DEF_PVF(void, sub_1401E7684);
        DEF_PVF(void, sub_1401E7718);
        DEF_PVF(void, sub_1401E5880);
        DEF_PVF(void, sub_1401E77DC);
        DEF_PVF(void, sub_1401E77C8);
        DEF_PVF(void, unused_2);
        DEF_PVF(void, unused_3);
        DEF_PVF(void, unused_4);
        DEF_PVF(void, unused_5);
        DEF_PVF(void, unused_6);
        DEF_PVF(void, unused_7);
        DEF_PVF(void, unused_8);
        DEF_PVF(void, unused_9);
        DEF_PVF(void, sub_1401E77FC);
        DEF_PVF(void, sub_1401E788C);
        DEF_PVF(void, sub_1401E3EFC);
        DEF_PVF(void, sub_1401E666C);
        DEF_PVF(void, sub_1401E6738);
        DEF_PVF(void, sub_1401E2438);
        DEF_PVF(void, sub_1401E2580);
        DEF_PVF(void, sub_1401E7A10);
        DEF_PVF(void, sub_1401E7A18);
        DEF_PVF(void, sub_1401C1920);
        DEF_PVF(void, sub_1401E7AF0);
        DEF_PVF(void, unused_10);
        DEF_PVF(void, unused_11);
    };

#define DEF_VFT_IMPL(ret, name, ...) DEF_VFT(ret, name, i_game_manager* This, __VA_ARGS__)

    struct i_game_manager_vftable {
    public:
        /// <summary>
        /// [Render Thread] Called at the start of the game frame
        /// </summary>
        DEF_VFT_IMPL(void, signal_begin_frame);

        /// <summary>
        /// [Render Thread] Called at the end of the game frame
        /// </summary>
        /// <param name="pSwapChain">[IN] swap chain</param>
        /// <param name="flags">[OUT] present flags</param>
        DEF_VFT_IMPL(void, signal_end_frame, IDXGISwapChain* pSwapChain, UINT* flags);

        /// <summary>
        /// [Main Thread] Called when the game resizes
        /// </summary>
        DEF_VFT_IMPL(void, signal_resize);

        /// <summary>
        /// [Main Thread] Set state
        /// </summary>
        /// <param name="state">[IN]</param>
        DEF_VFT_IMPL(void, game_set_state, e_game_state state);

        /// <summary>
        /// [Main Thread] Called right before the game exits
        /// </summary>
        /// <param name="reason">[IN]</param>
        /// <param name="debug_reason">[IN OPT]</param>
        DEF_VFT_IMPL(void, signal_restart, e_game_restart_reason reason, const char* debug_reason);

        /// <summary>
        /// [Main Thread] Auto save game state
        /// </summary>
        /// <param name="data">[IN]</param>
        /// <param name="size">[IN]</param>
        DEF_VFT_IMPL(void, game_auto_save, const char* data, unsigned int size);

        /// <summary>
        /// [Main Thread] Set game result
        /// </summary>
        /// <param name="result">[IN]</param>
        DEF_VFT_IMPL(void, game_set_result, s_game_result* result);

        /// <summary>
        /// [Main Thread] Pause the game
        /// </summary>
        /// <param name="a1">[IN] always 0</param>
        DEF_VFT_IMPL(void, game_pause_0, int a1);

        /// <summary>
        /// Similar to game_pause_0, but never used
        /// </summary>
        /// <param name="a1"></param>
        DEF_VFT_IMPL(void, game_pause_1, int a1);

        /// <summary>
        /// [Main Thread] Set game objective, right before calling game_pause_0
        /// </summary>
        /// <param name="primary_objectives"></param>
        /// <param name="primary_objectives"></param>
        DEF_VFT_IMPL(void, game_set_objectives, const wchar_t* primary_objectives, const wchar_t* secondary_objectives);

        /// <summary>
        /// [Main Thread] Get game event manager
        /// </summary>
        /// <returns>game event manager</returns>
        DEF_VFT_IMPL(i_game_event_manager*, game_event_manager);

        /// <summary>
        /// [Pre Launch] Set game variant
        /// </summary>
        /// <param name="variant">game engine variant</param>
        DEF_VFT_IMPL(void, game_set_game_variant, i_game_engine_variant* variant);

        /// <summary>
        /// [Pre Launch] Set map variant
        /// </summary>
        /// <param name="variant">scenario map variant</param>
        DEF_VFT_IMPL(void, game_set_map_variant, i_scenario_map_variant* variant);

        /// <summary>
        /// Do nothing
        /// </summary>
        DEF_VFT_IMPL(void, unused_0);

        /// <summary>
        /// [Main Thread] Set the player's look control inverted via HS
        /// </summary>
        /// <param name="player">player index [0,3]</param>
        /// <param name="inverted"></param>
        DEF_VFT_IMPL(void, player_set_look_control, int player, bool inverted);

        /// <summary>
        /// [Main Thread] Set player profile
        /// </summary>
        /// <param name="player"></param>
        /// <returns></returns>
        DEF_VFT_IMPL(void, player_set_profile, int player, s_player_profile* profile);

        /// <summary>
        /// [Main Thread] Need further research
        /// </summary>
        /// <param name="id"></param>
        /// <param name="a3"></param>
        /// <param name="a4"></param>
        /// <param name="a5"></param>
        DEF_VFT_IMPL(void, level_get_map, s_scenario_map_id* id, void* a3, void* a4, void* a5);

        /// <summary>
        /// [Main Thread] Get campaign map info
        /// </summary>
        /// <param name="id">[IN]</param>
        /// <param name="info">[OUT]</param>
        /// <param name="size">[OUT]</param>
        DEF_VFT_IMPL(void, level_get_campaign_map_info, s_scenario_map_id* map_id, char** map_info, int* size);

        /// <summary>
        /// [Main Thread] Get multiplayer map info
        /// </summary>
        /// <param name="map_id">[IN]</param>
        /// <param name="map_info">[OUT]</param>
        /// <param name="size">[OUT]</param>
        DEF_VFT_IMPL(void, level_get_multiplayer_map_info, s_scenario_map_id* map_id, char** map_info, int* size);

        DEF_VFT_IMPL(void, sub_1401E3EB0);
        DEF_VFT_IMPL(void, sub_1401E518C);
        DEF_VFT_IMPL(void, sub_1401E4044);
        DEF_VFT_IMPL(void, sub_1401E440C);
        DEF_VFT_IMPL(void, sub_1401E4544);
        DEF_VFT_IMPL(void, sub_1401E4ED4);
        DEF_VFT_IMPL(void, unused_1);
        DEF_VFT_IMPL(void, sub_1401F6630);
        DEF_VFT_IMPL(void, sub_1401E4F44);
        DEF_VFT_IMPL(void, sub_1401E4F58);
        DEF_VFT_IMPL(void, sub_1401E4FCC);
        DEF_VFT_IMPL(void, sub_1401E50C0);
        DEF_VFT_IMPL(void, sub_1401E51A4);
        DEF_VFT_IMPL(void, sub_1401E51AC);
        DEF_VFT_IMPL(void, sub_1401E78FC);
        DEF_VFT_IMPL(void, sub_1401E5404);
        DEF_VFT_IMPL(void, sub_1401E4EC4);
        DEF_VFT_IMPL(void, sub_1401E5424);
        DEF_VFT_IMPL(void, sub_1401E550C);
        DEF_VFT_IMPL(void, sub_1401E5584);
        DEF_VFT_IMPL(void, sub_1401E5568);
        DEF_VFT_IMPL(void, sub_1401E5AD8);
        DEF_VFT_IMPL(void, sub_1401E5B70);
        DEF_VFT_IMPL(void, sub_1401E5BBC);
        DEF_VFT_IMPL(void, sub_1401E5C0C);
        DEF_VFT_IMPL(void, sub_1401E62C8);
        DEF_VFT_IMPL(void, sub_1401E62F0);
        DEF_VFT_IMPL(void, sub_1401E5C4C);
        DEF_VFT_IMPL(void, sub_1401E5CB0);
        DEF_VFT_IMPL(void, sub_1401E5DA4);
        DEF_VFT_IMPL(void, sub_1401E5F00);
        DEF_VFT_IMPL(void, sub_1401E5FD8);
        DEF_VFT_IMPL(void, sub_1401E63E0);
        DEF_VFT_IMPL(void, sub_1401E64D0);
        DEF_VFT_IMPL(void, sub_1401E6664);
        DEF_VFT_IMPL(void, sub_1401E66C4);
        DEF_VFT_IMPL(void, sub_1401E67A8);
        DEF_VFT_IMPL(void, sub_1401E67D4);
        DEF_VFT_IMPL(void, sub_1401E6938);
        DEF_VFT_IMPL(void, sub_1401E6A98);
        DEF_VFT_IMPL(void, sub_1401E6C0C);
        DEF_VFT_IMPL(void, sub_1401E6C2C);
        DEF_VFT_IMPL(void, sub_1401E6C48);
        DEF_VFT_IMPL(void, sub_1401E6C94);
        DEF_VFT_IMPL(void, sub_1401E6CEC);
        DEF_VFT_IMPL(void, sub_1401E6D14);
        DEF_VFT_IMPL(void, sub_1401E6D60);
        DEF_VFT_IMPL(void, sub_1401E6DB8);
        DEF_VFT_IMPL(void, sub_1401E6E40);
        DEF_VFT_IMPL(void, sub_1401E6E94);
        DEF_VFT_IMPL(void, sub_1401E6154);
        DEF_VFT_IMPL(void, sub_1401E615C);
        DEF_VFT_IMPL(void, sub_1401E3EF0);
        DEF_VFT_IMPL(void, sub_1401E2348);
        DEF_VFT_IMPL(void, sub_1401E4418);
        DEF_VFT_IMPL(void, sub_1401E44C8);
        DEF_VFT_IMPL(void, sub_1401E6EB4);
        DEF_VFT_IMPL(void, sub_1401E72BC);
        DEF_VFT_IMPL(void, sub_1401E72C4);
        DEF_VFT_IMPL(void, sub_1401E72CC);
        DEF_VFT_IMPL(void, sub_1401E731C);
        DEF_VFT_IMPL(void, sub_1401E7324);
        DEF_VFT_IMPL(void, sub_1401E732C);
        DEF_VFT_IMPL(void, sub_1401E7354);
        DEF_VFT_IMPL(void, sub_1401E73AC);
        DEF_VFT_IMPL(void, sub_1401E7484);
        DEF_VFT_IMPL(void, sub_1401E74C0);
        DEF_VFT_IMPL(void, sub_1401E7500);
        DEF_VFT_IMPL(void, sub_1401E750C);
        DEF_VFT_IMPL(bool, local_user_get_player, XUID* xuid, wchar_t* name, uint32_t size, int player);
        DEF_VFT_IMPL(void, sub_1401E7540);
        DEF_VFT_IMPL(void, sub_1401E75B0);
        DEF_VFT_IMPL(void, sub_1401E75E8);
        DEF_VFT_IMPL(void, sub_1401E7618);
        DEF_VFT_IMPL(void, sub_1401E763C);
        DEF_VFT_IMPL(void, sub_1401E7668);
        DEF_VFT_IMPL(void, sub_1401E7684);
        DEF_VFT_IMPL(void, sub_1401E7718);
        DEF_VFT_IMPL(void, sub_1401E5880);
        DEF_VFT_IMPL(void, sub_1401E77DC);
        DEF_VFT_IMPL(void, sub_1401E77C8);
        DEF_VFT_IMPL(void, unused_2);
        DEF_VFT_IMPL(void, unused_3);
        DEF_VFT_IMPL(void, unused_4);
        DEF_VFT_IMPL(void, unused_5);
        DEF_VFT_IMPL(void, unused_6);
        DEF_VFT_IMPL(void, unused_7);
        DEF_VFT_IMPL(void, unused_8);
        DEF_VFT_IMPL(void, unused_9);
        DEF_VFT_IMPL(void, sub_1401E77FC);
        DEF_VFT_IMPL(void, sub_1401E788C);
        DEF_VFT_IMPL(void, sub_1401E3EFC);
        DEF_VFT_IMPL(void, sub_1401E666C);
        DEF_VFT_IMPL(void, sub_1401E6738);
        DEF_VFT_IMPL(void, sub_1401E2438);
        DEF_VFT_IMPL(void, sub_1401E2580);
        DEF_VFT_IMPL(void, sub_1401E7A10);
        DEF_VFT_IMPL(s_gamepad_mapping*, local_user_get_gamepad_mapping, XUID* xuid);
        DEF_VFT_IMPL(void, sub_1401C1920);
        DEF_VFT_IMPL(void, sub_1401E7AF0);
        DEF_VFT_IMPL(void, unused_10);
        DEF_VFT_IMPL(void, unused_11);
    };
}
