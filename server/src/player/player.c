/*
** chan_list.c for myirc in /home/baldas/Prog/repos/tek2/psu/PSU_2016_myirc/src/srv/chan_list
**
** Made by Hugo Baldassin
** Login   <baldas@epitech.net>
**
** Started on  Mon Jun  5 15:08:47 2017 Hugo Baldassin
** Last update Sun Jun 11 18:26:42 2017 Hugo Baldassin
*/

#include	 	<stdlib.h>
#include	 	<string.h>
#include	 	<errno.h>
#include	 	<stdio.h>
#include 	 	"player.h"
#include 	 	"utils.h"

static void		free_node(t_player *node)
{
  free(node);
}

t_player 		*init_player(t_pos *pos, t_team *team)
{
  t_player		*node;

  node = myalloc(sizeof(t_player));
  node->team = NULL;
  if (team)
    node->team = team;
  node->next = NULL;
  node->pos.x = pos->x;
  node->pos.y = pos->y;
  node->dir = (t_direction)(rand() % 4);
  node->cmd_list = NULL;
  node->life_time = CYCLE_FOOD;
  init_inventory(node->inventory);
  node->inventory[6].nb = 10;
  node->net = NULL;
  node->lvl = 1;
  node->id = 0;
  return (node);
}

void 			add_player(t_player **list, t_player *node)
{
  t_player		*tmp;

  tmp = (*list);
  if (!tmp)
  {
    (*list) = node;
    node->id = 1;
  }
  else
    {
      while (tmp->next)
    	tmp = tmp->next;
      tmp->next = node;
      node->id = tmp->id + 1;
    }
}

void			remove_player(t_player **list, t_player *player)
{
  t_player		*tmp;
  t_player		*node;

  node = (*list);
  if (node)
    {
      if (node == player)
	{
	  (*list) = (*list)->next;
	  free_node(node);
	}
      else
	{
	  while (node->next && node->next != player)
	    node = node->next;
	  if (node->next)
	    {
	      tmp = node->next;
	      node->next = node->next->next;
	      free_node(tmp);
	    }
	}
    }
}
