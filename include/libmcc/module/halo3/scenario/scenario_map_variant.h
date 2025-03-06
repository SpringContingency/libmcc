#pragma once

#include "./scenario_definitions.h"
#include "../../../scenario/scenario_map_id.h"
#include "../objects/objects.h"

namespace libmcc::halo3 {
    enum e_saved_game_file_type : uint32_t {
        _saved_game_file_type_personal = 0x0,
        _saved_game_file_type_ctf = 0x1,
        _saved_game_file_type_slayer = 0x2,
        _saved_game_file_type_oddball = 0x3,
        _saved_game_file_type_king = 0x4,
        _saved_game_file_type_juggernaut = 0x5,
        _saved_game_file_type_territories = 0x6,
        _saved_game_file_type_assault = 0x7,
        _saved_game_file_type_infection = 0x8,
        _saved_game_file_type_vip = 0x9,
        _saved_game_file_type_usermap = 0xA,
        _saved_game_file_type_film = 0xB,
        _saved_game_file_type_clip = 0xC,
        _saved_game_file_type_screenshot = 0xD,
        k_saved_game_file_type_count = 0xE,
        _saved_game_file_type_none = 0xFFFFFFFF,
      };

    struct s_saved_game_item_metadata {
        uint64_t unique_id;
        wchar_t name[16];
        char description[128];
        char author[16];
        e_saved_game_file_type file_type;
        bool author_is_xuid_online;
        char : 8;
        char : 8;
        char : 8;
        uint64_t author_id;
        uint64_t size_in_bytes;
        uint64_t date;
        int length_seconds;
        int campaign_id;
        int map_id;
        int game_engine_type;
        int campaign_difficulty;
        byte campaign_insertion_point;
        bool campaign_survival_enabled;
        char : 8;
        char : 8;
        uint64_t game_id;
    };

    static_assert(sizeof(s_saved_game_item_metadata) == 248);

    struct c_object_identifier {
        int m_unique_id;
        uint16_t m_origin_bsp_index;
        char m_type;
        char m_source;
    };

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

        if (palette <= 0 || palette > k_map_variant_palette_count) {
            return 0;
        } else {
            return map_variant_palette_offset[palette - 1];
        }
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
        s_scenario_map_id map_id;
    };

    static_assert(sizeof(s_map_variant) == 0xE0A0);

    typedef s_map_variant c_map_variant;
}
