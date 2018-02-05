from position import MyOrderedDict
import pytest


class TestOrdicts:

    @pytest.fixture(scope="class")
    def dic(self):
        return MyOrderedDict({'NORTH': (1, 1, 'NORTH'),
        'EAST': (-1, -1, 'NORTH'),
        'SOUTH': (1, 1, 'NORTH'),
        'WEST': (1, 1, 'NORTH')})

    def test_prev(self, dic):
        assert dic.prev_key('EAST')[0] == 'NORTH'

    def test_next(self, dic):
        assert dic.next_key('EAST')[0] == 'SOUTH'

    def test_trick_prev(self, dic):
        assert dic.next_key('WEST')[0] == 'NORTH'

    def test_trick_next(self, dic):
        assert dic.prev_key('NORTH')[0] == 'WEST'