#pragma once

#include "./players.h"
#include "./game_engine_variant.h"
#include "../scenario/scenario_map_id.h"
#include "../scenario/scenario_map_variant.h"

namespace libmcc {
	enum e_game_mode : int {
		_game_mode_none,
		_game_mode_campaign,
		_game_mode_spartan_ops,
		_game_mode_multiplayer,
		_game_mode_ui_shell,
		_game_mode_firefight,

		k_game_mode_count,
	};

	enum e_campaign_difficulty_level : int {
		_campaign_difficulty_level_none = -1,
		_campaign_difficulty_level_easy = 0,
		_campaign_difficulty_level_normal = 1,
		_campaign_difficulty_level_hard = 2,
		_campaign_difficulty_level_impossible = 3,
	};

	struct s_game_player_options {
		void initialize() {
			xuid = 0;
			unknown_1 = 0;
			unknown_2 = -1;
			unknown_3 = 0;
			unknown_4 = -1;
			unknown_5 = -1;
		}

		XUID xuid;
		uint64_t unknown_1;
		int unknown_2;
		int unknown_3;
		int unknown_4;
		int unknown_5;
	};

	static_assert(sizeof(s_game_player_options) == 32);


	struct s_player_options {
		void initialize() {
			for (auto& it: unknown_0) {
				it = 0;
			}
			player_count = 0;
			for (auto& it: player_options) {
				it.initialize();
			}
			unknown_1 = 0;
			unknown_2 = -1;
		}

		uintptr_t unknown_0[17];
		int player_count;
		s_game_player_options player_options[16];
		int unknown_1;
		int unknown_2;
	};

	static_assert(sizeof(s_player_options) == 664);

	union s_game_options_flags_0 {
		struct {
			char : 1;
			char : 1;
			char : 1;
			char online : 1;
			char : 1;
			char : 1;
			char un : 1;
		};
		char value;
	};

	union s_game_options_flags_1 {
		struct {
			char : 1;
			char debug : 1; // enable init.txt and terminal
			char : 1;
			char : 1;
			char unknown_0 : 1;
			char : 1;
			char unknown_1 : 1;
			char unknown_2 : 1;
		};
		char value;
	};

	union s_game_options_skulls {
		struct {

		};
		uint64_t value;
	};

	struct s_game_options_unknown {
		char data[1032];
	};

	static_assert(sizeof(s_game_options_unknown) == 1032);

	struct s_game_options {
		// todo: implement
		void initialize() {
			auto a1 = reinterpret_cast<uintptr_t>(this);
		}

		bool is_theater() {
			return saved_film_path != nullptr;
		}

		s_game_options_flags_0 flags_0;
		s_game_options_flags_1 flags_1;
		char option_1;
		char option_2;
		char option_3;
		char option_4;
		char option_5;
		char option_6;
		char network_option_1;
		char network_option_2;
		char game_tick;
		char un_0;
		e_game_mode game_mode;
		int legacy_map_id;
		s_scenario_map_id map_id;
		s_scenario_map_id custom_campaign_map_id;
		e_campaign_difficulty_level difficulty_level;
		int : 32;
		int campaign_insertion_point;
		int : 32;
		s_game_options_skulls skulls; // 72
		__int64 un_2;
		__int64 address;
		s_player_options player_options;
		__int64 un_3; // m_HostSAddr?
		s_game_engine_variant game_variant;
		s_game_options_unknown un_4;
		s_scenario_map_variant_storage map_variant;
		s_game_options_unknown un_5;
		int un_6;
		int padding_1;
		void* saved_game_state;
		const char* saved_film_path;
		__int64 un_7;
	};

	static_assert((sizeof(s_game_options) == 0x2BF30));
}
