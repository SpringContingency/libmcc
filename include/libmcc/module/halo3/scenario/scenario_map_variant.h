#pragma once

#include "../objects/objects.h"
#include "./scenario_definitions.h"
#include "../saved_games/saved_game_files.h"
#include "../../../scenario/scenario_map_id.h"
#include "../../../scenario/scenario_map_variant.h"

namespace libmcc::halo3 {
    struct s_variant_multiplayer_object_properties_definition {
        uint16_t game_engine_flags;
        byte object_flags;
        char team_affiliation;
        char shared_storage;
        char spawn_time;
        char teleporter_channel;
        char object_shape;
        real shape_radius_width;
        real shape_length;
        real shape_positive_height;
        real shape_negative_height;
    };

    enum e_map_variant {
        _map_variant_unique_spawn,
        _map_variant_not_initially_placed,
        _map_variant_symmetric_placement,
        _map_variant_asymmetric_placement,
        _map_variant_unused4,
        _map_variant_unused5,
        _map_variant_physics_fixed,
        _map_variant_physics_phased,

        //_map_variant_spawns_attached = 1,
        //_map_variant_occupied_slot = 1,
        //_map_variant_scenario_object_bit = 8,
        //_map_variant_scenario_object_removed = 32,
    };

    struct s_variant_object_datum {
        uint16_t flags;
        uint16_t __unknown2;
        int object_datum_index;
        int editor_object_index;
        int variant_quota_index;
        real_point3d position;
        real_vector3d forward;
        real_vector3d up;
        c_object_identifier parent_object_identifier;
        s_variant_multiplayer_object_properties_definition multiplayer_game_object_properties;
    };

    enum e_map_variant_palette : uint16_t {
        _map_variant_palette_vehicle = 1,
        _map_variant_palette_weapon,
        _map_variant_palette_equipment,
        _map_variant_palette_scenery,
        _map_variant_palette_teleporters,
        _map_variant_palette_goals,
        _map_variant_palette_spawners,

        _map_variant_palette_scenario_scenery,
        _map_variant_palette_scenario_vehicle,
        _map_variant_palette_scenario_weapon,
        _map_variant_palette_scenario_equipment,
        _map_variant_palette_scenario_crates,

        k_map_variant_palette_count = 12,
        k_map_variant_palette_none = 0,
    };

    constexpr uint64_t scenario_object_offset(e_map_variant_palette palette) {
        constexpr uint64_t scenario_object_offset[]{
            offsetof(scenario_definition, scenery),
            offsetof(scenario_definition, vehicles),
            offsetof(scenario_definition, weapons),
            offsetof(scenario_definition, equipment),
            offsetof(scenario_definition, crates)
        };

        if (palette < _map_variant_palette_scenario_scenery || palette > _map_variant_palette_scenario_crates)
            return 0;

        return scenario_object_offset[palette - _map_variant_palette_scenario_scenery];
    }

    constexpr uint64_t scenario_object_size(e_map_variant_palette palette) {
        constexpr uint64_t scenario_object_size[]{
            sizeof(s_scenario_scenery),
            sizeof(s_scenario_vehicle),
            sizeof(s_scenario_weapon),
            sizeof(s_scenario_equipment),
            sizeof(s_scenario_crate)
        };

        if (palette < _map_variant_palette_scenario_scenery || palette > _map_variant_palette_scenario_crates)
            return 0;

        return scenario_object_size[palette - _map_variant_palette_scenario_scenery];
    }

    constexpr uint64_t map_variant_palette_offset(e_map_variant_palette palette) {
        constexpr uint64_t map_variant_palette_offset[]{
            offsetof(scenario_definition, map_variant_vehicle_palette),
            offsetof(scenario_definition, map_variant_weapon_palette),
            offsetof(scenario_definition, map_variant_equipment_palette),
            offsetof(scenario_definition, map_variant_scenery_palette),
            offsetof(scenario_definition, map_variant_teleporters_palette),
            offsetof(scenario_definition, map_variant_goals_palette),
            offsetof(scenario_definition, map_variant_spawners_palette),
            offsetof(scenario_definition, scenery_palette),
            offsetof(scenario_definition, vehicle_palette),
            offsetof(scenario_definition, weapon_palette),
            offsetof(scenario_definition, equipment_palette),
            offsetof(scenario_definition, crate_palette),
        };

        if (palette <= 0 || palette > k_map_variant_palette_count)
            return 0;
        
        return map_variant_palette_offset[palette - 1];
    }

    constexpr uint64_t map_variant_palette_size(e_map_variant_palette palette) {
        if (palette <= 0 || palette > k_map_variant_palette_count) {
            return 0;
        } else if (palette <= _map_variant_palette_spawners) {
            return sizeof(s_map_variant_palette);
        } else {
            return sizeof(s_scenario_palette);
        }
    }

