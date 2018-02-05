/*
** list_erase.c for PSU_2016_myirc in /home/anthony/repository/PSU_2016_myirc/list_erase.c
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.eu>
**
** Started on  mar. juin 06 10:43:03 2017 Anthony LECLERC
** Last update Sun Jul  2 19:35:10 2017 Anthony LECLERC
*/

#include		"list/list.h"

void			list_erase_item(t_list *list,
					void *data,
					t_item_delete del)
{
  t_list_item		*it;

  it = list->first;
  while (it != NULL)
    {
      if (it->data == data)
	{
	  it = list_extract(list, it);
	  list_item_delete(it, del);
	  return ;
	}
      it = it->next;
    }
}
