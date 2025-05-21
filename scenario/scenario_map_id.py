from ctypes import c_int, c_short, c_longlong, Structure

class e_map_id(c_int):
    k_map_id_count = 228
    k_map_id_none = -2

class s_scenario_map_id(Structure):
    _fields_ = [
        ("builtin_map_id", e_map_id),
        ("part1", c_short),
        ("flags", c_short),
        ("part2", c_longlong)
    ]
