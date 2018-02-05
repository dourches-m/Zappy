/*
** Socket.c for PSU_2016_myftp in /home/anthony/repository/PSU_2016_myftp/Socket.c
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.eu>
**
** Started on  mar. mai 09 19:20:54 2017 Anthony LECLERC
** Last update Sun Jul  2 19:51:15 2017 Anthony LECLERC
*/

#include		<stdlib.h>
#include		"socket/Socket.h"

bool			new_socket(t_socket *sock, int domain, int type)
{
  if (sock != NULL)
    {
      sock->fd = INV_SOCKET;
      if (open_socket(sock, domain, type) == false)
	return (false);
    }
  return (true);
}

void			destruct_socket(t_socket *self)
{
  if (self != NULL && self->fd != INV_SOCKET)
    {
      close_socket(self);
    }
}
