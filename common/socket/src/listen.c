/*
** listen.c for PSU_2016_myftp in /home/anthony/repository/PSU_2016_myftp/listen.c
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.eu>
**
** Started on  mer. mai 10 10:01:02 2017 Anthony LECLERC
** Last update Sun Jul  2 19:44:20 2017 Anthony LECLERC
*/

#include	<err.h>
#include	<errno.h>
#include	<netinet/in.h>
#include	"socket/TcpListener.h"

bool		tcp_listen(t_tcplistener *self, int queuesize)
{
  if (self != NULL && self->socket.fd != INV_SOCKET)
    {
      if (listen(self->socket.fd, queuesize) == -1)
	{
	  self->socket.sock_err = errno;
	  warn("tcp listen failed: on port %hd ",
	       ((struct sockaddr_in *)&self->socket.infos)->sin_port);
	  return (false);
	}
      return (true);
    }
  return (false);
}
