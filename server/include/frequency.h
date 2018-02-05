/*
** frequency.h for zappy in /home/anthony/repository/zappy/frequency.h
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.eu>
**
** Started on  mer. juin 28 13:21:49 2017 Anthony LECLERC
** Last update mer. juin 28 13:21:49 2017 Anthony LECLERC
*/

#ifndef 	FREQUENCY_H_
# define 	FREQUENCY_H_

# include	<stddef.h>
# include	<sys/time.h>
# include 	"list/list.h"

# define	COMMAND_TIME(t, f) (t * 1000000 / f)

size_t		get_elapsed_time(struct timeval *begin);

size_t		next_command_time(t_list *playerlist, t_list *egg);

int		init_timer();

size_t		get_timer();

void		pause_timer();

void		resume_timer();

extern size_t	g_frequency;

#endif 		/* FREQUENCY_H_ */
