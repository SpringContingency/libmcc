from ctypes import c_uint, c_byte, Structure, c_int, c_short, c_bool

from ....math.real_math import *
from ....math.geometry import *
from ..saved_games.saved_game_files import *
from ....scenario import *

k_variant_object_maximum_count = 640
k_variant_quota_maximum_count = 256
k_simulation_entity_maximum_count = 80

class c_object_identifier(Structure):
    _fields_ = [
        ("m_unique_id", c_int),
        ("m_origin_bsp_index", c_short),
        ("m_type", c_byte),
        ("m_source", c_byte)
    ]

class e_map_variant_palette(c_short):
    _map_variant_palette_vehicle = 1
    _map_variant_palette_weapon = 2
    _map_variant_palette_equipment = 3
    _map_variant_palette_scenery = 4
    _map_variant_palette_teleporters = 5
    _map_variant_palette_goals = 6
    _map_variant_palette_spawners = 7

    _map_variant_palette_scenario_scenery = 8
    _map_variant_palette_scenario_vehicle = 9
    _map_variant_palette_scenario_weapon = 10
    _map_variant_palette_scenario_equipment = 11
    _map_variant_palette_scenario_crates = 12

    k_map_variant_palette_count = 12
    k_map_variant_palette_none = 0

class s_variant_multiplayer_object_properties_definition(Structure):
    _fields_ = [
        ("game_engine_flags", c_short),
        ("object_flags", c_byte),
        ("team_affiliation", c_byte),
        ("shared_storage", c_byte),
        ("spawn_time", c_byte),
        ("teleporter_channel", c_byte),
        ("object_shape", c_byte),
        ("shape_radius_width", real),
        ("shape_length", real),
        ("shape_positive_height", real),
        ("shape_negative_height", real)
    ]

class s_variant_object_datum(Structure):
    _pack_ = 8
    _fields_ = [
        ("flags", c_short),
        ("__unknown2", c_short),
        ("object_datum_index", c_int),
        ("editor_object_index", c_int),
        ("variant_quota_index", c_int),
        ("position", real_rectangle3d),
        ("forward", real_rectangle3d),
        ("up", real_rectangle3d),
        ("parent_object_identifier", c_object_identifier),
        ("multiplayer_game_object_properties", s_variant_multiplayer_object_properties_definition)
    ]

class s_variant_quota_index(Structure):
    _fields_ = [
        ("index", c_short),
        ("type", e_map_variant_palette)
    ]

class s_variant_quota(Structure):
    _fields_ = [
        ("object_definition_index", s_variant_quota_index),
        ("minimum_count", c_byte),
        ("maximum_count", c_byte),
        ("placed_on_map", c_byte),
        ("maximum_allowed", c_byte),
        ("price_per_item", real)
    ]

class s_map_variant(Structure):
    _pack_ = 8
    _fields_ = [
        ("metadata", s_saved_game_item_metadata),
        ("m_map_variant_version", c_short),
        ("m_number_of_scenario_objects", c_short),
        ("m_number_of_variant_objects", c_short),
        ("m_number_of_placeable_object_quotas", c_short),
        ("m_map_id", c_int),
        ("m_world_bounds", real_rectangle3d),
        ("m_game_engine_subtype", c_int),
        ("m_maximum_budget", real),
        ("m_spent_budget", real),
        ("m_helpers_enabled", c_bool),
        ("m_built_in", c_bool),
        ("m_map_variant_checksum", c_uint),
        ("m_variant_objects", s_variant_object_datum * k_variant_object_maximum_count),
        ("m_object_type_start_index", c_short * e_map_variant_palette.k_map_variant_palette_count),
        ("m_quotas", s_variant_quota * k_variant_quota_maximum_count),
        ("m_simulation_entities", c_int * k_simulation_entity_maximum_count),
        ("map_id", s_scenario_map_id)
    ]
