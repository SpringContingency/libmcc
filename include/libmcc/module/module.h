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

		k_game_count = 7,
		k_module_count = 10,
		k_module_none = -1,
	};

	typedef uint64_t(__fastcall* t_expf_create_data_access)(i_data_access**);
	typedef uint64_t(__fastcall* t_expf_create_game_engine)(i_game_engine**);
	typedef errno_t(__fastcall* t_expf_set_library_settings)(const s_language_settings*);

	struct s_module_info {
		e_module module_index;
		int error_code;
		HMODULE module_handle;
		t_expf_create_data_access create_data_access;
		i_data_access* data_access;
	};

	static_assert(sizeof(s_module_info) == 0x20);

	struct c_module_manager;

	struct c_module_manager_vftable {
		c_module_manager* (__fastcall* deep_copy)(c_module_manager* This, c_module_manager* other);
		c_module_manager* (__fastcall* shallow_copy)(c_module_manager* This, c_module_manager* other);
		void (__fastcall* update)(c_module_manager* This);
		void* (__fastcall* type)(c_module_manager* This);
		void* (__fastcall* unknown_0)(c_module_manager* This, bool value);
		void* (__fastcall* unknown_1)(c_module_manager* This);
	};

	struct c_module_manager {
		c_module_manager_vftable* __vftable;
		std::array<s_module_info, k_game_count>* m_module_infos;
		e_module m_module;
	};

	struct s_event {
		const char* name;
		HANDLE event;
		bool bAutoReset; // !bManualReset
	};

	struct s_thread {
		const char* name; // RaiseException(0x406D1388)
		LPTHREAD_START_ROUTINE start_routine;
		LPVOID parameter;
		int stack_size;
		int priority; // SetThreadPriority
		int processor; // SetThreadIdealProcessor
		HANDLE thread;
		uint64_t : 64;
		int thread_id;
	};

	union s_queue_thread {
		struct {
			s_event event;
			CRITICAL_SECTION critical_section;
			uint64_t : 64;
			s_thread thread;
		};
		char data[0xC0];
	};

	static_assert(sizeof(s_queue_thread) == 0xC0);

	struct s_module_globals {
		std::array<s_module_info, k_game_count> module_infos;
		s_queue_thread* queue_thread;
		DLL_DIRECTORY_COOKIE dll_cookie;
	};

	static_assert(sizeof(s_module_globals) == 0xF0);
}
