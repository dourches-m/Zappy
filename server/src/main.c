/*
** main.c for cpp_indie_studio in /home/anthony/repository/cpp_indie_studio/main.c
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.eu>
**
** Started on  lun. juin 19 19:52:43 2017 Anthony LECLERC
** Last update Sun Jul  2 16:56:34 2017 Hugo Baldassin
*/

#include	<stdio.h>
#include	<player.h>
#include	<stdlib.h>
#include	<map/egg.h>
#include 	<signal.h>

#include	"utils.h"
#include	"serverinfo.h"
#include	"debug.h"
#include	"arguments.h"
#include	"map/map.h"

/*
** Zappy server binary.
*/

void		sigpipe_handler(int sig)
{
  (void)sig;
  fprintf(stderr, "WARNING: SigPipe Occurred.\n");
}

int		main(int ac, char **av)
{
  t_servinfo	infos;
  t_zserver	*server;

  init_rand();
  signal(SIGPIPE, sigpipe_handler);
  if (parse_arguments(ac, av, &infos))
    {
      fprintf(stderr, "Quit\n");
      return (1);
    }
  DPRINT_ARGUMENTS(&infos);
  server = init_server(&infos);
  if (server == NULL)
    return (1);
  server->map = create_map(infos.width, infos.height);
  generate_map(server->map);
  server_loop(server);
  free(server->map);
  destruct_server(server);
  return (0);
}
