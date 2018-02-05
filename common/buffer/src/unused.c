/*
** unused.c for PSU_2016_myirc in /home/anthony/repository/PSU_2016_myirc/unused.c
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.eu>
**
** Started on  sam. mai 27 19:19:50 2017 Anthony LECLERC
** Last update sam. mai 27 19:19:50 2017 Anthony LECLERC
*/

#include	"buffer/circbuffer.h"

size_t		a_unused(t_circbuff const *self)
{
  return (self->end - self->a_end);
}

size_t	        b_unused(t_circbuff const *self)
{
  return (self->a_start - self->b_end);
}

size_t          circbuffer_unused(t_circbuff const *self)
{
  return (a_unused(self) + b_unused(self));
}

bool            circbuffer_isempty(t_circbuff const *self)
{
  return (circbuffer_unused(self) == self->size);
}

