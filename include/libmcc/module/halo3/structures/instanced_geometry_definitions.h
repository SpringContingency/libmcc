#pragma once

#include "../../../common.h"
#include "../tag_files/tag_files.h"

namespace libmcc::halo3 {
    struct s_collision_surface {
        uint16_t plane;
        uint16_t first_edge;
        uint16_t material;
        uint16_t breakable_surface_set;
        uint16_t breakable_surface;
        uint8_t flags;
        char best_plane_calculation_vertex_index;
    };

    union s_collision_edge {
        struct {
            uint16_t start_vertex;
            uint16_t end_vertex;
            uint16_t forward_edge;
            uint16_t reverse_edge;
            uint16_t left_surface;
            uint16_t right_surface;
        };

        struct {
            uint16_t vertex_indices[2];
            uint16_t edge_indices[2];
            uint16_t surface_indices[2];
        };
    };

    struct s_collision_vertex {
        real_point3d point;
        uint16_t first_edge;
        uint16_t sink;
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

}