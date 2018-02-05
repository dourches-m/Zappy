/*
** utils.h for zappy in /home/anthony/repository/zappy/utils.h
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.eu>
**
** Started on  mar. juin 20 02:37:42 2017 Anthony LECLERC
** Last update mar. juin 20 02:37:42 2017 Anthony LECLERC
*/

#ifndef 	UTILS_H_
# define 	UTILS_H_

# include 	<stddef.h>

# include	"player.h"

# ifndef	ABS
#  define	ABS(nb)		(((nb) < 0) ? -(nb) : (nb))
# endif		/* !ABS */

void		*myalloc(size_t size);
void		*mcalloc(size_t size);
char		*mstrdup(char const *s);
void		init_rand();
void 		free_2d_array(void **tab);
void 		send_data(t_circbuff *circbuff, char *reply);
unsigned int	nb_len(unsigned int nb);
char 		**my_str_to_wordtab(char *str);
unsigned int	get_tile_nb_player(t_list_item *players);
void 		send_to_players(t_list_item *list, char *reply);
char 		*concat_strings(char *format, char *str1, char *str2);
void 		convert_to_real_pos(t_pos *pos, t_map *map);
void		spawn_resource(t_map *map, t_item_type type, int quantity);

#endif 		/* UTILS_H_ */
