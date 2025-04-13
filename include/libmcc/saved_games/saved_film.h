#pragma once

#include "../common.h"

namespace libmcc {
	class i_saved_film : public i_unknown {
		virtual wchar_t* get_name() = 0;
		virtual wchar_t* get_description() = 0;
		virtual uint64_t get_author() = 0;
		virtual uint64_t get_unknown() = 0;
		virtual int get_length_in_seconds() = 0;
		virtual int get_game_options_unknown() = 0;
		virtual bool test_game_options_unknown() = 0;
	};
}

