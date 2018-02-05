/*
** time.c for zappy in /home/anthony/repository/zappy/time.c
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.eu>
**
** Started on  mer. juin 28 21:48:23 2017 Anthony LECLERC
** Last update mer. juin 28 21:48:23 2017 Anthony LECLERC
*/

#include		<sys/time.h>
#include		<stddef.h>
#include 		<stdbool.h>

static struct timeval	g_begin;
static size_t		g_lastick;
static bool		g_is_paused;

int			init_timer()
{
  g_is_paused = true;
  return (gettimeofday(&g_begin, NULL));
}

void			pause_timer()
{
  g_is_paused = true;
}

void			resume_timer()
{
  struct timeval	now;

  g_is_paused = false;
  gettimeofday(&now, NULL);
  g_lastick = (size_t)(now.tv_sec - g_begin.tv_sec) * 1000000 +
	      (now.tv_usec - g_begin.tv_usec);
}

size_t			get_elapsed_time(struct timeval *begin)
{
  struct timeval	end;
  time_t		elapsed;

  if (g_is_paused)
    return (0);
  gettimeofday(&end, NULL);
  elapsed = (end.tv_sec - begin->tv_sec) * 1000000 +
      (end.tv_usec - begin->tv_usec);
  g_lastick += elapsed;
  return ((size_t)elapsed);
}

size_t			get_tick()
{
  struct timeval	now;

  if (g_is_paused)
  {
    return (g_lastick);
  }
  gettimeofday(&now, NULL);
  g_lastick += get_elapsed_time(&now);
  return (g_lastick);
}
