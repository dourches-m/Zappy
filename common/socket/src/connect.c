/*
** connect.c for PSU_2016_myftp in /home/anthony/repository/PSU_2016_myftp/connect.c
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.eu>
**
** Started on  mer. mai 10 09:55:00 2017 Anthony LECLERC
** Last update Sun Jul  2 19:43:27 2017 Anthony LECLERC
*/

#include	<netinet/in.h>
#include	<errno.h>
#include	<err.h>
#include	"socket/TcpSocket.h"

bool		tcp_connect(t_tcpsocket *self,
			    char const *ip,
			    uint16_t port)
{
  if (self != NULL && self->socket.fd != INV_SOCKET)
    {
      if (set_inet_addr(&self->socket, ip, port) == false)
	return (false);
      if (connect(self->socket.fd, (struct sockaddr *)&self->socket.infos,
		  sizeof(struct sockaddr_in)) == -1)
	{
	  self->socket.sock_err = errno;
	  warn("Tcp connect failed: IP %s - port %hu ", ip, port);
	  return (false);
	}
      return (true);
    }
  return (false);
}
