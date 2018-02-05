/*
** egg.c for zappy in /home/anthony/repository/zappy/egg.c
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.eu>
**
** Started on  sam. juil. 01 13:08:09 2017 Anthony LECLERC
** Last update sam. juil. 01 13:08:09 2017 Anthony LECLERC
*/

#include		<string.h>
#include		"graphic.h"

void			gr_egg_hatch(t_graphic *graphic)
{
  t_gregg_hatch		packet;

  init_base_protocol(&packet.base.base, sizeof(packet), E_CMD_EGG);
  init_egg_protocol(&packet.base.proto, E_EGG_HATCH);
  packet.time = 0;
  circbuffer_append_n(graphic->client->output, &packet, sizeof(packet));
}

void			gr_set_egg_infos(t_egg_infos *infos, t_egg *egg)
{
  memset(infos, 0, sizeof(*infos));
  infos->pos.x = htonl((uint32_t)egg->pos.x);
  infos->pos.y = htonl((uint32_t)egg->pos.y);
  infos->team_id = htonl(egg->team->id);
  infos->dead = false;
  infos->created = egg->hatch >= 600;
}