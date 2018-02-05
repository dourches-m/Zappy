/*
** exec_connect_nbr.c for psu_zappy in /home/baldas/Prog/repos/tek2/psu/PSU_2016_zappy/server/src/commands
**
** Made by Hugo Baldassin
** Login   <baldas@epitech.net>
**
** Started on  Thu Jun 22 14:14:11 2017 Hugo Baldassin
** Last update Fri Jun 30 13:14:12 2017 Hugo Baldassin
*/

#include 	<string.h>
#include 	<stdio.h>
#include 	<stdlib.h>
#include 	"commands.h"
#include 	"utils.h"

void		exec_connect_nbr(t_player *player, t_map *map)
{
  char 		*reply;

  (void)map;
  if (player->team)
    {
      reply = myalloc(nb_len(player->team->slots -
			     player->team->nb_players) + 2);
      sprintf(reply, "%d\n", player->team->slots - player->team->nb_players);
      send_data(player->net->output, reply);
      free(reply);
    }
  else
    send_data(player->net->output, "0\n");
}
