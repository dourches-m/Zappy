/*
** TcpListener.c for PSU_2016_myftp in /home/anthony/repository/PSU_2016_myftp/TcpListener.c
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.eu>
**
** Started on  mer. mai 10 09:46:22 2017 Anthony LECLERC
** Last update Sun Jul  2 19:51:26 2017 Anthony LECLERC
*/

#include	"socket/TcpListener.h"

bool		tcp_listener(t_tcplistener *self)
{
  if (self != NULL)
    {
      return (new_socket(&self->socket, AF_INET, SOCK_STREAM));
    }
  return (false);
}
