/*
** write_to.c for zappy in /home/anthony/repository/zappy/write_to.c
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.eu>
**
** Started on  jeu. juin 29 03:21:35 2017 Anthony LECLERC
** Last update jeu. juin 29 03:21:35 2017 Anthony LECLERC
*/

#include	<string.h>
#include	"debug.h"
#include	"serverinfo.h"

int		write_to_client(t_client *client)
{
  char		*buffer;
  size_t	size;
  ssize_t	send;

  buffer = circbuffer_front(client->output, &size);
  assert(buffer != NULL);
  send = tcp_send(&client->socket, buffer, size);
  if (send == -1)
    return (-1);
  circbuffer_discard(client->output, (size_t)send);
  return (0);
}

int		msg_client(t_sockselector *select, t_client *client,
                              char const *msg)
{
  circbuffer_append(client->output, msg);
  select_add(select, &client->socket.socket, WRITE_SELECT);
  return (0);
}