/*
** exec_broadcast.c for psu_zappy in /home/baldas/Prog/repos/tek2/psu/PSU_2016_zappy/server/src/commands
**
** Made by Hugo Baldassin
** Login   <baldas@epitech.net>
**
** Started on  Thu Jun 22 14:13:55 2017 Hugo Baldassin
** Last update Thu Jun 22 14:13:56 2017 Hugo Baldassin
*/

#include 	<math.h>
#include 	<string.h>
#include 	<stdio.h>
#include 	<stdlib.h>

#include 	"commands.h"
#include 	"utils.h"

void 		find_shortest_way(t_pos *pos1, t_pos *pos2, t_map *map)
{
  if (ABS(pos2->x - pos1->x) > (map->width / 2))
    {
      if (pos2->x > pos1->x)
	pos1->x += map->width;
      else
	pos2->x += map->width;
    }
  if (ABS(pos2->y - pos1->y) > (map->height / 2))
    {
      if (pos2->y > pos1->y)
	pos1->y += map->height;
      else
	pos2->y += map->height;
    }
}

void 		send_message(t_player *receiver, int dir, char *msg)
{
  int 		real_dir;
  char 		*reply;
  size_t 	len;

  len = strlen(msg) + strlen("message , \n") + 2;
  reply = myalloc(len);
  real_dir = dir + 2 * receiver->dir;
  if (real_dir > 8)
    real_dir -= 8;
  if (dir != 0)
    snprintf(reply, len, "message %d, %s\n", real_dir, msg);
  else
    snprintf(reply, len, "message 0, %s\n", msg);
  if (receiver->net)
    send_data(receiver->net->output, reply);
  free(reply);
}

double 		determine_angle(t_pos *player_pos, t_pos *rcv_pos, t_map *map)
{
  int		dif;
  double 	ret;
  t_pos		pos1;
  t_pos		pos2;

  pos1.x = player_pos->x;
  pos1.y = player_pos->y;
  pos2.x = rcv_pos->x;
  pos2.y = rcv_pos->y;
  find_shortest_way(&pos1, &pos2, map);
  printf("P1: %d %d, P2: %d %d\n", pos1.x, pos1.y, pos2.x, pos2.y);
  dif = pos2.y - pos1.y;
  pos2.y = pos1.y - dif;
  ret = atan2 (pos1.y - pos2.y, pos1.x - pos2.x);
  if (ret < 0)
    ret += 2 * M_PI;
  ret *= 180.0 / M_PI;
  return (ret);
}

void 		broadcast_message(t_player *player, t_player *receiver,
				  char *msg, t_map *map)
{
  double 	angle;

  angle = determine_angle(&player->pos, &receiver->pos, map);
  printf("Degrees: %f\n", angle);
  if (angle >= 67.5 && angle < 112.5)
    send_message(receiver, 1, msg);
  else if (angle >= 112.5 && angle < 157.5)
    send_message(receiver, 2, msg);
  else if (angle >= 157.5 && angle < 202.5)
    send_message(receiver, 3, msg);
  else if (angle >= 202.5 && angle < 247.5)
    send_message(receiver, 4, msg);
  else if (angle >= 247.5 && angle < 292.5)
    send_message(receiver, 5, msg);
  else if (angle >= 292.5 && angle < 337.5)
    send_message(receiver, 6, msg);
  else if ((angle >= 337.5 && angle <= 360) || (angle >= 0 && angle < 22.5))
    send_message(receiver, 7, msg);
  else if (angle >= 22.5 && angle < 67.5)
    send_message(receiver, 8, msg);
}

void		exec_broadcast(t_player *player, t_map *map)
{
  t_list_item	*players;
  t_player	*tmp;

  players = map->players->first;
  if (!player->cmd_list->arg)
    send_data(player->net->output, "ko\n");
  else
    {
      while (players)
        {
          tmp = (t_player *)(players->data);
          if (tmp != player)
            {
              if (tmp->pos.x != player->pos.x || tmp->pos.y != player->pos.y)
                broadcast_message(player, tmp, player->cmd_list->arg, map);
              else
                send_message(tmp, 0, player->cmd_list->arg);
            }
          players = players->next;
        }
      send_data(player->net->output, "ok\n");
    }
}
