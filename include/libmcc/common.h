#pragma once

#include "./math/math.h"

typedef uint64_t XUID;

#define DEF_PVF(ret, name, ...) virtual ret __fastcall name(__VA_ARGS__) = 0

#define DEF_VFT(ret, name, ...) ret (__fastcall* name)(__VA_ARGS__)
