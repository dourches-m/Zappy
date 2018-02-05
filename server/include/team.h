/*
** team.h for psu_zappy in /home/baldas/Prog/repos/tek2/psu/PSU_2016_zappy
**
** Made by Hugo Baldassin
** Login   <baldas@epitech.net>
**
** Started on  Tue Jun 20 19:08:58 2017 Hugo Baldassin
** Last update Tue Jun 20 19:09:00 2017 Hugo Baldassin
*/

#ifndef 	ZAPPY_TEAM_H
# define 	ZAPPY_TEAM_H

# include	<stdint.h>
# include	"player.h"

typedef struct	s_player t_player;

typedef struct	s_team
{
  char 		*name;
  unsigned int	slots;
  unsigned int	nb_players;
  unsigned int	id;
  t_player	*player;
}		t_team;

t_team		*create_team(char const *name, uint32_t);
void		destruct_team(t_team *team);

#endif 		/* ZAPPY_TEAM_H */
