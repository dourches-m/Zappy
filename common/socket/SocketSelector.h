/*
** SocketSelector.h for PSU_2016_myirc in /home/anthony/repository/PSU_2016_myirc/SocketSelector.h
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.eu>
**
** Started on  lun. mai 22 23:28:22 2017 Anthony LECLERC
** Last update Sun Jul  2 19:40:31 2017 Anthony LECLERC
*/

#ifndef			SOCKETSELECTOR_H_
# define		SOCKETSELECTOR_H_

# include		<sys/types.h>
# include		"Socket.h"

typedef enum		e_select_set
{
  READ_SET,
  WRITE_SET,
  EXCEPT_SET,
  MAX_SET
}			t_select_set;

typedef enum		e_select_type
{
  READ_SELECT		= 1,
  WRITE_SELECT		= 2,
  EXCEPT_SELECT		= 4,
}			t_select_type;

typedef struct		s_sockselector
{
  fd_set		all[MAX_SET];
  fd_set		ready[MAX_SET];
  int			count;
}			t_sockselector;

void			sock_selector(t_sockselector *self);

void			select_add(t_sockselector *self, t_socket *sock,
				   t_select_type type);

void			select_remove(t_sockselector *self, t_socket *sock);

bool			select_ready(t_sockselector *self,
				     t_socket *sock,
				     t_select_set mode);

int			select_wait(t_sockselector *self, ssize_t timeout,
				    t_select_type flags);

void			select_clear(t_sockselector *self);

#endif 			/* SOCKETSELECTOR_H_ */
