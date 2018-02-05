/*
** list_item_delete.c for  in /home/anthony/documents/repository/PSU_2016_nmobjdump
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.net>
**
** Started on  Sun Feb 26 21:50:17 2017 Anthony LECLERC
** Last update Sun Feb 26 21:50:28 2017 Anthony LECLERC
*/

#include	<stdlib.h>
#include	"list/list_item.h"


void		list_item_delete(t_list_item *item, t_item_delete dtor)
{
  if (item)
    {
      if (dtor)
	dtor(item->data);
      free(item);
    }
}
