/*
** read_data.c for zappy in /home/anthony/repository/zappy/read_data.c
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.eu>
**
** Started on  ven. juin 23 11:57:52 2017 Anthony LECLERC
** Last update Sun Jul  2 19:17:12 2017 Hugo Baldassin
*/

#include 		"client.h"

int			read_unregister(t_client *self)
{
  char			*buffer;
  size_t		reserved;
  ssize_t		data;

  buffer = circbuffer_reserve(self->input, self->input->size, &reserved);
  data = tcp_receive(&self->socket, buffer, reserved);
  if (data <= 0)
    return (1);
  circbuffer_push(self->input, (size_t)data);
  return (0);
}

int			read_graphics(t_client *self)
{
  char			*buffer;
  size_t		reserved;
  ssize_t		data;

  buffer = circbuffer_reserve(self->input, 128, &reserved);
  data = tcp_receive(&self->socket, buffer, reserved);
  if (data <= 0)
    return (1);
  circbuffer_push(self->input, (size_t)data);
  return (0);
}
