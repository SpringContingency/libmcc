#pragma once

namespace libmcc {
	struct s_game_result {
		char buffer[0x5D138];
	};

	static_assert(sizeof(s_game_result) == 0x5D138);
}