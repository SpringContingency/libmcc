#pragma once

#include "../tag_files/tag_files.h"

namespace libmcc::halo3 {
	enum primitive_type : __int8 {
		primitive_type_line_strip = 0x2,
	};

	enum prt_type : unsigned __int8 {
		_prt_type_none = 0x0,
		_prt_type_ambient = 0x1,
		_prt_type_linear = 0x2,
		_prt_type_quadratic = 0x3,
	};

	enum vertex_type : __int8 {

	};

	struct s_mesh {
		s_tag_block parts;
		s_tag_block subparts;
		uint16_t vertex_buffer_indices[8];
		uint16_t index_buffer_indices[2];
		uint8_t mesh_flags;
		char rigid_node_index;
		vertex_type vertex_type;
		prt_type prt_vertex_type;
		primitive_type index_buffer_type;
		byte BAASDFIR[3];
		s_tag_block instanced_buckets;
		s_tag_block water_indices_start;
	};

	struct s_render_geometry {
		uint32_t runtime_flags;
		s_tag_block meshes;
		s_tag_block compression_info;
		s_tag_block part_sorting_position;
		s_tag_block user_data;
		s_tag_block per_mesh_temporary;
		s_tag_block per_mesh_mopp;
		s_tag_block per_mesh_node_map;
		s_tag_block per_mesh_subpart_visibility;
		s_tag_block per_mesh_prt_data;
		s_tag_block per_instance_lightmap_texcoords;
		s_tag_resource api_resource;
	};
}
