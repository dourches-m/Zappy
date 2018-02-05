/*
** incant.c for zappy in /home/anthony/repository/zappy/incant.c
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.eu>
**
** Started on  dim. juil. 02 04:59:07 2017 Anthony LECLERC
** Last update dim. juil. 02 04:59:07 2017 Anthony LECLERC
*/

#include		<string.h>
#include		"graphic.h"

void			gr_send_incant_begin(t_graphic *graphic,
						 t_pos *pos,
						 t_list *players)
{
  t_grincant_begin	packet;
  t_player_infos	pinfos;
  t_list_item		*it;

  memset(&packet, 0, sizeof(packet));
  init_base_protocol(&packet.base,
		     sizeof(packet) + players->size * sizeof(t_player_infos),
		     E_CMD_INCANTATION);
  init_incant_protocol(&packet.proto, E_INCANTATION_BEGIN);
  packet.pos.x = htonl((uint32_t)pos->x);
  packet.pos.y = htonl((uint32_t)pos->y);
  packet.nplayer = htonl((uint32_t)players->size);
  circbuffer_append_n(graphic->client->output, &packet, sizeof(packet));
  it = players->first;
  while (it != NULL)
  {
    gr_set_player_infos(&pinfos, it->data);
    circbuffer_append_n(graphic->client->output, &pinfos, sizeof(pinfos));
  }
}
