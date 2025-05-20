#pragma once

namespace libmcc::halo3 {
	struct field_information {
		virtual void _() = 0;
	};

	struct block_information {
		virtual void _() = 0;
	};

	struct tag_information {
		virtual void _() = 0;
	};

	class c_root_block_information {
		virtual void _() = 0;
	};
}