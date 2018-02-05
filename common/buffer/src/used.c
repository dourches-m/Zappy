/*
** used.c for PSU_2016_myirc in /home/anthony/repository/PSU_2016_myirc/used.c
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.eu>
**
** Started on  sam. mai 27 19:55:25 2017 Anthony LECLERC
** Last update sam. mai 27 19:55:25 2017 Anthony LECLERC
*/

#include	"buffer/circbuffer.h"

size_t		a_used(t_circbuff const *self)
{
  return (self->a_end - self->a_start);
}

size_t		b_used(t_circbuff const *self)
{
  return (self->b_end - self->buff);
}

int		bip_is_empty(t_circbuff const *self)
{
  return (self->a_end == self->a_start);
}