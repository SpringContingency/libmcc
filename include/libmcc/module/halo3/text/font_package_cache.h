#pragma once

namespace libmcc::halo3 {
	enum {
		k_font_maximum_packed_byte_count = 0xC000,
		k_font_character_maximum_pages = 0x1802,
		k_font_character_page_size = 8,
	};

	enum e_font_id {
		_font_id_terminal_font = 0x0,
		_font_id_body_text_font = 0x1,
		_font_id_title_font = 0x2,
		_font_id_super_large_font = 0x3,
		_font_id_large_body_text_font = 0x4,
		_font_id_split_screen_hud_message_font = 0x5,
		_font_id_full_screen_hud_message_font = 0x6,
		_font_id_english_body_text_font = 0x7,
		_font_id_hud_number_font = 0x8,
		_font_id_subtitle_font = 0x9,
		_font_id_main_menu_font = 0xA,
		k_font_id_count = 0xB,
	};

	struct s_font {
		int offset;
		int size;
		__int16 __unknown8;
		__int16 __unknownA;
	};

	static_assert(sizeof(s_font) == 12);

	struct s_font_package_entry {
		int first_character_key;
		int last_character_key;
	};

	static_assert(sizeof(s_font_package_entry) == 8);

	struct s_font_package_file_header {
		int version;
		int font_count;
		s_font fonts[64];
		int font_index_mapping[64]; // 776
		int package_file_font_offset; // 1032
		int package_file_font_size; // 1036
		s_font_package_entry first_package_entry; // 1040
	};

	static_assert(sizeof(s_font_package_file_header) == 1048);

	struct s_kerning_pair {
		char first;
		char second;
	};

	static_assert(sizeof(s_kerning_pair) == 2);

	struct s_font_character {
		__int16 abcC_abcB;
		__int16 : 16;
		int packed_pixel_count;
		__int16 width;
		__int16 height;
		__int16 abcA;
		__int16 tmAscent;
	};

	static_assert(sizeof(s_font_character) == 16);

	struct s_font_header {
		int version; // 0
		char name[32]; // 4 
		__int16 ascender; // 36
		__int16 descender; // 38
		__int16 tmExternalLeading; // 40
		__int16 width; // 42
		int kerning_pairs_offset; // 44
		int kerning_pair_count; // 48
		char kerning_pairs[256]; // 52
		int location_table_offset; // 308
		int location_table_count; // 312
		int character_count; // 316
		int character_offset; // 320
		int character_data_size_bytes; // 324
		int : 32;
		int : 32;
		int maximum_packed_pixel_size_bytes;
		int maximum_unpacked_pixel_size_bytes;
		int total_packed_pixel_size_bytes;
		int total_unpacked_pixel_size_bytes;
		int : 32;
		int : 32;
	};

	static_assert(sizeof(s_font_header) == 360);

	struct s_location_table {
		int page_index;
		int page_count;
	};

	struct s_font_package_file {
		s_font_package_file_header header;
		s_font_header font_headers[64];
		char __data[25064];
	};

	static_assert(sizeof(s_font_package_file) == 49152);

	struct s_fallback_font_data {
		char __data[0x13048];
	};

}
