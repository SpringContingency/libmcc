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
		_func_get_user_by_xuid = 0x2D3094,
		_func_get_user_profile = 0x1E4794,
	};

	enum e_data {
		_data_p_game_data = 0x3FFD4C8,
		_data_p_game_engine = 0x3FFCAA8,
		_data_p_game_globals = 0x3FFCAC0,
		_data_game_manager = 0x3F76E50,
		_data_p_input_manager = 0x3FFFFF8,

		_data_game_globals_states = 0x3F62910,
	};
}