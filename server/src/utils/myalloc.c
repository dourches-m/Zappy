/*
** myalloc.c for zappy in /home/anthony/repository/zappy/myalloc.c
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.eu>
**
** Started on  mar. juin 20 02:36:40 2017 Anthony LECLERC
** Last update Fri Jun 30 14:25:14 2017 Hugo Baldassin
*/

#include 	<stdlib.h>
#include 	<err.h>

void		*myalloc(size_t size)
{
  void		*ret;

  ret = malloc(size);
  if (ret == NULL)
    {
      warn("Allocation error");
      exit(84);
    }
  return (ret);
}

void		*mcalloc(size_t size)
{
  void		*ret;

  ret = calloc(1, size);
  if (ret == NULL)
  {
    warn("calloc");
    exit(1);
  }
  return (ret);
}
