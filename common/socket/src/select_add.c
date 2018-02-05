/*
** select_add.c for PSU_2016_myirc in /home/anthony/repository/PSU_2016_myirc/select_add.c
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.eu>
**
** Started on  lun. mai 22 23:45:03 2017 Anthony LECLERC
** Last update Sun Jul  2 19:45:04 2017 Anthony LECLERC
*/

#include	"socket/SocketSelector.h"

void		select_add(t_sockselector *self, t_socket *sock,
			   t_select_type type)
{
  if (sock->fd != INV_SOCKET)
    {
      self->count = (sock->fd > self->count) ? sock->fd : self->count;
      if (type & READ_SELECT)
        FD_SET(sock->fd, &self->all[READ_SET]);
      if (type & WRITE_SELECT)
        FD_SET(sock->fd, &self->all[WRITE_SET]);
      if (type & EXCEPT_SELECT)
        FD_SET(sock->fd, &self->all[EXCEPT_SET]);
    }
}
