#pragma once

#include "../native.h"
#include "../tag_files/tag_files.h"

namespace libmcc::halo3 {
    union s_structure_bsp;

    union scenario_structure_bsp_reference {
        struct {
            c_typed_tag_reference<s_structure_bsp> structure_bsp;
            s_tag_reference structure_design;
            s_tag_reference structure_lighting_info;
        };

        char data[108];
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
            s_tag_block object_names;
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
        };
        char data[0x780];
    };

    static_assert(sizeof(scenario_definition) == 0x780);

    inline scenario_definition* global_scenario() {
        return *REF<scenario_definition*>(_data_global_scenario);
    }
}
