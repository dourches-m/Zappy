/*
** exec_eject.c for psu_zappy in /home/baldas/Prog/repos/tek2/psu/PSU_2016_zappy/server/src/commands
**
** Made by Hugo Baldassin
** Login   <baldas@epitech.net>
**
** Started on  Thu Jun 22 14:14:20 2017 Hugo Baldassin
** Last update Fri Jun 30 13:20:21 2017 Hugo Baldassin
*/

#include 	<memory.h>

#include 	"commands.h"
#include 	"utils.h"
#include 	"pos.h"

void 		send_push_message(t_player *player, t_player *pusher)
{
  t_direction 	dir;

  dir = ABS((int)pusher->dir - (int)player->dir);
  if (player->net && dir == DIR_UP)
    send_data(player->net->output, "eject 5");
  else if (player->net && dir == DIR_LEFT)
    send_data(player->net->output, "eject 3");
  else if (player->net && dir == DIR_RIGHT)
    send_data(player->net->output, "eject 7");
  else if (player->net && dir == DIR_DOWN)
    send_data(player->net->output, "eject 1");
}

void 		push_player(t_player *player, t_map *map, t_direction dir)
{
  if (dir == DIR_UP)
    player->pos.y--;
  else if (dir == DIR_DOWN)
    player->pos.y++;
  else if (dir == DIR_RIGHT)
    player->pos.x++;
  else if (dir == DIR_LEFT)
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

void 		move_players(t_list *list, t_map *map, t_player *pusher)
{
  t_list_item	*players;
  t_list_item	*tmp;
  t_player	*player;
  int 		new_idx;

  players = list->first;
  while (players)
    {
      player = (t_player *)players->data;
      if (player == pusher)
	players = players->next;
      if (players)
	{
	  player = (t_player *)players->data;
	  send_push_message(player, pusher);
	  new_idx = GET_INDEX(player->pos.x, player->pos.y, map->width);
	  tmp = players;
	  players = players->next;
	  tmp = list_extract(list, tmp);
	  memcpy(tmp, tmp, sizeof(t_list_item));
	  list_pushback_item(&map->tiles[new_idx].players, tmp);
	}
    }
}

void		exec_eject(t_player *player, t_map *map)
{
  t_list_item	*tmp;
  int 		idx;

  idx = GET_INDEX((player->pos.x), (player->pos.y), map->width);
  if (map->tiles[idx].players.size <= 1)
    send_data(player->net->output, "ko\n");
  else
    {
      tmp = map->tiles[idx].players.first;
      while (tmp)
	{
	  if ((t_player*)(tmp->data) != player)
	    push_player((t_player*)(tmp->data), map, player->dir);
	  tmp = tmp->next;
	}
      move_players(&map->tiles[idx].players, map, player);
      send_data(player->net->output, "ok\n");
    }
}
