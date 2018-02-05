/*
** receive.c for PSU_2016_myftp in /home/anthony/repository/PSU_2016_myftp/receive.c
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.eu>
**
** Started on  mer. mai 10 13:57:31 2017 Anthony LECLERC
** Last update Sun Jul  2 19:50:00 2017 Anthony LECLERC
*/

#include	<unistd.h>
#include        "socket/TcpSocket.h"

int		tcp_receive(t_tcpsocket *self, void *data, size_t size)
{
  int		bytes_read;

  if (self != NULL && data != NULL)
    {
      bytes_read = (int)read(self->socket.fd, data, size);
      return (bytes_read);
    }
  return (-1);
}
