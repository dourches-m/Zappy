/*
** init.c for PSU_2016_myftp in /home/anthony/repository/PSU_2016_myftp/init.c
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.eu>
**
** Started on  ven. mai 19 11:03:56 2017 Anthony LECLERC
** Last update Sun Jul  2 19:49:13 2017 Anthony LECLERC
*/

#include	"socket/TcpSocket.h"

void		tcp_socket_init(t_tcpsocket *sock)
{
  sock->socket.fd = INV_SOCKET;
  sock->socket.sock_err = 0;
  sock->connected = false;
}
