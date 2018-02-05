/*
** proto_data.hpp for zappy in /home/anthony/repository/zappy/proto_data.hpp
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.eu>
**
** Started on  dim. juil. 02 00:04:27 2017 Anthony LECLERC
** Last update dim. juil. 02 00:04:27 2017 Anthony LECLERC
*/

#ifndef 		ZAPPY_PROTO_DATA_HPP
# define  		ZAPPY_PROTO_DATA_HPP

# include		"protocol.h"

typedef	struct		s_grconnect
{
  t_protocol_base	base;
  t_protocol_data	data;
}			t_grconnect;

#endif  		/* ZAPPY_PROTO_DATA_HPP */
