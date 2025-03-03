#pragma once

#include "../native.h"

#include "../../../xdk/xdk.h"
#include "../../../game/players.h"

namespace libmcc::mcc {
	inline void get_user_by_xuid(void* This, s_xdk_user* user, XUID xuid) {
		return INVOKE<void>(_func_get_user_by_xuid, This, user, xuid);
	}

	inline s_player_profile* get_user_profile(void* This, const s_xdk_user* user) {
		return INVOKE<s_player_profile*>(_func_get_user_profile, This, user);
	}
}
