#pragma once

#include "../game/players.h"

namespace libmcc::halo3 {
	union c_player_profile_interface {
		float* fov() {
			return reinterpret_cast<float*>(data + 0x74);
		}

		char data[0xD78];
	};

	static_assert(sizeof(c_player_profile_interface) == 0xD78);

	inline std::array<c_player_profile_interface, k_local_player_count>* g_player_profile_globals() {
		return REF<std::array<c_player_profile_interface, k_local_player_count>>(s_data_offset_table::g_player_profile_globals);
	}
}