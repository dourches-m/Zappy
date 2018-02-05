/*
** packet.c for PSU_2016_myirc in /home/anthony/repository/PSU_2016_myirc/packet.c
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.eu>
**
** Started on  mer. juin 07 17:15:11 2017 Anthony LECLERC
** Last update Sun Jul  2 19:44:48 2017 Anthony LECLERC
*/

#include	<assert.h>
#include	<stdio.h>
#include	"socket/TcpSocket.h"

void		tcp_packet(t_tcppacket *packet, char *data, size_t size)
{
  if (packet)
  {
    packet->data = data;
    packet->size = size;
    packet->sent = 0;
  }
}

ssize_t		tcp_send_packet(t_tcpsocket *self, t_tcppacket *packet)
{
  ssize_t	sent;

  assert(self != NULL);
  if (self->socket.fd != INV_SOCKET && packet)
  {
    if (packet->data == NULL)
    {
      fprintf(stderr, "Socket: Warning: Sending null data.\n");
      return (0);
    }
    sent = tcp_send(self, packet->data + packet->sent,
		    packet->size - packet->sent);
    if (sent == -1)
      return (-1);
    packet->sent += sent;
    return (packet->sent);
  }
  return (-1);
}

void            tcp_packet_clear(t_tcppacket *packet)
{
  if (packet)
  {
    packet->data = NULL;
    packet->size = 0;
    packet->sent = 0;
  }
}
