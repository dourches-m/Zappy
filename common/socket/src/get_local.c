/*
** get_local.c for PSU_2016_myftp in /home/anthony/repository/PSU_2016_myftp/get_local.c
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.eu>
**
** Started on  ven. mai 19 06:33:24 2017 Anthony LECLERC
** Last update Sun Jul  2 19:48:56 2017 Anthony LECLERC
*/

#include		<arpa/inet.h>
#include		"socket/TcpSocket.h"

char const		*get_local_saddr(t_socket *sock)
{
  struct sockaddr_in	addr;
  socklen_t		addrlen;

  if (sock != NULL && sock->fd != INV_SOCKET)
    {
      addrlen = sizeof(addr);
      if (getsockname(sock->fd, (struct sockaddr *)&addr,
		      &addrlen) != -1)
	{
	  return (inet_ntoa(addr.sin_addr));
	}
    }
  return (0);
}

uint32_t		get_local_addr(t_socket *sock)
{
  struct sockaddr_in	addr;
  socklen_t		addrlen;

  if (sock != NULL && sock->fd != INV_SOCKET)
    {
      addrlen = sizeof(addr);
      if (getsockname(sock->fd, (struct sockaddr *)&addr,
		      &addrlen) != -1)
	{
	  return (ntohl(addr.sin_addr.s_addr));
	}
    }
  return (0);
}

uint16_t		get_local_port(t_socket *sock)
{
  struct sockaddr_in	addr;
  socklen_t		addrlen;

  if (sock != NULL && sock->fd != INV_SOCKET)
    {
      addrlen = sizeof(addr);
      if (getsockname(sock->fd, (struct sockaddr *)&addr,
		      &addrlen) != -1)
	{
	  return (ntohs(addr.sin_port));
	}
    }
  return (0);
}
