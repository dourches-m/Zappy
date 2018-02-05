/*
** write_to.c for zappy in /home/anthony/repository/zappy/write_to.c
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.eu>
**
** Started on  jeu. juin 29 13:30:06 2017 Anthony LECLERC
** Last update jeu. juin 29 13:30:06 2017 Anthony LECLERC
*/

#include 		"client.h"

int			write_to_player(t_client *self)
{
  char		 	*buffer;
  size_t 		size;
  ssize_t	 	send;

  buffer = circbuffer_front(self->output, &size);
  assert(buffer != NULL);
  send = tcp_send(&self->socket, buffer, size);
  if (send == -1)
    return (-1);
  circbuffer_discard(self->output, (size_t)send);
  if (self->player == NULL)
    return (-1);
  return (0);
}