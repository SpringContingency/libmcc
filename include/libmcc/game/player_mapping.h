#pragma once

namespace libmcc {
	struct s_custom_keyboard_mouse_mapping_v2 {
		int abstract_button;
		int virtual_key_codes[5];
	};

	static_assert(sizeof(s_custom_keyboard_mouse_mapping_v2) == 0x18);
}
