/*
** Socket.h for PSU_2016_myftp in /home/anthony/repository/PSU_2016_myftp/Socket.h
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.eu>
**
** Started on  mar. mai 09 18:54:06 2017 Anthony LECLERC
** Last update Sun Jul  2 19:39:47 2017 Anthony LECLERC
*/

#ifndef			SOCKET_H_
# define		SOCKET_H_

# include		<sys/socket.h>
# include		<netinet/in.h>
# include		<stdint.h>
# include		<stddef.h>
# include		<stdbool.h>

# define		INV_SOCKET 	-1

# define		IP4_BYTE1(ip)	((ip) >> 24) & 0xFF
# define		IP4_BYTE2(ip)	((ip) >> 16) & 0xFF
# define		IP4_BYTE3(ip)	((ip) >> 8) & 0xFF
# define		IP4_BYTE4(ip)	(ip) & 0xFF

typedef struct		s_socket
{
  int			fd;
  int			sock_err;
  struct sockaddr_in	infos;
}			t_socket;

t_socket		*alloc_socket();

bool			new_socket(t_socket *self, int domain, int type);

void			destruct_socket(t_socket *self);

bool			open_socket(t_socket *self, int domain, int type);

void			close_socket(t_socket *socket);

bool			set_inet_addr(t_socket *self,
				      char const *ip,
				      uint16_t port);

#endif			/* SOCKET_H_ */
