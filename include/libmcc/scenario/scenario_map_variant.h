#pragma once

namespace libmcc {
	union s_scenario_map_variant_storage {
		char scenario_map_variant_data[59392];
	};

	static_assert(sizeof(s_scenario_map_variant_storage) == 59392);

	struct s_author_data {
		__time64_t time_0;
		uint64_t author_0;
		__time64_t time_1;
		uint64_t author_1;
	};

	class i_scenario_map_variant {
	public:
		virtual void free() = 0;
		virtual wchar_t* get_name() = 0;
		virtual wchar_t* set_name(const wchar_t* name) = 0;
		virtual wchar_t* get_description() = 0;
		virtual wchar_t* set_description(const wchar_t* description) = 0;
		virtual wchar_t* get_author(s_author_data* author_data) = 0;
		virtual wchar_t* set_author(const s_author_data* author_data) = 0;
		virtual void set_map_variant(struct s_game_options* game_options) = 0;
		virtual bool get_map_variant_file(const char** buf, uint32_t* len) = 0;
		virtual bool get_map_variant_file_2(const char** buf, uint32_t* len) = 0;
		virtual bool is_built_in() = 0;
		virtual bool is_built_in_2() = 0;
		virtual void unknown() = 0;
		virtual s_scenario_map_id* get_map_id() = 0;
		virtual bool set_map_id(s_scenario_map_id* map_id) = 0;
	};
}
