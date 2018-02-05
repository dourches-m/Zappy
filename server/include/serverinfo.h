/*
** serverinfo.h for zappy in /home/anthony/repository/zappy/serverinfo.h
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.eu>
**
** Started on  lun. juin 19 22:57:46 2017 Anthony LECLERC
** Last update Sat Jul  1 23:50:28 2017 Hugo Baldassin
*/

#ifndef			SERVERINFO_H_
# define 		SERVERINFO_H_

# include 		<stddef.h>
# include 		<stdint.h>
# include 		"map/map.h"
# include		"client.h"
# include		"graphic.h"
# include		"list/list.h"
# include 		"socket/SocketSelector.h"
# include 		"socket/TcpListener.h"
# include		"team.h"

# define		MAX_PRIVILEGED_PORT	1023
# define		MIN_PLAYER_IN_TEAM	1

# define		KO_MSG			"ko\n"

typedef struct		s_servinfo
{
  int32_t		width;
  int32_t		height;
  size_t		freq;
  char			**team_name;
  uint32_t		team_size;
  uint16_t		nteam;
  uint16_t		port;
}			t_servinfo;

typedef struct		s_zserver
{
  t_tcplistener		sock;
  t_sockselector	selector;
  t_graphic		*graphic;
  t_list		*clients;
  t_map			*map;
  t_team		**teams;
}			t_zserver;

t_zserver		*init_server(t_servinfo *infos);

int			server_loop(t_zserver *server);

void			verify_clients(t_zserver *server);

int			connect_client(t_zserver *server);

int			deconnect_client(t_zserver *server,
					 t_client *client);

int			try_register(t_zserver *server, t_client *client);

int			read_unregister(t_client *self);

int			read_player(t_client *self);

void			update(t_zserver *server, size_t timespend);

void			player_update(t_zserver *server, t_player *player,
				      size_t timespend);

void			player_dies(t_zserver *server, t_player *player);

void			handle_inputs(t_zserver *server);

void			handle_outputs(t_zserver *server);

void			destruct_server(t_zserver *server);

#endif 			/* SERVERINFO_H_ */
