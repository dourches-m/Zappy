import copy
import search
import sys
import random
from collections import deque
import os
import tile
import position as pos
from kbhit import KBHit
import time


def format_to_diclist(string):
    list = string[1:-1].split(',')
    newlist = []
    for each in list:
        dic = {}
        for any in each.split(' '):
            if any != '':
                try:
                    dic[any] += 1
                except KeyError:
                    dic[any] = 1
        newlist.append(dic)
    return newlist


def format_to_dict(string):
    list = string[1:-1].split(',')
    newdict = {}
    for each in list:
        item, nb = tuple(filter(lambda x: x != '', each.split(' ')))
        newdict[item] = int(nb)
    return newdict


class Player():
    def __init__(self, sock):
        with open(os.path.dirname(__file__) + '/adjectives') as f1:
            with open(os.path.dirname(__file__) + '/animals') as f2:
                adjs = f1.readlines()
                anims = f2.readlines()
                self.name = str(random.choice(adjs))[:-1] + ' ' + \
                str(random.choice(adjs))[:-1] + ' ' + \
                str(random.choice(anims))[:-1]
        self.level = 1
        self.cycles = 0
        self.group = [self.name]
        self.tmp_group = []
        self.state = 'FirstIncant'
        self.broad_queue = deque([])
        self.inventory = {'linemate': 0,
                          'deraumere': 0,
                          'sibur': 0,
                          'mendiane': 0,
                          'phiras': 0,
                          'thystame': 0,
                          'food': 10}
        random.seed(time.time())
        self.fiability = 75
        self.get_food = False
        self.look_counter = 0
        self.sent_orders = deque([])
        self.no_pop_commands = {'dead' : self.callback_die, 'message': self.callback_broadcast,
                                'eject:' : self.callback_eject, 'Current' : self.callback_level_up,
                                'Elevation' : self.callback_incant}

        self.state_dict = {'FirstIncant' : self.get_lv2,
                           'Hungry' : self.search_food,
                           'LFG' : self.search_group,
                           'PrepLead': self.prep_lead,
                           'PrepWork': self.prep_work,
                           'Leading' : self.lead_search,
                           'Gathering' : self.work_search,
                           'Incanting' : self.incanting,
                           'GoIncanting' : self.go_incant,
                           'end incant' : self.end_incant
                           }

        self.answer_dict = {'Inventory' : self.inventory_answer, 'Look' : self.look_answer,
                            'Incantation' : self.incant_answer,
                            'EndIncant' : self.end_incant_answer,
                            'Forward': self.movement_answer, 'Left': self.movement_answer, 'Right': self.movement_answer,
                            'Take' : self.take_answer, 'Set' : self.set_answer,
                            'Connect_nbr' : self.connect_nbr_answer, 'Fork' : self.fork_answer,
                            'Broadcast': self.do_nothing,
                            'Eject' : self.do_nothing}
        self.sock = sock
        self.sock.start_connection()
        self.team, self.xMax, self.yMax = sock.team, int(sock.maxX), int(sock.maxY)
        self.rem_connects = int(sock.rem_connects)
        self.pos = pos.Position(0, 0, self.xMax, self.yMax, 'NORTH')
        self.pos._init_dir_dict()
        self.map = [[tile.Tile(x, y) for x in range(self.xMax)] for y in range(self.yMax)]
        self.map[0][0].inventory['player'] += 1
        #self.kb = KBHit()


    '''
    ---------------------------------------------------------------
    ---------------------------------------------------------------
                          COMMAND ANSWERS
    ---------------------------------------------------------------
    ---------------------------------------------------------------
    '''

    def inventory_answer(self, command, str):
        '''
        Updates item after using the Inventory command
        '''
        dict = format_to_dict(str)
        self.inventory.update(dict)
        self.cycles = 0

    def look_answer(self, command, look_dict):
        '''
        Launched after sucessful execution of Look
        :param look_dict: list of dics returned by Look
        refresh the map inventories
        '''
        look_dict = format_to_diclist(look_dict)
        max_delta = self.level
        x, y, tile, delta = (0, 0, 0, 0)
        while delta <= max_delta:
            map_pos_y = self.yMax - abs(self.pos.y + y) if self.pos.y + y < 0 else (self.pos.y + y) % self.yMax
            map_pos_x = self.xMax - abs(self.pos.x + x) if self.pos.x + x < 0 else (self.pos.x + x) % self.xMax
            for key, value in self.map[map_pos_y][map_pos_x].inventory.items():
                if key in look_dict[tile].keys():
                    self.map[map_pos_y][map_pos_x].inventory[key] = look_dict[tile][key]
                else:
                    self.map[map_pos_y][map_pos_x].inventory[key] = 0
            tile += 1
            x, y, delta = self.pos.next_case(x, y, delta)

    def incant_answer(self, command, data):
        '''
        Set AI as "currently incanting"
        '''
        print("Calling the [start]incant answer")
        if data != 'ko':
            self.sent_orders.append("EndIncant")
        else:
            self.order("Look")


    def end_incant_answer(self, command, data):
        '''
        levels the ai up or not, depending of Incantation return.
        '''
        print("Calling the [end]incant answer")
        if data != 'ko':
            self.callback_level_up()
        else:
            self.order("Look")

    def movement_answer(self, command, pos):
        '''
        Changes the player's position according to the displacement command sent
        '''
        if command == 'Right' or command == 'Left':
            self.pos.change_dir(command)
        else:
            print("Forwarding.")
            self.map[self.pos.y][self.pos.x].inventory['player'] -= 1
            self.pos.forward()
            self.map[self.pos.y][self.pos.x].inventory['player'] += 1
        print(self.pos)

    def take_answer(self, command, data):
        item = command.split(' ')[1]
        if data == 'ko':
            self.map[self.pos.y][self.pos.x].inventory[item] = 0
        else:
            self.map[self.pos.y][self.pos.x].inventory[item] -= 1
            self.inventory[item] += 1

    def set_answer(self, command, data):
        item = command.split(' ')[1]
        if data == 'ko':
            self.inventory[item] = 0
        else:
            self.map[self.pos.y][self.pos.x].inventory[item] += 1
            self.inventory[item] -= 1

    def connect_nbr_answer(self, command, data):
        '''
        Updates available number of players for the team.
        '''
        self.rem_connects = int(data)

    def fork_answer(self, command, data):
        '''
        Forks the AI and connects the forked ai
        '''
        self.order("Connect_nbr")

    '''
    ---------------------------------------------------------------
    ---------------------------------------------------------------
                           CALLBACKS
    ---------------------------------------------------------------
    ---------------------------------------------------------------
    '''

    def callback_level_up(self, data=None):
        print("Calling the level up callback.")
        self.level += 1
        self.state = 'LFG'
        self.broad_queue = deque([])
        self.group = [self.name]

    def callback_die(self, command):
        '''
        This kills the Trantorian
        '''
        #self.kb.set_normal_term()
        print("MAX LEVEL {}".format(self.level))
        print("FINAL STATE = {}".format(self.state))
        exit(0)

    def callback_eject(self, data):
        '''
        Actualises player position after being ejected
        '''
        dir = int(data.split(' ')[1])
        dirs = {[(1, 'NORTH'), (5, 'SOUTH'), (3, 'EAST'), (7, 'WEST')] : (self.pos.x, self.pos.next_y()),
                [(5, 'NORTH'), (1, 'SOUTH'), (7, 'EAST'), (3, 'WEST')] : (self.pos.x, self.pos.prev_y()),
                [(3, 'NORTH'), (7, 'SOUTH'), (5, 'EAST'), (1, 'WEST')] : (self.pos.next_x(), self.pos.y),
                [(7, 'NORTH'), (3, 'SOUTH'), (1, 'EAST'), (5, 'WEST')] : (self.pos.prev_x(), self.pos.y)}

        self.pos.x = dirs[(dir, self.pos.dir)]
        self.pos.y = dirs[(dir, self.pos.dir)]

    def callback_broadcast(self, data):
        if self.state != 'Hungry' and self.state != 'FirstIncant':
            broad_dir = int(data[8])
            data = data[11:]
            self.broad_queue.append((broad_dir, data))


    '''
    ---------------------------------------------------------------
    ---------------------------------------------------------------
                         STATES    
    ---------------------------------------------------------------
    ---------------------------------------------------------------
    '''

    def end_incant(self):
        pass

    def go_incant(self):
        print("Go Incanting")
        if len(self.broad_queue) > 0 and self.search_target == '':
            dir, message = self.broad_queue.pop()
            self.broad_queue.clear()
            sender = message[1:message.index(']')]
            if dir == 0:
                self.streak += 1
            else:
                self.streak = 0
            if sender == self.chief and "Can you set" in message:
                self.search_target = message[message.index('{') + 1:message.index('}')]
            elif dir != 0 and sender == self.chief and "Come to me " in message and self.cast_tile is None:
                self.goto_broad_dir(dir)
                self.order("Broadcast [{}] L'attente..".format(self.name))
                self.order("Broadcast [{}] L'attente..".format(self.name))
                self.order("Broadcast [{}] L'attente..".format(self.name))
            elif sender == self.chief and self.name in message and "end incant" in message:
                self.state = "end incant"
                return
            if self.streak >= 2:
                self.order("Broadcast [{}] Hey chief, ready incant!".format(self.name))
                self.cast_tile = self.map[self.pos.y][self.pos.x]
                self.streak = 0

        elif self.search_target != '':
            if self.inventory[self.search_target] > 0:
                self.order("Set {}".format(self.search_target))
                self.order("Broadcast [{}] Can set {{{}}}".format(self.name, self.search_target))
                self.search_target = ''
            else:
                self.order("Broadcast [{}] Cannot set {{{}}}".format(self.name, self.search_target))
                self.search_target = ''
            return

    def incanting(self):
        print("Incanting with substate {}".format(self.inc_state))
        while len(self.broad_queue) > 0:
            dir, message = self.broad_queue.popleft()
            sender = message[1:message.index(']')]
            if 'ready incant' in message and sender in self.waitgroup:
                self.waitgroup.remove(sender)
            elif 'Can set' in message and sender in self.group:
                self.put_queue.popleft()
            elif 'Cannot set' in message and sender in self.group:
                self.put_queue[0][1][-1] = (sender, "received")
            if len(self.put_queue) == 0 and self.inc_state == "sorting":
                self.order("Incantation")
                return
        if self.inc_state == "pre-posing":
            for key, value in tile.level_dict[self.level + 1].items():
                if key is not 'player' and self.map[self.pos.y][self.pos.x].inventory[key] < value:
                    for i in range(value - self.map[self.pos.y][self.pos.x].inventory[key]):
                        self.put_queue.append((key, []))
            self.inc_state = "sorting"
        elif self.inc_state == "sorting" and len(self.put_queue) > 0:
            print(self.put_queue)
            if len(self.put_queue[0][1]) == 0:
                self.put_queue[0][1].append((self.name, 'received'))
                if self.inventory[self.put_queue[0][0]] > 0:
                    self.order("Set {}".format(self.put_queue[0][0]))
                    self.put_queue.popleft()
            elif len(self.put_queue[0][1]) < len(self.group) + 1:
                if self.put_queue[0][1][-1][1] == 'received':
                    self.put_queue[0][1].append((self.group[len(self.put_queue[0][1]) - 1], 'sent'))
                    self.order("Broadcast [{}] Can you set a {{{}}} here?".format(self.name, self.put_queue[0][0]))
        elif self.inc_state == "taking":
            for key, value in self.map[self.pos.y][self.pos.x].inventory.items():
                if key in tile.level_dict[self.level + 1].keys() and value > tile.level_dict[self.level + 1][key]:
                    self.order("Take {}".format(key))
                    return
            self.inc_state = "pre-posing"
        elif len(self.waitgroup) == 0 and self.inc_state == "start":
            self.inc_state = "taking"
            self.order("Look")
        else:
            self.order('Broadcast [{}] Come to me to incant !'.format(self.name))

    def lead_search(self):
        print("Leading")
        while len(self.broad_queue) > 0:
            dir, message = self.broad_queue.popleft()
            sender = message[1:message.index(']')]
            if "Got item" in message and self.name in message:
                item = message[message.index('{') + 1:message.index('}')]
                self.gather_orders.remove((sender, item))
                print("Still need this : {}".format(self.stone_dict))
        if len(self.gather_orders) < len(self.group):
            for key, value in self.stone_dict.items():
                if len(self.gather_orders) == len(self.group):
                    break
                if value > 0:
                    for each in self.group:
                        if (each, key) not in self.gather_orders:
                            self.gather_orders.append((each, key))
                            self.stone_dict[key] -= 1
                            self.order("Broadcast [{}] {} seek for {{{}}}".format(
                                self.name, each, key))
                            break
        if list(self.stone_dict.values()).count(0) == len(self.stone_dict) and \
            len(self.gather_orders) == 0:
            self.order("Broadcast [{}] Stop gathering, go incant! {}".format(self.name, self.group))
            self.waitgroup = copy.deepcopy(self.group)
            self.inc_state = "start"
            self.put_queue = deque([])
            self.state = 'Incanting'

    def work_search(self):
        print("Gathering")
        while len(self.broad_queue) > 0 and self.search_target == '':
            dir, message = self.broad_queue.popleft()
            if self.chief in message and self.name in message and 'seek for' in message:
                self.search_target = message[message.index('{') + 1:message.index('}')]
                self.inv_target = int(self.inventory[self.search_target]) + 1
            elif self.chief in message and self.name in message and 'go incant' in message:
                self.state = "GoIncanting"
                self.cast_tile = None
                self.streak = 0
        if self.search_target != '':
            if self.inventory[self.search_target] != self.inv_target:
                tiles = self.search_items([self.search_target])
                if tiles != None:
                    if tiles[0].x == self.pos.x and tiles[0].y == self.pos.y:
                        self.order("Take {}".format(self.search_target))
                    else:
                        self.goto_tile(tiles[0])
            elif self.inventory[self.search_target] == self.inv_target:
                self.order('Broadcast [{}] Got item {{{}}} for chief {} !'.format(self.name, self.search_target, self.chief))
                self.search_target = ''

    def prep_work(self):
        print("PrepWorking")
        while len(self.broad_queue) > 0:
            dir, message = self.broad_queue.popleft()
            if self.chief in message and self.name in message:
                self.order('Broadcast [{}] Okidoki, ready to work! {}'.format(self.name, self.inventory))
                self.search_target = ''
                self.state = 'Gathering'

    def prep_lead(self):
        print("PrepLeading")
        self.order("Broadcast [{}] Group done for : {}".format(self.name, self.group))
        while len(self.broad_queue) > 0:
            dir, message = self.broad_queue.popleft()
            for each in self.tmp_group:
                if message.startswith('[{}]'.format(each)) and 'Okidoki, ready to work!' in message:
                    for key, value in search.re_inventory.findall(message):
                        self.group_inventory[key] = int(self.group_inventory[key])
                        self.group_inventory[key] += int(value)
                    self.tmp_group.remove(each)
        if self.tmp_group == []:
            self.state = 'Leading'
            self.gather_orders = deque([])
            tile.removekey(self.group_inventory, 'food')
            self.stone_dict = copy.deepcopy(tile.level_dict[self.level + 1])
            self.stone_dict = tile.removekey(self.stone_dict, 'player')
            for key, value in self.stone_dict.items():
                if key in self.group_inventory.keys() and self.group_inventory[key] > 0 and self.stone_dict[key] > 0:
                    self.stone_dict[key] = self.stone_dict[key] - self.group_inventory[key]\
                        if self.group_inventory[key] < self.stone_dict[key] else 0
            self.gather_orders = deque([])

    def search_group(self):
        print("LFGing")
        while len(self.broad_queue) > 0:
            dir, message = self.broad_queue.popleft()
            if 'LFG' in message:
                send_name = message[1:message.index(']')]
                level = int(search.re_level.search(message).groups()[0])
                if send_name > self.name and level == int(self.level):
                    print("CHANGING STATE")
                    self.group = [self.name]
                    self.chief = send_name
                    self.state = 'PrepWork'
                elif level == self.level and send_name < self.name and send_name not in self.group:
                    self.group.append(send_name)
            elif 'Group done' in message and self.name in message:
                self.group = [self.name]
                self.chief = message[1:message.index(']')]
                self.state = 'PrepWork'
        if max(self.group) == self.name and len(self.group) < tile.level_dict[self.level + 1]['player']:
            self.order("Broadcast [{}] LFG lvl {}!".format(self.name, self.level))
        elif max(self.group) == self.name and len(self.group) == tile.level_dict[self.level + 1]['player']:
            self.group.remove(self.name)
            self.group_inventory = copy.deepcopy(self.inventory)
            self.state = 'PrepLead'
            self.tmp_group = copy.deepcopy(self.group)

    def get_lv2(self):
        print("Lv2 Getting")
        if int(self.map[self.pos.y][self.pos.x].inventory['linemate']) < 1:
            tiles = self.search_items(['linemate'])
            if tiles is not None:
                self.goto_tile(tiles[0])
        elif not self.incant_tile(self.map[self.pos.y][self.pos.x].inventory, tile.level_two):
            for key, value in self.map[self.pos.y][self.pos.x].inventory.items():
                if key is not 'player' and key is not 'linemate' and int(self.map[self.pos.y][self.pos.x].inventory[key]) > 0:
                    self.order('Take {}'.format(key))
                elif key is 'linemate' and int(self.map[self.pos.y][self.pos.x].inventory[key]) > 1:
                    self.order('Take {}'.format(key))
                elif key is 'player' and int(self.map[self.pos.y][self.pos.x].inventory[key]) > 1:
                    self.order("Eject")
        elif 'Incantation' not in self.sent_orders and\
            'EndIncant' not in self.sent_orders and\
            self.incant_tile(self.map[self.pos.y][self.pos.x].inventory, tile.level_two):
            self.order('Incantation')
        else:
            self.order("Look")

    def search_food(self):
        '''
        Makes the AI search for food
        '''
        print("Food Searching")
        tiles = self.search_items(['food'])
        if tiles != None:
            print("Wanna go there :", tiles[0])
            if tiles[0].x == self.pos.x and tiles[0].y == self.pos.y:
                self.order('Take food')
            else:
                self.goto_tile(tiles[0])

    '''
    ---------------------------------------------------------------
    ---------------------------------------------------------------
                         MAP MANAGEMENT
    ---------------------------------------------------------------
    ---------------------------------------------------------------
    '''

    def goto_tile(self, tile):
        '''
        Given a tile, takes a step toward it.
        '''

        dirs = {'NORTH': [[], ['Right', 'Right'], ['Left'], ['Right']],
                'SOUTH': [['Left', 'Left'], [], ['Right'], ['Left']],
                'EAST': [['Left'], ['Right'], [], ['Right', 'Right']],
                'WEST': [['Right'], ['Left'], ['Left', 'Left'], []]}
        
        diff_x, diff_y = (abs(tile.x - self.pos.x), abs(tile.y - self.pos.y))
        if (diff_y == 0 and diff_x != 0) or diff_x != 0 and random.randint(0, 1) == 1:
            x_outside = self.pos.xbound - max(self.pos.x, tile.x) + min(self.pos.x, tile.x) < diff_x
            dictdir = dirs[self.pos.dir][2] if x_outside and self.pos.x > tile.x \
            or not x_outside and tile.x > self.pos.x else dirs[self.pos.dir][3]
        elif diff_y != 0:
            y_outside = self.pos.ybound - max(self.pos.y, tile.y) + min(self.pos.y, tile.y) < diff_y
            dictdir = dirs[self.pos.dir][0] if y_outside and self.pos.y > tile.y \
            or not y_outside and tile.y > self.pos.y else dirs[self.pos.dir][1]
        else:
            return
        for each in dictdir:
            self.order(each)
        self.order('Forward')

    def goto_broad_dir(self, dir):
        '''
        Given a broadcast direction), tries to take the shortest path to it.
        '''
        dirdict = {1: ['Forward'],
                   2: ['Forward', 'Left', 'Forward'],
                   3: ['Left', 'Forward'],
                   4: ['Left', 'Forward', 'Left', 'Forward'],
                   5: ['Right', 'Right', 'Forward'],
                   6: ['Right', 'Forward', 'Right', 'Forward'],
                   7: ['Right', 'Forward'],
                   8: ['Forward', 'Right', 'Forward'],
                   0: []}
        for each in dirdict[dir]:
            self.order(each)

    def lookahead(self):
        '''
        Returns the Tiles in the see-able range of the player
        '''
        ahead = []
        max_delta = self.level
        x, y ,delta, moy, reliability = (0, 0, 0 ,0 ,0)
        while delta <= max_delta:
            map_pos_y = self.yMax - abs(self.pos.y + y) if self.pos.y + y < 0 else (self.pos.y + y) % self.yMax
            map_pos_x = self.xMax - abs(self.pos.x + x) if self.pos.x + x < 0 else (self.pos.x + x) % self.xMax
            ahead.append(self.map[map_pos_y][map_pos_x])
            x, y, delta = self.pos.next_case(x, y, delta)
        return ahead

    def lookaround(self):
        '''
        Returns the 8 tiles near the player, plus the player's tile
        '''
        around = []
        around.append(self.map[self.pos.y][self.pos.x])
        around.append(self.map[self.pos.y][self.pos.next_x()])
        around.append(self.map[self.pos.y][self.pos.prev_x()])
        around.append(self.map[self.pos.next_y()][self.pos.x])
        around.append(self.map[self.pos.prev_y()][self.pos.x])
        return around


    '''
    ---------------------------------------------------------------
    ---------------------------------------------------------------
                         TIME / BEHAVIOUR MANAGEMENT
    ---------------------------------------------------------------
    ---------------------------------------------------------------
    '''

    def cycle_update(self, data):
        '''
        Update the player life according to
        :data: , the executed command
        '''
        if data in ['Forward', 'Right', 'Left', 'Look',
                'Broadcast', 'Eject', 'Take', 'Set']:
            self.cycles += 7
        elif data is 'Inventory':
            self.cycles += 1
        elif data is 'Fork':
            self.cycles += 42
        elif data is 'EndIncant':
            self.cycles += 300
        self.cycles += 5

    def manual_override(self, inp_str):
        if self.kb.kbhit():
            c = self.kb.getch()
            if c == '\n':
                if inp_str.split(' ')[0] in self.answer_dict.keys():
                    self.order(inp_str)
                    inp_str = ''
                    print()
                else:
                    inp_str = ''
                    print('\nBad command')
            elif c == '\x7f':
                print('\b \b', end="")
                inp_str = inp_str[:-1]
                sys.stdout.flush()
            else:
                inp_str += c
                print(c, end="")
                sys.stdout.flush()
        return inp_str

    def auto_pilot(self):
        if len(self.sent_orders) < 10:
            if self.cycles > 80:
                self.order('Inventory')
                self.cycles = 0
            if int(self.inventory['food']) <= 10 and self.state != 'Hungry':
                self.prev_state = self.state
                self.state = 'Hungry'
            elif int(self.inventory['food']) > 30 and self.state == 'Hungry':
                self.state = self.prev_state
            if len(self.sent_orders) == 0:
                self.state_dict[self.state]()
            if len(self.sent_orders) == 0:
                self.order('Inventory')

    def go(self):
        '''
        AI Main loop. Interrupts when the player dies.
        '''
        inp_str = ''
        self.last_orders = copy.deepcopy(self.sent_orders)
        while True:
            self.sock.send_data()
            self.auto_pilot()
            #inp_str = self.manual_override(inp_str)
            if self.sent_orders != self.last_orders:
                self.last_orders = copy.deepcopy(self.sent_orders)
                print("SENT ORDER == \"{}\"".format(self.sent_orders))
            if self.sock.receive_data() == "die":
                print("Server connection cut.")
                self.callback_die("ded")
            data = self.sock.pop_data()
            if data != "":
                self.order_answer(data)

    '''
    ---------------------------------------------------------------
    ---------------------------------------------------------------
                         MISCELLANEOUS
    ---------------------------------------------------------------
    ---------------------------------------------------------------
    '''

    def is_moving(self):
        '''
        Check if player is currently moving
        '''
        return 'Forward' in self.sent_orders \
               or 'Right' in self.sent_orders \
               or 'Left' in self.sent_orders


    def order(self, data):
        '''
        Append an order to the queue of sent orders
        '''
        self.sock.prepare_to_send(data)
        self.sent_orders.append(data)

    def no_incant_trick(self, data):
        if "Current level" in data:
            return "EndIncant" != self.sent_orders[0]
        elif "Elevation" in data:
            return "Incantation" != self.sent_orders[0]
        return True

    def order_answer(self, data):
        '''
        Treats the answer to an order
        '''
        if data.split(' ')[0] in self.no_pop_commands.keys()\
                and self.no_incant_trick(data):
            #print("Received \"{}\".".format(data))
            self.no_pop_commands[data.split(' ')[0]](data)
            return
        popped = self.sent_orders.popleft()
        self.cycle_update(popped.split(' ')[0])
        #print("For \"{}\" sent, received \"{}\".".format(popped, data))
        pop = popped.split(' ')[0]
        self.answer_dict[pop](popped, data)

    def search_items(self, itemlist):
        tiles = []
        for y in self.map:
            for x in y:
                tiles.append(x)
        if self.look_counter == 0:
            self.look_counter = self.level + 1
            self.order('Look')
            return
        else:
            self.look_counter -= 1
            tiles = tile.select_tile(list(set(tiles)), itemlist,
                                     self.pos)
            if len(tiles) == 0:
                self.order(random.choice(['Forward', 'Forward', 'Left', 'Right']))
                return None
            return tiles

    def gem_empty(self, tile):
        for key, value in tile.inventory.items():
            if value != 0 and key != 'player' and key != 'food':
                return False
        return True

    def incant_tile(self, tile, incant):
        for key, value in incant.items():
            if int(value) != int(tile[key]):
                print("False because of key {} == {} except of {}".format(key, int(tile[key]), value))
                self.order("Look")
                return False
        return True

    def do_nothing(self, command, data):
        pass

    def callback_incant(self, data):
        pass