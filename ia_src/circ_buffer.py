from collections import deque


class CharCircBuffer():
    def __init__(self):
        self.buf = deque([])

    def __len__(self):
        return len(self.buf)

    def append(self, data):
        if len(data) > 0 and data[-1] != "\n":
            data += "\n"
        for each in str(data):
            self.buf.append(each)

    def append_left(self, data):
        if data[-1] != '\n':
            data += "\n"
        for each in str(data)[::-1]:
            self.buf.appendleft(each)

    def pop(self, sep='\n'):
        if self.buf.count(sep) == 0:
            return ""
        data = []
        byte = ""
        while byte != sep:
            byte = self.buf.popleft()
            data.append(byte)
        return "".join(data[:-1])

    def elements(self):
        return self.buf.count('\n')
