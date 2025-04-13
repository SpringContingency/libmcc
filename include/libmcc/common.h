#pragma once

#include "./win32/win32.h"
#include "./xdk/xdk.h"
#include "./math/math.inl"

#include <array>

namespace libmcc {
	struct c_synchronized_long {
		volatile unsigned long m_value;
	};

	struct c_synchronized_int64 {
		volatile unsigned long long m_value;
	};

	typedef int string_id;

	typedef unsigned int datum_index;

	typedef uint64_t network_id;

	typedef int s_big_endian_int;

	typedef int s_little_endian_int;

	typedef std::pair<uintptr_t, const char*> s_offset_table_item;

	template <typename Ret, typename ...Args>
	inline Ret INVOKE(HMODULE hModule, const s_offset_table_item& func, Args ...args) {
		return reinterpret_cast<Ret(__fastcall*)(...)>(reinterpret_cast<uintptr_t>(hModule) + func.first)(args...);
	}

	template <typename T>
	inline T* REF(HMODULE hModule, const s_offset_table_item& data) {
		return reinterpret_cast<T*>(reinterpret_cast<uintptr_t>(hModule) + data.first);
	}

	class i_unknown {
	public:
		virtual void __fastcall free() = 0;
	};

	enum e_unknown {};

	template<typename T = int, typename E = e_unknown>
	struct s_flags {
		s_flags() {}
		s_flags(T n) : n(n) {}

		bool bit_test(E position) {
			return n & (1 << position);
		}

		void bit_set(E position, bool value) {
			if (value) {
				n |= (1 << position);
			} else {
				n &= ~(1 << position);
			}
		}

		bool bit_test(T position) {
			return bit_test(static_cast<E>(position));
		}

		void bit_set(T position, bool value) {
			bit_set(static_cast<E>(position), value);
		}

		void operator=(T value) {
			n = value;
		}

		operator T() const {
			return n;
		}

		T n;
	};
}

#define byte_swap(x) _byteswap_ulong(x)

#define MAKE_OFFSET_TABLE_ITEM(name, offset, aob) constexpr static const s_offset_table_item name = s_offset_table_item(offset, aob)

#define DEF_PVF(ret, name, ...) virtual ret __fastcall name(__VA_ARGS__) = 0

#define DEF_VFT(ret, name, ...) ret (__fastcall* name)(__VA_ARGS__)
