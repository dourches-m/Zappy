/*
** animations.c for zappy in /home/sylvain/PSU_2016_zappy/graphic_client/demo
**
** Made by Sylvain Chaugny
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Sun Jul  2 20:30:55 2017 Sylvain Chaugny
** Last update Sun Jul  2 21:01:47 2017 Sylvain Chaugny
*/

#include			<string.h>
#include			<unistd.h>
#include			<stdlib.h>
#include			"protocol.h"

void				demo_animation_1(int	fd)
{
  t_protocol_player		proto;
  t_protocol_base		base;
  enum e_player_direction	dir;

  memset(&proto, 0, sizeof(proto));
  memset(&base, 0, sizeof(base));
  dir = E_DIRECTION_EAST;
  proto.frame = 10;
  proto.action = E_PLAYER_MOVE;
  proto.player_id = 1;
  base.size = sizeof(base) + sizeof(proto) + sizeof(dir);
  base.type = E_CMD_PLAYER;
  write(fd, &base, sizeof(base));
  write(fd, &proto, sizeof(proto));
  write(fd, &dir, sizeof(dir));
  sleep(1);
  proto.frame = 15;
  write(fd, &base, sizeof(base));
  write(fd, &proto, sizeof(proto));
  write(fd, &dir, sizeof(dir));
  sleep(1);
  proto.frame = 20;
  write(fd, &base, sizeof(base));
  write(fd, &proto, sizeof(proto));
  write(fd, &dir, sizeof(dir));
}

void				demo_animation_2(int	fd)
{
  t_protocol_player		proto;
  t_protocol_base		base;
  enum e_player_direction	dir;

  memset(&proto, 0, sizeof(proto));
  memset(&base, 0, sizeof(base));
  dir = E_DIRECTION_SOUTH;
  proto.frame = 25;
  proto.action = E_PLAYER_MOVE;
  proto.player_id = 1;
  base.size = sizeof(base) + sizeof(proto) + sizeof(dir);
  base.type = E_CMD_PLAYER;
  write(fd, &base, sizeof(base));
  write(fd, &proto, sizeof(proto));
  write(fd, &dir, sizeof(dir));
  sleep(1);
  proto.frame = 30;
  write(fd, &base, sizeof(base));
  write(fd, &proto, sizeof(proto));
  write(fd, &dir, sizeof(dir));
  sleep(1);
  proto.frame = 35;
  write(fd, &base, sizeof(base));
  write(fd, &proto, sizeof(proto));
  write(fd, &dir, sizeof(dir));
}

void				demo_animation_3(int	fd)
{
  t_protocol_player		proto;
  t_protocol_base		base;
  enum e_player_direction	dir;

  sleep(1);
  memset(&proto, 0, sizeof(proto));
  memset(&base, 0, sizeof(base));
  dir = E_DIRECTION_SOUTH;
  proto.frame = 40;
  proto.player_id = 2;
  base.size = sizeof(base) + sizeof(proto) + sizeof(dir);
  base.type = E_CMD_PLAYER;
  proto.action = E_PLAYER_DIE;
  write(fd, &base, sizeof(base));
  write(fd, &proto, sizeof(proto));
}
