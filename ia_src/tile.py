import operator
from functools import cmp_to_key

level_two = {'linemate': 1,
             'deraumere': 0,
             'sibur': 0,
             'mendiane': 0,
             'phiras': 0,
             'thystame': 0,
             'player': 1}

level_three = {'linemate': 1,
               'deraumere': 1,
               'sibur': 1,
               'mendiane': 0,
               'phiras': 0,
               'thystame': 0,
               'player': 2}

level_four = {'linemate': 2,
              'deraumere': 0,
              'sibur': 1,
              'mendiane': 0,
              'phiras': 2,
              'thystame': 0,
              'player': 2}

level_five = {'linemate': 1,
              'deraumere': 1,
              'sibur': 2,
              'mendiane': 0,
              'phiras': 1,
              'thystame': 0,
              'player': 4}

level_six = {'linemate': 1,
             'deraumere': 2,
             'sibur': 1,
             'mendiane': 3,
             'phiras': 0,
             'thystame': 0,
             'player': 4}

level_seven = {'linemate': 1,
               'deraumere': 2,
               'sibur': 3,
               'mendiane': 0,
               'phiras': 1,
               'thystame': 0,
               'player': 6}

level_eight = {'linemate': 2,
               'deraumere': 2,
               'sibur': 2,
               'mendiane': 2,
               'phiras': 2,
               'thystame': 1,
               'player': 6}


level_dict = {2: level_two, 3: level_three, 4: level_four,
              5: level_five, 6: level_six, 7: level_seven, 8: level_eight}

def select_tile(tilelist, keylist, play_pos):
    tiles = []

    for tile in tilelist:
        for item, nb in tile.inventory.items():
            if item in keylist and nb > 0:
                tiles.append(tile)
                break

    dist_list = []

    for tile in tiles:
        val = play_pos.dist_to_tile(tile)
        idx = 0
        for idx in range(len(dist_list)):
            if val < play_pos.dist_to_tile(dist_list[idx]):
                idx = 0 if idx == 0 else idx - 1
                break
            idx += 1
        dist_list.insert(idx, tile)

    return list(set(dist_list))


def removekey(d, key):
    r = dict(d)
    del r[key]
    return r


class Tile:
    def __init__(self, x, y):
        self.x = x
        self.y = y
        self.inventory = {'linemate': 0,
                          'deraumere': 0,
                          'sibur': 0,
                          'mendiane': 0,
                          'phiras': 0,
                          'thystame': 0,
                          'food': 0,
                          'player': 0}

    def update(self, cycles, inventory={}):
        self.inventory = self.inventory.update(inventory)

    def __eq__(self, other):
        dict_eq = [a == b for a, b in zip(self.inventory.values(), other.inventory.values())]
        return self.x == other.x and self.y == other.y and dict_eq.count(False) == 0

    def __str__(self):
        return "Tile placed in {}, {} containing {}.".format(self.x, self.y, self.inventory)

    def __hash__(self):
        return hash(str(self))

    def incanting(self):
        true_inventory = removekey(self.inventory, 'food')

        if (true_inventory == level_two or
            true_inventory == level_three or
            true_inventory == level_four or
            true_inventory == level_five or
            true_inventory == level_six or
            true_inventory == level_seven or
            true_inventory == level_eight):
            return True
        return False
