#pragma once

#include "../../../common.h"
#include "../tag_files/tag_files.h"
#include "../tag_files/tag_resource_runtime.h"


namespace libmcc::halo3 {
    union structure_instanced_geometry_instance {
        struct {
            real scale;
            real_vector3d forward;
            real_vector3d left;
            real_vector3d up;
            real_point3d position;
            uint16_t instance_definition;
        };
        char data[120];
    };

    static_assert(sizeof(structure_instanced_geometry_instance) == 120);

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
        s_tag_block surfaces;
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
        s_tag_block surfaces_0;
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
                return tag_resources.get<s_structure_bsp_resources>();
            else
                return raw_resources.begin();
        }
    };

    static_assert(sizeof(c_structure_bsp_resource_interface) == 0x20);

    union s_structure_bsp {
        c_typed_tag_block<structure_instanced_geometry_instance>* instanced_geometry_instances() {
            return reinterpret_cast<c_typed_tag_block<structure_instanced_geometry_instance>*>(data + 0x1C0);
        }
        c_structure_bsp_resource_interface* resource_interface() {
            return reinterpret_cast<c_structure_bsp_resource_interface*>(data + 0x380);
        }

        char data[0x3A0];
    };

    static_assert(sizeof(s_structure_bsp) == 0x3A0);

}
