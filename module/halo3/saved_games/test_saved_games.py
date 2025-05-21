import unittest
from saved_game_files import *

class test_saved_games(unittest.TestCase):
    def test_structure_size(self):
        self.assertEqual(sizeof(s_saved_game_item_metadata), 248)

if __name__ == '__main__':
    unittest.main()
