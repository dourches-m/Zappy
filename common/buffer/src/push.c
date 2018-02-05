/*
** push.c for PSU_2016_myirc in /home/anthony/repository/PSU_2016_myirc/push.c
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.eu>
**
** Started on  sam. mai 27 18:05:56 2017 Anthony LECLERC
** Last update Sun Jul  2 19:24:33 2017 Anthony LECLERC
*/

#include	"buffer/circbuffer.h"
#include	"buffer/bipbuffer.h"

void		circbuffer_push(t_circbuff *self, size_t size)
{
  assert(self != NULL);
  assert(size <= self->last_request);
  size = (self->last_request > size) ? size : self->last_request;
  if (self->b_used == BIP_B_UNUSED)
    {
      self->a_end += size;
    }
  else
    {
      self->b_end += size;
    }
  self->last_request = 0;
  bip_switch_to_b(self);
}
