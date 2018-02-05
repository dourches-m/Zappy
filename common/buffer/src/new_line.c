/*
** has_new_line.c for PSU_2016_myirc in /home/anthony/repository/PSU_2016_myirc/has_new_line.c
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.eu>
**
** Started on  mar. juin 06 13:38:00 2017 Anthony LECLERC
** Last update Sun Jul  2 19:23:33 2017 Anthony LECLERC
*/

#include		<string.h>
#include		<stdlib.h>
#include		<stdio.h>
#include		"buffer/circbuffer.h"
#include		"buffer/bipbuffer.h"

char 			*next_newline(t_circbuff const *self,
				      char const *endl)
{
  char			*seek;
  size_t		len;

  len = strlen(endl);
  seek = self->a_start;
  while (seek != self->a_end)
    {
      if (strncmp(seek, endl, len) == 0)
	return (seek);
      seek++;
    }
  return (NULL);
}

bool			circbuffer_has_newline(t_circbuff const *self,
					       char const *endl)
{
  char const            *crlf;

  crlf = next_newline(self, endl);
  return (crlf != NULL);
}

char                    *circbuffer_get_newline(t_circbuff *self,
                                                size_t *size,
                                                char const *endl)
{
  char			*end;
  char			*line;

  end = next_newline(self, endl);
  *size = 0;
  line = NULL;
  if (end != NULL)
    {
      *size = end - self->a_start;
      line = malloc(*size + 1);
      if (line == NULL)
	exit(84);
      strncpy(line, self->a_start, *size);
      line[*size] = 0;
      circbuffer_discard(self, *size + strlen(endl));
    }
  return (line);
}
