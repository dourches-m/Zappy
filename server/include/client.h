/*
** client.h for zappy in /home/anthony/repository/zappy/client.h
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.eu>
**
** Started on  jeu. juin 22 11:39:47 2017 Anthony LECLERC
** Last update jeu. juin 22 11:39:47 2017 Anthony LECLERC
*/

#ifndef 		ZAPPY_CLIENT_H
# define 		ZAPPY_CLIENT_H

# include		"socket/SocketSelector.h"
# include 		"buffer/circbuffer.h"
# include 		"socket/TcpSocket.h"

# define		CLIENT_BUFFER_SIZE	1024

struct			s_zserver;
struct			s_list;
struct			s_player;

typedef struct		s_client
{
  t_tcpsocket		socket;
  t_circbuff		*input;
  t_circbuff		*output;
  int			(*read_data)(struct s_client *self);
  int			(*write_data)(struct s_client *self);
  struct s_player	*player;
}			t_client;

t_client		*create_client();

void			destruct_client(void *client);

int			is_free_client(void *client);

int			register_player(struct s_zserver *server,
					   t_client *client,
					   char const *input);

int			register_graphic(struct s_zserver *server,
					    t_client *client,
					    char const *input);

int			msg_client(t_sockselector *select, t_client *client,
				      char const *msg);

int			write_to_graphic(struct s_client *client);

int			write_to_client(struct s_client *client);

int			write_to_player(struct s_client *client);

#endif 		 	/* ZAPPY_CLIENT_H */
