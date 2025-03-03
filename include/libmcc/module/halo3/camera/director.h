#pragma once

#include "camera.h"

namespace libmcc::halo3 {
    enum e_director_mode : int {
        _director_mode_game = 0x0,
        _director_mode_saved_film = 0x1,
        _director_mode_observer = 0x2,
        _director_mode_debug = 0x3,
        _director_mode_unused = 0x4,
        _director_mode_editor = 0x5,
        k_number_of_director_modes = 0x6,
    };

    class c_director {
    public:
        virtual int get_type();
        virtual void update(float);
        virtual bool should_draw_hud();
        virtual bool should_draw_hud_saved_film();
        virtual bool inhibits_facing();
        virtual bool inhibits_input();
        virtual void handle_deleted_player(int);
        virtual void handle_deleted_object(int);
        virtual bool can_use_camera_mode(int);
        virtual void select_fallback_target();

    public:
        c_camera_storage m_camera;
        s_observer_command m_observer_command;
        float m_transition_time;
        int m_output_user_index;
        int m_user_index;
    };

    class c_game_director : c_director {
    };

    class c_observer_director : c_director {
        e_camera_mode m_camera_mode;
        int m_free_camera_mode_index;
        byte m_target_camera_mode_index;
    };

    class c_saved_film_director : c_observer_director {

    };

    class c_debug_director : c_director {
        int m_camera_mode_index;
        bool m_collision_disabled;
        bool m_biped_control_mode;
    };

    class c_editor_director : c_director {
        int m_unit_focus;
        bool m_scripted;
    };

    union c_director_storage {
        c_director director;
        c_game_director game_director;
        c_saved_film_director saved_film_director;
        c_observer_director observer_director;
        c_debug_director debug_director;
        c_editor_director editor_director;
        char director_data[0x180];
    };

    static_assert((sizeof(c_director_storage) == 0x180));

    struct s_director_info {
        e_director_mode director_mode;
        int director_perspective;
        e_camera_mode camera_mode;
    };

    struct s_director_globals {
        c_director_storage directors[4];
        s_director_info infos[4];
        real dt;
        real fade_timer5B4;
        real fade_timer5B8;
        bool debug_force_scripted_camera_disable;
    };

    static_assert((sizeof(s_director_globals) == 0x640));

}
