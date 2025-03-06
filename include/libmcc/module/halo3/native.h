#pragma once

#include "../../common.h"

namespace libmcc::halo3 {
	inline uintptr_t g_hModule;
	inline int g_tls_index;

	enum e_func;
	enum e_data;

	inline void Initialize(HMODULE hModule) {
		g_hModule = reinterpret_cast<uintptr_t>(hModule);
        g_tls_index = get_tls_index(hModule);
	}

	template <typename Ret, typename ...Args>
	inline Ret INVOKE(e_func func, Args ...args) {
		return reinterpret_cast<Ret(__fastcall*)(...)>(g_hModule + func)(args...);
	}

	template <typename T>
	inline T* REF(e_data data) {
		return reinterpret_cast<T*>(g_hModule + data);
	}

	enum e_func {
		_func_main_thread_start = 0xA120,
		_func_process_game_engine_globals_messages = 0xB468,
		_func_c_rasterizer_set_explicit_shaders = 0x278C34,
		_func_c_rasterizer_set_pixel_shader_constant = 0x2AF478,
		_func_c_rasterizer_draw_primitive_up = 0x2A32B4,
		_func_c_rasterizer_set_z_buffer_mode = 0x277F90,
	};

	enum e_data {
		_data_g_player_profile_globals = 0x2D3ED70,
		_data_global_scenario = 0xA46A08,
		_data_physical_memory_globals = 0xA4F170,
		_data_saved_film_globals = 0x2127110,
		_data_g_resource_runtime_manager = 0x8F4018,
		_data_g_cache_file_tags_name = 0xA49148,
		_data_g_cache_file_globals = 0x20A9040,
		_data_g_current_cull_mode = 0x968DC0,
		_data_g_cull_mode_changed = 0x8AC580,
		_data_c_visible_items_m_item = 0x917C50,
	};
}