/*
** switch.c for PSU_2016_myirc in /home/anthony/repository/PSU_2016_myirc/switch.c
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.eu>
**
** Started on  sam. mai 27 19:35:42 2017 Anthony LECLERC
** Last update sam. mai 27 19:35:42 2017 Anthony LECLERC
*/

#include		"buffer/circbuffer.h"
#include		"buffer/bipbuffer.h"

void			bip_switch_to_b(t_circbuff *self)
{
  if (a_unused(self) < b_unused(self))
    self->b_used = BIP_B_USED;
}