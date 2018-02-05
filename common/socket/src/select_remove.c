/*
** select_remove.c for PSU_2016_myirc in /home/anthony/repository/PSU_2016_myirc/select_remove.c
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.eu>
**
** Started on  lun. mai 22 23:49:32 2017 Anthony LECLERC
** Last update Sun Jul  2 19:50:39 2017 Anthony LECLERC
*/

#include	"socket/SocketSelector.h"

void		select_remove(t_sockselector *self, t_socket *sock)
{
  if (sock->fd != INV_SOCKET)
    {
      FD_CLR(sock->fd, &self->all[READ_SET]);
      FD_CLR(sock->fd, &self->all[WRITE_SET]);
      FD_CLR(sock->fd, &self->all[EXCEPT_SET]);
      FD_CLR(sock->fd, &self->ready[WRITE_SET]);
      FD_CLR(sock->fd, &self->ready[READ_SET]);
      FD_CLR(sock->fd, &self->ready[EXCEPT_SET]);
    }
}
