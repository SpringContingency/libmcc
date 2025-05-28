#pragma once

#include "security_functions.h"
#include "../native.h"
#include "../cseries/cseries.h"
#include "../tag_files/tag_files.h"
#include "../memory/wrapped_arrays.h"

namespace libmcc::halo3 {
    enum e_cache_file_status : int {
        _cache_file_loaded = 2,
    };

    enum e_cache_file_shared_file_type
    {
        _shared_file_sounds,
        _shared_file_mainmenu,
        _shared_file_multiplayer,
        _shared_file_campaign,
        k_number_of_shared_file_types,
    };

    struct s_tag_persistent_identifier {
        int data[4];
    };

    struct s_cache_file_global_tag_index {
        e_tag_group type;
        int index;
    };

    struct s_cache_file_tag_group {
        e_tag_group type;
        e_tag_group parent_type;
        e_tag_group grandparent_type;
        string_id description;
    };

    struct cache_file_tag_instance {
        uint16_t tag_group_index;
        uint16_t datum_index_salt;
        uint32_t address;
    };

    struct s_cache_file_tag_interop {

    };

    struct s_cache_file_tag_interop_type_fixup {
        s_cache_file_tag_interop* interop_address;
        int cache_file_interop_type;
        int : 32;
    };

    struct s_cache_file_tags_header {
        c_wrapped_array_no_init<s_cache_file_tag_group> tag_groups;
        c_wrapped_array_no_init<cache_file_tag_instance> tag_instances;
        c_wrapped_array_no_init<s_cache_file_global_tag_index> global_tag_index;
        c_wrapped_array_no_init<s_cache_file_tag_interop_type_fixup> tag_interop_type_fixups;
    };

    struct s_cache_file_tags_name {
        uint32_t offset[0x8000];
        char buffer[0x800000];
        const char* name[0x8000];
    };

    static_assert(sizeof(s_cache_file_tags_name) == 0x860000);

    struct s_cache_file_tag_instance_t {
        int checksum;
        int total_size;
        __int16 dependency_count;
        __int16 data_fixup_count;
        __int16 resource_fixup_count;
        __int16 : 16;
        int offset;
        tag group_tags[3];
        string_id group_name;
        int dependencies[];
    };

    union cache_file_tag_instance_t {
        byte *base;
        s_cache_file_tag_instance_t*instance;
    };

    enum e_scenario_type : __int16 {
         _scenario_type_solo = 0x0,
         _scenario_type_multiplayer = 0x1,
         _scenario_type_main_menu = 0x2,
         _scenario_type_multiplayer_shared = 0x3,
         _scenario_type_single_player_shared = 0x4,
         k_scenario_type_count = 0x5,
     };

    enum e_cache_file_partition_type : __int32 {
        _cache_file_partition_type_resources = 0x0,
        _cache_file_partition_type_sound_resources = 0x1,
        _cache_file_partition_type_global_tags = 0x2,
        _cache_file_partition_type_shared_tags = 0x3,
        _cache_file_partition_type_base = 0x4,
        _cache_file_partition_type_map_tags = 0x5,
        k_number_of_cache_file_partition_types = 0x6,
    };

    enum e_cache_file_section : __int32 {
        _cache_file_section_debug = 0x0,
        _cache_file_section_resource = 0x1,
        _cache_file_section_tag = 0x2,
        _cache_file_section_localization = 0x3,
        k_number_of_cache_file_sections = 0x4,
    };

    struct s_cache_file_section_file_bounds {
        int offset;
        int size;
    };

    struct s_cache_file_insertion_point_resource_usage {
        char initial_zone_set_index;
        char : 8;
        char : 8;
        char : 8;
        int shared_required_locations[35];
        int local_required_locations[10];
    };

    static_assert(sizeof(s_cache_file_insertion_point_resource_usage) == 184);

    struct s_cache_file_local_resource_location {
        int flags: 2;
        int file_size: 30;
        int memory_size;

        s_network_http_request_hash entire_checksum;
    };

    static_assert(sizeof(s_cache_file_local_resource_location) == 28);

    struct s_cache_file_shared_resource_usage {
        s_tag_persistent_identifier shared_layout_identifier;
        short shared_location_count;
        short local_location_count;
        int first_file_offset;

        s_tag_persistent_identifier codec_identifier;
        s_cache_file_local_resource_location local_locations[320];

        byte insertion_point_usage_count; // 9000
        char : 8;
        char : 8;
        char : 8;
        s_cache_file_insertion_point_resource_usage insertion_point_usages[12];
    };

    static_assert(sizeof(s_cache_file_shared_resource_usage) == 11212);

