/*
** circbuffer.hpp for PSU_2016_myirc in /home/anthony/repository/PSU_2016_myirc/circbuffer.hpp
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.eu>
**
** Started on  jeu. mai 25 07:35:59 2017 Anthony LECLERC
** Last update Sun Jul  2 19:27:17 2017 Anthony LECLERC
*/

#ifndef 	CIRCBUFFER_H_
# define	CIRCBUFFER_H_

# include	<stddef.h>
# include	<assert.h>
# include 	<stdbool.h>

# define	BIP_B_UNUSED	0
# define	BIP_B_USED	1

typedef struct	s_circbuff
{
  char		*end;
  char		*a_start;
  char		*a_end;
  char		*b_end;
  size_t	size;
  size_t	last_request;
  int		b_used;
  char		buff[];
}		t_circbuff;

t_circbuff	*circbuffer_create(size_t size);

void		circbuffer_delete(t_circbuff *self);

size_t		circbuffer_unused(t_circbuff const *self);

char		*circbuffer_reserve(t_circbuff *self, size_t requested,
				    size_t *reserved);

void		circbuffer_push(t_circbuff *self, size_t size);

void		circbuffer_discard(t_circbuff *self, size_t size);

void		*circbuffer_front(t_circbuff *self, size_t *size);

bool		circbuffer_isempty(t_circbuff const *self);

char		*circbuffer_get_newline(t_circbuff *self, size_t *size,
					char const *endl);

bool		circbuffer_has_newline(t_circbuff const *self,
				       char const *endl);

size_t		circbuffer_append(t_circbuff *self, char const *s);

size_t		circbuffer_append_n(t_circbuff *self, void const *data,
				    size_t n);

size_t		circbuffer_extract(t_circbuff *self, char *s,
				   size_t size);

#endif		/* CIRCBUFFER_H_ */
