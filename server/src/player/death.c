/*
** death.c for zappy in /home/anthony/repository/zappy/death.c
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.eu>
**
** Started on  mer. juin 28 18:34:20 2017 Anthony LECLERC
** Last update Fri Jun 30 14:03:07 2017 Hugo Baldassin
*/

#include	<stdio.h>
#include	"debug.h"
#include	"serverinfo.h"
#include 	"utils.h"

static void 	disperse_inventory(t_map *map, t_player *player)
{
  spawn_resource(map, LINEMATE, player->inventory[0].nb);
  spawn_resource(map, DERAUMERE, player->inventory[1].nb);
  spawn_resource(map, SIBUR, player->inventory[2].nb);
  spawn_resource(map, MENDIANE, player->inventory[3].nb);
  spawn_resource(map, PHIRAS, player->inventory[4].nb);
  spawn_resource(map, THYSTAME, player->inventory[5].nb);
  spawn_resource(map, FOOD, player->inventory[6].nb);
}

void		player_dies(t_zserver *server, t_player *player)
{
  assert(player->net != NULL);
  disperse_inventory(server->map, player);
  circbuffer_append(player->net->output, "dead\n");
  select_add(&server->selector, &player->net->socket.socket, WRITE_SELECT);
  player->net->player = NULL;
  player->net = NULL;
  list_remove(&server->map->tiles[GET_INDEX(player->pos.x,
					    player->pos.y,
					    server->map->width)].players,
	      player);
  list_erase_item(server->map->players, player, NULL);
  player->team->nb_players -= 1;
  DLOG("[PLAYER] Death from team %s.\n", player->team->name);
  remove_player(&player->team->player, player);
}
