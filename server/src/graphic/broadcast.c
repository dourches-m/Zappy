/*
** broadcast.c for zappy in /home/anthony/repository/zappy/broadcast.c
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.eu>
**
** Started on  ven. juin 30 23:15:35 2017 Anthony LECLERC
** Last update ven. juin 30 23:15:35 2017 Anthony LECLERC
*/

#include	 		<string.h>
#include		 	"graphic.h"

int			 	gr_broadcast(t_graphic *graphic,
                                                char const *msg)
{
  t_protocol_base		base;
  t_protocol_player		proto;
  uint32_t			psize;
  size_t			reserved;
  char				*buf;

  psize = sizeof(t_protocol_base) + sizeof(t_protocol_player) + strlen(msg);
  init_base_protocol(&base, psize, E_CMD_PLAYER);
  init_player_protocol(&proto, E_PLAYER_BROADCAST);
  buf = circbuffer_reserve(graphic->client->output, psize, &reserved);
  if (psize >= reserved)
  {
    memcpy(buf, &base, sizeof(t_protocol_base));
    memcpy(buf + sizeof(t_protocol_base), &proto, sizeof(t_protocol_player));
    memcpy(buf + sizeof(t_protocol_base) + sizeof(t_protocol_player), msg,
	   psize - (sizeof(t_protocol_base) + sizeof(t_protocol_player)));
    circbuffer_push(graphic->client->output, psize);
  }
  return (0);
}