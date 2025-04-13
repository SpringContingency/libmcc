#pragma once

#include "../common.h"

#include "./players.h"
#include "./game_results.h"
#include "./game_settings.h"
#include "./game_event_manager.h"
#include "./game_engine_variant.h"

#include "../scenario/scenario_map_id.h"
#include "../scenario/scenario_map_variant.h"

#include "../input/input.h"

#include <d3d11.h>

namespace libmcc {
    enum e_folder : int {
        _folder_debug_logs = 0,
        _folder_config = 1,
        _folder_temporary = 2,
        _folder_root = 3,
    };

	enum e_game_state {
        _game_state_map_loaded = 0x1,
		_game_state_exit = 0x5,
		_game_state_restart = 0x5,
        _game_state_enter_leader_board = 0x8,
        _game_state_leave_leader_board = 0x9,
	};

	enum e_game_restart_reason {
	};

    class i_game_manager {
    public:
        virtual void __fastcall begin_frame() = 0;
        virtual void __fastcall end_frame(IDXGISwapChain* swapchain, UINT* flags) = 0;
        virtual void __fastcall resize() = 0;

        virtual void __fastcall set_game_state(e_game_state state) = 0;
        virtual void __fastcall restart_game(e_game_restart_reason reason, const char* message) = 0;
        virtual void __fastcall save_game(const char* buf, uint32_t len) = 0;
        virtual void __fastcall set_game_result(s_game_result* result) = 0;
        virtual void __fastcall pause_game(int a1) = 0;
        virtual void __fastcall _pause_game_(int a1) = 0;
        virtual void __fastcall set_game_objectives(const wchar_t* primary, const wchar_t* secondary) = 0;
        virtual i_game_event_manager* __fastcall get_game_event_manager() = 0;

        virtual void __fastcall set_game_engine_variant(i_game_engine_variant* variant) = 0;
        virtual void __fastcall set_scenario_map_variant(i_scenario_map_variant* variant) = 0;

        virtual uintptr_t __fastcall _() = 0;

        virtual void __fastcall set_player_look_control(e_local_player player, bool inverted) = 0;
        virtual void __fastcall set_player_profile_game_specific(e_local_player player, const s_game_specific_storage* game_specific) = 0;

        virtual bool __fastcall get_map_info(s_scenario_map_id* id, void* a3, void* a4, void* a5) = 0;
        virtual bool __fastcall get_campaign_map_info(const s_scenario_map_id* id, const char** info, uint32_t* size) = 0;
        virtual bool __fastcall get_multiplayer_map_info(const s_scenario_map_id* id, const char** info, uint32_t* size) = 0;

        virtual uintptr_t __fastcall sub_1401E3EB0() = 0;
        virtual uintptr_t __fastcall sub_1401E518C() = 0;
        virtual uintptr_t __fastcall sub_1401E4044() = 0;
        virtual uintptr_t __fastcall sub_1401E440C() = 0;
        virtual uintptr_t __fastcall update_launch_timer(int a2, float a3) = 0;
        virtual uintptr_t __fastcall sub_1401E4ED4() = 0;
        virtual uintptr_t __fastcall __() = 0;
        virtual uintptr_t __fastcall sub_1401F6630() = 0;
        virtual uintptr_t __fastcall sub_1401E4F44() = 0;
        virtual uintptr_t __fastcall sub_1401E4F58() = 0;
        virtual uintptr_t __fastcall sub_1401E4FCC() = 0;
        virtual uintptr_t __fastcall sub_1401E50C0() = 0;
        virtual uintptr_t __fastcall sub_1401E51A4() = 0;

        virtual bool __fastcall get_video_setting(s_game_video_settings* settings) = 0;
        virtual uintptr_t __fastcall get_audio_setting(s_game_audio_settings* settings) = 0;
        virtual s_player_profile* __fastcall get_player_profile(XUID xuid) = 0;

        virtual uintptr_t __fastcall sub_1401E4EC4() = 0;

        virtual bool __fastcall get_input_state(e_local_player player, s_input_state* state) = 0;
        virtual bool __fastcall get_input_state_gamepad(e_local_player player, s_input_state* state) = 0;
        virtual float __fastcall update_input_time(e_local_player player) = 0;
        virtual void __fastcall set_input_state(e_local_player player, s_rumble_state* state) = 0;
        virtual char __fastcall sub_1401E5AD8(__int64 a2, __int64 a3) = 0;

