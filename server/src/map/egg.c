/*
** egg.c for zappy in /home/anthony/repository/zappy/egg.c
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.eu>
**
** Started on  lun. juin 26 11:54:28 2017 Anthony LECLERC
** Last update lun. juin 26 11:54:28 2017 Anthony LECLERC
*/

#include		<stdlib.h>
#include		<string.h>
#include		"frequency.h"
#include		"debug.h"
#include		"utils.h"
#include		"map/map.h"
#include		"map/egg.h"

t_egg			*get_team_egg(char const *team, t_list_item *egg_list)
{
  t_egg			*egg;

  while (egg_list)
    {
      egg = (t_egg *)egg_list->data;
      if (!strcmp(egg->team->name, team))
        break;
      egg_list = egg_list->next;
    }
  if (egg_list)
    return (egg);
  return (NULL);
}

void			spawn_egg(t_map *map, t_team *owner, t_pos const *pos)
{
  t_egg			*egg;

  egg = myalloc(sizeof(t_egg));
  egg->hatch = 0;
  egg->pos.x = pos->x;
  egg->pos.y = pos->y;
  egg->team = owner;
  egg->hatched = false;
  if (map->eggs->last == NULL)
    egg->id = 1;
  else
    egg->id = ((t_egg *)map->eggs->last->data)->id + 1;
  list_pushback_data(map->eggs, egg, sizeof(t_egg));
}

int			is_hatch_time(t_egg const *egg)
{
  return (egg->hatch >= COMMAND_TIME(CYCLE_TO_HATCH, g_frequency));
}

void			egg_update(t_egg *egg, size_t stime)
{
  egg->hatch += stime;
  EGGLOG("[EGG] :: Hatch time :: %zu\n", egg->hatch);
  if (is_hatch_time(egg))
  {
    EGGLOG("[EGG] :: Hatched ::\n");
    egg->team->slots += 1;
    egg->hatched = true;
  }
}