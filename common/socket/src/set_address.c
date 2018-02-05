/*
** set_address.c for PSU_2016_myftp in /home/anthony/repository/PSU_2016_myftp/set_address.c
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.eu>
**
** Started on  mer. mai 10 11:07:33 2017 Anthony LECLERC
** Last update Sun Jul  2 19:46:17 2017 Anthony LECLERC
*/

#include		<netinet/in.h>
#include		<arpa/inet.h>
#include		<string.h>
#include		"socket/Socket.h"

bool			set_inet_addr(t_socket *self, char const *ip,
				      uint16_t port)
{
  struct sockaddr_in	addr;

  if (ip == NULL)
    addr.sin_addr.s_addr = INADDR_ANY;
  else if (inet_aton(ip, &addr.sin_addr) == 0)
    return (false);
  addr.sin_family = AF_INET;
  addr.sin_port = htons(port);
  memcpy(&self->infos, (struct sockaddr *) &addr,
	 sizeof(struct sockaddr));
  return (true);
}
