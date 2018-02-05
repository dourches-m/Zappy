/*
** getport.c for zappy in /home/anthony/repository/zappy/getport.c
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.eu>
**
** Started on  lun. juin 19 23:29:10 2017 Anthony LECLERC
** Last update lun. juin 19 23:29:10 2017 Anthony LECLERC
*/

#include 	<stdint.h>
#include 	<stdlib.h>
#include 	<stdio.h>
#include 	<limits.h>
#include 	"arguments.h"
#include 	"serverinfo.h"

uint16_t	get_port(char const *arg)
{
  int		port;

  port = atoi(arg);
  if (port <= MAX_PRIVILEGED_PORT || port > USHRT_MAX)
  {
    fprintf(stderr, "ERROR: Invalid port given in argument: %d\n", port);
    return (0);
  }
  return ((uint16_t)port);
}

int		get_port_command(t_servinfo *infos, int ac, char **av)
{
  int		it;

  it = 1;
  infos->port = 9001;
  while (it < ac)
  {
    if (compare(av[it], "-p"))
    {
      if (++it < ac)
      {
	infos->port = get_port(av[it]);
	if (infos->port == 0)
	  return (1);
	return (0);
      }
      fprintf(stderr, "Missing command argument: -p { port }.\n");
      return (1);
    }
    it++;
  }
  return (0);
}