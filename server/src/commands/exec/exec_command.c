/*
** exec_command.c for psu_zappy in /home/baldas/Prog/repos/tek2/psu/PSU_2016_zappy/server/src
**
** Made by Hugo Baldassin
** Login   <baldas@epitech.net>
**
** Started on  Wed Jun 21 18:06:51 2017 Hugo Baldassin
** Last update Wed Jun 21 18:13:11 2017 Hugo Baldassin
*/

#include 	"commands.h"

void 		exec_command(t_player *player, t_map *map)
{
  static void   (*exec_funcs[13])(t_player *_player, t_map *_map) =
    {
      exec_forward,
      exec_right,
      exec_left,
      exec_look,
      exec_inventory,
      exec_broadcast,
      exec_connect_nbr,
      exec_fork,
      exec_eject,
      exec_take,
      exec_set,
      exec_check_incantation,
      exec_incantation
    };

  if (player->cmd_list->type == UNDEF)
    circbuffer_append(player->net->output, "ko\n");
  else
    exec_funcs[player->cmd_list->type](player, map);
}
