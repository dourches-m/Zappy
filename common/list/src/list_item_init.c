/*
** list_item_init.c for  in /home/anthony/documents/repository/PSU_2016_nmobjdump
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.net>
**
** Started on  Sun Feb 26 21:50:35 2017 Anthony LECLERC
** Last update Sun Jul  2 19:37:41 2017 Anthony LECLERC
*/

#include		<stdlib.h>
#include		<memory.h>
#include		"list/list_item.h"

static void		*l_memdup(void *data, size_t length)
{
  void			*dup;

  dup = malloc(length);
  if (!dup)
    return (NULL);
  memcpy(dup, data, length);
  return (dup);
}

t_list_item		*list_item_alloc()
{
  t_list_item		*bloc;

  bloc = malloc(sizeof(t_list_item));
  if (!bloc)
    return (NULL);
  memset(bloc, 0, sizeof(t_list_item));
  return (bloc);
}

t_list_item		*list_item_init(void *data, size_t size)
{
  t_list_item		*item;

  item = list_item_alloc();
  if (!item)
    return (NULL);
  item->data = data;
  item->size = size;
  return (item);
}

t_list_item		*list_item_set(void *data, size_t size)
{
  t_list_item           *item;

  item = list_item_alloc();
  if (!item)
    return (NULL);
  item->data = l_memdup(data, size);
  if (item->data == NULL)
    return (NULL);
  item->size = size;
  return (item);
}

t_list_item		*list_item_copy(t_list_item *item, t_item_copy cpy)
{
  t_list_item		*copy;

  if (!item)
    return (NULL);
  if (!cpy)
    cpy = l_memdup;
  copy = list_item_init(cpy(item->data, item->size), item->size);
  return (copy);
}
