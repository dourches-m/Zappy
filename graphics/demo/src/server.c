/*
** server.c for zappy in /home/sylvain/PSU_2016_zappy/graphic_client
**
** Made by Sylvain Chaugny
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Sun Jul  2 19:30:31 2017 Sylvain Chaugny
** Last update Sun Jul  2 21:03:49 2017 Sylvain Chaugny
*/

#include		<stdlib.h>
#include		<stdio.h>
#include		<string.h>
#include		<unistd.h>
#include		"protocol.h"

void			demo_send_data_players(int		fd)
{
  t_player_infos	player;

  memset(&player, 0, sizeof(player));
  player.level = 1;
  player.id = 1;
  player.pos.x = 1;
  player.pos.y = 2;
  player.dir = E_DIRECTION_EAST;
  player.team_id = 6;
  write(fd, &player, sizeof(player));
  player.level = 2;
  player.id = 2;
  player.pos.x = 3;
  player.pos.y = 4;
  player.dir = E_DIRECTION_NORTH;
  player.team_id = 6;
  write(fd, &player, sizeof(player));
}

void			demo_send_data_teams(int		fd)
{
  t_team_infos		team;

  memset(&team, 0, sizeof(team));
  team.team_id = 6;
  sprintf(team.name, "Team 1");
  team.max_slots = 3;
  team.free_slots = 1;
  write(fd, &team, sizeof(team));
  team.team_id = 5;
  sprintf(team.name, "Team 2");
  team.free_slots = 3;
  team.max_slots = 3;
  write(fd, &team, sizeof(team));
}

void			demo_send_data_cells(int		fd,
					     t_protocol_data	*data,
					     t_cell		*cells)
{
  t_position		pos;

  pos.y = 0;
  while (pos.y < data->dimensions.height)
    {
      pos.x = 0;
      while (pos.x < data->dimensions.width)
	{
	  cells[pos.y * data->dimensions.height + pos.x].pos.x = pos.x;
	  cells[pos.y * data->dimensions.height + pos.x].pos.y = pos.y;
	  cells[pos.y * data->dimensions.height + pos.x].
	    ressources[rand() % E_RESSOURCES] = 1;
	  cells[pos.y * data->dimensions.height + pos.x].
	    ressources[rand() % E_RESSOURCES] = 1;
	  write(fd, &cells[pos.y * data->dimensions.height + pos.x],
		sizeof(t_cell));
	  pos.x++;
	}
      pos.y++;
    }
}

void			demo_send_data(int	fd)
{
  t_protocol_base	base;
  t_protocol_data	data;
  t_cell		cells[540];

  memset(cells, 0, sizeof(t_cell) * 540);
  data.nb_player = 2;
  data.nb_egg = 0;
  data.nb_team = 2;
  data.dimensions.width = 45;
  data.dimensions.height = 12;
  data.init_frame = 0;
  base.type = E_CMD_DATA;
  base.size = sizeof(base) + sizeof(cells) + 3 * sizeof(t_player_infos) +
    2 * sizeof(t_team_infos);
  write(fd, &base, sizeof(base));
  write(fd, &data, sizeof(data));
  demo_send_data_cells(fd, &data, cells);
  demo_send_data_players(fd);
  demo_send_data_teams(fd);
}
