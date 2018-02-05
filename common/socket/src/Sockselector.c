/*
** Sockselector.c for PSU_2016_myirc in /home/anthony/repository/PSU_2016_myirc/Sockselector.c
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.eu>
**
** Started on  lun. mai 22 23:39:29 2017 Anthony LECLERC
** Last update lun. mai 22 23:39:29 2017 Anthony LECLERC
*/

#include	"socket/SocketSelector.h"

void		sock_selector(t_sockselector *self)
{
  select_clear(self);
}