/*
** create.c for PSU_2016_myirc in /home/anthony/repository/PSU_2016_myirc/create.c
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.eu>
**
** Started on  jeu. mai 25 07:33:53 2017 Anthony LECLERC
** Last update Sun Jul  2 19:20:53 2017 Anthony LECLERC
*/

#include		<stdlib.h>
#include		<stdio.h>
#include		"buffer/circbuffer.h"

static size_t		buff_struct_size(size_t size)
{
  return (sizeof(t_circbuff) + size);
}

static void		set_circbuff_members(t_circbuff *circbuff)
{
  circbuff->end = circbuff->buff + circbuff->size;
  circbuff->b_end = circbuff->buff;
  circbuff->a_start = circbuff->buff;
  circbuff->a_end = circbuff->buff;
  circbuff->b_used = BIP_B_UNUSED;
  circbuff->last_request = 0;
}

t_circbuff		*circbuffer_create(size_t size)
{
  t_circbuff		*buffer;

  assert(size > sizeof(long));
  buffer = malloc(buff_struct_size(size) + 1);
  if (buffer == NULL)
    return (NULL);
  buffer->buff[size] = 0;
  buffer->size = size;
  set_circbuff_members(buffer);
  return (buffer);
}
