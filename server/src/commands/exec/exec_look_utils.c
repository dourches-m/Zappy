/*
** exec_look_utils.c for psu_zappy in /home/baldas/Prog/repos/tek2/psu/PSU_2016_zappy/server
**
** Made by Hugo Baldassin
** Login   <baldas@epitech.net>
**
** Started on  Mon Jun 26 13:02:38 2017 Hugo Baldassin
** Last update Tue Jun 27 00:12:17 2017 Hugo Baldassin
*/

#include 	"player.h"

void 		look_down(t_player *player, t_map *map, char **reply)
{
  int 		depth;
  t_pos		view;

  depth = 0;
  while (depth <= (int)player->lvl)
    {
      view.x = player->pos.x + depth;
      view.y = player->pos.y + depth;
      while (view.x >= (player->pos.x - depth))
	{
	  get_tile_content(map, &view, reply);
	  view.x--;
	}
      depth++;
    }
}

void 		look_up(t_player *player, t_map *map, char **reply)
{
  int 		depth;
  t_pos		view;

  depth = 0;
  while (depth <= (int)player->lvl)
    {
      view.x = player->pos.x - depth;
      view.y = player->pos.y - depth;
      while (view.x <= (player->pos.x + depth))
	{
	  get_tile_content(map, &view, reply);
	  view.x++;
	}
      depth++;
    }
}

void 		look_left(t_player *player, t_map *map, char **reply)
{
  int 		depth;
  t_pos		view;

  depth = 0;
  while (depth <= (int)player->lvl)
    {
      view.x = player->pos.x - depth;
      view.y = player->pos.y + depth;
      while (view.y >= (player->pos.y - depth))
	{
	  get_tile_content(map, &view, reply);
	  view.y--;
	}
      depth++;
    }
}

void 		look_right(t_player *player, t_map *map, char **reply)
{
  int 		depth;
  t_pos		view;

  depth = 0;
  while (depth <= (int)player->lvl)
    {
      view.x = player->pos.x + depth;
      view.y = player->pos.y - depth;
      while (view.y <= (player->pos.y + depth))
	{
	  get_tile_content(map, &view, reply);
	  view.y++;
	}
      depth++;
    }
}
