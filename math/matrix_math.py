from ctypes import Structure
from .real_math import real, real_vector3d

class real_matrix3x3(Structure):
    _fields_ = [
        ("forward", real_vector3d),
        ("left", real_vector3d),
        ("up", real_vector3d)
    ]

class real_matrix4x3(Structure):
    _fields_ = [
        ("center", real_vector3d),
        ("matrix", real_matrix3x3),
        ("scale", real)
    ]
