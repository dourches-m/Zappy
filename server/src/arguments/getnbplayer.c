/*
** getnbplayer.c for zappy in /home/anthony/repository/zappy/getnbplayer.c
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.eu>
**
** Started on  mar. juin 20 04:33:51 2017 Anthony LECLERC
** Last update mar. juin 20 04:33:51 2017 Anthony LECLERC
*/

#include 	<stdio.h>
#include 	<stdlib.h>
#include 	"arguments.h"

int		get_nbplayer_command(t_servinfo *infos, int ac, char **av)
{
  int		it;

  it = 0;
  infos->team_size = MIN_PLAYER_IN_TEAM;
  while (it < ac)
  {
    if (compare(av[it], "-c"))
    {
      if (++it < ac)
      {
	infos->team_size = (uint32_t)atoi(av[it]);
	if (infos->team_size < MIN_PLAYER_IN_TEAM)
	{
	  fprintf(stderr, "ERROR: Invalid command argument: -c.\n");
	  return (1);
	}
	return (0);
      }
      fprintf(stderr, "Missing command argument: -c { n players/team }.\n");
      return (1);
    }
    it++;
  }
  return (0);
}