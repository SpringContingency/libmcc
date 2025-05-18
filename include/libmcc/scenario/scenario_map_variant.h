#pragma once

#include "../saved_games/saved_game_files.h"

namespace libmcc {
	union s_scenario_map_variant_storage {
		char scenario_map_variant_data[59392];
	};

	static_assert(sizeof(s_scenario_map_variant_storage) == 59392);

	class i_scenario_map_variant : public i_saved_game_file {
	public:
		virtual bool is_built_in() = 0;
		virtual bool is_built_in_2() = 0;
		virtual void unknown() = 0;
		virtual s_scenario_map_id* get_map_id() = 0;
		virtual bool set_map_id(s_scenario_map_id* map_id) = 0;
	};
}
