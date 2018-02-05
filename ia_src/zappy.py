import zappy_connection as zapsock
from player import Player


def launch_zappy(port, name, machine):
    player = Player(zapsock.Socket(machine, port, name))
    player.go()
    exit(0)
