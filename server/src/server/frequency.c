/*
** frequency.c for zappy in /home/anthony/repository/zappy/frequency.c
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.eu>
**
** Started on  mer. juin 28 13:20:31 2017 Anthony LECLERC
** Last update mer. juin 28 13:20:31 2017 Anthony LECLERC
*/

#include	<stddef.h>
#include	<stdio.h>
#include	"debug.h"
#include 	"map/egg.h"
#include 	"player.h"
#include 	"list/list.h"

size_t		g_frequency = 100;

static size_t	get_egg_mintime(t_list_item *it)
{
  size_t	mintime;
  t_egg		*egg;

  assert(it != NULL);
  assert(it->size == sizeof(t_egg));
  mintime = 0;
  while (it)
    {
      egg = it->data;
      if (!egg->hatched)
        {
          mintime = egg->hatch;
          break;
        }
      it = it->next;
    }
  while (it != NULL)
  {
    egg = it->data;
    if (!egg->hatched && egg->hatch < mintime)
      mintime = egg->hatch;
    it = it->next;
  }
  return (mintime);
}

static size_t	get_player_mintime(t_player *pl)
{
  t_command	*cmd;
  size_t	mintime;

  mintime = pl->life_time;
  cmd = pl->cmd_list;
  DLOG("PLAYER: Life time unit: %zu\n", pl->life_time);
  while (cmd != NULL)
  {
    if (cmd->time_units < mintime)
      mintime = cmd->time_units;
    cmd = cmd->next;
  }
  return (mintime);
}

static size_t	get_players_mintime(t_list_item *it)
{
  size_t	mintime;
  size_t	player_mintime;

  assert(it != NULL);
  assert(it->size == sizeof(t_player));
  mintime = get_player_mintime(it->data);
  it = it->next;
  while (it != NULL)
  {
    player_mintime = get_player_mintime(it->data);
    if (player_mintime < mintime)
      mintime = player_mintime;
    it = it->next;
  }
  return (mintime);
}

static size_t	get_min_time(size_t player_time, size_t egg_time)
{
  if (player_time == 0 && egg_time == 0)
    return (0);
  if (player_time == 0)
    return (egg_time);
  if (egg_time == 0)
    return (player_time);
  return ((player_time < egg_time) ? player_time : egg_time);
}

size_t		next_command_time(t_list *players, t_list *eggs)
{
  size_t	pl_time;
  size_t	egg_time;

  DPLOG("Players in game: %zu\n", players->size);
  pl_time = 0;
  egg_time = 0;
  if (players->size == 0 && eggs->size == 0)
    return (0);
  if (players->size > 0)
    pl_time = get_players_mintime(players->first);
  if (eggs->size > 0)
    egg_time = get_egg_mintime(eggs->first);
  SERVLOG("Player waiting: %zu\n", pl_time);
  SERVLOG("Egg waiting: %zu\n", egg_time);
  return (get_min_time(pl_time, egg_time));
}