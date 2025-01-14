#pragma once

#include "../../common.h"

namespace libmcc::mcc {
	inline uint64_t g_hModule;

	enum e_mcc_func;
	enum e_mcc_data;

	inline void Initialize(void* hModule) {
		g_hModule = reinterpret_cast<uint64_t>(hModule);
	}

	template <typename Ret, typename ...Args>
	inline Ret INVOKE(e_mcc_func func, Args ...args) {
		return reinterpret_cast<Ret (__fastcall*)(...)>(g_hModule + func)(args...);
	}

	template <typename T>
	inline T* REF(e_mcc_data data) {
		return reinterpret_cast<T*>(g_hModule + data);
	}

	enum e_mcc_func {

	};

	enum e_mcc_data {
		_mcc_data_p_game_data = 0x3FFD4C8,
		_mcc_data_p_game_engine = 0x3FFCAA8,
		_mcc_data_game_manager = 0x3F76E50,
		_mcc_data_p_input_manager = 0x3FFFFF8,
	};
}