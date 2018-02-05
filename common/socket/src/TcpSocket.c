/*
** TcpSocket.c for PSU_2016_myftp in /home/anthony/repository/PSU_2016_myftp/TcpSocket.c
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.eu>
**
** Started on  mer. mai 10 09:40:01 2017 Anthony LECLERC
** Last update Sun Jul  2 19:46:44 2017 Anthony LECLERC
*/

#include	"socket/TcpSocket.h"

bool		tcp_socket(t_tcpsocket *self)
{
  if (self != NULL)
  {
    return (new_socket(&self->socket, AF_INET, SOCK_STREAM));
  }
  return (false);
}
