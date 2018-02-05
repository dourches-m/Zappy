/*
** TCPSocket.h for PSU_2016_myftp in /home/anthony/repository/PSU_2016_myftp/TCPSocket.h
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.eu>
**
** Started on  mer. mai 10 09:20:57 2017 Anthony LECLERC
** Last update Sun Jul  2 19:41:51 2017 Anthony LECLERC
*/

#ifndef		TCPSOCKET_H_
# define	TCPSOCKET_H_

# include	<stdint.h>
# include	<stdbool.h>
# include	"Socket.h"
# include	"TcpPacket.h"

typedef struct	s_tcpsocket
{
  t_socket	socket;
  bool		connected;
}		t_tcpsocket;

void		tcp_socket_init(t_tcpsocket *self);

bool		tcp_socket(t_tcpsocket *self);

ssize_t		tcp_send(t_tcpsocket *self, void const *data, size_t size);

int		tcp_receive(t_tcpsocket *self, void *data, size_t size);

bool		tcp_connect(t_tcpsocket *self,
			    char const *ip, uint16_t port);

ssize_t		tcp_send_packet(t_tcpsocket *self, t_tcppacket *packet);

char const	*get_remote_saddr(t_socket *sock);

uint32_t        get_remote_addr(t_socket *sock);

uint16_t	get_remote_port(t_socket *sock);

char const	*get_local_saddr(t_socket *sock);

uint32_t	get_local_addr(t_socket *sock);

uint16_t	get_local_port(t_socket *sock);

#endif 		/* TCPSOCKET_H_ */
