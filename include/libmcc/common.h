#pragma once

#include "./win32/win32.h"
#include "./xdk/xdk.h"
#include "./math/math.inl"

#include <array>

namespace libmcc {
	typedef int string_id;
}

#define DEF_PVF(ret, name, ...) virtual ret __fastcall name(__VA_ARGS__) = 0

#define DEF_VFT(ret, name, ...) ret (__fastcall* name)(__VA_ARGS__)

typedef int s_big_endian_int;
typedef int s_little_endian_int;

#define byte_swap(x) _byteswap_ulong(x)

