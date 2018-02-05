/*
** inventory_utils.c for psu_zappy in /home/baldas/Prog/repos/tek2/psu/PSU_2016_zappy/server/src
**
** Made by Hugo Baldassin
** Login   <baldas@epitech.net>
**
** Started on  Wed Jun 21 13:04:53 2017 Hugo Baldassin
** Last update Thu Jun 22 19:26:38 2017 Hugo Baldassin
*/

#include 	<string.h>

#include 	"player.h"
#include 	"utils.h"

void		init_inventory(t_item *inventory)
{
  unsigned int	i;

  i = 0;
  while (i < 7)
    {
      inventory[i].nb = 0;
      inventory[i].type = (t_item_type)i;
      i++;
    }
}

void 		edit_item_quantity(t_player *player, t_item_type type,
				   int val)
{
  unsigned int	i;

  i = 0;
  while (i < 7)
    {
      if (player->inventory[i].type == type)
	{
	  player->inventory[i].nb += val;
	  break;
	}
      i++;
    }
}

t_item_type	is_an_item(char *str)
{
  unsigned int	i;
  static char	*items[7] =
    {
      "linemate",
      "deraumere",
      "sibur",
      "mendiane",
      "phiras",
      "thystame",
      "food"
    };

  i = 0;
  while (i < 7)
    {
      if (!strcmp(str, items[i]))
	return ((t_item_type)i);
      i++;
    }
  return (NONE);
}

void 		consume_items(t_tile *tile, t_map *map)
{
  spawn_resource(map, THYSTAME, tile->thystame);
  tile->thystame = 0;
  spawn_resource(map, LINEMATE, tile->linemate);
  tile->linemate = 0;
  spawn_resource(map, PHIRAS, tile->phiras);
  tile->phiras = 0;
  spawn_resource(map, DERAUMERE, tile->deraumere);
  tile->deraumere = 0;
  spawn_resource(map, SIBUR, tile->sibur);
  tile->sibur = 0;
  spawn_resource(map, MENDIANE, tile->mendiane);
  tile->mendiane = 0;
}