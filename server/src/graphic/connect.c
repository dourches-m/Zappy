/*
** connect.c for zappy in /home/anthony/repository/zappy/connect.c
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.eu>
**
** Started on  sam. juil. 01 17:34:17 2017 Anthony LECLERC
** Last update sam. juil. 01 17:34:17 2017 Anthony LECLERC
*/

#include		<string.h>
#include		"protocol/proto_data.h"
#include		"graphic.h"

static void		setcell(t_cell *cell, t_tile *tile, int x, int y)
{
  cell->pos.x = x;
  cell->pos.y = y;
  cell->ressources[E_RESSOURCE_FOOD] = tile->food;
  cell->ressources[E_RESSOURCE_LINEMATE] = tile->linemate;
  cell->ressources[E_RESSOURCE_PHIRAS] = tile->phiras;
  cell->ressources[E_RESSOURCE_MENDIANE] = tile->mendiane;
  cell->ressources[E_RESSOURCE_THYSTAME] = tile->thystame;
  cell->ressources[E_RESSOURCE_SIBUR] = tile->sibur;
  cell->ressources[E_RESSOURCE_DERAUMERE] = tile->deraumere;
}

void			gr_send_all_players_eggs(t_graphic *graphic,
						     t_map *map)
{
  t_list_item		*item;
  t_player_infos	pinfos;
  t_egg_infos		einfos;

  item = map->players->first;
  while (item != NULL)
  {
    gr_set_player_infos(&pinfos, item->data);
    circbuffer_append_n(graphic->client->output, &pinfos, sizeof(pinfos));
    item = item->next;
  }
  item = map->eggs->first;
  while (item != NULL)
  {
    gr_set_egg_infos(&einfos, item->data);
    circbuffer_append_n(graphic->client->output, &einfos, sizeof(einfos));
    item = item->next;
  }
}

void			gr_send_all_teams(t_team **teams,
					  unsigned int nb_team)
{
  unsigned int		it;
  t_team_infos		iteam;

  it = 0;
  while (it < nb_team)
  {
    strncpy(&iteam.name[0], teams[it]->name, 128);
    iteam.free_slots = htonl(teams[it]->slots - teams[it]->nb_players);
    iteam.max_slots = htonl(teams[it]->slots);
    iteam.team_id = htonl(teams[it]->id);
    it++;
  }
}

void			gr_send_all_cells(t_graphic *graphic,
					      t_map *map)
{
  t_cell		cell;
  int			x;
  int			y;

  memset(&cell, 0, sizeof(t_cell));
  y = 0;
  while (y < map->height)
  {
    x = 0;
    while (x < map->width)
    {
      cell.pos.x = htonl((uint32_t)x);
      cell.pos.y = htonl((uint32_t)y);
      setcell(&cell, &map->tiles[GET_INDEX(x, y, map->width)], x, y);
      circbuffer_append_n(graphic->client->output, &cell, sizeof(cell));
      x++;
    }
    y++;
  }
}

void			gr_base_infos(t_graphic *graphic, t_map *map,
					 t_team **teams,
					 unsigned int nb_teams)
{
  t_grconnect		packet;

  memset(&packet, 0, sizeof(packet));
  init_base_protocol(&packet.base,
		     sizeof(packet) + (nb_teams * sizeof(t_team_infos)) +
		     (map->width * map->height * sizeof(t_cell)) +
		     (map->players->size * sizeof(t_player_infos)) +
		     (map->eggs->size *
		      sizeof(t_egg_infos)), E_CMD_DATA);
  packet.data.dimensions.width = htonl((uint32_t)map->width);
  packet.data.dimensions.height = htonl((uint32_t)map->height);
  packet.data.init_frame = 0;
  packet.data.nb_egg = htonl((uint32_t)map->eggs->size);
  packet.data.nb_player = htonl((uint32_t)map->players->size);
  packet.data.nb_team = htonl(nb_teams);
  circbuffer_append_n(graphic->client->output, &packet, sizeof(packet));
  gr_send_all_cells(graphic, map);
  gr_send_all_players_eggs(graphic, map);
  gr_send_all_teams(teams, nb_teams);
}