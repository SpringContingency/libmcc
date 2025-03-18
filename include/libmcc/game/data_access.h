#pragma once

#include "./game_engine_variant.h"
#include "../scenario/scenario_map_id.h"
#include "../scenario/scenario_map_variant.h"

namespace libmcc {
	class i_data_access {
	public:
		virtual void free() = 0;
		virtual i_scenario_map_variant* create_scenario_map_variant_from_file(const char* buf, uint32_t len) = 0;
		virtual i_scenario_map_variant* create_scenario_map_variant_from_map_id(const s_scenario_map_id* map_id) = 0;
		virtual i_scenario_map_variant* create_scenario_map_variant_from_map_variant(const void* map_variant) = 0;
		virtual i_game_engine_variant* create_game_engine_variant_from_file(const char* buf, uint32_t len) = 0;
		virtual i_game_engine_variant* create_scenario_map_variant_from_game_variant(const void* game_variant) = 0;
	};
}
