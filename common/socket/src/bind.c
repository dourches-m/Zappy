/*
** bind.c for PSU_2016_myftp in /home/anthony/repository/PSU_2016_myftp/bind.c
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.eu>
**
** Started on  mer. mai 10 09:56:09 2017 Anthony LECLERC
** Last update Sun Jul  2 19:42:57 2017 Anthony LECLERC
*/

#include	<string.h>
#include	<errno.h>
#include	<err.h>
#include	"socket/TcpListener.h"

bool		tcp_bind(t_tcplistener *self,
			 char const *ip,
			 uint16_t port)
{
  if (self != NULL && self->socket.fd != INV_SOCKET)
    {
      if (set_inet_addr(&self->socket, ip, port) == false)
	return (false);
      if (bind(self->socket.fd, (const struct sockaddr *)&self->socket.infos,
	       sizeof(self->socket.infos)) == -1)
	{
	  self->socket.sock_err = errno;
	  warn("tcp bind failed: on ip %s and port %hu ", ip, port);
	  return (false);
	}
      return (true);
    }
  return (false);
}
