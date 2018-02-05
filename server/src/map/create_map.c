/*
** create_map.c for zappy in /home/anthony/repository/zappy/create_map.c
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.eu>
**
** Started on  mar. juin 20 21:37:28 2017 Anthony LECLERC
** Last update mar. juin 20 21:37:28 2017 Anthony LECLERC
*/

#include 	<assert.h>
#include 	<string.h>
#include	<stdio.h>
#include 	"list/list.h"
#include 	"utils.h"
#include 	"debug.h"
#include	"serverinfo.h"
#include 	"map/map.h"

t_map		*create_map(int32_t width, int32_t height)
{
  t_map		*map;

  assert(width > 0);
  assert(height > 0);
  map = myalloc(sizeof(t_map) + (width * height * sizeof(t_tile)));
  map->width = width;
  map->height = height;
  map->players = list_init();
  map->eggs = list_init();
  memset(map->tiles, 0, (width * height * sizeof(t_tile)));
  return (map);
}