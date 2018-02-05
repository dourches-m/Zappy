/*
** usage.c for zappy in /home/anthony/repository/zappy/usage.c
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.eu>
**
** Started on  lun. juin 19 21:10:27 2017 Anthony LECLERC
** Last update Tue Jun 27 00:01:34 2017 Hugo Baldassin
*/

#include	"stdio.h"

void		usage(char const *binary)
{
  printf("USAGE: %s: -p port -x width -y height -n name1 name2 ... -c "
	 "clientsNb -f freq\n"
	 "port\t\tis the port number\n"
	 "width\t\tis the width of the world\n"
	 "height\t\tis the height of the world\n"
	 "nameX\t\tis the name of the team X\n"
	 "clientNb\tis the number of authorized clients per team\n"
	 "freq\t\tis the reciprocal of time unit for execution"
	 " of actions\n", binary);
}
