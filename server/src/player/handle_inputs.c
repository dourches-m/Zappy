/*
** handle_inputs.c for zappy in /home/anthony/repository/zappy/handle_inputs.c
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.eu>
**
** Started on  mer. juin 28 17:56:18 2017 Anthony LECLERC
** Last update mer. juin 28 17:56:18 2017 Anthony LECLERC
*/

#include 	<stdlib.h>
#include 	<stdio.h>
#include 	"debug.h"
#include	"serverinfo.h"
#include	"frequency.h"

void		get_commands(t_player *player, size_t fq)
{
  char		*line;
  size_t	size;

  if (player->net != NULL)
  {
    while (circbuffer_has_newline(player->net->input, "\n"))
    {
      line = (circbuffer_get_newline(player->net->input, &size, "\n"));
      if (get_nb_commands(player) <= 10)
	add_command(&player->cmd_list, init_command(line, fq));
      free(line);
    }
  }
}

void		handle_inputs(t_zserver *server)
{
  t_list_item	*it;

  verify_clients(server);
  it = server->map->players->first;
  while (it != NULL)
  {
    get_commands(it->data, g_frequency);
    it = it->next;
  }
}