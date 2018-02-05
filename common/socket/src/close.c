/*
** close.c for PSU_2016_myftp in /home/anthony/repository/PSU_2016_myftp/close.c
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.eu>
**
** Started on  mar. mai 09 20:16:35 2017 Anthony LECLERC
** Last update Sun Jul  2 19:48:32 2017 Anthony LECLERC
*/

#include	<unistd.h>
#include	"socket/Socket.h"

void		close_socket(t_socket *self)
{
  if (self->fd != INV_SOCKET)
    {
      close(self->fd);
      self->fd = INV_SOCKET;
    }
}
