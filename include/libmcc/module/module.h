#pragma once

#include "../game/language.h"
#include "../game/data_access.h"
#include "../game/game_engine.h"

#define GROUNDHOG_MODULE_NAME "groundhog.dll"
#define HALOREACH_MODULE_NAME "haloreach.dll"
#define HALO1_MODULE_NAME "halo1.dll"
#define HALO2_MODULE_NAME "halo2.dll"
#define HALO3_MODULE_NAME "halo3.dll"
#define HALO3ODST_MODULE_NAME "halo3odst.dll"
#define HALO4_MODULE_NAME "halo4.dll"
#define MCC_MODULE_NAME "MCC-Win64-Shipping.exe"
#define MCCWINSTORE_MODULE_NAME "MCCWinStore-Win64-Shipping.exe"

#define EXPORT_FUNCTION_CREATE_DATA_ACCESS "CreateDataAccess"
#define EXPORT_FUNCTION_CREATE_GAME_ENGINE "CreateGameEngine"
#define EXPORT_FUNCTION_SET_LIBRARY_SETTINGS "SetLibrarySettings"

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
		_module_network_session_layer = -2,

		k_module_count,
		k_module_none = -1,
	};

	typedef uint64_t(__fastcall* t_expf_create_data_access)(i_data_access**);
	typedef uint64_t(__fastcall* t_expf_create_game_engine)(i_game_engine**);
	typedef errno_t(__fastcall* t_expf_set_library_settings)(const s_language_settings*);
}
