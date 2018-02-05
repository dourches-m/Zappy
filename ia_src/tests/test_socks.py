import pytest, zappy_connection, time
from multiprocessing import Process, Queue, TimeoutError, Manager

def str_process(func, retval, args=()):
    retval['string'] = func(*args)

def accept_process(func, retval):
    retval['client'] = func()[0]

@pytest.fixture("module")
def srv():
    '''
    Creates a mock server
    should be accessed using Process(target=pro, args=(srv.blockingmethod,))
    '''
    import socket
    server = socket.socket()
    server.bind(('', 0))
    server.listen()
    yield server
    server.close()

def test_ping(srv):
    with Manager() as manager:
        shared = manager.dict()
        accept = Process(target=accept_process, args=(srv.accept, shared))
        accept.start()
        sock = zappy_connection.Socket("127.0.0.1", srv.getsockname()[1], "lol")
        accept.join()
        print(shared)
        recv = Process(target=str_process, args=(shared['client'].recv, shared, (1024,)))
        recv.start()
        sock.prepare_to_send("lol")
        sock.send_data()
        recv.join()
        assert shared['string'].decode('utf-8') == "lol\n"
