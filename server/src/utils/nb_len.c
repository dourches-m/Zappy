/*
** nb_len.c for psu_zappy in /home/baldas/Prog/repos/tek2/psu/PSU_2016_zappy/server/src
**
** Made by Hugo Baldassin
** Login   <baldas@epitech.net>
**
** Started on  Thu Jun 22 22:04:11 2017 Hugo Baldassin
** Last update Thu Jun 22 22:04:13 2017 Hugo Baldassin
*/

unsigned int 	nb_len(unsigned int nb)
{
  unsigned int	len;

  len = 0;
  while (nb > 0)
    {
      nb /= 10;
      len++;
    }
  return (len);
}