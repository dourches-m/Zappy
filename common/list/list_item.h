/*
** list_item.h for  in /home/anthony/documents/repository/PSU_2016_nmobjdump
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.net>
**
** Started on  Sun Feb 26 22:03:07 2017 Anthony LECLERC
** Last update Sun Jul  2 19:34:09 2017 Anthony LECLERC
*/

#ifndef			LIST_ITEM_H_
# define		LIST_ITEM_H_

# include		<stddef.h>

typedef void		*(*t_item_copy)(void *data, size_t size);
typedef int		(*t_item_cmp)(void *data, void *list_it);
typedef	int		(*t_item_mem)(void *);
typedef void		(*t_item_delete)(void *);
typedef void		(*t_item_iter)(void *);
typedef void		(*t_item_iteri)(unsigned int idx, void *);
typedef void		*(*t_item_map)(void *, size_t *outsize);

typedef t_item_cmp 	t_item_lower;
typedef t_item_cmp 	t_item_higher;
typedef t_item_cmp 	t_predicate;

typedef struct		s_list_item
{
  void			*data;
  size_t		size;
  struct s_list_item 	*next;
  struct s_list_item	*prev;
}			t_list_item;

t_list_item		*list_item_init(void *data, size_t size);

t_list_item		*list_item_set(void *data, size_t size);

t_list_item		*list_item_copy(t_list_item *item,
					t_item_copy cpy_data);

void			list_item_delete(t_list_item *item,
					 t_item_delete dtor);

#endif 			/* LIST_ITEM_H_ */
