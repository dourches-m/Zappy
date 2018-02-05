/*
** NetworkWrapper.cpp for zappy in /home/sylvain/Documents/projets/tek2/PSU/PSU_2016_zappy/graphic_client
**
** Made by Sylvain Chaugny
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Thu Jun 22 20:00:23 2017 Sylvain Chaugny
// Last update Sun Jul  2 08:14:04 2017 Sylvain Chaugny
*/

#include		<fcntl.h>
#include		<netdb.h>
#include		<arpa/inet.h>
#include		"network/NetworkWrapper.hpp"
#include		"utl/CWrapper.hpp"

zappy::network::NetworkWrapper::NetworkWrapper()
{
}

zappy::network::NetworkWrapper::~NetworkWrapper()
{
}

int			zappy::network::NetworkWrapper::inet_pton(int af, const char *src, char *dst)
{
  return ::inet_pton(af, src, dst);
}

struct protoent		*zappy::network::NetworkWrapper::getprotobyname(const char *name)
{
  return ::getprotobyname(name);
}

int			zappy::network::NetworkWrapper::socket(int domain, int type, int protocol)
{
  return ::socket(domain, type, protocol);
}

int			zappy::network::NetworkWrapper::connect(int sockfd, struct sockaddr *addr, socklen_t addrlen)
{
  return ::connect(sockfd, addr, addrlen);
}

int			zappy::network::NetworkWrapper::htons(int port)
{
  return ::htons(port);
}

int			zappy::network::NetworkWrapper::inet_addr(const char *addr)
{
  return ::inet_addr(addr);
}

void			zappy::network::NetworkWrapper::_FD_ZERO(fd_set *set)
{
  FD_ZERO(set);
}

void			zappy::network::NetworkWrapper::_FD_SET(int fd, fd_set *set)
{
  FD_SET(fd, set);
}

int			zappy::network::NetworkWrapper::_FD_ISSET(int fd, fd_set *set)
{
  return FD_ISSET(fd, set);
}

int			zappy::network::NetworkWrapper::select(int nfds,
							       fd_set *read,
							       fd_set *write,
							       fd_set *err,
							       struct timeval *timeout)
{
  return ::select(nfds, read, write, err, timeout);
}

int			zappy::network::NetworkWrapper::close(int fd)
{
  return utl::CWrapper::close(fd);
}

int			zappy::network::NetworkWrapper::recv(int fd, void *buf, int length, int flags)
{
  return ::recv(fd, buf, length, flags);
}

int			zappy::network::NetworkWrapper::send(int fd, const void *buf, int length, int flags)
{
  return ::send(fd, buf, length, flags);
}

int			zappy::network::NetworkWrapper::fcntl(int fd, int cmd, int flags)
{
  return ::fcntl(fd, cmd, flags);
}
