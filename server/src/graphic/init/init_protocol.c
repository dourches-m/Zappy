/*
** init_protocol.c for zappy in /home/anthony/repository/zappy/init_protocol.c
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.eu>
**
** Started on  sam. juil. 01 01:53:05 2017 Anthony LECLERC
** Last update sam. juil. 01 01:53:05 2017 Anthony LECLERC
*/

#include		"graphic.h"

void			init_player_protocol(t_protocol_player *proto,
						 enum e_protocol_player type)
{
  proto->action = type;
  proto->frame = 0;
  proto->player_id = 0;
}

void			init_incant_protocol(t_protocol_incantation *proto,
						enum e_protocol_incantation t)
{
  proto->action = t;
  proto->frame = 0;
  proto->player_id = 0;
}

void			init_egg_protocol(t_protocol_egg *proto,
					      enum e_protocol_egg type)
{
  proto->action = type;
  proto->frame = 0;
  proto->player_id = 0;
}

void			init_server_protocol(t_protocol_server *proto,
						 enum e_protocol_server type)
{
  proto->action = type;
  proto->frame = 0;
  proto->player_id = 0;
}

void			init_base_protocol(t_protocol_base *base,
					       uint32_t size,
					       enum e_protocol_cmd type)
{
  base->size = htonl(size);
  base->type = (enum e_protocol_cmd)htonl(type);
}