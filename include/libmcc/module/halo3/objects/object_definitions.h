#pragma once

#include "../models/model_definitions.h"

namespace libmcc::halo3 {
	union _object_definition {
		struct {
			short runtime_object_type;
			short flags;
			real bounding_radius;
			real_point3d bounding_offset;
			real acceleration_scale;
			short lightmap_shadow_mode;
			char sweetener_size;
			char water_density;
			int runtime_flags;
			real dynamic_light_sphere_radius;
			real_point3d dynamic_light_sphere_offset;
			string_id default_model_variant;
			c_typed_tag_reference<s_model_definition> model;
		};

		char __data[0xF8];
	};
}