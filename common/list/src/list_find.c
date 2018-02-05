/*
** list_find.c for PSU_2016_lemipc in /home/anthony/repository/PSU_2016_lemipc/list_find.c
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.eu>
**
** Started on  ven. mars 31 10:42:41 2017 Anthony LECLERC
** Last update Sun Jul  2 19:36:11 2017 Anthony LECLERC
*/

#include		"list/list.h"

t_list_item		*list_find_item(struct s_list *list,
					void *item,
					t_predicate cmp)
{
  t_list_item		*it;

  it = list->first;
  while (it != NULL)
    {
      if (cmp(item, it->data) == 1)
	{
	  return (it);
	}
      it = it->next;
    }
  return (NULL);
}

void			*list_find(struct s_list *list,
				   void *data,
				   t_predicate cmp)
{
  t_list_item		*item;

  item = list_find_item(list, data, cmp);
  if (item == NULL)
    return (NULL);
  return (item->data);
}
