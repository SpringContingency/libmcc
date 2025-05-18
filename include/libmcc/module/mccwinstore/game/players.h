#include "../native.h"

#include "../../../xdk/xdk.h"
#include "../../../game/players.h"

namespace libmcc::mccwinstore {
	inline void get_user_by_xuid(void* This, s_xdk_user* user, XUID xuid) {
		return INVOKE<void>(s_function_offset_table::get_user_by_xuid, This, user, xuid);
	}
}
