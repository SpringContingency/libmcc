#pragma once

#include "instanced_geometry_definitions.h"
#include "../geometry/geometry_definitions.h"
#include "../tag_files/tag_resource_runtime.h"

namespace libmcc::halo3 {
    struct s_collision_bsp {
        s_tag_block bsp3d_nodes;
        s_tag_block planes;
        s_tag_block leaves;
        s_tag_block bsp2d_references;
        s_tag_block bsp2d_nodes;
        c_typed_tag_block<s_collision_surface> surfaces;
        c_typed_tag_block<s_collision_edge> edges;
        c_typed_tag_block<s_collision_vertex> vertices;
    };

    struct s_structure_bsp_resources {
        c_typed_tag_block<s_collision_bsp> collision_bsp;
        s_tag_block large_collision_bsp;
        c_typed_tag_block<s_instanced_geometries_definitions> instanced_geometries_definitions;
        s_tag_block pathfinding_data;
    };

    struct c_structure_bsp_resource_interface {
        c_typed_tag_block<s_structure_bsp_resources> raw_resources;
        c_typed_tag_resource<s_structure_bsp_resources> tag_resources;
        s_tag_resource cache_file_resources;
        int use_resource_items;

        s_structure_bsp_resources* get_resources() {
            if (use_resource_items)
				return get_tag_resource<s_structure_bsp_resources>(&tag_resources);
            else
                return get_tag<s_structure_bsp_resources>(raw_resources.address);
        }
    };

    static_assert(sizeof(c_structure_bsp_resource_interface) == 0x20);

    struct s_structure_physics {
        s_tag_block mopp_code_block;
        byte JWF[4];
        real_point3d mopp_bounds_min;
        real_point3d mopp_bounds_max;
        s_tag_block breakable_surfaces_mopp_code_block;
        s_tag_block breakable_surface_key_table;
    };

    struct s_structure_bsp {
		uint32_t checksum; // offset 0x0
		uint32_t import_version; // offset 0x4
		string_id visible_name; // offset 0x8
		uint32_t flags; // offset 0xC
		s_tag_block seam_identifiers; // offset 0x10
		s_tag_block edge_to_seam_edge; // offset 0x1C
		s_tag_block collision_materials; // offset 0x28
		s_tag_block unknown_raw_leaves; // offset 0x34
		real_rectangle3d world_bounds;
		s_tag_block structure_surfaces; // offset 0x58
		s_tag_block large_structure_surfaces; // offset 0x64
		s_tag_block structure_surface_to_triangle_mapping; // offset 0x70
		s_tag_block cluster_portals; // offset 0x7C
		s_tag_block weather_palette; // offset 0x88
		s_tag_block atmosphere_palette; // offset 0x94
		s_tag_block camera_fx_palette; // offset 0xA0
		s_tag_block weather_polyhedra; // offset 0xAC
		s_tag_block detail_objects; // offset 0xB8
		s_tag_block clusters; // offset 0xC4
		s_tag_block materials; // offset 0xD0
		s_tag_block sky_owner_cluster; // offset 0xDC
		s_tag_block conveyor_surfaces; // offset 0xE8
		s_tag_block breakable_surface_sets; // offset 0xF4
		s_tag_block pathfinding_data; // offset 0x100
		s_tag_block pathfinding_edges; // offset 0x10C
		s_tag_block acoustics_palette; // offset 0x118
		s_tag_block background_sound_palette;
		s_tag_block sound_environment_palette;
		s_tag_data sound_pas_data;
		s_tag_block markers; // offset 0x150
		s_tag_block marker_light_palette; // offset 0x15C
		s_tag_block marker_light_palette_index; // offset 0x168
		s_tag_block runtime_decals; // offset 0x174
		s_tag_block environment_object_palette; // offset 0x180
		s_tag_block environment_objects; // offset 0x18C
		byte IMISWXUG[4];
		s_tag_block leaf_map_leaves;
		s_tag_block leaf_map_connections;
		s_tag_block errors;
        c_typed_tag_block<structure_instanced_geometry_instance> instanced_geometry_instances;
		s_tag_block decorator_sets;
		s_render_geometry decorator_instance_buffer;
		s_tag_block acoustics_sound_clusters;
		s_tag_block ambience_sound_clusters;
		s_tag_block reverb_sound_clusters;
		s_tag_block transparent_planes;
		s_tag_block debug_info;
		s_structure_physics structure_physics;
		s_tag_block audibility;
		s_tag_block object_fake_lightprobes;
		s_render_geometry render_geometry;
		s_tag_block widget_references;
		c_structure_bsp_resource_interface resource_interface;
    };

    static_assert(sizeof(s_structure_bsp) == 0x3A0);

}