        virtual uint32_t __fastcall network_sendto_unreliable(network_id id, const char* buf, uint32_t len, uint32_t port) = 0;
        virtual uint32_t __fastcall network_sendto_reliable(network_id id, const char* buf, uint32_t len, uint32_t port) = 0;
        virtual uint32_t __fastcall network_recvfrom(char* buf, uint32_t len, network_id* id, uint32_t* port) = 0;
        virtual void __fastcall network_send(const char* buf) = 0;

        virtual __int64 __fastcall sub_1401E62F0(__int64 a2, float a3) = 0;
        virtual bool __fastcall get_folder_path(e_folder folder, wchar_t* buf, size_t len) = 0;
        virtual bool __fastcall get_game_folder_path(e_folder folder, wchar_t* buf, size_t len) = 0;
        virtual bool __fastcall get_scenario_path_a(bool builtin, char* buf, size_t len) = 0;
        virtual bool __fastcall get_scenario_path_w(bool builtin, wchar_t* buf, size_t len) = 0;

        virtual bool __fastcall get_ugc_id(s_scenario_map_id* map_id, char* buf, size_t len) = 0;

        virtual bool __fastcall get_game_setting(e_game_setting setting, bool* v1, uint64_t* v2) = 0;

        virtual bool __fastcall validate_cache_file(int a2) = 0;

        virtual uintptr_t __fastcall sub_1401E6664() = 0;
        virtual uintptr_t __fastcall sub_1401E66C4() = 0;
        virtual uintptr_t __fastcall sub_1401E67A8() = 0;
        virtual uintptr_t __fastcall sub_1401E67D4() = 0;

        virtual bool __fastcall get_game_mode(int a2, unsigned int a3, wchar_t* buf, size_t len) = 0;
        virtual bool __fastcall get_subtitle(const char* sound_tag_name, const char* prefix, int index, wchar_t* buf, size_t len) = 0;

        virtual bool __fastcall font__() = 0;
        virtual bool __fastcall font___() = 0;
        virtual bool __fastcall font_test_string(
            const wchar_t* str, 
            int font_id,
            float scale, 
            const char* font_name
        ) = 0;

        struct s_font_character {
            short : 16;
            float _;
            short : 16;
            short : 16;
            __int16 bitmap_height;
            __int16 bitmap_width;
            __int16 ascender;
            __int16 begin_x;
            __int16 end_x;
            short : 16;
            char : 8;
            char : 8;
        };

        virtual bool __fastcall font_precache_character(
            wchar_t c,
            s_font_character* character,
            int font_id,
            float scale,
            const char* font_name
        ) = 0;

        virtual bool __fastcall font_test__(int) = 0;

        virtual bool __fastcall font_test_char(
            wchar_t c, 
            int font_id,
            float scale, 
            const char* font_name
        ) = 0;

        virtual int __fastcall font_get_kerning_pair_offset(
            wchar_t c,
            int,
            int font_id,
            float scale,
			const char* font_name
        ) = 0;

        virtual bool __fastcall font_set__(
            wchar_t c,
            int font_id,
            float scale,
            const char* font_name,
            int len,
            int count,
            int a8,
            const char* data,
            int size
        ) = 0;

        virtual bool __fastcall font_get_height(
            int font_id, 
            float scale, 
            const char* font_name, 
            uint16_t* ascender,
            uint16_t* descender
        ) = 0;

        virtual bool __fastcall font____() = 0;

        virtual float __fastcall sub_1401E6154() = 0;
        virtual void __fastcall sub_1401E615C() = 0;
        virtual uintptr_t __fastcall sub_1401E3EF0() = 0;
        virtual void __fastcall draw_player_icon(
            XUID xuid,
            int,
            float x0,
			float x1,
			float y0,
			float y1
        ) = 0;
        virtual uintptr_t __fastcall sub_1401E4418() = 0;
        virtual uintptr_t __fastcall sub_1401E44C8() = 0;
        virtual bool __fastcall get_player_weapon_offset(
            datum_index index,
            e_local_player player,
            const char* tag_name,
            real_vector3d* offset,
            bool dual_wielding
        ) = 0;
        virtual uintptr_t __fastcall sub_1401E72BC() = 0;
        virtual uintptr_t __fastcall sub_1401E72C4() = 0;
        virtual uintptr_t __fastcall sub_1401E72CC() = 0;
        virtual uintptr_t __fastcall sub_1401E731C() = 0;
        virtual uintptr_t __fastcall sub_1401E7324() = 0;
        virtual uintptr_t __fastcall sub_1401E732C() = 0;
        virtual uintptr_t __fastcall sub_1401E7354() = 0;
        virtual uintptr_t __fastcall sub_1401E73AC() = 0;
        virtual uintptr_t __fastcall sub_1401E7484() = 0;
        virtual uintptr_t __fastcall sub_1401E74C0() = 0;
        virtual uintptr_t __fastcall sub_1401E7500() = 0;
        virtual uintptr_t __fastcall sub_1401E750C() = 0;

