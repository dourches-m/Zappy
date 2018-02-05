/*
** compare.c for zappy in /home/anthony/repository/zappy/compare.c
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.eu>
**
** Started on  mar. juin 20 02:29:05 2017 Anthony LECLERC
** Last update mar. juin 20 02:29:05 2017 Anthony LECLERC
*/

#include 	<string.h>

int		compare(char const *s1, char const *s2)
{
  return (strcmp(s1, s2) == 0);
}