/*
** free_tab.c for free_tab in /home/baldas/Prog/libs/libmy
**
** Made by Hugo Baldassin
** Login   <baldas_h@epitech.net>
**
** Started on  Tue Mar 15 18:20:08 2016 Hugo Baldassin
** Last update Tue Mar 15 18:21:52 2016 Hugo Baldassin
*/

#include	<stdlib.h>

void		free_2d_array(void **tab)
{
  int		y;

  y = 0;
  while (tab && tab[y] != NULL)
    {
      free(tab[y]);
      y++;
    }
  if (tab)
    free(tab);
}
