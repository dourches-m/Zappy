/*
** selector_clear.c for PSU_2016_myirc in /home/anthony/repository/PSU_2016_myirc/selector_clear.c
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.eu>
**
** Started on  lun. mai 22 23:47:36 2017 Anthony LECLERC
** Last update Sun Jul  2 19:50:22 2017 Anthony LECLERC
*/

#include	"socket/SocketSelector.h"

void		select_clear(t_sockselector *self)
{
  FD_ZERO(&self->all[READ_SET]);
  FD_ZERO(&self->all[WRITE_SET]);
  FD_ZERO(&self->all[EXCEPT_SET]);
  FD_ZERO(&self->ready[READ_SET]);
  FD_ZERO(&self->ready[WRITE_SET]);
  FD_ZERO(&self->ready[EXCEPT_SET]);
  self->count = 0;
}
