/*
** bipbuffer.h.h for PSU_2016_myirc in /home/anthony/repository/PSU_2016_myirc/bipbuffer.h.h
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.eu>
**
** Started on  sam. mai 27 19:16:43 2017 Anthony LECLERC
** Last update sam. mai 27 19:16:43 2017 Anthony LECLERC
*/

#ifndef		BIPBUFFER_H_
# define	BIPBUFFER_H_

size_t		a_unused(t_circbuff const *circbuff);

size_t		b_unused(t_circbuff const *circbuff);

size_t		a_used(t_circbuff const *circbuff);

size_t		b_used(t_circbuff const *circbuff);

void		bip_switch_to_b(t_circbuff *circbuff);

int		bip_is_empty(t_circbuff const *circbuff);

#endif		/* BIPBUFFER_H_ */
