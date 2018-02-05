/*
** exec_left.c for psu_zappy in /home/baldas/Prog/repos/tek2/psu/PSU_2016_zappy/server/src/commands
**
** Made by Hugo Baldassin
** Login   <baldas@epitech.net>
**
** Started on  Thu Jun 22 14:15:30 2017 Hugo Baldassin
** Last update Thu Jun 22 14:15:30 2017 Hugo Baldassin
*/

#include 	"commands.h"
#include 	"utils.h"

void		exec_left(t_player *player, t_map *map)
{
  (void)map;
  player->dir = (player->dir == DIR_UP) ? DIR_LEFT : player->dir - 1;
  send_data(player->net->output, "ok\n");
}
