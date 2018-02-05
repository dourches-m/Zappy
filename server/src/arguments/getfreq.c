/*
** getfreq.c for zappy in /home/anthony/repository/zappy/getfreq.c
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.eu>
**
** Started on  mar. juin 20 03:07:26 2017 Anthony LECLERC
** Last update Fri Jun 30 11:59:52 2017 Hugo Baldassin
*/

#include 	<stdlib.h>
#include 	<stdio.h>
#include	"arguments.h"

int		get_freq_command(t_servinfo *infos,
				 int ac,
				 char **av)
{
  int		it;

  it = 0;
  infos->freq = 100;
  while (it < ac)
    {
      if (compare(av[it], "-f"))
	{
	  if (++it < ac)
	    {
	      infos->freq = (size_t) atol(av[it]);
	      if (infos->freq == 0 || infos->freq > 100000)
		{
		  fprintf(stderr, "ERROR: Invalid command argument: -f\n");
		  return (1);
		}
	      return (0);
	    }
	  fprintf(stderr, "Missing command argument: -f { frequency }.\n");
	  return (1);
	}
      it++;
    }
  return (0);
}
