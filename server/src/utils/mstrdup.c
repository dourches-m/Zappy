/*
** mstrdup.c for zappy in /home/anthony/repository/zappy/mstrdup.c
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.eu>
**
** Started on  mar. juin 20 04:11:16 2017 Anthony LECLERC
** Last update mar. juin 20 04:11:16 2017 Anthony LECLERC
*/

#include	<stdlib.h>
#include 	<assert.h>
#include 	<string.h>
#include 	<err.h>

char		*mstrdup(char const *str)
{
  char		*s;

  assert(str != NULL);
  s = strdup(str);
  if (s == NULL)
    {
      warn("strdup");
      exit(84);
    }
  return (s);
}