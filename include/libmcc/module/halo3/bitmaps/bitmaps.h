#pragma once

#include "../../../common.h"
#include "../tag_files/tag_groups.h"

namespace libmcc::halo3 {
	struct c_rasterizer_texture_ref {
		short m_datum_ref;
		short __unknown2;
	};

	struct bitmap_data {
		tag signature;
		__int16 width;
		__int16 height;
		char depth;
		s_flags<char> more_flags;
		__int16 type;
		__int16 format;
		s_flags<short> flags;
		short_point2d registration_point;
		char mipmap_count_excluding_highest;
		char curve;
		char interleaved_interop;
		char interleaved_texture_index;
		int pixels_offset;
		int pixels_size;
		int high_res_pixels_offset_offset;
		int high_res_pixels_size;
		c_rasterizer_texture_ref internal_hardware_format;
		void* base_address;
	};

	static_assert(sizeof(bitmap_data) == 0x38);
}
