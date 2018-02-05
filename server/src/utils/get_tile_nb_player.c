/*
** get_tile_nb_player.c for psu_zappy in /home/baldas/Prog/repos/tek2/psu/PSU_2016_zappy
**
** Made by Hugo Baldassin
** Login   <baldas@epitech.net>
**
** Started on  Sat Jun 24 18:16:34 2017 Hugo Baldassin
** Last update Sat Jun 24 18:16:35 2017 Hugo Baldassin
*/

#include 	"list/list_item.h"

unsigned int	get_tile_nb_player(t_list_item *players)
{
  t_list_item	*list;
  unsigned int	size;

  list = players;
  size = 0;
  while (list)
    {
      list = list->next;
      size++;
    }
  return (size);
}