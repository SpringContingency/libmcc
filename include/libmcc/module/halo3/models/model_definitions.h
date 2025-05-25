#pragma once

#include "render_model_definitions.h"

namespace libmcc::halo3 {
	union s_model_definition {
		struct {
			c_typed_tag_reference<render_model_definition> render_model;
			s_tag_reference collision_model;
			s_tag_reference animation;
			s_tag_reference physics_model;
		};

		char __data[0x188];
	};
}
