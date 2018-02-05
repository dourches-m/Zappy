/*
** parse.c for zappy in /home/anthony/repository/zappy/parse.c
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.eu>
**
** Started on  lun. juin 19 23:17:29 2017 Anthony LECLERC
** Last update Fri Jun 30 11:54:58 2017 Hugo Baldassin
*/

#include	<string.h>
#include 	<assert.h>
#include 	<stdlib.h>
#include 	<stdio.h>
#include 	"debug.h"
#include 	"arguments.h"
#include 	"serverinfo.h"

void		print_arguments(t_servinfo const *infos)
{
  size_t	i;

  i = 0;
  fprintf(stdout, SLOG_FORMAT("PORT") "%hd\n", infos->port);
  fprintf(stdout, SLOG_FORMAT("WIDTH") "%u\n", infos->width);
  fprintf(stdout, SLOG_FORMAT("HEIGHT") "%u\n", infos->height);
  fprintf(stdout, SLOG_FORMAT("FREQUENCY") "%zu\n", infos->freq);
  fprintf(stdout, SLOG_FORMAT("P TEAM") "%u\n", infos->team_size);
  fprintf(stdout, SLOG_FORMAT("NB TEAM") "%u\n", infos->nteam);
  while (i < infos->nteam)
  {
    fprintf(stdout, SLOG_FORMAT("TEAM") "%s\n", infos->team_name[i]);
    ++i;
  }
}

int		parse_arguments(int ac, char **av, t_servinfo *infos)
{
  assert(infos != NULL);
  if (get_port_command(infos, ac, av) == 1)
    return (1);
  if (get_dimensions_command(infos, ac, av) == 1)
    return (1);
  if (get_freq_command(infos, ac, av) == 1)
    return (1);
  if (get_nbplayer_command(infos, ac, av) == 1)
    return (1);
  if (get_teams_command(infos, ac, av) == 1)
    return (1);
  return (0);
}
