/*
** exec_right.c for psu_zappy in /home/baldas/Prog/repos/tek2/psu/PSU_2016_zappy/server/src/commands
**
** Made by Hugo Baldassin
** Login   <baldas@epitech.net>
**
** Started on  Thu Jun 22 14:15:56 2017 Hugo Baldassin
** Last update Thu Jun 22 14:15:57 2017 Hugo Baldassin
*/

#include 	"commands.h"
#include 	"utils.h"

void		exec_right(t_player *player, t_map *map)
{
  (void)map;
  player->dir = (player->dir == DIR_LEFT) ? DIR_UP : player->dir + 1;
  send_data(player->net->output, "ok\n");
}