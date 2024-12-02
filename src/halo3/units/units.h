#pragma once

#include "../game/aim_assist.h"
#include "../objects/objects.h"

struct units_definition : objects_definition {
    enum eUnitFlags {
        _biped_setting_relaxation_pose_bit = 0x200,
    };

    uint8_t v9[0x54];
    t_definition_index actor_index;//0x168
    uint8_t v10[0x4];
    uint32_t unit_flags;
    eTeamAI team; //0x174
    t_Player player_index; //0x178
    uint8_t v11[0xA0]; //0x20C?
    t_definition_index aim_target; //0x21C
    uint8_t v12[0x14C];
    float camo_time;
    uint64_t un;
    float crouch_progress; // [0, 1.0]
    uint8_t v13[0xE4];
    uint16_t biped_flags;
    uint8_t v14[0x42];
    t_definition_index bump_target; // 1188
    uint8_t bump_close;

    // 0x460 uint16_t biped.flags

    inline bool FlashLight(){return unit_flags & 0x8000000u;}
    inline void FlashLight(bool b){if(b) unit_flags |= 0x8000000u;else damage_flags &= ~0x8000000u;}
    inline bool CanMove(){return unit_flags & 0x3u;}
    inline void CanMove(bool b){if(b) unit_flags |= 0x3u;else unit_flags &= ~0x3u;}
    inline void EnableCamo() { unit_flags |= 0x10u | 0x8u; }
    inline void SetCamo(float time) { EnableCamo(); camo_time = time; }
};

struct unit_control_definition {
    const static int k_maximum_weapons_per_unit = 4;
    const static int k_unit_grenade_types_count = 4;
    const static uint16_t k_unit_aiming_speeds_count = 0x8000;

    int identifier;
    uint16_t un;
    uint16_t weapon_set_identifier;
    char primary_weapon_indices;
    char secondary_weapon_indices;
    uint16_t grenade_index;
    uint16_t zoom_level;
    uint16_t interaction_type;
    uint64_t action_flags;
    Vector3 throttle; // 24 movement
    float primary_trigger;
    float secondary_trigger;
    Vector3 facing_vector;
    Vector3 aiming_vector;
    Vector3 looking_vector;
    Vector3 gaze_position;
    aim_assist_definition aim_assist_data;
};