/*
** get_remote_address.c for PSU_2016_myftp in /home/anthony/repository/PSU_2016_myftp/get_remote_address.c
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.eu>
**
** Started on  jeu. mai 18 10:44:06 2017 Anthony LECLERC
** Last update Sun Jul  2 19:44:02 2017 Anthony LECLERC
*/

#include		<arpa/inet.h>
#include		"socket/Socket.h"
#include		"socket/TcpSocket.h"

char const		*get_remote_saddr(t_socket *sock)
{
  struct sockaddr_in    addr;
  socklen_t		addrlen;

  if (sock != NULL && sock->fd != INV_SOCKET)
    {
      addrlen = sizeof(addr);
      if (getpeername(sock->fd, (struct sockaddr *)&addr,
		      &addrlen) != -1)
	return (inet_ntoa(addr.sin_addr));
    }
  return (NULL);
}

uint32_t                get_remote_addr(t_socket *sock)
{
  struct sockaddr_in    addr;
  socklen_t		addrlen;

  if (sock != NULL && sock->fd != INV_SOCKET)
    {
      addrlen = sizeof(addr);
      if (getpeername(sock->fd, (struct sockaddr *)&addr,
		      &addrlen) != -1)
	return (ntohl(addr.sin_addr.s_addr));
    }
  return ((uint32_t)-1);
}

uint16_t                get_remote_port(t_socket *sock)
{
  struct sockaddr_in    addr;
  socklen_t		addrlen;

  if (sock != NULL && sock->fd != INV_SOCKET)
    {
      addrlen = sizeof(addr);
      if (getpeername(sock->fd, (struct sockaddr *)&addr,
		      &addrlen) != -1)
	return (ntohs(addr.sin_port));
    }
  return (0);
}
