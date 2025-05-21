from ctypes import Structure, c_float

class real(c_float):
    pass

class real_point2d(Structure):
    _fields_ = [
        ("x", real),
        ("y", real)
    ]

class real_point3d(Structure):
    _fields_ = [
        ("x", real),
        ("y", real),
        ("z", real)
    ]

class real_vector2d(Structure):
    _fields_ = [
        ("i", real),
        ("j", real)
    ]

class real_vector3d(Structure):
    _fields_ = [
        ("i", real),
        ("j", real),
        ("k", real)
    ]

class real_vector4d(Structure):
    _fields_ = [
        ("i", real),
        ("j", real),
        ("k", real),
        ("w", real)
    ]

class real_euler_angles2d(Structure):
    _fields_ = [
        ("yaw", real),
        ("pitch", real)
    ]

class real_euler_angles3d(Structure):
    _fields_ = [
        ("yaw", real),
        ("pitch", real),
        ("roll", real)
    ]

class real_quaternion(Structure):
    _fields_ = [
        ("i", real),
        ("j", real),
        ("k", real),
        ("w", real)
    ]

class real_orientation(Structure):
    _fields_ = [
        ("rotation", real_quaternion),
        ("translation", real_point3d),
        ("scale", real)
    ]

class real_bounds(Structure):
    _fields_ = [
        ("lower", real),
        ("upper", real)
    ]