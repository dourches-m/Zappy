import circ_buffer
import pytest

class TestBuffer():
    def test_reify(self):
        buf = circ_buffer.CharCircBuffer()
        assert(True)

    def test_append(self):
        buf = circ_buffer.CharCircBuffer()
        buf.append("Hurlutipopogroum\n")
        assert list(buf.buf) == list("Hurlutipopogroum\n")

    def test_append_invalid(self):
        buf = circ_buffer.CharCircBuffer()
        buf.append("Hurlutipopogroum")
        assert list(buf.buf) == list("Hurlutipopogroum\n")

    def test_pop(self):
        buf = circ_buffer.CharCircBuffer()
        buf.append("Hurlutipopogroum\n")
        assert buf.pop() == "Hurlutipopogroum"

    def test_append_left(self):
        buf = circ_buffer.CharCircBuffer()
        buf.append_left("Hurlutipopogroum\n")
        assert list(buf.buf) == list("Hurlutipopogroum\n")
