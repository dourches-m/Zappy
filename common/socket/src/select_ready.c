/*
** select_ready.c for PSU_2016_myirc in /home/anthony/repository/PSU_2016_myirc/select_ready.c
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.eu>
**
** Started on  mar. mai 23 04:39:50 2017 Anthony LECLERC
** Last update Sun Jul  2 19:45:29 2017 Anthony LECLERC
*/

#include	<stdio.h>
#include	"socket/SocketSelector.h"

bool		select_ready(t_sockselector *self, t_socket *sock,
			     t_select_set type)
{
  if (type < MAX_SET && sock->fd != INV_SOCKET)
    {
      if (FD_ISSET(sock->fd, &self->ready[type]) != 0)
	return (true);
      return (false);
    }
  return (false);
}
