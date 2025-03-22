#pragma once

#include "../../common.h"

namespace libmcc::mcc {
	template <typename Ret, typename ...Args>
	inline Ret INVOKE(const s_offset_table_item& func, Args ...args) {
		return libmcc::INVOKE<Ret>(get_module_base_address(), func, args...);
	}

	template <typename T>
	inline T* REF(const s_offset_table_item& data) {
		return libmcc::REF<T>(get_module_base_address(), data);
	}

	struct s_function_offset_table {
		MAKE_OFFSET_TABLE_ITEM(get_user_by_xuid,	0x38cf54,	"48 8B C4 57 48 83 EC ? 48 C7 40 ? ? ? ? ? 48 89 58 ? 48 89 70 ? 49 8B F0 48 8B FA 48 89 50");
		MAKE_OFFSET_TABLE_ITEM(get_user_profile,	0x1e8ebc,	"48 89 54 24 ? 48 89 4C 24 ? 55 53 56 57 41 54 41 55 41 56 41 57 48 8B EC 48 83 EC ? 48 C7 45 ? ? ? ? ? 48 8B F2");
		MAKE_OFFSET_TABLE_ITEM(set_player_gamepad,	0x8CEF8C,	nullptr); // UIInputHandler::UIMessageBasic
	};

	struct s_data_offset_table {
		MAKE_OFFSET_TABLE_ITEM(p_game_data,		 	0x4001658,	"74 ? 8B 08 E8 ? ? ? ? EB ? 83 C8 ? 83 F8 ? 40 0F 94 C5");
		MAKE_OFFSET_TABLE_ITEM(p_game_engine,		0x4000ba0,	"0F 84 ? ? ? ? 8B C8 E8 ? ? ? ? 8B C8");
		MAKE_OFFSET_TABLE_ITEM(p_game_globals,		0x4000bc8,	"C6 80 ? ? ? ? ? E8 ? ? ? ? 33 DB");
		MAKE_OFFSET_TABLE_ITEM(game_manager,		0x3f7b190,	"E8 ? ? ? ? 48 8D 05 ? ? ? ? 48 89 05 ? ? ? ? 33 C0");
		MAKE_OFFSET_TABLE_ITEM(p_input_manager,		0x4001b78,	"48 8B 0D ? ? ? ? 45 33 C9 48 85 C9");
		MAKE_OFFSET_TABLE_ITEM(game_globals_states,	0x3f66890,	"49 8B 94 CE");
	};
}
