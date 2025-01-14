#pragma once

namespace libmcc {
	struct s_game_options {
		char unknown[0x2BF30];
	};

	static_assert((sizeof(s_game_options) == 0x2BF30));
}
