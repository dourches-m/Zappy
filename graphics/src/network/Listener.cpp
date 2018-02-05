/*
** Listener.cpp for zappy in /home/sylvain/Documents/projets/tek2/PSU/PSU_2016_zappy/graphic_client
**
** Made by Sylvain Chaugny
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Sun Jun 25 18:13:29 2017 Sylvain Chaugny
// Last update Sun Jul  2 20:39:31 2017 Sylvain Chaugny
*/

#include		"network/Listener.hpp"
#include		"network/NetworkWrapper.hpp"

zappy::network::Listener::Listener()
{
  NetworkWrapper::_FD_ZERO(&_set);
}

zappy::network::Listener::~Listener()
{
}

void			zappy::network::Listener::init(Socket const &sock, ssize_t timeout)
{
  _timeout = timeout;
  _fd = sock.getFd();
  NetworkWrapper::_FD_SET(_fd, &_set);
}

bool			zappy::network::Listener::isSet()
{
  return NetworkWrapper::_FD_ISSET(_fd, &_set_ready);
}

int			zappy::network::Listener::isRunning()
{
  struct timeval	time;

  time.tv_sec = _timeout / 1000000;
  time.tv_usec = _timeout % 1000000;
  _set_ready = _set;
  return NetworkWrapper::select(_fd + 1, &_set_ready, NULL, NULL, &time);
}

void			zappy::network::Listener::bufferize()
{
  std::vector<char>	buf;
  std::vector<char>	tmp;
  int			read;
  std::string		welcome;

  _buffer.getData().clear();
  _buffer.setOffBegin(0);
  buf.resize(1024);
  buf.clear();
  while ((read = NetworkWrapper::recv(_fd, buf.data(), 1024)) > 0)
    {
      tmp.clear();
      tmp.insert(tmp.begin(), buf.begin(), buf.begin() + read);
      _buffer.addData(tmp);
      if (read == 8 && std::string(_buffer.getData().data()).substr(0, 8) == "WELCOME\n")
	return ;
      buf.clear();
    }
}

zappy::utl::Buffer	&zappy::network::Listener::getBuffer()
{
  return _buffer;
}

void			zappy::network::Listener::replyToWelcome()
{
  std::string		str("GRAPHIC");

  NetworkWrapper::send(_fd, str.c_str(), str.length());
}
