/*
** concat_strings.c for psu_zappy in /home/baldas/Prog/repos/tek2/psu/PSU_2016_zappy/server
**
** Made by Hugo Baldassin
** Login   <baldas@epitech.net>
**
** Started on  Mon Jun 26 14:23:33 2017 Hugo Baldassin
** Last update Mon Jun 26 14:23:33 2017 Hugo Baldassin
*/

#include 	<stdio.h>
#include 	<stdlib.h>
#include 	<string.h>

#include 	"utils.h"

char 		*concat_strings(char *str1, char *str2, char *separators)
{
  char		*res;

  if (!str1)
    {
      res = mcalloc(strlen(str2) + strlen(separators) + 1);
      if (strlen(separators))
        res = strcat(res, separators);
      res = strcat(res, str2);
    }
  else
    {
      res = mcalloc(strlen(str1) + strlen(str2) + strlen(separators) + 1);
      res = strcat(res, str1);
      if (strlen(separators))
        res = strcat(res, separators);
      res = strcat(res, str2);
      free(str1);
    }
  return (res);
}