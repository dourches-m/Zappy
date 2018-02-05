/*
** proto_egg.h for zappy in /home/anthony/repository/zappy/proto_egg.h
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.eu>
**
** Started on  sam. juil. 01 13:08:26 2017 Anthony LECLERC
** Last update sam. juil. 01 13:08:26 2017 Anthony LECLERC
*/

#ifndef 		 	ZAPPY_PROTO_EGG_H
# define 		 	ZAPPY_PROTO_EGG_H

# include			"map/egg.h"
# include 			"protocol.h"

typedef struct			s_gregg_base
{
  t_protocol_base		base;
  t_protocol_egg		proto;
}				t_gregg_base;

typedef struct			s_gregg_hatch
{
  t_gregg_base			base;
  int32_t			time;
}				t_gregg_hatch;

typedef struct			s_gregg_infos
{
  t_gregg_base			base;
  t_egg_infos			infos;
}				t_gregg_infos;

void				gr_set_egg_infos(t_egg_infos *infos,
						     t_egg *egg);

#endif 		 	 	/* ZAPPY_PROTO_EGG_H */
