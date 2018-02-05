/*
** front.c for PSU_2016_myirc in /home/anthony/repository/PSU_2016_myirc/front.c
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.eu>
**
** Started on  sam. mai 27 20:51:25 2017 Anthony LECLERC
** Last update sam. mai 27 20:51:25 2017 Anthony LECLERC
*/

#include	"buffer/circbuffer.h"
#include	"buffer/bipbuffer.h"

void		*circbuffer_front(t_circbuff *buff, size_t *size)
{
  assert(buff != NULL);
  assert(size != NULL);
  if (bip_is_empty(buff))
    return (NULL);
  *size = a_used(buff);
  return (buff->a_start);
}