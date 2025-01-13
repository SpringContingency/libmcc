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

	inline void* REF(e_mcc_data data) {
		return reinterpret_cast<void*>(g_hModule + data);
	}

	enum e_mcc_func {

	};

	enum e_mcc_data {
		_mcc_data_pGameEngine = 0x3FFCAA8,
		_mcc_data_gameManager = 0x3F76E50,
		_mcc_data_pInputManager = 0x3FFFFF8,
	};
}