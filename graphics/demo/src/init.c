/*
** init.c for zappy in /home/sylvain/PSU_2016_zappy/graphic_client/demo
**
** Made by Sylvain Chaugny
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Sun Jul  2 20:31:41 2017 Sylvain Chaugny
** Last update Sun Jul  2 20:32:28 2017 Sylvain Chaugny
*/

#include		<string.h>
#include		<stdio.h>
#include		<stdlib.h>
#include		<fcntl.h>
#include		<unistd.h>
#include		<netinet/in.h>
#include		<arpa/inet.h>
#include		<sys/types.h>
#include		<netdb.h>
#include		<sys/socket.h>
#include		<unistd.h>
#include		"protocol.h"

int			demo_init_server(int	port)
{
  int			fd;
  struct sockaddr_in	s_in;
  int			s_in_size;
  struct protoent	*proto;

  s_in.sin_family = AF_INET;
  s_in.sin_port = htons(port);
  s_in.sin_addr.s_addr = inet_addr("127.0.0.1");
  s_in_size = sizeof(s_in);
  proto = getprotobyname("TCP");
  fd = socket(AF_INET, SOCK_STREAM, proto->p_proto);
  if (fd == -1)
    return (-1);
  if (bind(fd, (struct sockaddr *)&s_in, s_in_size) == -1)
    return (-1);
  if (listen(fd, SOMAXCONN) == -1)
    return (-1);
  printf("Server initialized with port %d\n", port);
  return (fd);
}

int			demo_get_client(int	fd)
{
  int			c_fd;
  struct sockaddr_in	*c_s_in;
  socklen_t		c_s_in_size;

  c_s_in_size = sizeof(c_s_in);
  c_fd = accept(fd, (struct sockaddr *)&c_s_in, &c_s_in_size);
  return (c_fd);
}

void			demo_welcome(int	fd)
{
  char			reply[64];

  write(fd, "WELCOME\n", strlen("WELCOME\n"));
  reply[read(fd, reply, 63)] = 0;
  printf("The client responded with <%s>\n", reply);
}
