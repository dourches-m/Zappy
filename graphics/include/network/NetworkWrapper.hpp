/*
** NetworkWrapper.hpp for zappy in /home/sylvain/Documents/projets/tek2/PSU/PSU_2016_zappy/graphic_client/include
**
** Made by Sylvain Chaugny
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Thu Jun 22 19:57:26 2017 Sylvain Chaugny
// Last update Sun Jul  2 08:12:43 2017 Sylvain Chaugny
*/

#ifndef				CPP_ZAPPY_NETWORKWRAPPER_HPP_
# define			CPP_ZAPPY_NETWORKWRAPPER_HPP_

#include			<sys/types.h>
#include			<sys/socket.h>
#include			<sys/select.h>

namespace			zappy
{
  namespace			network
  {
    class			NetworkWrapper
    {
    public:
      NetworkWrapper();
      ~NetworkWrapper();

      static int		inet_pton(int af, const char *src, char *dst);
      static struct protoent	*getprotobyname(const char *name);
      static int		socket(int domain, int type, int protocol);
      static int		connect(int sockfd, struct sockaddr *addr, socklen_t addrlen);
      static int		htons(int port);
      static int		inet_addr(const char *addr);

      static void	        _FD_ZERO(fd_set *set);
      static void		_FD_SET(int fd, fd_set *set);
      static int		_FD_ISSET(int fd, fd_set *set);

      static int		select(int nfds, fd_set *read, fd_set *write, fd_set *err, struct timeval *timeout);

      static int		close(int fd);

      static int		recv(int fd, void *buf, int length, int flags = 0);
      static int		send(int fd, const void *buf, int length, int flags = 0);
      static int		fcntl(int fd, int cmd, int flags);
    };
  };
};

#endif			/* !CPP_ZAPPY_NETWORKWRAPPER_HPP_ */
