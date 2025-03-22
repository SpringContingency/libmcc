#pragma once

namespace libmcc::groundhog {
	inline HMODULE hModule;

	template <typename Ret, typename ...Args>
	inline Ret INVOKE(const s_offset_table_item& func, Args ...args) {
		return libmcc::INVOKE<Ret>(hModule, func, args...);
	}

	template <typename T>
	inline T* REF(const s_offset_table_item& data) {
		return libmcc::REF<T>(hModule, data);
	}
}
