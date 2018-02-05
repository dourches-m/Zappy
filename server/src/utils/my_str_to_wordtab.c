/*
** my_str_to_wordtab.c for my_str_to_wordtab in /home/baldas/Prog/repos/psu/PSU_2015_minishell2
**
** Made by Hugo Baldassin
** Login   <baldas@epitech.net>
**
** Started on  Fri Apr 29 16:34:03 2016 Hugo Baldassin
** Last update Fri Apr 29 16:34:09 2016 Hugo Baldassin
*/

#include	<stdlib.h>
#include	<unistd.h>

#include 	"utils.h"

static int	count_words(char *str)
{
  int		i;
  int		count;

  i = 0;
  count = 0;
  while (str[i] != '\0')
    {
      if (str[i] != ' ' && str[i] != '\t' &&
	  (str[i + 1] == ' ' || str[i + 1] == '\t' || str[i + 1] == '\0'))
	count++;
      i++;
    }
  return (count);
}

static void	put_words(char **tab, char *str, int words)
{
  int		i;
  int		j;
  int		y;

  i = 0;
  y = 0;
  while (str[i] != '\0' && (y < words))
    {
      while (str[i] == ' ' || str[i] == '\t')
	i++;
      j = 0;
      while (str[i] != ' ' && str[i] != '\t' && str[i] != '\0')
	{
	  tab[y][j] = str[i];
	  i++;
	  j++;
	}
      tab[y][j] = '\0';
      y++;
    }
}

static int	malloc_words(char **tab, char *str, int words)
{
  int		i;
  int		j;
  int		y;

  i = 0;
  y = 0;
  while (str[i] != '\0' && (y < words))
    {
      while (str[i] == ' ' || str[i] == '\t')
	i++;
      j = i;
      while (str[i] != ' ' && str[i] != '\t' && str[i] != '\0')
	i++;
      tab[y] = myalloc((i - j + 1) * sizeof(char));
      y++;
    }
  return (0);
}

char		**my_str_to_wordtab(char *str)
{
  char		**tab;
  int		words;

  words = count_words(str);
  tab = myalloc((words + 1) * sizeof(char *));
  tab[words] = NULL;
  if (words != 0)
    {
      malloc_words(tab, str, words);
      put_words(tab, str, words);
    }
  return (tab);
}
