#pragma once

namespace libmcc::halo3 {
    enum e_rasterizer_vertex_format : char {
        _rasterizer_vertex_format_float1,
        _rasterizer_vertex_format_float2,
        _rasterizer_vertex_format_float3,
        _rasterizer_vertex_format_float4,
        _rasterizer_vertex_format_d3dcolor,
        _rasterizer_vertex_format_ubyte4,
        _rasterizer_vertex_format_short2,
        _rasterizer_vertex_format_short4,
        _rasterizer_vertex_format_ubyte4n,
        _rasterizer_vertex_format_short2n,
        _rasterizer_vertex_format_short4n,
        _rasterizer_vertex_format_ushort2n,
        _rasterizer_vertex_format_ushort4n,
        _rasterizer_vertex_format_udec3,
        _rasterizer_vertex_format_dec3n,
        _rasterizer_vertex_format_float16_2,
        _rasterizer_vertex_format_float16_4,
        _rasterizer_vertex_format_unused,
		k_rasterizer_vertex_format_count,
    };

    constexpr size_t g_rasterizer_vertex_format_size[k_rasterizer_vertex_format_count] {
		4, 8, 12, 16, 
        4, 4, 4, 4, 
        8, 4, 8, 4, 8,
        4, 4, 4, 8,
        4
    };

    enum e_rasterizer_vertex_attribute : char {
        _rasterizer_vertex_attribute_none = -1,
        NUMBER_OF_RASTERIZER_VERTEX_ATTRIBUTE = 13,
    };

    struct s_rasterizer_vertex_register_mapping {
        char attribute;
        e_rasterizer_vertex_format format;
        const char* name;
        __int64 un;
    };

    static_assert(sizeof(s_rasterizer_vertex_register_mapping) == 24);

    struct s_rasterizer_vertex_declaration {
        __int64 index;
        s_rasterizer_vertex_register_mapping mappings[NUMBER_OF_RASTERIZER_VERTEX_ATTRIBUTE];
    };

    static_assert(sizeof(s_rasterizer_vertex_declaration) == 320);

	enum e_vertex_buffer_declaration : short {
		_vertex_buffer_declaration_none,
		k_number_of_vertex_buffer_declarations = 30,
	};

