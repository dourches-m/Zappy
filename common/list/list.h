/*
** list.h for  in /home/anthony/documents/repository/PSU_2016_nmobjdump
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.net>
**
** Started on  Sun Feb 26 22:00:48 2017 Anthony LECLERC
** Last update Sun Jul  2 19:30:47 2017 Anthony LECLERC
*/

#ifndef		LIST_H_
# define	LIST_H_

# include	"list_item.h"

typedef struct	s_list
{
  size_t	size;
  t_list_item	*first;
  t_list_item	*last;
}		t_list;

struct s_list	*list_init();

void		list_delete(struct s_list *list, t_item_delete it_del);

int		list_pushback_item(struct s_list *list,
				   struct s_list_item *item);

int		list_pushback_data(struct s_list *list,
				   void *data,
				   size_t size);

int		list_pushfront_item(struct s_list *list,
				    struct s_list_item *item);

int		list_pushfront_data(struct s_list *list,
				    void *data,
				    size_t size);

t_list_item	*list_find_item(struct s_list *list,
				void *data,
				t_predicate cmp);

void		*list_find(struct s_list *list,
			   void *data,
			   t_predicate cmp);

void		list_erase_item(struct s_list *list,
				void *data,
				t_item_delete del);

t_list_item	*list_extract(t_list *list, t_list_item *item);

t_list_item	*list_remove(t_list *list, void *data);

#endif 		/* LIST_H_ */
