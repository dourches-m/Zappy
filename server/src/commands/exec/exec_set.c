/*
** exec_set.c for psu_zappy in /home/baldas/Prog/repos/tek2/psu/PSU_2016_zappy/server/src/commands
**
** Made by Hugo Baldassin
** Login   <baldas@epitech.net>
**
** Started on  Thu Jun 22 14:16:06 2017 Hugo Baldassin
** Last update Thu Jun 22 14:16:06 2017 Hugo Baldassin
*/

#include 	"commands.h"
#include 	"utils.h"

void 		validate_set(t_player *player, uint16_t *item_qty,
			     t_item_type type)
{
  assert(item_qty != NULL);
  if (player->inventory[type].nb == 0)
    send_data(player->net->output, "ko\n");
  else
    {
      *item_qty += 1;
      player->inventory[type].nb--;
      send_data(player->net->output, "ok\n");
    }
}

void 		set_object(t_player *player, t_map *map, t_item_type type)
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
  validate_set(player, item_qty, type);
}

void		exec_set(t_player *player, t_map *map)
{
  t_item_type	type;

  if (player->cmd_list->arg)
    {
      type = is_an_item(player->cmd_list->arg);
      if (type == NONE || !player->inventory[type].nb)
	send_data(player->net->output, "ko\n");
      else
	set_object(player, map, type);
    }
  else
    send_data(player->net->output, "ko\n");
}
