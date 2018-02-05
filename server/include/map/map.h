/*
** map.h for zappy in /home/anthony/repository/zappy/map.h
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.eu>
**
** Started on  mar. juin 20 18:54:35 2017 Anthony LECLERC
** Last update mar. juin 20 18:54:35 2017 Anthony LECLERC
*/

#ifndef 		MAP_H_
# define 		MAP_H_

#include 		<stdint.h>
#include 		"list/list.h"

typedef struct		s_tile
{
  uint16_t		linemate;
  uint16_t		deraumere;
  uint16_t		sibur;
  uint16_t		mendiane;
  uint16_t		phiras;
  uint16_t		thystame;
  uint16_t		food;
  t_list		players;
}			t_tile;

typedef struct		s_map
{
  int32_t		width;
  int32_t		height;
  t_list		*eggs;
  t_list		*players;
  t_tile		tiles[];
}			t_map;

# define		MAP_POS(map, x, y) ((x) + (y) * map->width)

t_map			*create_map(int32_t width, int32_t height);

void			generate_map(t_map *map);

void 			consume_items(t_tile *tile, t_map *map);

#endif 			/* MAP_H_ */
