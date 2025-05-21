from ctypes import c_short, Structure

class short_point3d(Structure):
    _fields_ = [
        ("x", c_short),
        ("y", c_short),
        ("z", c_short)
    ]

class rectangle2d(Structure):
    _fields_ = [
        ("y0", c_short),
        ("x0", c_short),
        ("y1", c_short),
        ("x1", c_short)
    ]

