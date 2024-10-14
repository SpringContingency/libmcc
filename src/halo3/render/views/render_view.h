#pragma once

#include "../render_cameras.h"

namespace Halo3 {
    struct c_view {
        struct s_vftable {

        };

        s_vftable* vftable;
        render_camera camera;
    };
}