    enum e_cache_file_content_hash {
        _cache_file_content_hash_header,
        _cache_file_content_hash_tags_language_dependent,
        _cache_file_content_hash_tags_language_neutral,
        k_cache_file_content_hash_count
    };

#pragma pack(push, 1)

    struct s_cache_file_header {
        union {
            struct {
                int header_signature;
                uint32_t version;
                int file_size;
                char halo_engine;
                char : 8;
                char : 8;
                char : 8;

                int tag_buffer_offset;
                int tag_buffer_size; // [0, 2GB]

                e_scenario_type scenario_type; // [0, 6)
                short shared_cache_file_type;
                short flags;
                short shared_map_usage;

                int debug_tag_name_count; // 32
                int debug_tag_name_data_offset;
                int debug_tag_name_data_size;
                int debug_tag_name_index_offset;

                int string_id_count;
                int string_id_data_offset;
                int string_id_data_count;
                int string_id_index_offset;

                int string_namespace_table_count;
                int string_namespace_table_offset;

                int language;
                int minor_version_number;
                s_file_last_modification_date creation_date;
                s_file_last_modification_date shared_creation_date[k_number_of_shared_file_types];
                int : 32;
                int : 32;
                int : 32;
                int : 32;
                int : 32;
                int : 32;
                int : 32;
                int : 32;
                int : 32;
                int : 32;
                char build_number[0x20]; // 160
                char internal_name[0x20];
                char tag_path[0x100];
                char map_path[0x100];
                cache_file_tag_instance_t* expected_base_address; // 736
                s_cache_file_tags_header* tags_header;
                int : 32;
                int : 32;
                int : 32;
                int : 32;
                c_basic_buffer tag_post_link_buffer; // 768
                c_basic_buffer tag_language_dependent_read_only_buffer;
                c_basic_buffer tag_language_dependent_read_write_buffer;
                c_basic_buffer tag_language_neutral_read_write_buffer;
                c_basic_buffer tag_language_neutral_write_combined_buffer;
                c_basic_buffer tag_language_neutral_read_only_buffer;
                int : 32;
                int content_hash_mask; // 868
                uint64_t signature_marker; // 0x17800EA664197BFCLL
                s_network_http_request_hash content_hashes[k_cache_file_content_hash_count]; // 880
                s_cache_file_header_hash hash;
                s_rsa_signature rsa_signature; // 972
                int section_offsets[k_number_of_cache_file_sections]; // 1228
                s_cache_file_section_file_bounds original_section_bounds[k_number_of_cache_file_sections];
                s_cache_file_shared_resource_usage shared_resource_usage; // 1276
            };
            char __data[0x3FFC];
        };
        int footer_signature; // 16380
    };

#pragma pack(pop)

    static_assert(sizeof(s_cache_file_header) == 0x4000);

    struct s_cache_file_globals {
        bool tags_loaded;
        cache_file_tag_instance_t* tag_instances;
        uint64_t : 64;
        s_cache_file_header header;
    };

    struct s_cached_map_file {
        s_file_handle file_handle;
        s_cache_file_header header;
        s_indirect_file indirect_file;
        s_file_handle overlapped_handle;
    };

	static_assert(sizeof(s_cached_map_file) == 0x4018);

    struct s_cache_file_table_of_contents {
        s_cached_map_file map_files[27];
    };

	inline s_cache_file_tags_name** g_cache_file_tags_name() {
		return REF<s_cache_file_tags_name*>(s_data_offset_table::g_cache_file_tags_name);
	}

    inline s_cache_file_globals* g_cache_file_globals() {
        return REF<s_cache_file_globals>(s_data_offset_table::g_cache_file_globals);
    }
}

// CACHE_FILE_RESOURCE_LAYOUT_TAG
namespace libmcc::halo3 {
    enum e_codec : uint8_t {
		_codec_deflate,

    };

	struct s_cache_file_resource_file_location {
		uint16_t runtime_salt;
		uint8_t flags;
        e_codec codec_index;
		uint16_t shared_file_index;
		uint16_t shared_file_location_index;
		uint32_t block_offset;
		uint32_t compressed_block_size;
		uint32_t uncompressed_block_size;
		uint32_t crc_checksum;
		char entire_hash[0x14];
		char first_chunk_hash[0x14];
		char last_chunk_hash[0x14];
		uint16_t resource_reference_count;
		uint16_t streaming_sublocation_table_index;
	};

	static_assert(sizeof(s_cache_file_resource_file_location) == 0x58);

    struct s_cache_file_resource_default_location {
		uint16_t required_location_index;
		uint16_t optional_location_index;
		uint32_t required_location_offset;
		uint32_t optional_location_offset;
		uint16_t pageable_sublocation_table_index;
		uint16_t optional_sublocation_table_index;
    };

