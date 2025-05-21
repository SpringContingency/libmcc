from ctypes import Structure
from .real_math import real, real_vector2d, real_vector3d

class real_plane2d(Structure):
    _fields_ = [
        ("n", real_vector2d),
        ("d", real)
    ]

class real_plane3d(Structure):
    _fields_ = [
        ("n", real_vector3d),
        ("d", real)
    ]

class real_rectangle2d(Structure):
    _fields_ = [
        ("x0", real),
        ("x1", real),
        ("y0", real),
        ("y1", real)
    ]

class real_rectangle3d(Structure):
    _fields_ = [
        ("x0", real),
        ("x1", real),
        ("y0", real),
        ("y1", real),
        ("z0", real),
        ("z1", real)
    ]
