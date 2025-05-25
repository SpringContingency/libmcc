#pragma once

#include "scenario_object_definitions.h"

namespace libmcc::halo3 {
    struct s_structure_bsp;

    union scenario_structure_bsp_reference {
        struct {
            c_typed_tag_reference<s_structure_bsp> structure_bsp;
            s_tag_reference structure_design;
            s_tag_reference structure_lighting_info;
        };

        char data[108];
    };

    struct s_scenario_palette {
        s_tag_reference object;
    };

    static_assert(sizeof(s_scenario_palette) == 0x10);

	struct s_map_variant_palette : s_scenario_palette {
		string_id display_name;
        int maximum_allowed;
        real price_per_instance;
	};

	static_assert(sizeof(s_map_variant_palette) == 0x1C);

    struct scenario_object_name {
        char name[32];
        short object_type;
        short placement_index;
    };

    union scenario_definition {
        struct {
            uint16_t type;
            uint16_t campaign_type;
            uint16_t flags;
            uint32_t campaign_id;
            uint32_t map_id;
            angle local_north;
            real sandbox_budget;
            c_typed_tag_block<scenario_structure_bsp_reference> structure_bsps;
            s_tag_reference structure_seams;
            s_tag_block sky_references;
            s_tag_block zone_set_pvs;
            s_tag_block zone_set_audibility;
            s_tag_block zone_sets;
            s_tag_block lighting_zone_sets;
            s_tag_block campaign_players;
            s_tag_data editor_scenario_data;
            s_tag_block comments;
            s_tag_block unused_scenario_environment_objects;
            c_typed_tag_block<scenario_object_name> object_names;
            s_tag_block scenery;
            s_tag_block scenery_palette;
            s_tag_block bipeds;
            s_tag_block biped_palette;
            s_tag_block vehicles;
            s_tag_block vehicle_palette;
            s_tag_block equipment;
            s_tag_block equipment_palette;
            s_tag_block weapons;
            s_tag_block weapon_palette;
            s_tag_block device_groups;
            s_tag_block machines;
            s_tag_block machine_palette;
            s_tag_block terminals;
            s_tag_block terminal_palette;
            s_tag_block controls;
            s_tag_block control_palette;
            s_tag_block sound_scenery;
            s_tag_block sound_scenery_palette;
            s_tag_block giants;
            s_tag_block giant_palette;
            s_tag_block effect_scenery;
            s_tag_block effect_scenery_palette;
            s_tag_block light_volumes;
            s_tag_block light_volume_palette;
            s_tag_block map_variant_vehicle_palette;
            s_tag_block map_variant_weapon_palette;
            s_tag_block map_variant_equipment_palette;
            s_tag_block map_variant_scenery_palette;
            s_tag_block map_variant_teleporters_palette;
            s_tag_block map_variant_goals_palette;
            s_tag_block map_variant_spawners_palette;
            s_tag_block soft_ceilings;
            s_tag_block player_starting_profile;
            s_tag_block player_starting_locations;
            s_tag_block trigger_volumes;
            s_tag_block recorded_animations;
            s_tag_block zone_set_trigger_volumes;
            s_tag_block enemy_forbid_influence;
            s_tag_block enemy_bias_influence;
            s_tag_block ally_bias_influence;
            s_tag_block selected_ally_bias_influence;
            s_tag_block dead_teammate_influence;
            s_tag_block weapon_spawn_influencers;
            s_tag_block vehicle_spawn_influencers;
            s_tag_block projectile_spawn_influencers;
            s_tag_block equipment_spawn_influencers;
            s_tag_block koth_hill_influencer;
            s_tag_block oddball_influencer;
            s_tag_block ctf_flag_away_influencer;
            s_tag_block territories_ally_influencer;
            s_tag_block territories_enemy_influencer;
            s_tag_block infection_safe_zone_human_influencer;
            s_tag_block infection_safe_zone_zombie_influencer;
            s_tag_block vip_influencer;
            s_tag_block decals;
            s_tag_block decal_palette;
            s_tag_block detail_object_collection_palette;
            s_tag_block style_palette;
            s_tag_block squad_groups;
            s_tag_block squads;
            s_tag_block zones;

            s_tag_block mission_scenes;
            s_tag_block character_palette;
            s_tag_block ai_pathfinding_data;
            s_tag_block ai_user_hint_data;
            s_tag_block ai_recording_references;
            s_tag_data script_string_data;
            s_tag_block scripts;
            s_tag_block globals;
            s_tag_block references;
            s_tag_block source_files;
            s_tag_block scripting_data;
            s_tag_block cutscene_flags;
            s_tag_block cutscene_camera_points;
            s_tag_block cutscene_titles;
            s_tag_reference custom_object_names;
            s_tag_reference chapter_title_text;
            s_tag_block scenario_resources;
            s_tag_block hs_unit_seats;
            s_tag_block scenario_kill_triggers;
            s_tag_block scenario_safe_zone_triggers;
            s_tag_block hs_syntax_datums;
            s_tag_block orders;
            s_tag_block triggers;
            s_tag_block acoustics_palette;
            s_tag_block old_background_sound_palette;
            s_tag_block sound_environment_palette;
            s_tag_block weather_palette;
            s_tag_block atmosphere;
            s_tag_block camera_fx_palette;
            s_tag_block scenario_cluster_data;
            s_tag_block acoustic_spaces;
            int object_salts[32];
            s_tag_block spawn_data;
            s_tag_reference sound_effect_collection;
            s_tag_block crates;
            s_tag_block crate_palette;
        };
        char data[0x780];
    };

    static_assert(sizeof(scenario_definition) == 0x780);

    inline scenario_definition* global_scenario() {
        return *REF<scenario_definition*>(s_data_offset_table::global_scenario);
    }
}
