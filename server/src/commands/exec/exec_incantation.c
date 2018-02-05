/*
** exec_incantation.c for psu_zappy in /home/baldas/Prog/repos/tek2/psu/PSU_2016_zappy/server/src/commands
**
** Made by Hugo Baldassin
** Login   <baldas@epitech.net>
**
** Started on  Thu Jun 22 14:14:55 2017 Hugo Baldassin
** Last update Sun Jul  2 22:05:31 2017 Anthony LECLERC
*/

#include 	<string.h>
#include 	<stdlib.h>
#include 	<stdio.h>

#include 	"frequency.h"
#include 	"commands.h"
#include 	"utils.h"
#include 	"incant.h"

static t_incant	incantations[] =
  {
    {{1, 0, 0, 0, 0, 0}, 1, 1},
    {{1, 1, 1, 0, 0, 0}, 2, 2},
    {{2, 0, 1, 0, 2, 0}, 2, 3},
    {{1, 1, 2, 0, 1, 0}, 4, 4},
    {{1, 2, 1, 3, 0, 0}, 4, 5},
    {{1, 2, 3, 0, 1, 0}, 6, 6},
    {{2, 2, 2, 2, 2, 1}, 6, 7}
  };

bool		validate_players(t_incant *incant, t_tile *tile)
{
  t_list_item	*list;
  t_player	*player;

  if (get_tile_nb_player(tile->players.first) != incant->nb_players)
    return (false);
  list = tile->players.first;
  while (list)
    {
      player = (t_player *)list->data;
      if (player->lvl != incant->lvl)
	return (false);
      list = list->next;
    }
  return (true);
}

bool		validate_incant(t_player *player, t_incant *incant,
				t_map *map)
{
  int 		idx;

  idx = GET_INDEX(player->pos.x, player->pos.y, map->width);
  if (map->tiles[idx].linemate == incant->materials[0] &&
      map->tiles[idx].deraumere == incant->materials[1] &&
      map->tiles[idx].sibur == incant->materials[2] &&
      map->tiles[idx].mendiane == incant->materials[3] &&
      map->tiles[idx].phiras == incant->materials[4] &&
      map->tiles[idx].thystame == incant->materials[5] &&
      validate_players(incant, &map->tiles[idx]))
    return (true);
  return (false);
}

void 		increase_players_lvl(t_list_item *list)
{
  t_list_item	*players;
  t_player	*player;
  char 		*reply;

  players = list;
  while (players)
    {
      player = (t_player *)players->data;
      player->lvl++;
      reply = myalloc(strlen("Current level: \n") + 2);
      sprintf(reply, "Current level: %u\n", player->lvl);
      send_data(player->net->output, reply);
      free(reply);
      players = players->next;
    }
}

void		exec_check_incantation(t_player *player, t_map *map)
{
  unsigned int	i;
  t_command	*new_cmd;
  t_list_item	*item;

  i = 0;
  while (i < 7 && !validate_incant(player, &incantations[i], map))
    i++;
  if (i < 7)
    {
      item = map->tiles[GET_INDEX(player->pos.x, player->pos.y, map->width)].
	players.first;
      while (item != NULL)
	{
	  send_data(((t_player *)item->data)->net->output,
		    "Elevation underway\n");
	  item = item->next;
	}
      new_cmd = init_command("Incantation", g_frequency);
      new_cmd->type = INCANTATION;
      new_cmd->time_units = COMMAND_TIME(300, g_frequency);
      new_cmd->next = player->cmd_list->next;
      player->cmd_list->next = new_cmd;
    }
  else
    send_data(player->net->output, "ko\n");
}

void		exec_incantation(t_player *player, t_map *map)
{
  unsigned int	i;
  int 		idx;

  i = 0;
  idx = GET_INDEX(player->pos.x, player->pos.y, map->width);
  while (i < 7 && !validate_incant(player, &incantations[i], map))
    i++;
  if (i < 7)
    {
      increase_players_lvl(map->tiles[idx].players.first);
      consume_items(&map->tiles[idx], map);
    }
  else
    send_data(player->net->output, "ko\n");
}
