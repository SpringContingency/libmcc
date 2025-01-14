#pragma once

#include <cstdint>

#include "../native.h"
#include "../../module.h"
#include "../../../game/game_options.h"

namespace libmcc::mcc {
	enum e_presence_in : int {
		_presence_in_game_campaign,
		_presence_in_game_campaign_coop,
		_presence_in_game_customgames,
		_presence_in_game_mapeditor,
		_presence_in_game_matchmaking,
		_presence_in_game_survival,
		_presence_in_game_firefight,
		_presence_in_game_theater,
		_presence_in_game_dedicatedcustomgame,
	};

	struct s_game_data {
		e_module game_title;
		uint64_t unknown_1[2][4];
		uint32_t unknown_2;

#pragma pack(push, 1)
		struct s_unknown_3 {
			uint32_t unknown_0;
			uint64_t unknown_1;
			uint64_t unknown_2;
			uint32_t unknown_3;
			s_game_options unknown_4;
			uint16_t unknown_5;
			uint8_t unknown_6;
			uint8_t padding_0;
			uint32_t unknown_7;
			uint32_t unknown_8;
			uint16_t unknown_9;
			uint8_t unknown_10;
			uint8_t padding_1;
		} unknown_3;
#pragma pack(pop)

		static_assert(sizeof(s_unknown_3) == 0x2BF58);

		e_presence_in presence_in;

		char unknown_4[844];
	};

	static_assert((sizeof(s_game_data) == 0x2C2F8));

	inline s_game_data** pp_game_data() {
		return REF<s_game_data*>(_mcc_data_p_game_data);
	}
}