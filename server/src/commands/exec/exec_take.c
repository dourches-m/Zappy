/*
** exec_take.c for psu_zappy in /home/baldas/Prog/repos/tek2/psu/PSU_2016_zappy/server/src/commands
**
** Made by Hugo Baldassin
** Login   <baldas@epitech.net>
**
** Started on  Thu Jun 22 14:16:16 2017 Hugo Baldassin
** Last update Thu Jun 22 14:16:17 2017 Hugo Baldassin
*/

#include 	"commands.h"
#include 	"utils.h"

void 		validate_take(t_player *player, uint16_t *item_qty,
			      t_item_type type, t_map *map)
{
  assert(item_qty != NULL);
  if (*item_qty == 0)
    send_data(player->net->output, "ko\n");
  else
    {
      *item_qty -= 1;
      if (type == FOOD)
      	spawn_resource(map, type, 1);
      player->inventory[type].nb++;
      send_data(player->net->output, "ok\n");
    }
}

void 		take_object(t_player *player, t_map *map, t_item_type type)
{
  uint16_t 	*item_qty;
  int 		idx;

  item_qty = NULL;
  idx = GET_INDEX((player->pos.x), (player->pos.y), map->width);
  if (type == LINEMATE)
    item_qty = &map->tiles[idx].linemate;
  else if (type == DERAUMERE)
    item_qty = &map->tiles[idx].deraumere;
  else if (type == SIBUR)
    item_qty = &map->tiles[idx].sibur;
  else if (type == MENDIANE)
    item_qty = &map->tiles[idx].mendiane;
  else if (type == PHIRAS)
    item_qty = &map->tiles[idx].phiras;
  else if (type == THYSTAME)
    item_qty = &map->tiles[idx].thystame;
  else if (type == FOOD)
    item_qty = &map->tiles[idx].food;
  validate_take(player, item_qty, type, map);
}

void		exec_take(t_player *player, t_map *map)
{
  t_item_type	type;

  if (player->cmd_list->arg)
    {
      type = is_an_item(player->cmd_list->arg);
      if (type == NONE)
	send_data(player->net->output, "ko\n");
      else
	take_object(player, map, type);
    }
  else
    send_data(player->net->output, "ko\n");
}