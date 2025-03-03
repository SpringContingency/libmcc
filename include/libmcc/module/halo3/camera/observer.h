#pragma once

#include "../game/players.h"
#include "../structures/structures.h"

namespace libmcc::halo3 {
    struct s_observer_command {
        int flags;
        real_point3d position;
        real_point3d focus_offset;
        real_point2d crosshair_location;
        real focus_distance;
        real field_of_view;
        real_vector3d forward;
        real_vector3d up;
        real_vector3d velocities;
        real_matrix4x3 focus_space;
        int : 32;
        real_point3d center;
        real timer;
        int parent_objects[2];
        int number_of_parents_objects;
        real_point3d physics_pill_position;
        real physics_pill_height;
        real physics_pill_radius;
        char unknown[52];
    };

    static_assert(sizeof(s_observer_command) == 0xEC);

    struct s_observer_result {
        real_point3d focus_point;
        s_location location;
        char __dataE[2];
        real_vector3d __vector10;
        real_vector3d __vector1C;
        real_vector3d forward;
        real_vector3d up;
        real horizontal_field_of_view;
        int __flags44;
        char __data48[16];
        real __unknown58;
        real_vector2d __vector44;
        real __unknown64;
        real vertical_field_of_view;
        real horizontal_field_of_view_rad;
    };

    static_assert(sizeof(s_observer_result) == 0x70);

    union s_observer {
		struct {
		    int header_signature;
		    s_observer_command *pending_command;
		    s_observer_command command;
		    bool updated_for_frame;
		    bool __unknownF5;
		    bool __unknownF6;
		    bool __unknownF7;
		    real __unknownF8;
		    int __unknownFC;
		    int __unknown100;
		    int __unknown104;
		    bool result_valid;
		    char __unknown109;
		    char __unknown10A;
		    char __unknown10B;
		    s_observer_result result;
		    real_point3d positions_focus_position;
		    real_vector3d positions_focus_offset;
		    char __data194[8];
		    real positions_focus_distance;
		    real horizontal_field_of_view;
		    real_vector3d positions_forward;
		    real_vector3d positions_up;
		    real_matrix4x3 focus_space;
		    real velocities[13]; // 0x1F8
		    real accelerations[13];
		    real __unknown260[13];
		    real __unknown294[13];
		    real __unknown2C8[13];
		    real __unknown2FC[13];
		    real __unknown330[13];
		    real __unknown364[13];
		    real displacements[13];
		    int trailer_signature; // 972
        };
        char data[0x3D0];

        static constexpr int signature = 0x72616421;
    };

    static_assert(sizeof(s_observer) == 0x3D0);

    union s_observer_globals {
        struct {
            real dtime;
            s_observer observers[k_local_player_count];
        };
        char data[0xF50];
    };

    static_assert(sizeof(s_observer_globals) == 0xF50);
}
