#pragma once

namespace libmcc::halo3 {
	enum {
		k_physical_memory_page_mask = 0xFFFF0000,
	};

	struct c_basic_buffer {
		void* m_buffer;
		unsigned long long m_size;
	};

	static_assert(sizeof(c_basic_buffer) == 0x10);
}
