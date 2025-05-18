#pragma once

#include "../../common.h"

namespace libmcc::halo3 {
	inline HMODULE hModule;

	template <typename Ret, typename ...Args>
	inline Ret INVOKE(const s_offset_table_item& func, Args ...args) {
		return libmcc::INVOKE<Ret>(hModule, func, args...);
	}

	template <typename T>
	inline T* REF(const s_offset_table_item& data) {
		return libmcc::REF<T>(hModule, data);
	}

	struct s_function_offset_table {
		MAKE_OFFSET_TABLE_ITEM(main_thread_start,								0xA120,		nullptr);
		MAKE_OFFSET_TABLE_ITEM(process_game_engine_globals_messages,			0xB468,		nullptr);
		MAKE_OFFSET_TABLE_ITEM(c_rasterizer_set_explicit_shaders,				0x278C34,	nullptr);
		MAKE_OFFSET_TABLE_ITEM(c_rasterizer_set_pixel_shader_constant,			0x2AF478,	nullptr);
		MAKE_OFFSET_TABLE_ITEM(c_rasterizer_draw_primitive_up,					0x2A32B4,	nullptr);
		MAKE_OFFSET_TABLE_ITEM(c_rasterizer_set_z_buffer_mode,					0x277F90,	nullptr);
		MAKE_OFFSET_TABLE_ITEM(c_network_session__can_accept_any_join_request,	0x11DF8,	"33 D2 F6 81 E4 41 00 00 01 74 ?? 44 8A 81 E4 41 00 00");
	};

	struct s_data_offset_table {
		MAKE_OFFSET_TABLE_ITEM(c_splitscreen_config__m_config_table,			0x8ADFC0,	nullptr);
		MAKE_OFFSET_TABLE_ITEM(g_player_profile_globals,						0x2D3ED70,	nullptr);
		MAKE_OFFSET_TABLE_ITEM(global_scenario,									0xA46A08,	nullptr);
		MAKE_OFFSET_TABLE_ITEM(physical_memory_globals,							0xA4F170,	nullptr);
		MAKE_OFFSET_TABLE_ITEM(saved_film_globals,								0x2127110,	nullptr);
		MAKE_OFFSET_TABLE_ITEM(g_resource_runtime_manager,						0x8F4018,	nullptr);
		MAKE_OFFSET_TABLE_ITEM(g_cache_file_tags_name,							0xA49148,	nullptr);
		MAKE_OFFSET_TABLE_ITEM(g_cache_file_globals,							0x20A9040,	nullptr);
		MAKE_OFFSET_TABLE_ITEM(g_current_cull_mode,								0x968DC0,	nullptr);
		MAKE_OFFSET_TABLE_ITEM(g_cull_mode_changed,								0x8AC580,	nullptr);
		MAKE_OFFSET_TABLE_ITEM(c_visible_items_m_item,							0x917C50,	nullptr);
	};
}