    constexpr s_rasterizer_vertex_declaration g_rasterizer_vertex_declaration[k_number_of_vertex_buffer_declarations] = {
        // Declaration 0
        {
            .index = 0,
            .mappings = {
                {.attribute = -1}
            }
        },
        // Declaration 1
        {
            .index = 1,
            .mappings = {
                {.attribute = 0, .format = _rasterizer_vertex_format_float3, .name = "POSITION", .un = 0},
                {.attribute = 3, .format = _rasterizer_vertex_format_float2, .name = "TEXCOORD", .un = 0},
                {.attribute = 4, .format = _rasterizer_vertex_format_short4n, .name = "NORMAL", .un = 0},
                {.attribute = 6, .format = _rasterizer_vertex_format_short4n, .name = "TANGENT", .un = 0},
                {.attribute = 5, .format = _rasterizer_vertex_format_short4n, .name = "BINORMAL", .un = 0},
                {.attribute = -1}
            }
        },
        // Declaration 2
        {
            .index = 2,
            .mappings = {
                {.attribute = 0, .format = _rasterizer_vertex_format_ushort4n, .name = "POSITION", .un = 0},
                {.attribute = 3, .format = _rasterizer_vertex_format_ushort2n, .name = "TEXCOORD", .un = 0},
                {.attribute = 4, .format = _rasterizer_vertex_format_short4n, .name = "NORMAL", .un = 0},
                {.attribute = 6, .format = _rasterizer_vertex_format_short4n, .name = "TANGENT", .un = 0},
                {.attribute = 5, .format = _rasterizer_vertex_format_short4n, .name = "BINORMAL", .un = 0},
                {.attribute = -1}
            }
        },
        // Declaration 3
        {
            .index = 3,
            .mappings = {
                {.attribute = 0, .format = _rasterizer_vertex_format_ushort4n, .name = "POSITION", .un = 0},
                {.attribute = 3, .format = _rasterizer_vertex_format_ushort2n, .name = "TEXCOORD", .un = 0},
                {.attribute = 4, .format = _rasterizer_vertex_format_short4n, .name = "NORMAL", .un = 0},
                {.attribute = 6, .format = _rasterizer_vertex_format_short4n, .name = "TANGENT", .un = 0},
                {.attribute = 5, .format = _rasterizer_vertex_format_short4n, .name = "BINORMAL", .un = 0},
                {.attribute = 1, .format = _rasterizer_vertex_format_ubyte4, .name = "BLENDINDICES", .un = 0},
                {.attribute = 2, .format = _rasterizer_vertex_format_ubyte4n, .name = "BLENDWEIGHT", .un = 0},
                {.attribute = -1}
            }
        },
        // Declaration 4
        {
            .index = 4,
            .mappings = {
                {.attribute = 7, .format = _rasterizer_vertex_format_ushort2n, .name = "TEXCOORD", .un = 1},
                {.attribute = -1}
            }
        },
        // Declaration 5
        {
            .index = 5,
            .mappings = {
                {.attribute = 8, .format = _rasterizer_vertex_format_short2n, .name = "COLOR", .un = 0},
                {.attribute = -1}
            }
        },
        // Declaration 6
        {
            .index = 6,
            .mappings = {
                {.attribute = 13, .format = _rasterizer_vertex_format_short2n, .name = "TEXCOORD", .un = 3},
                {.attribute = 13, .format = _rasterizer_vertex_format_short2n, .name = "TEXCOORD", .un = 4},
                {.attribute = 13, .format = _rasterizer_vertex_format_short2n, .name = "TEXCOORD", .un = 5},
                {.attribute = 13, .format = _rasterizer_vertex_format_short2n, .name = "TEXCOORD", .un = 6},
                {.attribute = 13, .format = _rasterizer_vertex_format_short2n, .name = "TEXCOORD", .un = 7},
                {.attribute = -1}
            }
        },
        // Declaration 7
        {
            .index = 7,
            .mappings = {
                {.attribute = 12, .format = _rasterizer_vertex_format_float1, .name = "FOG", .un = 0},
                {.attribute = 13, .format = _rasterizer_vertex_format_float4, .name = "TEXCOORD", .un = 2},
                {.attribute = -1}
            }
        },
        // Declaration 8
        {
            .index = 8,
            .mappings = {
                {.attribute = -1}
            }
        },
        // Declaration 9
        {
            .index = 9,
            .mappings = {
                {.attribute = 13, .format = _rasterizer_vertex_format_ubyte4n, .name = "BLENDWEIGHT", .un = 1},
                {.attribute = -1}
            }
        },
        // Declaration 10
        {
            .index = 10,
            .mappings = {
                {.attribute = 13, .format = _rasterizer_vertex_format_ubyte4n, .name = "BLENDWEIGHT", .un = 1},
                {.attribute = -1}
            }
        },
        // Declaration 11
        {
            .index = 11,
            .mappings = {
                {.attribute = 13, .format = _rasterizer_vertex_format_ushort4n, .name = "BLENDWEIGHT", .un = 1},
                {.attribute = 13, .format = _rasterizer_vertex_format_ushort4n, .name = "BLENDWEIGHT", .un = 2},
                {.attribute = 13, .format = _rasterizer_vertex_format_ushort4n, .name = "BLENDWEIGHT", .un = 3},
                {.attribute = -1}
            }
        },
        // Declaration 12
        {
            .index = 12,
            .mappings = {
                {.attribute = 0, .format = _rasterizer_vertex_format_float2, .name = "POSITION", .un = 0},
                {.attribute = 3, .format = _rasterizer_vertex_format_float2, .name = "TEXCOORD", .un = 0},
                {.attribute = 8, .format = _rasterizer_vertex_format_short2n, .name = "COLOR", .un = 0},
                {.attribute = -1}
            }
        },
        // Declaration 13
        {
            .index = 13,
            .mappings = {
                {.attribute = 0, .format = _rasterizer_vertex_format_float3, .name = "POSITION", .un = 0},
                {.attribute = 8, .format = _rasterizer_vertex_format_short2n, .name = "COLOR", .un = 0},
                {.attribute = -1}
            }
        },
        // Declaration 14
        {
            .index = 14,
            .mappings = {
                {.attribute = 9, .format = _rasterizer_vertex_format_float3, .name = "TEXCOORD", .un = 2},
                {.attribute = -1}
            }
        },
        // Declaration 15
        {
            .index = 15,
            .mappings = {
                {.attribute = 0, .format = _rasterizer_vertex_format_float3, .name = "POSITION", .un = 0},
                {.attribute = 3, .format = _rasterizer_vertex_format_float2, .name = "TEXCOORD", .un = 0},
                {.attribute = 8, .format = _rasterizer_vertex_format_short2n, .name = "COLOR", .un = 0},
                {.attribute = -1}
            }
        },
        // Declaration 16
        {
            .index = 16,
            .mappings = {
                {.attribute = 0, .format = _rasterizer_vertex_format_float4, .name = "SITION", .un = 1},
                {.attribute = 0, .format = _rasterizer_vertex_format_float16_4, .name = "OSITION", .un = 2},
                {.attribute = 0, .format = _rasterizer_vertex_format_short4n, .name = "POSITION", .un = 3},
                {.attribute = 0, .format = _rasterizer_vertex_format_short4n, .name = "POSITION", .un = 4},
                {.attribute = 3, .format = _rasterizer_vertex_format_short4n, .name = "TEXCOORD", .un = 2},
                {.attribute = 3, .format = _rasterizer_vertex_format_float16_4, .name = "TEXCOORD", .un = 3},
                {.attribute = 3, .format = _rasterizer_vertex_format_float16_2, .name = "TEXCOORD", .un = 4},
                {.attribute = 3, .format = _rasterizer_vertex_format_short2n, .name = "TEXCOORD", .un = 5},
                {.attribute = 4, .format = _rasterizer_vertex_format_unused, .name = "NORMAL", .un = 1},
                {.attribute = 8, .format = _rasterizer_vertex_format_short2, .name = "OLOR", .un = 0},
                {.attribute = 8, .format = _rasterizer_vertex_format_short2, .name = "COLOR", .un = 1},
                {.attribute = 0, .format = _rasterizer_vertex_format_float1, .name = "POSITION", .un = 0xF},
                {.attribute = -1}
            }
        },
        // Declaration 17
        {
            .index = 17,
            .mappings = {
                {.attribute = 3, .format = _rasterizer_vertex_format_short4, .name = "TEXCOORD", .un = 1},
                {.attribute = -1}
            }
        },
        // Declaration 18
        {
            .index = 18,
            .mappings = {
                {.attribute = 0, .format = _rasterizer_vertex_format_float4, .name = "POSITION", .un = 0},
                {.attribute = 0, .format = _rasterizer_vertex_format_float16_4, .name = "POSITION", .un = 1},
                {.attribute = 0, .format = _rasterizer_vertex_format_short4n, .name = "POSITION", .un = 2},
                {.attribute = 3, .format = _rasterizer_vertex_format_float16_4, .name = "TEXCOORD", .un = 0},
                {.attribute = 3, .format = _rasterizer_vertex_format_short4n, .name = "TEXCOORD", .un = 2},
                {.attribute = 3, .format = _rasterizer_vertex_format_float16_2, .name = "TEXCOORD", .un = 3},
                {.attribute = 8, .format = _rasterizer_vertex_format_short2, .name = "COLOR", .un = 0},
                {.attribute = 8, .format = _rasterizer_vertex_format_short2, .name = "COLOR", .un = 1},
                {.attribute = 0, .format = _rasterizer_vertex_format_float1, .name = "POSITION", .un = 0xF},
                {.attribute = -1}
            }
        },
        // Declaration 19
        {
            .index = 19,
            .mappings = {
                {.attribute = 0, .format = _rasterizer_vertex_format_float4, .name = "POSITION", .un = 0},
                {.attribute = 3, .format = _rasterizer_vertex_format_float16_2, .name = "TEXCOORD", .un = 0},
                {.attribute = 8, .format = _rasterizer_vertex_format_short2, .name = "COLOR", .un = 0},
                {.attribute = 0, .format = _rasterizer_vertex_format_float2, .name = "POSITION", .un = 0xF},
                {.attribute = -1}
            }
        },
        // Declaration 20
        {
            .index = 20,
            .mappings = {
                {.attribute = 0, .format = _rasterizer_vertex_format_ubyte4, .name = "POSITION", .un = 1},
                {.attribute = 0, .format = _rasterizer_vertex_format_ubyte4, .name = "NORMAL", .un = 1},
                {.attribute = 8, .format = _rasterizer_vertex_format_short2n, .name = "COLOR", .un = 1},
                {.attribute = -1}
            }
        },
        // Declaration 21
        {
            .index = 21,
            .mappings = {
                {.attribute = 0, .format = _rasterizer_vertex_format_short4, .name = "POSITION", .un = 2},
                {.attribute = -1}
            }
        },
        // Declaration 22
        {
            .index = 22,
            .mappings = {
                {.attribute = 0, .format = _rasterizer_vertex_format_short4, .name = "POSITION", .un = 2},
                {.attribute = -1}
            }
        },
        // Declaration 23
        {
            .index = 23,
            .mappings = {
                {.attribute = 0, .format = _rasterizer_vertex_format_short4, .name = "POSITION", .un = 2},
                {.attribute = -1}
            }
        },
        // Declaration 24
        {
            .index = 24,
            .mappings = {
                {.attribute = 0, .format = _rasterizer_vertex_format_ushort4n, .name = "POSITION", .un = 0},
                {.attribute = 3, .format = _rasterizer_vertex_format_ushort2n, .name = "TEXCOORD", .un = 0},
                {.attribute = 4, .format = _rasterizer_vertex_format_short4n, .name = "NORMAL", .un = 0},
                {.attribute = -1}
            }
        },
        // Declaration 25
        {
            .index = 25,
            .mappings = {
                {.attribute = 0, .format = _rasterizer_vertex_format_float3, .name = "POSITION", .un = 0},
                {.attribute = 3, .format = _rasterizer_vertex_format_float2, .name = "TEXCOORD", .un = 0},
                {.attribute = 4, .format = _rasterizer_vertex_format_float3, .name = "NORMAL", .un = 0},
                {.attribute = -1}
            }
        },
        // Declaration 26
        {
            .index = 26,
            .mappings = {
                {.attribute = 0, .format = _rasterizer_vertex_format_short4, .name = "POSITION", .un = 0},
                {.attribute = 0, .format = _rasterizer_vertex_format_short4, .name = "POSITION", .un = 0},
                {.attribute = 0, .format = _rasterizer_vertex_format_short4, .name = "POSITION", .un = 0},
                {.attribute = -1}
            }
        },
        // Declaration 27
        {
            .index = 27,
            .mappings = {
                {.attribute = 0, .format = _rasterizer_vertex_format_float3, .name = "POSITION", .un = 0},
                {.attribute = 0, .format = _rasterizer_vertex_format_float3, .name = "POSITION", .un = 0},
                {.attribute = 0, .format = _rasterizer_vertex_format_float3, .name = "POSITION", .un = 0},
                {.attribute = -1}
            }
        },
        // Declaration 28
        {
            .index = 28,
            .mappings = {
                {.attribute = 0, .format = _rasterizer_vertex_format_float4, .name = "POSITION", .un = 0},
                {.attribute = 0, .format = _rasterizer_vertex_format_float4, .name = "POSITION", .un = 0},
                {.attribute = 0, .format = _rasterizer_vertex_format_float4, .name = "POSITION", .un = 0},
                {.attribute = 0, .format = _rasterizer_vertex_format_float4, .name = "POSITION", .un = 0},
                {.attribute = 0, .format = _rasterizer_vertex_format_float4, .name = "POSITION", .un = 0},
                {.attribute = 0, .format = _rasterizer_vertex_format_float4, .name = "POSITION", .un = 0},
                {.attribute = 0, .format = _rasterizer_vertex_format_float4, .name = "POSITION", .un = 0},
                {.attribute = 0, .format = _rasterizer_vertex_format_float4, .name = "POSITION", .un = 0},
                {.attribute = -1}
            }
        },
        // Declaration 29
        {
            .index = 29,
            .mappings = {
                {.attribute = 0, .format = _rasterizer_vertex_format_float4, .name = "OSITION", .un = 0},
                {.attribute = 3, .format = _rasterizer_vertex_format_short4n, .name = "EXCOORD", .un = 0},
                {.attribute = 3, .format = _rasterizer_vertex_format_float16_4, .name = "TEXCOORD", .un = 2},
                {.attribute = 8, .format = _rasterizer_vertex_format_short2, .name = "OLOR", .un = 0},
                {.attribute = 8, .format = _rasterizer_vertex_format_float3, .name = "OSITION", .un = 0xF},
                {.attribute = -1}
            }
        }
    };
}

