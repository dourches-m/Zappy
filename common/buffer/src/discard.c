/*
** discard.c for PSU_2016_myirc in /home/anthony/repository/PSU_2016_myirc/discard.c
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.eu>
**
** Started on  sam. mai 27 19:50:52 2017 Anthony LECLERC
** Last update sam. mai 27 19:50:52 2017 Anthony LECLERC
*/

#include	<stdio.h>
#include	"buffer/circbuffer.h"
#include        "buffer/bipbuffer.h"

void		circbuffer_discard(t_circbuff *self, size_t size)
{
  assert(self != NULL);
  assert(size <= a_used(self));
  self->a_start += size;
  if (self->a_start == self->a_end)
  {
    if (self->b_used == BIP_B_USED)
    {
      self->a_start = self->buff;
      self->a_end = self->b_end;
      self->b_end = self->buff;
      self->b_used = BIP_B_UNUSED;
    }
    else
    {
      self->a_start = self->buff;
      self->a_end = self->buff;
    }
  }
  bip_switch_to_b(self);
}