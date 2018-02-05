/*
** death.c for zappy in /home/anthony/repository/zappy/death.c
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.eu>
**
** Started on  sam. juil. 01 03:18:28 2017 Anthony LECLERC
** Last update sam. juil. 01 03:18:28 2017 Anthony LECLERC
*/

#include		"graphic.h"

void			gr_player_dies(t_graphic *graphic)
{
  t_grplayer_base	packet;

  init_base_protocol(&packet.base, sizeof(t_grplayer_base), E_CMD_PLAYER);
  init_player_protocol(&packet.proto, E_PLAYER_DIE);
  circbuffer_append_n(graphic->client->output, &packet, packet.base.size);
}