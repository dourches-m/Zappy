/*
** set.c for zappy in /home/anthony/repository/zappy/set.c
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.eu>
**
** Started on  sam. juil. 01 03:05:21 2017 Anthony LECLERC
** Last update sam. juil. 01 03:05:21 2017 Anthony LECLERC
*/

#include			"graphic.h"

enum e_ressources		convert_ressource(t_item_type type)
{
  if (type == FOOD)
    return (E_RESSOURCE_FOOD);
  if (type == LINEMATE)
    return (E_RESSOURCE_LINEMATE);
  if (type == SIBUR)
    return (E_RESSOURCE_SIBUR);
  if (type == THYSTAME)
    return (E_RESSOURCE_THYSTAME);
  if (type == PHIRAS)
    return (E_RESSOURCE_PHIRAS);
  if (type == MENDIANE)
    return (E_RESSOURCE_MENDIANE);
  if (type == DERAUMERE)
    return (E_RESSOURCE_DERAUMERE);
  assert(false);
}

void				gr_player_set(t_graphic *graphic,
						  t_item_type type)
{
  t_grplayer_item		packet;

  init_base_protocol(&packet.base, sizeof(t_grplayer_item), E_CMD_PLAYER);
  init_player_protocol(&packet.proto, E_PLAYER_DELETE_RESSOURCE);
  packet.type = convert_ressource(type);
  circbuffer_append_n(graphic->client->output, &packet, packet.base.size);
}

void				gr_player_get(t_graphic *graphic,
						  t_item_type type)
{
  t_grplayer_item		packet;

  init_base_protocol(&packet.base, sizeof(t_grplayer_item), E_CMD_PLAYER);
  init_player_protocol(&packet.proto, E_PLAYER_GET_RESSOURCE);
  packet.type = convert_ressource(type);
  circbuffer_append_n(graphic->client->output, &packet, packet.base.size);
}