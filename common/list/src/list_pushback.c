/*
** list_pushback.c for  in /home/anthony/documents/repository/PSU_2016_nmobjdump
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.net>
**
** Started on  Sun Feb 26 21:52:44 2017 Anthony LECLERC
** Last update Sun Jul  2 19:38:02 2017 Anthony LECLERC
*/

#include	"list/list.h"

int		list_pushback_item(struct s_list *list,
				   struct s_list_item *item)
{
  if (item == NULL)
    return (1);
  list->size += 1;
  if (!list->first)
    {
      list->first = item;
      list->last = item;
      item->next = NULL;
      item->prev = NULL;
    }
  else
    {
      list->last->next = item;
      item->prev = list->last;
      list->last = item;
      list->last->next = NULL;
    }
  return (0);
}

int		list_pushback_data(struct s_list *list,
				   void *data,
				   size_t size)
{
  t_list_item	*inserted;

  inserted = list_item_init(data, size);
  if (!inserted)
    return (1);
  return (list_pushback_item(list, inserted));
}
