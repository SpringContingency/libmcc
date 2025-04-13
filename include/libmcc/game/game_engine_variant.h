#pragma once

#include "../saved_games/saved_game_files.h"

namespace libmcc {
	struct s_game_engine_variant {
		char data[117760];
	};

	static_assert(sizeof(s_game_engine_variant) == 117760);

	class i_game_engine_variant : public i_saved_game_file {

	};
}