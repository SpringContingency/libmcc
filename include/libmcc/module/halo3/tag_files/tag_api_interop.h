#pragma once

namespace libmcc::halo3 {
    struct s_tag_interop {
        unsigned int descriptor;
        unsigned int address;
        unsigned int definition_address;
    };

	template <typename t_descriptor, typename t_object>
    struct c_typed_tag_interop : public s_tag_interop {};
}