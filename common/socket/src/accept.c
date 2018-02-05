/*
** accept.c for PSU_2016_myftp in /home/anthony/repository/PSU_2016_myftp/accept.c
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.eu>
**
** Started on  mer. mai 10 10:00:06 2017 Anthony LECLERC
** Last update Sun Jul  2 19:42:32 2017 Anthony LECLERC
*/

#include		<stddef.h>
#include		<netinet/in.h>
#include		<errno.h>
#include		<err.h>
#include		<string.h>
#include		"socket/TcpListener.h"

bool			tcp_accept(t_tcplistener *self, t_socket *sock)
{
  socklen_t 		addr_len;
  int			clientfd;

  if (self != NULL && sock != NULL)
    {
      addr_len = sizeof(struct sockaddr_in);
      clientfd = accept(self->socket.fd, (struct sockaddr *)&sock->infos,
			&addr_len);
      if (clientfd == INV_SOCKET)
	{
	  self->socket.sock_err = errno;
	  warn("tcp accept failed: port %hu ",
	       ntohs(self->socket.infos.sin_port));
	  return (false);
	}
      if (sock->fd != INV_SOCKET)
	close_socket(sock);
      sock->fd = clientfd;
      return (true);
    }
  return (false);
}
