/*
** TcpListener.h for PSU_2016_myftp in /home/anthony/repository/PSU_2016_myftp/TcpListener.h
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.eu>
**
** Started on  mer. mai 10 09:22:44 2017 Anthony LECLERC
** Last update Sun Jul  2 19:40:52 2017 Anthony LECLERC
*/

#ifndef		TCPLISTENER_H_
# define	TCPLISTENER_H_

#include	<stdint.h>
#include	"Socket.h"

typedef struct	s_tcplistener
{
  t_socket	socket;
}		t_tcplistener;

bool		tcp_listener(t_tcplistener *self);

bool		tcp_bind(t_tcplistener *self,
			 char const *ip, uint16_t port);

bool		tcp_listen(t_tcplistener *self, int queuesize);

bool		tcp_accept(t_tcplistener *self, t_socket *sock);

#endif 		/* TCPLISTENER_H */
