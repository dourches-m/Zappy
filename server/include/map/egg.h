/*
** egg.h for zappy in /home/anthony/repository/zappy/egg.h
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.eu>
**
** Started on  lun. juin 26 11:55:24 2017 Anthony LECLERC
** Last update lun. juin 26 11:55:24 2017 Anthony LECLERC
*/

#ifndef 		EGG_H_
# define 		EGG_H_

# include		"team.h"
# include 		"pos.h"

typedef struct		s_egg
{
  t_pos			pos;
  size_t		hatch;
  unsigned long		id;
  t_team		*team;
  bool			hatched;
}			t_egg;

# define		CYCLE_TO_HATCH	600

void			spawn_egg(t_map *map, t_team *owner,
				  t_pos const *pos);

int			is_hatch_time(t_egg const *egg);

void			egg_update(t_egg *egg, size_t elapsed_time);

t_egg			*get_team_egg(char const *team, t_list_item *eggs);

#endif 			/* EGG_H_ */
