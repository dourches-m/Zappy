/*
** send.c for PSU_2016_myftp in /home/anthony/repository/PSU_2016_myftp/send.c
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.eu>
**
** Started on  mer. mai 10 13:55:12 2017 Anthony LECLERC
** Last update Sun Jul  2 19:50:52 2017 Anthony LECLERC
*/

#include	<unistd.h>
#include	<err.h>
#include	"socket/TcpSocket.h"

ssize_t		tcp_send(t_tcpsocket *self, void const *data, size_t size)
{
  ssize_t  	ret;

  if (self != NULL && data != NULL)
    {
      ret = write(self->socket.fd, data, size);
      if (ret == -1)
	warn("Socket: write");
      return (ret);
    }
  return (-1);
}
