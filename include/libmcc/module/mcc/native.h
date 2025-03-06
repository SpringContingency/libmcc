#pragma once

#include "../../common.h"

namespace libmcc::mcc {
	inline uintptr_t g_hModule;

	enum e_func;
	enum e_data;

	inline void Initialize(HMODULE hModule) {
		g_hModule = reinterpret_cast<uintptr_t>(hModule);
	}

	template <typename Ret, typename ...Args>
	inline Ret INVOKE(e_func func, Args ...args) {
		return reinterpret_cast<Ret (__fastcall*)(...)>(g_hModule + func)(args...);
	}

	template <typename T>
	inline T* REF(e_data data) {
		return reinterpret_cast<T*>(g_hModule + data);
	}

	enum e_func {
		_func_get_user_by_xuid = 0x38cf54, // 48 8B C4 57 48 83 EC ? 48 C7 40 ? ? ? ? ? 48 89 58 ? 48 89 70 ? 49 8B F0 48 8B FA 48 89 50
		_func_get_user_profile = 0x1e8ebc, // 48 89 54 24 ? 48 89 4C 24 ? 55 53 56 57 41 54 41 55 41 56 41 57 48 8B EC 48 83 EC ? 48 C7 45 ? ? ? ? ? 48 8B F2
	};

	enum e_data {
		_data_p_game_data = 0x4001658, // 74 ? 8B 08 E8 ? ? ? ? EB ? 83 C8 ? 83 F8 ? 40 0F 94 C5
		_data_p_game_engine = 0x4000ba0, // 0F 84 ? ? ? ? 8B C8 E8 ? ? ? ? 8B C8
		_data_p_game_globals = 0x4000bc8, // C6 80 ? ? ? ? ? E8 ? ? ? ? 33 DB
		_data_game_manager = 0x3f7b190, // E8 ? ? ? ? 48 8D 05 ? ? ? ? 48 89 05 ? ? ? ? 33 C0
		_data_p_input_manager = 0x4001b78, // 48 8B 0D ? ? ? ? 45 33 C9 48 85 C9

		_data_game_globals_states = 0x3f66890, // 49 8B 94 CE
	};
}