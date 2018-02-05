/*
** try_register.c for zappy in /home/anthony/repository/zappy/try_register.c
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.eu>
**
** Started on  ven. juin 23 11:53:20 2017 Anthony LECLERC
** Last update Fri Jun 30 14:22:05 2017 Hugo Baldassin
*/

#include		<stdio.h>
#include		<stdlib.h>
#include		"debug.h"
#include		"utils.h"
#include		"graphic.h"
#include		"serverinfo.h"

int			try_register(t_zserver *server, t_client *client)
{
  char			*line;
  size_t		size;

  if (circbuffer_has_newline(client->input, "\n"))
  {
    line = circbuffer_get_newline(client->input, &size, "\n");
    if (register_player(server, client, line) != 0)
    {
      if (register_graphic(server, client, line) != 0)
        msg_client(&server->selector, client, "ko\n");
    }
    free(line);
  }
  return (0);
}
