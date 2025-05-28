#pragma once

#include "../tag_files/tag_files.h"
#include "../geometry/geometry_definitions.h"

namespace libmcc::halo3 {
	struct s_scenario_lightmap_bsp_data {
		short flags;
		short bsp_reference_index;
		int structure_bsp_import_checksum;
		real_vector3d compression_vectors[18];
		s_tag_reference lightprobe_texture_reference;
		s_tag_reference dominant_light_intensity_texture_reference;
		s_tag_block bsp_per_vertex_data_block;
		s_tag_block clusters_block;
		s_tag_block instances_block;
		s_tag_block probes_block;
		s_render_geometry imported_geometry;
		s_tag_block airprobes_block;
		s_tag_block scenery_probes_block;
		s_tag_block device_machine_probes_block;
		s_tag_block errors_block;
	};

	static_assert(sizeof(s_scenario_lightmap_bsp_data) == 0x1E4);

	struct s_scenario_lightmap_bsp_data_reference {
		c_typed_tag_reference<s_scenario_lightmap_bsp_data> lightmap_bsp_data_reference;
	};

	struct s_scenario_lightmap {
	    int job_guid;
	    c_typed_tag_block<s_scenario_lightmap_bsp_data_reference> per_pxiel_lightmap_bsps;
	    s_tag_block per_vertex_lightmap_bsps;
	    s_tag_block airprobes;
	    s_tag_block scenery_probes;
	    s_tag_block device_machine_probes;
		s_tag_block lightmap_bsps;
	};

	static_assert(sizeof(s_scenario_lightmap) == 0x4C);
}
