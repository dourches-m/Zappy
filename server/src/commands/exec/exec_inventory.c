/*
** exec_inventory.c for psu_zappy in /home/baldas/Prog/repos/tek2/psu/PSU_2016_zappy/server/src/commands
**
** Made by Hugo Baldassin
** Login   <baldas@epitech.net>
**
** Started on  Thu Jun 22 14:15:02 2017 Hugo Baldassin
** Last update Fri Jun 23 15:41:38 2017 Hugo Baldassin
*/

#include 	<stdlib.h>
#include 	<stdio.h>
#include 	<string.h>

#include 	"commands.h"
#include 	"utils.h"

void		exec_inventory(t_player *player, t_map *map)
{
  char 		*reply;

  (void)map;
  reply = myalloc(512);
  sprintf(reply, "[food %d, linemate %d, deraumere %d, sibur %d, ",
	  player->inventory[6].nb, player->inventory[0].nb,
	  player->inventory[1].nb, player->inventory[2].nb);
  sprintf(reply + strlen(reply), "mendiane %d, phiras %d, thystame %d]\n",
	  player->inventory[3].nb, player->inventory[4].nb,
	  player->inventory[5].nb);
  send_data(player->net->output, reply);
  free(reply);
}
