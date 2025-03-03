#pragma once

namespace libmcc {
	struct s_scenario_map_variant {
		char data[59392];
	};

	static_assert(sizeof(s_scenario_map_variant) == 59392);

	class i_scenario_map_variant {
	};

}
