#!/usr/bin/python3

global loop_running

def signal_handler(signal, frame):
    global loop_running
    loop_running = False


import select
import signal
import time
import socket
import multiprocessing as mp
import subprocess as sp
import sys
import re
import argparse

class Translator():
    def __init__(self):
        self.en_fr = {"player": "joueur", 'food': 'nourriture',
                      'look': 'voir', 'left': 'gauche', 'right': 'droite',
                      'inventory': 'inventaire', 'forward': 'avance',
                      'take': 'prend', 'dead': 'mort',
                      'set': 'pose', 'eject': 'expulse', 'Welcome': 'Bienvenue'}
        self.fr_en = {v: k for k, v in self.en_fr.items()}
        self.en_fr.update({'\[': '{', '\]': '}'})
        self.fr_en.update({'{': '[', '}': ']'})

    def is_fr(self, data):
        matches = 0
        for key, value in self.fr_en.items():
            match = re.match(key, data)
            if match != None:
                matches += 1
        return matches

    def is_en(self, data):
        matches = 0
        for key, value in self.en_fr.items():
            match = re.match(key, data)
            if match != None:
                matches += 1
        return matches

    def choose_book(self, data):
        en = self.is_en(data)
        fr = self.is_fr(data)
        if en > fr:
            return self.en_fr
        elif fr > en:
            return self.fr_en
        else:
            return {}

    def translate(self, data):
        oldata = data
        book = self.choose_book(data)
        for key, value in book.items():
            data = re.sub(key.lower(), value.lower(), data)
        return data

def launch_graphic(args):
    time.sleep(0.5)
    graph = sp.run(args)

def graph_args(port):
    result = "./zappy-gfx-linux64 127.0.0.1 " + port
    return result.split(' ')

def get_srv_port():
    for each in range(len(sys.argv)):
        if re.match('-p', sys.argv[each]):
            return sys.argv[each + 1]


def launch_server(args, in_buf, out_buf):
    args.insert(0, "./old-zappy-server-linux")
    serv = sp.run(args)
    return

if __name__ == "__main__":
    global loop_running
    loop_running = True
    signal.signal(signal.SIGINT, signal_handler)
    with mp.Manager() as mgr:
        parser = argparse.ArgumentParser()
        parser.add_argument("-y", type=int, help="Hauteur")
        parser.add_argument("-x", type=int, help="Largeur")
        parser.add_argument("-c", type=int, help="Clients max par équipe")
        parser.add_argument("-p", type=int, required=True, help="Port to run server on")
        parser.add_argument("-t", type=int, required=True, help="Speed of server")
        parser.add_argument("-n", required=True, help="Team names", nargs='*',)
        parser.parse_args()
        in_buf = mgr.Queue()
        out_buf = mgr.Queue()
        srv_port = get_srv_port()
        server = mp.Process(target=launch_server, args=(sys.argv[1:], in_buf, out_buf))
        graphical = mp.Process(target=launch_graphic, args=(graph_args(srv_port),))

        server.start()
        graphical.start()


        sock = socket.socket()
        sock.bind(('', 0))
        sock.listen()
        print("Listening on port {}".format(sock.getsockname()[1]))
        rlist = [sock]
        sockmap = {}

        translator = Translator()
        while loop_running:
            readable, writable, trash = select.select(rlist, [], [], 0.1)
            for each in readable:
                if each == sock:
                    aisock = sock.accept()[0]
                    rlist.append(aisock)
                    srvsock = socket.socket()
                    srvsock.connect(('', int(srv_port)))
                    rlist.append(srvsock)
                    sockmap[aisock] = srvsock
                    sockmap[srvsock] = aisock
                else:
                    try:
                        data = each.recv(1024).decode('utf-8').lower()
                        data = translator.translate(data)
                        sockmap[each].send(bytes(data, 'utf-8'))
                    except (ConnectionResetError, BrokenPipeError):
                        other = sockmap[each]
                        sockmap.pop(each)
                        sockmap.pop(other)
                        rlist.remove(each)
                        rlist.remove(other)
        server.terminate()
        graphical.terminate()
        for each in sockmap:
            each.close()

