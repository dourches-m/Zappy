/*
** convert_to_pos->c for psu_zappy in /home/baldas/Prog/repos/tek2/psu/PSU_2016_zappy/server
**
** Made by Hugo Baldassin
** Login   <baldas@epitech.net>
**
** Started on  Tue Jun 27 18:01:13 2017 Hugo Baldassin
** Last update Tue Jun 27 18:01:13 2017 Hugo Baldassin
*/

#include 	"pos.h"
#include 	"map/map.h"

void		convert_to_real_pos(t_pos *pos, t_map *map)
{
  if (pos->x < 0)
    pos->x = map->width + pos->x;
  else if (pos->x > (map->width - 1))
    pos->x = 0 + (pos->x - map->width);
  if (pos->y < 0)
    pos->y = map->height + pos->y;
  else if (pos->y > (map->height - 1))
    pos->y = 0 + (pos->y - map->height);
}