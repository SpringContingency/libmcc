#pragma once

#include <d3d11.h>

#include <shared/shared.h>
#include "game_save.h"
#include "game_event_handler.h"

// variant
#include "game_engine_variant.h"
#include "../scenario/scenario_map_variant.h"
#include "../scenario/scenario_map_id.h"

// settings
#include "../sound/game_audio_settings.h"
#include "../render/game_render_settings.h"
#include "player_profile_settings.h"

// input
#include "mcc/input/input.h"
#include "mcc/input/input_abstraction.h"

struct s2 {
    struct {
        char buffer[128];
    } n[2];
};

enum e_path : int {
    DebugLogs = 0,
    Config = 1,
    Temporary = 2,
    Root = 3,
};

struct map_identifier {
    int in_game_id = -2;
    __int16 un = 0;
    __int16 flag = 0x8888i16;
    __int64 part2 = 0;
};

enum e_game_option {
    _game_option_enable_subtitle = 5,
    _game_option_new_font_package = 6, // use `_icon` suffix instead of language suffix
};

class i_game_infrastructure {
public:
    /// Begin a new frame
    virtual void begin_frame() = 0;

    /// End a new frame.
    /// called in c_rasterizer::end_frame, right before swap_chain->Present() is called
    virtual void end_frame(IN IDXGISwapChain* p_swap_chain, OUT int* flags) = 0;

    /// Resize Window Event.
    virtual void resize_blocking() = 0;

