#pragma once

namespace libmcc {
	class i_game_event_manager {
		virtual bool AchievementEarned() = 0;

		// odst
		// v14 = *(__int128*)(*(*this + 0x498LL))(v10);
		// (*(*this + 0x128LL))(v13, v9, &v14, v6);
	};

	struct i_game_event_manager_vftable {
		void* __data[151];
	};
}