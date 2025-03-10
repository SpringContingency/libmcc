#pragma once

#include "../../../common.h"
#include "../tag_files/tag_files.h"
#include "../geometry/geometry_definitions.h"
#include "../tag_files/tag_resource_runtime.h"

namespace libmcc::halo3 {
    struct structure_instanced_geometry_instance {
        real scale;
        real_vector3d forward;
        real_vector3d left;
        real_vector3d up;
        real_point3d position;
        uint16_t instance_definition;
        uint16_t flags;
        uint16_t lightmap_texcoord_block_index;
        byte BJOLSRJV[2];
        uint16_t runtime_subcluster_render_first_bitvector_index;
        uint16_t runtime_magic_render_number;
        real_point3d world_bounding_sphere_center;
        real world_bounding_sphere_radius;
        int checksum;
        string_id name;
        uint16_t pathfinding_policy;
        uint16_t lightmapping_policy;
        real lightmap_resolution_scale;
        s_tag_block bsp_physics;
        uint16_t fade_pixels_start;
        uint16_t fade_pixels_end;
        uint16_t cubemap0_bitmap_index;
        uint16_t cubemap1_bitmap_index;
        real cubemap_blend_factor;
    };

    static_assert(sizeof(structure_instanced_geometry_instance) == 120);

    struct s_collision_surface {
        uint16_t plane;
        uint16_t first_edge;
        uint16_t material;
        uint16_t breakable_surface_set;
        uint16_t breakable_surface;
        uint8_t flags;
        char best_plane_calculation_vertex_index;
    };

    struct s_collision_edge {
        uint16_t vertex_indices[2];
        uint16_t edge_indices[2];
        uint16_t surface_indices[2];
    };

    struct s_collision_vertex {
        real_point3d point;
        uint16_t first_edge;
        uint16_t sink;
    };

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

    struct s_instanced_geometries_definitions {
        uint32_t checksum;
        real_point3d bounding_sphere_center;
        real bounding_sphere_radius;
        s_tag_block bsp3d_nodes;
        s_tag_block planes;
        s_tag_block leaves;
        s_tag_block bsp2d_references;
        s_tag_block bsp2d_nodes;
        c_typed_tag_block<s_collision_surface> surfaces_0;
        c_typed_tag_block<s_collision_edge> edges;
        c_typed_tag_block<s_collision_vertex> vertices;
        s_tag_block render_bsp;
        s_tag_block mopp_codes;
        s_tag_block breakable_surface_sets;
        s_tag_block surfaces_1;
        s_tag_block large_surfaces;
        s_tag_block surface_to_triangle_mapping;
        uint16_t mesh_index;
        uint16_t compression_index;
        real global_lightmap_resolution_scale;
    };

    static_assert(sizeof(s_instanced_geometries_definitions) == 196);

    struct s_structure_bsp_resources {
        c_typed_tag_block<s_collision_bsp> collision_bsp;
        s_tag_block large_collision_bsp;
        c_typed_tag_block<s_instanced_geometries_definitions> instanced_geometries_definitions;
        s_tag_block pathfinding_data;
    };

    struct c_structure_bsp_resource_interface {
        c_typed_tag_block<s_structure_bsp_resources> raw_resources;
        s_tag_resource tag_resources;
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