    virtual void game_set_state(int state) = 0;
    virtual void game_restart(int type, const char* reason) = 0;
    virtual void game_auto_save(char* buf, int len) = 0;
    virtual void game_save(s_game_save_data* a2) = 0;
    virtual void game_pause(int a2) = 0;
    virtual void sub_1401E2F04(int a2) = 0;
    virtual const wchar_t* game_set_objectives(const wchar_t* a2) = 0;
    virtual i_game_event_handler* game_event_handler() {return m_game_event_handler;};
    virtual void game_set_game_variant(c_game_engine_variant_interface* variant) = 0;
    virtual void game_set_map_variant(c_scenario_map_variant_interface* variant) = 0;
    virtual void unused_01() {};
    virtual __int64 player_profile_set_LookControlsInverted(int player_index, bool LookControlsInverted) = 0;
    virtual __int64 player_profile_set(int player_index, s_player_profile_settings* profile) = 0;
    virtual char levels_try_and_get_campaign_map(map_identifier* a2, void* a3, void* a4, void* a5) = 0;
    virtual bool get_map_info_campaign(s_map_id *key, char **map_info, int *size) = 0;
    virtual char get_map_info_multiplayer(s_map_id *a2, char **map_info, int *size) = 0;
    virtual void sub_1401E3EB0(void* a2) = 0;
    virtual char sub_1401E518C() = 0;
    virtual void sub_1401E4044(int a2) = 0;
    virtual __int64 sub_1401E440C() = 0;
    virtual __int64 sub_1401E4544(int a2, float a3) = 0;
    virtual void sub_1401E4ED4(__int64 a2, char a3) = 0;
    virtual void unused_02() {};
    virtual bool unused_03() {return 0;};
    virtual __int64 sub_1401E4F44() = 0;
    virtual __int64 sub_1401E4F58(__int64 a2) = 0;
    virtual char sub_1401E4FCC(__int64 a2, __int64 a3) = 0;
    virtual void game_save_state(s_game_state* a2) = 0;
    virtual char sub_1401E51A4() = 0;
    virtual char setting_render_get(s_game_render_settings* a2) = 0;
    virtual void setting_audio_get(s_game_audio_settings* a2) = 0;
    virtual s_player_profile_settings* setting_player_profile_get(s_player_identifier player_identifier) = 0;
    virtual char is_local() = 0;
    virtual bool player_control_data_get(int index, s_player_input_state* input_data) = 0;
    virtual char player_control_mouse_get(__int64 player_index, __int64 p_mouse) = 0;
    virtual float control_device_get_time(int device_index) = 0;
    virtual void control_gamepad_set_state(DWORD dwUserIndex, XINPUT_VIBRATION* pVibration) = 0;
    virtual char network_unknown_function(wchar_t* buf, __int64 a3) = 0;
    virtual __int64 network_sendto_unreliable(__int64 network_id, char* buf, int len, int port) = 0;
    virtual __int64 network_sendto_reliable(__int64 network_id, char* buf, int len, int port) = 0;
    virtual size_t network_recvfrom(char* buf, int len, __int64* network_id, __int16* port) = 0;
    virtual void network_send(char* buf) = 0;
    virtual void sub_1401E62F0(__int64 a2, float a3) = 0;
    virtual bool path_get(e_path path, wchar_t* buf, size_t len) = 0;
    virtual bool path_get_game(e_path path, wchar_t* buf, size_t len) = 0;
    virtual bool path_scenario_path_get_a(int is_not_ugc, char* buf, size_t len) = 0;
    virtual bool path_scenario_path_get_w(int is_not_ugc, wchar_t* buf, size_t len) = 0;
    virtual bool ugc_id_get(s_map_id *map_id, char* buf, size_t len) = 0;
    virtual bool setting_get(e_game_option option, bool* value1, __int64* value2) = 0;
    virtual bool cache_file_validate(int a2) = 0;
    virtual __int64 sub_1401E6664(char* a2) = 0;
    virtual char sub_1401E66C4(char* a2, wchar_t* buf, int len) = 0;
    virtual char sub_1401E67A8() = 0;
    virtual __int64 sub_1401E67D4(int a2, unsigned int a3, const char* a4, const char* a5) = 0;
    virtual char getGameMode(int a2, unsigned int a3, wchar_t *p_gameMode, __int64 a5) = 0;
    virtual bool subtitle_get(const char* sound_tag_name, const char* prefix, int index, wchar_t* buf, size_t len) = 0;
    virtual char sub_1401E6C0C() = 0;
    virtual char sub_1401E6C2C() = 0;
    virtual bool parse_string_new(const wchar_t* str, unsigned int a3, float scale, const char* font_name) = 0;
    virtual char sub_1401E6C94(unsigned __int16 a2, __int64 a3, unsigned int a4, float a5, __int64 a6) = 0;
    virtual __int64 sub_1401E6CEC(unsigned int a2) = 0;
    virtual char sub_1401E6D14(unsigned __int16 a2, unsigned int a3, __int64 a4, __int64 a5) = 0;
    virtual __int64 sub_1401E6D60(unsigned __int16 a2, unsigned __int16 a3, int a4, int a5, __int64 a6) = 0;
    virtual char sub_1401E6DB8(unsigned __int16 a2, int a3, __int64 a4, __int64 a5, int a6, int a7, int a8, __int64 a9, int a10) = 0;
    virtual bool font_get(int font_index, float scale, const char* font_name, __int16* count, __int16* offset) = 0;
    virtual char sub_1401E6E94() = 0;
    virtual __int64 sub_1401E6154() = 0;
    virtual __int64 sub_1401E615C() = 0;
    virtual __int64 sub_1401E3EF0(unsigned int a2, unsigned int a3) = 0;
    virtual __int64 sub_1401E2348(__int64 a2, __int64 a3, float a4, float a5, float a6, float a7, int a8) = 0;
    virtual __int64 sub_1401E4418(__int64 a2) = 0;
    virtual void* sub_1401E44C8(__int64 a2, void* a3, void* a4, void* a5) = 0;
    virtual char sub_1401E6EB4(unsigned int player_index, int a3, void* a4, __int64 a5, char a6) = 0;
    virtual char sub_1401E72BC() = 0;
    virtual __int64 sub_1401E72C4(int a1, int a2, int a3, int a4, int a5) = 0;
    virtual __int64 sub_1401E72CC(void* a2) = 0;
    virtual __int64 sub_1401E731C() = 0;
    virtual __int64 sub_1401E7324() = 0;
    virtual char sub_1401E732C(__int16 a2, __int16 a3) = 0;
    virtual char sub_1401E7354(__int64 a2) = 0;
    virtual __int64 sub_1401E73AC() = 0;
    virtual float sub_1401E7484(int a2) = 0;
    virtual float sub_1401E74C0(int a2) = 0;
    virtual float sub_1401E7500() = 0;
    virtual __int64 sub_1401E750C(float a2, unsigned __int16 a3, __int16 a4, void* a5, void* a6) = 0;
    virtual bool player_get_xuid(s_player_identifier *player_identifier, wchar_t *name, int size, int index) = 0;
    virtual char sub_1401E7540(__int64 a2, __int64 a3, __int64 a4, __int64 a5, int a6, int a7) = 0;
    virtual char sub_1401E75B0(__int64 a2, unsigned int a3) = 0;
    virtual char sub_1401E75E8(__int64 a2, char a3) = 0;
    virtual char sub_1401E7618(__int64 a2) = 0;
    virtual char sub_1401E763C() = 0;
    virtual char sub_1401E7668() = 0;
    virtual char sub_1401E7684(int a2, void* a3) = 0;
    virtual char sub_1401E7718(int a2, void* a3, void* a4, void* a5) = 0;
    virtual __int64 sub_1401E5880(unsigned int player_index, unsigned int a3) = 0;
    virtual char sub_1401E77DC() = 0;
    virtual char sub_1401E77C8() = 0;
    virtual void unused_04() {};
    virtual void unused_05() {};
    virtual void unused_06() {};
    virtual void unused_07() {};
    virtual void unused_08() {};
    virtual void unused_09() {};
    virtual void unused_10() {};
    virtual void unused_11() {};
    virtual void* sub_1401E77FC(__int64 a2, __int64 a3) = 0;
    virtual void sub_1401E788C(__int64 a2, __int64 a3) = 0;
    virtual __int64 sub_1401E3EFC(char* a2) = 0;
    virtual void sub_1401E666C() = 0;
    virtual void sub_1401E6738(__int64 a2) = 0;
    virtual void sub_1401E2438(const char* a2, float a3, float a4, float a5, float a6, int a7) = 0;
    virtual __int64 sub_1401E2580(uint8_t a2) = 0;
    virtual char sub_1401E7A10() = 0;
    virtual s_gamepad_input_preferences* retrieve_gamepad_mapping(s_player_identifier player_identifier) = 0;
    virtual void unused_12() {};
    virtual char sub_1401E7AF0(__int64 a2) = 0;
    virtual void unused_13() {};
    virtual void unused_14() {};

public:
    i_game_event_handler* m_game_event_handler;

};