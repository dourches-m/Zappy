/*
** select_wait.c for PSU_2016_myirc in /home/anthony/repository/PSU_2016_myirc/select_wait.c
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.eu>
**
** Started on  mar. mai 23 04:35:20 2017 Anthony LECLERC
** Last update Sun Jul  2 19:45:55 2017 Anthony LECLERC
*/

#include		<string.h>
#include		"socket/SocketSelector.h"

int			select_wait(t_sockselector *self, ssize_t timeout,
				    t_select_type flags)
{
  struct timeval	time;

  time.tv_sec = timeout / 1000000;
  time.tv_usec = timeout % 1000000;
  memcpy(&self->ready[READ_SET],
	 &self->all[READ_SET], sizeof(self->all[READ_SET]));
  memcpy(&self->ready[WRITE_SET],
	 &self->all[WRITE_SET], sizeof(self->all[WRITE_SET]));
  memcpy(&self->ready[EXCEPT_SET],
	 &self->all[EXCEPT_SET], sizeof(self->all[EXCEPT_SET]));
  return (select(self->count + 1,
		 (flags & READ_SELECT) ? &self->ready[READ_SET] : NULL,
		 (flags & WRITE_SELECT) ? &self->ready[WRITE_SET] : NULL,
		 (flags & EXCEPT_SELECT) ? &self->ready[EXCEPT_SET] : NULL,
		 (timeout == 0) ? NULL : &time));
}
