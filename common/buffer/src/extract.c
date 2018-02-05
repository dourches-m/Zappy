/*
** extract.c for zappy in /home/anthony/repository/zappy/extract.c
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.eu>
**
** Started on  ven. juin 23 16:42:57 2017 Anthony LECLERC
** Last update Sun Jul  2 19:21:26 2017 Anthony LECLERC
*/

#include		<string.h>
#include		"buffer/circbuffer.h"
#include		"buffer/bipbuffer.h"

size_t			circbuff_extract(t_circbuff *self,
					 void *dest,
					 size_t n)
{
  char			*buff;
  size_t		rq;

  if (a_used(self) + b_used(self) < n)
    return (n - (a_used(self) + b_used(self)));
  buff = circbuffer_front(self, &rq);
  if (n > rq)
    {
      memcpy(dest, buff, rq);
      circbuffer_discard(self, rq);
      dest += rq;
      buff = circbuffer_front(self, &rq);
      memcpy(dest, buff, rq);
    }
  else
    {
      memcpy(dest, buff, n);
      circbuffer_discard(self, n);
    }
  return (0);
}
