/*
** exec_forward.c for psu_zappy in /home/baldas/Prog/repos/tek2/psu/PSU_2016_zappy/server/src/commands
**
** Made by Hugo Baldassin
** Login   <baldas@epitech.net>
**
** Started on  Thu Jun 22 14:14:47 2017 Hugo Baldassin
** Last update Thu Jun 22 14:14:47 2017 Hugo Baldassin
*/

#include 	"commands.h"
#include 	"utils.h"

void 		move_player_forward(t_player *player, t_map *map)
{
  if (player->dir == DIR_UP)
    player->pos.y--;
  else if (player->dir == DIR_DOWN)
    player->pos.y++;
  else if (player->dir == DIR_RIGHT)
    player->pos.x++;
  else if (player->dir == DIR_LEFT)
    player->pos.x--;
  if (player->pos.x < 0)
    player->pos.x = map->width - 1;
  else if (player->pos.x > (map->width - 1))
    player->pos.x = 0;
  else if (player->pos.y < 0)
    player->pos.y = map->height - 1;
  else if (player->pos.y > (map->height - 1))
    player->pos.y = 0;
}

void		exec_forward(t_player *player, t_map *map)
{
  t_list_item	*players;
  t_list_item	*tmp;
  int		idx;
  int		new_idx;

  idx = GET_INDEX(player->pos.x, player->pos.y, map->width);
  move_player_forward(player, map);
  new_idx = GET_INDEX(player->pos.x, player->pos.y, map->width);
  players = map->tiles[idx].players.first;
  while (players && (t_player *)players->data != player)
    players = players->next;
  if (players)
    {
      tmp = list_extract(&map->tiles[idx].players, players);
      list_pushback_item(&map->tiles[new_idx].players, tmp);
      send_data(player->net->output, "ok\n");
    }
}