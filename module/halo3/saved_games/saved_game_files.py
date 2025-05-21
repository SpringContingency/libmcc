from ctypes import c_bool, c_byte, c_wchar, c_int, c_ulonglong, Structure

class e_saved_game_file_type(c_int):
    _saved_game_file_type_personal = 0x0
    _saved_game_file_type_ctf = 0x1
    _saved_game_file_type_slayer = 0x2
    _saved_game_file_type_oddball = 0x3
    _saved_game_file_type_king = 0x4
    _saved_game_file_type_juggernaut = 0x5
    _saved_game_file_type_territories = 0x6
    _saved_game_file_type_assault = 0x7
    _saved_game_file_type_infection = 0x8
    _saved_game_file_type_vip = 0x9
    _saved_game_file_type_usermap = 0xA
    _saved_game_file_type_film = 0xB
    _saved_game_file_type_clip = 0xC
    _saved_game_file_type_screenshot = 0xD
    k_saved_game_file_type_count = 0xE
    _saved_game_file_type_none = 0xFFFFFFFF

class s_saved_game_item_metadata(Structure):
    _pack_ = 8
    _fields_ = [
        ("unique_id", c_ulonglong),
        ("name", c_wchar * 16),
        ("description", c_byte * 128),
        ("author", c_byte * 16),
        ("file_type", e_saved_game_file_type),
        ("author_is_xuid_online", c_bool),
        ("author_id", c_ulonglong),
        ("size_in_bytes", c_ulonglong),
        ("date", c_ulonglong),
        ("length_seconds", c_int),
        ("campaign_id", c_int),
        ("map_id", c_int),
        ("game_engine_type", c_int),
        ("campaign_difficulty", c_int),
        ("campaign_insertion_point", c_byte),
        ("campaign_survival_enabled", c_bool),
        ("game_id", c_ulonglong)
    ]
