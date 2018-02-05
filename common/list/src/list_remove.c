/*
** list_remove.c for zappy in /home/anthony/repository/zappy/list_remove.c
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.eu>
**
** Started on  jeu. juin 29 03:42:49 2017 Anthony LECLERC
** Last update Sun Jul  2 19:38:29 2017 Anthony LECLERC
*/

#include	"list/list.h"

t_list_item	*list_remove(t_list *list, void *data)
{
  t_list_item	*item;

  item = list->first;
  while (item != NULL)
    {
      if (item->data == data)
	return (list_extract(list, item));
      item = item->next;
    }
  return (NULL);
}
