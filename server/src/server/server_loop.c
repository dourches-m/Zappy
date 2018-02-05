/*
** server_loop.c for zappy in /home/anthony/repository/zappy/server_loop.c
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.eu>
**
** Started on  jeu. juin 22 16:35:43 2017 Anthony LECLERC
** Last update jeu. juin 22 16:35:43 2017 Anthony LECLERC
*/

#include		<signal.h>
#include		<string.h>
#include 		<stdio.h>
#include 		<time.h>
#include		<sys/time.h>
#include		"frequency.h"
#include 		"debug.h"
#include 		"client.h"
#include 		"serverinfo.h"

static int		g_running = 1;

void			handle_stop(int sig)
{
  (void)sig;
  g_running = 0;
}

static void		handle_running_signal()
{
  struct sigaction	sa;

  memset(&sa, 0, sizeof(sa));
  sa.sa_handler = handle_stop;
  sigaction(SIGINT, &sa, NULL);
}

static ssize_t		wait_activity(t_zserver *server)
{
  size_t		waittime;
  struct timeval	timespend;
  struct timeval 	now;

  if (gettimeofday(&timespend, NULL) == -1)
    return (-1);
  waittime = next_command_time(server->map->players, server->map->eggs);
  (waittime == 0) ? pause_timer() : resume_timer();
  SERVLOG("[WAIT] :: Time min to wait :: %zu\n", waittime);
  if (select_wait(&server->selector, waittime,
                  READ_SELECT | WRITE_SELECT) == -1)
    return (-1);
  gettimeofday(&now, NULL);
  waittime = (size_t)((now.tv_sec - timespend.tv_sec) * 1000000 +
      (now.tv_usec - timespend.tv_usec));
  SERVLOG("[WAIT] :: Timespend on wait :: %zu\n", waittime);
  return (0);
}

/*
** BEGIN LOOP -> 0
** Get update time -> min next command / Food / Player Input / Connection
** WAIT -> SPENT TIME -> 50
** [ GAME LOOP ]
** --> GAME TIMESPENT -> 100
** --> Total time spend in loop -> 150
** --> Update players state -> 150 frames
*/

int			server_loop(t_zserver *server)
{
  size_t		elapsed;
  struct timeval	begin;

  handle_running_signal();
  select_add(&server->selector, &server->sock.socket, READ_SELECT);
  if (!tcp_listen(&server->sock, 0))
    return (1);
  if (gettimeofday(&begin, NULL) == -1)
    return (1);
  while (g_running)
  {
    if (wait_activity(server) == -1)
      return (1);
    handle_inputs(server);
    if (select_ready(&server->selector, &server->sock.socket, READ_SET))
      connect_client(server);
    elapsed = get_elapsed_time(&begin);
    SERVLOG("[LOOP] :: BEFORE UPDATE :: %zu\n", elapsed);
    if (gettimeofday(&begin, NULL) == -1)
      return (1);
    update(server, elapsed);
  }
  return (0);
}