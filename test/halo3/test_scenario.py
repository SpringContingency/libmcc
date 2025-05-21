import unittest

from ctypes import sizeof
from libmcc.module.halo3.scenario import *

class test_scenario(unittest.TestCase):
    def test_structure_size(self):
        self.assertEqual(8, sizeof(c_object_identifier))
        self.assertEqual(24, sizeof(s_variant_multiplayer_object_properties_definition))
        self.assertEqual(84, sizeof(s_variant_object_datum))
        self.assertEqual(0xC, sizeof(s_variant_quota))
        self.assertEqual(0xE0A0, sizeof(s_map_variant))

if __name__ == '__main__':
    unittest.main()