namespace libmcc::halo3 {
	enum e_vertex_type : char {
		_vertex_type_world,
		_vertex_type_rigid,
		_vertex_type_skinned,
		_vertex_type_particle_model,
		_vertex_type_flat_world,
		_vertex_type_flat_rigid,
		_vertex_type_flat_skinned,
		_vertex_type_screen,
		_vertex_type_debug,
		_vertex_type_transparent,
		_vertex_type_particle,
		_vertex_type_contrail,
		_vertex_type_light_volume,
		_vertex_type_chud_simple,
		_vertex_type_chud_fancy,
		_vertex_type_decorator,
		_vertex_type_position_only,
		_vertex_type_patchy_fog,
		_vertex_type_water,
		_vertex_type_ripple,
		_vertex_type_implicit_geometry,
		_vertex_type_beam,
		k_vertex_type_count,
	};

    constexpr e_vertex_buffer_declaration g_vertex_declaration_mapping[k_vertex_type_count] = {
        static_cast<e_vertex_buffer_declaration>(1),    // _vertex_type_world
        static_cast<e_vertex_buffer_declaration>(2),    // _vertex_type_rigid
        static_cast<e_vertex_buffer_declaration>(3),    // _vertex_type_skinned
        static_cast<e_vertex_buffer_declaration>(25),   // _vertex_type_particle_model
        static_cast<e_vertex_buffer_declaration>(1),    // _vertex_type_flat_world
        static_cast<e_vertex_buffer_declaration>(2),    // _vertex_type_flat_rigid
        static_cast<e_vertex_buffer_declaration>(3),    // _vertex_type_flat_skinned
        static_cast<e_vertex_buffer_declaration>(12),   // _vertex_type_screen
        static_cast<e_vertex_buffer_declaration>(13),    // _vertex_type_debug
        _vertex_buffer_declaration_none,                // _vertex_type_transparent
        _vertex_buffer_declaration_none,                // _vertex_type_particle
        _vertex_buffer_declaration_none,                // _vertex_type_contrail
        _vertex_buffer_declaration_none,                // _vertex_type_light_volume
        _vertex_buffer_declaration_none,                // _vertex_type_chud_simple
        _vertex_buffer_declaration_none,                // _vertex_type_chud_fancy
        static_cast<e_vertex_buffer_declaration>(24),   // _vertex_type_decorator
        static_cast<e_vertex_buffer_declaration>(21),   // _vertex_type_position_only
        _vertex_buffer_declaration_none,                // _vertex_type_patchy_fog
        static_cast<e_vertex_buffer_declaration>(28),   // _vertex_type_water
        _vertex_buffer_declaration_none,                // _vertex_type_ripple
        _vertex_buffer_declaration_none,                // _vertex_type_implicit_geometry
        _vertex_buffer_declaration_none,                // _vertex_type_beam
    };

    struct s_world_vertex {
        float position[3]; 
        float texcoord[2]; 
        short normal[4]; 
        short tangent[4];
        short binormal[4];
    };

    static_assert(sizeof(s_world_vertex) == 44);

    struct s_rigid_vertex {
        unsigned short position[4]; 
        unsigned short texcoord[2]; 
        short normal[4]; 
        short tangent[4];
        short binormal[4];
    };

    static_assert(sizeof(s_rigid_vertex) == 36);

    struct s_skinned_vertex {
        unsigned short position[4];
        unsigned short texcoord[2];
        short normal[4];
        short tangent[4];
        short binormal[4];
        unsigned char blend_indices[4];
        unsigned char blend_weight[4];
    };

    static_assert(sizeof(s_skinned_vertex) == 44);
}