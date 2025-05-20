#pragma once

#include "../geometry/geometry_definitions.h"

namespace libmcc::halo3 {
	struct render_model_definition {
		string_id name;
		short flags;
		short : 16;
		int runtime_import_info_checksum;
		s_tag_block regions;
		char l1_section_group_index;
		char l2_section_group_index;
		short : 16;
		int instance_starting_mesh_index;
		s_tag_block instance_placements;
		int node_list_checksum;
		s_tag_block nodes;
		s_tag_block marker_groups;
		s_tag_block materials;
		s_tag_block errors;
		real dont_draw_over_camera_cosine_angle;
		s_render_geometry geometry;
		s_tag_block sky_lights;
		real default_lightprobe_r[16];
		real default_lightprobe_g[16];
		real default_lightprobe_b[16];
		s_tag_block volume_samples;
		s_tag_block runtime_node_orientations;
	};

	static_assert(sizeof(render_model_definition) == 0x1CC);
}