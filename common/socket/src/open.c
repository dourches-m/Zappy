/*
** open.c for PSU_2016_myftp in /home/anthony/repository/PSU_2016_myftp/open.c
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.eu>
**
** Started on  mar. mai 09 20:05:18 2017 Anthony LECLERC
** Last update Sun Jul  2 19:49:36 2017 Anthony LECLERC
*/

#include		<sys/socket.h>
#include		<errno.h>
#include		<err.h>
#include		"socket/Socket.h"

bool			open_socket(t_socket *self, int domain, int type)
{
  if (self != NULL)
    {
      if (self->fd != INV_SOCKET)
	close_socket(self);
      self->fd = socket(domain, type, 0);
      if (self->fd == INV_SOCKET)
	{
	  self->sock_err = errno;
	  warn("open socket failed. Domain: %d - Type: %d ", domain, type);
	  return (false);
	}
    }
  return (true);
}
