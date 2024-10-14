#pragma once

#include "./simulation_queue.h"
#include "../units/units.h"
#include "../game/player_control.h"

//#define H3_DEBUG_BUILD

namespace Halo3 {
#pragma pack(push, 1)
    struct core_update_definition {
        enum {
            _simulation_update_simulation_in_progress_bit = 0x1,
            _simulation_update_game_simulation_queue_requires_application_bit = 0x8,
        };

        int update_number;
        int flags;
        int player_flags;
        int un;
        player_action_definition actions[16];
        int verify_game_time;
        int verify_random;

#ifdef H3_DEBUG_BUILD
        char buffer[136];
#endif

        simulation_queue_definition simulation_queue;
        simulation_queue_definition game_simulation_queue;

        inline bool has_player_actions() {return player_flags != 0;}
    };

#ifdef H3_DEBUG_BUILD
    static_assert(sizeof(core_update_definition) == 2416);
#else
    static_assert(sizeof(core_update_definition) == 2280);
#endif

    struct simulation_update_definition {
        core_update_definition core_update;
        int64 valid_actor_mask;
        datum_index actor_unit_index[16];
        unit_control_definition control_data[16];
        bool machine_update_exists;
        char padding[3];
        int machine_valid_mask;
        s_machine_identifier machineIdentifier[16];
        int64 un1;
        int valid_player_prediction_mask;
        player_prediction_definition player_prediction[16];
        char buffer[68];
        int valid_camera_mask;
        int camera_type;
        int player_absolute_index;
        Vector3 camera_update_position;
        Vector3 camera_update_forward;
        bool zoomed;
        char padding2[3];

        bool has_player_prediction() {return valid_player_prediction_mask != 0;}
    };

#pragma pack(pop)

#ifdef H3_DEBUG_BUILD
    static_assert(sizeof(simulation_update_definition) == 5912);
#else
    static_assert(sizeof(simulation_update_definition) == 5776);
#endif
}