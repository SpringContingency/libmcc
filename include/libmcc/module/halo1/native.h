#pragma once

#include "../../common.h"

namespace libmcc::halo1 {
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
        MAKE_OFFSET_TABLE_ITEM(dsSTATE_MGR__SetState,       0x18AE40,   nullptr);
        MAKE_OFFSET_TABLE_ITEM(dsSTATE_MGR__RegisterState,  0x5DB40,    nullptr);
        MAKE_OFFSET_TABLE_ITEM(dsSTATE_MGR__GetState,       0x18B150,   nullptr);
    };
}