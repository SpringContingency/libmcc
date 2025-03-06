#pragma once

#include "../memory/data.h"

namespace libmcc::halo3 {
    enum {
		_object_types_biped, 
		_object_types_vehicle, 
		_object_types_weapon, 
		_object_types_equipment, 
		_object_types_terminal, 
		_object_types_projectile, 
		_object_types_scenery, 
		_object_types_machine, 
		_object_types_control, 
		_object_types_sound_scenery,
		_object_types_crate, 
		_object_types_creature, 
		_object_types_giant, 
		_object_types_effect_scenery,

        k_object_types_count = 14,
    };


	struct _object_datum {};
	struct _item_datum {};
	struct _equipment_datum {};
	struct _weapon_datum {};
	struct _unit_datum {};
	struct _biped_datum {};
	struct _vehicle_datum {};
	struct _projectile_datum {};
	struct _device_datum {};
	struct _motor_datum {};

	struct object_datum {
		int definition_index;
		_object_datum object;
	};

	struct item_datum {
		int definition_index;
		_object_datum object;
		_item_datum item;
	};

	struct equipment_datum {
		int definition_index;
		_object_datum object;
		_equipment_datum equipment;
	};

	struct weapon_datum {
		int definition_index;
		_object_datum object;
		_item_datum item;
		_weapon_datum weapon;
	};

	struct unit_datum {
		int definition_index;
		_object_datum object;
		_motor_datum motor;
		_unit_datum unit;
	};

	struct biped_datum {
		int definition_index;
		_object_datum object;
		_motor_datum motor;
		_unit_datum unit;
		_biped_datum biped;
	};

	struct vehicle_datum {
		int definition_index;
		_object_datum object;
		_motor_datum motor;
		_unit_datum unit;
		_vehicle_datum vehicle;
	};

	struct projectile_datum {
		int definition_index;
		_object_datum object;
		_projectile_datum projectile;
	};

	struct device_datum {
		int definition_index;
		_object_datum object;
		_device_datum device;
	};

	union u_object_datum {
		char data[];
		object_datum object;
		item_datum item;
		equipment_datum equipment;
		weapon_datum weapon;
		unit_datum unit;
		biped_datum biped;
		vehicle_datum vehicle;
		projectile_datum projectile;
		device_datum device;
	};

	struct object_header_datum : s_datum_header {
		uint8_t flags;
		uint8_t type;
		__int16 cluster_index;
		__int16 data_size;
		int datum_handle;
		u_object_datum* datum;
	};
};