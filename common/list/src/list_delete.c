/*
** list_delete.c for  in /home/anthony/documents/repository/PSU_2016_nmobjdump
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.net>
**
** Started on  Sun Feb 26 21:46:33 2017 Anthony LECLERC
** Last update Sun Feb 26 23:37:15 2017 Anthony LECLERC
*/

#include	<stdlib.h>
#include	"list/list.h"

void		list_delete(struct s_list *list, t_item_delete it_del)
{
  t_list_item	*it;

  while (list->first)
    {
      it = list->first;
      list->first = it->next;
      list_item_delete(it, it_del);
    }
  free(list);
}
