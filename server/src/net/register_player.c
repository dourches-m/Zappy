/*
** register_player.c for zappy in /home/anthony/repository/zappy/register_player.c
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.eu>
**
** Started on  jeu. juin 29 03:02:38 2017 Anthony LECLERC
** Last update Sun Jul  2 05:05:31 2017 Hugo Baldassin
*/

#define			_GNU_SOURCE
#include		<stdlib.h>
#include		<string.h>
#include		<stdio.h>
#include		"map/egg.h"
#include		"frequency.h"
#include		"debug.h"
#include		"serverinfo.h"

static void		send_players_infos(t_player *player, t_map *map)
{
  char			*msg;

  asprintf(&msg, "%d\n%d %d\n", player->team->slots - player->team->nb_players
	   , map->width, map->height);
  circbuffer_append(player->net->output, msg);
  free(msg);
}

static t_player		*add_player_in_map(t_map *map, t_team *team)
{
  t_player		*player;
  t_pos			pos;
  t_list_item		*map_player;

  pos.x = rand() % map->width;
  pos.y = rand() % map->height;
  player = init_player(&pos, team);
  map_player = list_item_init(player, sizeof(t_player));
  list_pushback_item(map->players, map_player);
  list_pushback_data(&map->tiles[GET_INDEX(player->pos.x,
					   player->pos.y, map->width)].players
		     , map_player->data, sizeof(t_player));
  return (player);
}

static t_team		*find_team_from_name(t_team **teams,
					     char const *teamname)
{
  unsigned int		i;

  i = 0;
  while (teams[i])
  {
    if (strcmp(teams[i]->name, teamname) == 0)
      return (teams[i]);
    i++;
  }
  return (NULL);
}

int			is_valid_team(t_team *team)
{
  return (team->nb_players < team->slots);
}

int			register_player(t_zserver *server, t_client *client,
					char const *input)
{
  t_player		*new_player;
  t_team		*team;
  t_egg			*egg;

  team = find_team_from_name(server->teams, input);
  if (team == NULL || !is_valid_team(team))
    return (1);
  new_player = add_player_in_map(server->map, team);
  new_player->net = client;
  new_player->life_time = COMMAND_TIME(CYCLE_FOOD, g_frequency);
  egg = get_team_egg(input, server->map->eggs->first);
  if (egg && egg->hatched)
    {
      new_player->pos.x = egg->pos.x;
      new_player->pos.y = egg->pos.y;
      list_erase_item(server->map->eggs, egg, free);
    }
  client->player = new_player;
  add_player(&team->player, new_player);
  team->nb_players += 1;
  client->write_data = write_to_player;
  send_players_infos(new_player, server->map);
  DLOG("[CONNECTION] New player registered.\n");
  return (0);
}
