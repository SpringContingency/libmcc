#pragma once

#include "../tag_files/tag_files.h"
#include "../rasterizer/rasterizer_globals.h"
#include "../rasterizer/rasterizer_vertex_definitions.h"

namespace libmcc::halo3 {
	enum e_prt_type : char {
		_prt_type_none = 0x0,
		_prt_type_ambient = 0x1,
		_prt_type_linear = 0x2,
		_prt_type_quadratic = 0x3,
	};

	struct s_render_vertex_buffer_descriptor {
	    int vertex_count;
		e_vertex_buffer_declaration declaration;
	    short stride;
	    s_tag_data vertex_data;
	};

	struct s_render_index_buffer_descriptor {
		c_rasterizer_index_buffer::e_primitive_type primitive_type;
		s_tag_data index_data;
	};

	struct s_part {
	    short render_method_index;
	    short transparent_sorting_index;
	    short index_start;
	    short index_count;
	    short subpart_start;
	    short subpart_count;
	    char part_type;
	    char part_flags;
	    short budget_vertex_count;
	};

	static_assert(sizeof(s_part) == 0x10);

	struct s_subpart {
		short index_start;
		short index_count;
		short part_index;
		short budget_vertex_count;
	};

	static_assert(sizeof(s_subpart) == 0x8);

	struct s_mesh {
		c_typed_tag_block<s_part> parts;
		c_typed_tag_block<s_subpart> subparts;
		uint16_t vertex_buffer_indices[8];
		uint16_t index_buffer_indices[2];
		uint8_t mesh_flags;
		char rigid_node_index;
		e_vertex_type vertex_type;
		e_prt_type prt_vertex_type;
		c_rasterizer_index_buffer::e_primitive_type index_buffer_type;
		char : 8;
		char : 8;
		char : 8;
		s_tag_block instanced_buckets;
		s_tag_block water_indices_start;
	};

	static_assert(sizeof(s_mesh) == 76);

	typedef
		c_typed_tag_interop<s_render_vertex_buffer_descriptor, c_rasterizer_vertex_buffer>
		render_vertex_buffer_interop_definition;

	typedef
		c_typed_tag_interop<s_render_index_buffer_descriptor, c_rasterizer_index_buffer>
		render_index_buffer_interop_definition;

	struct s_render_geometry_api_resource {
		c_typed_tag_block<render_vertex_buffer_interop_definition> pc_vertex_buffers;
		c_typed_tag_block<render_index_buffer_interop_definition> pc_index_buffers;
		c_typed_tag_block<render_vertex_buffer_interop_definition> xenon_vertex_buffers;
		c_typed_tag_block<render_index_buffer_interop_definition> xenon_index_buffers;
	};

	static_assert(sizeof(s_render_geometry_api_resource) == 48);

	struct s_render_geometry {
		uint32_t runtime_flags;
		c_typed_tag_block<s_mesh> meshes;
		s_tag_block compression_info;
		s_tag_block part_sorting_position;
		s_tag_block user_data;
		s_tag_block per_mesh_temporary;
		s_tag_block per_mesh_mopp;
		s_tag_block per_mesh_node_map;
		s_tag_block per_mesh_subpart_visibility;
		s_tag_block per_mesh_prt_data;
		s_tag_block per_instance_lightmap_texcoords;
		c_typed_tag_resource<s_render_geometry_api_resource> api_resource;
	};
}
