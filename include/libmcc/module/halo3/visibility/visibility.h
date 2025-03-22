#pragma once

#include "../native.h"
#include "../memory/array.h"
#include "./visibility_render_objects.h"

namespace libmcc::halo3  {
    struct s_visible_items {
        c_simple_list<s_visible_object_hierarchy, 768> root_objects;
        int : 32;
        c_simple_list<s_visible_object_render_visibility, 896> objects;
        int : 32;
        c_simple_list<s_visible_instance_list, 1024> instance_list;
        int : 32;
        c_simple_list<s_visible_instances, 1152> instances;
        c_simple_list<s_visible_clusters, 348> clusters;
    };

    struct c_visible_items {
        static s_visible_items* m_item() {
            return REF<s_visible_items>(s_data_offset_table::c_visible_items_m_item);
        };
    };
}
