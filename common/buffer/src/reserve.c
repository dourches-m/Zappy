/*
** reserve.c for PSU_2016_myirc in /home/anthony/repository/PSU_2016_myirc/reserve.c
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.eu>
**
** Started on  sam. mai 27 17:45:00 2017 Anthony LECLERC
** Last update Sun Jul  2 19:22:40 2017 Anthony LECLERC
*/

#include	<stdio.h>
#include	"buffer/circbuffer.h"
#include	"buffer/bipbuffer.h"

char		*circbuffer_reserve(t_circbuff *self,
				    size_t requested,
				    size_t *reserved)
{
  char		*data;

  assert(self != NULL);
  assert(reserved != NULL);
  if (circbuffer_unused(self) == 0)
    {
      *reserved = 0;
      return (NULL);
    }
  if (self->b_used == BIP_B_UNUSED)
    {
      *reserved = (a_unused(self) > requested) ? requested : a_unused(self);
      data = self->a_end;
    }
  else
    {
      *reserved = (b_unused(self) > requested) ? requested : b_unused(self);
      data = self->b_end;
    }
  self->last_request = *reserved;
  return (data);
}
