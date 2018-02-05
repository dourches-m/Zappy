/*
** connect_player.c for zappy in /home/anthony/repository/zappy/connect_player.c
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.eu>
**
** Started on  ven. juin 30 22:46:37 2017 Anthony LECLERC
** Last update ven. juin 30 22:46:37 2017 Anthony LECLERC
*/

#include 		<string.h>
#include		"graphic.h"

static void		convert_inventory(t_player_infos *infos,
					     t_player *player)
{
  infos->inventory.ressources[E_RESSOURCE_FOOD] = player->inventory[FOOD].nb;
  infos->inventory.ressources[E_RESSOURCE_LINEMATE] =
      player->inventory[LINEMATE].nb;
  infos->inventory.ressources[E_RESSOURCE_DERAUMERE] =
      player->inventory[DERAUMERE].nb;
  infos->inventory.ressources[E_RESSOURCE_MENDIANE] =
      player->inventory[MENDIANE].nb;
  infos->inventory.ressources[E_RESSOURCE_PHIRAS] =
      player->inventory[PHIRAS].nb;
  infos->inventory.ressources[E_RESSOURCE_SIBUR] =
      player->inventory[SIBUR].nb;
  infos->inventory.ressources[E_RESSOURCE_THYSTAME] =
      player->inventory[THYSTAME].nb;
}

void                     gr_set_player_infos(t_player_infos *infos,
                                             t_player *player)
{
  infos->pos.x = htonl((uint32_t)player->pos.x);
  infos->pos.y = htonl((uint32_t)player->pos.y);
  infos->id = htonl(0);
  infos->dir = convert_dir(player->dir);
  infos->level = htonl(player->lvl);
  convert_inventory(infos, player);
}

int			gr_player_connect(t_graphic *graphic,
                                             t_player *player)
{
  t_grpacket_player	packet;

  memset(&packet, 0, sizeof(packet));
  init_base_protocol(&packet.base, sizeof(packet), E_CMD_PLAYER);
  init_player_protocol(&packet.proto, E_PLAYER_NEW);
  gr_set_player_infos(&packet.infos, player);
  circbuffer_append_n(graphic->client->output, &packet, sizeof(packet));
  return (0);
}