	static_assert(sizeof(s_cache_file_resource_default_location) == 0x10);

    TAG_GROUP(CACHE_FILE_RESOURCE_LAYOUT_TAG)
    struct s_cache_file_resource_layout_table {
        s_tag_block codec_identifiers;
        s_tag_block shared_files;
        c_typed_tag_block<s_cache_file_resource_file_location> file_locations;
        s_tag_block streaming_sublocation_tables;
        s_tag_block file_locations_patch_lookup;
        c_typed_tag_block<s_cache_file_resource_default_location> default_locations;
        int32_t required_location_count;
        int32_t required_dvd_location_count;
    };
}

// CACHE_FILE_RESOURCE_GESTALT_TAG
namespace libmcc::halo3 {
    union c_tag_resource_fixup {
        uint32_t n;
        struct {
            uint32_t offset : 24;
            uint32_t : 5;
            uint32_t fixup : 1;
            uint32_t raw_page : 1;
            uint32_t : 1;
        };
    };

    static_assert(sizeof(c_tag_resource_fixup) == 4);

    enum e_scenario_resource : uint8_t {
        _scenario_resource_block_owned_by_scenario,
        _scenario_resource_block_global_to_scenario,

        NUMBER_OF_SCENARIO_RESOURCE_TYPES = 18
    };

    struct s_tag_resource_fixup_location {
        int encoded_fixup_location;
        c_tag_resource_fixup encoded_fixup_value;
    };

    struct s_cache_file_resource_runtime_data_new {
        s_tag_reference owner_tag;
        uint16_t resource_salt;
        e_scenario_resource resource_type_index;
        uint8_t control_alignment_bits;
        uint32_t control_offset;
        uint32_t control_size;
        uint32_t optional_control_offset;
        uint16_t flags;
        uint16_t location_index;
        c_tag_resource_fixup root_address_fixup;
        c_typed_tag_block<s_tag_resource_fixup_location> control_fixups;
        s_tag_block interop_locations;
    };

    static_assert(sizeof(s_cache_file_resource_runtime_data_new) == 64);

    struct s_tag_resource_cache_prediction_table {
        s_tag_block prediction_quanta;
        s_tag_block prediction_atoms;
        s_tag_block prediction_molecule_atoms;
        s_tag_block prediction_molecules;
        s_tag_block prediction_molecule_keys;
    };

    TAG_GROUP(CACHE_FILE_RESOURCE_GESTALT_TAG)
    struct s_cache_file_resource_gestalt {
        e_scenario_type scenario_type;
        uint16_t scenario_flags;
        s_tag_block resource_type_identifiers;
        s_tag_block interop_type_identifiers;
        s_tag_block codec_identifiers;
        s_tag_block shared_files;
        s_tag_block file_locations;
        s_tag_block streaming_sublocation_tables;
        s_tag_block file_locations_patch_lookup;
        s_tag_block default_locations;
        c_typed_tag_block<s_cache_file_resource_runtime_data_new> resources;
        s_tag_block designer_zone_manifests;
        s_tag_block global_zone_manifest;
        s_tag_block hs_zone_manifest;
        s_tag_block unattached_designer_zone_manifest;
        s_tag_block dvd_forbidden_zone_manifest;
        s_tag_block dvd_always_streaming_zone_manifest;
        s_tag_block default_zone_set_manifest;
        s_tag_block static_bsp_zone_manifests;
        s_tag_block dynamic_bsp_zone_manifests;
        s_tag_block cinematic_zone_manifests;
        s_tag_block zone_only_zone_set_manifests;
        s_tag_block expected_zone_set_manifests;
        s_tag_block fully_populated_zone_set_manifests;
        s_tag_block zone_set_zone_usage;
        s_tag_block bsp_references;

        uint32_t resource_owners_block[3];
        uint32_t model_variant_usage_block[3];
        uint32_t character_usage_block[3];

        s_tag_data fixup_data;

        uint32_t minimum_complete_resource_size;
        uint32_t minimum_required_resource_size;
        uint32_t minimum_dvd_resource_size;
        uint32_t global_required_resource_size;
        uint32_t total_optional_control_data_size;

        s_tag_block overall_resource_usage;

        uint32_t bsp_game_attachments_block[3];
        uint32_t model_variant_zones_block[3];

        s_tag_block combat_dialogue_zones;

        uint32_t tags_zones_block[3];
        uint32_t debug_resource_definitions_block[3];
        uint32_t resource_layouts_block[3];
        uint32_t resource_properties_block[3];
        uint32_t parentages_block[3];

        s_tag_resource_cache_prediction_table prediction_table;

        uint32_t : 32;
        uint32_t : 32;
        uint32_t : 32;
        uint32_t : 32;
    };
}