    union s_variant_quota_index {
        struct {
            uint16_t index;
            e_map_variant_palette type;
        };
		uint32_t value;
    };

    struct s_variant_quota {
        s_variant_quota_index object_definition_index;
        byte minimum_count;
        byte maximum_count;
        byte placed_on_map;
        byte maximum_allowed;
        real price_per_item;
    };

    static_assert(sizeof(s_variant_quota) == 0xC);

    enum {
		k_variant_object_maximum_count = 640,
		k_variant_quota_maximum_count = 256,
		k_simulation_entity_maximum_count = 80,
    };

    struct s_map_variant {
        s_saved_game_item_metadata metadata;
        uint16_t m_map_variant_version;
        uint16_t m_number_of_scenario_objects;
        uint16_t m_number_of_variant_objects;
        uint16_t m_number_of_placeable_object_quotas;
        int m_map_id;
        real_rectangle3d m_world_bounds;
        int m_game_engine_subtype;
        real m_maximum_budget;
        real m_spent_budget;
        bool m_helpers_enabled;
        bool m_built_in;
        char : 8;
        char : 8;
        uint32_t m_map_variant_checksum;
        s_variant_object_datum m_variant_objects[k_variant_object_maximum_count];
        uint16_t m_object_type_start_index[k_object_types_count];
        s_variant_quota m_quotas[k_variant_quota_maximum_count];
        int simulation_entities[k_simulation_entity_maximum_count];
        int : 32;
        s_scenario_map_id map_id;
    };

    static_assert(sizeof(s_map_variant) == 0xE0A0);

    typedef s_map_variant c_map_variant;
}

namespace libmcc::halo3 {
    class c_scenario_map_variant : public i_scenario_map_variant {
    public:
		s_map_variant m_map_variant;
        int blffile_map_variant_size;
        char blffile_map_variant_data[0xE13D];
    };
}

// mvar
namespace libmcc::halo3 {
    struct content_header {
        uint64_t id;
        wchar_t name[16];
        char description[128];
        char author[16];
        e_game_engine_type game_type_menu_order;
        int is_user_valid;
        char author_xuid[8];
        uint64_t size;
        uint64_t timestamp;
        int : 32;
        int campaign_id;
        int map_id;
        e_game_engine_type game_type_menu;
        CampaignDifficultyLevel game_difficulty;
        // padding byte
        // padding byte
        int campaign_insertion_index;
        int is_survival;
        int game_id;
     };

    struct game_engine_base_variant {

    };

    struct map_variant_properties {
        uint16_t engine_flags;
        byte object_flags;
        byte team_affilation;
        byte shared_storage;
        byte respawn_time;
        byte object_type;
        byte zone_shape;
        real zone_radius_width;
        real zone_depth;
        real zone_top;
        real zone_bottom;
    };

    struct map_variant_placement {
        uint16_t placement_flags;                
        uint16_t unknown02;
        __int32 object_index;               
        __int32 editor_object_index;        
        __int32 budget_index;               
        real_vector3d position;
        real_vector3d right_vector;
        real_vector3d up_vector;
        __int32 unknown34;                  
        __int32 unknown38;
        map_variant_properties properties;  
    };

    struct map_variant_budget_entry {
        __int32 tag_index;
        byte runtime_min;
        byte runtime_max;
        byte count_on_map;
        byte design_time_max;
        real cost;
    };

#pragma pack(push, 1)
    struct s_blf_chunk_map_variant : s_blf_header {
        content_header header;
        uint16_t unknown_f8;
        uint16_t placement_count;
        uint16_t used_placements_count;
        uint16_t budget_entry_count;
        __int32 map_id;
        real_bounds world_bounds_x;
        real_bounds world_bounds_y;
        real_bounds world_bounds_z;
        __int32 content_type;
        real max_budget;
        real current_budget;
        __int32 unknown128;
        __int32 unknown12C;
        map_variant_placement placements[640];
        uint16_t scenario_indices[16];
        map_variant_budget_entry budget[256];
        char unused[320];
    };

    struct s_blffile_map_variant {
        s_blf_chunk_start_of_file start_of_file_chunk;
        s_blf_chunk_author author_chunk;
        s_blf_chunk_map_variant map_variant_chunk;
        s_blf_chunk_end_of_file end_of_file_chunk;
        s_blf_chunk_fsm fsm_chunk;
    };

#pragma pack(pop)

    class c_map_variant_interface : public libmcc::i_scenario_map_variant {

    private:
        s_map_variant m_map_variant;
    };
}

