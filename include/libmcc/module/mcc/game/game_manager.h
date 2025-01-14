#pragma once

#include "../../../game/game_manager.h"

namespace libmcc::mcc {
	class c_game_manager : public i_game_manager {
	public:
		i_game_event_manager* m_game_event_manager;
		int m_unknown_0;
		void* m_unknown_1;
		void* m_unknown_2;
		void* m_unknown_3;
		void* m_unknown_4;
		int m_unknown_5;

		struct { char buffer[680]; } m_unknown_6[69];
	};

	static_assert(sizeof(c_game_manager) == 0xB788);

	inline c_game_manager* p_game_manager() {
		return REF<c_game_manager>(_mcc_data_game_manager);
	}
}
