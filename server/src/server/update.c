/*
** update.c for zappy in /home/anthony/repository/zappy/update.c
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.eu>
**
** Started on  mer. juin 28 18:13:07 2017 Anthony LECLERC
** Last update mer. juin 28 18:13:07 2017 Anthony LECLERC
*/

#include 		<sys/time.h>
#include		<stdio.h>
#include 		"frequency.h"
#include 		"debug.h"
#include		"utils.h"
#include 		"serverinfo.h"
#include		"map/egg.h"

static void		eggs_update(t_zserver *server, size_t elapsed_time)
{
  t_list_item		*it;
  t_egg			*egg;

  it = server->map->eggs->first;
  while (it != NULL)
  {
    egg = it->data;
    if (!egg->hatched)
      egg_update(it->data, elapsed_time);
    it = it->next;
  }
}

static void		players_update(t_zserver *server, size_t timespend)
{
  t_list_item		*it;
  t_player		*player;

  it = server->map->players->first;
  while (it != NULL)
  {
    player = it->data;
    it = it->next;
    player_update(server, player, timespend);
  }
}

void			update(t_zserver *server, size_t timespend)
{
  eggs_update(server, timespend);
  players_update(server, timespend);
}