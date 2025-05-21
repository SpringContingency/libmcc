import unittest
from ctypes import sizeof

from .scenario_map_variant import s_map_variant

class test_scenario(unittest.TestCase):
    def test_structure_size(self):
        self.assertEqual(sizeof(s_map_variant), 57504)

if __name__ == '__main__':
    unittest.main()
