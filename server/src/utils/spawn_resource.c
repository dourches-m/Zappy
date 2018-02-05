/*
** spawn_resource.c for psu_zappy in /home/baldas/Prog/repos/tek2/psu/PSU_2016_zappy/server
**
** Made by Hugo Baldassin
** Login   <baldas@epitech.net>
**
** Started on  Fri Jun 30 22:48:11 2017 Hugo Baldassin
** Last update Fri Jun 30 22:48:12 2017 Hugo Baldassin
*/

#include 	<stdlib.h>

#include 	"map/map.h"
#include 	"item_type.h"
#include 	"pos.h"

void		spawn_resource(t_map *map, t_item_type type, int quantity)
{
  int 		x;
  int 		y;
  int 		idx;

  while (quantity)
    {
      x = rand() % map->width;
      y = rand() % map->height;
      idx = GET_INDEX(x, y, map->width);
      if (type == LINEMATE)
	map->tiles[idx].linemate += 1;
      else if (type == DERAUMERE)
	map->tiles[idx].deraumere += 1;
      else if (type == SIBUR)
	map->tiles[idx].sibur += 1;
      else if (type == PHIRAS)
	map->tiles[idx].phiras += 1;
      else if (type == THYSTAME)
	map->tiles[idx].thystame += 1;
      else if (type == MENDIANE)
	map->tiles[idx].mendiane += 1;
      else if (type == FOOD)
	map->tiles[idx].food += 1;
      quantity--;
    }
}