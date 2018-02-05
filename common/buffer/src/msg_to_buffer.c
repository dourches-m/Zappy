/*
** msg_to_buffer.c for zappy in /home/anthony/repository/zappy/msg_to_buffer.c
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.eu>
**
** Started on  ven. juin 23 16:34:29 2017 Anthony LECLERC
** Last update Sun Jul  2 19:21:57 2017 Anthony LECLERC
*/

#include	<string.h>
#include	"buffer/circbuffer.h"

size_t		circbuffer_append_n(t_circbuff *self, void const *data,
				    size_t n)
{
  char		*buff;
  size_t	reserved;

  buff = circbuffer_reserve(self, n, &reserved);
  if (reserved < n)
    return (n - reserved);
  memcpy(buff, data, n);
  circbuffer_push(self, n);
  return (0);
}

size_t		circbuffer_append(t_circbuff *self, char const *s)
{
  char		*buff;
  size_t	reserved;
  size_t	len;

  len = strlen(s);
  buff = circbuffer_reserve(self, len, &reserved);
  if (reserved < len)
    return (len - reserved);
  strncpy(buff, s, len);
  circbuffer_push(self, len);
  return (0);
}
