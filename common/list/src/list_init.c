/*
** list_init.c for  in /home/anthony/documents/repository/PSU_2016_nmobjdump
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.net>
**
** Started on  Sun Feb 26 21:48:27 2017 Anthony LECLERC
** Last update Sun Jul  2 19:36:43 2017 Anthony LECLERC
*/

#include	<stdlib.h>
#include	"list/list.h"

t_list		*list_init()
{
  t_list	*list;

  list = malloc(sizeof(t_list));
  if (!list)
    exit(84);
  list->first = NULL;
  list->last = NULL;
  list->size = 0;
  return (list);
}
