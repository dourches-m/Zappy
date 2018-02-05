/*
** update.c for zappy in /home/anthony/repository/zappy/update.c
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.eu>
**
** Started on  lun. juin 26 13:02:17 2017 Anthony LECLERC
** Last update Fri Jun 30 14:07:34 2017 Hugo Baldassin
*/

#include 	<stdlib.h>
#include	<stdio.h>
#include	"debug.h"
#include 	"frequency.h"
#include 	"serverinfo.h"

static int	skip_command(t_player *player)
{
  if (player->cmd_list == NULL)
    return (1);
  if (player->cmd_list->active == false)
  {
    CMDLOG("[SKIP COMMAND] :: Next command ==> Executed next tick\n");
    player->cmd_list->active = true;
    return (1);
  }
  return (0);
}

int		feed_player(t_player *player, size_t elapsedtime,
                            size_t frequency)
{
  if (elapsedtime > player->life_time)
  {
    if (player->inventory[FOOD].nb > 0)
    {
      player->inventory[FOOD].nb -= 1;
      player->life_time = COMMAND_TIME(CYCLE_FOOD, frequency) -
	(elapsedtime - player->life_time);
      DLOG("PLAYER: Lost: %zu ; Cycles left: %zu\n",
	   elapsedtime, player->life_time);
      DLOG("[PLAYER] :: Food remaining :: %u\n", player->inventory[FOOD].nb);
      return (0);
    }
    else
      return (1);
  }
  player->life_time -= elapsedtime;
  return (0);
}

static void	player_killed(t_zserver *server, t_player *player)
{
  printf("Remove from list tile\n");
  list_remove(&server->map->tiles[GET_INDEX(player->pos.x,
					    player->pos.y,
					    server->map->width)].players,
	      player);
  printf("Remove from list map\n");
  list_erase_item(server->map->players, player, NULL);
  printf("LIST: MAP LIST PLAYER SIZE= %zu\n", server->map->players->size);
  player->team->nb_players--;
  remove_player(&player->team->player, player);
  SERVLOG("[SERVER]: Player deconnection\n");
}

void		handle_next_command(t_zserver *server, t_player *player,
				    size_t elapsed)
{
  if (skip_command(player))
    return ;
  while (player->cmd_list != NULL && player->cmd_list->time_units <= elapsed)
  {
    CMDLOG("[EXEC COMMAND] :: Execution    ::\n");
    CMDLOG("[EXEC COMMAND] :: Time left    :: %zu\n", player->cmd_list->time_units);
    CMDLOG("[EXEC COMMAND] :: Elapsed time :: %zu\n\n", elapsed);
    exec_command(player, server->map);
    elapsed -= player->cmd_list->time_units;
    pop_command(&player->cmd_list);
  }
  if (player->cmd_list != NULL)
  {
    CMDLOG("[WAIT COMMAND] :: Waiting left time :: %zu :=: Time left before execution\n",
	 player->cmd_list->time_units);
    CMDLOG("[WAIT COMMAND] :: Elapsed time :: %zu\n", elapsed);
    if (elapsed <= player->cmd_list->time_units)
      player->cmd_list->time_units -= elapsed;
  }
}

void		player_update(t_zserver *server, t_player *player,
			      size_t timespend)
{
  if (feed_player(player, timespend, g_frequency) == 1)
  {
    player_dies(server, player);
    return ;
  }
  if (player->net == NULL)
  {
    player_killed(server, player);
    return ;
  }
  handle_next_command(server, player, timespend);
  if (!circbuffer_isempty(player->net->output))
  {
    DPLOG("[PLAYER]: Data to send\n");
    select_add(&server->selector, &player->net->socket.socket, WRITE_SELECT);
  }
  else
  {
    DPLOG("[PLAYER]: Remove waiting to send\n");
    select_remove(&server->selector, &player->net->socket.socket);
    select_add(&server->selector, &player->net->socket.socket, READ_SELECT);
  }
}