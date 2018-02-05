/*
** send_data.c for psu_zappy in /home/baldas/Prog/repos/tek2/psu/PSU_2016_zappy/server
**
** Made by Hugo Baldassin
** Login   <baldas@epitech.net>
**
** Started on  Thu Jun 22 20:12:13 2017 Hugo Baldassin
** Last update Thu Jun 22 20:12:25 2017 Hugo Baldassin
*/

#include 	<string.h>

#include 	"player.h"

void 		send_data(t_circbuff *circbuff, char *reply)
{
  char 		*reserve;
  unsigned int	i;
  size_t 	res_bytes;

  i = 0;
  reserve = circbuffer_reserve(circbuff, strlen(reply), &res_bytes);
  while (i < res_bytes)
    {
      reserve[i] = reply[i];
      i++;
    }
  circbuffer_push(circbuff, res_bytes);
}