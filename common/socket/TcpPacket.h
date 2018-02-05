/*
** TcpPacket.h for PSU_2016_myirc in /home/anthony/repository/PSU_2016_myirc/TcpPacket.h
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.eu>
**
** Started on  mer. juin 07 17:11:23 2017 Anthony LECLERC
** Last update Sun Jul  2 19:41:17 2017 Anthony LECLERC
*/

#ifndef		TCPPACKET_H_
# define	TCPPACKET_H_

# include	<sys/types.h>

typedef struct	s_tcppacket
{
  char		*data;
  size_t	size;
  size_t	sent;
}		t_tcppacket;

void		tcp_packet(t_tcppacket *self, char *data, size_t size);

void		tcp_packet_clear(t_tcppacket *self);

#endif		/* TCPPACKET_H_ */
