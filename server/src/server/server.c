/*
** server.c for zappy in /home/anthony/repository/zappy/server.c
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.eu>
**
** Started on  jeu. juin 22 13:09:14 2017 Anthony LECLERC
** Last update jeu. juin 22 13:09:14 2017 Anthony LECLERC
*/

#include		<stdlib.h>
#include 		<err.h>
#include		"team.h"
#include 		"list/list.h"
#include 		"serverinfo.h"
#include 		"utils.h"
#include 		"frequency.h"

static t_team		**init_team(t_servinfo *infos)
{
  t_team		**team_list;
  uint16_t		it;

  it = 0;
  team_list = myalloc((infos->nteam + 1) * sizeof(t_team *));
  team_list[infos->nteam] = NULL;
  while (it < infos->nteam)
  {
    team_list[it] = create_team(infos->team_name[it], infos->team_size);
    it++;
  }
  return (team_list);
}

t_zserver		*init_server(t_servinfo *infos)
{
  t_zserver		*server;

  server = myalloc(sizeof(*server));
  tcp_listener(&server->sock);
  if (!tcp_bind(&server->sock, NULL, infos->port))
  {
    warn("bind");
    free(server);
    return (NULL);
  }
  sock_selector(&server->selector);
  select_add(&server->selector, &server->sock.socket, READ_SELECT);
  server->teams = NULL;
  server->clients = list_init();
  g_frequency = infos->freq;
  server->teams = init_team(infos);
  return (server);
}

void			destruct_server(t_zserver *self)
{
  close_socket(&self->sock.socket);
  free_2d_array((void**)(self->teams));
  list_delete(self->clients, NULL);
}