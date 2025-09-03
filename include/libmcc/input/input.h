#pragma once

#include "../common.h"

namespace libmcc {
    enum e_mouse_button {
        _mouse_button_left = 0,
        _mouse_button_right = 1,
        _mouse_button_middle = 2,
        _mouse_button_4 = 3,
        _mouse_button_5 = 4,
    };

    enum e_gamepad_button {
        _gamepad_button_dpad_up = 0,
        _gamepad_button_dpad_down = 1,
        _gamepad_button_dpad_left = 2,
        _gamepad_button_dpad_right = 3,
        _gamepad_button_start = 4,
        _gamepad_button_back = 5,
        _gamepad_button_left_thumb = 6,
        _gamepad_button_right_thumb = 7,
        _gamepad_button_left_shoulder = 8,
        _gamepad_button_right_shoulder = 9,
        _gamepad_button_a = 10,
        _gamepad_button_b = 11,
        _gamepad_button_x = 12,
        _gamepad_button_y = 13,
    };

    enum e_abstract_gamepad_button : unsigned char {
        _abstract_gamepad_button_left_trigger,
        _abstract_gamepad_button_right_trigger,
        _abstract_gamepad_button_up,
        _abstract_gamepad_button_down,
        _abstract_gamepad_button_left,
        _abstract_gamepad_button_right,
        _abstract_gamepad_button_start,
        _abstract_gamepad_button_select,
        _abstract_gamepad_button_left_stick,
        _abstract_gamepad_button_right_stick,
        _abstract_gamepad_button_left_bumper,
        _abstract_gamepad_button_right_bumper,
        _abstract_gamepad_button_a,
        _abstract_gamepad_button_b,
        _abstract_gamepad_button_x,
        _abstract_gamepad_button_y,

        k_abstract_gamepad_button_count = 0x10,
        k_abstract_gamepad_button_none = 0xFF,
    };

    enum e_game_abstract_button {
        _game_abstract_button_jump,
        _game_abstract_button_switchgrenade,
        _game_abstract_button_actionreload,
        _game_abstract_button_reload,
        _game_abstract_button_switchweapon,
        _game_abstract_button_meleeattack,
        _game_abstract_button_flashlight,
        _game_abstract_button_throwgrenade,
        _game_abstract_button_fire,
        _game_abstract_button_crouch,
        _game_abstract_button_zoom,
        _game_abstract_button_zoomin,
        _game_abstract_button_zoomout,
        _game_abstract_button_swapweapon,
        _game_abstract_button_sprint,
        _game_abstract_button_bansheebomb,
        _game_abstract_button_moveforward,
        _game_abstract_button_movebackward,
        _game_abstract_button_strafeleft,
        _game_abstract_button_straferight,
        _game_abstract_button_showscores,
        _game_abstract_button_primaryvehicletrick,
        _game_abstract_button_secondaryvehicletrick,
        _game_abstract_button_equipment,
        _game_abstract_button_secondaryfire,
        _game_abstract_button_lifteditor,
        _game_abstract_button_dropeditor,
        _game_abstract_button_grabobjecteditor,
        _game_abstract_button_boosteditor,
        _game_abstract_button_croucheditor,
        _game_abstract_button_deleteobjecteditor,
        _game_abstract_button_createobjecteditor,
        _game_abstract_button_opentoolmenueditor,
        _game_abstract_button_switchplayermodeeditor,
        _game_abstract_button_scopezoomeditor,
        _game_abstract_button_playerlockformanipulationeditor,
        _game_abstract_button_showhidepanneltheater,
        _game_abstract_button_showhideinterfacetheater,
        _game_abstract_button_togglefirstthirdpersonviewtheater,
        _game_abstract_button_camerafocustheater,
        _game_abstract_button_fastforwardtheater,
        _game_abstract_button_fastrewindtheater,
        _game_abstract_button_stopcontinueplaybacktheater,
        _game_abstract_button_playbackspeeduptheater,
        _game_abstract_button_enterfreecameramodetheater,
        _game_abstract_button_movementspeeduptheater,
        _game_abstract_button_panningcameratheater,
        _game_abstract_button_cameramoveuptheater,
        _game_abstract_button_cameramovedowntheater,
        _game_abstract_button_dualwield,
        _game_abstract_button_zoomcameratheater,
        _game_abstract_button_togglerotationaxeseditor,
        _game_abstract_button_duplicateobjecteditor,
        _game_abstract_button_lockobjecteditor,
        _game_abstract_button_resetorientationeditor,
        _game_abstract_button_reloadsecondary,
        _game_abstract_button_previousgrenade,
        _game_abstract_button_specialaction,
        _game_abstract_button_loadoutmenu,
        _game_abstract_button_activatewaypoint,
        _game_abstract_button_activatewaypointalt,
        _game_abstract_button_pingnavpoints,
        _game_abstract_button_raisehornet,
        _game_abstract_button_lowerhornet,
        _game_abstract_button_flashlightalt,
        _game_abstract_button_nextgrenade,

        k_game_abstract_button_count,
    };

    struct s_keyboard_state {
        bool key_down[256];
    };

    static_assert(sizeof(s_keyboard_state) == 0x100);

    struct s_mouse_state {
        float lX;       // relative position in X
        float lY;       // relative position in Y
        float pX;       // absolute position in X
        float pY;       // absolute position in Y
        float lZ;       // relative position in Z
        float lZScale;  // relative position in Z scale
		s_flags<int, e_mouse_button> buttons;
    };

    static_assert(sizeof(s_mouse_state) == 0x1C);

    struct s_gamepad_state {
        s_flags<int, e_gamepad_button> buttons;
        unsigned char leftTrigger;
        unsigned char rightTrigger;
        short thumbLX;
        short thumbLY;
        short thumbRX;
        short thumbRY;
    };

    static_assert(sizeof(s_gamepad_state) == 0x10);

    struct s_input_state {
        int is_km;
        s_keyboard_state keyboard;
        s_mouse_state mouse;
        s_gamepad_state gamepad;
    };

    static_assert(sizeof(s_input_state) == 0x130);

    struct s_rumble_state {
        short left_motor_speed;
        short right_motor_speed;
    };

    struct s_custom_keyboard_mouse_mapping_v2 {
        e_game_abstract_button abstract_button;
        int virtual_key_codes[5];
    };

    static_assert(sizeof(s_custom_keyboard_mouse_mapping_v2) == 0x18);

    struct s_gamepad_mapping {
        e_abstract_gamepad_button actions[k_game_abstract_button_count];
    };

    static_assert(sizeof(s_gamepad_mapping) == 0x42);
}
