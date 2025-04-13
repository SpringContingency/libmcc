#pragma once

#include "saved_film.h"

namespace libmcc {
	struct s_author_data {
		__time64_t time_0;
		uint64_t author_0;
		__time64_t time_1;
		uint64_t author_1;
	};

	class i_saved_game_file : public i_unknown {
	public:
		virtual wchar_t* get_name() const = 0;
		virtual wchar_t* set_name(const wchar_t* name) = 0;
		virtual wchar_t* get_description() const = 0;
		virtual wchar_t* set_description(const wchar_t* description) = 0;
		virtual wchar_t* get_author(s_author_data* author_data) const = 0;
		virtual wchar_t* set_author(const s_author_data* author_data) = 0;
		virtual void copy_to_game_options(struct s_game_options* game_options) const = 0;
		virtual bool save_to_file(const char** buf, uint32_t* len) = 0;
		virtual bool save_to_file_(const char** buf, uint32_t* len) = 0;
	};
}
