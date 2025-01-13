#pragma once

namespace libmcc {
	struct s_player_loadout {
        int tactical_package_index;
        int support_upgrade_index;
        int primary_weapon_index;
        int secondary_weapon_index;
        int primary_weapon_variant_index;
        int secondary_weapon_variant_index;
        int equipment_index;
        int grenade_index;
        wchar_t name[14];
	};

	static_assert(sizeof(s_player_loadout) == 0x3C);
}
