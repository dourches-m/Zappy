/*
** exec_fork.c for psu_zappy in /home/baldas/Prog/repos/tek2/psu/PSU_2016_zappy/server/src/commands
**
** Made by Hugo Baldassin
** Login   <baldas@epitech.net>
**
** Started on  Thu Jun 22 14:14:34 2017 Hugo Baldassin
** Last update Thu Jun 22 14:14:34 2017 Hugo Baldassin
*/

#include 	<stdlib.h>
#include 	<string.h>

#include 	"commands.h"
#include 	"utils.h"
#include 	"map/egg.h"

void		exec_fork(t_player *player, t_map *map)
{
  (void)map;
  if (player->team)
    {
      send_data(player->net->output, "ok\n");
      spawn_egg(map, player->team, &player->pos);
    }
  else
    send_data(player->net->output, "ko\n");
}