import select
import socket
import circ_buffer as buffer
import sys


class Socket:
    def __init__(self, address, port, team):
        self.in_buffer = buffer.CharCircBuffer()
        self.out_buffer = buffer.CharCircBuffer()
        self.serv = socket.socket()
        try:
            self.serv.connect((address, port))
        except ConnectionError:
            print("Could not connect to server : aborting client", file=sys.stderr)
            exit(0)
        self.team = team
        self.ip = address
        self.port = port
        self.recvpoll = select.poll()

    def __del__(self):
        self.serv.close()

    def start_connection(self):
        try:
            welcome = self.serv.recv(128)
            if welcome != b'WELCOME\n':
                raise Exception("Bad welcome")
            self.serv.send(bytes(self.team + "\n", 'utf-8'))
            datalist = self.serv.recv(128).decode('utf-8').split('\n')
            self.rem_connects = datalist[0]
            if len(datalist) == 2:
                datalist[1] = self.serv.recv(128).decode('utf-8')[:-1]
            self.maxX, self.maxY = datalist[1].split(' ')
            self.RDONLY = select.POLLIN | select.POLLPRI | select.POLLHUP | select.POLLERR
            self.recvpoll.register(self.serv.fileno(), self.RDONLY)
        except ConnectionError:
            print('Connection with server cut, aborting client.')
            exit(0)
        except Exception:
            print('Bad info sent from server, aborting client.'
                  'Are you sure the server is following the zappy protocol ?')
            exit(0)

    def pop_data(self):
        return self.in_buffer.pop()

    def receive_data(self):
        pool = self.recvpoll.poll(1)
        if len(pool) == 0 or pool[0][1] & select.POLLIN == 0:
            return ''
        data = self.serv.recv(1024).decode('utf-8')
        if data == "":
            return "die"
        self.in_buffer.append(data)

    def prepare_to_send(self, data):
        if data[-1] != '\n':
            data += '\n'
        self.out_buffer.append(data)

    def send_data(self):
        data = self.out_buffer.pop()
        if data == "":
            return
        sent_data = self.serv.send(bytes(data + "\n", 'utf-8'))
        if sent_data == 0:
            return "die"
        elif sent_data < len(data):
            self.out_buffer.append_left(data[sent_data:])
