/*
** direction.c for zappy in /home/anthony/repository/zappy/direction.c
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.eu>
**
** Started on  ven. juin 30 21:26:42 2017 Anthony LECLERC
** Last update ven. juin 30 21:26:42 2017 Anthony LECLERC
*/

#include			"graphic.h"

t_player_direction		convert_dir(t_direction dir)
{
  if (dir == DIR_UP)
    return (E_DIRECTION_NORTH);
  else if (dir == DIR_DOWN)
    return (E_DIRECTION_SOUTH);
  else if (dir == DIR_RIGHT)
    return (E_DIRECTION_EAST);
  else if (dir == DIR_LEFT)
    return (E_DIRECTION_WEST);
  else
    return (E_DIRECTIONS);
}

int				gr_send_player_direction(t_graphic *graphic,
							    t_player *player)
{
  t_grpacket_dir		packet;

  packet.dir = convert_dir(player->dir);
  assert(packet.dir != E_DIRECTIONS);
  init_player_protocol(&packet.player, E_PLAYER_MOVE);
  circbuffer_append_n(graphic->client->output, &packet, sizeof(packet));
  return (0);
}