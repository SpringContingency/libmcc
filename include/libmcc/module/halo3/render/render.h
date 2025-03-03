#pragma once

namespace libmcc::halo3 {
    struct s_oriented_bounding_box {
        real matrix[4][4];
    };

    struct render_projection {
        real_matrix4x3 world_to_view;
        real_matrix4x3 view_to_world;
        real_rectangle2d projection_bounds;
        s_oriented_bounding_box projective_to_texture;
        real_vector2d __unknownB8;
    };

    static_assert(sizeof(render_projection) == 192);
}
