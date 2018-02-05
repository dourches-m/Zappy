/*
** list_extract.c for zappy in /home/anthony/repository/zappy/list_extract.c
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.eu>
**
** Started on  sam. juin 24 18:50:48 2017 Anthony LECLERC
** Last update Sun Jul  2 19:35:39 2017 Anthony LECLERC
*/

#include	<stdio.h>
#include	<assert.h>
#include	"list/list.h"

t_list_item	*list_extract(t_list *list, t_list_item *item)
{
  assert(item != NULL);
  if (list->size)
    {
      if (item->prev)
        item->prev->next = item->next;
      else
        list->first = item->next;
      if (item->next)
        item->next->prev = item->prev;
      else
        list->last = item->prev;
      list->size -= 1;
      if (list->size == 0)
        {
          list->first = NULL;
          list->last = NULL;
        }
    }
  return (item);
}
