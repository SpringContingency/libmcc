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

    struct s_variant_quota {
        int object_definition_index;
        byte minimum_count;
        byte maximum_count;
        byte placed_on_map;
        byte maximum_allowed;
        real price_per_item;
    };

    static_assert(sizeof(s_variant_quota) == 0xC);

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
        s_variant_object_datum m_variant_objects[640];
        uint16_t m_object_type_start_index[k_object_types_count];
        s_variant_quota m_quotas[256];
        int simulation_entities[80];
        s_scenario_map_id map_id;
    };

    static_assert(sizeof(s_map_variant) == 0xE0A0);

    typedef s_map_variant c_map_variant;
}
