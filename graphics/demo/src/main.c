/*
** main.c for zappy in /home/sylvain/PSU_2016_zappy/graphic_client/demo
**
** Made by Sylvain Chaugny
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Sun Jul  2 20:33:00 2017 Sylvain Chaugny
** Last update Sun Jul  2 21:04:48 2017 Sylvain Chaugny
*/

#include		<stdlib.h>
#include		<unistd.h>
#include		<stdio.h>
#include		"demo.h"

void			demo_launch(int		fd)
{
  demo_welcome(fd);
  demo_send_data(fd);
  sleep(2);
  demo_animation_1(fd);
  sleep(1);
  demo_animation_2(fd);
  demo_animation_3(fd);
}

int			main(const int		ac,
			     const char		**av)
{
  int			fd;
  int			client;

  if (ac != 2)
    {
      printf("Usage: %s [port]\n", av[0]);
      return (0);
    }
  fd = demo_init_server(atoi(av[1]));
  if (fd == -1)
    {
      fprintf(stderr, "Error initializing server\n");
      return (1);
    }
  client = demo_get_client(fd);
  demo_launch(client);
  close(fd);
  close(client);
}
