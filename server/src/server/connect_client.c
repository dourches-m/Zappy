/*
** connect_client.c for zappy in /home/anthony/repository/zappy/connect_client.c
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.eu>
**
** Started on  jeu. juin 22 16:44:56 2017 Anthony LECLERC
** Last update Fri Jun 30 14:11:36 2017 Hugo Baldassin
*/

#include	<stdio.h>
#include	"debug.h"
#include 	"client.h"
#include 	"serverinfo.h"

int		connect_client(t_zserver *server)
{
  t_client 	*client;

  client = create_client();
  if (client == NULL)
    return (1);
  tcp_socket(&client->socket);
  if (!tcp_accept(&server->sock, &client->socket.socket))
  {
    destruct_client(client);
    return (1);
  }
  select_add(&server->selector, &client->socket.socket,
	     READ_SELECT);
  list_pushback_data(server->clients, client, sizeof(*client));
  client->read_data = read_unregister;
  client->write_data = write_to_client;
  circbuffer_append(client->output, "WELCOME\n");
  select_add(&server->selector, &client->socket.socket, WRITE_SELECT);
  DLOG("Client Connected ==> FD: %d\n", client->socket.socket.fd);
  return (0);
}
