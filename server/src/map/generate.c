/*
** generate.c for zappy in /home/anthony/repository/zappy/generate.c
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.eu>
**
** Started on  mar. juin 20 21:57:17 2017 Anthony LECLERC
** Last update mar. juin 20 21:57:17 2017 Anthony LECLERC
*/

#include 	<stdlib.h>
#include 	<assert.h>
#include 	<stdio.h>
#include 	<string.h>
#include	"map/map.h"

uint16_t	generate_ressource(int prob, int quantity)
{
  uint16_t	value;

  value = 0;
  if (rand() % 100 < prob)
  {
    value = (uint16_t)(rand() % quantity + 1);
  }
  return (value);
}

void		generate_map(t_map *map)
{
  int		it;
  int		max;
  t_tile	*tiles;

  max = map->width * map->height;
  assert(max >= 0);
  it = 0;
  tiles = &map->tiles[0];
  while (it < max)
  {
    tiles[it].food = generate_ressource(50, 3);
    tiles[it].linemate = generate_ressource(25, 3);
    tiles[it].mendiane = generate_ressource(10, 2);
    tiles[it].deraumere = generate_ressource(20, 2);
    tiles[it].phiras = generate_ressource(20, 2);
    tiles[it].thystame = generate_ressource(5, 1);
    tiles[it].sibur = generate_ressource(25, 2);
    memset(&tiles[it].players, 0, sizeof(t_list));
    it++;
  }
}