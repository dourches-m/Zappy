/*
** delete.c for PSU_2016_myirc in /home/anthony/repository/PSU_2016_myirc/delete.c
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.eu>
**
** Started on  jeu. mai 25 07:42:34 2017 Anthony LECLERC
** Last update jeu. mai 25 07:42:34 2017 Anthony LECLERC
*/

#include	<stdlib.h>
#include	"buffer/circbuffer.h"

void		circbuffer_delete(t_circbuff *self)
{
  free(self);
}