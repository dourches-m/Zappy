/*
** Socket.cpp for zappy in /home/sylvain/Documents/projets/tek2/PSU/PSU_2016_zappy/graphic_client
**
** Made by Sylvain Chaugny
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Sun Jun 25 14:29:20 2017 Sylvain Chaugny
** Last update Mon Jun 26 18:47:33 2017 Sylvain Chaugny
*/

#include		<sys/types.h>
#include		<sys/socket.h>
#include		<netdb.h>
#include		"Exceptions.hpp"
#include		"network/NetworkWrapper.hpp"
#include		"utl/CWrapper.hpp"
#include		"network/Socket.hpp"

zappy::network::Socket::Socket(int port, std::string const &addr, std::string const &proto_name) :
  _port(port),
  _addr(addr),
  _proto_name(proto_name),
  _proto(nullptr),
  _s_in(),
  _s_in_size(sizeof(_s_in)),
  _fd(0)
{
}

zappy::network::Socket::Socket(Socket const &ref) :
  _port(ref._port),
  _addr(ref._addr),
  _proto_name(ref._proto_name),
  _proto(ref._proto),
  _s_in(),
  _s_in_size(sizeof(_s_in)),
  _fd(ref._fd)
{
}

zappy::network::Socket	&zappy::network::Socket::operator=(Socket const &ref)
{
  _port = ref._port;
  _addr = ref._addr;
  _proto = ref._proto;
  _proto_name = ref._proto_name;
  _s_in = ref._s_in;
  _s_in_size = sizeof(_s_in);
  _fd = ref._fd;
  return *this;
}

zappy::network::Socket::~Socket()
{
}

void			zappy::network::Socket::init()
{
  _s_in.sin_family = AF_INET;
  _s_in.sin_port = NetworkWrapper::htons(_port);
  _s_in.sin_addr.s_addr = NetworkWrapper::inet_addr(_addr.c_str());
  _proto = NetworkWrapper::getprotobyname(_proto_name.c_str());
  if (!_proto)
    throw exception::NetworkException(utl::CWrapper::strerror());
  _fd = NetworkWrapper::socket(AF_INET, SOCK_STREAM, _proto->p_proto);
  if (_fd <= 0)
    throw exception::NetworkException(utl::CWrapper::strerror());
}

void			zappy::network::Socket::connect()
{
  if (NetworkWrapper::connect(_fd, reinterpret_cast<struct sockaddr *>(&_s_in), _s_in_size))
    throw exception::NetworkException(utl::CWrapper::strerror());
}

void			zappy::network::Socket::close()
{
  if (NetworkWrapper::close(_fd))
    throw exception::NetworkException(utl::CWrapper::strerror());
}
