/*
** pos.h for psu_zappy in /home/baldas/Prog/repos/tek2/psu/PSU_2016_zappy/server/src
**
** Made by Hugo Baldassin
** Login   <baldas@epitech.net>
**
** Started on  Wed Jun 21 13:31:28 2017 Hugo Baldassin
** Last update Wed Jun 21 13:31:29 2017 Hugo Baldassin
*/

#ifndef 	ZAPPY_POS_H
# define 	ZAPPY_POS_H

# include	<stdint.h>

# ifndef	GET_X
#  define	GET_X(INDEX, MAP_WIDTH)		(INDEX % MAP_WIDTH)
# endif		/* !GET_X */

# ifndef	GET_Y
#  define	GET_Y(INDEX, MAP_WIDTH)		(INDEX / MAP_WIDTH)
# endif		/* !GET_Y */

# ifndef	GET_INDEX
#  define	GET_INDEX(X, Y, MAP_WIDTH)	(X * MAP_WIDTH + Y)
# endif		/* !GET_INDEX */

typedef struct	s_pos
{
  int32_t 	x;
  int32_t	y;
}		t_pos;

#endif 		/* !ZAPPY_POS_H */
