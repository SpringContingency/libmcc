#pragma once

#include "../../common.h"

namespace libmcc::halo4 {
	inline HMODULE hModule;

	template <typename Ret, typename ...Args>
	inline Ret INVOKE(const s_offset_table_item& func, Args ...args) {
		return libmcc::INVOKE<Ret>(hModule, func, args...);
	}

	template <typename T>
	inline T* REF(const s_offset_table_item& data) {
		return libmcc::REF<T>(hModule, data);
	}

    struct s_data_offset_table {
        MAKE_OFFSET_TABLE_ITEM(c_splitscreen_config__m_config_table,    0xE84DB0,	nullptr);
    };
}
