#pragma once

#define GROUNDHOG_MODULE_NAME "groundhog.dll"
#define HALOREACH_MODULE_NAME "haloreach.dll"
#define HALO1_MODULE_NAME "halo1.dll"
#define HALO2_MODULE_NAME "halo2.dll"
#define HALO3_MODULE_NAME "halo3.dll"
#define HALO3ODST_MODULE_NAME "halo3odst.dll"
#define HALO4_MODULE_NAME "halo4.dll"
#define MCC_MODULE_NAME "MCC-Win64-Shipping.exe"
#define MCCWINSTORE_MODULE_NAME "MCCWinStore-Win64-Shipping.exe"

namespace libmcc {
	enum e_module {
		_module_halo1,
		_module_halo2,
		_module_halo3,
		_module_halo4,
		_module_groundhog,
		_module_halo3odst,
		_module_haloreach,
		_module_mcc,
		_module_mccwinstore,

		k_module_count,
		k_module_invalid = -1,
	};

	inline const char* g_module_names[] = {
		HALO1_MODULE_NAME,
		HALO2_MODULE_NAME,
		HALO3_MODULE_NAME,
		HALO4_MODULE_NAME,
		GROUNDHOG_MODULE_NAME,
		HALO3ODST_MODULE_NAME,
		HALOREACH_MODULE_NAME,
		MCC_MODULE_NAME,
		MCCWINSTORE_MODULE_NAME,
	};

	inline const char* module_name(e_module module) {
		return g_module_names[module];
	}
}
