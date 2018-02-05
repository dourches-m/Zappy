/*
** proto_player.h for zappy in /home/anthony/repository/zappy/proto_player.h
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.eu>
**
** Started on  sam. juil. 01 03:19:25 2017 Anthony LECLERC
** Last update sam. juil. 01 03:19:25 2017 Anthony LECLERC
*/

#ifndef 		ZAPPY_PROTO_PLAYER_H
# define 		ZAPPY_PROTO_PLAYER_H

# include		"protocol.h"

typedef struct		s_grplayer_base
{
  t_protocol_base	base;
  t_protocol_player	proto;
}			t_grplayer_base;

typedef struct		s_grpacket_player
{
  t_protocol_base	base;
  t_protocol_player	proto;
  t_player_infos	infos;
}			t_grpacket_player;

typedef struct		s_grpacket_dir
{
  t_protocol_base	base;
  t_protocol_player	player;
  t_player_direction	dir;
}			t_grpacket_dir;

typedef struct		s_grplayer_item
{
  t_protocol_base	base;
  t_protocol_player	proto;
  enum e_ressources	type;
}			t_grplayer_item;

void			init_player_protocol(t_protocol_player *proto,
						 enum e_protocol_player);

void			gr_set_player_infos(t_player_infos *infos,
						t_player *pl);

#endif 		 	/* ZAPPY_PROTO_PLAYER_H */
