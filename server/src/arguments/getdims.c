/*
** getdims.c for zappy in /home/anthony/repository/zappy/getdims.c
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.eu>
**
** Started on  mar. juin 20 02:44:42 2017 Anthony LECLERC
** Last update Sun Jul  2 04:49:31 2017 Hugo Baldassin
*/

#include	<stdlib.h>
#include	<stdio.h>
#include	"arguments.h"

static int	get_height(t_servinfo *infos, int ac, char **av)
{
  int		it;

  it = 0;
  while (it < ac)
  {
    if (compare(av[it], "-y"))
    {
      if (++it < ac)
      {
	infos->height = (uint32_t)atoi(av[it]);
	if (infos->height < 5 || infos->height > 150)
	{
	  fprintf(stderr, "ERROR: Invalid command argument: -y"
		  " (min 5, max 150)\n");
	  return (1);
	}
	return (0);
      }
      fprintf(stderr, "Missing command argument: -y { height }.\n");
      return (1);
    }
    ++it;
  }
  return (0);
}

static int	get_width(t_servinfo *infos, int ac, char **av)
{
  int		it;

  it = 0;
  while (it < ac)
  {
    if (compare(av[it], "-x"))
    {
      if (++it < ac)
      {
	infos->width = (uint32_t)atoi(av[it]);
	if (infos->width < 5 || infos->width > 150)
        {
	  fprintf(stderr, "ERROR: Invalid command argument: -x"
		  " (min 5, max 150)\n");
	  return (1);
        }
	return (0);
      }
      fprintf(stderr, "Missing command argument: -x { width }.\n");
      return (1);
    }
    ++it;
  }
  return (0);
}

int		get_dimensions_command(t_servinfo *infos, int ac, char **av)
{
  infos->width = 20;
  infos->height = 20;
  return (get_width(infos, ac, av) || get_height(infos, ac, av));
}
