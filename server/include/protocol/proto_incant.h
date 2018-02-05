/*
** proto_incant.h for zappy in /home/anthony/repository/zappy/proto_incant.h
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.eu>
**
** Started on  dim. juil. 02 11:42:05 2017 Anthony LECLERC
** Last update dim. juil. 02 11:42:05 2017 Anthony LECLERC
*/

#ifndef 		 	ZAPPY_PROTO_INCANT_H
# define  	 		ZAPPY_PROTO_INCANT_H

#include			"protocol.h"

typedef struct			s_grincant_begin
{
  t_protocol_base		base;
  t_protocol_incantation	proto;
  t_position			pos;
  uint32_t			nplayer;
}				t_grincant_begin;

typedef struct			s_grincant_end
{
  t_protocol_base		base;
  t_protocol_incantation	proto;
}				t_incant_end;

#endif 				/* ZAPPY_PROTO_INCANT_H */
