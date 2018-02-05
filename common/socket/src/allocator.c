/*
** allocator.c for PSU_2016_myftp in /home/anthony/repository/PSU_2016_myftp/allocator.c
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.eu>
**
** Started on  mar. mai 09 19:24:36 2017 Anthony LECLERC
** Last update Sun Jul  2 19:48:16 2017 Anthony LECLERC
*/

#include	<stdlib.h>
#include	<err.h>
#include	<string.h>
#include	"socket/Socket.h"

t_socket	*alloc_socket()
{
  t_socket	*sock;

  sock = malloc(sizeof(t_socket));
  if (sock == NULL)
    {
      warn("Socket allocation failed.");
      return (NULL);
    }
  memset(sock, 0, sizeof(t_socket));
  return (sock);
}
