/*
** rand_init.c for zappy in /home/anthony/repository/zappy/rand_init.c
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.eu>
**
** Started on  jeu. juin 22 11:54:59 2017 Anthony LECLERC
** Last update jeu. juin 22 11:54:59 2017 Anthony LECLERC
*/

#include 		<stdlib.h>
#include 		<time.h>

void			init_rand()
{
  struct timespec	spec;

  clock_gettime(CLOCK_REALTIME, &spec);
  srand((unsigned int)spec.tv_nsec);
}