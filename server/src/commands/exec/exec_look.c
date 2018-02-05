/*
** exec_look.c for psu_zappy in /home/baldas/Prog/repos/tek2/psu/PSU_2016_zappy/server/src/commands
**
** Made by Hugo Baldassin
** Login   <baldas@epitech.net>
**
** Started on  Thu Jun 22 14:15:42 2017 Hugo Baldassin
** Last update Tue Jun 27 00:12:27 2017 Hugo Baldassin
*/

#include 	<stdlib.h>
#include 	<string.h>

#include 	"commands.h"
#include 	"utils.h"

void 		get_players(t_list_item *list, char **reply)
{
  t_list_item	*players;

  players = list;
  while (players)
    {
      if ((*reply)[strlen(*reply) - 1] != '[')
        (*reply) = concat_strings(*reply, "player", " ");
      else
        (*reply) = concat_strings(*reply, "player", "");
      players = players->next;
    }
}

void 		get_item(char **reply, char *name, int nb)
{
  while (nb)
    {
      if ((*reply)[strlen(*reply) - 1] != '[')
        (*reply) = concat_strings((*reply), name, " ");
      else
        (*reply) = concat_strings((*reply), name, "");
      nb--;
    }
}

void 		get_items(t_tile *tile, char **reply)
{
  get_item(reply, "thystame", tile->thystame);
  get_item(reply, "sibur", tile->sibur);
  get_item(reply, "phiras", tile->phiras);
  get_item(reply, "deraumere", tile->deraumere);
  get_item(reply, "mendiane", tile->mendiane);
  get_item(reply, "linemate", tile->linemate);
  get_item(reply, "food", tile->food);
}

void 		get_tile_content(t_map *map, t_pos *pos, char **reply)
{
  t_pos		real_pos;
  int 		idx;

  real_pos.x = pos->x;
  real_pos.y = pos->y;
  convert_to_real_pos(&real_pos, map);
  idx = GET_INDEX(real_pos.x, real_pos.y, map->width);
  get_players(map->tiles[idx].players.first, reply);
  get_items(&map->tiles[idx], reply);
  (*reply) = concat_strings((*reply), "", ",");
}

void		exec_look(t_player *player, t_map *map)
{
  char 		*reply;

  reply = mstrdup("[");
  if (player->dir == DIR_DOWN)
    look_down(player, map, &reply);
  else if (player->dir == DIR_UP)
    look_up(player, map, &reply);
  else if (player->dir == DIR_LEFT)
    look_left(player, map, &reply);
  else if (player->dir == DIR_RIGHT)
    look_right(player, map, &reply);
  reply[strlen(reply) - 1] = ']';
  reply = concat_strings(reply, "\n", "");
  send_data(player->net->output, reply);
  free(reply);
}
