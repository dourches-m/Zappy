/*
** getteams.c for zappy in /home/anthony/repository/zappy/getteams.c
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.eu>
**
** Started on  mar. juin 20 02:35:04 2017 Anthony LECLERC
** Last update Sun Jul  2 04:50:16 2017 Hugo Baldassin
*/

#include 	<stdio.h>
#include 	<assert.h>
#include 	<string.h>
#include 	"utils.h"
#include 	"arguments.h"
#include	"serverinfo.h"

static int	get_teams_names(t_servinfo *infos, int ac, char **av, int idx)
{
  int		it;

  idx++;
  while (idx < ac && av[idx][0] != '-')
  {
    if (av[idx + 1] && !strcmp(av[idx], av[idx + 1]))
      return (1);
    infos->nteam++;
    idx++;
  }
  infos->team_name = myalloc((infos->nteam + 1) * sizeof(char *));
  infos->team_name[infos->nteam] = NULL;
  it = 0;
  while (it < infos->nteam)
  {
    infos->team_name[it] = mstrdup(av[idx - (infos->nteam - it)]);
    it++;
  }
  return (infos->team_name[0] == 0);
}

int		get_teams_command(t_servinfo *infos, int ac, char **av)
{
  int		it;

  assert(infos != NULL);
  it = 0;
  infos->nteam = 0;
  infos->team_name = NULL;
  while (it < ac)
  {
    if (compare(av[it], "-n"))
    {
      if (get_teams_names(infos, ac, av, it))
	{
	  fprintf(stderr, "ERROR: invalid team arguments\n");
	  return (1);
	}
      return (0);
    }
    it++;
  }
  return (0);
}
