#pragma once

#include "../native.h"
#include "../game/game_tick.h"
#include "../game/game_engine.h"
#include "../game/game_globals.h"
#include "../game/player_control.h"
#include "../camera/director.h"
#include "../objects/objects.h"

namespace libmcc::halo3 {
    struct s_thread_local_storage {
        uint64_t : 64; // 0x00
        uint64_t : 64; // 0x08
        void* player_data; // 0x10
        int g_registered_thread_index; // 0x18
        s_game_engine_globals* game_engine_globals; // 0x20
        uint64_t : 64; // 0x28
        uint64_t : 64; // 0x30
        s_data_array<object_header_datum>* object_header_data; // 0x38
        uint64_t : 64; // 0x40
        game_globals_storage* game_globals; // 0x48
        uint64_t : 64; // 0x50
        uint64_t : 64; // 0x58
        uint64_t : 64; // 0x60
        uint64_t : 64; // 0x68
        uint64_t : 64; // 0x70
        uint64_t : 64; // 0x78
        uint64_t : 64; // 0x80
        uint64_t : 64; // 0x88
        uint64_t : 64; // 0x90
        uint64_t : 64; // 0x98
        uint64_t : 64; // 0xA0
        uint64_t : 64; // 0xA8
        uint64_t : 64; // 0xB0
        uint64_t : 64; // 0xB8
        s_player_control_globals* player_control_globals; // 0xC0
        game_time_globals_struct* game_time_globals; // 0xC8
        uint64_t : 64; // 0xD0
        void* g_campaign_metagame_globals; // 0xD8
        uint64_t : 64; // 0xE0
        uint64_t : 64; // 0xE8
        uint64_t : 64; // 0xF0
        uint64_t : 64; // 0xF8
        uint64_t : 64; // 0x100
        uint64_t : 64; // 0x108
        uint64_t : 64; // 0x110
        uint64_t : 64; // 0x118
        uint64_t : 64; // 0x120
        uint64_t : 64; // 0x128
        uint64_t : 64; // 0x130
        uint64_t : 64; // 0x138
        uint64_t : 64; // 0x140
        uint64_t : 64; // 0x148
        void* g_font_cache_globals; // 0x150
        uint64_t : 64; // 0x158
        uint64_t : 64; // 0x160
        uint64_t : 64; // 0x168
        uint64_t : 64; // 0x170
        uint64_t : 64; // 0x178
        uint64_t : 64; // 0x180
        s_director_globals* director_globals; // 0x188
        uint64_t : 64; // 0x190
        uint64_t : 64; // 0x198
        uint64_t : 64; // 0x1A0
        uint64_t : 64; // 0x1A8
        uint64_t : 64; // 0x1B0
        uint64_t : 64; // 0x1B8
        uint64_t : 64; // 0x1C0
        uint64_t : 64; // 0x1C8
        uint64_t : 64; // 0x1D0
        uint64_t : 64; // 0x1D8
        uint64_t : 64; // 0x1E0
        uint64_t : 64; // 0x1E8
        uint64_t : 64; // 0x1F0
        uint64_t : 64; // 0x1F8
        uint64_t : 64; // 0x200
        uint64_t : 64; // 0x208
        uint64_t : 64; // 0x210
        uint64_t : 64; // 0x218
        uint64_t : 64; // 0x220
        uint64_t : 64; // 0x228
        uint64_t : 64; // 0x230
        uint64_t : 64; // 0x238
        uint64_t : 64; // 0x240
        uint64_t : 64; // 0x248
        uint64_t : 64; // 0x250
        uint64_t : 64; // 0x258
        uint64_t : 64; // 0x260
        uint64_t : 64; // 0x268
        uint64_t : 64; // 0x270
        uint64_t : 64; // 0x278
        uint64_t : 64; // 0x280
        uint64_t : 64; // 0x288
        uint64_t : 64; // 0x290
        uint64_t : 64; // 0x298
        uint64_t : 64; // 0x2A0
        uint64_t : 64; // 0x2A8
        uint64_t : 64; // 0x2B0
        uint64_t : 64; // 0x2B8
        uint64_t : 64; // 0x2C0
        uint64_t : 64; // 0x2C8
        uint64_t : 64; // 0x2D0
        uint64_t : 64; // 0x2D8
        uint64_t : 64; // 0x2E0
        uint64_t : 64; // 0x2E8
        uint64_t : 64; // 0x2F0
        uint64_t : 64; // 0x2F8
        uint64_t : 64; // 0x300
        uint64_t : 64; // 0x308
        uint64_t : 64; // 0x310
        uint64_t : 64; // 0x318
        uint64_t : 64; // 0x320
        uint64_t : 64; // 0x328
        uint64_t : 64; // 0x330
        uint64_t : 64; // 0x338
        uint64_t : 64; // 0x340
        uint64_t : 64; // 0x348
        uint64_t : 64; // 0x350
        uint64_t : 64; // 0x358
        uint64_t : 64; // 0x360
        uint64_t : 64; // 0x368
        uint64_t : 64; // 0x370
        uint64_t : 64; // 0x378
        uint64_t : 64; // 0x380
        uint64_t : 64; // 0x388
        uint64_t : 64; // 0x390
        uint64_t : 64; // 0x398
        uint64_t : 64; // 0x3A0
        uint64_t : 64; // 0x3A8
        uint64_t : 64; // 0x3B0
        uint64_t : 64; // 0x3B8
        uint64_t : 64; // 0x3C0
        uint64_t : 64; // 0x3C8
        uint64_t : 64; // 0x3D0
        uint64_t : 64; // 0x3D8
        uint64_t : 64; // 0x3E0
        uint64_t : 64; // 0x3E8
        uint64_t : 64; // 0x3F0
        uint64_t : 64; // 0x3F8
        uint64_t : 64; // 0x400
        uint64_t : 64; // 0x408
        uint64_t : 64; // 0x410
        uint64_t : 64; // 0x418
        uint64_t : 64; // 0x420
        uint64_t : 64; // 0x428
        uint64_t : 64; // 0x430
        uint64_t : 64; // 0x438
        uint64_t : 64; // 0x440
        uint64_t : 64; // 0x448
        uint64_t : 64; // 0x450
        uint64_t : 64; // 0x458
        uint64_t : 64; // 0x460
        uint64_t : 64; // 0x468
        uint64_t : 64; // 0x470
        uint64_t : 64; // 0x478
        uint64_t : 64; // 0x480
        uint64_t : 64; // 0x488
        uint64_t : 64; // 0x490
        uint64_t : 64; // 0x498
        uint64_t : 64; // 0x4A0
        uint64_t : 64; // 0x4A8
        uint64_t : 64; // 0x4B0
        uint64_t : 64; // 0x4B8
        uint64_t : 64; // 0x4C0
        uint64_t : 64; // 0x4C8
        uint64_t : 64; // 0x4D0
        uint64_t : 64; // 0x4D8
        uint64_t : 64; // 0x4E0
        uint64_t : 64; // 0x4E8
        uint64_t : 64; // 0x4F0
        uint64_t : 64; // 0x4F8
        uint64_t : 64; // 0x500
        uint64_t : 64; // 0x508
        uint64_t : 64; // 0x510
        uint64_t : 64; // 0x518
        uint64_t : 64; // 0x520
        uint64_t : 64; // 0x528
        uint64_t : 64; // 0x530
        uint64_t : 64; // 0x538
        uint64_t : 64; // 0x540
        uint64_t : 64; // 0x548
        uint64_t : 64; // 0x550
        uint64_t : 64; // 0x558
        uint64_t : 64; // 0x560
        uint64_t : 64; // 0x568
        uint64_t : 64; // 0x570
        s_observer_globals* g_observer_globals; // 0x578
    };

	inline s_thread_local_storage* g_thread_local_storage() {
		return reinterpret_cast<s_thread_local_storage*>(get_tls(get_tls_index(hModule)));
	}

    inline bool game_in_progress() {
        auto globals = g_thread_local_storage()->game_globals;
        return globals != nullptr && globals->game_in_progress && !globals->initializing && globals->map_active;
    }
}
