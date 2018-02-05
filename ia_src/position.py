from collections import OrderedDict

class MyOrderedDict(OrderedDict):
    def first_key(self):
        for key in self: return key
        raise ValueError("OrderedDict() is empty")

    def prev_key(self, key):
        items = list(self.items())
        if items[0][0] == key:
            return items[len(self) - 1][0]
        for x in range(1, len(items)):
            if items[x][0] == key:
                return items[x - 1][0]

    def next_key(self, key):
        items = list(self.items())
        for x in range(len(items)):
            if items[x][0] == key:
                return items[(x + 1) % len(self)][0]


class Position:
    def __init__(self, x, y, xbound = None, ybound = None, dir = None):
        self.x = x
        self.y = y
        self.dir = dir
        self.xbound = xbound
        self.ybound = ybound

    def _init_dir_dict(self):
        self.dir_dict = MyOrderedDict({'NORTH': Position(1, 1, self.xbound, self.ybound),
                                       'EAST': Position(1, -1, self.xbound, self.ybound),
                                       'SOUTH': Position(-1, -1, self.xbound, self.ybound),
                                       'WEST': Position(-1, 1, self.xbound, self.ybound)})

    def __str__(self):
        return "Pos [{}, {}], facing {}, on map of dimensions [{}, {}]".format(
            self.x, self.y, self.dir, self.xbound, self.ybound)

    def dist_to_tile(self, tile):
        x_outside = self.xbound - max(self.x, tile.x) + min(self.x, tile.x)
        x_inside = max(self.x, tile.x) - min(self.x, tile.x)
        y_outside = self.ybound - max(self.y, tile.y) + min(self.y, tile.y)
        y_inside =  max(self.y, tile.y) - min(self.y, tile.y)
        return min(x_outside, x_inside) + min(y_outside, y_inside)
        

    def forward(self):
        if self.dir == 'NORTH' or self.dir == 'SOUTH':
            self.y = self.ybound - 1 if self.y + self.dir_dict[self.dir].y < 0 else (self.y + self.dir_dict[self.dir].y) % self.ybound
        else:
            self.x = self.xbound - 1 if self.x + self.dir_dict[self.dir].x < 0 else (self.x + self.dir_dict[self.dir].x) % self.xbound

    def change_dir(self, dir):
        if dir == 'Left':
            self.dir = self.dir_dict.prev_key(self.dir)
        elif dir == 'Right':
            self.dir = self.dir_dict.next_key(self.dir)

    def next_x(self):
        next = self.x + 1 if self.x + 1 < self.xbound else 0
        return next

    def next_y(self):
        next = self.y + 1 if self.y + 1 < self.ybound else 0
        return next

    def prev_x(self):
        prev = self.x - 1 if self.x + 1 >= 0 else self.xbound -1
        return prev

    def prev_y(self):
        prev = self.y - 1 if self.y - 1 >= 0 else self.ybound - 1
        return prev

    def next_case(self, x, y, delta):
        if self.dir == 'NORTH' or self.dir == 'SOUTH':
            x = (x + self.dir_dict[self.dir].x) if abs(x + self.dir_dict[self.dir].x) <= delta \
                else (delta + 1) * -1 * self.dir_dict[self.dir].x
            y = y + self.dir_dict[self.dir].y if abs(x) > delta else y
            delta = delta + 1 if abs(x) > delta else delta
        else:
            y = (y + self.dir_dict[self.dir].y) if abs(y + self.dir_dict[self.dir].y) <= delta\
                else (delta + 1) * -1 *  self.dir_dict[self.dir].y
            x = x + self.dir_dict[self.dir].x if abs(y) > delta else x
            delta = delta + 1 if abs(y) > delta else delta
        return (x, y, delta)