        virtual bool __fastcall get_player_xuid(
            XUID* xuid, 
            wchar_t* name, 
            int size, 
            e_local_player player
        ) = 0;

        virtual uintptr_t __fastcall sub_1401E7540() = 0;
        virtual uintptr_t __fastcall sub_1401E75B0() = 0;
        virtual uintptr_t __fastcall sub_1401E75E8() = 0;
        virtual uintptr_t __fastcall sub_1401E7618() = 0;
        virtual uintptr_t __fastcall sub_1401E763C() = 0;
        virtual uintptr_t __fastcall sub_1401E7668() = 0;
        virtual uintptr_t __fastcall sub_1401E7684() = 0;
        virtual uintptr_t __fastcall sub_1401E7718() = 0;
        virtual uintptr_t __fastcall sub_1401E5880() = 0;
        virtual uintptr_t __fastcall sub_1401E77DC() = 0;
        virtual uintptr_t __fastcall sub_1401E77C8() = 0;
        virtual uintptr_t __fastcall ___() = 0;
        virtual uintptr_t __fastcall ____() = 0;
        virtual uintptr_t __fastcall _____() = 0;
        virtual uintptr_t __fastcall ______() = 0;
        virtual uintptr_t __fastcall _______() = 0;
        virtual uintptr_t __fastcall ________() = 0;
        virtual uintptr_t __fastcall _________() = 0;
        virtual uintptr_t __fastcall __________() = 0;
        virtual uintptr_t __fastcall sub_1401E77FC() = 0;
        virtual uintptr_t __fastcall sub_1401E788C() = 0;
        virtual uintptr_t __fastcall sub_1401E3EFC() = 0;
        virtual uintptr_t __fastcall sub_1401E666C() = 0;
        virtual uintptr_t __fastcall sub_1401E6738() = 0;
        virtual uintptr_t __fastcall sub_1401E2438() = 0;
        virtual uintptr_t __fastcall sub_1401E2580() = 0;
        virtual bool __fastcall sub_1401E7A10() = 0;

        virtual s_gamepad_mapping* __fastcall get_player_gamepad_mapping(
            XUID xuid
        ) = 0;

        virtual int __fastcall sub_1401C1920() = 0;
        virtual bool __fastcall sub_1401E7AF0() = 0;
        virtual uintptr_t __fastcall ___________() = 0;
        virtual uintptr_t __fastcall ____________() = 0;
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
        /// <param name="player"></param>
        /// <param name="inverted"></param>
        DEF_VFT_IMPL(void, player_set_look_control, e_local_player player, bool inverted);

        /// <summary>
        /// [Main Thread] Set player profile
        /// </summary>
        /// <param name="player"></param>
        /// <returns></returns>
        DEF_VFT_IMPL(void, player_set_profile, e_local_player player, s_player_profile* profile);

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
        DEF_VFT_IMPL(s_player_profile*, local_user_get_profile, XUID xuid);
        DEF_VFT_IMPL(void, sub_1401E4EC4);
        DEF_VFT_IMPL(bool, input_update, e_local_player player, s_input_state* state);
        DEF_VFT_IMPL(bool, input_update_gamepad, e_local_player player, s_input_state* state);
        DEF_VFT_IMPL(float, input_get_time, e_local_player player);
        DEF_VFT_IMPL(void, input_set_rumble, e_local_player player, s_rumble_state* state);
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
        DEF_VFT_IMPL(bool, local_user_get_player, XUID* xuid, wchar_t* name, uint32_t size, e_local_player player);
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
        DEF_VFT_IMPL(s_gamepad_mapping*, local_user_get_gamepad_mapping, XUID xuid);
        DEF_VFT_IMPL(void, sub_1401C1920);
        DEF_VFT_IMPL(void, sub_1401E7AF0);
        DEF_VFT_IMPL(void, unused_10);
        DEF_VFT_IMPL(void, unused_11);
    };
}
